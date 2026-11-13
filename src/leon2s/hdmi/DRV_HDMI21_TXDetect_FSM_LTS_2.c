/* DRV_HDMI21_TXDetect_FSM_LTS_2  (FUN_a00a3a10)
 *
 * Run LTS:2 of the HDMI TX FRL training: write the FRL rate and FFE levels to the sink.
 *   port: HDMI TX port 0/1
 * Returns: 0, so the next state runs on the next tick
 * Name basis: proven - state name printed ('[HDMI_TX_FRL_Training]: Port%d : DRV_HDMI21_TXDetect_FSM_LTS_2');
 *   state 2; SCDC write 0x31 = FFE levels << 4 | FRL rate
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00a3a10 @ 0xa00a3a10-0xa00a3b68 (86 words), flags -mcpu=v8 -Os -g (section default).
 * Source forms the exact build depends on:
 *  - the parameter is int and masked in place; `index` is a copy taken after the mask and indexes the state
 *    tables, the parameter indexes everything else;
 *  - the read of the level table for register 0xE2 follows the store of level 0 (the compiler loads entry 0
 *    directly); the read for register 0xE3 loads hdmi_tx_ffe_levels[port] again after the call; the table is
 *    not volatile;
 *  - the record word is read into `value` before the state store and written back after it.
 */

/* States of the FRL training, = index into hdmi_tx_frl_training_state_handlers. */
enum {
    TX_FRL_STATE_LTS_2 = 2,
    TX_FRL_STATE_LTS_3 = 3
};

/* Registers of the sink, read and written with hdmi_tx_scdc_read / _write. */
#define SCDC_REG_40        0x40
#define SCDC_REG40_BIT6    0x40         /* the training waits in this state until the sink sets it */
#define SCDC_REG_RATE_FFE  0x31         /* written in LTS:2 as FFE levels << 4 | FRL rate */

/* Register bank 4 (FRL) of the transmitter: the 16-bit value of the current TxFFE level, low byte first. */
#define HDMI_TX_BANK_FRL   4
#define FRL_REG_FFE_LOW    0xe2
#define FRL_REG_FFE_HIGH   0xe3

/* Word 5 (+0x14) of the port's 28-byte TX channel record (hdmi_tx_output_records). */
#define CHANNEL_WORD5          5
#define CHANNEL_WORD5_BIT11    0x800    /* with it and control bit 31 set, hdmi_tx_run_frl_training keeps
                                           training a channel that is not running */
#define CHANNEL_WORD5_BIT12    0x1000

extern int dbg_printf(const char *, ...);
extern unsigned char hdmi_tx_scdc_read(unsigned int, unsigned int);
extern void hdmi_tx_scdc_write(unsigned int, unsigned int, unsigned int);
extern void hdmi_tx_set_frl_reg28_bit0(unsigned char, unsigned char);
extern void hdmi_tx_reg_write8(unsigned int, unsigned int, unsigned int, unsigned char);
extern void hdmi_tx_clear_active(unsigned int);
extern void hdmi_tx_clear_cfg_bit14(unsigned int);
extern void hdmi_tx_clear_status_bit31(unsigned int);

extern unsigned int hdmi_tx_frl_states[];         /* training state of each port (TX_FRL_STATE_*) */
extern unsigned int hdmi_tx_frl_printed_states[];         /* state printed last for each port */
extern unsigned int hdmi_tx_ffe_max_levels[];         /* highest TxFFE level index of each port ('FFE_Max') */
extern unsigned int hdmi_tx_frl_rates[];
extern unsigned char hdmi_tx_frl_rate_byte;
extern unsigned short hdmi_tx_ffe_normal_values[];       /* value of FRL registers 0xE2 / 0xE3 for each TxFFE level */
extern unsigned int hdmi_tx_output_records[];         /* TX channel records, 7 words per port */
extern unsigned char hdmi_tx_ffe_levels[];  /* 'u8HDMI21_TxFFE_Index' */
extern unsigned char hdmi_tx_frl_step_bytes[];
extern const char DAT_a006bb50[];           /* '[HDMI_TX_FRL_Training]: Port%d : DRV_HDMI21_TXDetect_FSM_LTS_2' */

/*
 * State LTS_2 of the FRL link training of HDMI output `port` (0 or 1). Run by hdmi_tx_run_frl_training
 * through hdmi_tx_frl_training_state_handlers on each timer tick while the port's state is 2.
 *
 * The state name is printed when the port entered this state since the last print, and the shared FRL rate
 * byte is set to 1. Then everything waits on bit 6 of the sink's SCDC register 0x40:
 *   - clear: the state stays LTS_2 and the step is tried again on the next tick;
 *   - set:   write FFE_Max << 4 | FRL rate to SCDC register 0x31, set bit 0 of FRL register 0x28, start
 *            again at TxFFE level 0 (its value from hdmi_tx_ffe_normal_values into FRL registers 0xE2 / 0xE3, as
 *            hdmi_tx_set_txffe_mode does), mark the channel not running, clear bit 14 of record word 5 and
 *            bit 31 of record word 1, clear bit 11 and set bit 12 of record word 5, and go to LTS_3 with the
 *            step count at 0.
 *
 * Returns 0, so the next state runs on the next tick.
 */
unsigned int DRV_HDMI21_TXDetect_FSM_LTS_2(int port) {
    unsigned int *channel_words;
    unsigned int index;
    unsigned int value;

    port &= 0xff;
    index = port;

    if (hdmi_tx_frl_states[index] != hdmi_tx_frl_printed_states[index]) {
        dbg_printf(DAT_a006bb50, port);
        hdmi_tx_frl_printed_states[index] = hdmi_tx_frl_states[index];
    }

    hdmi_tx_frl_rate_byte = 1;

    if (hdmi_tx_scdc_read(port, SCDC_REG_40) & SCDC_REG40_BIT6) {
        value = (hdmi_tx_ffe_max_levels[index] << 4 | hdmi_tx_frl_rates[index]) & 0xff;
        hdmi_tx_scdc_write(port, SCDC_REG_RATE_FFE, value);
        hdmi_tx_set_frl_reg28_bit0(port, 1);

        /* Start the TxFFE level from 0. */
        hdmi_tx_ffe_levels[port] = 0;
        hdmi_tx_reg_write8(port, HDMI_TX_BANK_FRL, FRL_REG_FFE_LOW, hdmi_tx_ffe_normal_values[hdmi_tx_ffe_levels[port]] & 0xff);
        hdmi_tx_reg_write8(port, HDMI_TX_BANK_FRL, FRL_REG_FFE_HIGH, hdmi_tx_ffe_normal_values[hdmi_tx_ffe_levels[port]] >> 8);

        hdmi_tx_clear_active(port);
        hdmi_tx_clear_cfg_bit14(port);
        hdmi_tx_clear_status_bit31(port);

        channel_words = hdmi_tx_output_records + port * 7;
        value = channel_words[CHANNEL_WORD5];
        hdmi_tx_frl_states[index] = TX_FRL_STATE_LTS_3;
        channel_words[CHANNEL_WORD5] = (value & ~CHANNEL_WORD5_BIT11) | CHANNEL_WORD5_BIT12;
        hdmi_tx_frl_step_bytes[port] = 0;
    } else {
        hdmi_tx_frl_states[index] = TX_FRL_STATE_LTS_2;
    }

    return 0;
}
