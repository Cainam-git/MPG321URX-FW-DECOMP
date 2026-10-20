/* leon2m FUN_a0145c5c @ 0xa0145c5c-0xa0145eb8 (151 words; the asm header's '40 bytes' label is wrong, its range
 * is right). -mcpu=v8 -O3 -g, jump table proven by tools/exact.py
 * (written from the asm).
 * What it does (leaf): setting setter: writes v into field number id (0..17, jump table at fw 0xe3280) of the
 * record DAT_a802e1a0 (the saved-settings record; dc6c reads its byte +7 as DAT_a802e1a7):
 *   id 0/1/2/3 -> 1-bit fields at bits 30/29/27/26 of word +0x00;   id 4, 5 and > 17: nothing;
 *   id 6/8/10/11 -> bytes +0x08 / +0x0c / +0x0f / +0x10;
 *   id 7/9/12/13/14/15 -> 16-bit fields at bytes +0x09 / +0x0d / +0x11 / +0x13 / +0x15 / +0x17 (unaligned:
 *   word read-modify-writes; +0x13 and +0x17 straddle two words, so the fw writes both words);
 *   id 16/17 -> 1-bit fields at bits 23/22 of word +0x18 (byte +0x19 bits 7/6).
 * Not rate-dependent (a settings store; callers FUN_a0081ea8, FUN_a0087020, FUN_a008e270).
 * Code facts that fix the declaration: the record is a packed, 4-byte aligned struct (16-bit fields at odd
 * offsets accessed with word RMWs, two straddling fields); the 16-bit fields are 'unsigned short x:16' bit-fields
 * (fw value conversion 'sll 16 / srl 8'; an 'unsigned int x:16' field masks with 'and 0xffff' instead); the
 * byte fields are plain unsigned char members (stb; byte bit-fields would be word RMWs on SPARC). Field
 * names are offsets/bits only (meaning not shown here). volatile: none. Aids: none.
 */
struct __attribute__((packed, aligned(4))) Settings {
    unsigned int b31:1, f30:1, f29:1, b28:1, f27:1, f26:1, r0:26;   /* +0x00 */
    unsigned int w04;                                                /* +0x04 */
    unsigned char b08;                                               /* +0x08 */
    unsigned short h09:16;                                             /* +0x09 */
    unsigned char b0b, b0c;                                          /* +0x0b, +0x0c */
    unsigned short h0d:16;                                             /* +0x0d */
    unsigned char b0f, b10;                                          /* +0x0f, +0x10 */
    unsigned short h11:16, h13:16, h15:16, h17:16;                     /* +0x11, +0x13, +0x15, +0x17 */
    unsigned int f19_7:1, f19_6:1, r19:6;                            /* +0x19 */
};
extern struct Settings DAT_a802e1a0;

void FUN_a0145c5c(unsigned int id, unsigned int v)
{
    switch (id) {
    case 0: DAT_a802e1a0.f30 = v; break;
    case 1: DAT_a802e1a0.f29 = v; break;
    case 2: DAT_a802e1a0.f27 = v; break;
    case 3: DAT_a802e1a0.f26 = v; break;
    case 6: DAT_a802e1a0.b08 = v; break;
    case 7: DAT_a802e1a0.h09 = v; break;
    case 8: DAT_a802e1a0.b0c = v; break;
    case 9: DAT_a802e1a0.h0d = v; break;
    case 10: DAT_a802e1a0.b0f = v; break;
    case 11: DAT_a802e1a0.b10 = v; break;
    case 12: DAT_a802e1a0.h11 = v; break;
    case 13: DAT_a802e1a0.h13 = v; break;
    case 14: DAT_a802e1a0.h15 = v; break;
    case 15: DAT_a802e1a0.h17 = v; break;
    case 16: DAT_a802e1a0.f19_7 = v; break;
    case 17: DAT_a802e1a0.f19_6 = v; break;
    }
}
