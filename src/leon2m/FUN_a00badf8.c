/* FUN_a00badf8 (leon2m 0xa00badf8-0xa00bae38, 64 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Stores 0x30 to DAT_a802d078[7] and the bytes DAT_a802d290[k + 0x197] + 0x30 and DAT_a802d290[k + 0x19b] + 0x30 to
 * DAT_a802d078[8] and [9], k the byte DAT_a802cffd. Nothing in the image refers to it: no call, branch, sethi/or
 * constant or address word. It lies between FUN_a00badc0 and FUN_a00bae38.
 */
extern unsigned char DAT_a802cffd;
extern unsigned char DAT_a802d290[];
extern unsigned char DAT_a802d078[];

void FUN_a00badf8(void)
{
    DAT_a802d078[7] = 0x30;
    DAT_a802d078[8] = DAT_a802d290[DAT_a802cffd + 0x197] + 0x30;
    DAT_a802d078[9] = DAT_a802d290[DAT_a802cffd + 0x19b] + 0x30;
}
