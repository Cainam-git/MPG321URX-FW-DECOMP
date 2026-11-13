/* dp_tx_choose_link_config  (FUN_a0086c48)
 *
 * Choose link rate and lane count from the sink caps and the configured limits.
 *   port: output
 *   cfg: rate, lanes, ...
 * Name basis: derived - min of caps record and the stored limits; path 0 may follow the input's own link rate
 *
 * Matching notes
 * --------------
 * FUN_a0086c48 (leon2s 0xa0086c48-0xa0086df4, 428 bytes), flags -mcpu=v8 -Os -g.
 * dp_tx_limits_others and dp_tx_limits_port0 are volatile as in their other users (every access is a
 * separate load).
 * Source form: the call result r is an int set to -1 and then narrowed to the byte c; if/else chain on c & 3.
 */
extern unsigned char dp_tx_sink_caps_records[][6];
extern volatile unsigned char dp_tx_limits_others[];
extern volatile unsigned char dp_tx_limits_port0[];
extern unsigned char dp_tx_get_link_state(void);
extern unsigned char input_get_port_source_code(unsigned char);
extern unsigned char dp_is_link_trained(unsigned char port);
extern unsigned int dp_reg_read8(unsigned int param_1, unsigned short param_2);

#define CAPS_MAX_RATE  2
#define CAPS_MAX_LANES 3
#define INPUT_CODE_DP_0 0x71 /* source codes of the two DP receivers */
#define INPUT_CODE_DP_1 0x81
#define RECV_REG_LINK   0x80 /* receiver register: bits 0-1 rate, bits 2-4 lane count */

/*
 * Pick the link rate code and lane count that dp_tx_train_links starts training with.
 *   port: output
 *   cfg:  result, 4 bytes: [0] rate code (6, 10, 0x14 or 0x1E), [1] lane count,
 *         [2] lowest rate code the caller may fall back to (6), [3] lowest lane count (1)
 *
 * Start from the highest rate and lane count in the sink caps record of the port, cut down to the stored
 * limits. Output 0 has its own limit pair (dp_tx_limits_port0) that is put back to 0x1E / 4 once it has
 * been used; the other outputs share one pair (dp_tx_limits_others).
 * Output 0 only, while the output link state is non-zero: when the source code of port 0 is 0x71 or 0x81 and
 * dp_is_link_trained of the matching receiver returns 1, the rate and lane count are taken from register 0x80
 * of that receiver instead, and the rate is also made the lowest rate (no fall-back).
 */
void dp_tx_choose_link_config(unsigned char port, unsigned char *cfg)
{
    unsigned char source_code;
    int recv_value;
    unsigned char recv_cfg;

    cfg[1] = dp_tx_sink_caps_records[port][CAPS_MAX_LANES];
    cfg[0] = dp_tx_sink_caps_records[port][CAPS_MAX_RATE];
    cfg[3] = 1;
    cfg[2] = 6;
    if (port == 0) {
        if (cfg[1] > dp_tx_limits_port0[1])
            cfg[1] = dp_tx_limits_port0[1];
        if (cfg[0] > dp_tx_limits_port0[0])
            cfg[0] = dp_tx_limits_port0[0];
        dp_tx_limits_port0[0] = 0x1e;
        dp_tx_limits_port0[1] = 4;
        if (!dp_tx_get_link_state())
            return;
        source_code = input_get_port_source_code(0);
        recv_value = -1;
        if (source_code == INPUT_CODE_DP_0) {
            if (dp_is_link_trained(0) == 1)
                recv_value = dp_reg_read8(0, RECV_REG_LINK);
        } else if (source_code == INPUT_CODE_DP_1) {
            if (dp_is_link_trained(1) == 1)
                recv_value = dp_reg_read8(1, RECV_REG_LINK);
        }
        recv_cfg = recv_value;
        if (recv_cfg == 0xff)
            return;
        /* Register value to rate code: 0 -> 6, 1 -> 10, 2 -> 0x14, 3 -> 0x1E. */
        if ((recv_cfg & 3) == 0)
            cfg[0] = 6;
        else if ((recv_cfg & 3) == 1)
            cfg[0] = 10;
        else if ((recv_cfg & 3) == 2)
            cfg[0] = 0x14;
        else
            cfg[0] = 0x1e;
        cfg[2] = cfg[0];
        cfg[1] = (recv_cfg & 0x1c) >> 2;
    } else {
        if (cfg[1] > dp_tx_limits_others[1])
            cfg[1] = dp_tx_limits_others[1];
        if (cfg[0] > dp_tx_limits_others[0])
            cfg[0] = dp_tx_limits_others[0];
    }
}
