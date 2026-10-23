/* leon2m FUN_a00cb3a8 @ 0xa00cb3a8 (-mcpu=v8 -O2 -g)
 * Reads byte 0xA802D049 (port 2), 0xA802D0A1 (port 3) or 0xA802D0D9 (other ports) of the receive buffer; d = byte
 * - '0' (u16); d > 1 (as a byte) -> returns 0xff. Else halfword 0xA802D478 = d, FUN_a00dac00(), FUN_a00b88cc(),
 * FUN_a00baa6c(port), FUN_a00ba950(port), FUN_a00bab80(port, 6) and returns 0.
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
