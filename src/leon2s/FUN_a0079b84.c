/* FUN_a0079b84 (leon2s 0xa0079b84-0xa0079e00, 636 bytes), flags -mcpu=v8 -Os -g.
 * unsigned short (port, ch, rate, e); called by DRV_HDMI21_Set_PHY as FUN_a0079b84(port, j, rate, E[j]).
 * sel = (rate == 5) | (e == 8). For ch <= 3 it reads FUN_a00a7314(port, DAT_a00b3af4[ch]) and
 * FUN_a00a7314(port, DAT_a00b3aec[ch]) three times each: r1 / r2 = bits 24..28, r3 / r4 = bits 16..19,
 * r5 / r6 = bits 8..12 of the two words (all 0 for ch > 3). r3 / r4 are xor-ed with 8 and r5 / r6 with 0x10;
 * d1..d4 are their distances from 8 / 0x10, ev = max(d1, d2), eh = max(d3, d4), mn = min(r1, r2).
 * With mn > 5 and ev < 4 the result is mn * 7 + (8 - ev) * 8 - eh + 0x10 (sel set) or
 * ((8 - ev) * 2 - eh) * 2 + mn + 0x20 (sel clear); otherwise mn - ev + 8.
 * Source form: the result is computed in a short variable; ev is preset to d2 and replaced by d1 when larger,
 * mn is an if/else on r1 > r2.
 */
extern const unsigned short DAT_a00b3af4[];
extern const unsigned short DAT_a00b3aec[];
extern unsigned int FUN_a00a7314(unsigned int, unsigned short);

unsigned short FUN_a0079b84(unsigned int port, unsigned int ch, unsigned char rate, unsigned char e)
{
    unsigned char sel;
    unsigned char r1 = 0, r2 = 0, r3 = 0, r4 = 0, r5 = 0, r6 = 0;
    unsigned char d1, d2, d3, d4, ev, eh, mn;
    unsigned int ra, rb;
    short res;

    sel = (rate == 5) | (e == 8);
    if ((ch & 0xff) <= 3) {
        ra = DAT_a00b3af4[ch & 0xff];
        r1 = (FUN_a00a7314(port & 0xff, ra) & 0x1f000000) >> 24;
        rb = DAT_a00b3aec[ch & 0xff];
        r2 = (FUN_a00a7314(port & 0xff, rb) & 0x1f000000) >> 24;
        r3 = (FUN_a00a7314(port & 0xff, ra) & 0xf0000) >> 16;
        r4 = (FUN_a00a7314(port & 0xff, rb) & 0xf0000) >> 16;
        r5 = (FUN_a00a7314(port & 0xff, ra) & 0x1f00) >> 8;
        r6 = (FUN_a00a7314(port & 0xff, rb) & 0x1f00) >> 8;
    }
    r3 ^= 8;
    r4 ^= 8;
    r5 ^= 0x10;
    r6 ^= 0x10;
    if (r3 <= 7)
        d1 = 8 - r3;
    else
        d1 = r3 - 8;
    if (r4 <= 7)
        d2 = 8 - r4;
    else
        d2 = r4 - 8;
    ev = d2;
    if (d2 < d1)
        ev = d1;
    if (r5 <= 0xf)
        d3 = 0x10 - r5;
    else
        d3 = r5 - 0x10;
    if (r6 <= 0xf)
        d4 = 0x10 - r6;
    else
        d4 = r6 - 0x10;
    eh = d4;
    if (d4 < d3)
        eh = d3;
    if (r1 > r2)
        mn = r2;
    else
        mn = r1;
    if (((mn > 5) & (ev < 4)) && sel)
        res = mn * 7 + (8 - ev) * 8 - eh + 0x10;
    else if (((mn > 5) & (ev < 4)) && !sel)
        res = ((8 - ev) * 2 - eh) * 2 + mn + 0x20;
    else
        res = mn - ev + 8;
    return res;
}
