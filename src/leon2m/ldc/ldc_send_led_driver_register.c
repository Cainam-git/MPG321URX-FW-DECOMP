/* ldc_send_led_driver_register  (FUN_a013aae4)
 *
 * Send dimming command 0x61 with two byte values, which write one register of the LED driver.
 * Name basis: derived - waits for mailbox portal 2 slot 0x20 to be free, then posts; the dimming program's
 *   handler of the command is ldc_cmd_write_as3824_register (fn_400019c4)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a013aae4 @ 0xa013aae4-0xa013ab9c (184 bytes), flags -mcpu=v8 -O3 -g.
 * Source form: the low byte value is converted into a short at the start; the constant 0x61000000 is held in a
 * local, which keeps the or order (sub_code << 16) | command_base before | value (a literal is reassociated to the
 * outside).
 */

#define DIMMING_PORTAL 2            /* mailbox portal 2: the dimming (Tensilica) processor */
#define COMMAND_SLOT   0x20         /* byte offset of its command slot in the portal */
#define WAIT_TRIES     100          /* waits of timer_sleep_ticks(1) before the command is dropped */

extern void ipc_mailbox_read();
extern void ipc_mailbox_write();
extern int timer_sleep_ticks();

/*
 * Send command 0x61 to the dimming processor (handler ldc_cmd_write_as3824_register: the sub-code is the number of
 * the AS3824 register to write, and the handler acts only when the panel's driver type is 1). The command word is
 * 0x61000000 | sub_code << 16 | value.
 *
 * Wait for the dimming processor to take its previous command (the command slot reads 0): read the slot once,
 * then up to 100 times wait timer_sleep_ticks(1) and read again. The command word is written as soon as a read
 * gives 0. If the slot never reads 0 nothing is written and the command is lost; there is no result either way.
 */
void ldc_send_led_driver_register(unsigned char sub_code, unsigned char value)
{
    short value_short;
    unsigned int slot_word;
    int tries;
    unsigned int command_base = 0x61000000;

    slot_word = 0xffffffff;
    value_short = value & 0xff;
    ipc_mailbox_read(DIMMING_PORTAL, COMMAND_SLOT, &slot_word, 1);
    tries = WAIT_TRIES;
    while (slot_word != 0) {
        timer_sleep_ticks(1);
        tries--;
        ipc_mailbox_read(DIMMING_PORTAL, COMMAND_SLOT, &slot_word, 1);
        if (tries == 0)
            break;
    }
    if (slot_word == 0) {
        slot_word = ((sub_code << 16) | command_base) | value_short;
        ipc_mailbox_write(DIMMING_PORTAL, COMMAND_SLOT, &slot_word, 1);
    }
}
