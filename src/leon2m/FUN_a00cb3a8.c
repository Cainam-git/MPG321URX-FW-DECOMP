/* leon2m FUN_a00cb3a8 @ 0xa00cb3a8 (-mcpu=v8 -O2 -g)
 * This function reads a byte from one of three addresses based on the input parameter (2, 3, or other), subtracts 0x30 from it, and if the result is 0 or 1 (after masking to a byte), stores it to a global, then performs a sequence of initialization calls. The check `(unsigned char)diff > 1` matches the `bgu` after `cmp %o5, 1` in the assembly. The main uncertainty is whether the difference check should be `> 1` or `> 2` — the assembly shows `cmp %o5, 1; bgu`, which means branch if unsigned greater than 1, so values 0 and 1 pass, anything else fails with 0xff.
 */
extern unsigned char DAT_a802d049;
extern unsigned char DAT_a802d0a1;
extern unsigned char DAT_a802d0d9;
extern unsigned char DAT_a802d478;
extern void FUN_a00dac00(void);
extern void FUN_a00b88cc(void);
extern int FUN_a00baa6c();
extern int FUN_a00ba950();
extern int FUN_a00bab80();

int FUN_a00cb3a8(int param_1)
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
    
    DAT_a802d478 = diff;
    FUN_a00dac00();
    FUN_a00b88cc();
    FUN_a00baa6c(param_1);
    FUN_a00ba950(param_1);
    FUN_a00bab80(param_1, 6);
    return 0;
}
