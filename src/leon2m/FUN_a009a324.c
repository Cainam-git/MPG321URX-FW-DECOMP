/* leon2m FUN_a009a324 @ 0xa009a324 (-mcpu=v8 -O2 -g)
 * 
 */
extern unsigned char DAT_a8025c55;
extern unsigned char DAT_a802b08e;
extern unsigned char DAT_a802d470;
extern unsigned int _DAT_a802afec;

extern int FUN_a00a93bc(unsigned char);
extern void FUN_a00af44c(int, int);
extern void FUN_a00a9650(int, int);
extern void FUN_a00dab20(void);

void FUN_a009a324(void)
{
    FUN_a00a93bc(DAT_a802d470);
    FUN_a00af44c(0x34, 3);
    _DAT_a802afec = 0xbd;
    FUN_a00a9650(2, 1);
    DAT_a8025c55 = 0;
    FUN_a00dab20();
    DAT_a802b08e = DAT_a802b08e | 2;
}
