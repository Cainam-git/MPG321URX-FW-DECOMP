/* FUN_a00d8064 (leon2m 0xa00d8064-0xa00d80b0, 76 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Calls FUN_a014bd0c(c) as a tail call when c is 0, 1, 2 or 3. Nothing in the image refers to it: no call, branch,
 * sethi/or constant or address word. It lies between FUN_a00d8034 and FUN_a00d80b0. Source form: an if/else chain
 * with a constant argument per call (GCC merges the four calls).
 */
extern void FUN_a014bd0c(unsigned char);
void FUN_a00d8064(unsigned char c)
{
    if (c == 0)
        FUN_a014bd0c(0);
    else if (c == 1)
        FUN_a014bd0c(1);
    else if (c == 2)
        FUN_a014bd0c(2);
    else if (c == 3)
        FUN_a014bd0c(3);
}
