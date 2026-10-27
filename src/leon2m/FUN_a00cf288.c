/* FUN_a00cf288 (leon2m 0xa00cf288-0xa00cf2d4, 76 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Stores a halfword to *p: 0x80 when a is below 0x60; when a is 0x60, 0x80, 0x100, 0x180 or 0x200 for b = 0, 1, 2
 * or any other value; nothing for a above 0x60. Nothing in the image refers to it: no call, branch, sethi/or
 * constant or address word. It lies between FUN_a00cf280 and FUN_a00cf2d4.
 */
void FUN_a00cf288(unsigned char a, unsigned char b, unsigned short *p)
{
    if (a < 0x60)
        *p = 0x80;
    else if (a == 0x60) {
        if (b == 0)
            *p = 0x80;
        else if (b == 1)
            *p = 0x100;
        else if (b == 2)
            *p = 0x180;
        else
            *p = 0x200;
    }
}
