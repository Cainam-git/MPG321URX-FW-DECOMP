/* leon2m FUN_a00bd244 @ 0xa00bd244 (-mcpu=v8 -O3 -g)
 * Twin of FUN_a00be38c: same code, other constants.
 */
extern unsigned int _DAT_a802d3ac;
extern unsigned char DAT_a802d078[];
extern void FUN_a00bac3c();
extern unsigned char FUN_a00ba950();
extern void FUN_a00babe4(unsigned char param_1, unsigned char param_2);

unsigned int FUN_a00bd244(unsigned char param_1)
{
    unsigned int uVar1;
    
    uVar1 = (_DAT_a802d3ac >> 0x4) & 1;
    DAT_a802d078[7] = 0x30;
    DAT_a802d078[8] = 0x30;
    DAT_a802d078[9] = (uVar1 + 0x30);
    (void)FUN_a00bac3c(0x24);
    (void)FUN_a00ba950(param_1);
    FUN_a00babe4(param_1, 0xb);
}
