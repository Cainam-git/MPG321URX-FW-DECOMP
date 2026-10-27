/* FUN_a01483b8 (leon2m 0xa01483b8-0xa01483f4, 60 bytes, leaf), flags -mcpu=v8 -Os -g.
 * Copies the 0x58 bytes DAT_a802e378[0..0x57] to p[0..0x57]. Nothing in the image refers to it: no call, branch,
 * sethi/or constant or address word. It lies between FUN_a014837c and FUN_a01483f4. Source form: an unsigned short
 * loop counter.
 */
extern unsigned char DAT_a802e378[];
void FUN_a01483b8(unsigned char *p)
{
    unsigned short i;
    for (i = 0; i < 0x58; i++)
        *(p + i) = *(i + DAT_a802e378);
}
