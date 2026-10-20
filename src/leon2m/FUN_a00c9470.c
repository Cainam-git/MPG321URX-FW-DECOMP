/* leon2m FUN_a00c9470 @ 0xa00c9470  MATCH (-mcpu=v8 -O2 -g)
 * Selects a byte by the low byte of the parameter (2: DAT_a802d049, 3: DAT_a802d0a1, otherwise DAT_a802d0d9). If
 * it equals 0x31 and DAT_a802d2af is non-zero, calls FUN_a00d93c8(), FUN_a00baa6c(p), FUN_a00ba950(p),
 * FUN_a00bab80(p, 6) and returns 0; otherwise returns 0xff. The call results are not used.
 */
extern unsigned char DAT_a802d049;
extern unsigned char DAT_a802d0a1;
extern unsigned char DAT_a802d0d9;
extern unsigned char DAT_a802d2af;
extern void FUN_a00d93c8(void);
extern int FUN_a00baa6c();
extern int FUN_a00ba950();
extern int FUN_a00bab80();

int FUN_a00c9470(int param_1)
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
    
    FUN_a00d93c8();
    FUN_a00baa6c(param_1);
    FUN_a00ba950(param_1);
    FUN_a00bab80(param_1, 6);
    return 0;
}
