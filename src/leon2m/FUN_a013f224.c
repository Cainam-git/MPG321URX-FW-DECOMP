/* FUN_a013f224 (leon2m 0xa013f224-0xa013f284, 96 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Returns 1 when one of the first 13 four-byte entries of DAT_001a59e2 has byte +0 equal to 0xc and halfword +2
 * equal to k, otherwise 0. Nothing in the image refers to it: no call, branch, sethi/or constant or address word.
 * It lies between FUN_a013f204 and FUN_a013f284.
 */
struct T4 { unsigned char b0, b1; unsigned short h2; };
extern const struct T4 DAT_001a59e2[];

int FUN_a013f224(unsigned short k)
{
    unsigned char i;

    for (i = 0; i < 13; i++)
        if (DAT_001a59e2[i].b0 == 0xc && DAT_001a59e2[i].h2 == k)
            return 1;
    return 0;
}
