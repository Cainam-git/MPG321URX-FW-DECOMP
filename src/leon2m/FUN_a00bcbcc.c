/* leon2m FUN_a00bcbcc @ 0xa00bcbcc  MATCH (-mcpu=v8 -O3 -g, twin)
 * Twin of FUN_a00be38c: same code, constants swapped; byte-exact.
 */
extern unsigned int _DAT_a802d338;
extern unsigned char DAT_a802d078[];
extern void FUN_a00bac3c();
extern unsigned char FUN_a00ba950();
extern void FUN_a00babe4(unsigned char param_1, unsigned char param_2);

unsigned int FUN_a00bcbcc(unsigned char param_1)
{
    unsigned int uVar1;
    
    uVar1 = (_DAT_a802d338 >> 0xc) & 1;
    DAT_a802d078[7] = 0x30;
    DAT_a802d078[8] = 0x30;
    DAT_a802d078[9] = (uVar1 + 0x30);
    (void)FUN_a00bac3c(0x18);
    (void)FUN_a00ba950(param_1);
    FUN_a00babe4(param_1, 0xb);
}
