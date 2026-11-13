/* ldc_send_led_current_on  (FUN_a01394a8)
 *
 * Send dimming command 0x38 with an on/off bit: switch the LED current on or off.
 * Name basis: derived - waits for mailbox portal 2 slot 0x20 to be free, then posts command 0x38; unused; the
 *   dimming program's handler of the command is ldc_cmd_set_led_current_on (fn_40001a08)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01394a8 @ 0xa01394a8
 * Required form: the bit is kept in an unsigned char local and turned into 0/1 with a separate 'v = on != 0;'
 * statement before the OR; this keeps the firmware's compare (cmp %g0 / addx). An unsigned int local lets the
 * compiler drop the compare, and '0x38000000 | (on != 0)' in one expression becomes a branch.
 */
extern void ipc_mailbox_read(unsigned char portal, unsigned char offset, unsigned int *buf, unsigned char count);
extern void ipc_mailbox_write(unsigned char portal, unsigned char offset, unsigned int *buf, unsigned char count);
extern void timer_sleep_ticks(int ms);

#define DIMMING_PORTAL 2                        /* mailbox portal 2: the dimming processor */
#define COMMAND_SLOT   0x20                     /* its command slot; 0 = free */
#define WAIT_TRIES     100                      /* checks of the slot, 1 tick apart */

/*
 * Post command 0x38 with bit 0 of the argument as its value (word 0x38000000 | bit). If the command slot is not
 * 0 it is checked again up to 100 times, waiting 1 tick before each check; if it never becomes 0 nothing is
 * sent. Nothing in the image calls this routine or stores its address.
 */
void ldc_send_led_current_on(unsigned int flag)
{
    unsigned char on = flag & 1;
    unsigned int slot_word = 0xffffffff;
    int tries = WAIT_TRIES;

    ipc_mailbox_read(DIMMING_PORTAL, COMMAND_SLOT, &slot_word, 1);

    if (slot_word == 0) goto build;

    do {
        timer_sleep_ticks(1);
        tries--;
        ipc_mailbox_read(DIMMING_PORTAL, COMMAND_SLOT, &slot_word, 1);
    } while (tries != 0 && slot_word != 0);

    if (slot_word == 0) {
build:
        slot_word = on != 0;
        slot_word |= 0x38 << 24;
        ipc_mailbox_write(DIMMING_PORTAL, COMMAND_SLOT, &slot_word, 1);
    }
}
