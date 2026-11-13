/* ddc_tool_fill_reply_0x97  (FUN_a00d0fa0)
 *
 * Fill the factory tool reply to command 0x97.
 *   p: reply
 * Note: Uncalled copy of the 0x97 arm of ddc_tool_build_reply; fixed bytes 2, 1 and the checksum.
 * Name basis: descriptive - same body as the cmd 0x97 arm
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00d0fa0 (0xa00d0fa0-0xa00d0fe8, 72 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Source form: the checksum is a static helper inlined here; the compiler folds p[1] from the store, so the loop
 * bound is the constant 10 (cmp 10 / bcs). The store order is p[1], p[8], p[9], p[7], p[10].
 */

#define DDC_CHECKSUM_SEED  0x50                 /* first value of the reply XOR checksum */
#define DDC_LENGTH_BYTE(n) ((n) + 0x80)         /* reply byte 1: 0x80 + the number of bytes behind it */
#define DDC_LENGTH_MASK    0x7f

/* XOR of the seed and reply bytes 0 .. (byte 1 & 0x7F) + 1 (same as ddc_tool_calc_checksum). */
static unsigned char tool_checksum(const unsigned char *p, unsigned char x)
{
    unsigned int n = (p[1] & DDC_LENGTH_MASK) + 2;
    unsigned char i;

    for (i = 0; i < n; i++)
        x ^= p[i];
    return x;
}

/*
 * Set the length byte to DDC_LENGTH_BYTE(8), bytes 7..9 to 0, 2, 1, and store the checksum of bytes 0..9 in byte 10.
 *
 *   p  the reply; bytes 0 and 2..6 are already written by the caller
 *
 * Nothing calls this copy; ddc_tool_build_reply has the same body for its answer kind 0x97.
 */
void ddc_tool_fill_reply_0x97(unsigned char *p)
{
    p[1] = DDC_LENGTH_BYTE(8);
    p[8] = 2;
    p[9] = 1;
    p[7] = 0;
    p[10] = tool_checksum(p, DDC_CHECKSUM_SEED);
}
