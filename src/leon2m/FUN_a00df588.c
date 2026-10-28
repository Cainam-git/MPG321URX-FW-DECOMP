/* leon2m FUN_a00df588 @ 0xa00df588-0xa00df5dc (21 words), flags -mcpu=v8 -O3 -g.
 * Read-modify-write of bits lo..hi of the register addr: lo and hi are the smaller and the larger of a and b,
 * mask = (2 << hi) - (1 << lo) (written (1 << hi) - (1 << lo) + (1 << hi)); writes
 * (FUN_a00e021c(addr) & ~mask) | ((v << lo) & mask) with FUN_a00e0228 (tail call).
 * Source form: after the mask, the variable hi is reused for the shift count ('hi = lo; v <<= hi;'); a separate
 * shift variable or 'v <<= lo' gives another register choice in the a < b arm. Aids: none.
 */
extern unsigned int FUN_a00e021c(unsigned int addr);
extern void FUN_a00e0228(unsigned int addr, unsigned int val);

void FUN_a00df588(unsigned int addr, unsigned char a, unsigned char b, unsigned int v)
{
    unsigned char lo = b, hi = a;
    unsigned int mask;

    if (a < b) {
        lo = a;
        hi = b;
    }
    mask = (1 << hi) - (1 << lo) + (1 << hi);
    hi = lo;
    v <<= hi;
    FUN_a00e0228(addr, (FUN_a00e021c(addr) & ~mask) | (v & mask));
}
