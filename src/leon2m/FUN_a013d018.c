/* leon2m FUN_a013d018 @ 0xa013d018-0xa013d0ec (53 words), flags -mcpu=v8 -O3 -g. Callers: FUN_a012f43c (twice).
 * For channel ch 0..3 of the 0x78-byte records at 0xa802df30: when bits 12..15 of word 0 differ from src, or force is
 * not 0, writes src into bits 12..15, writes FUN_a014226c(byte +0xa of record src of the 0x2a-byte records at
 * 0xa802e224) into bits 8..11 and, when bits 28..31 are above 5 and bit 0 of byte +0x70 is set, sets bits 28..31 to
 * 5. The nibbles are 4-bit bit-fields; the top nibble is compared with 5u (unsigned compare).
 */
struct Chan {
    unsigned int top : 4, mid : 12, f12 : 4, f8 : 4, lo : 8;
    unsigned char pad4[0x6c];
    unsigned char b70;
    unsigned char rest[7];
};
struct Port { unsigned char pad[0xa]; unsigned char ba; unsigned char rest[0x1f]; };
extern struct Chan DAT_a802df30[];
extern struct Port DAT_a802e224[];
extern unsigned char FUN_a014226c(unsigned char p);

void FUN_a013d018(unsigned char ch, unsigned char src, unsigned char force)
{
    if (ch > 3)
        return;
    if (src != DAT_a802df30[ch].f12 || force) {
        DAT_a802df30[ch].f12 = src;
        DAT_a802df30[ch].f8 = FUN_a014226c(DAT_a802e224[src].ba);
        if (DAT_a802df30[ch].top > 5u && (DAT_a802df30[ch].b70 & 1))
            DAT_a802df30[ch].top = 5;
    }
}
