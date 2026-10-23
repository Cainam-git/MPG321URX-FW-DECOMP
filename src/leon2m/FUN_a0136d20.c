/* leon2m FUN_a0136d20 @ 0xa0136d20  copy Small-chip port template t into port entry n
 * Flags: -mcpu=v8 -O3 -g.
 *
 * t = 2, 3, 4, 5 for n = 0, 1, 2, 3, else t = 0. Template = 16 bytes at 0xA802DEC0 + 16*t (filled by FUN_a01387a4
 * from mailbox portal 1); entry = 18 bytes at 0xA802E116 + 18*n.
 *   entry h0 bits 15..12 (type nibble) = template byte +0 (bits 11..7 kept);
 *   entry +4 = tmpl +1, +6/+8/+0xa/+0xc/+0xe (u16) = tmpl +2/+4/+6/+8/+0xa, +5 = tmpl +0xe, +3 = tmpl +0xd;
 *   template flags byte +0xc spread into the entry bits:
 *     flags bit 0 -> h0 bit 6 (0x40)   bit 1 -> h0 bit 5 (0x20)   bit 2 -> h0 bit 4 (0x10)   bit 3 -> h0 bit 3 (0x08)
 *     bit 4 -> h0 bit 2 (0x04)          bit 5 -> h2 bit 15 (+2, 0x8000)   bit 6 -> h0 bit 1   bit 7 -> h0 bit 0.
 * Copy chain to the 0xA802CBD4 port bit: entry h0 bit 4 (0x10) = template +0xc bit 2, entry type nibble = template +0;
 *   index n (not t) selects the entry.
 * Callers: only FUN_a002f550 (RAM copy at 0x4008F550, four calls; its listing shows 'call 0xd6d20').
 * Returns nothing (the Ghidra 'uint' result is the leftover %i0).
 * Source form: h0 as a bitfield struct; the type and the flag bits written through DAT_a802e116[n] (the field
 *   copies through a pointer local e); flag bit 5 written with an explicit '& 1' ('(f >> 5) & 1'), without it gcc
 *   drops the 'and' and the registers rotate.
 */
struct Tmpl {
    unsigned char type;     /* +0 */
    unsigned char b1;       /* +1 */
    unsigned short w2, w4, w6, w8, wa; /* +2..+0xb */
    unsigned char flags;    /* +0xc */
    unsigned char bd;       /* +0xd */
    unsigned char be;       /* +0xe */
    unsigned char bf;
};
struct Entry {
    unsigned short type:4;     /* h0 bits 15..12 */
    unsigned short h0_11:5;    /* h0 bits 11..7 (not touched here) */
    unsigned short f0:1;       /* bit 6 */
    unsigned short f1:1;       /* bit 5 */
    unsigned short f2:1;       /* bit 4: the line-rate switch */
    unsigned short f3:1;       /* bit 3 */
    unsigned short f4:1;       /* bit 2 */
    unsigned short f6:1;       /* bit 1 */
    unsigned short f7:1;       /* bit 0 */
    unsigned short f5:1;       /* +2 bit 15 */
    unsigned short h2_rest:7;
    unsigned char b3;          /* +3 */
    unsigned char b4, b5;
    unsigned short w6, w8, wa, wc, we;
    unsigned short w10;
};
extern struct Tmpl DAT_a802dec0[];
extern struct Entry DAT_a802e116[];

void FUN_a0136d20(unsigned char n)
{
    unsigned char t;
    struct Tmpl *s;
    struct Entry *e;

    t = 0;
    switch (n) {
    case 0: t = 2; break;
    case 1: t = 3; break;
    case 2: t = 4; break;
    case 3: t = 5; break;
    }
    DAT_a802e116[n].type = DAT_a802dec0[t].type;
    s = &DAT_a802dec0[t];
    e = &DAT_a802e116[n];
    e->b4 = s->b1;
    e->w6 = s->w2;
    e->w8 = s->w4;
    e->wa = s->w6;
    e->wc = s->w8;
    e->we = s->wa;
    e->b5 = s->be;
    DAT_a802e116[n].f0 = s->flags;
    DAT_a802e116[n].f1 = s->flags >> 1;
    DAT_a802e116[n].f2 = s->flags >> 2;
    DAT_a802e116[n].f3 = s->flags >> 3;
    DAT_a802e116[n].f4 = s->flags >> 4;
    DAT_a802e116[n].f5 = (s->flags >> 5) & 1;
    DAT_a802e116[n].f6 = s->flags >> 6;
    DAT_a802e116[n].f7 = s->flags >> 7;
    e->b3 = s->bd;
}
