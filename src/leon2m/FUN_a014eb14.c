/* FUN_a014eb14: looks for a free slot among the candidates {1, 3}: the first candidate c whose 4-bit field
 * (DAT_a802cc80 >> (4 * c)) & 0xf is 0 is the result, 4 when none is free. Logs "IsAnyACRAvailable %d"
 * (s_001a7328, with colour codes) and returns the result. No direct callers were found.
 * Built with -mcpu=v8 -O3 (no -g: the firmware has no nop after the final call).
 */
extern unsigned short DAT_a802cc80;
extern int FUN_a00df170();
extern char s_001a7328[];

unsigned char FUN_a014eb14(void)
{
    unsigned char tab[2] = {1, 3};
    unsigned char i, r = 4;

    for (i = 0; i < 2; i++)
        if (((DAT_a802cc80 >> (tab[i] * 4)) & 0xf) == 0)
            break;
    if (i < 2)
        r = tab[i];
    FUN_a00df170(s_001a7328, r);
    return r;
}
