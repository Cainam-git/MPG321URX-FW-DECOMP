/* leon2m FUN_a01235b4 @ 0xa01235b4 (-mcpu=v8 -O2 -g)
 * The function takes a byte parameter, calls a helper twice with different constants, and checks if the results match one of three (x, y) pairs, returning 1 for a match or 0 otherwise. Whether the original used `||` or separate `if` statements for the branch pattern is not determined; the logic is the same.
 */
extern int FUN_a00f2e30(int, int); /* at 0xa00f2e30 */

int FUN_a01235b4(unsigned char param_1)
{
    unsigned char x = FUN_a00f2e30(param_1 & 0xff, 0x10) & 0xf;
    unsigned char y = FUN_a00f2e30(param_1 & 0xff, 9) & 0xff;
    
    if (x == 8 && y == 0xff)
        return 1;
    if (x == 4 && y == 0xf)
        return 1;
    return (x == 2 && y == 3);
}
