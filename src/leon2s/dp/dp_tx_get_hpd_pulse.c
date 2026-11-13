/* dp_tx_get_hpd_pulse  (FUN_a008899c)
 *
 * Return 1 or 2 from the first two hot-plug event bits of an output.
 *   port: output
 * Name basis: descriptive - bits 0/1 of dp_tx_get_hpd_event_bits; callers HPD action routines
 *
 * Matching notes
 * --------------
 * FUN_a008899c (leon2s 0xa008899c-0xa0088a80, 228 bytes), flags -mcpu=v8 -Os -g.
 * Source form: an if/else-if chain with one arm per output value, tested in the order 0, 2, 3, 4, 1, each
 * arm with its own two calls; the result starts at 0 and the function returns result & 3 (GCC merges the
 * second calls into one block).
 */
extern unsigned char dp_tx_get_hpd_event_bits(int output);

/*
 * Read the event bits of a link output (output 0..4) with dp_tx_get_hpd_event_bits. Returns 1 when bit 0 is
 * set, else 2 when bit 1 is set of a second read, else 0. Any other output returns 0 without a read.
 *   port: link output
 * Called by the hot-plug action routines.
 */
unsigned char dp_tx_get_hpd_pulse(unsigned char port)
{
    unsigned char result = 0;
    if (port == 0) {
        if (dp_tx_get_hpd_event_bits(0) & 1)
            result = 1;
        else if (dp_tx_get_hpd_event_bits(0) & 2)
            result = 2;
    } else if (port == 2) {
        if (dp_tx_get_hpd_event_bits(2) & 1)
            result = 1;
        else if (dp_tx_get_hpd_event_bits(2) & 2)
            result = 2;
    } else if (port == 3) {
        if (dp_tx_get_hpd_event_bits(3) & 1)
            result = 1;
        else if (dp_tx_get_hpd_event_bits(3) & 2)
            result = 2;
    } else if (port == 4) {
        if (dp_tx_get_hpd_event_bits(4) & 1)
            result = 1;
        else if (dp_tx_get_hpd_event_bits(4) & 2)
            result = 2;
    } else if (port == 1) {
        if (dp_tx_get_hpd_event_bits(1) & 1)
            result = 1;
        else if (dp_tx_get_hpd_event_bits(1) & 2)
            result = 2;
    }
    return result & 3;
}
