/* leon2m FUN_a00c3e3c @ 0xa00c3e3c (-mcpu=v8 -O3 -g)
 * Twin of FUN_a00c3ec8: same code, other constants.
 */
extern unsigned char DAT_a802d049;
extern unsigned char DAT_a802d0a1;
extern unsigned char DAT_a802d0d9;
extern unsigned char DAT_a802d2dc;
extern int FUN_a00d5eac(int);
extern int FUN_a00baa6c();
extern int FUN_a00ba950();
extern int FUN_a00bab80();

int FUN_a00c3e3c(int param_1)
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
    
    DAT_a802d2dc = (unsigned char)diff;
    FUN_a00d5eac(1);
    FUN_a00baa6c(param_1);
    FUN_a00ba950(param_1);
    FUN_a00bab80(param_1, 6);
    return 0;
}
