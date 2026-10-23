/* leon2s FUN_a00c8360 @ 0xa00c8360 (-mcpu=v8 -Os -g)
 * p = p1 & 0xff. r = FUN_a00c8048(p, 0x74, 0x40, 1) & 0xff, returned when non-zero; then r = FUN_a00c81f8(p, buf, 1) & 0xff,
 * returned when non-zero; otherwise sets bit 28 of word 0 of the 24-byte record p at 0xA8078BB0 when bit 6 of buf[0]
 * is set, and returns 0.
 */
extern unsigned int DAT_a8078bb0[];
extern int FUN_a00c8048();
extern int FUN_a00c81f8();

int FUN_a00c8360(unsigned int param_1, unsigned char *param_2)
{
    unsigned int uVar1;
    unsigned int uVar2;
    
    param_1 = param_1 & 0xff;
    uVar1 = FUN_a00c8048(param_1, 0x74, 0x40, 1) & 0xff;
    if (uVar1 == 0) {
        uVar2 = FUN_a00c81f8(param_1, param_2, 1) & 0xff;
        if (uVar2 == 0) {
            if ((*param_2 & 0x40) != 0) {
                DAT_a8078bb0[param_1 * 6] |= 0x10000000;
            }
            return 0;
        }
        return uVar2;
    }
    return uVar1;
}
