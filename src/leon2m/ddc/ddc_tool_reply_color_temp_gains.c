/* ddc_tool_reply_color_temp_gains  (FUN_a00d0fe8)
 *
 * Fill the factory tool reply with the gains of the current colour temperature.
 *   p: reply
 * Note: Uncalled copy of the 0x92 arm of ddc_tool_build_reply; three bytes of the table 0xA802E1F0.
 * Name basis: derived - entry chosen by settings byte +0x11 (colour temperature)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00d0fe8 (0xa00d0fe8-0xa00d10b4, 204 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Source form: an if/else chain testing 2, 1, 0; the checksum is a static helper inlined here (the compiler folds
 * p[1], so the loop bound is the constant 11).
 */
extern unsigned char user_settings_color_temperature;
extern unsigned char part_record[];

#define DDC_CHECKSUM_SEED  0x50                 /* first value of the reply XOR checksum */
#define DDC_LENGTH_BYTE(n) ((n) + 0x80)         /* reply byte 1: 0x80 + the number of bytes behind it */
#define DDC_LENGTH_MASK    0x7f
#define TOOL_RESULT_DONE   0xe0                 /* byte 7 of a reply: carried out */

/* Colour temperature values (settings +0x11) and the part record rows of their three colour bytes. */
#define COLOR_TEMP_COOL    0
#define COLOR_TEMP_NORMAL  1
#define COLOR_TEMP_WARM    2
#define PART_WARM50        6
#define PART_NORMAL65      9
#define PART_COOL93        0x12

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
 * Put the three part record colour bytes of the current colour temperature (Warm, Normal or Cool) in reply bytes
 * 8..10, set byte 7 to TOOL_RESULT_DONE and store the checksum of bytes 0..10 in byte 11.
 *
 *   p  the reply; bytes 0 and 2..6 are already written by the caller
 *
 * Any other colour temperature value leaves bytes 8..10 as they were. Nothing calls this copy;
 * ddc_tool_build_reply has the same body for its answer kind 0x92.
 */
void ddc_tool_reply_color_temp_gains(unsigned char *p)
{
    p[1] = DDC_LENGTH_BYTE(9);
    p[7] = TOOL_RESULT_DONE;
    if (user_settings_color_temperature == COLOR_TEMP_WARM) {
        p[8] = part_record[PART_WARM50];
        p[9] = part_record[PART_WARM50 + 1];
        p[10] = part_record[PART_WARM50 + 2];
    }
    else if (user_settings_color_temperature == COLOR_TEMP_NORMAL) {
        p[8] = part_record[PART_NORMAL65];
        p[9] = part_record[PART_NORMAL65 + 1];
        p[10] = part_record[PART_NORMAL65 + 2];
    }
    else if (user_settings_color_temperature == COLOR_TEMP_COOL) {
        p[8] = part_record[PART_COOL93];
        p[9] = part_record[PART_COOL93 + 1];
        p[10] = part_record[PART_COOL93 + 2];
    }
    p[11] = tool_checksum(p, DDC_CHECKSUM_SEED);
}
