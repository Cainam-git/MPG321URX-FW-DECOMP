/* leon2s FUN_a006d4e0 @ 0xa006d4e0-0xa006d53c (23 words), flags -mcpu=v8 -Os -g.
 * Code facts: leaf: data = byte 0xa80788d3; for i = 0..8 (u8): bit 7 of the u16 at +0x12 of the 20-byte record
 * ARR_a807a824[i] = bit i of data (signed shift of the int-promoted byte).
 * Fix vs the autoc draft: the record address as integer arithmetic r = (struct Rec *)(i * sizeof + b) with
 * b = (unsigned int)ARR_a807a824 (fw 'add offset, base'; '&t[i]' swaps the add operands, 95.65; the
 * form of FUN_a00700cc); 20-byte struct (the draft indexed a u16 array by i * 10). Aids: none.
 */
struct Rec { unsigned char pad[0x12]; unsigned short h12; };
extern struct Rec ARR_a807a824[];
extern unsigned char DAT_a80788d3;

void FUN_a006d4e0(void)
{
    unsigned int b = (unsigned int)ARR_a807a824;
    int data = DAT_a80788d3;
    unsigned char i;

    for (i = 0; i <= 8; i++)
    {
        struct Rec *r = (struct Rec *)(i * sizeof(struct Rec) + b);
        r->h12 = (r->h12 & ~0x80) | (((data >> i) & 1) << 7);
    }
}
