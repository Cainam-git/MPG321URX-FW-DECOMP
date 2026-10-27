/* FUN_a0148d34 (leon2m 0xa0148d34-0xa0148d98, 100 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Calls FUN_a011dd9c(7, v) as a tail call when c is 0, 1 or 2. Nothing in the image refers to it: no call, branch,
 * sethi/or constant or address word. It lies between FUN_a0148c94 and FUN_a0148d98. Source form: a switch with a
 * separate call per case (GCC merges them).
 */
extern void FUN_a011dd9c(unsigned char a, unsigned short b);

void FUN_a0148d34(unsigned char c, unsigned short v)
{
    switch (c) {
    case 0:
        FUN_a011dd9c(7, v);
        break;
    case 1:
        FUN_a011dd9c(7, v);
        break;
    case 2:
        FUN_a011dd9c(7, v);
        break;
    }
}
