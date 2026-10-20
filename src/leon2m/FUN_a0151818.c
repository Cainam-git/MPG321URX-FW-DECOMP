/* leon2m FUN_a0151818 @ 0xa0151818-0xa01518c8 (44 words). -mcpu=v8 -O3 -g.
 * (hand, from the asm).
 * What it does: GlobalModeHandler state C entry for channel ch:
 *   pc = the 4-bit port field (bits 12..15 of word 0) of DAT_a802df30[ch] (ch 1..3; anything else uses record 0);
 *   only when pc == 0 AND bit 21 (0x200000) of the FRC config word DAT_a802e3d0 is set:
 *     FUN_a01084a8(FUN_a013cda8(3), 1)  (set bit 'port code of channel 3' in hw 0xcf011800 / 0xcf011a00 / 0xcf011bf8)
 *     FUN_a0109554(FUN_a013cda8(3), 0)  (clear that bit in hw 0xcf011a00, tail call; FUN_a013cda8 is called twice).
 *   Otherwise nothing.
 * Nothing here reads the rate; it depends on the port field and e3d0 bit 21 only.
 * Prototypes: FUN_a013cda8 returns the port code 0..3 as a byte (fw 'and %o0,0xff' after each call);
 * FUN_a0109554(int bit, u8 on) (its asm: 'sll %g1,%o0' unmasked, 'btst 0xff,%o1').
 * Lever: the record switch in the order 'case 0: default:', 1, 2, 3 (as in FUN_a01516b0). volatile: none. Aids: none.
 */
struct Chan {
    union { unsigned int w; struct { unsigned int state:4, f24:4, step:4, f16:4, port:4, f8:4, f4:4, f1:3, b0:1; } b; } u;
    unsigned char p04[0x78 - 0x04];
};
extern struct Chan DAT_a802df30[4];
extern unsigned int DAT_a802e3d0;
extern unsigned char FUN_a013cda8(unsigned char ch);
extern void FUN_a01084a8(unsigned char bit, unsigned char on);
extern void FUN_a0109554(int bit, unsigned char on);

void FUN_a0151818(unsigned char ch)
{
    unsigned char pc;

    switch (ch) {
    case 0: default: pc = DAT_a802df30[0].u.b.port; break;
    case 1: pc = DAT_a802df30[1].u.b.port; break;
    case 2: pc = DAT_a802df30[2].u.b.port; break;
    case 3: pc = DAT_a802df30[3].u.b.port; break;
    }
    if (pc == 0 && (DAT_a802e3d0 & 0x200000)) {
        FUN_a01084a8(FUN_a013cda8(3), 1);
        FUN_a0109554(FUN_a013cda8(3), 0);
    }
}
