/* DRV_HDMI21_TXDetect_FSM_LTS_P  (FUN_a00a4370)
 *
 * Run LTS:P of the HDMI TX FRL training: start FRL video once the sink is ready.
 *   port: HDMI TX port 0/1
 * Returns: always 0
 * Name basis: proven - state name printed ('[HDMI_TX_FRL_Training]: Port%d : DRV_HDMI21_TXDetect_FSM_LTS_P');
 *   state 5; tests SCDC register 0x10 bit 4 ('FRL_StartBit' in its warning text) and bit 5 (the lane request
 *   flag LTS_3 serves); 'force Start Normal FRL video'
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00a4370 @ 0xa00a4370, flags -mcpu=v8 -Os -g (section default).
 * Source forms the exact build depends on:
 *  - the parameter is masked in place; the entry block is skipped with a goto;
 *  - the callees are declared without prototypes except hdmi_tx_scdc_read and hdmi_tx_set_frl_reg28_bit0, and
 *    the two texts are passed as the addresses of unsigned int objects.
 */

/* States of the FRL training, = index into hdmi_tx_frl_training_state_handlers. */
enum {
    TX_FRL_STATE_LTS_2 = 2,
    TX_FRL_STATE_LTS_3 = 3,
    TX_FRL_STATE_LTS_P = 5
};

/* Register of the sink, read and written with hdmi_tx_scdc_read / _write. A set flag is acknowledged by
   writing the bit back. */
#define SCDC_REG_FLAGS        0x10
#define SCDC_FLAG_FRL_START   0x10      /* 'FRL_StartBit' */
#define SCDC_FLAG_LTP_REQ     0x20      /* set: the sink has new lane requests, which LTS_3 reads */

/* Transmitter register banks (hdmi_tx_reg_* routines): bank 1 = PHY, bank 4 = FRL. */
#define HDMI_TX_BANK_PHY      1
#define HDMI_TX_BANK_FRL      4
#define PHY_REG_39            0x39
#define PHY_REG39_BIT4        0x10
#define FRL_REG_LTP_LANES01   0xe0      /* LTS_3 writes the lane requests of lanes 0 / 1 into its nibbles */
#define FRL_REG_LTP_LANES23   0xe1      /* the same for lanes 2 / 3 */

extern unsigned int DAT_a006bf18;       /* '[HDMI_TX_FRL_Training]: Port%d : DRV_HDMI21_TXDetect_FSM_LTS_P' */
extern unsigned int DAT_a006bf68;       /* '... Port%d : [WRN]LTS_P - Bypass check FRL_StartBit, and force Start
                                           Normal FRL video' */
extern int dbg_printf();
extern int hdmi_tx_set_cfg_bit14();
extern int hdmi_tx_scdc_write();
extern unsigned char hdmi_tx_scdc_read(unsigned int port, unsigned int reg);
extern void hdmi_tx_set_frl_reg28_bit0(unsigned char port, unsigned char on);
extern void hdmi_tx_reg_write8();
extern void hdmi_tx_reg_update_bits();
extern unsigned int hdmi_tx_frl_printed_states[];     /* state printed last for each port */
extern unsigned int hdmi_tx_frl_states[];     /* training state of each port (TX_FRL_STATE_*) */
extern unsigned char hdmi_tx_frl_video_flags[];
extern unsigned char hdmi_tx_frl_step_bytes[];
extern unsigned char hdmi_tx_frl_done_flags[];

/*
 * State LTS_P of the FRL link training of HDMI output `port` (0 or 1); `unused` is not read. Run by
 * hdmi_tx_run_frl_training through hdmi_tx_frl_training_state_handlers; LTS_3 enters it when the sink
 * requests 0 on all lanes.
 *
 * On the first call after entering the state: print the state name, clear bit 4 of PHY register 0x39,
 * write 0 to the lane request registers 0xE0 / 0xE1 and acknowledge the sink's LTP_req flag.
 *
 * Then, on the sink's SCDC flags register 0x10, in this order:
 *   1. the port's done flag set: clear it and go back to LTS_2;
 *   2. FRL_StartBit set, or the port's video flag set (the start bit is then not checked, with a warning):
 *      the same three register writes again, clear bit 0 of FRL register 0x28, acknowledge the start bit (or
 *      clear the video flag) and set bit 14 of word 5 of the TX channel record. The state stays LTS_P;
 *   3. LTP_req flag set: acknowledge it and go back to LTS_3 with the step count at 0;
 *   4. nothing set: stay in LTS_P.
 *
 * Returns 0, so the next state runs on the next tick.
 */
unsigned int DRV_HDMI21_TXDetect_FSM_LTS_P(unsigned int port, unsigned int unused)
{
  unsigned char scdc_flags;
  port = port & 0xff;
  if (hdmi_tx_frl_states[port] == hdmi_tx_frl_printed_states[port])
  {
    goto skip_init;
  }
  dbg_printf(&DAT_a006bf18, port);
  hdmi_tx_frl_printed_states[port] = hdmi_tx_frl_states[port];
  hdmi_tx_reg_update_bits(port, HDMI_TX_BANK_PHY, PHY_REG_39, PHY_REG39_BIT4, 0);
  hdmi_tx_reg_write8(port, HDMI_TX_BANK_FRL, FRL_REG_LTP_LANES01, 0);
  hdmi_tx_reg_write8(port, HDMI_TX_BANK_FRL, FRL_REG_LTP_LANES23, 0);
  hdmi_tx_scdc_write(port, SCDC_REG_FLAGS, SCDC_FLAG_LTP_REQ);
  skip_init:
  scdc_flags = hdmi_tx_scdc_read(port, SCDC_REG_FLAGS);

  if (hdmi_tx_frl_done_flags[port] != 0)
  {
    hdmi_tx_frl_states[port] = TX_FRL_STATE_LTS_2;
    hdmi_tx_frl_done_flags[port] = 0;
    return 0;
  }
  if (((scdc_flags & SCDC_FLAG_FRL_START) != 0) || (hdmi_tx_frl_video_flags[port] != 0))
  {
    hdmi_tx_reg_update_bits(port, HDMI_TX_BANK_PHY, PHY_REG_39, PHY_REG39_BIT4, 0);
    hdmi_tx_reg_write8(port, HDMI_TX_BANK_FRL, FRL_REG_LTP_LANES01, 0);
    hdmi_tx_reg_write8(port, HDMI_TX_BANK_FRL, FRL_REG_LTP_LANES23, 0);
    hdmi_tx_set_frl_reg28_bit0(port, 0);
    if ((scdc_flags & SCDC_FLAG_FRL_START) != 0)
    {
      hdmi_tx_scdc_write(port, SCDC_REG_FLAGS, SCDC_FLAG_FRL_START);
    }
    else
    {
      /* Started without the sink's start bit; the video flag is cleared after this one use. */
      hdmi_tx_frl_video_flags[port] = 0;
      dbg_printf(&DAT_a006bf68, port);
    }
    hdmi_tx_set_cfg_bit14(port);
  }
  else
    if (!((scdc_flags & SCDC_FLAG_LTP_REQ) == 0))
  {
    /* The sink asks for training again. */
    hdmi_tx_scdc_write(port, SCDC_REG_FLAGS, SCDC_FLAG_LTP_REQ);
    hdmi_tx_frl_states[port] = TX_FRL_STATE_LTS_3;
    hdmi_tx_frl_step_bytes[port] = 0;
  }
  else
  {
    hdmi_tx_frl_states[port] = TX_FRL_STATE_LTS_P;
  }
  return 0;
}
