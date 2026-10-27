/* FUN_a00badc0 (leon2m 0xa00badc0-0xa00badf8, 56 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Stores bytes 0x12, 0x13 and 0x14 of DAT_a802d290, each plus 0x30, to DAT_a802d078[7], [8] and [9]. Nothing in the
 * image refers to it: no call, branch, sethi/or constant or address word. It lies between FUN_a00bad4c and
 * FUN_a00badf8.
 */
extern unsigned char DAT_a802d290[];
extern unsigned char DAT_a802d078[];

void FUN_a00badc0(void)
{
    DAT_a802d078[7] = DAT_a802d290[0x12] + 0x30;
    DAT_a802d078[8] = DAT_a802d290[0x13] + 0x30;
    DAT_a802d078[9] = DAT_a802d290[0x14] + 0x30;
}
