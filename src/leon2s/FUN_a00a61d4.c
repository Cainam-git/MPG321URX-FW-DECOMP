/* leon2s FUN_a00a61d4 @ 0xa00a61d4  MATCH (-mcpu=v8 -Os -g)
 * Returns 1 when param_1 is 0x71 and the low byte of FUN_a00ad784(0) is 1, or when param_1 is 0x81 and the low
 * byte of FUN_a00ad784(1) is 1; otherwise returns 0. The firmware loads the argument 0 with clr %o0 before the
 * first comparison and the argument 1 with mov 1, %o0 in the branch delay slot; the bne of the second comparison
 * branches straight to the return.
 */
extern int FUN_a00ad784();

unsigned char FUN_a00a61d4(unsigned char param_1)
{
    unsigned char result;
    
    result = 0;
    param_1 = param_1 & 0xff;
    if (param_1 == 0x71) {
        if ((FUN_a00ad784(0) & 0xff) == 1) {
            result = 1;
        }
    } else if (param_1 == 0x81) {
        if ((FUN_a00ad784(1) & 0xff) == 1) {
            result = 1;
        }
    }
    return result;
}
