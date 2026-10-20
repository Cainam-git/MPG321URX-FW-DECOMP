/* leon2s FUN_a00ac5a4 @ 0xa00ac5a4 (-mcpu=v8 -Os -g)
 * Polls FUN_a00a6bb8(param_1 & 0xFF, 0xC1) until bit 6 of the result is set, then calls FUN_a00a6c98(port, 0xC1,
 * 0x80, 1), writes 0 to 0x3D2, 0x3D1 and 0x3D0 through FUN_a00a6c00, and ends with FUN_a00a6c98(port, 0xC1, 0x80,
 * 0). The loop tests the return value of FUN_a00a6bb8 (btst %o0), not the parameter as in Ghidra's output.
 */
/* FUN_a00a6bb8 at 0xa00a6bb8 */
extern int FUN_a00a6bb8(unsigned int, int);
/* FUN_a00a6c00 at 0xa00a6c00 */
extern void FUN_a00a6c00(unsigned int, int, int);
/* FUN_a00a6c98 at 0xa00a6c98 */
extern void FUN_a00a6c98(unsigned int, int, int, int);

void FUN_a00ac5a4(unsigned int param_1)
{
    unsigned int uVar2;
    unsigned int uVar1;

    do {
        uVar2 = param_1 & 0xff;
        uVar1 = FUN_a00a6bb8(uVar2, 0xc1);
    } while ((uVar1 & 0x40) == 0);

    FUN_a00a6c98(uVar2, 0xc1, 0x80, 1);
    FUN_a00a6c00(uVar2, 0x3d2, 0);
    FUN_a00a6c00(uVar2, 0x3d1, 0);
    FUN_a00a6c00(uVar2, 0x3d0, 0);
    FUN_a00a6c98(uVar2, 0xc1, 0x80, 0);
}
