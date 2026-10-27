/* FUN_a011a974 (leon2m 0xa011a974-0xa011a9e4, 112 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * For the word register r at 0xcf000000 + 4 * (DAT_a8027aa8[k] + 0x30): when on is non-zero writes the low byte of
 * r | 0x2f, otherwise r & 0xd0. Nothing in the image refers to it: no call, branch, sethi/or constant or address
 * word. It lies between FUN_a011a848 and FUN_a011a9e4. Source form: the register address is computed separately in
 * each arm.
 */
extern unsigned short DAT_a8027aa8[];

void FUN_a011a974(unsigned char on, unsigned char k)
{
    volatile unsigned int *p;

    if (on) {
        p = (volatile unsigned int *)(0xcf000000 | ((DAT_a8027aa8[k] + 0x30) << 2));
        *p = (unsigned char)(*p | 0x2f);
    } else {
        p = (volatile unsigned int *)(0xcf000000 | ((DAT_a8027aa8[k] + 0x30) << 2));
        *p &= 0xd0;
    }
}
