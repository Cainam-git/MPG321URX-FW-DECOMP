/* leon2s FUN_a00acb00 @ 0xa00acb00 (-mcpu=v8 -Os -g)
 * Twin of FUN_a00acac0: same code, other constants.
 */
typedef unsigned int uint;
typedef unsigned short ushort;

extern uint FUN_a00a6bb8(uint param_1, ushort param_2);

ushort FUN_a00acb00(uint param_1)
{
    uint uVar1;

    param_1 = param_1 & 0xff;
    uVar1 = (FUN_a00a6bb8(param_1, 0x8b) & 0xff) << 8;
    return (ushort)(uVar1 + (FUN_a00a6bb8(param_1, 0x8c) & 0xff));
}
