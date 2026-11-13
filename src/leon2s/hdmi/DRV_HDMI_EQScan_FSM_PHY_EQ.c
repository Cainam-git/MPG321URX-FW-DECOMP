/* DRV_HDMI_EQScan_FSM_PHY_EQ  (DRV_HDMI_EQScan_FSM_PHY_EQ)
 *
 * EQ scan step: set the per-lane PHY and EQ table values for the clock range.
 *   port: PHY
 * Note: State function of the EQ scan table run by hdmi_eq_run_scan_fsm.
 * Name basis: proven - original name printed: 'DRV_HDMI_EQScan_FSM_PHY_EQ'
 *
 * Matching notes
 * --------------
 * leon2s DRV_HDMI_EQScan_FSM_PHY_EQ @ 0xa007b394-0xa007c4b8, flags -mcpu=v8 -Os -g (section default).
 * Source forms the exact build depends on:
 *  - the 300..600 MHz range reaches the code of the 160..300 MHz range through 'goto' when
 *    hdmi_eq_get_clock_ratio_mode returns 0;
 *  - the next state is written in two arms chosen by byte_0x8 of the scan record,
 *    'if (hdmi_eq_scan_records[port].byte_0x8) .. else ..', as in DRV_HDMI_EQScan_FSM_PHY_RunAEQ and
 *    DRV_HDMI_EQScan_FSM_PHY_BA_Turning; both arms store 10 here and the firmware holds the store once
 *    (0xa007c4ac). The two-arm form is what the registers of 0xa007c494-0xa007c4ac show (record index in %o0,
 *    value in %g1); a single store gives %g1 and %o5, and a test on is_hdmi21, clock, port or the recheck
 *    flag in place of a field of this record does not give the firmware code.
 */

/* Message groups of dbg_hdmi_message_flags: every print of the EQ scan is in group EQ_FLOW. */
#define HDMI_MSG_EQ_FLOW 0x02

/* States of the EQ scan: the index into hdmi_eq_scan_state_handlers. */
#define EQSCAN_STATE_PRE_CHKERROR 0x0a  /* DRV_HDMI_EQScan_FSM_PHY_PreChkError */

/* Limits of the PHY clock (phy_clock_mhz) for the register sets below: below 100, below 160, below 300,
   up to 600 (above that: "out clk range"). */
#define EQ_CLOCK_LIMIT_100  100
#define EQ_CLOCK_LIMIT_160  160
#define EQ_CLOCK_LIMIT_300  300
#define EQ_CLOCK_LIMIT_600  600
#define CLOCK_AEQ_ABOVE     EQ_CLOCK_LIMIT_300  /* above this the scan runs as AEQ (byte_0x8 = 1), else MEQ */

#define RESET_WHOLE_RECORD  5           /* mode of hdmi_eq_reset_port_record: clear all 0x898 bytes */
#define SETTLE_DELAY        10          /* timer_delay_long_units before the channels are released */

/* Registers of the three channels: each channel has the same set of registers at 0x1100 + 0x400 * ch, and a
   second set just below it at 0x1000 + 0x400 * ch. */
#define PHY_CH_REG(ch, reg)     (0x1100 + 0x400 * (ch) + (reg))
#define PHY_CH_LOW_REG(ch, reg) (0x1000 + 0x400 * (ch) + (reg))
#define CH_REG_CTRL         0x00        /* bit 21 cleared at the end of this step */
#define CH_REG_RVGA         0x28        /* bits 20..23: RVGA gain (the field Search_Process writes) */
#define CH_REG_34           0x34        /* bit 15 set before the RVGA gain is written */
#define CH_REG_70           0x70        /* bits 16..23: 0x2c in AEQ, 0x2f in MEQ */
#define CH_REG_EQ           0x78        /* RCT bits 0..3, CFT bits 8..23 */
#define CH_REG_7C           0x7c        /* bits 16..23: 0xff in AEQ, 0x4f in MEQ */
#define CH_REG_B0           0xb0        /* low byte set to 0xf8 */
#define CH_LOW_REG_04       0x04        /* bit 16 set at the end of this step */
#define CH_LOW_REG_1C       0x1c        /* bit 7 set, bits 1..2 by clock range; top byte of channel 0 = 0xbb */
#define CH_LOW_REG_20       0x20        /* bits 20..21 by clock range; top byte of channel 0 = 0xa2 (HDMI 2.1) */
#define RVGA_FIELD_MASK     0xff0fffff
#define RVGA_ENABLE_BIT     0x0f
#define CH_CTRL_BIT21       0x15
#define EQ_REG_KEEP         0xff0000f0  /* keep mask of the RCT/CFT write */
#define EQ_PAIR(rct, cft)   ((rct) | ((cft) << 8))      /* value of CH_REG_EQ */

/* The HDMI PHY record (24 bytes per PHY). */
struct hdmi_phy_record {
    unsigned char power;
    unsigned char eq_done;
    unsigned char eq_reset_request;
    unsigned char clock_detect;
    unsigned char byte_0x4[4];
    unsigned short phy_clock_mhz;       /* +8: printed 'Phy Clk*1 %dMHz' / 'Phy Clk*4 %dMHz' */
    unsigned char rest_0xa[0x18 - 0xa];
};

