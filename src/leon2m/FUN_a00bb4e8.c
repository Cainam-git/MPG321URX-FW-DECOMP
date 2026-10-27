/* FUN_a00bb4e8 (leon2m 0xa00bb4e8-0xa00bb520, 56 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Stores the six bytes 0x35, 0x36, 0x30, 0x30, 0x2b, 0x0d to DAT_a802d128[0..5]. Nothing in the image refers to it:
 * no call, branch, sethi/or constant or address word. It lies between FUN_a00bb49c and FUN_a00bb520.
 */
extern unsigned char DAT_a802d128[];

void FUN_a00bb4e8(void)
{
    DAT_a802d128[0] = 0x35;
    DAT_a802d128[1] = 0x36;
    DAT_a802d128[2] = 0x30;
    DAT_a802d128[3] = 0x30;
    DAT_a802d128[4] = 0x2b;
    DAT_a802d128[5] = 0xd;
}
