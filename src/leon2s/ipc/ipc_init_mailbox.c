/* ipc_init_mailbox  (FUN_a0072958)
 *
 * Write 0 to the word at 0x9F130000, 0x100 below mailbox portal 1, at start-up.
 * Name basis: descriptive - writes 0 to 0x9F130000 (mailbox portal 1 starts at 0x9F130100); called by main
 *   init before input_init_receivers
 *
 * Matching notes
 * --------------
 * FUN_a0072958 (leon2s 0xa0072958), flags -mcpu=v8 -Os -g.
 * The write goes through reg_write32_copy; Ghidra's type names are kept.
 */
extern int reg_write32_copy();

#define MAILBOX_INPUT_CPU_CONTROL 0x9f130000    /* the word 0x100 below the first word of portal 1 (0x9F130100) */

/*
 * Write 0 to the word at 0x9F130000, 0x100 below portal 1 of the mailbox.
 * Called by the main start-up routine before input_init_receivers.
 */
void ipc_init_mailbox(void)

{
  reg_write32_copy(MAILBOX_INPUT_CPU_CONTROL,0);
  return;
}
