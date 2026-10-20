/* FUN_a014489c (leon2m, 0xa014489c-0xa01448fc, 96 bytes, 24 words).
 * Flags: -mcpu=v8 -O3 -g.
 * Code facts: port = (u8)param_1; field = (word at DAT_a802df30 + port*0x78 >> 12) & 0xf;
 * if (u8)FUN_a00fd820(field) == 0xb1: r = FUN_a013923c((u8)FUN_a0142168((u8)FUN_a012fc20()));
 * otherwise r = 8; returns (u8)r. Source form: one return of a variable set in both arms (fw: the
 * 'mov 8,%o0' sits in the bne delay slot and both paths meet at one 'and %o0,0xff,%i0'); two returns
 * give 'mov 8,%i0'. Aids: none.
 */
extern unsigned char DAT_a802df30;
extern int FUN_a00fd820(unsigned char);
extern unsigned char FUN_a012fc20(void);
extern int FUN_a0142168(unsigned char);
extern int FUN_a013923c(unsigned char);

unsigned char FUN_a014489c(unsigned int param_1)
{
    unsigned int uVar1;
    unsigned int uVar2;

    uVar1 = (*(unsigned int *)(&DAT_a802df30 + (param_1 & 0xff) * 0x78) >> 0xc) & 0xf;
    if ((FUN_a00fd820(uVar1) & 0xff) == 0xb1) {
        uVar2 = FUN_a012fc20() & 0xff;
        uVar2 = FUN_a0142168(uVar2) & 0xff;
        uVar2 = FUN_a013923c(uVar2);
    } else
        uVar2 = 8;
    return uVar2;
}
