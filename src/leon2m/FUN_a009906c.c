/* leon2m FUN_a009906c @ 0xa009906c  MATCH (-mcpu=v8 -O3 -g, gcc 3.4.4, permuter)
 * reached byte-exact by tools/permuter.py: base 0xa802d290 kept in a register: pointer local (basefix)
 */
extern unsigned char DAT_a8025c56;   // 0xa8025c56
extern unsigned char DAT_a802b08e;   // 0xa802b08e
extern unsigned int _DAT_a802afec;   // 0xa802afec
extern unsigned int _DAT_a802d338;   // 0xa802d338

extern void FUN_a00a813c(int, unsigned char, int); // 0xa00a813c
extern void FUN_a00a900c(int, int); // 0xa00a900c
extern void FUN_a00a9650(int, int); // 0xa00a9650

void FUN_a009906c(void)
{
    volatile unsigned char *pb1_ = (volatile unsigned char *)0xA802D290;
    unsigned int tmp;

    tmp = ((*(volatile unsigned int *)(pb1_ + 168)) >> 0xf) & 1;
    DAT_a8025c56 = (unsigned char)tmp;
    FUN_a00a813c(1, (unsigned char)tmp, 0);
    FUN_a00a900c((_DAT_a802afec - 42) & 0xff, 2);
    tmp = ((*(volatile unsigned int *)(pb1_ + 168)) >> 0xf) & 1;
    _DAT_a802afec = tmp + 0xb4;
    FUN_a00a9650((int)tmp, 1);
    DAT_a802b08e = DAT_a802b08e | 2;
}
