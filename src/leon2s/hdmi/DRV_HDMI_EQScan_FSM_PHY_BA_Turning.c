/* DRV_HDMI_EQScan_FSM_PHY_BA_Turning  (DRV_HDMI_EQScan_FSM_PHY_BA_Turning)
 *
 * EQ scan step: once all three channels report 0xF, raise the EQ value by 0, 2 or 3 and move on.
 *   port: PHY
 * Returns: 0
 * Note: State function of the EQ scan table run by hdmi_eq_run_scan_fsm. The step size comes from the low byte
 *   of PHY register 0x1018; the next state from byte 8 of the scan record.
 * Name basis: proven - original name printed: 'DRV_HDMI_EQScan_FSM_PHY_BA_Turning'
 *
 * Matching notes
 * --------------
 * leon2s DRV_HDMI_EQScan_FSM_PHY_BA_Turning @ 0xa0075508-0xa0075858, flags -mcpu=v8 -Os -g (section default).
 * Source forms the exact build depends on:
 *  - port is a u8 parameter (the firmware keeps the raw %i0 copy in %l4 and re-extends it at each use; an int
 *    parameter swaps %i0 / %l4);
 *  - three separate debug ifs on the EQ_FLOW bit, one per channel; jump threading turns them into a nested shape;
 *  - each of the three adjusting arms clamps to 15 on its own (crossjumping shares the clamp);
 *  - the next state is stored in each arm of the final if, as a full word; one variable gives a branch-free
 *    form;
 *  - the three format strings are the shared objects DAT_a0066b30 / b58 / b80; the routine name is a string
 *    literal in the calls.
 */
/* Message groups of dbg_hdmi_message_flags: every print of the EQ scan is in group EQ_FLOW. */
#define HDMI_MSG_EQ_FLOW 0x02

/* States of the EQ scan: the index into hdmi_eq_scan_state_handlers. */
#define EQSCAN_STATE_BA_TURNING     5   /* this step */
#define EQSCAN_STATE_PRE_RVGA       6
#define EQSCAN_STATE_RUN_AEQ        8
#define EQSCAN_STATE_SEARCH_PROCESS 0x0d

/* Registers of the three channels: channel ch has its own page at 0x1100 + 0x400 * ch. */
#define PHY_CH_REG(ch, reg) (0x1100 + 0x400 * (ch) + (reg))
#define CH_REG_CTRL         0x00        /* bit 21 is set around the write of the new value */
#define CH_REG_48           0x48        /* bits 16..19: printed per channel; this step waits until all three are 0xF */
#define CH_REG_68           0x68        /* bits 4..7: value adjusted here; bits 8..15 / 8..11 written */
#define CH_CTRL_BIT21       0x15
#define PHY_REG_1018        0x1018      /* low byte: its range decides how the value is adjusted */
#define PHY_REG_1038        0x1038      /* low byte set to 7 */
#define PHY_REG_1154        0x1154      /* low byte set to 0x1e */
#define EQ_MAX              0xf

extern unsigned int dbg_hdmi_message_flags;
extern unsigned char DAT_a0066b30[];            /* "[EQ]: Port%c, Ch0, %s [0x%02lx]" (bold) */
extern unsigned char DAT_a0066b58[];            /* same for Ch1 */
extern unsigned char DAT_a0066b80[];            /* same for Ch2 */
extern int dbg_printf(const void *, ...);
extern unsigned int hdmi_phy_read_reg(unsigned int, unsigned short);
extern void hdmi_phy_write_bit(int, unsigned int, unsigned char, unsigned short);
extern void hdmi_phy_update_reg(unsigned int, unsigned short, unsigned int, unsigned int);
extern void timer_delay_long_units(int);
/* The scan state of one port (12 bytes per port). byte_0x8 set: AEQ mode; clear: MEQ. */
struct eq_scan_record {
    unsigned int state;                 /* EQSCAN_STATE_*: the step hdmi_eq_run_scan_fsm runs next */
    unsigned int word_0x4;
    unsigned char byte_0x8;
    unsigned char pad[3];
};
extern struct eq_scan_record hdmi_eq_scan_records[];
extern unsigned char hdmi_eq_keep_results_flags[];   /* per port */

/*
 * EQ scan state EQSCAN_STATE_BA_TURNING (step of the table run by hdmi_eq_run_scan_fsm): adjust the value read
 * from bits 4..7 of channel 0's register 0x68, write it into bits 8..11 of the same register while bit 21 of all
 * three channel control registers is set, then choose the next state.
 *
 *   port  PHY
 *
 * Returns 0. It also returns 0 at once, with the state unchanged, until bits 16..19 of channel register 0x48
 * of channels 0, 1 and 2 are all 0xF; with debug flag bit 1 set each of the three is printed first.
 *
 * Once they are: read the low byte of PHY register 0x1018 and the value eq from register 0x1168. The byte
 * decides the change of eq (the result is limited to 15): 0x80..0x90 none, 0x70..0x7F plus 3, 0x50..0x6F and
 * 0xB0..0xC0 plus 2. Any other byte skips the write. The write sets bits 8..15 of register 0x1168 to 0x10, then
 * with bit 21 of the control register of all three channels set writes eq into bits 8..11 of 0x1168 (twice),
 * clears the three bits and waits. Whether or not it wrote, the low byte of 0x1018 is rewritten with its own
 * value, the low byte of 0x1038 is set to 7 and that of 0x1154 to 0x1E.
 *
 * Next state: with byte_0x8 of the port's scan record 1, EQSCAN_STATE_RUN_AEQ when hdmi_eq_keep_results_flags[port]
 * is 1, else EQSCAN_STATE_PRE_RVGA; with byte_0x8 not 1, EQSCAN_STATE_SEARCH_PROCESS.
 */
