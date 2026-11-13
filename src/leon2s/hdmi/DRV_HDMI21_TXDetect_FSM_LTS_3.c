/* DRV_HDMI21_TXDetect_FSM_LTS_3  (FUN_a00a3b68)
 *
 * Run LTS:3 of the HDMI TX FRL training: answer the sink's link pattern and FFE requests.
 *   port_arg: HDMI TX port 0/1
 * Returns: 0 on every path
 * Name basis: proven - state name printed ('[HDMI_TX_FRL_Training]: Port%d : DRV_HDMI21_TXDetect_FSM_LTS_3');
 *   state 3; 'LTP_req[%d] need to change TxFFE', 'LTS3 MAX timeout for 200ms go to LTS_L'
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00a3b68 @ 0xa00a3b68-0xa00a4238 (1744 bytes), flags -mcpu=v8 -Os -g.
 * Source forms the exact build depends on:
 *  - the parameter is unsigned int; `port` is an unsigned char copy, assigned again after the SCDC_FLAG_LTP_REQ
 *    test and inside the once-block (the firmware masks %i0 again there); the later uses mask the parameter
 *    in place;
 *  - lanes is written 3 + (rate >= 3) (subx form);
 *  - every call with a 0 / 1 argument is a separate call in each arm;
 *  - the unused table copy stays (lib_memcpy into an 8-byte local).
 */
extern int dbg_printf(const char *, ...);
extern void *lib_memcpy(void *, const void *, unsigned int);
extern unsigned int hdmi_tx_is_active(unsigned char);
extern unsigned char hdmi_tx_scdc_read(unsigned int, unsigned int);
extern void hdmi_tx_scdc_write(unsigned int, unsigned int, unsigned int);
extern void hdmi_tx_set_txffe_mode(unsigned char, int);
extern void hdmi_tx_reg_update_bits(unsigned char, unsigned char, unsigned short, unsigned int, unsigned char);
extern void hdmi_tx_reg_write_field(unsigned char, unsigned char, unsigned short, unsigned int, unsigned int);
extern void hdmi_tx_reg_write8(unsigned char, unsigned char, unsigned short, unsigned char);
extern void hdmi_tx_set_frl_reg28_bit0(unsigned char, unsigned char);
extern void hdmi_tx_set_phy_reg3b_bits(unsigned char, unsigned char);
extern unsigned int reg_read32(volatile unsigned int *);
extern void reg_write32(volatile unsigned int *, unsigned int);

/* Printed texts, all starting '[HDMI_TX_FRL_Training]: ' unless noted. */
extern const unsigned char hdmi_tx_lts3_byte_table[];
extern const char DAT_a006bb98[];       /* 'Port%d : DRV_HDMI21_TXDetect_FSM_LTS_3' */
extern const char DAT_a006bbe0[];       /* 'Port%d : [WRN] LTS3 MAX timeout for 200ms go to LTS_L' */
extern const char DAT_a006bc38[];       /* 'Port%d : TX setting is not ready' */
extern const char DAT_a006bc80[];       /* '>>SCDC_Read 0x%02X = 0x%02X, FRL_Max = 0x%02X, FLT_no_timeout = 0x%02X' */
extern const char DAT_a006bce8[];       /* ' - LTP_req[%d] need to change TxFFE, Now only can 4 lane align' (no prefix) */
extern const char DAT_a006bd38[];       /* 'Port%d : LTP_req[%d] Receive FFE Request' */
extern const char DAT_a006bd88[];       /* ' - LTP_req[%d] u8HDMI21_TxFFE_Index+1 > FFE_Max' (no prefix) */
extern const char DAT_a006bdc8[];       /* 'Skip LTP3 pattern request at lane %d' */
extern const char DAT_a006be10[];       /* "Port%d : [WRN] LTP_req[%d]=0x%02X abnormal value, don't do anything" */

/* Registers cleared in bits 8..14 before the lane requests are applied, one per output port. */
#define TX_PORT0_REG_340C ((volatile unsigned int *)0xce00340c)
#define TX_PORT1_REG_370C ((volatile unsigned int *)0xce00370c)