/* The scan state of one port (12 bytes per port). byte_0x8 set: AEQ, clear: MEQ (both printed here). */
struct eq_scan_record {
    unsigned int state;                 /* EQSCAN_STATE_*: the step hdmi_eq_run_scan_fsm runs next */
    unsigned char byte_0x4[3];
    unsigned char check_error_round;
    unsigned char byte_0x8;
    unsigned char pad[3];
};

/* The EQ scan work record of one port (0x898 bytes); only the first field is used here. */
struct eq_scan_channels {
    unsigned char eq_table_index[3];    /* per channel: the hdmi_eq_aeq_entries entry loaded in MEQ */
    unsigned char byte_0x3[0x898 - 3];
};
extern struct hdmi_phy_record hdmi_phy_records[];
extern struct eq_scan_record hdmi_eq_scan_records[];
extern unsigned int dbg_hdmi_message_flags;
extern unsigned char hdmi_eq_keep_results_flags[];
extern unsigned char hdmi_eq_zero_rct_flag;
extern struct eq_scan_channels hdmi_eq_port_records[];
extern unsigned char hdmi_eq_fixed_rct;
extern unsigned short hdmi_eq_fixed_cft;
extern unsigned char hdmi_eq_rct_try_indexes[];
extern unsigned char hdmi_eq_cft_try_indexes[];
extern unsigned int hdmi_eq_initial_rct_values[];
extern unsigned int hdmi_eq_initial_cft_values[];
extern unsigned char DAT_a0067058[];    /* "[EQ]: Port%c %s:" */
extern unsigned char DAT_a0067988[];    /* "[EQ]: Port%c,------- Force MEQ -------" */
extern int dbg_printf(const void *, ...);
extern int dbg_print_string(const char *);
extern unsigned char hdmi_is_hdmi21_phy(unsigned char);
extern unsigned char hdmi_eq_get_clock_ratio_mode(unsigned char);
extern void hdmi_phy_load_aeq_entry(unsigned char, unsigned char, unsigned char);
extern void hdmi_phy_write_bit(int, unsigned int, unsigned char, unsigned short);
extern void hdmi_phy_update_reg(unsigned int, unsigned short, unsigned int, unsigned int);
extern void timer_delay_long_units(unsigned short);
extern void hdmi_eq_reset_port_record(unsigned int, int);
extern void _hdmi_PHY_Set_CTLE(unsigned char);
extern void hdmi_phy_set_rate_fields(unsigned char);
extern void DRV_HDMI_PHY_Clr_EQ_Err(unsigned int);

/*
 * EQ scan state 4. The PI-CDR step (state 3) comes here, and the error check (state 11) comes back here to run
 * the scan as MEQ when an AEQ result shows RCT 0 on a channel.
 *
 *   port  HDMI receiver PHY (printed as the letter 'A' + port); PHYs 2 and 3 are the HDMI 2.1 receivers
 *         (hdmi_is_hdmi21_phy) and get their own values in several places
 *
 * Always returns 0 (hdmi_eq_run_scan_fsm stops until its next call) and leaves the scan in state 10.
 *
 * Register numbers below are those of channel 0; channels 1 and 2 have theirs 0x400 and 0x800 higher.
 *
 * Phases:
 *  1. RVGA gain of all channels: bits 20..23 of register 0x1128 = 0xf on an HDMI 2.1 PHY, else 3 (done
 *     twice, the second time after the top byte of register 0x101c is set to 0xbb); low byte of 0x11b0 =
 *     0xf8.
 *  2. AEQ or MEQ: AEQ (byte_0x8 = 1) when the PHY clock is above 300 MHz, else MEQ. Unless the recheck flag
 *     is set, the port's work record is cleared. hdmi_eq_zero_rct_flag (set by the error check) forces MEQ
 *     ("Force MEQ") and is cleared.
 *  3. Start values of the channels. AEQ: bits 16..23 of 0x1170 / 0x117c = 0x2c / 0xff and an RCT/CFT pair,
 *     on an HDMI 2.1 PHY the pair at each channel's try index (hdmi_eq_initial_rct_values / _cft_values),
 *     else hdmi_eq_fixed_rct / _cft. MEQ: 0x2f / 0x4f and the hdmi_eq_aeq_entries entry of each channel's
 *     eq_table_index (hdmi_phy_load_aeq_entry).
 *  4. Clock range: registers 0x101c (bits 1..2), 0x1178 (RCT/CFT) and 0x1020 (bits 20..21) of all channels,
 *     and on an HDMI 2.1 PHY the low half of 0x3614, by the PHY clock: below 100, below 160, below 300, up
 *     to 600 MHz (with hdmi_eq_get_clock_ratio_mode 0 the values of the range below 300, print
 *     "LABEL_HDMI14_MODE"); above 600 nothing ("out clk range"). Every range up to 600 writes its own RCT/CFT
 *     pair over the one of phase 3.
 *  5. HDMI 2.1 PHY only: a fixed set of the registers 0x3604..0x3620, the top byte of 0x1020 and 0x23c0 /
 *     0x27c0 / 0x2bc0 / 0x33c0 (the 0x3614 low half written in phase 4 is cleared here).
 *  6. Release: set bit 16 of 0x1004 of all channels, _hdmi_PHY_Set_CTLE, on an HDMI 2.1 PHY
 *     hdmi_phy_set_rate_fields, wait, clear bit 21 of the channel control registers (0x1100), clear the
 *     error counters and go to the pre-check step (state 10).
 */
