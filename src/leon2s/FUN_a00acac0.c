/* leon2s FUN_a00acac0 @ 0xa00acac0 (-mcpu=v8 -Os -g)
 * This way, the first call's result is masked and shifted immediately after the call (stored in `%i0`), then the second call happens, and its result is masked and added. The final `(ushort)` cast would generate the shift-left-16/shift-right-16 masking.
 */
typedef unsigned int uint;
typedef unsigned short ushort;

extern uint FUN_a00a6bb8(uint param_1, ushort param_2);

ushort FUN_a00acac0(uint param_1)
{
    uint uVar1;

    param_1 = param_1 & 0xff;
    uVar1 = (FUN_a00a6bb8(param_1, 0x89) & 0xff) << 8;
    return (ushort)(uVar1 + (FUN_a00a6bb8(param_1, 0x8a) & 0xff));
}