/* States of the FRL training, = index into hdmi_tx_frl_training_state_handlers. */
enum {
    TX_FRL_STATE_INIT  = 0,
    TX_FRL_STATE_LTS_1 = 1,
    TX_FRL_STATE_LTS_2 = 2,
    TX_FRL_STATE_LTS_3 = 3,
    TX_FRL_STATE_LTS_4 = 4,
    TX_FRL_STATE_LTS_P = 5,
    TX_FRL_STATE_LTS_L = 6
};

/* Modes of hdmi_tx_set_txffe_mode, named by the texts it prints. */
enum {
    TXFFE_MODE_NORMAL      = 0,         /* 'TxFFE_Normal(Exit Mode)' (every value other than 1..3) */
    TXFFE_MODE_PRESHOOT    = 1,         /* 'TxFFE_Preshoot' */
    TXFFE_MODE_DE_EMPHASIS = 2,         /* 'TxFFE De-Emphasis' */
    TXFFE_MODE_NO          = 3          /* 'TxFFE_NO' */
};

/* Registers of the sink, read and written with hdmi_tx_scdc_read / _write. */
#define SCDC_REG_FLAGS         0x10
#define SCDC_FLAG_REG35        0x08     /* set: register 0x35 is read; the bit is written back afterwards */
#define SCDC_FLAG_LTP_REQ      0x20     /* set: registers 0x41 / 0x42 are read; the bit is written back afterwards */
#define SCDC_REG_35            0x35     /* printed as FRL_Max (bit 7) and FLT_no_timeout (bit 5) */
#define SCDC_REG35_PRESHOOT    0x02     /* bits 1..3 choose the TxFFE mode, lowest set bit first */
#define SCDC_REG35_DE_EMPHASIS 0x04
#define SCDC_REG35_NO_FFE      0x08
#define SCDC_REG35_FLT_NO_TIMEOUT 0x20
#define SCDC_REG_LTP_REQ_LO    0x41     /* LTP_req of lanes 0 (bits 0..3) and 1 (bits 4..7) */
#define SCDC_REG_LTP_REQ_HI    0x42     /* LTP_req of lanes 2 and 3 */

/* LTP_req values of one lane (only the handling below is shown by the code). */
#define LTP_REQ_FFE            0xe      /* 'Receive FFE Request' */
#define LTP_REQ_SKIPPED        3        /* skipped while FLT_no_timeout is 0 ('Skip LTP3 pattern request') */

#define LTS3_MAX_STEPS         200      /* calls in this state before the 'LTS3 MAX timeout' */

extern unsigned int hdmi_tx_frl_states[];     /* training state of each port (TX_FRL_STATE_*) */
extern unsigned int hdmi_tx_frl_printed_states[];     /* state last printed for each port; starts at 7, so the first state is printed */
extern unsigned int hdmi_tx_frl_rates[];
extern unsigned int hdmi_tx_ffe_max_levels[];     /* highest TxFFE level index of each port ('FFE_Max') */
extern unsigned char hdmi_tx_frl_step_bytes[];
extern unsigned char hdmi_tx_flt_no_timeout_flags[];    /* FLT_no_timeout bit of SCDC register 0x35, per port */
extern unsigned char hdmi_tx_lts3_timeout_enables[];    /* 1: the LTS3 timeout applies (start value 1) */
extern unsigned char hdmi_tx_lts3_phy39_bit4_on[];    /* non-zero: set bit 4 of PHY register 0x39, else clear it (start value 1) */
extern unsigned char hdmi_tx_lts3_phy39_bit1_on[];    /* non-zero: set bit 1 of PHY register 0x39, else clear it (start value 1) */
extern unsigned char hdmi_tx_lts3_phy3c_bits_off[];    /* non-zero: clear bits 2..3 of PHY register 0x3C, else set them (start value 1) */
extern unsigned char hdmi_tx_ffe_levels[];      /* 'u8HDMI21_TxFFE_Index' */
extern unsigned char hdmi_tx_txffe_mode;         /* TxFFE mode chosen from SCDC register 0x35 (TXFFE_MODE_*) */

