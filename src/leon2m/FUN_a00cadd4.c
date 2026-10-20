/* leon2m FUN_a00cadd4 @ 0xa00cadd4 (-mcpu=v8 -O3 -g)
 * Twin of FUN_a00cb3a8: same code, other constants.
 */
extern unsigned char DAT_a802d049;
extern unsigned char DAT_a802d0a1;
extern unsigned char DAT_a802d0d9;
extern unsigned char DAT_a802d470;
extern void FUN_a00dab20(void);
extern void FUN_a00b88cc(void);
extern int FUN_a00baa6c();
extern int FUN_a00ba950();
extern int FUN_a00bab80();

int FUN_a00cadd4(int param_1)
{
    unsigned char value;
    unsigned short diff;
    
    param_1 = param_1 & 0xff;
    if (param_1 == 2) {
        value = DAT_a802d049;
    } else if (param_1 == 3) {
        value = DAT_a802d0a1;
    } else {
        value = DAT_a802d0d9;
    }
    
    diff = value - 0x30;
    if ((unsigned char)diff > 1) {
        return 0xff;
    }
    
    DAT_a802d470 = diff;
    FUN_a00dab20();
    FUN_a00b88cc();
    FUN_a00baa6c(param_1);
    FUN_a00ba950(param_1);
    FUN_a00bab80(param_1, 6);
    return 0;
}
