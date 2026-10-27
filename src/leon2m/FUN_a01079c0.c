/* FUN_a01079c0 (leon2m 0xa01079c0-0xa01079f4, 52 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Copies the five bytes p[0..4] to the byte array DAT_a8027a82. Nothing in the image refers to it: no call, branch,
 * sethi/or constant or address word. It lies between FUN_a010795c and FUN_a01079f4.
 */
extern unsigned char DAT_a8027a82[];

void FUN_a01079c0(const unsigned char *p)
{
    DAT_a8027a82[0] = p[0];
    DAT_a8027a82[1] = p[1];
    DAT_a8027a82[2] = p[2];
    DAT_a8027a82[3] = p[3];
    DAT_a8027a82[4] = p[4];
}
