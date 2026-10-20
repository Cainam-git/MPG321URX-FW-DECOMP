/* FUN_a0062b64 (leon2s 0xa0062b64-0xa0062b94, 48 bytes), flags -mcpu=v8 -Os -g.
 * With h = halfword DAT_a8078aa4 and r = FUN_a0062a34(x), returns (h << 18) + (0x1000 - h) * (r >> 2).
 * FUN_a0062a34 takes the value x and returns an unsigned word; the product and sum are unsigned 32-bit.
 */
extern unsigned short DAT_a8078aa4;
extern unsigned int FUN_a0062a34(unsigned int);

unsigned int FUN_a0062b64(unsigned int x)
{
    unsigned int h = DAT_a8078aa4;

    return (h << 18) + (0x1000 - h) * (FUN_a0062a34(x) >> 2);
}
