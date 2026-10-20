/* leon2m FUN_a01302a4 @ 0xa01302a4-0xa01302e0 (15 words), flags -mcpu=v8 -O3 -g. Callers: FUN_a014b844 (twice).
 * Leaf. Writes bit 0 of v into bit 17 of the word at +0x70 of record ch of the 0x78-byte record array at 0xa802df30
 * (index ch * 15 * 8: sll 4 / sub / sll 3). ch is an unsigned char parameter. The bit is a 1-bit bit-field.
 */
struct Rec { unsigned char pad[0x70]; unsigned int hi : 14, b17 : 1, lo : 17; unsigned int pad74; };
extern struct Rec DAT_a802df30[];

void FUN_a01302a4(unsigned char ch, unsigned int v)
{
    DAT_a802df30[ch].b17 = v;
}
