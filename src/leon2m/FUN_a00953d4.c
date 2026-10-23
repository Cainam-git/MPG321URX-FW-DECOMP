/* leon2m FUN_a00953d4 @ 0xa00953d4 (-mcpu=v8 -O2 -g)
 * Byte 0xA802B08F = 0xf; FUN_a00a8c88(); FUN_a00a86e8(); word 0xA802AFEC = 0x7b; FUN_a00a9650(1, 1); byte 0xA8025C55 =
 * byte 0xA802D434; byte 0xA802B08E |= 2.
 */
extern unsigned char DAT_a802b08f; /* 0xa802b08f */
extern unsigned char DAT_a802b08e; /* 0xa802b08e */
extern unsigned int  DAT_a802afec; /* 0xa802afec */
extern unsigned char DAT_a802d434; /* 0xa802d434 */
extern unsigned char DAT_a8025c55; /* 0xa8025c55 */
extern void FUN_a00a8c88(void);
extern void FUN_a00a86e8(void);
extern void FUN_a00a9650(unsigned int, unsigned int);

void FUN_a00953d4(void)
{
    DAT_a802b08f = 0xf;
    FUN_a00a8c88();
    FUN_a00a86e8();
    DAT_a802afec = 0x7b;
    FUN_a00a9650(1, 1);
    DAT_a8025c55 = DAT_a802d434;
    DAT_a802b08e = DAT_a802b08e | 2;
}
