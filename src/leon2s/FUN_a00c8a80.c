/* leon2s FUN_a00c8a80 @ 0xa00c8a80-0xa00c8aec (27 words), flags -mcpu=v8 -Os -g.
 * jf 100.00 match=True, rawcmp 0/27 mismatches.
 * Code facts: ch (u8). Word 0 of the 24-byte record DAT_a8078bb0[ch]: bits 16..17 = 1; then
 * r = func_0xa0fb7fd8(ch, 0, 9); if bit 1 of r is clear: bits 16..17 = 0, else bits 16..17 = 1
 * (mask 0xfffcffff kept in a register). void. Family of FUN_a00cdc74.
 * Fix vs the autoc draft (81.48): record struct indexed by ch (the draft built a pointer from a
 * volatile byte cast); the '(r & 2) == 0' clear arm FIRST (fw falls through into it). No volatile
 * (RAM). Aids: none.
 */
struct Rec18 { unsigned int w0; unsigned char pad[0x14]; };
extern struct Rec18 DAT_a8078bb0[];
extern unsigned char func_0xa0fb7fd8(unsigned char, unsigned int, unsigned int);

void FUN_a00c8a80(unsigned char ch)
{
    DAT_a8078bb0[ch].w0 = (DAT_a8078bb0[ch].w0 & 0xfffcffff) | 0x10000;
    if ((func_0xa0fb7fd8(ch, 0, 9) & 2) == 0)
        DAT_a8078bb0[ch].w0 = DAT_a8078bb0[ch].w0 & 0xfffcffff;
    else
        DAT_a8078bb0[ch].w0 = (DAT_a8078bb0[ch].w0 & 0xfffcffff) | 0x10000;
}
