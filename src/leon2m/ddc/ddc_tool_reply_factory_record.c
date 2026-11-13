/* ddc_tool_reply_factory_record  (FUN_a00d1110)
 *
 * Fill the factory tool reply with 13 bytes of the factory record.
 *   p: reply
 * Note: Uncalled copy of the 0x6B arm.
 * Name basis: derived - bytes 3..15 of 0xA802D274
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00d1110 (0xa00d1110-0xa00d1184, 116 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Source form: the checksum is a static helper inlined here; an int loop counter for the copy.
 */
extern unsigned char factory_record[];

#define DDC_CHECKSUM_SEED   0x50                /* first value of the reply XOR checksum */
#define DDC_LENGTH_BYTE(n)  ((n) + 0x80)        /* reply byte 1: 0x80 + the number of bytes behind it */
#define DDC_LENGTH_MASK     0x7f
#define TOOL_RESULT_DONE    0xe0                /* byte 7 of a reply: carried out */
#define FACTORY_SERIAL      3                   /* factory record +3: the serial characters */
#define SERIAL_ANSWER_LENGTH 13

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
 * Answer with the serial number: set the length byte to DDC_LENGTH_BYTE(19) and byte 7 to TOOL_RESULT_DONE, copy
 * 13 bytes of the factory record from +3 to reply bytes 8..20 and store the checksum of bytes 0..20 in byte 21.
 *
 *   p  the reply; bytes 0 and 2..6 are already written by the caller
 *
 * Nothing calls this copy; ddc_tool_build_reply has the same body for its answer kind 0x6B.
 */
void ddc_tool_reply_factory_record(unsigned char *p)
{
    int i;

    p[1] = DDC_LENGTH_BYTE(19);
    p[7] = TOOL_RESULT_DONE;
    for (i = 0; i < SERIAL_ANSWER_LENGTH; i++)
        p[8 + i] = factory_record[FACTORY_SERIAL + i];
    p[0x15] = tool_checksum(p, DDC_CHECKSUM_SEED);
}
