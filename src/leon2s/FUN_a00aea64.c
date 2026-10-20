/* FUN_a00aea64 (leon2s 0xa00aea64-0xa00aeadc, 120 bytes), flags -mcpu=v8 -Os -g.
 * a = FUN_a00acac0(port) (halfword), b = bits 4-7 of FUN_a00a6bb8(port, 0x481), c = FUN_a008d800(). Returns 1
 * when c > 0x83, b == 4 and a == 0xd70, else 0. Source form: the c test is a separate outer if.
 */
extern unsigned short FUN_a00acac0(unsigned char);
extern unsigned int FUN_a00a6bb8(unsigned char, unsigned short);
extern unsigned char FUN_a008d800(void);

unsigned char FUN_a00aea64(unsigned char port)
{
    unsigned short a = FUN_a00acac0(port);
    unsigned char b = (unsigned char)FUN_a00a6bb8(port, 0x481) >> 4;
    unsigned char c = FUN_a008d800();

    if (c > 0x83) {
        if (b == 4 && a == 0xd70)
            return 1;
    }
    return 0;
}
