/* leon2s FUN_a008b934 @ 0xa008b934  MATCH (-mcpu=v8 -Os -g)
 * This function masks its byte argument, programs two scaler registers through the helper functions, then updates a bitfield byte at `0xa8078b54`: it sets bit `param_1` and clears bit `param_1 + 4` (i.e. `0x10 << param_1`). The decompiler’s bogus second parameter and `CONCAT44` return are dropped, and the explicit `& 0x1f` shift masks are left out so the compiler uses the already-masked `%i0` directly, matching the target’s `sll` instructions.
 */
extern unsigned char DAT_a8078b54; /* 0xa8078b54 */
extern void FUN_a00a6c98(unsigned int, unsigned int, unsigned int, unsigned int); /* 0xa00a6c98 */
extern void FUN_a00a6fc0(unsigned int, unsigned int, unsigned int); /* 0xa00a6fc0 */

void FUN_a008b934(unsigned char param_1) /* 0xa008b934 */
{
    unsigned int uVar1;

    uVar1 = param_1 & 0xff;
    FUN_a00a6c98(uVar1, 0x50, 0x40, 1);
    FUN_a00a6fc0(uVar1, 4, 0xff);
    FUN_a00a6fc0(uVar1, 3, 0xff);
    FUN_a00a6c98(uVar1, 0x50, 0x10, 0);
    DAT_a8078b54 = ((1 << uVar1) | DAT_a8078b54) & ~(0x10 << uVar1);
}