/*
 * State LTS_3 of the FRL link training of HDMI output `port_arg` (0 or 1): follow the per-lane link pattern
 * requests (LTP_req) that the sink sets in its SCDC registers 0x41 / 0x42.
 *
 * Returns 0. Run by hdmi_tx_run_frl_training through hdmi_tx_frl_training_state_handlers, which calls the next
 * state at once only on a non-zero result.
 *
 * Bank numbers are those of the HDMI transmitter's register banks (hdmi_tx_reg_* routines): bank 1 = PHY,
 * bank 4 = FRL.
 *
 * Phases:
 *   1. Print the state name when the port entered this state since the last print.
 *   2. Lane count (3 for FRL rates below 3, else 4). Count the call; after more than LTS3_MAX_STEPS calls with
 *      FLT_no_timeout 0 and the timeout on, set state LTS_L (the routine goes on after that).
 *   3. Stop when the output is not running ('TX setting is not ready').
 *   4. SCDC flag bit 3: read register 0x35, print it, choose the TxFFE mode from bits 1..3 and set it, keep
 *      FLT_no_timeout, write the flag bit back.
 *   5. Without SCDC flag bit 5 stop here. Otherwise set or clear bit 4 of PHY register 0x39 (hdmi_tx_lts3_phy39_bit4_on),
 *      read LTP_req and split it into one nibble per lane.
 *   6. All requests 0: write 0x20 to FRL register 0x0D, set FRL register 0x28 bit 0 and go to LTS_P.
 *      All requests 0xF: go to LTS_4. Both restart the step count.
 *   7. Otherwise clear bits 8..14 of the port's register 0xCE00340C / 0xCE00370C, set or clear bit 1 of PHY
 *      register 0x39 and bits 2..3 of PHY register 0x3C (hdmi_tx_lts3_phy39_bit1_on / hdmi_tx_lts3_phy3c_bits_off), then per lane:
 *        0xE    raise the TxFFE level by one (at most once per call, up to FFE_Max) and set the mode again;
 *        1..8   5..8 set bit 5 and clear bit 4 of PHY register 0x3B; then, unless it is a request 3 that is
 *               skipped, write the nibble into FRL register 0xE0 (lanes 0, 1) or 0xE1 (lanes 2, 3) and clear the
 *               lane's bit in PHY register 0x50;
 *        others print 'abnormal value' and do nothing.
 *      Afterwards hdmi_tx_set_phy_reg3b_bits(port, ffe_requested) with ffe_requested = 1 when a lane asked for
 *      0xE or 5..8.
 *   8. Write SCDC flag bit 5 back.
 */
