/* leon2s FUN_a0088af0 @ 0xa0088af0  MATCH (-mcpu=v8 -Os -g)
 * For a port byte of 0, 2, 3, 4 or 1 calls FUN_a0083648 with that value and returns 1 if the call returned 0, else
 * 0; any other value returns 0 without a call. The if/else chain tests the values in the target order 0, 2, 3, 4,
 * 1; the result local starts at 0 and is set to 1 only on success.
 */
extern int FUN_a0083648(int param_1);

int FUN_a0088af0(unsigned char param_1)
{
    unsigned char l0;
    
    param_1 = param_1 & 0xff;
    l0 = 0;
    if (param_1 == 0) {
        if (FUN_a0083648(0) == 0) {
            l0 = 1;
        }
    } else if (param_1 == 2) {
        if (FUN_a0083648(2) == 0) {
            l0 = 1;
        }
    } else if (param_1 == 3) {
        if (FUN_a0083648(3) == 0) {
            l0 = 1;
        }
    } else if (param_1 == 4) {
        if (FUN_a0083648(4) == 0) {
            l0 = 1;
        }
    } else if (param_1 == 1) {
        if (FUN_a0083648(1) == 0) {
            l0 = 1;
        }
    }
    return l0 & 1;
}
