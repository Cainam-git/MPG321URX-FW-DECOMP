/* FUN_a0141c98 (leon2m 0xa0141c98-0xa0141ce0, 72 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Sets the top four bits (bits 12..15) of the halfword at +0 of the first seven 0x12-byte entries of DAT_a802e116
 * to 1. Nothing in the image refers to it: no call, branch, sethi/or constant or address word. It lies between
 * FUN_a0141c48 and FUN_a0141ce0. Source form: a four-bit bit-field at the top of the halfword (the layout used for
 * DAT_a802e116 elsewhere).
 */
struct EntF { unsigned short type:4, f11:1, f10_6:5, f5:1, f4:1, f3_0:4; };
struct Ent { struct EntF f; unsigned char p02[0x12 - 0x02]; };
extern struct Ent DAT_a802e116[];

void FUN_a0141c98(void)
{
    unsigned char i;

    for (i = 0; i < 7; i++)
        DAT_a802e116[i].f.type = 1;
}
