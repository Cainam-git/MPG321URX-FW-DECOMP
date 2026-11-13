/* DRV_HDMI_EQScan_FSM_PHY_PreChkError  (DRV_HDMI_EQScan_FSM_PHY_PreChkError)
 *
 * EQ scan step: raise the PHY's IVCO value by one when the level byte is high, then set the next state.
 *   port: PHY
 * Note: State function of the EQ scan table run by hdmi_eq_run_scan_fsm. The raise is undone when the low byte
 *   of PHY register 0x1018 then reads 0x1F or less.
 * Name basis: proven - original name printed: 'DRV_HDMI_EQScan_FSM_PHY_PreChkError'
 *
 * Matching notes
 * --------------
 * leon2s DRV_HDMI_EQScan_FSM_PHY_PreChkError @ 0xa007796c-0xa0077e68 (1276 bytes), flags -mcpu=v8 -Os -g
 * (section default).
 * Source forms the exact build depends on:
 *  - ivco is an unsigned int that is copied into the unsigned char ivco_saved before its print and test;
 *  - the raised value ivco_next is an unsigned char set in an if/else (as an unsigned int the compiler
 *    turns it into addx arithmetic).
 */
extern unsigned int dbg_hdmi_message_flags;
extern unsigned char DAT_a0066b30[];
extern unsigned char DAT_a0066b58[];
extern unsigned char DAT_a0067290[];
extern unsigned char DAT_a00672c0[];
extern unsigned char DAT_a00672f0[];
extern unsigned char DAT_a0067318[];
extern unsigned char DAT_a0067358[];
extern unsigned char DAT_a0067388[];
extern unsigned char DAT_a0067398[];
extern unsigned char DAT_a00673d0[];
extern int dbg_printf(const void *, ...);
extern unsigned int hdmi_phy_read_reg(unsigned int, unsigned short);
extern void hdmi_phy_write_bit(int, unsigned int, unsigned char, unsigned short);
extern void hdmi_phy_update_reg(unsigned int, unsigned short, unsigned int, unsigned int);
extern void timer_delay_long_units(int);
extern unsigned int timer_get_ticks(void);

#define HDMI_MSG_EQ_FLOW 0x02           /* bit of dbg_hdmi_message_flags: the "[EQ]" lines */

/* States of the EQ scan (index into hdmi_eq_scan_state_handlers). */
#define EQSCAN_STATE_PHY_INIT   0       /* FSM_EQSCAN_PHY_INIT */
#define EQSCAN_STATE_PRE_RVGA   6       /* DRV_HDMI_EQScan_FSM_PHY_PreRVGA */
#define EQSCAN_STATE_CHKERROR   0x0b    /* DRV_HDMI_EQScan_FSM_PHY_ChkError */

/* PHY registers. The three channels have the same registers at 0x1100 + 0x400 * channel + offset. */
#define PHY_CH_REG(ch, reg) (0x1100 + 0x400 * (ch) + (reg))
#define CH_REG_CTRL         0x00        /* bit 21 is set before and cleared after each rewrite of CH_REG_68 */
#define CH_CTRL_BIT21       0x15
#define CH_REG_48           0x48        /* bits 16..19, printed per channel ("Ch0" .. "Ch2") */
#define CH_FIELD_FULL       0xf         /* value of those bits when the channel passes */
#define CH_REG_68           0x68        /* channel 0 only here: bits 4..7 hold the IVCO value read, bits 8..11 the one written, bit 13 is set while forced */
#define PHY_REG_1018        0x1018      /* low byte compared with the two limits below */
#define REG_1018_HIGH       0xdf
#define REG_1018_LOW        0x1f
#define PHY_REG_SRC_SETTING 0x11f0      /* low byte printed ("SRC setting 0x11F0?") */
#define PHY_REG_SRC_FREQ    0x11f4      /* bits 16..31 printed as "SRC Freq", bits 12..15 as "calibrated ICDR_SEL value 0x11F5" */
#define IVCO_FORCE_BIT      0xd         /* printed as "FORCE IVCO SEL" */
#define IVCO_MAX            0xf
#define IVCO_KEEP_MASK      0xfffff0ff  /* keeps all of 0x1168 except bits 8..11 */
#define IVCO_SETTLE_UNITS   5           /* timer_delay_long_units argument after the raise */

