/* leon2m FUN_a00b0fc0 @ 0xa00b0fc0-0xa00b1004 (17 words).
 * Toggles byte 0xa802d43a (offset 0x1aa of the block at 0xa802d290) between 0 and 1 (new value = 1 - old) and
 * tail-calls FUN_a00b0710(0, 1) when the new value is 1, FUN_a00b0710(0, 0) otherwise. Leaf function directly after
 * FUN_a00b0f48 (split from it in the function table).
 */
extern unsigned char DAT_a802d290[];
extern void FUN_a00b0710(int, int);

void FUN_a00b0fc0(void)
{
    unsigned char v = 1 - DAT_a802d290[0x1aa];

    DAT_a802d290[0x1aa] = v;
    if (v == 1)
        FUN_a00b0710(0, 1);
    else
        FUN_a00b0710(0, 0);
}
