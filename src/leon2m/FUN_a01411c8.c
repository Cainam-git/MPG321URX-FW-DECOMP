/* leon2m FUN_a01411c8 @ 0xa01411c8-0xa01411f8 (12 words), flags -mcpu=v8 -O3 -g.
 * Code facts: r = FUN_a011909c() (u8); returns byte [((p << 4) + r) * 2] of the ROM table at 0x1a3648
 * (16 two-byte entries per p; first byte of each entry).
 * Fix vs the autoc draft (76.92): the mask is a separate first statement 'p &= 0xff;' on the unsigned int param
 * (fw 'and %i0, 0xff, %i0' in place before the call; a u8 param or '(param_1 & 0xff)' inside the expression
 * masks into a fresh register after the call, 76.92); FUN_a011909c returns u8 (its asm: & 0xf). Aids: none.
 */
extern unsigned char DAT_001a3648[];
extern unsigned char FUN_a011909c(void);

unsigned char FUN_a01411c8(unsigned int p)
{
    unsigned int r;
    p &= 0xff;
    r = FUN_a011909c();
    return DAT_001a3648[((p << 4) + r) * 2];
}
