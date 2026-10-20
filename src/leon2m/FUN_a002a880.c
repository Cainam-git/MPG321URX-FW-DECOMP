/* leon2m FUN_a002a880 @ 0xa002a880-0xa002a910 (36 words).
 * Finds the lowest set bit b of the 16-bit mask (16 when none). When b is not 16, i < 15 and b is below byte
 * 0x199278 + i, word 0xa802b170 + 4 * (16 * i + b) = v.
 */
extern const unsigned char DAT_00199278[];
extern unsigned int DAT_a802b170[15][16];

void FUN_a002a880(unsigned int i, unsigned short mask, unsigned int v)
{
    unsigned short b;

    for (b = 0; b < 16; b++)
        if ((mask >> b) & 1)
            break;
    if (b == 16)
        return;
    if (i >= 15)
        return;
    if (b >= DAT_00199278[i])
        return;
    DAT_a802b170[i][b] = v;
}
