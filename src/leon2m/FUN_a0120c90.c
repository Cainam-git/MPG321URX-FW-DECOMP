/* leon2m FUN_a0120c90 @ 0xa0120c90-0xa0120de4 (85 words), flags -mcpu=v8 -O3 -g -msoft-float (float source;
 * the FUN_a0155xxx/a01560ac callees are the libgcc soft-float routines, see src/leon2m/*.lib).
 * jf 99.00 'bytes differ at 0xa0120d90' = a JUDGE artefact, not a code difference:
 * exact.py strips trailing zero bytes of the .rodata.cst8 pool (data.rstrip(b"\0")), so the double 0.5
 * (3fe00000 00000000) shrinks to 3fe000, is "found" somewhere in parts/leon2m.bin and placed there,
 * instead of being checked at the fw address 0x19a638 (which does hold 0.5) by verify_pool.
 * What it does: the input timing value t.x that the output clock sum FUN_a010325c (and FUN_a014285c,
 * r->h26) uses for port 'port'. Registers via FUN_a00f21f0 (16-bit pair read of the 0x19A2FC block):
 *   h   = reg 0x12 & 0x1fff; outside 147..8000 -> returns 0;
 *   cnt = reg 0x14 & 0x1fff (the frame-period counter FUN_a0120b38 also uses); outside 1027..18750 -> 0;
 *   if bit 1 of FUN_a00f1a90(port, 4) is set AND FUN_a00f1a90(port, 0x54) == 0x20:
 *       f = cnt * 256.0f when the port's 12-byte record DAT_a8027aac[port].div32 == 1, else cnt * 2048.0f;
 *       returns (u16)(unsigned)((double)(f / h) + 0.5)    (rounded; constants at ROM 0x1a2fd8 = 256.0f,
 *       0x1a2fdc = 2048.0f, 0x19a638 = 0.5);
 *   else returns (u16)(FUN_a00f21f0(port, 0x26) + 1).
 * The value is either the scaled ratio cnt * 256 (or 2048) / h, or reg pair
 * 0x26 + 1; nothing here clamps to 60 Hz.
 * Required forms (Ghidra loses all float math): -msoft-float float source; h is an int and
 * cnt a short (an unsigned short cnt re-extends, an int cnt gives 'and o0,l0' instead of the fw
 * 'and l0,o0'); u8 port, u16 return. Aids: none.
 */
struct VMode { unsigned int a; unsigned int div32; unsigned int c; };
extern struct VMode DAT_a8027aac[];
extern unsigned short FUN_a00f21f0(unsigned char, unsigned char);
extern unsigned char FUN_a00f1a90(unsigned char, unsigned char);

unsigned short FUN_a0120c90(unsigned char port)
{
    int h; short cnt;
    float f;

    h = FUN_a00f21f0(port, 0x12) & 0x1fff;
    if ((unsigned short)(h - 0x93) > 0x1ead)
        return 0;
    cnt = FUN_a00f21f0(port, 0x14) & 0x1fff;
    if ((unsigned short)(cnt - 0x403) > 0x453b)
        return 0;
    if ((FUN_a00f1a90(port, 4) & 2) && FUN_a00f1a90(port, 0x54) == 0x20) {
        if (DAT_a8027aac[port].div32 == 1)
            f = (float)cnt * 256.0f;
        else
            f = (float)cnt * 2048.0f;
        return (unsigned int)((double)(f / (float)h) + 0.5);
    }
    return FUN_a00f21f0(port, 0x26) + 1;
}
