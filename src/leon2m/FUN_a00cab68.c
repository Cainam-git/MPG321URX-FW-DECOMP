/* leon2m FUN_a00cab68 @ 0xa00cab68 (-mcpu=v8 -O3 -g)
 * k = p1 & 0xff; b = byte 0xA802D049 for k == 2, 0xA802D0A1 for k == 3, 0xA802D0D9 otherwise. When b - '0' (8
 * bits) is above 1 returns 0xFF; otherwise stores b - '0' in byte 0xA802D471, calls FUN_a00dab20(),
 * FUN_a00b88cc(), FUN_a00baa6c(k), FUN_a00ba950(k) and FUN_a00bab80(k, 6) and returns 0. Same code as FUN_a00cb3a8
 * with other constants.
 */
extern unsigned char DAT_a802d049;
extern unsigned char DAT_a802d0a1;
extern unsigned char DAT_a802d0d9;
extern unsigned char DAT_a802d471;
extern void FUN_a00dab20(void);
extern void FUN_a00b88cc(void);
extern int FUN_a00baa6c();
extern int FUN_a00ba950();
extern int FUN_a00bab80();

int FUN_a00cab68(int param_1)
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
    
    DAT_a802d471 = diff;
    FUN_a00dab20();
    FUN_a00b88cc();
    FUN_a00baa6c(param_1);
    FUN_a00ba950(param_1);
    FUN_a00bab80(param_1, 6);
    return 0;
}
