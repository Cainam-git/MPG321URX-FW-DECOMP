/* dbg_cmd_mailbox_dump  (FUN_a0070704)
 *
 * Console command: print the mailbox contents.
 * Name basis: derived - entry of the console command table (word 0xA00B4F10); calls MAILBOX_DUMP when the
 *   argument is 0
 *
 * Matching notes
 * --------------
 * FUN_a0070704 (leon2s 0xa0070704-0xa0070728, 36 bytes), flags -mcpu=v8 -Os -g.
 * Tail call of FUN_a0072b04 (the routine in MAILBOX_DUMP.c); the routine has no register window (no save). Its
 * address is the word at 0xa00b4f10.
 */
extern void MAILBOX_DUMP(void);

/*
 * Console command: print the mailbox contents (FUN_a0072b04, the routine in MAILBOX_DUMP.c). Entry of the console
 * command table (the word at 0xa00b4f10).
 *   arg: the command's argument; the dump is printed only when it is 0
 */
void dbg_cmd_mailbox_dump(int arg)
{
    if (arg == 0)
        MAILBOX_DUMP();
}
