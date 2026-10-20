/* leon2m FUN_a00c93e0 @ 0xa00c93e0 (-mcpu=v8 -O3 -g)
 * Twin of FUN_a00c9470: same code, other constants.
 * See FUN_a00c9470 for the explanation; this copy's constants differ, so its comments were removed.
 */
extern unsigned char DAT_a802d049;
extern unsigned char DAT_a802d0a1;
extern unsigned char DAT_a802d0d9;
extern unsigned char DAT_a802d2af;
extern void FUN_a00d934c(void);
extern int FUN_a00baa6c();
extern int FUN_a00ba950();
extern int FUN_a00bab80();

int FUN_a00c93e0(int param_1)
{
    unsigned char value;
    
    param_1 = param_1 & 0xff;
    if (param_1 == 2) {
        value = DAT_a802d049;
    } else if (param_1 == 3) {
        value = DAT_a802d0a1;
    } else {
        value = DAT_a802d0d9;
    }
    
    if (value != 0x31) {
        return 0xff;
    }
    
    if (DAT_a802d2af == 0) {
        return 0xff;
    }
    
    FUN_a00d934c();
    FUN_a00baa6c(param_1);
    FUN_a00ba950(param_1);
    FUN_a00bab80(param_1, 6);
    return 0;
}
