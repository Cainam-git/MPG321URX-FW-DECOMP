/* CED_ALL (leon2s 0xa0072cb8-0xa0072e60, 424 bytes), flags -mcpu=v8 -Os -g.
 * Crash report printed after a trap, then a halt loop. Prints "System Crash. PC=" with the saved PC word at
 * 0xa807ff84 (FUN_a0061348 prints a word in hex, FUN_a0061280 prints a string), then the name of the trap type
 * (bits 4..11 of the saved word at 0xa807ff8c) looked up in the 17-entry table DAT_a8076104 of {type, name}.
 * Then three dumps of 8 words per line: the 40 saved registers at 0xa807ff60, 16 words of the stack at the
 * pointer saved at 0xa807ff94, and 32 words of code starting 16 bytes before the saved PC. Ends with
 * "System Halt." and an endless loop.
 * Strings: " " (s_a006c690) and "
" (s_a0069ee8, the tail of another message) are shared firmware strings.
 * Source forms: the trap type is computed once before the table loop; each dump reads through a
 * volatile unsigned int pointer (the dumped words are loaded before each print call, never in its delay
 * slot, which GCC only does for volatile loads).
 */
#define CRASH_PC   (*(unsigned int *)0xa807ff84)
#define CRASH_TBR  (*(unsigned int *)0xa807ff8c)
#define CRASH_SP   (*(volatile unsigned int **)0xa807ff94)
#define CRASH_REGS ((volatile unsigned int *)0xa807ff60)

struct trap_name {
    unsigned int tt;
    const char *name;
};
extern struct trap_name DAT_a8076104[];
extern const char s_a006c690[];
extern const char s_a0069ee8[];
extern int FUN_a0061280(const char *);
extern void FUN_a0061348(unsigned int);

void CED_ALL(void)
{
    unsigned int pc;
    volatile unsigned int *sp;
    int i;
    unsigned int tt;

    FUN_a0061280("\n\nSystem Crash.\nPC= ");
    pc = CRASH_PC;
    FUN_a0061348(pc);
    FUN_a0061280(", Exception= ");
    tt = (CRASH_TBR & 0xff0) >> 4;
    for (i = 0; i <= 16; i++) {
        if (DAT_a8076104[i].tt == tt) {
            FUN_a0061280(DAT_a8076104[i].name);
            break;
        }
    }
    FUN_a0061280("\nCPU registers:\n");
    sp = CRASH_REGS;
    for (i = 0; i < 40; i++) {
        FUN_a0061348(sp[i]);
        FUN_a0061280(s_a006c690);
        if ((i & 7) == 7)
            FUN_a0061280(s_a0069ee8);
    }
    FUN_a0061280("\nStack contents:\n");
    sp = CRASH_SP;
    for (i = 0; i < 16; i++) {
        FUN_a0061348(sp[i]);
        FUN_a0061280(s_a006c690);
        if ((i & 7) == 7)
            FUN_a0061280(s_a0069ee8);
    }
    FUN_a0061280("\nCode contents:\n");
    sp = (volatile unsigned int *)(pc - 16);
    for (i = 0; i < 32; i++) {
        FUN_a0061348(sp[i]);
        FUN_a0061280(s_a006c690);
        if ((i & 7) == 7)
            FUN_a0061280(s_a0069ee8);
    }
    FUN_a0061280("\nSystem Halt.");
    for (;;)
        ;
}
