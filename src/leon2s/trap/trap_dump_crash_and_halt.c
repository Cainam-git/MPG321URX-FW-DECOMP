/* trap_dump_crash_and_halt  (CED_ALL)
 *
 * Print the crash report (PC, trap name, registers, stack, code) and halt.
 * Note: The old label CED_ALL is not printed by the firmware.
 * Name basis: proven - prints 'System Crash.', 'CPU registers:', 'System Halt.'; crash hook set at start-up;
 *   same job as leon2m's
 *
 * Matching notes
 * --------------
 * CED_ALL (leon2s 0xa0072cb8-0xa0072e60, 424 bytes), flags -mcpu=v8 -Os -g.
 * Source forms the exact build depends on:
 *  - the trap type is computed once, before the table loop;
 *  - each dump reads through a volatile unsigned int pointer, so that the dumped word is loaded before each print
 *    call and not in its delay slot (GCC does that only for volatile loads);
 *  - " " (DAT_a006c690) and "\n" (s_a0069ee8, the tail of another message) are strings shared with other code.
 */
/* Saved crash record at fixed addresses (PC, trap word, stack pointer, 40 register words). */
#define CRASH_PC   (*(unsigned int *)0xa807ff84)
#define CRASH_TBR  (*(unsigned int *)0xa807ff8c)
#define CRASH_SP   (*(volatile unsigned int **)0xa807ff94)
#define CRASH_REGS ((volatile unsigned int *)0xa807ff60)     /* 40 saved words */

struct trap_name {
    unsigned int tt;
    const char *name;
};
extern struct trap_name trap_name_table[];
extern const char DAT_a006c690[];
extern const char s_a0069ee8[];
extern int uart_put_string(const char *);
extern void uart_put_hex32(unsigned int);

/*
 * Report a crash on the serial port, then stop for good. The report is: the saved PC; the name of the trap type
 * (bits 4..11 of the saved trap base word, looked up in trap_name_table; nothing is printed for a type that is not
 * in the table); then three dumps of 8 words per line: the 40 saved register words, 16 words of the stack at the
 * saved stack pointer, and 32 words of code starting 16 bytes before the saved PC. The last output is
 * "System Halt." and the routine never returns.
 */
void trap_dump_crash_and_halt(void)
{
    unsigned int pc;
    volatile unsigned int *sp;
    int i;
    unsigned int tt;

    uart_put_string("\n\nSystem Crash.\nPC= ");
    pc = CRASH_PC;
    uart_put_hex32(pc);
    uart_put_string(", Exception= ");
    /* Trap type = bits 4..11 of the saved trap base register word. */
    tt = (CRASH_TBR & 0xff0) >> 4;
    for (i = 0; i <= 16; i++) {
        if (trap_name_table[i].tt == tt) {
            uart_put_string(trap_name_table[i].name);
            break;
        }
    }
    /* The three dumps share one form: hex word, blank, and a line break after every 8th word. */
    uart_put_string("\nCPU registers:\n");
    sp = CRASH_REGS;
    for (i = 0; i < 40; i++) {
        uart_put_hex32(sp[i]);
        uart_put_string(DAT_a006c690);  /* " " */
        if ((i & 7) == 7)
            uart_put_string(s_a0069ee8);  /* "\n" */
    }
    uart_put_string("\nStack contents:\n");
    sp = CRASH_SP;
    for (i = 0; i < 16; i++) {
        uart_put_hex32(sp[i]);
        uart_put_string(DAT_a006c690);  /* " " */
        if ((i & 7) == 7)
            uart_put_string(s_a0069ee8);  /* "\n" */
    }
    uart_put_string("\nCode contents:\n");
    sp = (volatile unsigned int *)(pc - 16);
    for (i = 0; i < 32; i++) {
        uart_put_hex32(sp[i]);
        uart_put_string(DAT_a006c690);  /* " " */
        if ((i & 7) == 7)
            uart_put_string(s_a0069ee8);  /* "\n" */
    }
    uart_put_string("\nSystem Halt.");
    for (;;)
        ;
}
