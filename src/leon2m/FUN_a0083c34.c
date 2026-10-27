/* FUN_a0083c34 (leon2m 0xa0083c34-0xa0083c88, 84 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Returns 1 when the bytes DAT_a8024018[1..4] are 'P', 'l', 'a', 'y', otherwise 0. Nothing in the image refers to
 * it: no call, branch, sethi/or constant or address word. It lies between FUN_a0083c20 and FUN_a0083c88.
 */
extern unsigned char DAT_a8024018[];

int FUN_a0083c34(void)
{
    if (DAT_a8024018[1] == 'P' && DAT_a8024018[2] == 'l' && DAT_a8024018[3] == 'a' && DAT_a8024018[4] == 'y')
        return 1;
    return 0;
}
