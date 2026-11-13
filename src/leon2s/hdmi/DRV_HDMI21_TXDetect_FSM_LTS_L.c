/* DRV_HDMI21_TXDetect_FSM_LTS_L  (FUN_a00a4524)
 *
 * Run LTS:L of the HDMI TX FRL training: write 0 to SCDC register 0x31; go to LTS:2 when in FRL mode.
 *   port: HDMI TX port 0/1
 * Returns: 0
 * Note: The SCDC writes happen only when the state differs from the one printed last; a set bit 5 of SCDC
 *   register 0x10 is written back. Always clears hdmi_tx_frl_rate_byte.
 * Name basis: proven - state name printed ('[HDMI_TX_FRL_Training]: Port%d : DRV_HDMI21_TXDetect_FSM_LTS_L');
 *   state 6; SCDC write 0x31 = 0
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00a4524 @ 0xa00a4524, flags -mcpu=v8 -Os -g.
 * Source forms the exact build depends on: the parameter is masked in place and copied to an unsigned int
 * index; the SCDC flags byte is kept in the same unsigned int as the FRL-mode result.
 */
#define TX_FRL_STATE_LTS_2 2
#define SCDC_REG_RATE_FFE  0x31         /* written in LTS:2 as FFE levels << 4 | FRL rate */
#define SCDC_REG_FLAGS     0x10
#define SCDC_FLAG_LTP_REQ  0x20         /* a set flag is acknowledged by writing the bit back */

extern unsigned char hdmi_tx_frl_rate_byte;
extern int dbg_printf(const char *, ...);
extern unsigned int hdmi_tx_is_frl_mode(unsigned int);
extern void hdmi_tx_scdc_write(unsigned int, unsigned int, unsigned int);
extern unsigned char hdmi_tx_scdc_read(unsigned int, unsigned int);
extern unsigned int hdmi_tx_frl_printed_states[];     /* state printed last for each port */
extern unsigned int hdmi_tx_frl_states[];     /* training state of each port */

/*
 * State 6 (LTS:L) of the HDMI TX FRL link training. port is the HDMI TX port (0 or 1).
 *
 * When the port's state differs from the one printed last, the state name is printed and the step writes 0
 * to SCDC register 0x31 of the sink and acknowledges the sink's LTP_req flag if it is set. If the port is
 * in FRL mode the state then goes back to LTS_2. The shared FRL rate byte is cleared. Returns 0.
 */
unsigned int DRV_HDMI21_TXDetect_FSM_LTS_L(unsigned char port) {
    unsigned int scdc_flags;
    unsigned int index;

    port &= 0xff;
    index = port;

    if (hdmi_tx_frl_states[index] != hdmi_tx_frl_printed_states[index]) {
        dbg_printf("\x1b[1;33m[HDMI_TX_FRL_Training]: Port%d : DRV_HDMI21_TXDetect_FSM_LTS_L\n\n\x1b[0m", port);
        hdmi_tx_frl_printed_states[index] = hdmi_tx_frl_states[index];
        hdmi_tx_scdc_write(port, SCDC_REG_RATE_FFE, 0);
        scdc_flags = hdmi_tx_scdc_read(port, SCDC_REG_FLAGS);
        if (scdc_flags & SCDC_FLAG_LTP_REQ) {
            hdmi_tx_scdc_write(port, SCDC_REG_FLAGS, SCDC_FLAG_LTP_REQ);
        }
    }

    scdc_flags = hdmi_tx_is_frl_mode(port);
    if ((scdc_flags & 0xff) == 1) {
        hdmi_tx_frl_states[port] = TX_FRL_STATE_LTS_2;
    }

    hdmi_tx_frl_rate_byte = 0;
    return 0;
}
