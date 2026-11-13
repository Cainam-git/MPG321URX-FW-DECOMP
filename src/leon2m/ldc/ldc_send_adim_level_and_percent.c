/* ldc_send_adim_level_and_percent  (FUN_a013a0d4)
 *
 * Send dimming command 0x39: ADIM_BrighPercent and usUserADIM packed into 24 bits.
 * Name basis: derived - waits for mailbox portal 2 slot 0x20 to be free, then posts command 0x39; the dimming
 *   program's handler of the command is ldc_cmd_set_adim_level_and_percent (fn_40001830)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a013a0d4 @ 0xa013a0d4-0xa013a1a4 (208 bytes), flags -mcpu=v8 -O3 -g.
 * Source form: value is an unsigned short parameter updated in place (the firmware truncates it only at the final
 * use); the low halfword of percent is copied to an unsigned short and its shifted byte is taken before the 2-bit
 * field; the constant 0x39000000 is a local (as in ldc_send_led_driver_register).
 */

#define DIMMING_PORTAL 2            /* mailbox portal 2: the dimming (Tensilica) processor */
#define COMMAND_SLOT   0x20         /* byte offset of its command slot in the portal */
#define WAIT_TRIES     100          /* waits of timer_sleep_ticks(1) before the command is dropped */

extern void ipc_mailbox_read();
extern void ipc_mailbox_write();
extern int timer_sleep_ticks();

/*
 * Send command 0x39 to the dimming processor: set ADIM_BrighPercent and usUserADIM with one command (handler
 * ldc_cmd_set_adim_level_and_percent, which takes the percent from sub-code << 2 | value >> 14 and usUserADIM from
 * the low 10 bits of the value). So:
 *   percent  goes in two parts: bits 2.. as the sub-code byte (bits 16..23 of the word), bits 0..1 into bits 14..15
 *            of the value halfword;
 *   value    fills the low 16 bits of the word (OR-ed with those two bits).
 * Only called by ldc_api_send_cmd_0x39, which nothing calls.
 *
 * Wait for the dimming processor to take its previous command (the command slot reads 0): read the slot once,
 * then up to 100 times wait timer_sleep_ticks(1) and read again. The command word is written as soon as a read
 * gives 0. If the slot never reads 0 nothing is written and the command is lost; there is no result either way.
 */
void ldc_send_adim_level_and_percent(unsigned int percent, unsigned short value)
{
    unsigned short percent_low16 = percent;
    unsigned char sub_code = percent_low16 >> 2;
    unsigned int slot_word;
    int tries;
    unsigned int command_base = 0x39000000;

    value |= (percent_low16 & 3) << 14;
    slot_word = 0xffffffff;
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
        slot_word = (sub_code << 16 | command_base) | value;
        ipc_mailbox_write(DIMMING_PORTAL, COMMAND_SLOT, &slot_word, 1);
    }
}
