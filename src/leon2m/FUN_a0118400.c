/* leon2m FUN_a0118400 @ 0xa0118400..0xa011855c (87 words)  start-up step 2 (FUN_a015266c step 5, called with
 * (0x1E, 0x32) = (30, 50)): programs the same two values into three identical clock blocks.
 * Code: b == 0: clears bit 0 of 0xCF0129D0, 0xCF012B10 and 0xCF014090 and returns. Otherwise a is
 * forced to 30 unless 25 <= a <= 50, b to 20 unless 5 <= b <= 250; q = (u8)(1500 / a), r = (u8)(((a * b) << 15) /
 * 15000000); for each block base B in 0xCF0129D0, 0xCF012B10, 0xCF014090: B+8 = q, B+0xC = r, B+8 |= 0x80; then bit 0 of
 * all three B is set. FW.021 call (30, 50): q = 50, r = 3 (1500 * 32768 / 15e6 = 3.28).
 * Register writes only: no read-back loop, no wait, no failure path.
 * Exact form: u16 parameters, the range checks as (u16)(x - lo) > n, 1500 / a signed (int promotion of the u16).
 */
#define R(a) (*(volatile unsigned int *)(a))

void FUN_a0118400(unsigned short a, unsigned short b)
{
    unsigned char q, r;
    if (b == 0) {
        R(0xcf0129d0) &= ~1;
        R(0xcf012b10) &= ~1;
        R(0xcf014090) &= ~1;
        return;
    }
    if ((unsigned short)(a - 25) > 25)
        a = 30;
    q = 1500 / a;
    if ((unsigned short)(b - 5) > 0xf5)
        b = 20;
    r = ((unsigned int)(b * a) << 15) / 15000000;
    R(0xcf0129d8) = q;
    R(0xcf0129dc) = r;
    R(0xcf0129d8) |= 0x80;
    R(0xcf012b18) = q;
    R(0xcf012b1c) = r;
    R(0xcf012b18) |= 0x80;
    R(0xcf014098) = q;
    R(0xcf01409c) = r;
    R(0xcf014098) |= 0x80;
    R(0xcf0129d0) |= 1;
    R(0xcf012b10) |= 1;
    R(0xcf014090) |= 1;
}
