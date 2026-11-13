/* ldc_send_user_adim_sub1  (FUN_a0139558)
 *
 * Send dimming command 0x31 (usUserADIM) variant 1, with a 16-bit value.
 * Name basis: derived - waits for mailbox portal 2 slot 0x20 to be free, then posts command 0x31; the dimming
 *   program's handler of the command is ldc_cmd_set_user_adim (fn_4000153c)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0139558 @ 0xa0139558
 * Source form: the wait is a while loop with the count test after the re-read; the command word is
 * (0x31 << 24) | (0x01 << 16) | value.
 */
extern void ipc_mailbox_read(unsigned char portal, unsigned char offset, unsigned int *buf, unsigned char count);
extern void ipc_mailbox_write(unsigned char portal, unsigned char offset, unsigned int *buf, unsigned char count);
extern void timer_sleep_ticks(int ms);

#define DIMMING_PORTAL 2                        /* mailbox portal 2: the dimming processor */
#define COMMAND_SLOT   0x20                     /* its command slot; 0 = free */
#define WAIT_TRIES     100                      /* checks of the slot, 1 tick apart */

/*
 * Post command 0x31 with sub-code 1 and a 16-bit value (word 0x31010000 | value). If the command slot is not 0 it
 * is checked again up to 100 times, waiting 1 tick before each check; if it never becomes 0 nothing is sent.
 * Called by ldc_api_send_cmd_0x31_sub1.
 */
void ldc_send_user_adim_sub1(unsigned short value)
{
    unsigned int slot_word = 0xffffffff;
    int tries = WAIT_TRIES;
    ipc_mailbox_read(DIMMING_PORTAL, COMMAND_SLOT, &slot_word, 1);
    while (slot_word != 0) { tries--; timer_sleep_ticks(1); ipc_mailbox_read(DIMMING_PORTAL, COMMAND_SLOT, &slot_word, 1); if (tries == 0) break; }
    if (slot_word == 0) { slot_word = (0x31 << 24) | (0x1 << 16) | value; ipc_mailbox_write(DIMMING_PORTAL, COMMAND_SLOT, &slot_word, 1); }
}
