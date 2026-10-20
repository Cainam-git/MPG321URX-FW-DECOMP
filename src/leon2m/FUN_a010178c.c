/* leon2m FUN_a010178c @ 0xa010178c-0xa0101858 (51 words), flags -mcpu=v8 -O3 -g -msoft-float.
 * Clamps x to 0x3c..0x2af8, clears bit 2 of hardware register 0xcf0160c0 and computes
 * v = (unsigned int)(12000000.0f / x - 0.5) with the libgcc soft-float routines (FUN_a0155c40 = __floatsisf,
 * FUN_a0155a18 = __divsf3, FUN_a0155d90 = __extendsfdf2, FUN_a01560fc = __subdf3, FUN_a0155160 = __fixunsdfsi;
 * constants 12000000.0f at 0x19a634 and 0.5 at 0x19a638). Then writes (0xcf0160cc & 0x20) | b << 6 | 0x1a to
 * 0xcf0160cc, bits 10-17 of v to 0xcf0160d0, 0xff to 0xcf0160d4, and sets bit 0 of 0xcf0160f4.
 * Called from FUN_a0129b44. Source form: b << 6 is computed into a variable before the register read (scheduling).
 */
#define REG_cf0160c0 (*(volatile unsigned int *)0xcf0160c0)
#define REG_cf0160cc (*(volatile unsigned int *)0xcf0160cc)
#define REG_cf0160d0 (*(volatile unsigned int *)0xcf0160d0)
#define REG_cf0160d4 (*(volatile unsigned int *)0xcf0160d4)
#define REG_cf0160f4 (*(volatile unsigned int *)0xcf0160f4)

void FUN_a010178c(unsigned short x, unsigned int b)
{
    unsigned int v;
    unsigned int s;

    if (x > 0x2af8)
        x = 0x2af8;
    if (x < 0x3c)
        x = 0x3c;
    REG_cf0160c0 &= ~4;
    v = (unsigned int)(12000000.0f / x - 0.5);
    s = b << 6;
    REG_cf0160cc = (REG_cf0160cc & 0x20) | s | 0x1a;
    REG_cf0160d0 = (v >> 10) & 0xff;
    REG_cf0160d4 = 0xff;
    REG_cf0160f4 |= 1;
}
