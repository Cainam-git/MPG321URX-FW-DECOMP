/* dp_get_port_record_word_fc  (FUN_a00b0438)
 *
 * Return the word at +0xFC of a DisplayPort input's record.
 * Returns: word
 * Name basis: descriptive - 300-byte records at 0xA807DC18
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00b0438 @ 0xa00b0438 (-mcpu=v8 -Os -g)
 * Source form: the table is an array of words, so the record size is written as 75 words and the offset as word
 * 0x3f (0x3f * 4 = 0xFC).
 */

#define DP_INPUT_RECORD_WORDS 75        /* 300 bytes per port record, counted in words */
#define RECORD_WORD_0xFC      0x3f      /* word index of byte offset 0xFC */

extern unsigned int dp_input_records[];

/*
 * Return the word at byte offset 0xFC of the DP input record of a port. CONV2HDMITX_UpdateInterface multiplies
 * it by the colour depth byte (dp_get_port_record_byte_f6) and shifts the product right by 3 to get the
 * channel's pixel clock.
 *   port: DP receiver (0 or 1)
 */
unsigned int dp_get_port_record_word_fc(unsigned int port)
{
    return dp_input_records[(port & 0xff) * DP_INPUT_RECORD_WORDS + RECORD_WORD_0xFC];
}
