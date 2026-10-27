/* FUN_a00bac04 (leon2m 0xa00bac04-0xa00bac3c, 56 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Stores the six bytes 0x35, 0x36, 0x30, 0x30, 0xee, 0x0d to DAT_a802d078[0..5]. Nothing in the image refers to it:
 * no call, branch, sethi/or constant or address word. It lies between FUN_a00babe4 and FUN_a00bac3c.
 */
extern unsigned char DAT_a802d078[];

void FUN_a00bac04(void)
{
    DAT_a802d078[0] = 0x35;
    DAT_a802d078[1] = 0x36;
    DAT_a802d078[2] = 0x30;
    DAT_a802d078[3] = 0x30;
    DAT_a802d078[4] = 0xee;
    DAT_a802d078[5] = 0xd;
}
