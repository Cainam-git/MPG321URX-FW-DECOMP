/* ldc_send_adim_min  (FUN_a013a028)
 *
 * Send dimming command 0x34 (ADIM_Min) with a 16-bit value.
 * Name basis: derived - waits for mailbox portal 2 slot 0x20 to be free, then posts command 0x34; the dimming
 *   program's handler of the command is ldc_cmd_set_adim_min (fn_400017a0)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a013a028 @ 0xa013a028, flags -mcpu=v8 -O3 -g.
 * Source form: the command word is the expression (0x34 << 24) | (0x0 << 16) | arg.
 */

#define DIMMING_PORTAL 2            /* mailbox portal 2: the dimming (Tensilica) processor */
#define COMMAND_SLOT   0x20         /* byte offset of its command slot in the portal */
#define WAIT_TRIES     100          /* waits of timer_sleep_ticks(1) before the command is dropped */

extern void ipc_mailbox_read(unsigned char portal, unsigned char offset, unsigned int *buf, unsigned char count);
extern void ipc_mailbox_write(unsigned char portal, unsigned char offset, unsigned int *buf, unsigned char count);
extern void timer_sleep_ticks(int ms);

/*
 * Send command 0x34 to the dimming processor: set ADIM_Min (handler ldc_cmd_set_adim_min). The command word is
 * 0x34000000 | (arg & 0xffff). Called only by ldc_api_send_cmd_0x34, which nothing calls.
 *
 * Wait for the dimming processor to take its previous command (the command slot reads 0): read the slot once,
 * then up to 100 times wait timer_sleep_ticks(1) and read again. The command word is written as soon as a read
 * gives 0. If the slot never reads 0 nothing is written and the command is lost; there is no result either way.
 */
void ldc_send_adim_min(unsigned short arg)
{
    unsigned int slot_word = 0xffffffff;
    int tries = WAIT_TRIES;
    ipc_mailbox_read(DIMMING_PORTAL, COMMAND_SLOT, &slot_word, 1);
    while (slot_word != 0) { tries--; timer_sleep_ticks(1); ipc_mailbox_read(DIMMING_PORTAL, COMMAND_SLOT, &slot_word, 1); if (tries == 0) break; }
    if (slot_word == 0) { slot_word = (0x34 << 24) | (0x0 << 16) | arg; ipc_mailbox_write(DIMMING_PORTAL, COMMAND_SLOT, &slot_word, 1); }
}
