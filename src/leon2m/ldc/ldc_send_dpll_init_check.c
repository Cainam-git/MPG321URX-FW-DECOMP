/* ldc_send_dpll_init_check  (FUN_a013a750)
 *
 * Send the check command that the dimming processor answers with its init-done message.
 * Name basis: proven - docs/MAP.md: command 0x40, check message 'MAILBOX_DPLL INIT DONE'; called from start-up
 *
 * Matching notes
 * --------------
 * leon2m FUN_a013a750 @ 0xa013a750, flags -mcpu=v8 -O3 -g.
 * Source form: the command word is the constant 0x40000001, no argument.
 */

#define DIMMING_PORTAL 2            /* mailbox portal 2: the dimming (Tensilica) processor */
#define COMMAND_SLOT   0x20         /* byte offset of its command slot in the portal */
#define WAIT_TRIES     100          /* waits of timer_sleep_ticks(1) before the command is dropped */

/* Command 0x40 (handler ldc_cmd_dpll_init_check) with the value 1 in the low halfword. */
#define LDC_DPLL_INIT_CHECK_WORD 0x40000001

extern void ipc_mailbox_read(unsigned char portal, unsigned char offset, unsigned int *buf, unsigned char count);
extern void ipc_mailbox_write(unsigned char portal, unsigned char offset, unsigned int *buf, unsigned char count);
extern void timer_sleep_ticks(int ms);

/*
 * Send command 0x40 to the dimming processor; it prints 'MAILBOX_DPLL INIT DONE!!' (or 'NOT INIT!!') for it.
 * Called once by the system start-up (System_Initialize path, startup_bring_up_system).
 *
 * Wait for the dimming processor to take its previous command (the command slot reads 0): read the slot once,
 * then up to 100 times wait timer_sleep_ticks(1) and read again. The command word is written as soon as a read
 * gives 0. If the slot never reads 0 nothing is written and the command is lost; there is no result either way.
 */
void ldc_send_dpll_init_check(void)
{
    unsigned int slot_word = 0xffffffff;
    int tries = WAIT_TRIES;
    ipc_mailbox_read(DIMMING_PORTAL, COMMAND_SLOT, &slot_word, 1);
    while (slot_word != 0) { tries--; timer_sleep_ticks(1); ipc_mailbox_read(DIMMING_PORTAL, COMMAND_SLOT, &slot_word, 1); if (tries == 0) break; }
    if (slot_word == 0) { slot_word = LDC_DPLL_INIT_CHECK_WORD; ipc_mailbox_write(DIMMING_PORTAL, COMMAND_SLOT, &slot_word, 1); }
}