/* The scan state of one port (12 bytes per port, table at 0xA807CCC4). */
struct eq_scan_record {
    unsigned int state;                 /* EQSCAN_STATE_*: the step hdmi_eq_run_scan_fsm runs next */
    unsigned int word_0x4;
    unsigned char byte_0x8;             /* 1: AEQ scan (see ChkError) */
    unsigned char pad[3];
};
/* The EQ scan work record of one port (0x898 bytes); only wait_count is used here. */
struct eq_scan_channels {
    unsigned char bytes_0x0[0x30];
    unsigned char wait_count;           /* passes of a waiting step so far */
    unsigned char rest_0x31[0x898 - 0x31];
};
extern struct eq_scan_record hdmi_eq_scan_records[];
extern struct eq_scan_channels hdmi_eq_port_records[];
extern unsigned char hdmi_eq_wait_passes[];

/*
 * EQ scan state 10: the step before ChkError. It prints the three channel registers and the source
 * setting, then decides whether the scan goes on (step_done) and sets the next state:
 *  1. step_done = 1 when bits 16..19 of the channel registers 0x1148 / 0x1548 / 0x1948 all read 0xf.
 *  2. When the low byte of register 0x1018 is above 0xdf, step_done = 1 as well and the IVCO setting
 *     (bits 4..7 of 0x1168) is raised by one (not above 0xf): written to bits 8..11 of 0x1168 with bit 13
 *     ("FORCE IVCO SEL") set, around which bit 21 of 0x1100 / 0x1500 / 0x1900 is set and cleared. After the
 *     wait, if the low byte of 0x1018 is at most 0x1f the original value is written back and bit 13
 *     cleared ("Revert").
 *  3. step_done: pre_aeq_flags[port] = 6, wait_count = 0 and the next state is ChkError for an AEQ scan
 *     (scan record byte +8 is 1; the tick count is printed), PreRVGA otherwise.
 *     Not step_done: the scan goes back to PHY_INIT.
 * Always returns 0: the scan runs the next state on its next call.
 *   port: PHY index (the letter in the prints is 'A' + port)
 */
