/* leon2m FUN_a00ca380 @ 0xa00ca380  MATCH (-mcpu=v8 -O2 -g)
 * Selects DAT_a802d049 (param_1 == 2), DAT_a802d0a1 (param_1 == 3) or DAT_a802d0d9 (other values, param_1 masked
 * to 8 bits) and subtracts '0' (0x30). A result above 2 returns 0xFF. Otherwise the result is stored to
 * DAT_a802d46d, FUN_a00dab08, FUN_a00b88cc, FUN_a00baa6c(param_1), FUN_a00ba950(param_1) and FUN_a00bab80(param_1,
 * 6) are called, and 0 is returned.
 */
extern unsigned char DAT_a802d049;
extern unsigned char DAT_a802d0a1;
extern unsigned char DAT_a802d0d9;
extern unsigned char DAT_a802d46d;
extern void FUN_a00dab08(void);
extern void FUN_a00b88cc(void);
extern int FUN_a00baa6c();
extern int FUN_a00ba950();
extern int FUN_a00bab80();

int FUN_a00ca380(int param_1)
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
    if ((unsigned char)diff > 2) {
        return 0xff;
    }
    
    DAT_a802d46d = diff;
    FUN_a00dab08();
    FUN_a00b88cc();
    FUN_a00baa6c(param_1);
    FUN_a00ba950(param_1);
    FUN_a00bab80(param_1, 6);
    return 0;
}