int DRV_HDMI_EQScan_FSM_PHY_BA_Turning(unsigned char port)
{
    unsigned int reg_1018;
    unsigned char eq;
    unsigned char skip_write = 0;
    int sum;
    unsigned int eq_field;

    if ((dbg_hdmi_message_flags & HDMI_MSG_EQ_FLOW) != 0)
        dbg_printf(DAT_a0066b30, (char)(port + 'A'), "DRV_HDMI_EQScan_FSM_PHY_BA_Turning",
                     hdmi_phy_read_reg(port, PHY_CH_REG(0, CH_REG_48)) >> 16 & 0xf);
    if ((dbg_hdmi_message_flags & HDMI_MSG_EQ_FLOW) != 0)
        dbg_printf(DAT_a0066b58, (char)(port + 'A'), "DRV_HDMI_EQScan_FSM_PHY_BA_Turning",
                     hdmi_phy_read_reg(port, PHY_CH_REG(1, CH_REG_48)) >> 16 & 0xf);
    if ((dbg_hdmi_message_flags & HDMI_MSG_EQ_FLOW) != 0)
        dbg_printf(DAT_a0066b80, (char)(port + 'A'), "DRV_HDMI_EQScan_FSM_PHY_BA_Turning",
                     hdmi_phy_read_reg(port, PHY_CH_REG(2, CH_REG_48)) >> 16 & 0xf);
    if ((hdmi_phy_read_reg(port, PHY_CH_REG(0, CH_REG_48)) >> 16 & 0xf) != 0xf) return 0;
    if ((hdmi_phy_read_reg(port, PHY_CH_REG(1, CH_REG_48)) >> 16 & 0xf) != 0xf) return 0;
    if ((hdmi_phy_read_reg(port, PHY_CH_REG(2, CH_REG_48)) >> 16 & 0xf) != 0xf) return 0;
    reg_1018 = hdmi_phy_read_reg(port, PHY_REG_1018);
    eq = hdmi_phy_read_reg(port, PHY_CH_REG(0, CH_REG_68)) >> 4 & 0xf;
    /* The low byte of register 0x1018 decides how far eq is raised. */
    if ((unsigned char)(reg_1018 - 0x80) <= 0x10) {
    } else if ((unsigned char)(reg_1018 - 0x70) <= 0xf) {
        sum = eq + 3; if (sum > EQ_MAX) sum = EQ_MAX; eq = sum;
    } else if ((unsigned char)(reg_1018 - 0x50) <= 0x1f) {
        sum = eq + 2; if (sum > EQ_MAX) sum = EQ_MAX; eq = sum;
    } else if ((unsigned char)(reg_1018 + 0x50) <= 0x10) {
        sum = eq + 2; if (sum > EQ_MAX) sum = EQ_MAX; eq = sum;
    } else {
        skip_write = 1;
    }
    if (skip_write == 0) {
        hdmi_phy_update_reg(port, PHY_CH_REG(0, CH_REG_68), 0xffff00ff, 0x1000);
        hdmi_phy_write_bit(1, CH_CTRL_BIT21, port, PHY_CH_REG(0, CH_REG_CTRL));
        hdmi_phy_write_bit(1, CH_CTRL_BIT21, port, PHY_CH_REG(1, CH_REG_CTRL));
        hdmi_phy_write_bit(1, CH_CTRL_BIT21, port, PHY_CH_REG(2, CH_REG_CTRL));
        eq_field = (eq & 0xf) << 8;
        hdmi_phy_update_reg(port, PHY_CH_REG(0, CH_REG_68), 0xfffff0ff, eq_field);
        hdmi_phy_update_reg(port, PHY_CH_REG(0, CH_REG_68), 0xfffff0ff, eq_field);
        hdmi_phy_write_bit(0, CH_CTRL_BIT21, port, PHY_CH_REG(0, CH_REG_CTRL));
        hdmi_phy_write_bit(0, CH_CTRL_BIT21, port, PHY_CH_REG(1, CH_REG_CTRL));
        hdmi_phy_write_bit(0, CH_CTRL_BIT21, port, PHY_CH_REG(2, CH_REG_CTRL));
        timer_delay_long_units(1);
    }
    hdmi_phy_update_reg(port, PHY_REG_1018, 0xffffff00, hdmi_phy_read_reg(port, PHY_REG_1018) & 0xff);
    hdmi_phy_update_reg(port, PHY_REG_1038, 0xffffff00, 7);
    hdmi_phy_update_reg(port, PHY_REG_1154, 0xffffff00, 0x1e);
    if (hdmi_eq_scan_records[port].byte_0x8 == 1) {
        if (hdmi_eq_keep_results_flags[port] == 1) hdmi_eq_scan_records[port].state = EQSCAN_STATE_RUN_AEQ;
        else hdmi_eq_scan_records[port].state = EQSCAN_STATE_PRE_RVGA;
    } else {
        hdmi_eq_scan_records[port].state = EQSCAN_STATE_SEARCH_PROCESS;
    }
    return 0;
}