int DRV_HDMI21_TXDetect_FSM_LTS_3(unsigned int port_arg)
{
    unsigned char ltp_req_bytes[2] = { 0 };
    int ltp_req[4] = { 0 };
    unsigned char unused_table[8];
    unsigned char port;
    unsigned char lanes;
    unsigned char step_or_flags;        /* first the previous step count, then SCDC register 0x10 */
    unsigned char scdc_35;
    unsigned char lane;
    unsigned char ffe_requested;
    unsigned char ffe_level_raised;
    unsigned short ltp_req_word;
    unsigned int next_ffe_level;

    /* hdmi_tx_lts3_byte_table (00 00 11 11 22 22 33 33) is copied here and never read. */
    lib_memcpy(unused_table, hdmi_tx_lts3_byte_table, 8);
    port = port_arg;
    ffe_requested = 0;

    /* Phase 1. */
    if (hdmi_tx_frl_states[port] != hdmi_tx_frl_printed_states[port]) {
        dbg_printf(DAT_a006bb98, port);
        hdmi_tx_frl_printed_states[port] = hdmi_tx_frl_states[port];
    }

    /* Phase 2: lane count and the step limit. */
    lanes = 3 + (hdmi_tx_frl_rates[port] >= 3);
    step_or_flags = hdmi_tx_frl_step_bytes[port];
    hdmi_tx_frl_step_bytes[port] = step_or_flags + 1;
    if (step_or_flags > LTS3_MAX_STEPS && hdmi_tx_flt_no_timeout_flags[port] == 0 && hdmi_tx_lts3_timeout_enables[port] == 1) {
        dbg_printf(DAT_a006bbe0, port);
        hdmi_tx_frl_states[port] = TX_FRL_STATE_LTS_L;
        hdmi_tx_frl_step_bytes[port] = 0;
    }

    /* Phase 3. */
    if ((unsigned char)hdmi_tx_is_active(port) == 0) {
        dbg_printf(DAT_a006bc38, port);
        return 0;
    }

    /* Phase 4: SCDC register 0x35. */
    step_or_flags = hdmi_tx_scdc_read(port, SCDC_REG_FLAGS);
    if (step_or_flags & SCDC_FLAG_REG35) {
        scdc_35 = hdmi_tx_scdc_read(port, SCDC_REG_35);
        dbg_printf(DAT_a006bc80, SCDC_REG_35, scdc_35, scdc_35 & 0x80, scdc_35 & SCDC_REG35_FLT_NO_TIMEOUT);
        if (scdc_35 & SCDC_REG35_PRESHOOT)
            hdmi_tx_txffe_mode = TXFFE_MODE_PRESHOOT;
        else if (scdc_35 & SCDC_REG35_DE_EMPHASIS)
            hdmi_tx_txffe_mode = TXFFE_MODE_DE_EMPHASIS;
        else if (scdc_35 & SCDC_REG35_NO_FFE)
            hdmi_tx_txffe_mode = TXFFE_MODE_NO;
        else
            hdmi_tx_txffe_mode = TXFFE_MODE_NORMAL;
        hdmi_tx_set_txffe_mode(port, hdmi_tx_txffe_mode);
        if (scdc_35 & SCDC_REG35_FLT_NO_TIMEOUT)
            hdmi_tx_flt_no_timeout_flags[port] = 1;
        else
            hdmi_tx_flt_no_timeout_flags[port] = 0;
        hdmi_tx_scdc_write(port, SCDC_REG_FLAGS, SCDC_FLAG_REG35);
    }

    /* Phase 5: the lane requests. */
    if (!(step_or_flags & SCDC_FLAG_LTP_REQ))
        return 0;

    port = port_arg;
    if (hdmi_tx_lts3_phy39_bit4_on[port] != 0)
        hdmi_tx_reg_update_bits(port, 1, 0x39, 0x10, 1);
    else
        hdmi_tx_reg_update_bits(port, 1, 0x39, 0x10, 0);
    ltp_req_bytes[0] = hdmi_tx_scdc_read(port, SCDC_REG_LTP_REQ_LO);
    ltp_req_bytes[1] = hdmi_tx_scdc_read(port, SCDC_REG_LTP_REQ_HI);
    ltp_req_word = (ltp_req_bytes[1] << 8) | ltp_req_bytes[0];
    for (lane = 0; lane < lanes; lane++)
        ltp_req[lane] = (int)(ltp_req_word & (0xf << (lane * 4))) >> (lane * 4);

    /* Phase 6: all lanes 0, or all lanes 0xF. With 3 lanes only the low 12 bits count. */
    if (ltp_req_word == 0 || (lanes == 3 && (ltp_req_word & 0xfff) == 0)) {
        hdmi_tx_reg_write8(port, 4, 0xd, 0x20);
        hdmi_tx_set_frl_reg28_bit0(port, 1);
        hdmi_tx_frl_states[port] = TX_FRL_STATE_LTS_P;
        hdmi_tx_frl_step_bytes[port] = 0;
    } else if (ltp_req_word == 0xffff || (lanes == 3 && (ltp_req_word & 0xfff) == 0xfff)) {
        hdmi_tx_frl_states[port] = TX_FRL_STATE_LTS_4;
        hdmi_tx_frl_step_bytes[port] = 0;
    } else {
        /* Phase 7: per-lane requests. */
        if (port == 0)
            reg_write32(TX_PORT0_REG_340C, reg_read32(TX_PORT0_REG_340C) & 0xffff80ff);
        else
            reg_write32(TX_PORT1_REG_370C, reg_read32(TX_PORT1_REG_370C) & 0xffff80ff);
        if (hdmi_tx_lts3_phy39_bit1_on[port] != 0)
            hdmi_tx_reg_update_bits(port, 1, 0x39, 2, 1);
        else
            hdmi_tx_reg_update_bits(port, 1, 0x39, 2, 0);
        if (hdmi_tx_lts3_phy3c_bits_off[port] != 0)
            hdmi_tx_reg_update_bits(port, 1, 0x3c, 0xc, 0);
        else
            hdmi_tx_reg_update_bits(port, 1, 0x3c, 0xc, 1);
        ffe_level_raised = 0;
        for (lane = 0; lane < lanes; lane++) {
            if (ltp_req[lane] == LTP_REQ_FFE) {
                ffe_requested = 1;
                /* The TxFFE level goes up by one per call, however many lanes ask. */
                if (!ffe_level_raised) {
                    ffe_level_raised = 1;
                    port = port_arg;
                    next_ffe_level = hdmi_tx_ffe_levels[port] + 1;
                    if (next_ffe_level <= hdmi_tx_ffe_max_levels[port]) {
                        hdmi_tx_ffe_levels[port] = next_ffe_level % (hdmi_tx_ffe_max_levels[port] + 1);
                        dbg_printf(DAT_a006bce8, lane);
                        hdmi_tx_set_txffe_mode(port, hdmi_tx_txffe_mode);
                    } else {
                        dbg_printf(DAT_a006bd88, lane);
                    }
                }
                dbg_printf(DAT_a006bd38, (unsigned char)port_arg, lane);
            } else if (ltp_req[lane] - 1 < 8u) {
                /* Requests 1..8. */
                if (ltp_req[lane] - 5 < 4u) {
                    /* Requests 5..8. */
                    hdmi_tx_reg_update_bits(port_arg, 1, 0x3b, 0x20, 1);
                    ffe_requested = 1;
                    hdmi_tx_reg_update_bits(port_arg, 1, 0x3b, 0x10, 0);
                }
                if (ltp_req[lane] == LTP_REQ_SKIPPED && hdmi_tx_flt_no_timeout_flags[(unsigned char)port_arg] == 0) {
                    dbg_printf(DAT_a006bdc8, lane);
                } else if (lane == 0) {
                    /* The request goes to the lane's nibble of FRL register 0xE0 / 0xE1. */
                    hdmi_tx_reg_write_field(port_arg, 4, 0xe0, 0xf, (unsigned char)ltp_req[0]);
                    hdmi_tx_reg_update_bits(port_arg, 1, 0x50, 1, 0);
                } else if (lane == 1) {
                    hdmi_tx_reg_write_field(port_arg, 4, 0xe0, 0xf0, (ltp_req[1] << 4) & 0xf0);
                    hdmi_tx_reg_update_bits(port_arg, 1, 0x50, 2, 0);
                } else if (lane == 2) {
                    hdmi_tx_reg_write_field(port_arg, 4, 0xe1, 0xf, (unsigned char)ltp_req[2]);
                    hdmi_tx_reg_update_bits(port_arg, 1, 0x50, 4, 0);
                } else if (lane == 3) {
                    hdmi_tx_reg_write_field(port_arg, 4, 0xe1, 0xf0, (ltp_req[3] << 4) & 0xf0);
                    hdmi_tx_reg_update_bits(port_arg, 1, 0x50, 8, 0);
                }
            } else {
                dbg_printf(DAT_a006be10, (unsigned char)port_arg, lane, ltp_req[lane] & 0xff);
            }
        }
        hdmi_tx_set_phy_reg3b_bits(port_arg, ffe_requested);
    }

    /* Phase 8. */
    hdmi_tx_scdc_write((unsigned char)port_arg, SCDC_REG_FLAGS, SCDC_FLAG_LTP_REQ);
    return 0;
}
