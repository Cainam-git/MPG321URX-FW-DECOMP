/* leon2m FUN_a00990e4 @ 0xa00990e4  MATCH (-mcpu=v8 -O2 -g)
 * 
 */
// FUN_a00990e4 at 0xa00990e4
extern unsigned char DAT_a8025c56; // 0xa8025c56
extern unsigned char DAT_a802b08e; // 0xa802b08e
extern unsigned int _DAT_a802afec; // 0xa802afec
extern unsigned int DAT_a802d290[]; // base 0xa802d290

extern void FUN_a00a93bc(unsigned char); // 0xa00a93bc
extern void FUN_a00a813c(int, unsigned char, int); // 0xa00a813c
extern void FUN_a00a9650(int, int); // 0xa00a9650
extern void FUN_a00a900c(int, int); // 0xa00a900c

void FUN_a00990e4(void)
{
    FUN_a00a93bc(DAT_a8025c56);
    FUN_a00a813c(1, DAT_a8025c56, 0);
    FUN_a00a9650((DAT_a802d290[42] >> 0xf) & 1, 0);
    FUN_a00a813c(1, (DAT_a802d290[42] >> 0xf) & 1, 1);
    _DAT_a802afec = 0x2e;
    FUN_a00a900c(4, 1);
    DAT_a802b08e = DAT_a802b08e | 2;
}
