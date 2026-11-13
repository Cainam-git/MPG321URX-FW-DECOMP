/* DRV_HDMI21_TXDetect_FSM_Init  (FUN_a00a3788)
 *
 * Run the start state of the HDMI TX FRL link training: clear the FRL rate.
 *   port: HDMI TX port 0/1
 * Returns: 0
 * Name basis: proven - state name printed ('[HDMI_TX_FRL_Training]: Port%d : DRV_HDMI21_TXDetect_FSM_Init');
 *   SCDC 0x31 = 0; state 0 of 0xA00B4CF8
 *
 * Matching notes
 * --------------
 * FUN_a00a3788 (leon2s, 0xa00a3788), flags -mcpu=v8 -Os -g.
 * Source forms the exact build depends on: the dashes line is printed through the one-argument
 * dbg_print_string (the string has no format) from the symbol DAT_a006ba90; the table symbol is
 * hdmi_tx_frl_printed_states; the port is masked in place and copied to an unsigned int index.
 */
#define TX_FRL_STATE_LTS_1 1            /* the state that follows this one */
#define SCDC_REG_RATE_FFE  0x31         /* written in LTS:2 as FFE levels << 4 | FRL rate */

extern unsigned int hdmi_tx_frl_states[];     /* training state of each port */
extern unsigned int hdmi_tx_frl_printed_states[];     /* state printed last for each port */
extern unsigned char hdmi_tx_frl_rate_byte;
extern unsigned char hdmi_tx_frl_done_flags[];
extern int dbg_printf(const char *, ...);
extern unsigned int dbg_print_string(const char *);
extern const char DAT_a006ba90[];       /* line of dashes */
extern void hdmi_tx_scdc_write(unsigned int, unsigned int, unsigned int);
extern const char DAT_a006bac0[];       /* '[HDMI_TX_FRL_Training]: Port%d : DRV_HDMI21_TXDetect_FSM_Init' */

/*
 * State 0 of the HDMI TX FRL link training. port is the HDMI TX port (0 or 1).
 *
 * The dashes line and the state name are printed only when the port's state differs from the one printed
 * last. The step then writes 0 to SCDC register 0x31 of the sink, sets the port's state to LTS_1 and clears
 * the port's done flag and the shared FRL rate byte. Returns 0: the next state runs on the next timer tick.
 */
unsigned int DRV_HDMI21_TXDetect_FSM_Init(unsigned char port)
{
  unsigned int index;
  port &= 0xff;
  index = port;
  if (hdmi_tx_frl_states[index] != hdmi_tx_frl_printed_states[index])
  {
    dbg_print_string(DAT_a006ba90);
    dbg_printf(DAT_a006bac0, port);
    hdmi_tx_frl_printed_states[index] = hdmi_tx_frl_states[index];
  }
  hdmi_tx_scdc_write(port, SCDC_REG_RATE_FFE, 0);
  hdmi_tx_frl_states[index] = TX_FRL_STATE_LTS_1;
  hdmi_tx_frl_done_flags[port] = 0;
  hdmi_tx_frl_rate_byte = 0;
  return 0;
}
