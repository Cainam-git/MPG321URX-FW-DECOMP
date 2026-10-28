/* FUN_a0089e74 (leon2s 0xa0089e74-0xa0089f00, 140 bytes), flags -mcpu=v8 -Os -g.
 * When bit 1 of hardware register 0xcf03c940 is set, calls FUN_a00a7940(i, 0x7d, 0x10, 1) for i = 1..4 and
 * prints DAT_a0068c60 ("DPTX_EnableEDPFastmutePattern %d") through FUN_a0073044; otherwise calls
 * FUN_a00a7940(i, 0x7d, 0x10, 0) for i = 1..4 and prints DAT_a0068c90 ("DPTX_DisableEDPFastmutePattern %d").
 * Both prints pass the final counter value (5) for the %d field.
 * The byte counter is initialised at its declaration (the firmware sets it before the test).
 */
#define REG_C940 (*(volatile unsigned int *)0xcf03c940)
extern char DAT_a0068c60[], DAT_a0068c90[];
extern int FUN_a0073044(const char *, ...);
extern void FUN_a00a7940(unsigned int, short, unsigned int, unsigned int);

void FUN_a0089e74(void)
{
    unsigned char i = 1;

    if (REG_C940 & 2) {
        for (; i <= 4; i++)
            FUN_a00a7940(i, 0x7d, 0x10, 1);
        FUN_a0073044(DAT_a0068c60, i);
    } else {
        for (; i <= 4; i++)
            FUN_a00a7940(i, 0x7d, 0x10, 0);
        FUN_a0073044(DAT_a0068c90, i);
    }
}
