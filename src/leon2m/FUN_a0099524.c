/* leon2m FUN_a0099524 @ 0xa0099524  MATCH (-mcpu=v8 -O2 -g)
 * Calls FUN_a00a93bc(DAT_a8025c56) and FUN_a00a813c(1, DAT_a8025c56, 0), then FUN_a00a9650(DAT_a802d290[0x17C], 0)
 * and FUN_a00a813c(1, DAT_a802d290[0x17C], 1). Writes 0xB to _DAT_a802afec, calls FUN_a00a900c(0, 1) and sets bit 1
 * of DAT_a802b08e.
 */
extern unsigned char DAT_a8025c56;   // 0xa8025c56
extern unsigned char DAT_a802b08e;   // 0xa802b08e
extern unsigned int _DAT_a802afec;   // 0xa802afec
extern unsigned char DAT_a802d290[]; // base 0xa802d290

extern void FUN_a00a93bc(unsigned char); // 0xa00a93bc
extern void FUN_a00a813c(int, unsigned char, int); // 0xa00a813c
extern void FUN_a00a9650(int, int); // 0xa00a9650
extern void FUN_a00a900c(int, int); // 0xa00a900c

void FUN_a0099524(void)
{
    FUN_a00a93bc(DAT_a8025c56);
    FUN_a00a813c(1, DAT_a8025c56, 0);
    FUN_a00a9650(DAT_a802d290[0x17c], 0);
    FUN_a00a813c(1, DAT_a802d290[0x17c], 1);
    _DAT_a802afec = 0xb;
    FUN_a00a900c(0, 1);
    DAT_a802b08e = DAT_a802b08e | 2;
}
