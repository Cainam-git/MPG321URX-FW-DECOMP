/* dp_tx_check_caps_byte1  (FUN_a0087074)
 *
 * Compare byte 1 of a DP output's sink caps record.
 *   output
 * Name basis: descriptive - byte +1 of the 6-byte caps record; callers link training
 *
 * Matching notes
 * --------------
 * leon2s FUN_a0087074 @ 0xa0087074 (-mcpu=v8 -Os -g)
 * Source form: the record offset is (port & 0xff) * 6 + 1, the byte compared with 0x14 by xor (the
 * 'ldub [%g1 + 1]' of the build).
 */
extern unsigned char dp_tx_sink_caps_records[];    /* 6-byte caps record per output */

/*
 * Return 1 when byte 1 of the output's 6-byte caps record equals 0x14, else 0. The link training routine
 * tests it for output 0.
 *   output: link output
 */
unsigned char dp_tx_check_caps_byte1(unsigned int output)
{
    return (dp_tx_sink_caps_records[(output & 0xff) * 6 + 1] ^ 0x14) == 0;
}
