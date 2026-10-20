/* leon2m FUN_a014a768 @ 0xa014a768 (-mcpu=v8 -O3 -g)
 * Twin of FUN_a014a654: same code, other constants.
 * See FUN_a014a654 for the explanation; this copy's constants differ, so its comments were removed.
 */
extern unsigned char DAT_a802e1a0[];
extern int FUN_a0125198(unsigned char);
extern void FUN_a012b260(unsigned char, unsigned char);
extern int FUN_a01421c4(unsigned char);
extern int FUN_a0142218(unsigned char);
extern void FUN_a0151aa4(unsigned int, unsigned int);
extern void FUN_a0153970(void *, unsigned int);

void FUN_a014a768(unsigned char p, unsigned char q)
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
        FUN_a012b260(k, q);
        FUN_a0153970(DAT_a802e1a0, 0);
    }
}
