/* FUN_a011e6dc: fixed register set-up in the 0xcf016480..0xcf0164f4 block: 0x22 to 0xcf016480..0xcf01648c,
 * bits 0-3 set in 0xcf016490, 0xa / 0xc3 / 0 / 0x10 / 4 / 0x22 to 0xcf0164e0..0xcf0164f4, bit 2 set in
 * 0xcf0164c0, bits 6-7 cleared in 0xcf0164c4, 0xcf016408 read and written back unchanged, 0x20 to 0xcf01640c.
 * Callers: FUN_a014fe78, FUN_a01502c4.
 * The read-back of 0xcf016408 is written as '|= 0' (a volatile read-modify-write that GCC keeps as ld/st).
 */
#define R(a) (*(volatile unsigned int *)(a))

void FUN_a011e6dc(void)
{
    R(0xcf016480) = 0x22;
    R(0xcf016484) = 0x22;
    R(0xcf016488) = 0x22;
    R(0xcf01648c) = 0x22;
    R(0xcf016490) |= 0xf;
    R(0xcf0164e0) = 0xa;
    R(0xcf0164e4) = 0xc3;
    R(0xcf0164e8) = 0;
    R(0xcf0164ec) = 0x10;
    R(0xcf0164f0) = 4;
    R(0xcf0164f4) = 0x22;
    R(0xcf0164c0) |= 4;
    R(0xcf0164c4) &= ~0xc0;
    R(0xcf016408) |= 0;
    R(0xcf01640c) = 0x20;
}
