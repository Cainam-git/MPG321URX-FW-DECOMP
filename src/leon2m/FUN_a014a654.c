/* leon2m FUN_a014a654 @ 0xa014a654-0xa014a6e0 (35 words), flags -mcpu=v8 -O3 -g.
 * jf 100.00 match=True, rawcmp 0/35 mismatches.
 * Code facts: v = (u8)FUN_a01421c4((u8)FUN_a0142218((u8)FUN_a0125198(p))) (each result is
 * re-masked by the caller: the callees return int). v == 0x71: k = 0, FUN_a0151aa4(0x10, 1);
 * v == 0x81: k = 1, FUN_a0151aa4(0x20, 1) (one shared call in the fw); else k = 0xff. If
 * k != 0xff: FUN_a012b164(k, q); tail call FUN_a0153970(&DAT_a802e1a0, 0). void.
 * Fix vs the autoc draft (82.86): the arm selection is a SWITCH on v (an if/else-if chain makes
 * gcc crossjump 'mov 1,%o1; call' together; the switch keeps only the call shared, so the 0x81
 * arm sets o0 and o1 itself as in the fw). Aids: none.
 */
extern unsigned char DAT_a802e1a0[];
extern int FUN_a0125198(unsigned char);
extern void FUN_a012b164(unsigned char, unsigned char);
extern int FUN_a01421c4(unsigned char);
extern int FUN_a0142218(unsigned char);
extern void FUN_a0151aa4(unsigned int, unsigned int);
extern void FUN_a0153970(void *, unsigned int);

void FUN_a014a654(unsigned char p, unsigned char q)
{
    unsigned char v;
    unsigned char k;

    v = FUN_a01421c4(FUN_a0142218(FUN_a0125198(p)));
    switch (v) {
    case 0x71:
        k = 0;
        FUN_a0151aa4(0x10, 1);
        break;
    case 0x81:
        k = 1;
        FUN_a0151aa4(0x20, 1);
        break;
    default:
        k = 0xff;
        break;
    }
    if (k != 0xff) {
        FUN_a012b164(k, q);
        FUN_a0153970(DAT_a802e1a0, 0);
    }
}
