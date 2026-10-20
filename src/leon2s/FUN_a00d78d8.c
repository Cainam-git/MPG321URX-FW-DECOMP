/* leon2s FUN_a00d78d8 @ 0xa00d78d8 (-mcpu=v8 -Os -g)
 * The loop now keeps `bVar1` as the counter, masks it with `& 0xff` at each use (matching the `and %o3, 0xff, %g1`), and compares the masked value against 0xf (matching `cmp %o5, 0xf; bleu`). The store happens before the increment, putting the `stb` in the branch delay slot as the target shows.
 */
extern void FUN_a00d78d8(unsigned char *param_1, unsigned char *param_2);

void FUN_a00d78d8(unsigned char *param_1, unsigned char *param_2)
{
    unsigned char bVar1;
    unsigned char bVar2;

    *param_2 = *param_1;
    bVar1 = 0;
    do {
        bVar2 = param_1[(bVar1 & 0xff) + 1];
        param_2[(bVar1 & 0xff) + 1] = bVar2;
        bVar1 = bVar1 + 1;
    } while ((bVar1 & 0xff) < 0x10);
    param_2[0x11] = param_1[0x11];
    param_2[0x12] = param_1[0x12];
    return;
}
