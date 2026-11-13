/* ldc_send_adim_bright_percent  (FUN_a0139604)
 *
 * Send dimming command 0x35 (ADIM_BrighPercent) with a value, only when the value has changed.
 * Name basis: derived - waits for mailbox portal 2 slot 0x20 to be free, then posts command 0x35; last value
 *   kept at 0xA802A458; unused; the dimming program's handler of the command is
 *   ldc_cmd_set_adim_bright_percent (fn_400017c0)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0139604 @ 0xa0139604-0xa01396d8 (53 words), flags -mcpu=v8 -O3 -g.
 * Source form: the 0x35000000 operand is a separate u16 copy 'copy = value' taken after the early-return
 * test (the firmware's 'mov %i0,%l1' keeps the store value; the or re-extends %i0 and reuses %i0 for the sethi).
 * With the copy before the test, the scheduler puts the sll before the sethi. No other aids.
 */
extern unsigned short ldc_cmd35_last_value;
extern int ipc_mailbox_read(unsigned char portal, unsigned char offset, unsigned int *buf, unsigned char count);
extern int ipc_mailbox_write(unsigned char portal, unsigned char offset, unsigned int *buf, unsigned char count);
extern int timer_sleep_ticks(int ms);

#define DIMMING_PORTAL 2                        /* mailbox portal 2: the dimming processor */
#define COMMAND_SLOT   0x20                     /* its command slot; 0 = free */
#define WAIT_TRIES     100                      /* checks of the slot, 1 tick apart */

/*
 * Post command 0x35 with a 16-bit value (word 0x35000000 | value) unless the value equals the one sent last
 * (ldc_cmd35_last_value); then nothing happens. If the command slot is not 0 it is checked again up to 100 times,
 * waiting 1 tick before each check; if it never becomes 0 nothing is sent. The new value is remembered in
 * either case. Nothing in the image calls this routine or stores its address.
 */
void ldc_send_adim_bright_percent(unsigned short value)
{
    unsigned int slot_word;
    int tries;
    unsigned short copy;
    if (ldc_cmd35_last_value == value)
        return;
    copy = value;
    slot_word = 0xffffffff;
    ipc_mailbox_read(DIMMING_PORTAL, COMMAND_SLOT, &slot_word, 1);
    if (slot_word != 0) {
        tries = WAIT_TRIES;
        do {
            timer_sleep_ticks(1);
            tries--;
            ipc_mailbox_read(DIMMING_PORTAL, COMMAND_SLOT, &slot_word, 1);
            if (tries == 0)
                break;
        } while (slot_word != 0);
    }
    if (slot_word == 0) {
        slot_word = 0x35000000 | copy;
        ipc_mailbox_write(DIMMING_PORTAL, COMMAND_SLOT, &slot_word, 1);
    }
    ldc_cmd35_last_value = value;
}
