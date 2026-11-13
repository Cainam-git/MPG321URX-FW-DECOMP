/* ldc_send_input_duty_check  (FUN_a013a98c)
 *
 * Send dimming command 0x97 with a 16-bit value: switch the per-frame input duty check on or off.
 * Name basis: derived - waits for mailbox portal 2 slot 0x20 to be free, then posts command 0x97; docs/MAP.md:
 *   one value, written by the receiver to 0xE0080388; the dimming program's handler of the command is
 *   ldc_cmd_enable_input_duty_check (fn_40001ac8)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a013a98c @ 0xa013a98c, flags -mcpu=v8 -O3 -g.
 * Source form: the command word is the expression (0x97 << 24) | (0x0 << 16) | arg.
 */

#define DIMMING_PORTAL 2            /* mailbox portal 2: the dimming (Tensilica) processor */
#define COMMAND_SLOT   0x20         /* byte offset of its command slot in the portal */
#define WAIT_TRIES     100          /* waits of timer_sleep_ticks(1) before the command is dropped */

extern void ipc_mailbox_read(unsigned char portal, unsigned char offset, unsigned int *buf, unsigned char count);
extern void ipc_mailbox_write(unsigned char portal, unsigned char offset, unsigned int *buf, unsigned char count);
extern void timer_sleep_ticks(int ms);

/*
 * Send command 0x97 to the dimming processor: switch its per-frame input duty check on or off (handler
 * ldc_cmd_enable_input_duty_check, which also updates register 0xE0080388). The command word is
 * 0x97000000 | (arg & 0xffff). Called by ldc_api_set_zone_grid (start-up path).
 *
 * Wait for the dimming processor to take its previous command (the command slot reads 0): read the slot once,
 * then up to 100 times wait timer_sleep_ticks(1) and read again. The command word is written as soon as a read
 * gives 0. If the slot never reads 0 nothing is written and the command is lost; there is no result either way.
 */
void ldc_send_input_duty_check(unsigned short arg)
{
    unsigned int slot_word = 0xffffffff;
    int tries = WAIT_TRIES;
    ipc_mailbox_read(DIMMING_PORTAL, COMMAND_SLOT, &slot_word, 1);
    while (slot_word != 0) { tries--; timer_sleep_ticks(1); ipc_mailbox_read(DIMMING_PORTAL, COMMAND_SLOT, &slot_word, 1); if (tries == 0) break; }
    if (slot_word == 0) { slot_word = (0x97 << 24) | (0x0 << 16) | arg; ipc_mailbox_write(DIMMING_PORTAL, COMMAND_SLOT, &slot_word, 1); }
}
