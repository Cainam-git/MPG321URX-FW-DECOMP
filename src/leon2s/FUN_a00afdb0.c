/* leon2s FUN_a00afdb0 @ 0xa00afdb0  MATCH (-mcpu=v8 -Os -g)
 * The function masks its first argument to a byte, calls a helper to compute a value, masks that result, passes it to another helper, then calls a fixed-argument function, and finally tail-calls a fourth function with the computed value and three of the original parameters. The main fix was adding the `& 0xff` on the result of `FUN_a00add48` and using that masked value as the first argument to the final tail call instead of the original parameter. Open question: whether the final call is truly a tail call or the compiler emits the trailing `nop` as a return-address placeholder; the C relies on the compiler's sibling-call optimization to produce the observed `restore` in the delay slot and the `nop`.
 */
extern int func_0x9f1c6624();  /* 0x9f1c6624 */
extern int FUN_a00add48();     /* 0xa00add48 */
extern int FUN_a00a8400();     /* 0xa00a8400 */
extern int FUN_a00a8370();     /* 0xa00a8370 */

void FUN_a00afdb0(unsigned char param_1, unsigned int param_2, unsigned int param_3,
                  unsigned int param_4, unsigned int param_5, unsigned int param_6)
{
    unsigned int uVar1;

    param_1 = param_1 & 0xff;
    uVar1 = func_0x9f1c6624(param_1);
    uVar1 = FUN_a00add48(param_1, uVar1 & 0xff) & 0xff;
    FUN_a00a8400(uVar1, 1, 0x20, 1);
    FUN_a00a8370(uVar1, 3, 2, param_4, param_5, param_6);
}
