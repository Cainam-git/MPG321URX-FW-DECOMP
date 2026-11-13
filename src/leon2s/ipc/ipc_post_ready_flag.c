/* ipc_post_ready_flag  (FUN_a006fb00)
 *
 * Set the ready bit in mailbox slot 0 for the main processor.
 * Note: Also sets ipc_ready_posted_flag; called by the start-up assembly sys_main_part4.
 * Name basis: derived - bit 0 of the status word written to slot 0 word 0; the main program's start-up waits
 *   for that bit ('wait sub init', ipc_input_cpu_get_ready_bit)
 *
 * Matching notes
 * --------------
 * FUN_a006fb00 (leon2s 0xa006fb00), flags -mcpu=v8 -Os -g.
 * The status word is reached through a local pointer.
 */
extern unsigned int ipc_slot0_status_word;
extern unsigned char ipc_ready_posted_flag;
extern void ipc_write_mailbox_slot(unsigned int, int, int, unsigned int);

/*
 * Set bit 0 of the status word that is kept for slot 0 word 0 of the input-processor mailbox, set
 * ipc_ready_posted_flag and write the word to the mailbox. The main program's start-up waits for this bit
 * ('wait sub init'). Called by the start-up assembly sys_main_part4 (sys/sys_main_part4.S) after the set-up routine.
 */
void ipc_post_ready_flag(void)
{
    unsigned int *status_word = &ipc_slot0_status_word;
    *status_word |= 1;
    ipc_ready_posted_flag = 1;
    ipc_write_mailbox_slot(0, 0, (int)status_word, 1);
    return;
}
