/* FUN_a0089f00 (leon2s 0xa0089f00-0xa0089f84, 132 bytes), flags -mcpu=v8 -Os -g.
 * When bit 2 of hardware register 0xcf03c940 is set, calls FUN_a00a78fc(i, 0x11, 0x1b) for i = 1..4 and prints
 * DAT_a0068cc0 ("DPTX_EnableEDPPostPattern %d") through FUN_a0073044; otherwise calls FUN_a00a78fc(i, 0x11, 0)
 * for i = 1..4 and prints DAT_a0068cf0 ("DPTX_DisableEDPPostPattern %d"). Both prints pass the final counter value
 * (5) for the %d field.
 * The byte counter is initialised at its declaration (the firmware sets it before the test).
 */
#define REG_C940 (*(volatile unsigned int *)0xcf03c940)
extern char DAT_a0068cc0[], DAT_a0068cf0[];
extern int FUN_a0073044(const char *, ...);
extern void FUN_a00a78fc(unsigned int, unsigned short, unsigned int);

void FUN_a0089f00(void)
{
    unsigned char i = 1;

    if (REG_C940 & 4) {
        for (; i <= 4; i++)
            FUN_a00a78fc(i, 0x11, 0x1b);
        FUN_a0073044(DAT_a0068cc0, i);
    } else {
        for (; i <= 4; i++)
            FUN_a00a78fc(i, 0x11, 0);
        FUN_a0073044(DAT_a0068cf0, i);
    }
}
