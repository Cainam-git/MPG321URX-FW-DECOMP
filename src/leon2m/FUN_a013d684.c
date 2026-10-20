/* leon2m FUN_a013d684 @ 0xa013d684-0xa013d918 (165 words). -mcpu=v8 -O3 -g.
 * (hand, written from the asm).
 * What it does, for channel ch (record c = DAT_a802df30[ch], 0x78 bytes; the u16 fields at +0x48.. are the
 * channel's output-timing block, here named by offset):
 *   if ch == 0 and DAT_a802e3d3 != 0 and DAT_a802e1a7 == 0:  c->h48 = DAT_a802e39a (a fixed value);
 *   else: c->h48 = c->h4c * 120 / 100 (unsigned, i.e. 20 % more than h4c);
 *         ch 1 only: c->h48 = c->h48 * 102 / 100 (2 % more again);
 *         lim = 0xd0 for ch 0, 0xe0 for the others: if (int)(h48 - h4c) < lim then h48 = h4c + lim;
 *         if h48 is not a multiple of 8 it is rounded UP to the next multiple of 8.
 *   sel = the record's 4-bit port field (bits 12..15 of word 0): 1/2/3 -> 1/2/3, anything else -> 0;
 *   FUN_a0109148(sel & 3, c->h5a, c->h5c, c->h54); then the port field is read again (after the call) and
 *   FUN_a0109278(sel & 3, c->h4a, c->h52) as a tail call.
 * Nothing here reads the input rate; it derives h48 from h4c with the fixed 120 % /
 * 102 % factors and the 0xd0 / 0xe0 minimum gap. Callers: dc6c (channel bring-up), FUN_a0149e8c,
 * FUN_a0149f44, FUN_a013129c (all 4 channels).
 * Levers: 'sel = 0;' then a switch with cases 0..3 and NO default (the fw compare tree has root 1, the
 * 4-node {0,1,2,3} list, and bb-reorder then copies the FUN_a0109278 call block into each case, 4 copies);
 * the ch-1 step written with DAT_a802df30[ch] (cse turns the address into base + 0x78: fw 'add %o0,0x78');
 * 120u / 102u (fw umul: unsigned division). volatile: none. Aids: none.
 */
struct Chan {
    union { unsigned int w; struct { unsigned int state:4, f24:4, step:4, f16:4, port:4, f8:4, f4:4, f1:3, b0:1; } b; } u;
    unsigned char p04[0x48 - 0x04];
    unsigned short h48, h4a, h4c, h4e, h50, h52, h54, h56, h58, h5a, h5c, h5e;
    unsigned char p60[0x78 - 0x60];
};
extern struct Chan DAT_a802df30[4];
extern unsigned char DAT_a802e3d3, DAT_a802e1a7;
extern unsigned short DAT_a802e39a;
extern void FUN_a0109148(unsigned char sel, unsigned short a, unsigned short b, unsigned short c);
extern void FUN_a0109278(unsigned char sel, unsigned short a, unsigned short b);

void FUN_a013d684(unsigned char ch)
{
    unsigned char lim = 0xd0;
    unsigned char sel;

    if (ch == 0 && DAT_a802e3d3 != 0 && DAT_a802e1a7 == 0) {
        DAT_a802df30[ch].h48 = DAT_a802e39a;
    } else {
        DAT_a802df30[ch].h48 = DAT_a802df30[ch].h4c * 120u / 100;
        if (ch == 1)
            DAT_a802df30[ch].h48 = DAT_a802df30[ch].h48 * 102u / 100;
        if (ch != 0)
            lim = 0xe0;
        if ((int)(DAT_a802df30[ch].h48 - DAT_a802df30[ch].h4c) < lim)
            DAT_a802df30[ch].h48 = DAT_a802df30[ch].h4c + lim;
        if (DAT_a802df30[ch].h48 & 7)
            DAT_a802df30[ch].h48 = (DAT_a802df30[ch].h48 >> 3) * 8 + 8;
    }
    sel = 0;
    switch (DAT_a802df30[ch].u.b.port) {
    case 0: sel = 0; break;
    case 1: sel = 1; break;
    case 2: sel = 2; break;
    case 3: sel = 3; break;
    }
    FUN_a0109148(sel & 3, DAT_a802df30[ch].h5a, DAT_a802df30[ch].h5c, DAT_a802df30[ch].h54);
    sel = 0;
    switch (DAT_a802df30[ch].u.b.port) {
    case 0: sel = 0; break;
    case 1: sel = 1; break;
    case 2: sel = 2; break;
    case 3: sel = 3; break;
    }
    FUN_a0109278(sel & 3, DAT_a802df30[ch].h4a, DAT_a802df30[ch].h52);
}
