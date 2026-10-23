/* leon2m FUN_a00c3ec8 @ 0xa00c3ec8 (-mcpu=v8 -O2 -g)
 * Reads byte 0xA802D049 (port 2), 0xA802D0A1 (port 3) or 0xA802D0D9 (other ports); d = byte - '0'; d > 2 (as a
 * byte) -> returns 0xff. Else byte 0xA802D2DB = d, FUN_a00d5eac(1), FUN_a00baa6c(port), FUN_a00ba950(port),
 * FUN_a00bab80(port, 6) and returns 0. The firmware sets the argument 1 of FUN_a00d5eac before the compare.
 */
extern unsigned char DAT_a802d049;
extern unsigned char DAT_a802d0a1;
extern unsigned char DAT_a802d0d9;
extern unsigned char DAT_a802d2db;
extern int FUN_a00d5eac(int);
extern int FUN_a00baa6c();
extern int FUN_a00ba950();
extern int FUN_a00bab80();

int FUN_a00c3ec8(int param_1)
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
    
    DAT_a802d2db = (unsigned char)diff;
    FUN_a00d5eac(1);
    FUN_a00baa6c(param_1);
    FUN_a00ba950(param_1);
    FUN_a00bab80(param_1, 6);
    return 0;
}
