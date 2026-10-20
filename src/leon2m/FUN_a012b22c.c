/* leon2m FUN_a012b22c @ 0xa012b22c-0xa012b260 (13 words).
 * Takes nibble ch of byte 0xa802e1a0+0x32 and nibble ch of byte +0x2c (nibble n = bits 4n..4n+3) and returns
 * bit (second nibble) of the first nibble. The shift amount b is computed before the value v (source order
 * decides the load order).
 */
struct E1a0 {
    unsigned char pad0[0x2c];
    unsigned char b2c;
    unsigned char pad2d[0x32 - 0x2d];
    unsigned char b32;
};
extern struct E1a0 DAT_a802e1a0;

unsigned char FUN_a012b22c(unsigned char ch)
{
    unsigned char b = (DAT_a802e1a0.b2c >> (ch * 4)) & 0xf;
    unsigned char v = (DAT_a802e1a0.b32 >> (ch * 4)) & 0xf;

    return (v >> b) & 1;
}
