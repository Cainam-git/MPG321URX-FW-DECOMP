/* leon2m FUN_a00e0134 @ 0xa00e0134  MATCH (-mcpu=v8 -O3 -g)
 * Adds (add != 0) or subtracts (add == 0) delta within the bits of mask of an 8-bit PHY register value.
 * Callers: FUN_a00e0e44 (two calls). Parameters: phy, addr, delta, mask, limit, keep, sat, add.
 * First counts the 0/1 transitions over the 32 bits of mask; unless there are one or two (one contiguous run of
 * set bits), it calls FUN_a00df80c and FUN_a00e0bc0 and prints "Invalid mask from phy_reg_add/sub ...".
 * Otherwise it reads the register with FUN_a00e02ec(phy, addr), computes (value & mask) +/- (delta & mask) as a
 * byte and compares it with limit & mask: above the limit when adding, below it when subtracting, the field is set
 * to sat & mask, or left unchanged when keep != 0. The result (value & 0xff & ~mask) | field is written with
 * FUN_a00e03b0(phy, addr, value).
 */
extern void FUN_a00df80c(void);
extern void FUN_a00e0bc0(void);
extern int FUN_a00df170(const char *fmt, ...);
extern unsigned int FUN_a00e02ec(int phy, unsigned int addr);
extern void FUN_a00e03b0(int phy, unsigned int addr, unsigned int val);

void FUN_a00e0134(int phy, unsigned int addr, unsigned int delta, unsigned int mask,
                  unsigned int limit, int keep, unsigned int sat, int add)
{
    unsigned int prev, bit, edges;
    int i;
    unsigned int cur, v, m;

    prev = 0;
    edges = 0;
    for (i = 0; i < 32; i++) {
        bit = (mask >> i) & 1;
        edges += bit ^ prev;
        prev = bit;
    }
    sat &= mask;
    if (edges - 1 > 1) {
        FUN_a00df80c();
        FUN_a00e0bc0();
        FUN_a00df170("Invalid mask from phy_reg_add/sub (non-continued set bits), abort command\n");
        return;
    }
    delta &= mask;
    limit &= mask;
    cur = FUN_a00e02ec(phy, addr);
    m = cur & mask;
    if (add != 0) {
        v = (m + delta) & 0xff;
        if (v > limit)
            goto clamp;
    } else {
        v = (m - delta) & 0xff;
        if (v < limit)
            goto clamp;
    }
    FUN_a00e03b0(phy, addr, ((unsigned char)cur & ~mask) | (v & mask));
    return;
clamp:
    if (keep != 0)
        return;
    FUN_a00e03b0(phy, addr, ((unsigned char)cur & ~mask) | sat);
}
