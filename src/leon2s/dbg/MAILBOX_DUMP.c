/* MAILBOX_DUMP  (MAILBOX_DUMP)
 *
 * Print the 48 words of mailbox portal 1 on the debug console.
 * Name basis: proven - prints 'MAILBOX_DUMP 0x%d'; ipc_mailbox_read(1, 0, buf, 48)
 *
 * Matching notes
 * --------------
 * leon2s MAILBOX_DUMP @ 0xa0072b04-0xa0072b7c (30 words), flags -mcpu=v8 -Os -g.
 * Source form: lib_memset is declared returning void * (a void prototype moves the %o0 set before %o1/%o2).
 * The buffer is cleared before the read; the %d argument of the last print is the loop counter after the loop.
 */
extern void *lib_memset(void *, int, unsigned int);
extern void ipc_mailbox_read(unsigned char, unsigned char, unsigned int *, unsigned char);
extern void dbg_printf(const char *fmt, ...);

#define MAILBOX_PORTAL   1              /* portal read */
#define MAILBOX_WORDS    0x30           /* words read and printed */

/*
 * Print the first 48 words of mailbox portal 1, one per line as "0x%8lX", then the line "MAILBOX_DUMP 0x%d" with
 * the word count (48, printed in decimal). Console command; the console command table entry dbg_cmd_mailbox_dump ends
 * in a tail call of it.
 */
void MAILBOX_DUMP(void)
{
    unsigned int words[MAILBOX_WORDS];
    unsigned char i;

    lib_memset(words, 0, 0xc0);
    ipc_mailbox_read(MAILBOX_PORTAL, 0, words, MAILBOX_WORDS);
    for (i = 0; i < MAILBOX_WORDS; i++)
        dbg_printf("\r\n 0x%8lX", words[i]);
    dbg_printf("\r\n MAILBOX_DUMP 0x%d", i);
}
