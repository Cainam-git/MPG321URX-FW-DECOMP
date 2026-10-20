/* leon2m FUN_a0094fc4 @ 0xa0094fc4  MATCH (-mcpu=v8 -O2 -g)
 * 
 */
extern unsigned char DAT_a8025c55;
extern unsigned char DAT_a802b08e;
extern unsigned char DAT_a802b08f;
extern unsigned char DAT_a802d434;
extern unsigned int _DAT_a802afec;
extern int FUN_a00a86e8();
extern int FUN_a00a8c88();
extern void FUN_a00a9650();

unsigned int FUN_a0094fc4(unsigned int param_1, unsigned int param_2)
{
    DAT_a802b08f = 0xf;
    FUN_a00a8c88();
    FUN_a00a86e8();
    _DAT_a802afec = 0x7c;
    FUN_a00a9650(2, 1);
    DAT_a8025c55 = DAT_a802d434;
    DAT_a802b08e = DAT_a802b08e | 2;
    return param_1;
}
