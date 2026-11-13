/* dp_tx_init_sink_caps  (FUN_a00866e0)
 *
 * Fill the sink capability records of the embedded DP outputs with defaults and two reads.
 * Name basis: derived - DPCD rev 1.2, rate and lane limits, AUX read interval (DPCD 0x0E) and 0x07; caller
 *   dp_tx_edp_run_hpd_actions
 *
 * Matching notes
 * --------------
 * FUN_a00866e0 (leon2s 0xa00866e0-0xa008686c, 396 bytes), flags -mcpu=v8 -Os -g.
 * dp_tx_limits_others is volatile as in its other users (every access is a separate load).
 * Source form: byte 5 is stored twice (first the raw byte, then the scaled value or 1); the bit-3 update is a
 * nested if with the clear written in both else arms.
 */
extern unsigned char dp_tx_sink_caps_records[][6];
extern volatile unsigned char dp_tx_limits_others[];
extern unsigned char dp_tx_aux_data_byte;
extern unsigned char dp_tx_edp_last_output;
extern unsigned char dp_tx_edp_first_output;
extern unsigned char dp_tx_aux_request_copy(unsigned char, unsigned int, unsigned int, unsigned int, unsigned char *);

#define CAPS_FLAGS     0 /* flag bits, see below */
#define CAPS_REV       1 /* revision byte */
#define CAPS_MAX_RATE  2 /* link rate code (6, 0xA, 0x14, 0x1E) */
#define CAPS_MAX_LANES 3 /* lane count */
#define CAPS_AUX_WAIT  5 /* training wait value */
#define CAPS_VALID     0x80
#define CAPS_BIT3      0x08 /* copy of bit 6 of the byte at address 7 */
#define CAPS_BIT4      0x10

/*
 * Give the sink capability records of the outputs a fixed starting content and re-read two bytes from the
 * sink. The record of an output (dp_tx_sink_caps_records, 6 bytes each) holds: flags, revision, highest link rate code,
 * highest lane count, a byte that dp_tx_read_sink_caps fills from the sink, and the training wait value.
 *
 * Per output: revision 0x12; rate code 0x1E and 4 lanes, or the stored limits of the outputs other than
 * output 0 (dp_tx_limits_others) when those are lower; the wait value from the byte at address 0xE of the
 * sink (its value times 4 when it is 1..4, otherwise 1; 10 when the read fails); flag bit 3 from bit 6 of the
 * byte at address 7 (clear when the read fails); flag bit 4 set; flag bits 1, 2, 5 and 6 cleared; the valid
 * bit (0x80) set.
 *   all_edp: 0 = only output 0; non-zero = the outputs dp_tx_edp_first_output..dp_tx_edp_last_output
 * Called by dp_tx_edp_run_hpd_actions (dp_tx_edp_run_hpd_actions).
 */
void dp_tx_init_sink_caps(unsigned char all_edp)
{
    unsigned char first = 0;
    unsigned char last = 0;
    unsigned char out;
    unsigned char *rec;

    if (all_edp) {
        first = dp_tx_edp_first_output;
        last = dp_tx_edp_last_output;
    }
    for (out = first; out <= last; out++) {
        rec = dp_tx_sink_caps_records[out];
        rec[CAPS_REV] = 0x12;
        /* The limits of the outputs other than 0 apply to every record, also in the output 0 case. */
        rec[CAPS_MAX_RATE] = 0x1e;
        if (dp_tx_limits_others[0] <= 0x1d)
            rec[CAPS_MAX_RATE] = dp_tx_limits_others[0];
        rec[CAPS_MAX_LANES] = 4;
        if (dp_tx_limits_others[1] <= 3)
            rec[CAPS_MAX_LANES] = dp_tx_limits_others[1];
        /* Wait value: byte at address 0xE of the sink, times 4 when it is 1..4, else 1; 10 if the read fails. */
        if (dp_tx_aux_request_copy(out, 0x90, 0xe, 0, &dp_tx_aux_data_byte) == 1) {
            rec[CAPS_AUX_WAIT] = dp_tx_aux_data_byte;
            if ((unsigned char)(dp_tx_aux_data_byte - 1) <= 3)
                rec[CAPS_AUX_WAIT] = dp_tx_aux_data_byte << 2;
            else
                rec[CAPS_AUX_WAIT] = 1;
        } else
            rec[CAPS_AUX_WAIT] = 10;
        dp_tx_sink_caps_records[out][CAPS_FLAGS] |= CAPS_BIT4;
        /* Flag bit 3 follows bit 6 of the byte at address 7 of the sink. */
        if (dp_tx_aux_request_copy(out, 0x90, 7, 0, &dp_tx_aux_data_byte) == 1) {
            if (dp_tx_aux_data_byte & 0x40)
                dp_tx_sink_caps_records[out][CAPS_FLAGS] |= CAPS_BIT3;
            else
                dp_tx_sink_caps_records[out][CAPS_FLAGS] &= ~CAPS_BIT3;
        } else
            dp_tx_sink_caps_records[out][CAPS_FLAGS] &= ~CAPS_BIT3;
        /* Bits 1, 2, 5 and 6 cleared, valid bit set. */
        dp_tx_sink_caps_records[out][CAPS_FLAGS] = (dp_tx_sink_caps_records[out][CAPS_FLAGS] & ~0x66) | CAPS_VALID;
    }
}
