/* FUN_a014eaa8 (leon2m 0xa014eaa8-0xa014ead0, 40 bytes, leaf), flags -mcpu=v8 -O3.
 * Shifts the halfword DAT_a802cc82 right by 4, puts c in its top four bits (c << 12) and returns the four bits
 * shifted out (old value & 0xf). Nothing in the image refers to it: no call, branch, sethi/or constant or address
 * word. It lies between FUN_a014ea54 and FUN_a014ead0.
 */
extern unsigned short DAT_a802cc82;

unsigned char FUN_a014eaa8(unsigned char c)
{
    unsigned short x = DAT_a802cc82;

    DAT_a802cc82 = (x >> 4) | (c << 12);
    return x & 0xf;
}
