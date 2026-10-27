/* FUN_a00fe7d8 (leon2m 0xa00fe7d8-0xa00fe820, 72 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Returns 3 when bit 5 of the word register 0xcf02dc04 is clear; otherwise, from bits 6..7 of the word register
 * 0xcf0116dc (m = value & 0xc0): 0 for m = 0, 1 for m = 0x80, 2 for any other value. Nothing in the image refers to
 * it: no call, branch, sethi/or constant or address word. It lies between FUN_a00fe718 and FUN_a00fe820. Source
 * form: r = 3 as default, an if/else chain on m, return r & 3.
 */
#define REGA (*(volatile unsigned int *)0xcf02dc04)
#define REGB (*(volatile unsigned int *)0xcf0116dc)
unsigned char FUN_a00fe7d8(void)
{
    unsigned char r = 3;
    unsigned int m;
    if (REGA & 0x20) {
        m = REGB & 0xc0;
        if (m == 0)
            r = 0;
        else if (m == 0x80)
            r = 1;
        else
            r = 2;
    }
    return r & 3;
}
