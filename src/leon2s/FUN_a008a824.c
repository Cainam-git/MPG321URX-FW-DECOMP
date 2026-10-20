/* leon2s FUN_a008a824 @ 0xa008a824 (-mcpu=v8 -Os -g)
 * This should match: the `param_1 != 0` gives `btst 0xff, %o0` followed by branch, the `else if` gives the nested test, and the two separate stores are at the right places.
 */
#define REG_011018 (*(volatile unsigned int *)0xcf011018)
#define REG_011200 (*(volatile unsigned int *)0xcf011200)

void FUN_a008a824(unsigned char param_1)
{
    if (param_1 != 0) {
        REG_011018 = REG_011018 | 0xc;
    } else if ((REG_011200 & 0xf) != 0) {
        REG_011018 = REG_011018 & 0xfffffff3;
    }
}
