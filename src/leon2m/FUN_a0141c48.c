/* FUN_a0141c48 (leon2m 0xa0141c48-0xa0141c98, 80 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Sets the top four bits (bits 12..15) of the halfword at +0 of the first four 0x12-byte entries of DAT_a802e116 to
 * 6. Nothing in the image refers to it: no call, branch, sethi/or constant or address word. It lies between
 * FUN_a0141b60 and FUN_a0141c98. Source form: a four-bit bit-field at the top of the halfword, four separate
 * statements.
 */
struct EntF { unsigned short type:4, f11:1, f10_6:5, f5:1, f4:1, f3_0:4; };
struct Ent { struct EntF f; unsigned char p02[0x12 - 0x02]; };
extern struct Ent DAT_a802e116[];

void FUN_a0141c48(void)
{
    DAT_a802e116[0].f.type = 6;
    DAT_a802e116[1].f.type = 6;
    DAT_a802e116[2].f.type = 6;
    DAT_a802e116[3].f.type = 6;
}
