/* FUN_a00bb528 (leon2m 0xa00bb528-0xa00bb560, 56 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Clears the byte DAT_a802b09a and the 0x32 bytes DAT_a802d040[0..0x31], then returns 0. Nothing in the image
 * refers to it: no call, branch, sethi/or constant or address word. It lies between FUN_a00bb520 and FUN_a00bb560.
 * Source form: an unsigned char loop counter.
 */
extern unsigned char DAT_a802b09a;
extern unsigned char DAT_a802d040[];

int FUN_a00bb528(void)
{
    unsigned char i;

    DAT_a802b09a = 0;
    for (i = 0; i < 0x32; i++)
        DAT_a802d040[i] = 0;
    return 0;
}
