/* sys_dsc_dec_is_dp_source  (FUN_a00a61d4)
 *
 * Return whether the DP input selected for the decoder carries a stream.
 *   input_code: input code 0x51/0x61/0x71/0x81
 * Returns: 1 when present
 * Name basis: derived - input code 0x71 / 0x81 -> dp_is_stream_present(0 / 1)
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00a61d4 @ 0xa00a61d4 (-mcpu=v8 -Os -g)
 * The firmware loads the argument 0 with clr %o0 before the first comparison and the argument 1 with mov 1,%o0
 * in the branch delay slot; the bne of the second comparison branches straight to the return.
 */
extern int dp_is_stream_present();

/* Return 1 when the DisplayPort input named by the input code reports a stream (dp_is_stream_present): input 0
 * for code 0x71, input 1 for code 0x81. Any other code gives 0.
 *   input_code: 0x71 or 0x81 for the DisplayPort inputs
 */
unsigned char sys_dsc_dec_is_dp_source(unsigned char input_code)
{
    unsigned char result;
    
    result = 0;
    input_code = input_code & 0xff;
    if (input_code == 0x71) {
        if ((dp_is_stream_present(0) & 0xff) == 1) {
            result = 1;
        }
    } else if (input_code == 0x81) {
        if ((dp_is_stream_present(1) & 0xff) == 1) {
            result = 1;
        }
    }
    return result;
}
