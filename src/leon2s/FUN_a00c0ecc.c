/* leon2s FUN_a00c0ecc @ 0xa00c0ecc-0xa00c0f88 (47 words), flags -mcpu=v8 -Os -g.
 * Code facts: copies ROM tables into three caller buffers with u16 counters: dst1[i] = DAT_9f1b7148[0x13 - i]
 * for i = 0..15 (reversed), dst2[i] = DAT_9f1b7148[0x28 + i] for i = 0..0x209, dst3[i] = DAT_9f1b74b8[i]
 * for i = 0..0x7f. dst3 is the FOURTH parameter (%i3); the third parameter is never read (the fw reuses
 * %i2 as a temp). void.
 * Fixes vs the autoc draft (78.72): BEHAVIOUR: dst3 = param_4 (the draft wrote through param_3); the second
 * table is DAT_9f1b7148 + 0x28 (same symbol: fw [base + i + 0x28], the draft named 0x9f1b7170 separately).
 * Aids: none.
 */
extern const unsigned char DAT_9f1b7148[];
extern const unsigned char DAT_9f1b74b8[];

void FUN_a00c0ecc(unsigned char *param_1, unsigned char *param_2, unsigned char *param_3,
                  unsigned char *param_4)
{
    unsigned short i;

    for (i = 0; i <= 0xf; i++)
        param_1[i] = DAT_9f1b7148[0x13 - i];
    for (i = 0; i <= 0x209; i++)
        param_2[i] = DAT_9f1b7148[0x28 + i];
    for (i = 0; i <= 0x7f; i++)
        param_4[i] = DAT_9f1b74b8[i];
}
