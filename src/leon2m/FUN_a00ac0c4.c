/* leon2m FUN_a00ac0c4 @ 0xa00ac0c4 (-mcpu=v8 -O2)
 */
extern void FUN_a00a8c88(void);
extern void FUN_a0146b50(unsigned short, unsigned char);
extern void FUN_a0146b6c(unsigned short, unsigned char);
extern unsigned int FUN_a00a3844(int, unsigned short);
extern void FUN_a00a31a4(int, int, int, int, unsigned int, int);

void FUN_a00ac0c4(void)
{
    unsigned char i;
    
    FUN_a00a8c88();
    FUN_a0146b50(0x111, 0);
    FUN_a0146b6c(0, 0);
    
    for (i = 0; i <= 4; i++) {
        unsigned int r = FUN_a00a3844(0x18a758, i);
        FUN_a00a31a4(0, 0x2a, (i * 2) + 6, 1, r, 0);
    }
}
