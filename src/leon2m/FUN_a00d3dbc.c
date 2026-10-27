/* FUN_a00d3dbc (leon2m 0xa00d3dbc-0xa00d3e28, 108 bytes, leaf), flags -mcpu=v8 -O3 -g -msoft-float.
 * When bit 11 of the word at DAT_a802d290 + 0xa8 is set and the byte at DAT_a802d290 + 0x181 is 7, rewrites the
 * halfword *p as (*p - 0x7e) * 0x381 / 0x381 + 0x7e (unsigned arithmetic). Called by gap. It lies between
 * FUN_a00d3d30 and FUN_a00d3e28.
 */
struct R290 { unsigned char p0[0xa8]; unsigned int wa8; unsigned char pac[0x181 - 0xac]; unsigned char b181; };
extern struct R290 DAT_a802d290;

void FUN_a00d3dbc(unsigned short *p)
{
    if ((DAT_a802d290.wa8 & 0x800) && DAT_a802d290.b181 == 7)
        *p = (unsigned int)(*p - 0x7e) * 0x381 / 0x381 + 0x7e;
}
