/* FUN_a00da9e8 (leon2s 0xa00da9e8-0xa00daa98, 176 bytes), flags -mcpu=v8 -Os -g.
 * Reads byte 0 of the 0x30-byte record ARR_a8079c98[DAT_a80787fc]: hi = bits 4..7, lo = bits 0..3.
 * n = hi - 1 (int); k = n / 2, plus 1 when n is odd. bit = 1 when bit 4 of record byte k + 2 is set.
 * Returns 1 when ARR_a8079c3d[(hi - lo) * 2 + bit] differs from bits 0..6 of record byte k + 3 and lo < hi,
 * else 0 (both tests are computed with addx and combined with and).
 * Source form: bit is first assigned the masked byte and then bit = bit != 0 in a second statement (one
 * expression is folded into a shift and mask instead of the firmware's cmp/addx).
 */
extern unsigned char DAT_a80787fc;
extern unsigned char ARR_a8079c98[][0x30];
extern unsigned char ARR_a8079c3d[];

int FUN_a00da9e8(void)
{
    unsigned char *rec = ARR_a8079c98[DAT_a80787fc];
    unsigned char b = rec[0];
    unsigned char hi = b >> 4;
    unsigned char lo = b & 0xf;
    int n = hi - 1;
    unsigned char k = n / 2;
    unsigned char bit;

    if (n & 1)
        k = n / 2 + 1;
    bit = rec[k + 2] & 0x10;
    bit = bit != 0;
    return ARR_a8079c3d[(hi - lo) * 2 + bit] != (rec[k + 3] & 0x7f) && lo < hi;
}
