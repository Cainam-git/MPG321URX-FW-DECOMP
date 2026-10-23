/* FUN_a00a79c4 (leon2s 0xa00a79c4-0xa00a7a5c, 152 bytes, leaf), flags -mcpu=v8 -Os -g.
 * Reads three consecutive 8-bit hardware registers reg, reg + 1 and reg + 2 of block port (ports 0..4 only,
 * otherwise returns 0). Register address = ((u16 base table at 0xa00b4d7a [port] + reg) * 4) | 0xcf000000, the
 * same table as FUN_a00a78b4. Result: for reg 0x50 the third register word (unmasked) OR'd with
 * (first << 16) | (second << 8); for every other reg (third << 16) | (second << 8) | first.
 * Source form: the first two values are unsigned char locals (the byte mask comes from the conversion), and the
 * else arm shifts v in place (v <<= 8; v |= mid; ...); a shift into a new value lets the scheduler move it
 * above the reg == 0x50 branch. The register pointer is volatile because it addresses hardware registers.
 */
extern unsigned char DAT_a00b4d7a;

static __inline__ unsigned int rd(unsigned int a)
{
    return *(volatile unsigned int *)((a * 4) | 0xcf000000);
}

unsigned int FUN_a00a79c4(unsigned int port, unsigned short reg)
{
    unsigned int v = 0;
    unsigned int base;
    unsigned char lo, mid;

    if ((port & 0xff) < 5) {
        base = *(unsigned short *)(&DAT_a00b4d7a + (port & 0xff) * 2) + reg;
        lo = rd(base);
        mid = rd(base + 1);
        v = rd(base + 2);
        if (reg == 0x50) {
            v |= lo << 16 | mid << 8;
        } else {
            v <<= 8;
            v |= mid;
            v <<= 8;
            v |= lo;
        }
    }
    return v;
}
