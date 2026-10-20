/* leon2m FUN_a00c1078 @ 0xa00c1078 (-mcpu=v8 -O2 -g)
 * This function reads a byte from one of three addresses (selected by the input parameter 0, 1, or 2), subtracts 0x30 ('0'), and if the result is 0 or 1, stores it to a global, calls several functions, and returns 0. Otherwise it returns 0xff. The main uncertainty is whether the compiler will match the exact branch layout and the `sethi`/`or` addressing for the global loads, but the structure matches the proven similar function exactly.
 */
extern unsigned char DAT_a802d049;
extern unsigned char DAT_a802d0a1;
extern unsigned char DAT_a802d0d9;
extern unsigned char DAT_a802d47e;
extern void FUN_a00b88cc(void);
extern int FUN_a00baa6c();
extern int FUN_a00ba950();
extern int FUN_a00bab80();

int FUN_a00c1078(int param_1)
{
    unsigned char value;
    int diff;
    
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
    
    DAT_a802d47e = (unsigned char)diff;
    FUN_a00b88cc();
    FUN_a00baa6c(param_1);
    FUN_a00ba950(param_1);
    FUN_a00bab80(param_1, 6);
    return 0;
}
