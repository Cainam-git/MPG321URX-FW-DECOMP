/* leon2s FUN_a00c30e4 @ 0xa00c30e4 (-mcpu=v8 -Os -g)
 * This should give: first check `param <= 1`, if true do the call and bit test; if false, check `param > 3`, and within that check `param <= 5`; otherwise (2-3) set result = 1. The branch structure should match: the `bgu` for `param > 1`, the `be` for bit test, the `bleu` for `param <= 3`, and the `bgu` for `param > 5`.
 */
extern int func_0xa0fb657c();

int FUN_a00c30e4(unsigned int param_1)
{
    unsigned char result = 0;
    
    param_1 = param_1 & 0xff;
    if (param_1 <= 1) {
        if ((func_0xa0fb657c(param_1, 0x319) & 0x10) != 0) {
            result = 1;
        }
    } else if (param_1 > 3) {
        if (param_1 <= 5) {
            result = 1;
        }
    } else {
        result = 1;
    }
    return result;
}
