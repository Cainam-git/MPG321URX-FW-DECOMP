/* FUN_a014b844: ch 0: byte +0x2a of the RAM record DAT_a802e3d0 = v, FUN_a01302a4(2, v == 1),
 * FUN_a012f1ec(2, 0), FUN_a0132770(byte +0x2a). ch 1: byte +0x2c = v, FUN_a01302a4(3, v == 1),
 * FUN_a012f1ec(3, 0), FUN_a01327e0(byte +0x2c). In all cases FUN_a013129c() is tail-called at the end.
 * Callers: FUN_a00d5a9c. The v == 1 argument is written as an if/else of two calls (the firmware sets both
 * argument registers in each branch).
 */
extern unsigned char DAT_a802e3d0[];
extern void FUN_a01302a4(unsigned char ch, unsigned char on);
extern void FUN_a012f1ec(unsigned char ch, unsigned char mode);
extern void FUN_a0132770(unsigned char v);
extern void FUN_a01327e0(unsigned char v);
extern void FUN_a013129c(void);

void FUN_a014b844(unsigned char ch, unsigned char v)
{
    if (ch == 0) {
        DAT_a802e3d0[0x2a] = v;
        if (v == 1)
            FUN_a01302a4(2, 1);
        else
            FUN_a01302a4(2, 0);
        FUN_a012f1ec(2, 0);
        FUN_a0132770(DAT_a802e3d0[0x2a]);
    } else if (ch == 1) {
        DAT_a802e3d0[0x2c] = v;
        if (v == 1)
            FUN_a01302a4(3, 1);
        else
            FUN_a01302a4(3, 0);
        FUN_a012f1ec(3, 0);
        FUN_a01327e0(DAT_a802e3d0[0x2c]);
    }
    FUN_a013129c();
}
