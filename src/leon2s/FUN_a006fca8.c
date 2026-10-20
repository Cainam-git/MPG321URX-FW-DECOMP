/* FUN_a006fca8 (leon2s 0xa006fca8-0xa006fd04, 92 bytes), flags -mcpu=v8 -Os -g.
 * Reads 4 words from slot 0, word 0 through FUN_a006faa8 into a zeroed local buffer, then stores the low seven
 * nibbles of buffer word 1 into out[0..6] (nibble i into out[i]). The count is a variable (gives 'cmp 7; bcs').
 */
extern void FUN_a006faa8(unsigned char slot, int word, unsigned int *buf, unsigned char n);

void FUN_a006fca8(unsigned char *out)
{
    unsigned int buf[4] = { 0, 0, 0, 0 };
    unsigned char i;
    unsigned char n = 7;

    FUN_a006faa8(0, 0, buf, 4);
    for (i = 0; i < n; i++)
        out[i] = (buf[1] >> (i * 4)) & 0xf;
}
