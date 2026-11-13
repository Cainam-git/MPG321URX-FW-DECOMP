/* dp_tx_hpd_event_bit2  (FUN_a0088a80)
 *
 * Return whether hot-plug event bit 2 of an output is set.
 *   output
 * Name basis: descriptive - bit 2 of dp_tx_get_hpd_event_bits; callers HPD action routines
 *
 * Matching notes
 * --------------
 * FUN_a0088a80 (leon2s 0xa0088a80-0xa0088af0, 112 bytes), flags -mcpu=v8 -Os -g.
 * Source form: same shape as dp_tx_is_connected: an if/else-if chain testing the values in the order 0, 2, 3,
 * 4, 1; the result starts at 0 and is set to 1 only on success.
 */
extern unsigned char dp_tx_get_hpd_event_bits(int output);

/*
 * Return 1 when bit 2 of the event bits of a link output (output 0..4, read with dp_tx_get_hpd_event_bits)
 * is set, else 0. Any other output returns 0 without a read.
 *   output: link output
 * Called by the hot-plug action routines.
 */
int dp_tx_hpd_event_bit2(unsigned char output)
{
    unsigned char result;
    
    output = output & 0xff;
    result = 0;
    if (output == 0) {
        if (dp_tx_get_hpd_event_bits(0) & 4) {
            result = 1;
        }
    } else if (output == 2) {
        if (dp_tx_get_hpd_event_bits(2) & 4) {
            result = 1;
        }
    } else if (output == 3) {
        if (dp_tx_get_hpd_event_bits(3) & 4) {
            result = 1;
        }
    } else if (output == 4) {
        if (dp_tx_get_hpd_event_bits(4) & 4) {
            result = 1;
        }
    } else if (output == 1) {
        if (dp_tx_get_hpd_event_bits(1) & 4) {
            result = 1;
        }
    }
    return result & 1;
}
