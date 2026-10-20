/* leon2m FUN_a00c1100 @ 0xa00c1100 (-mcpu=v8 -O2 -g)
 * The `diff` variable holds the `value - 0x30` (which becomes `%o4`), and `(unsigned char)diff` forces the mask to `0xff` (which becomes `%o5`). The store `DAT_a802d40c = (unsigned char)diff` uses the same `%o4` value.
 */
extern unsigned char DAT_a802d049;
extern unsigned char DAT_a802d0a1;
extern unsigned char DAT_a802d0d9;
extern unsigned char DAT_a802d40c;
extern void FUN_a00b88cc(void);
extern int FUN_a00ba950();
extern int FUN_a00baa6c();
extern int FUN_a00bab80();

int FUN_a00c1100(int param_1)
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
    if ((unsigned char)diff > 2) {
        return 0xff;
    }
    
    DAT_a802d40c = (unsigned char)diff;
    FUN_a00b88cc();
    FUN_a00baa6c(param_1);
    FUN_a00ba950(param_1);
    FUN_a00bab80(param_1, 6);
    return 0;
}
