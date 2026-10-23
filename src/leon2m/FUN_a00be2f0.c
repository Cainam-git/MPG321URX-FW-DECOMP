/* leon2m FUN_a00be2f0 @ 0xa00be2f0 (-mcpu=v8 -O3 -g)
 * Stores '0', '0' and '0' + bit 15 of word 0xA802D404 in bytes 7, 8 and 9 of the byte array 0xA802D078, then calls
 * FUN_a00bac3c(0x6c), FUN_a00ba950(p1) and FUN_a00babe4(p1, 0xb). Same code as FUN_a00be38c with other constants.
 */
extern unsigned int _DAT_a802d404;
extern unsigned char DAT_a802d078[];
extern void FUN_a00bac3c();
extern unsigned char FUN_a00ba950();
extern void FUN_a00babe4(unsigned char param_1, unsigned char param_2);

unsigned int FUN_a00be2f0(unsigned char param_1)
{
    unsigned int uVar1;
    
    uVar1 = (_DAT_a802d404 >> 0xf) & 1;
    DAT_a802d078[7] = 0x30;
    DAT_a802d078[8] = 0x30;
    DAT_a802d078[9] = (uVar1 + 0x30);
    (void)FUN_a00bac3c(0x6c);
    (void)FUN_a00ba950(param_1);
    FUN_a00babe4(param_1, 0xb);
}
