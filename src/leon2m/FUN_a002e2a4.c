/* leon2m FUN_a002e2a4 @ 0xa002e2a4-0xa002e3c4 (72 words, including the unreachable ret/restore tail at 0xa002e3bc),
 * flags -mcpu=v8 -O3 -g. Called from many places (FUN_a002e764, FUN_a008a434, FUN_a00a93bc, FUN_a0123cf0, ...).
 * When bit 0 of the register at 0xcf00ed40 is clear: tail-calls FUN_a002d1a0(0x28). Otherwise t0 = FUN_a002d588()
 * and FUN_a002d594(t0) gives the time since t0: when bit 4 of 0xcf00ed58 is clear it waits while bit 7 of 0xcf00ee1c
 * is set (as long as the time is below 50), then while it is clear (below 100); when bit 4 is set it waits for the
 * opposite levels in the same order.
 * Source form: each wait loop tests the time in the loop condition and the bit 7 level in the body with 'break'
 * (with both tests in one '&&' condition the 0xcf00ec00 high part of the entry is reused in the else arm and the
 * loop temporaries take other registers).
 */
#define REG(a) (*(volatile unsigned int *)(a))
extern unsigned short FUN_a002d588(void);
extern unsigned short FUN_a002d594(unsigned short);
extern void FUN_a002d1a0(unsigned short);

void FUN_a002e2a4(void)
{
    unsigned short t0;

    if (!(REG(0xcf00ed40) & 1)) {
        FUN_a002d1a0(0x28);
        return;
    }
    if (!(REG(0xcf00ed58) & 0x10)) {
        t0 = FUN_a002d588();
        while (FUN_a002d594(t0) < 50) {
            if (!(REG(0xcf00ee1c) & 0x80))
                break;
        }
        while (FUN_a002d594(t0) < 100) {
            if (REG(0xcf00ee1c) & 0x80)
                break;
        }
    } else {
        t0 = FUN_a002d588();
        while (FUN_a002d594(t0) < 50) {
            if (REG(0xcf00ee1c) & 0x80)
                break;
        }
        while (FUN_a002d594(t0) < 100) {
            if (!(REG(0xcf00ee1c) & 0x80))
                break;
        }
    }
}
