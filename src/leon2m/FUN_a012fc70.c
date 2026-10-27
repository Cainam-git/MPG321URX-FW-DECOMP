/* FUN_a012fc70 (leon2m 0xa012fc70-0xa012fcf4, 132 bytes), flags -mcpu=v8 -O3 -g.
 * Returns v = FUN_a00fd820(port of DAT_a802df30[c]) (port = bits 12..15 of the entry word); when v is 0xb1 returns
 * instead byte +0xa of the DAT_a802e224 entry of the port of DAT_a802df30[DAT_a802a44c], or 0xff when the byte
 * DAT_a802a44c is 0xff. Called by FUN_a0132e1c, FUN_a0152e28. Source form: one unsigned char result variable; the
 * 0xb1 branch uses an int set to -1.
 */
struct Chan { unsigned int w; unsigned char p04[0x74]; };
struct E2a { unsigned char p0[0xa]; unsigned char ba; unsigned char pb[0x1f]; };
extern struct Chan DAT_a802df30[4];
extern struct E2a DAT_a802e224[];
extern unsigned char DAT_a802a44c;
extern unsigned char FUN_a00fd820(unsigned char blk);

unsigned char FUN_a012fc70(unsigned char c)
{
    unsigned char v = FUN_a00fd820((DAT_a802df30[c].w >> 12) & 0xf);

    if (v == 0xb1) {
        int r = -1;

        if (DAT_a802a44c != 0xff)
            r = DAT_a802e224[(DAT_a802df30[DAT_a802a44c].w >> 12) & 0xf].ba;
        v = r;
    }
    return v;
}
