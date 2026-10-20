/* leon2s FUN_a00c9968 @ 0xa00c9968  MATCH (-mcpu=v8 -Os -g)
 * Calls FUN_a00c76c0(param_1, 4, 0x80, flag) with flag = 1 when param_2 is non-zero, else 0. param_2 is an
 * unsigned char (btst 0xff, %o1). The bne goes to the clr %o3 path and the fall-through sets %o3 = 1; mov 4, %o1
 * sits in the branch delay slot.
 */
extern int FUN_a00c76c0();

void FUN_a00c9968(unsigned char param_1, unsigned char param_2)
{
    if (param_2 != 0)
        FUN_a00c76c0(param_1, 4, 0x80, 1);
    else
        FUN_a00c76c0(param_1, 4, 0x80, 0);
    return;
}