int DRV_HDMI_EQScan_FSM_PHY_PreChkError(unsigned char port)
{
    unsigned char step_done = 0;
    unsigned int ivco;
    unsigned char ivco_saved;
    unsigned char ivco_next;

    if ((dbg_hdmi_message_flags & HDMI_MSG_EQ_FLOW) != 0)
        dbg_printf(DAT_a0066b30, (char)(port + 'A'), "DRV_HDMI_EQScan_FSM_PHY_PreChkError",
                     hdmi_phy_read_reg(port, PHY_CH_REG(0, CH_REG_48)) >> 16 & 0xf);
    if ((dbg_hdmi_message_flags & HDMI_MSG_EQ_FLOW) != 0)
        dbg_printf(DAT_a0066b58, (char)(port + 'A'), "DRV_HDMI_EQScan_FSM_PHY_PreChkError",
                     hdmi_phy_read_reg(port, PHY_CH_REG(1, CH_REG_48)) >> 16 & 0xf);
    if ((dbg_hdmi_message_flags & HDMI_MSG_EQ_FLOW) != 0)
        dbg_printf(DAT_a0067290, (char)(port + 'A'), "DRV_HDMI_EQScan_FSM_PHY_PreChkError",
                     hdmi_phy_read_reg(port, PHY_CH_REG(2, CH_REG_48)) >> 16 & 0xf);
    if ((dbg_hdmi_message_flags & HDMI_MSG_EQ_FLOW) != 0)
        dbg_printf(DAT_a00672c0, (char)(port + 'A'), hdmi_phy_read_reg(port, PHY_REG_SRC_SETTING) & 0xff);
    if ((dbg_hdmi_message_flags & HDMI_MSG_EQ_FLOW) != 0)
        dbg_printf(DAT_a00672f0, (char)(port + 'A'), hdmi_phy_read_reg(port, PHY_REG_SRC_FREQ) >> 16);
    if ((dbg_hdmi_message_flags & HDMI_MSG_EQ_FLOW) != 0)
        dbg_printf(DAT_a0067318, (char)(port + 'A'), hdmi_phy_read_reg(port, PHY_REG_SRC_FREQ) >> 12 & 0xf);

    if ((hdmi_phy_read_reg(port, PHY_CH_REG(0, CH_REG_48)) >> 16 & 0xf) == CH_FIELD_FULL &&
        (hdmi_phy_read_reg(port, PHY_CH_REG(1, CH_REG_48)) >> 16 & 0xf) == CH_FIELD_FULL &&
        (hdmi_phy_read_reg(port, PHY_CH_REG(2, CH_REG_48)) >> 16 & 0xf) == CH_FIELD_FULL)
        step_done = 1;

    if ((unsigned char)hdmi_phy_read_reg(port, PHY_REG_1018) > REG_1018_HIGH) {
        ivco = hdmi_phy_read_reg(port, PHY_CH_REG(0, CH_REG_68)) >> 4 & 0xf;
        ivco_saved = ivco;
        if ((dbg_hdmi_message_flags & HDMI_MSG_EQ_FLOW) != 0)
            dbg_printf(DAT_a0067358, (char)(port + 'A'), "DRV_HDMI_EQScan_FSM_PHY_PreChkError");
        if ((dbg_hdmi_message_flags & HDMI_MSG_EQ_FLOW) != 0)
            dbg_printf(DAT_a0067388, ivco_saved & 0xf);
        hdmi_phy_write_bit(1, CH_CTRL_BIT21, port, PHY_CH_REG(0, CH_REG_CTRL));
        hdmi_phy_write_bit(1, CH_CTRL_BIT21, port, PHY_CH_REG(1, CH_REG_CTRL));
        hdmi_phy_write_bit(1, CH_CTRL_BIT21, port, PHY_CH_REG(2, CH_REG_CTRL));

        /* raise by one, but stay at the largest value */
        if (ivco_saved != IVCO_MAX)
            ivco_next = ivco + 1;
        else
            ivco_next = ivco;
        hdmi_phy_update_reg(port, PHY_CH_REG(0, CH_REG_68), IVCO_KEEP_MASK, (ivco_next & 0xf) << 8);
        hdmi_phy_write_bit(1, IVCO_FORCE_BIT, port, PHY_CH_REG(0, CH_REG_68));
        hdmi_phy_write_bit(0, CH_CTRL_BIT21, port, PHY_CH_REG(0, CH_REG_CTRL));
        hdmi_phy_write_bit(0, CH_CTRL_BIT21, port, PHY_CH_REG(1, CH_REG_CTRL));
        hdmi_phy_write_bit(0, CH_CTRL_BIT21, port, PHY_CH_REG(2, CH_REG_CTRL));
        timer_delay_long_units(IVCO_SETTLE_UNITS);
        /* register 0x1018 low byte fell to the low limit: put the original value back */
        if ((unsigned char)hdmi_phy_read_reg(port, PHY_REG_1018) <= REG_1018_LOW) {
            if ((dbg_hdmi_message_flags & HDMI_MSG_EQ_FLOW) != 0)
                dbg_printf(DAT_a0067398, (char)(port + 'A'), "DRV_HDMI_EQScan_FSM_PHY_PreChkError");
            hdmi_phy_write_bit(1, CH_CTRL_BIT21, port, PHY_CH_REG(0, CH_REG_CTRL));
            hdmi_phy_write_bit(1, CH_CTRL_BIT21, port, PHY_CH_REG(1, CH_REG_CTRL));
            hdmi_phy_write_bit(1, CH_CTRL_BIT21, port, PHY_CH_REG(2, CH_REG_CTRL));
            hdmi_phy_update_reg(port, PHY_CH_REG(0, CH_REG_68), IVCO_KEEP_MASK, ivco_saved << 8);
            hdmi_phy_write_bit(0, IVCO_FORCE_BIT, port, PHY_CH_REG(0, CH_REG_68));
            hdmi_phy_write_bit(0, CH_CTRL_BIT21, port, PHY_CH_REG(0, CH_REG_CTRL));
            hdmi_phy_write_bit(0, CH_CTRL_BIT21, port, PHY_CH_REG(1, CH_REG_CTRL));
            hdmi_phy_write_bit(0, CH_CTRL_BIT21, port, PHY_CH_REG(2, CH_REG_CTRL));
        }
        step_done = 1;
    }

    if (step_done) {
        hdmi_eq_wait_passes[port] = 6;
        hdmi_eq_port_records[port].wait_count = 0;
        if (hdmi_eq_scan_records[port].byte_0x8 == 1) {
            if ((dbg_hdmi_message_flags & HDMI_MSG_EQ_FLOW) != 0)
                dbg_printf(DAT_a00673d0, (char)(port + 'A'), timer_get_ticks());
            hdmi_eq_scan_records[port].state = EQSCAN_STATE_CHKERROR;
        } else {
            hdmi_eq_scan_records[port].state = EQSCAN_STATE_PRE_RVGA;
        }
    } else {
        hdmi_eq_scan_records[port].state = EQSCAN_STATE_PHY_INIT;
    }
    return 0;
}
