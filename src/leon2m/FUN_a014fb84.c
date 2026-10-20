/* leon2m FUN_a014fb84 @ 0xa014fb84-0xa014fbf0 (27 words), flags -mcpu=v8 -O3 -g.
 * Code facts: b = byte 0xa802a49a; mode == 1: FUN_a011e028(b, 1), FUN_a011e220(b, 1), FUN_a011dd9c(b, u16
 * 0xa802a49e), tail FUN_a011d748(b, 0xff, u16 0xa802a4a0, 0); else tail FUN_a011e148(b). (The GEN2/GEN1 arms of
 * FUN_a0150120 without the prints.)
 * FUN_a011e148 takes one argument (FUN_a0150120 sets only %o0 for it); the %i1 = 0xff / %i2 = sethi / %i3 = 0
 * set before the branch belong to the d748 tail call of the other arm (0xa802a400 = the HIGH of b's address).
 * Returns nothing. Aids: none.
 */
extern unsigned char DAT_a802a49a;
extern unsigned short _DAT_a802a49e;
extern unsigned short _DAT_a802a4a0;
extern void FUN_a011d748(unsigned char, unsigned char, unsigned short, int);
extern void FUN_a011dd9c(unsigned char, unsigned short);
extern void FUN_a011e028(unsigned char, int);
extern void FUN_a011e148(unsigned char);
extern void FUN_a011e220(unsigned char, int);

void FUN_a014fb84(unsigned char mode)
{
    if (mode == 1) {
        FUN_a011e028(DAT_a802a49a, 1);
        FUN_a011e220(DAT_a802a49a, 1);
        FUN_a011dd9c(DAT_a802a49a, _DAT_a802a49e);
        FUN_a011d748(DAT_a802a49a, 0xff, _DAT_a802a4a0, 0);
        return;
    }
    FUN_a011e148(DAT_a802a49a);
}
