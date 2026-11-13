/* DRV_HDMI21_TXDetect_FSM_LTS_4  (FUN_a00a4238)
 *
 * Run LTS:4 of the HDMI TX FRL training: fall back to a lower FRL rate or give up.
 *   port: HDMI TX port 0/1
 * Returns: 0, so the next state runs on the next tick
 * Name basis: proven - state name printed ('[HDMI_TX_FRL_Training]: Port%d : DRV_HDMI21_TXDetect_FSM_LTS_4');
 *   state 4; 'No lower FRL_RATE could be used', 'SCDC_Write'
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00a4238 @ 0xa00a4238-0xa00a4370 (312 bytes), flags -mcpu=v8 -Os -g (section default).
 * Source forms the exact build depends on:
 *  - the rate is taken as (word & 0xff) into an unsigned int before the zero test, and the zero test reads the
 *    word again;
 *  - each arm has its own value variable, its own SCDC write and its own print (the compiler shares only the
 *    print call);
 *  - hdmi_tx_scdc_write is declared (unsigned int, char, unsigned char).
 */

/* States of the FRL training, = index into hdmi_tx_frl_training_state_handlers. */
enum {
    TX_FRL_STATE_LTS_3 = 3,
    TX_FRL_STATE_LTS_L = 6
};

#define SCDC_REG_RATE_FFE  0x31         /* register of the sink; LTS:2 writes FFE levels << 4 | FRL rate */

extern unsigned int hdmi_tx_frl_states[];     /* training state of each port (TX_FRL_STATE_*) */
extern unsigned int hdmi_tx_frl_printed_states[];     /* state printed last for each port */
extern unsigned int hdmi_tx_frl_rates[];
extern unsigned char hdmi_tx_frl_step_bytes[];
extern unsigned char hdmi_tx_ffe_levels[];      /* 'u8HDMI21_TxFFE_Index' */
extern int dbg_printf(const char *, ...);
extern int dbg_print_string(const char *);
extern void hdmi_tx_set_frl_rate_update(unsigned int);
extern void hdmi_tx_set_frl_rate(unsigned int, unsigned char);
extern void hdmi_tx_clear_active(unsigned int);
extern void hdmi_tx_clear_frl_mode(unsigned int);
extern void hdmi_tx_set_status_bit31(unsigned int);
extern void hdmi_tx_scdc_write(unsigned int, char, unsigned char);

/*
 * State LTS_4 of the FRL link training of HDMI output `port` (0 or 1). Run by hdmi_tx_run_frl_training
 * through hdmi_tx_frl_training_state_handlers; LTS_3 enters it when the sink requests 0xF on all lanes.
 *
 * Prints the state name when the port entered this state since the last print, and sets bit 13 of word 5 of
 * the port's TX channel record (frl_rate_update). Then one FRL rate down:
 *   - rate above 0: lower it by one, store it in the channel record and mark the channel not running;
 *   - rate 0 now (at once or after lowering): no lower rate is left. The channel goes back from FRL to TMDS,
 *     is marked not running, bit 31 of record word 1 is set and the state becomes LTS_L;
 *   - otherwise the state goes back to LTS_3 with the step count at 0.
 * Both ways the TxFFE level starts again at 0 and SCDC register 0x31 of the sink gets the new rate (0 when
 * giving up; the FFE levels in bits 4..7 are not written here).
 *
 * Returns 0, so the next state runs on the next tick.
 */
int DRV_HDMI21_TXDetect_FSM_LTS_4(unsigned int port)
{
    unsigned int rate;
    unsigned int rate_now;

    port &= 0xff;
    if (hdmi_tx_frl_states[port] != hdmi_tx_frl_printed_states[port]) {
        dbg_printf("\x1b[1;33m[HDMI_TX_FRL_Training]: Port%d : DRV_HDMI21_TXDetect_FSM_LTS_4\n", port);
        hdmi_tx_frl_printed_states[port] = hdmi_tx_frl_states[port];
    }
    hdmi_tx_set_frl_rate_update(port);
    if (hdmi_tx_frl_rates[port] != 0) {
        hdmi_tx_frl_rates[port]--;
        hdmi_tx_set_frl_rate(port, hdmi_tx_frl_rates[port]);
        hdmi_tx_clear_active(port);
    }
    rate = hdmi_tx_frl_rates[port] & 0xff;
    if (hdmi_tx_frl_rates[port] == 0) {
        /* No rate left to try: give up on FRL for this port. */
        hdmi_tx_clear_frl_mode(port);
        hdmi_tx_clear_active(port);
        hdmi_tx_frl_states[port] = TX_FRL_STATE_LTS_L;
        hdmi_tx_set_status_bit31(port);
        dbg_print_string("\x1b[0;33m\t\t - No lower FRL_RATE could be used\n");
        rate_now = hdmi_tx_frl_rates[port] & 0xff;
        hdmi_tx_ffe_levels[port] = 0;
        hdmi_tx_scdc_write(port, SCDC_REG_RATE_FFE, rate_now);
        dbg_printf("\x1b[0;33m\t\t - SCDC_Write 0x%02X = 0x%02X\n", SCDC_REG_RATE_FFE, rate_now);
    } else {
        /* Train again at the lower rate. */
        hdmi_tx_frl_states[port] = TX_FRL_STATE_LTS_3;
        hdmi_tx_frl_step_bytes[port] = 0;
        hdmi_tx_ffe_levels[port] = 0;
        hdmi_tx_scdc_write(port, SCDC_REG_RATE_FFE, rate);
        dbg_printf("\x1b[0;33m\t\t - SCDC_Write 0x%02X = 0x%02X\n", SCDC_REG_RATE_FFE, rate);
    }
    return 0;
}
