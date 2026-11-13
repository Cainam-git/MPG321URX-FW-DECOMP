/* ddc_tool_reply_key_test  (FUN_a00d10b4)
 *
 * Fill the factory tool reply with the front key test result.
 *   p: reply
 * Note: Uncalled copy of the 0x69 arm; bit 0 and bits 1..5 of factory record byte +0x10.
 * Name basis: derived - glossary: factory record +0x10 = key-test bits
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00d10b4 (0xa00d10b4-0xa00d1110, 92 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Source form: the checksum is a static helper inlined here.
 */
extern unsigned char factory_record[];

#define DDC_CHECKSUM_SEED     0x50              /* first value of the reply XOR checksum */
#define DDC_LENGTH_MASK       0x7f
#define FACTORY_KEY_TEST_BITS 0x10              /* factory record +0x10: one bit per front key passed */

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
 * Put the key test bits of the factory record in the reply: bit 0 in byte 6, bits 1..5 (still in place, mask
 * 0x3E) in byte 7, and the checksum in byte 8. The length byte 1 is the caller's.
 *
 *   p  the reply
 *
 * Nothing calls this copy; ddc_tool_build_reply has the same body for its answer kind 0x69.
 */
void ddc_tool_reply_key_test(unsigned char *p)
{
    p[6] = factory_record[FACTORY_KEY_TEST_BITS] & 1;
    p[7] = factory_record[FACTORY_KEY_TEST_BITS] & 0x3e;
    p[8] = tool_checksum(p, DDC_CHECKSUM_SEED);
}
