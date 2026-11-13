/* ipc_wait_command_slot_free  (FUN_a0137644)
 *
 * Wait until the input processor's command slot is free; at most 100 rounds if the argument is set.
 * Returns: 1 when the slot is free, 0 when the 100 rounds ran out
 * Note: With argument 0 it polls without limit; with a non-zero argument it sleeps one tick after each busy
 *   read. No routine calls it.
 * Name basis: derived - first word at offset 0x80 of mailbox portal 1 reads 0; the round limit applies only
 *   when the argument is non-zero
 *
 * Matching notes
 * --------------
 * FUN_a0137644, flags -mcpu=v8 -O3 -g. Source form: one polling loop with the 'wait != 0' timeout step inside it
 * (u8 counter tries = 100, u8 result ok = 0 set before the loop); the compiler unswitches the loop on the argument,
 * which gives the two loop copies at 0xa0137674 and 0xa01376a0 and keeps the result in %l2.
 */
extern void ipc_mailbox_read(unsigned char portal, unsigned char offset, unsigned int *buf, unsigned char count);
extern void timer_sleep_ticks(int ticks);

#define IPC_PORTAL_INPUT_CPU  1     /* mailbox portal of the input processor */
#define IPC_COMMAND_SLOT      0x80  /* the slot into which ipc_send_command writes a command; word 0 is 0 when free */
#define IPC_WAIT_TRIES        100

/*
 * Wait until word 0 of the command slot of the input processor (portal 1, offset 0x80) reads 0, which means the
 * input program has taken the last command. Returns 1 when the slot is free, 0 when the wait ran out. Nothing in the
 * firmware calls this routine.
 *   limited: 0 = poll until the slot is free, with no time limit;
 *            non-zero = at most 100 reads, with a one-tick sleep after each busy read
 */
unsigned char ipc_wait_command_slot_free(unsigned char limited)
{
    unsigned int slot[8] = {0};
    unsigned char tries = IPC_WAIT_TRIES;
    unsigned char ok = 0;

    for (;;) {
        ipc_mailbox_read(IPC_PORTAL_INPUT_CPU, IPC_COMMAND_SLOT, slot, 1);
        if (slot[0] == 0) {
            ok = 1;
            break;
        }
        if (limited != 0) {
            tries--;
            timer_sleep_ticks(1);
            if (tries == 0)
                break;
        }
    }
    return ok;
}
