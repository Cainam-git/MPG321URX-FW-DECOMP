/* dp_tx_check_training_lost  (FUN_a0088c5c)
 *
 * Check the trained outputs and return 1 at the first output that lost its link, else 0.
 * Returns: 1 when a link was lost
 * Name basis: proven - prints 'DPTX(%d) Training Lost'; dp_tx_read_link_status + dp_tx_check_channel_eq
 *
 * Matching notes
 * --------------
 * FUN_a0088c5c (leon2s 0xa0088c5c-0xa0088ea0, 580 bytes), flags -mcpu=v8 -Os -g.
 * Source form: bit 7 of status[0] is read through a 1-bit bit-field; the rate_index checks are one '||'
 * condition of four '(rate_index == k && dp_tx_reg_read8(out, 2) != X)' terms; the clear-bit path is
 * 'if (out != 0) continue; fail = 1;'. The output range is set up as in dp_tx_train_clock_recovery and
 * dp_tx_train_channel_eq: lo = 0 at its declaration and 'if (!all_edp) { hi = 0; lo = 0; } else { ... }' (the
 * firmware's 'mov %l2,%o0' copy of fail's zero register at 0xa0088c70 and its block order).
 */
extern unsigned char dp_tx_edp_last_output;
extern unsigned char dp_tx_edp_first_output;
extern unsigned char dp_tx_is_connected(unsigned char);
extern unsigned char dp_tx_reg_read8(unsigned char, unsigned short);
extern void dp_tx_read_link_status(unsigned char, unsigned char *);
extern unsigned char dp_tx_get_mode_flag(void);
extern void dp_mst_set_option_byte(unsigned char);
extern unsigned char dp_tx_check_channel_eq(unsigned char, unsigned char *);
extern int dbg_printf(const char *, ...);
extern unsigned char dp_tx_get_link_state(void);
extern unsigned char input_get_port_source_code(unsigned char);
extern unsigned char dp_is_link_trained(unsigned char);
extern unsigned char dp_reg_read8(unsigned char, unsigned short);

struct status_head { unsigned char valid : 1; unsigned char rest : 7; };

/*
 * Check that the links that were trained are still up; stop at the first output that lost its link.
 *   all_edp: 0 = output 0 only; non-zero = dp_tx_edp_first_output..dp_tx_edp_last_output
 *   status:  16-byte buffer for the link status record of dp_tx_read_link_status (reused for every output)
 *   mask:    bit n set = output n is trained; the bit of an output whose status cannot be read is cleared
 * Returns 1 when an output lost its link, 0 when all outputs in the range are fine.
 *
 * Outputs without a connected sink are skipped. For each other output the lane count is read back from
 * transmitter register 3 and the link status from the sink. The link counts as lost when
 *  - the status cannot be read (output 0 only; for the other outputs the mask bit is cleared and the check goes on),
 *  - dp_tx_check_channel_eq does not return 5 for that lane count (this also prints "DPTX(%d) Training Lost"),
 *  - bit 0 of status byte 6 is clear,
 *  - output 0, with a non-zero output link state, has source code 0x71 (receiver 0, register read only when
 *    dp_is_link_trained(0) returns 1) or 0x81 (receiver 1), and the rate code in transmitter register 2
 *    differs from the rate in bits 0-1 of that receiver's register 0x80 (0 -> 6, 1 -> 10, 2 -> 0x14,
 *    3 -> 0x1E).
 * Output 0 also hands status byte 3 to dp_mst_set_option_byte when dp_tx_get_mode_flag is non-zero.
 */
unsigned char dp_tx_check_training_lost(unsigned char all_edp, unsigned char *status, unsigned char *mask)
{
    unsigned char fail = 0;
    unsigned char lo = 0;
    unsigned char hi;
    unsigned char out;
    unsigned char lanes;
    unsigned char source_code;
    unsigned char recv_cfg;
    unsigned int rate_index;

    if (!all_edp) {
        hi = 0;
        lo = 0;
    } else {
        lo = dp_tx_edp_first_output;
        hi = dp_tx_edp_last_output;
    }
    for (out = lo; out <= hi; out++) {
        if (dp_tx_is_connected(out) == 0)
            continue;
        lanes = dp_tx_reg_read8(out, 3) & 0x1f;
        dp_tx_read_link_status(out, status);
        if (!((struct status_head *)status)->valid) {
            *mask &= ~(1 << out);
            if (out != 0)
                continue;
            fail = 1;
        } else {
            if (dp_tx_get_mode_flag() && out == 0)
                dp_mst_set_option_byte(status[3]);
            if (dp_tx_check_channel_eq(lanes & 0x1f, status) != 5) {
                dbg_printf("DPTX(%d) Training Lost\r\n", out);
                fail = 1;
            }
            if (!(status[6] & 1))
                fail = 1;
            if (dp_tx_get_link_state() && out == 0) {
                source_code = input_get_port_source_code(out);
                recv_cfg = 0xff;
                if (source_code == 0x71) {
                    if (dp_is_link_trained(out) == 1)
                        recv_cfg = dp_reg_read8(0, 0x80);
                } else if (source_code == 0x81)
                    recv_cfg = dp_reg_read8(1, 0x80);
                if (recv_cfg != 0xff) {
                    rate_index = recv_cfg & 3;
                    if ((rate_index == 0 && dp_tx_reg_read8(out, 2) != 6) ||
                        (rate_index == 1 && dp_tx_reg_read8(out, 2) != 10) ||
                        (rate_index == 2 && dp_tx_reg_read8(out, 2) != 0x14) ||
                        (rate_index == 3 && dp_tx_reg_read8(out, 2) != 0x1e))
                        fail = 1;
                }
            }
        }
        if (fail)
            return 1;
    }
    return 0;
}
