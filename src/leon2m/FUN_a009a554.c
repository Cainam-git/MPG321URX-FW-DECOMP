/* leon2m FUN_a009a554 @ 0xa009a554  MATCH (-mcpu=v8 -O3 -g, gcc 3.4.4, autoc)
 * Mechanical: Ghidra's C cleaned by tools/autoc.py; Ghidra's type and symbol names are kept.
 */
extern unsigned char DAT_a8025c55;
extern unsigned char DAT_a802b08e;
extern unsigned char DAT_a802d471;
extern unsigned int _DAT_a802afec;
extern int FUN_a00a93bc();
extern void FUN_a00a9650();
extern void FUN_a00af44c();
extern void FUN_a00dab20(void);

void FUN_a009a554(void)
{
    FUN_a00a93bc(DAT_a802d471);
    FUN_a00af44c(0x34, 3);
    _DAT_a802afec = 0xbe;
    FUN_a00a9650(3, 1);
    DAT_a8025c55 = 0;
    FUN_a00dab20();
    DAT_a802b08e = DAT_a802b08e | 2;
}
