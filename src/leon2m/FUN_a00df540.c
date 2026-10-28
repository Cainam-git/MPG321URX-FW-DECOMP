/* leon2m FUN_a00df540 @ 0xa00df540-0xa00df588 (18 words), flags -mcpu=v8 -O3 -g.
 * Reads bits lo..hi of the register addr: lo and hi are the smaller and the larger of a and b,
 * mask = (2 << hi) - (1 << lo) (written (1 << hi) - (1 << lo) + (1 << hi)); returns
 * (FUN_a00e021c(addr) & mask) >> lo. Read counterpart of the next function, FUN_a00df588.
 * Source form: as in FUN_a00df588, after the mask the variable hi is reused for the shift count ('hi = lo;');
 * the shift by lo directly gives another register choice for lo.
 */
extern unsigned int FUN_a00e021c(unsigned int addr);

unsigned int FUN_a00df540(unsigned int addr, unsigned char a, unsigned char b)
{
    unsigned char lo = b, hi = a;
    unsigned int mask;

    if (a < b) {
        lo = a;
        hi = b;
    }
    mask = (1 << hi) - (1 << lo) + (1 << hi);
    hi = lo;
    return (FUN_a00e021c(addr) & mask) >> hi;
}
