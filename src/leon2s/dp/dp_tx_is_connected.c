/* dp_tx_is_connected  (FUN_a0088af0)
 *
 * Return whether the hot-plug line of an output is high.
 *   output
 * Returns: 1 when connected
 * Name basis: derived - inverse of dp_tx_hpd_is_low for outputs 0..4
 *
 * Matching notes
 * --------------
 * leon2s FUN_a0088af0 @ 0xa0088af0 (-mcpu=v8 -Os -g)
 * Source form: an if/else-if chain testing the values in the order 0, 2, 3, 4, 1; the result starts at 0 and
 * is set to 1 only on success.
 */
extern int dp_tx_hpd_is_low(int output);

/*
 * Return 1 when dp_tx_hpd_is_low returns 0 for the link output (output 0..4), else 0. Any other output
 * returns 0 without a call.
 *   output: link output
 */
int dp_tx_is_connected(unsigned char output)
{
    unsigned char result;
    
    output = output & 0xff;
    result = 0;
    if (output == 0) {
        if (dp_tx_hpd_is_low(0) == 0) {
            result = 1;
        }
    } else if (output == 2) {
        if (dp_tx_hpd_is_low(2) == 0) {
            result = 1;
        }
    } else if (output == 3) {
        if (dp_tx_hpd_is_low(3) == 0) {
            result = 1;
        }
    } else if (output == 4) {
        if (dp_tx_hpd_is_low(4) == 0) {
            result = 1;
        }
    } else if (output == 1) {
        if (dp_tx_hpd_is_low(1) == 0) {
            result = 1;
        }
    }
    return result & 1;
}
