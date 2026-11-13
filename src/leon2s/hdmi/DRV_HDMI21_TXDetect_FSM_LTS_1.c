/* DRV_HDMI21_TXDetect_FSM_LTS_1  (FUN_a00a3810)
 *
 * Run LTS:1 of the HDMI TX FRL training: read the sink's SCDC and pick the FRL rate.
 *   port: HDMI TX port 0/1
 * Returns: always 0
 * Name basis: proven - state name printed ('[HDMI_TX_FRL_Training]: Port%d : DRV_HDMI21_TXDetect_FSM_LTS_1');
 *   state 1; FRL rate from hdmi_tx_parse_hf_vsdb, hdmi_tx_print_frl_rate
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00a3810 @ 0xa00a3810-0xa00a3a10, flags -mcpu=v8 -Os -g.
 * Source forms the exact build depends on:
 *  - the first block indexes the word arrays through `index` = port (as in DRV_HDMI21_TXDetect_FSM_LTS_2), the
 *    later accesses use the byte parameter;
 *  - the condition names hdmi_tx_frl_sink_check_flag == 0 twice, first and last;
 *  - the hdmi_tx_is_frl_mode result is tested twice: the first if/else sets the state to LTS_L through `port`
 *    after the condition (fw 0xa00a39c0) or through `index` (fw 0xa00a39d0); the second if/else calls
 *    hdmi_tx_clear_frl_mode(index) (fw 0xa00a39c4) and hdmi_tx_clear_active(index), or only
 *    hdmi_tx_clear_active(index) (the two calls share one call site at fw 0xa00a39d4).
 */

/* The port's 28-byte TX channel record (hdmi_tx_output_records): the fields used here. */
struct hdmi_tx_channel_record {
    unsigned char _0[0x12];
    unsigned char byte_0x12;            /* set to the FRL rate here */
    unsigned char _13;
    unsigned int word5;                 /* +0x14 */
    unsigned char _18[4];
};
#define CHANNEL_WORD5_BIT11    0x800
#define CHANNEL_WORD5_BIT12    0x1000

/* States of the FRL training, = index into hdmi_tx_frl_training_state_handlers. */
enum {
    TX_FRL_STATE_LTS_2 = 2,
    TX_FRL_STATE_LTS_L = 6
};

#define SCDC_REG_01            0x01     /* sink register read here; its value is kept in hdmi_tx_lts1_results */
#define FRL_RATE_MAX           6        /* highest rate taken from hdmi_tx_sink_max_frl */
#define FRL_RATE_DEFAULT       5        /* used for a sink rate of 0 while hdmi_tx_frl_sink_check_flag is 0 */

extern struct hdmi_tx_channel_record hdmi_tx_output_records[];
extern unsigned int hdmi_tx_frl_states[];         /* training state of each port (TX_FRL_STATE_*) */
extern unsigned int hdmi_tx_frl_printed_states[];         /* state printed last for each port */
extern unsigned int hdmi_tx_frl_rates[];
extern unsigned char hdmi_tx_frl_sink_check_flag;          /* 0: take the FRL rate without the sink checks (see below) */
extern unsigned char hdmi_tx_lts1_results[];
extern unsigned char hdmi_tx_sink_max_frl[];
extern unsigned char hdmi_tx_sink_scdc_present[];
extern const char DAT_a006bb08[];           /* '[HDMI_TX_FRL_Training]: Port%d : DRV_HDMI21_TXDetect_FSM_LTS_1' */
extern int dbg_printf(const char *, ...);
extern unsigned char hdmi_tx_scdc_read(unsigned int, unsigned int);
extern unsigned int hdmi_tx_is_frl_mode(unsigned int);
extern void hdmi_tx_set_frl_rate(unsigned int, unsigned char);
extern void hdmi_tx_print_frl_rate(unsigned char);
extern void hdmi_tx_clear_frl_mode(unsigned int);
extern void hdmi_tx_clear_active(unsigned int);

