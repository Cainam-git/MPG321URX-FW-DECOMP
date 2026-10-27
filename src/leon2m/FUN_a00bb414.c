/* FUN_a00bb414 (leon2m 0xa00bb414-0xa00bb44c, 56 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Clears the byte DAT_a802b09a and the 0x32 bytes DAT_a802d040[0..0x31]. Nothing in the image refers to it: no
 * call, branch, sethi/or constant or address word. It lies between FUN_a00bb260 and FUN_a00bb44c. Source form: an
 * unsigned char loop counter.
 */
extern unsigned char DAT_a802b09a;
extern unsigned char DAT_a802d040[];

void FUN_a00bb414(void)
{
    unsigned char i;

    DAT_a802b09a = 0;
    for (i = 0; i < 0x32; i++)
        DAT_a802d040[i] = 0;
}
