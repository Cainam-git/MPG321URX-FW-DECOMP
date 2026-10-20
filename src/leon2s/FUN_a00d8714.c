/* leon2s FUN_a00d8714 @ 0xa00d8714-0xa00d87fc (58 words), flags -mcpu=v8 -Os -g.
 * jf 100.00 match=True, rawcmp_l2s 0/58 mismatches.
 * Code facts: 1-byte command h on the stack (fp-9): bits 0..6 = 0x14 (bit 7 kept: ldub/and -128/or/stb);
 * clears u16 _DAT_a80787fa then _DAT_a80787f8; 4 passes i = 0..3 over the register block
 * DAT_a807609c[byte DAT_a8078832] (table and index re-read for every access): saved = (u8) reg +0x2ac;
 * +0x2ac = (saved & 0x3f) | ((i + 1) << 6); +0x284 = 0; +0x2b0 |= 0x10; +0x2b0 &= ~0x10 (pulse);
 * +0x2ac = saved. Then FUN_a00d791c(&h, 2, 1, 6, 1). void.
 * Fixes vs the autoc draft (75.86): 7-bit BIT-FIELD for the command byte, the register block reached
 * through 'volatile unsigned int *DAT_a807609c[]' (same pointers as FUN_a00da6ac; the
 * fw reads and writes +0x2ac / +0x2b0 twice per pass), every access after the first re-indexes the table
 * (fw reloads), void. volatile only on the register blocks behind DAT_a807609c[]. Aids: none.
 */
struct cmd1 {
    unsigned char b7 : 1;
    unsigned char type : 7;
};
extern unsigned char DAT_a8078832;
extern unsigned short _DAT_a80787f8;
extern unsigned short _DAT_a80787fa;
extern volatile unsigned int *DAT_a807609c[];
extern void FUN_a00d791c(void *, int, int, int, int);

void FUN_a00d8714(void)
{
    struct cmd1 h;
    unsigned char i;
    unsigned char saved;
    volatile unsigned int *r;

    h.type = 0x14;
    _DAT_a80787fa = 0;
    _DAT_a80787f8 = 0;
    for (i = 0; i < 4; i++) {
        r = DAT_a807609c[DAT_a8078832];
        saved = r[0x2ac / 4];
        r[0x2ac / 4] = (saved & 0x3f) | ((i + 1) << 6);
        DAT_a807609c[DAT_a8078832][0x284 / 4] = 0;
        DAT_a807609c[DAT_a8078832][0x2b0 / 4] |= 0x10;
        DAT_a807609c[DAT_a8078832][0x2b0 / 4] &= ~0x10;
        DAT_a807609c[DAT_a8078832][0x2ac / 4] = saved;
    }
    FUN_a00d791c(&h, 2, 1, 6, 1);
}