/*
 * State LTS_1 of the FRL link training of HDMI output `port` (0 or 1): choose the FRL rate. Run by
 * hdmi_tx_run_frl_training through hdmi_tx_frl_training_state_handlers while the port's state is 1.
 *
 * The state name is printed when the port entered this state since the last print, and the sink's SCDC
 * register 1 is read into hdmi_tx_lts1_results. Then:
 *   - The channel uses FRL, and either hdmi_tx_frl_sink_check_flag is 0 or the sink passes all three checks (a non-zero
 *     hdmi_tx_sink_max_frl and hdmi_tx_sink_scdc_present from its EDID (hdmi_tx_parse_hf_vsdb), and a non-zero
 *     SCDC register 1): the sink's maximum rate becomes the port's FRL rate when it is at most 6 (otherwise the
 *     rate stays as it was); with hdmi_tx_frl_sink_check_flag 0 a sink rate of 0 gives rate 5. The rate is handed to
 *     hdmi_tx_set_frl_rate, printed, and the state goes to LTS_2.
 *   - Otherwise the state goes to LTS_L, a channel in FRL mode is switched back to TMDS, the channel is marked
 *     not running, and bit 11 of channel word 5 is cleared and bit 12 set (as LTS_2 does when it moves on).
 *
 * hdmi_tx_frl_sink_check_flag is not written by any routine of the program that names it.
 * Returns 0 in every case, so the next state runs on the next tick.
 */
int DRV_HDMI21_TXDetect_FSM_LTS_1(unsigned char port)
{
    unsigned char sink_rate;
    unsigned int index;
    unsigned char frl_mode;

    index = port;
    if (hdmi_tx_frl_states[index] != hdmi_tx_frl_printed_states[index]) {
        dbg_printf(DAT_a006bb08, port);
        hdmi_tx_frl_printed_states[index] = hdmi_tx_frl_states[index];
    }
    hdmi_tx_lts1_results[port] = hdmi_tx_scdc_read(port, SCDC_REG_01);
    frl_mode = hdmi_tx_is_frl_mode(port);
    if (frl_mode == 1) {
        if (hdmi_tx_frl_sink_check_flag == 0 || (hdmi_tx_sink_max_frl[port] != 0 && hdmi_tx_sink_scdc_present[port] == 1 && hdmi_tx_lts1_results[port] != 0)
            || hdmi_tx_frl_sink_check_flag == 0) {
            sink_rate = hdmi_tx_sink_max_frl[port];
            if (sink_rate <= FRL_RATE_MAX) {
                hdmi_tx_frl_rates[port] = sink_rate;
                hdmi_tx_output_records[port].byte_0x12 = sink_rate;
            }
            if (hdmi_tx_frl_sink_check_flag == 0)
                if (sink_rate == 0) {
                    hdmi_tx_frl_rates[port] = FRL_RATE_DEFAULT;
                    hdmi_tx_output_records[port].byte_0x12 = FRL_RATE_DEFAULT;
                }
            hdmi_tx_set_frl_rate(port, hdmi_tx_frl_rates[port]);
            hdmi_tx_print_frl_rate(hdmi_tx_frl_rates[port]);
            hdmi_tx_frl_states[port] = TX_FRL_STATE_LTS_2;
            return 0;
        }
        hdmi_tx_frl_states[port] = TX_FRL_STATE_LTS_L;
    } else
        hdmi_tx_frl_states[index] = TX_FRL_STATE_LTS_L;
    if (frl_mode == 1) {
        hdmi_tx_clear_frl_mode(index);
        hdmi_tx_clear_active(index);
    } else
        hdmi_tx_clear_active(index);
    hdmi_tx_output_records[index].word5 = (hdmi_tx_output_records[index].word5 & ~CHANNEL_WORD5_BIT11) | CHANNEL_WORD5_BIT12;
    return 0;
}
