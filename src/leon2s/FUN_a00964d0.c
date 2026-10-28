/* leon2s FUN_a00964d0 @ 0xa00964d0-0xa0096538 (26 words), flags -mcpu=v8 -Os -g.
 * Code facts: writes (b << 4) | a, the low byte of w and the high byte of w to the hardware registers
 * 0xcf0146c0 / 0xcf0146c8 / 0xcf0146cc (p == 0) or 0xcf014700 / 0xcf014708 / 0xcf01470c (p != 0).
 * All six register addresses are set up before the p test. volatile only on the 0xcf... hardware registers.
 * Aids: none.
 */
#define R(a) (*(volatile unsigned int *)(a))

void FUN_a00964d0(unsigned char p, unsigned char a, unsigned char b, unsigned short w)
{
    if (p == 0) {
        R(0xcf0146c0) = (b << 4) | a;
        R(0xcf0146c8) = (unsigned char)w;
        R(0xcf0146cc) = w >> 8;
    } else {
        R(0xcf014700) = (b << 4) | a;
        R(0xcf014708) = (unsigned char)w;
        R(0xcf01470c) = w >> 8;
    }
}
