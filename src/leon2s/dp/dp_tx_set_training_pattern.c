/* dp_tx_set_training_pattern  (FUN_a00864d4)
 *
 * Select training pattern 1..4 (scrambling off) in the sink.
 *   port: output
 *   pattern: pattern 0..3
 * Returns: 1 on success
 * Name basis: proven - writes 0x21/0x22/0x23/0x27 to DPCD 0x102 TRAINING_PATTERN_SET
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00864d4 @ 0xa00864d4 (-mcpu=v8 -Os -g)
 * Source form: the pattern code is first copied into a byte local.
 */
extern unsigned char dp_tx_aux_request(unsigned int, unsigned int, unsigned int, char, unsigned int);

/*
 * Write the training pattern byte to DPCD 0x102 (TRAINING_PATTERN_SET). Pattern 0, 1, 2, 3 give 0x21, 0x22,
 * 0x23, 0x27; any other value gives 0. Returns 1 when the request succeeded.
 *   port:    link output
 *   pattern: pattern 0..3
 */
int dp_tx_set_training_pattern(unsigned int port, unsigned int pattern)
{
    unsigned char pattern_byte;
    unsigned char code;
    
    code = (unsigned char)pattern;
    if (code == 0)
        pattern_byte = 0x21;
    else if (code == 1)
        pattern_byte = 0x22;
    else if (code == 2)
        pattern_byte = 0x23;
    else if (code == 3)
        pattern_byte = 0x27;
    else
        pattern_byte = 0;
    
    return dp_tx_aux_request((unsigned char)port, 0x80, 0x102, 0, (unsigned int)&pattern_byte) != 0;
}
