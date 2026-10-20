/* FUN_a00abb30 (leon2s 0xa00abb30-0xa00abba8, 120 bytes), flags -mcpu=v8 -Os -g.
 * Clears bits 0-2 of hardware register 0xcf01143c and bit 7 of 0xcf011674, calls FUN_a00a6c98(port, 0xc0, 0x10,
 * 0), then clears bits 4, 1, 2 and 3 of 0xcf01147c one at a time (four read-modify-writes).
 */
#define R(a) (*(volatile unsigned int *)(a))
extern void FUN_a00a6c98(unsigned char, unsigned short, unsigned int, unsigned int);

void FUN_a00abb30(unsigned char port)
{
    R(0xcf01143c) &= ~7;
    R(0xcf011674) &= ~0x80;
    FUN_a00a6c98(port, 0xc0, 0x10, 0);
    R(0xcf01147c) &= ~0x10;
    R(0xcf01147c) &= ~2;
    R(0xcf01147c) &= ~4;
    R(0xcf01147c) &= ~8;
}
