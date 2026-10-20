/* leon2s FUN_a00856fc @ 0xa00856fc (-mcpu=v8 -Os -g)
 * c = FUN_a0083ed0(param_1 & 0xFF) & 0xFF; every register access below passes c first. When bit 1 of register
 * 0x4B1 (read with FUN_a00a74b8) is set: writes 2 and then 0 to 0x4B1 (FUN_a00a7614) and, when bit 5 of 0x409 is
 * set, 0xB4 to 0xAF. When bit 1 of 0x4B2 is set: writes 2 and then 0 to 0x4B2 and, when bit 5 of 0x409 is clear,
 * 0x94 to 0xAF (tail call). Passing the masked input to FUN_a0083ed0 and masking its return produces the first two
 * instructions.
 */
extern int FUN_a0083ed0(int);                 /* 0xa0083ed0 */
extern int FUN_a00a74b8(int, int);            /* 0xa00a74b8 */
extern void FUN_a00a7614(int, int, int);      /* 0xa00a7614 */

void FUN_a00856fc(unsigned char param_1, int param_2, int param_3,
                  int param_4, int param_5, int param_6)
{
    unsigned int uVar3;
    unsigned int uVar1;

    uVar3 = FUN_a0083ed0(param_1 & 0xff) & 0xff;

    uVar1 = FUN_a00a74b8(uVar3, 0x4b1);
    if ((uVar1 & 2) != 0) {
        FUN_a00a7614(uVar3, 0x4b1, 2);
        FUN_a00a7614(uVar3, 0x4b1, 0);
        uVar1 = FUN_a00a74b8(uVar3, 0x409);
        if ((uVar1 & 0x20) != 0) {
            FUN_a00a7614(uVar3, 0xaf, 0xb4);
        }
    }

    uVar1 = FUN_a00a74b8(uVar3, 0x4b2);
    if ((uVar1 & 2) != 0) {
        param_2 = 0xaf;
        FUN_a00a7614(uVar3, 0x4b2, 2);
        FUN_a00a7614(uVar3, 0x4b2, 0);
        uVar1 = FUN_a00a74b8(uVar3, 0x409);
        if ((uVar1 & 0x20) == 0) {
            param_3 = 0x94;
            FUN_a00a7614(uVar3, param_2, param_3);
        }
    }
}