int DRV_HDMI_EQScan_FSM_PHY_EQ(unsigned char port)
{
    unsigned short clock = hdmi_phy_records[port].phy_clock_mhz;
    unsigned char is_hdmi21;

    if ((dbg_hdmi_message_flags & HDMI_MSG_EQ_FLOW) != 0)
        dbg_printf(DAT_a0067058, (char)(port + 'A'), "DRV_HDMI_EQScan_FSM_PHY_EQ");

    /* Phase 1: RVGA gain and register 0x1b0 of the three channels. */
    hdmi_phy_write_bit(1, RVGA_ENABLE_BIT, port, PHY_CH_REG(0, CH_REG_34));
    hdmi_phy_write_bit(1, RVGA_ENABLE_BIT, port, PHY_CH_REG(1, CH_REG_34));
    hdmi_phy_write_bit(1, RVGA_ENABLE_BIT, port, PHY_CH_REG(2, CH_REG_34));
    if (hdmi_is_hdmi21_phy(port)) {
        hdmi_phy_update_reg(port, PHY_CH_REG(0, CH_REG_RVGA), RVGA_FIELD_MASK, 0xf00000);
        hdmi_phy_update_reg(port, PHY_CH_REG(1, CH_REG_RVGA), RVGA_FIELD_MASK, 0xf00000);
        hdmi_phy_update_reg(port, PHY_CH_REG(2, CH_REG_RVGA), RVGA_FIELD_MASK, 0xf00000);
    } else {
        hdmi_phy_update_reg(port, PHY_CH_REG(0, CH_REG_RVGA), RVGA_FIELD_MASK, 0x300000);
        hdmi_phy_update_reg(port, PHY_CH_REG(1, CH_REG_RVGA), RVGA_FIELD_MASK, 0x300000);
        hdmi_phy_update_reg(port, PHY_CH_REG(2, CH_REG_RVGA), RVGA_FIELD_MASK, 0x300000);
    }
    hdmi_phy_update_reg(port, PHY_CH_REG(0, CH_REG_B0), 0xffffff00, 0xf8);
    hdmi_phy_update_reg(port, PHY_CH_REG(1, CH_REG_B0), 0xffffff00, 0xf8);
    hdmi_phy_update_reg(port, PHY_CH_REG(2, CH_REG_B0), 0xffffff00, 0xf8);
    if (hdmi_is_hdmi21_phy(port)) {
        hdmi_phy_update_reg(port, PHY_CH_LOW_REG(0, CH_LOW_REG_1C), 0xffffff, 0xbb000000);
        hdmi_phy_write_bit(1, RVGA_ENABLE_BIT, port, PHY_CH_REG(0, CH_REG_34));
        hdmi_phy_update_reg(port, PHY_CH_REG(0, CH_REG_RVGA), RVGA_FIELD_MASK, 0xf00000);
        hdmi_phy_write_bit(1, RVGA_ENABLE_BIT, port, PHY_CH_REG(1, CH_REG_34));
        hdmi_phy_update_reg(port, PHY_CH_REG(1, CH_REG_RVGA), RVGA_FIELD_MASK, 0xf00000);
        hdmi_phy_write_bit(1, RVGA_ENABLE_BIT, port, PHY_CH_REG(2, CH_REG_34));
        hdmi_phy_update_reg(port, PHY_CH_REG(2, CH_REG_RVGA), RVGA_FIELD_MASK, 0xf00000);
    } else {
        hdmi_phy_update_reg(port, PHY_CH_LOW_REG(0, CH_LOW_REG_1C), 0xffffff, 0xbb000000);
        hdmi_phy_write_bit(1, RVGA_ENABLE_BIT, port, PHY_CH_REG(0, CH_REG_34));
        hdmi_phy_update_reg(port, PHY_CH_REG(0, CH_REG_RVGA), RVGA_FIELD_MASK, 0x300000);
        hdmi_phy_write_bit(1, RVGA_ENABLE_BIT, port, PHY_CH_REG(1, CH_REG_34));
        hdmi_phy_update_reg(port, PHY_CH_REG(1, CH_REG_RVGA), RVGA_FIELD_MASK, 0x300000);
        hdmi_phy_write_bit(1, RVGA_ENABLE_BIT, port, PHY_CH_REG(2, CH_REG_34));
        hdmi_phy_update_reg(port, PHY_CH_REG(2, CH_REG_RVGA), RVGA_FIELD_MASK, 0x300000);
    }

    /* Phase 2: AEQ above 300 MHz, MEQ below. */
    if (clock > CLOCK_AEQ_ABOVE)
        hdmi_eq_scan_records[port].byte_0x8 = 1;
    else
        hdmi_eq_scan_records[port].byte_0x8 = 0;
    if (hdmi_eq_keep_results_flags[port] == 0)
        hdmi_eq_reset_port_record(port, RESET_WHOLE_RECORD);
    if (hdmi_eq_zero_rct_flag != 0) {
        if ((dbg_hdmi_message_flags & HDMI_MSG_EQ_FLOW) != 0)
            dbg_printf(DAT_a0067988, (char)(port + 'A'));
        hdmi_eq_scan_records[port].byte_0x8 = 0;
        hdmi_eq_zero_rct_flag = 0;
    }

    /* Phase 3: start values of the channels. */
    if (hdmi_eq_scan_records[port].byte_0x8 == 1) {
        if ((dbg_hdmi_message_flags & HDMI_MSG_EQ_FLOW) != 0)
            dbg_printf("[EQ]: # Port%c,------- AEQ ------- \n", (char)(port + 'A'));
        hdmi_phy_update_reg(port, PHY_CH_REG(0, CH_REG_70), 0xff00ffff, 0x2c0000);
        hdmi_phy_update_reg(port, PHY_CH_REG(1, CH_REG_70), 0xff00ffff, 0x2c0000);
        hdmi_phy_update_reg(port, PHY_CH_REG(2, CH_REG_70), 0xff00ffff, 0x2c0000);
        hdmi_phy_update_reg(port, PHY_CH_REG(0, CH_REG_7C), 0xff00ffff, 0xff0000);
        hdmi_phy_update_reg(port, PHY_CH_REG(1, CH_REG_7C), 0xff00ffff, 0xff0000);
        hdmi_phy_update_reg(port, PHY_CH_REG(2, CH_REG_7C), 0xff00ffff, 0xff0000);
        if (hdmi_is_hdmi21_phy(port)) {
            hdmi_phy_update_reg(port, PHY_CH_REG(0, CH_REG_EQ), EQ_REG_KEEP,
                         (hdmi_eq_initial_rct_values[hdmi_eq_rct_try_indexes[0]] & 0xf) | ((hdmi_eq_initial_cft_values[hdmi_eq_cft_try_indexes[0]] & 0xffff) << 8));
            hdmi_phy_update_reg(port, PHY_CH_REG(1, CH_REG_EQ), EQ_REG_KEEP,
                         (hdmi_eq_initial_rct_values[hdmi_eq_rct_try_indexes[1]] & 0xf) | ((hdmi_eq_initial_cft_values[hdmi_eq_cft_try_indexes[1]] & 0xffff) << 8));
            hdmi_phy_update_reg(port, PHY_CH_REG(2, CH_REG_EQ), EQ_REG_KEEP,
                         (hdmi_eq_initial_rct_values[hdmi_eq_rct_try_indexes[2]] & 0xf) | ((hdmi_eq_initial_cft_values[hdmi_eq_cft_try_indexes[2]] & 0xffff) << 8));
            if ((dbg_hdmi_message_flags & HDMI_MSG_EQ_FLOW) != 0)
                dbg_printf("[EQ]: Init value RX2&3 : RCT 0x%02lx, CFT 0x%04lx \n\n", hdmi_eq_initial_rct_values[hdmi_eq_rct_try_indexes[0]], hdmi_eq_initial_cft_values[hdmi_eq_cft_try_indexes[0]]);
        } else {
            hdmi_phy_update_reg(port, PHY_CH_REG(0, CH_REG_EQ), EQ_REG_KEEP, (hdmi_eq_fixed_rct & 0xf) | (hdmi_eq_fixed_cft << 8));
            hdmi_phy_update_reg(port, PHY_CH_REG(1, CH_REG_EQ), EQ_REG_KEEP, (hdmi_eq_fixed_rct & 0xf) | (hdmi_eq_fixed_cft << 8));
            hdmi_phy_update_reg(port, PHY_CH_REG(2, CH_REG_EQ), EQ_REG_KEEP, (hdmi_eq_fixed_rct & 0xf) | (hdmi_eq_fixed_cft << 8));
            if ((dbg_hdmi_message_flags & HDMI_MSG_EQ_FLOW) != 0)
                dbg_printf("[EQ]: Init value RX0&1 : RCT 0x%02x, CFT 0x%04x \n\n", hdmi_eq_fixed_rct, hdmi_eq_fixed_cft);
        }
    } else {
        if ((dbg_hdmi_message_flags & HDMI_MSG_EQ_FLOW) != 0)
            dbg_printf("[EQ]: # Port%c,------- MEQ ------- \n\n", (char)(port + 'A'));
        hdmi_phy_update_reg(port, PHY_CH_REG(0, CH_REG_70), 0xff00ffff, 0x2f0000);
        hdmi_phy_update_reg(port, PHY_CH_REG(1, CH_REG_70), 0xff00ffff, 0x2f0000);
        hdmi_phy_update_reg(port, PHY_CH_REG(2, CH_REG_70), 0xff00ffff, 0x2f0000);
        hdmi_phy_update_reg(port, PHY_CH_REG(0, CH_REG_7C), 0xff00ffff, 0x4f0000);
        hdmi_phy_update_reg(port, PHY_CH_REG(1, CH_REG_7C), 0xff00ffff, 0x4f0000);
        hdmi_phy_update_reg(port, PHY_CH_REG(2, CH_REG_7C), 0xff00ffff, 0x4f0000);
        hdmi_phy_load_aeq_entry(port, 0, hdmi_eq_port_records[port].eq_table_index[0]);
        hdmi_phy_load_aeq_entry(port, 1, hdmi_eq_port_records[port].eq_table_index[1]);
        hdmi_phy_load_aeq_entry(port, 2, hdmi_eq_port_records[port].eq_table_index[2]);
    }

    /* Phase 4: register values by clock range. */
    if (clock < EQ_CLOCK_LIMIT_100) {
        if (!hdmi_is_hdmi21_phy(port)) {
            hdmi_phy_write_bit(1, 7, port, PHY_CH_LOW_REG(0, CH_LOW_REG_1C));
            hdmi_phy_write_bit(1, 7, port, PHY_CH_LOW_REG(1, CH_LOW_REG_1C));
            hdmi_phy_write_bit(1, 7, port, PHY_CH_LOW_REG(2, CH_LOW_REG_1C));
            hdmi_phy_update_reg(port, PHY_CH_LOW_REG(0, CH_LOW_REG_1C), 0xfffffff9, 2);
            hdmi_phy_update_reg(port, PHY_CH_LOW_REG(1, CH_LOW_REG_1C), 0xfffffff9, 2);
            hdmi_phy_update_reg(port, PHY_CH_LOW_REG(2, CH_LOW_REG_1C), 0xfffffff9, 2);
            hdmi_phy_update_reg(port, PHY_CH_REG(0, CH_REG_EQ), EQ_REG_KEEP, EQ_PAIR(8, 0xff));
            hdmi_phy_update_reg(port, PHY_CH_REG(1, CH_REG_EQ), EQ_REG_KEEP, EQ_PAIR(8, 0xff));
            hdmi_phy_update_reg(port, PHY_CH_REG(2, CH_REG_EQ), EQ_REG_KEEP, EQ_PAIR(8, 0xff));
            hdmi_phy_update_reg(port, PHY_CH_LOW_REG(0, CH_LOW_REG_20), 0xffcfffff, 0x100000);
            hdmi_phy_update_reg(port, PHY_CH_LOW_REG(1, CH_LOW_REG_20), 0xffcfffff, 0x100000);
            hdmi_phy_update_reg(port, PHY_CH_LOW_REG(2, CH_LOW_REG_20), 0xffcfffff, 0x100000);
        } else {
            hdmi_phy_update_reg(port, PHY_CH_REG(0, CH_REG_EQ), EQ_REG_KEEP, EQ_PAIR(8, 0xff));
            hdmi_phy_update_reg(port, PHY_CH_REG(1, CH_REG_EQ), EQ_REG_KEEP, EQ_PAIR(8, 0xff));
            hdmi_phy_update_reg(port, PHY_CH_REG(2, CH_REG_EQ), EQ_REG_KEEP, EQ_PAIR(8, 0xff));
            hdmi_phy_write_bit(1, 7, port, PHY_CH_LOW_REG(0, CH_LOW_REG_1C));
            hdmi_phy_write_bit(1, 7, port, PHY_CH_LOW_REG(1, CH_LOW_REG_1C));
            hdmi_phy_write_bit(1, 7, port, PHY_CH_LOW_REG(2, CH_LOW_REG_1C));
            hdmi_phy_update_reg(port, PHY_CH_LOW_REG(0, CH_LOW_REG_1C), 0xfffffff9, 2);
            hdmi_phy_update_reg(port, PHY_CH_LOW_REG(1, CH_LOW_REG_1C), 0xfffffff9, 2);
            hdmi_phy_update_reg(port, PHY_CH_LOW_REG(2, CH_LOW_REG_1C), 0xfffffff9, 2);
            hdmi_phy_update_reg(port, PHY_CH_LOW_REG(0, CH_LOW_REG_20), 0xffcfffff, 0x100000);
            hdmi_phy_update_reg(port, PHY_CH_LOW_REG(1, CH_LOW_REG_20), 0xffcfffff, 0x100000);
            hdmi_phy_update_reg(port, PHY_CH_LOW_REG(2, CH_LOW_REG_20), 0xffcfffff, 0x100000);
            hdmi_phy_update_reg(port, 0x3614, 0xffff0000, 0x160);
        }
    } else if (clock < EQ_CLOCK_LIMIT_160) {
        if (hdmi_is_hdmi21_phy(port)) {
            hdmi_phy_update_reg(port, PHY_CH_REG(0, CH_REG_EQ), EQ_REG_KEEP, EQ_PAIR(8, 0xff));
            hdmi_phy_update_reg(port, PHY_CH_REG(1, CH_REG_EQ), EQ_REG_KEEP, EQ_PAIR(8, 0xff));
            hdmi_phy_update_reg(port, PHY_CH_REG(2, CH_REG_EQ), EQ_REG_KEEP, EQ_PAIR(8, 0xff));
            hdmi_phy_write_bit(1, 7, port, PHY_CH_LOW_REG(0, CH_LOW_REG_1C));
            hdmi_phy_write_bit(1, 7, port, PHY_CH_LOW_REG(1, CH_LOW_REG_1C));
            hdmi_phy_write_bit(1, 7, port, PHY_CH_LOW_REG(2, CH_LOW_REG_1C));
            hdmi_phy_update_reg(port, PHY_CH_LOW_REG(0, CH_LOW_REG_1C), 0xfffffff9, 4);
            hdmi_phy_update_reg(port, PHY_CH_LOW_REG(1, CH_LOW_REG_1C), 0xfffffff9, 4);
            hdmi_phy_update_reg(port, PHY_CH_LOW_REG(2, CH_LOW_REG_1C), 0xfffffff9, 4);
            hdmi_phy_update_reg(port, PHY_CH_LOW_REG(0, CH_LOW_REG_20), 0xffcfffff, 0x100000);
            hdmi_phy_update_reg(port, PHY_CH_LOW_REG(1, CH_LOW_REG_20), 0xffcfffff, 0x100000);
            hdmi_phy_update_reg(port, PHY_CH_LOW_REG(2, CH_LOW_REG_20), 0xffcfffff, 0x100000);
            hdmi_phy_update_reg(port, 0x3614, 0xffff0000, 0x4444);
        } else {
            hdmi_phy_write_bit(1, 7, port, PHY_CH_LOW_REG(0, CH_LOW_REG_1C));
            hdmi_phy_write_bit(1, 7, port, PHY_CH_LOW_REG(1, CH_LOW_REG_1C));
            hdmi_phy_write_bit(1, 7, port, PHY_CH_LOW_REG(2, CH_LOW_REG_1C));
            hdmi_phy_update_reg(port, PHY_CH_LOW_REG(0, CH_LOW_REG_1C), 0xfffffff9, 6);
            hdmi_phy_update_reg(port, PHY_CH_LOW_REG(1, CH_LOW_REG_1C), 0xfffffff9, 6);
            hdmi_phy_update_reg(port, PHY_CH_LOW_REG(2, CH_LOW_REG_1C), 0xfffffff9, 6);
            hdmi_phy_update_reg(port, PHY_CH_REG(0, CH_REG_EQ), EQ_REG_KEEP, EQ_PAIR(8, 0xff));
            hdmi_phy_update_reg(port, PHY_CH_REG(1, CH_REG_EQ), EQ_REG_KEEP, EQ_PAIR(8, 0xff));
            hdmi_phy_update_reg(port, PHY_CH_REG(2, CH_REG_EQ), EQ_REG_KEEP, EQ_PAIR(8, 0xff));
            hdmi_phy_update_reg(port, PHY_CH_LOW_REG(0, CH_LOW_REG_20), 0xffcfffff, 0x100000);
            hdmi_phy_update_reg(port, PHY_CH_LOW_REG(1, CH_LOW_REG_20), 0xffcfffff, 0x100000);
            hdmi_phy_update_reg(port, PHY_CH_LOW_REG(2, CH_LOW_REG_20), 0xffcfffff, 0x100000);
        }
    } else if (clock < EQ_CLOCK_LIMIT_300) {
range_3:
        if (!hdmi_is_hdmi21_phy(port)) {
            hdmi_phy_write_bit(1, 7, port, PHY_CH_LOW_REG(0, CH_LOW_REG_1C));
            hdmi_phy_write_bit(1, 7, port, PHY_CH_LOW_REG(1, CH_LOW_REG_1C));
            hdmi_phy_write_bit(1, 7, port, PHY_CH_LOW_REG(2, CH_LOW_REG_1C));
            hdmi_phy_update_reg(port, PHY_CH_LOW_REG(0, CH_LOW_REG_1C), 0xfffffff9, 6);
            hdmi_phy_update_reg(port, PHY_CH_LOW_REG(1, CH_LOW_REG_1C), 0xfffffff9, 6);
            hdmi_phy_update_reg(port, PHY_CH_LOW_REG(2, CH_LOW_REG_1C), 0xfffffff9, 6);
            hdmi_phy_update_reg(port, PHY_CH_REG(0, CH_REG_EQ), EQ_REG_KEEP, EQ_PAIR(8, 0xff));
            hdmi_phy_update_reg(port, PHY_CH_REG(1, CH_REG_EQ), EQ_REG_KEEP, EQ_PAIR(8, 0xff));
            hdmi_phy_update_reg(port, PHY_CH_REG(2, CH_REG_EQ), EQ_REG_KEEP, EQ_PAIR(8, 0xff));
            hdmi_phy_update_reg(port, PHY_CH_LOW_REG(0, CH_LOW_REG_20), 0xffcfffff, 0x100000);
            hdmi_phy_update_reg(port, PHY_CH_LOW_REG(1, CH_LOW_REG_20), 0xffcfffff, 0x100000);
            hdmi_phy_update_reg(port, PHY_CH_LOW_REG(2, CH_LOW_REG_20), 0xffcfffff, 0x100000);
        } else {
            hdmi_phy_update_reg(port, PHY_CH_REG(0, CH_REG_EQ), EQ_REG_KEEP, EQ_PAIR(8, 0xff));
            hdmi_phy_update_reg(port, PHY_CH_REG(1, CH_REG_EQ), EQ_REG_KEEP, EQ_PAIR(8, 0xff));
            hdmi_phy_update_reg(port, PHY_CH_REG(2, CH_REG_EQ), EQ_REG_KEEP, EQ_PAIR(8, 0xff));
            hdmi_phy_write_bit(1, 7, port, PHY_CH_LOW_REG(0, CH_LOW_REG_1C));
            hdmi_phy_write_bit(1, 7, port, PHY_CH_LOW_REG(1, CH_LOW_REG_1C));
            hdmi_phy_write_bit(1, 7, port, PHY_CH_LOW_REG(2, CH_LOW_REG_1C));
            hdmi_phy_update_reg(port, PHY_CH_LOW_REG(0, CH_LOW_REG_1C), 0xfffffff9, 4);
            hdmi_phy_update_reg(port, PHY_CH_LOW_REG(1, CH_LOW_REG_1C), 0xfffffff9, 4);
            hdmi_phy_update_reg(port, PHY_CH_LOW_REG(2, CH_LOW_REG_1C), 0xfffffff9, 4);
            hdmi_phy_update_reg(port, PHY_CH_LOW_REG(0, CH_LOW_REG_20), 0xffcfffff, 0x100000);
            hdmi_phy_update_reg(port, PHY_CH_LOW_REG(1, CH_LOW_REG_20), 0xffcfffff, 0x100000);
            hdmi_phy_update_reg(port, PHY_CH_LOW_REG(2, CH_LOW_REG_20), 0xffcfffff, 0x100000);
            hdmi_phy_update_reg(port, 0x3614, 0xffff0000, 0x60);
        }
    } else if (clock <= EQ_CLOCK_LIMIT_600) {
        if (!hdmi_eq_get_clock_ratio_mode(port)) {
            /* Clock ratio mode 0: the values of the range below 300 MHz. */
            if ((dbg_hdmi_message_flags & HDMI_MSG_EQ_FLOW) != 0)
                dbg_print_string("[EQ]: \nLABEL_HDMI14_MODE");
            goto range_3;
        } else {
            if (!hdmi_is_hdmi21_phy(port)) {
                hdmi_phy_write_bit(1, 7, port, PHY_CH_LOW_REG(0, CH_LOW_REG_1C));
                hdmi_phy_write_bit(1, 7, port, PHY_CH_LOW_REG(1, CH_LOW_REG_1C));
                hdmi_phy_write_bit(1, 7, port, PHY_CH_LOW_REG(2, CH_LOW_REG_1C));
                hdmi_phy_update_reg(port, PHY_CH_LOW_REG(0, CH_LOW_REG_1C), 0xfffffff9, 6);
                hdmi_phy_update_reg(port, PHY_CH_LOW_REG(1, CH_LOW_REG_1C), 0xfffffff9, 6);
                hdmi_phy_update_reg(port, PHY_CH_LOW_REG(2, CH_LOW_REG_1C), 0xfffffff9, 6);
                hdmi_phy_update_reg(port, PHY_CH_REG(0, CH_REG_EQ), EQ_REG_KEEP, EQ_PAIR(8, 0xfff));
                hdmi_phy_update_reg(port, PHY_CH_REG(1, CH_REG_EQ), EQ_REG_KEEP, EQ_PAIR(8, 0xfff));
                hdmi_phy_update_reg(port, PHY_CH_REG(2, CH_REG_EQ), EQ_REG_KEEP, EQ_PAIR(8, 0xfff));
                hdmi_phy_update_reg(port, PHY_CH_LOW_REG(0, CH_LOW_REG_20), 0xffcfffff, 0x300000);
                hdmi_phy_update_reg(port, PHY_CH_LOW_REG(1, CH_LOW_REG_20), 0xffcfffff, 0x300000);
                hdmi_phy_update_reg(port, PHY_CH_LOW_REG(2, CH_LOW_REG_20), 0xffcfffff, 0x300000);
            } else {
                hdmi_phy_update_reg(port, PHY_CH_REG(0, CH_REG_EQ), EQ_REG_KEEP, EQ_PAIR(3, 3));
                hdmi_phy_update_reg(port, PHY_CH_REG(1, CH_REG_EQ), EQ_REG_KEEP, EQ_PAIR(3, 3));
                hdmi_phy_update_reg(port, PHY_CH_REG(2, CH_REG_EQ), EQ_REG_KEEP, EQ_PAIR(3, 3));
                hdmi_phy_write_bit(1, 7, port, PHY_CH_LOW_REG(0, CH_LOW_REG_1C));
                hdmi_phy_write_bit(1, 7, port, PHY_CH_LOW_REG(1, CH_LOW_REG_1C));
                hdmi_phy_write_bit(1, 7, port, PHY_CH_LOW_REG(2, CH_LOW_REG_1C));
                hdmi_phy_update_reg(port, PHY_CH_LOW_REG(0, CH_LOW_REG_1C), 0xfffffff9, 4);
                hdmi_phy_update_reg(port, PHY_CH_LOW_REG(1, CH_LOW_REG_1C), 0xfffffff9, 4);
                hdmi_phy_update_reg(port, PHY_CH_LOW_REG(2, CH_LOW_REG_1C), 0xfffffff9, 4);
                hdmi_phy_update_reg(port, PHY_CH_LOW_REG(0, CH_LOW_REG_20), 0xffcfffff, 0x100000);
                hdmi_phy_update_reg(port, PHY_CH_LOW_REG(1, CH_LOW_REG_20), 0xffcfffff, 0x100000);
                hdmi_phy_update_reg(port, PHY_CH_LOW_REG(2, CH_LOW_REG_20), 0xffcfffff, 0x100000);
            }
        }
    } else {
        if ((dbg_hdmi_message_flags & HDMI_MSG_EQ_FLOW) != 0)
            dbg_print_string("[EQ]: HDMI Mode : out clk range!!!");
    }

    /* Phase 5: the fixed HDMI 2.1 set. */
    is_hdmi21 = hdmi_is_hdmi21_phy(port);
    if (is_hdmi21) {
        hdmi_phy_update_reg(port, 0x3614, 0xffffff00, 0);
        hdmi_phy_update_reg(port, 0x3614, 0xffff00ff, 0);
        hdmi_phy_update_reg(port, 0x360c, 0xffff0000, 0x83d0);
        hdmi_phy_update_reg(port, 0x360c, 0xffff, 0x83d00000);
        hdmi_phy_update_reg(port, 0x3610, 0xffff0000, 0x83d0);
        hdmi_phy_update_reg(port, 0x3610, 0xffff, 0x83d00000);
        hdmi_phy_update_reg(port, 0x3614, 0xff00ffff, 0x7c0000);
        hdmi_phy_update_reg(port, 0x3614, 0xffffff, 0xff000000);
        hdmi_phy_update_reg(port, 0x3618, 0xffffff00, 0xff);
        hdmi_phy_update_reg(port, 0x3620, 0xffffff00, 0);
        hdmi_phy_update_reg(port, 0x3620, 0xffff00ff, 0x100);
        hdmi_phy_write_bit(0, 0x1b, port, 0x3604);
        hdmi_phy_update_reg(port, PHY_CH_LOW_REG(0, CH_LOW_REG_20), 0xffffff, 0xa2000000);
        hdmi_phy_update_reg(port, 0x23c0, 0xffff00ff, 0x5000);
        hdmi_phy_update_reg(port, 0x27c0, 0xffff00ff, 0x1000);
        hdmi_phy_update_reg(port, 0x2bc0, 0xffff00ff, 0x1000);
        hdmi_phy_update_reg(port, 0x33c0, 0xffff00ff, 0x1000);
    }

    /* Phase 6: release the channels and hand over to the pre-check step. */
    hdmi_phy_write_bit(1, 0x10, port, PHY_CH_LOW_REG(0, CH_LOW_REG_04));
    hdmi_phy_write_bit(1, 0x10, port, PHY_CH_LOW_REG(1, CH_LOW_REG_04));
    hdmi_phy_write_bit(1, 0x10, port, PHY_CH_LOW_REG(2, CH_LOW_REG_04));
    _hdmi_PHY_Set_CTLE(port);
    if (is_hdmi21)
        hdmi_phy_set_rate_fields(port);
    timer_delay_long_units(SETTLE_DELAY);
    hdmi_phy_write_bit(0, CH_CTRL_BIT21, port, PHY_CH_REG(2, CH_REG_CTRL));
    hdmi_phy_write_bit(0, CH_CTRL_BIT21, port, PHY_CH_REG(1, CH_REG_CTRL));
    hdmi_phy_write_bit(0, CH_CTRL_BIT21, port, PHY_CH_REG(0, CH_REG_CTRL));
    DRV_HDMI_PHY_Clr_EQ_Err(port);
    if (hdmi_eq_scan_records[port].byte_0x8)
        hdmi_eq_scan_records[port].state = EQSCAN_STATE_PRE_CHKERROR;
    else
        hdmi_eq_scan_records[port].state = EQSCAN_STATE_PRE_CHKERROR;
    return 0;
}
