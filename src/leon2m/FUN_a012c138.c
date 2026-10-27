/* FUN_a012c138 (leon2m 0xa012c138-0xa012c16c, 52 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Replaces the four-bit field i (bits 4i..4i+3) of the word DAT_a802cb08 with v >> 7 (v a halfword). Nothing in the
 * image refers to it: no call, branch, sethi/or constant or address word. It lies between FUN_a012c130 and
 * FUN_a012c16c.
 */
extern unsigned int DAT_a802cb08;

void FUN_a012c138(unsigned char i, unsigned short v)
{
    unsigned int s = i * 4;

    DAT_a802cb08 = ((v >> 7) << s) | (DAT_a802cb08 & ~(0xf << s));
}
