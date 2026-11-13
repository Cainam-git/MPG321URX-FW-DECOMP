/* DRV_HDMI_EQScan_FSM_PHY_R_Turning  (DRV_HDMI_EQScan_FSM_PHY_R_Turning)
 *
 * EQ scan step: print the channel CCT/RCT values and adjust channels with RCT below 8.
 *   port: PHY
 * Note: State function of the EQ scan table run by hdmi_eq_run_scan_fsm.
 * Name basis: proven - original name printed: 'DRV_HDMI_EQScan_FSM_PHY_R_Turning'
 *
 * Matching notes
 * --------------
 * leon2s DRV_HDMI_EQScan_FSM_PHY_R_Turning @ 0xa007769c-0xa007796c (720 bytes), flags -mcpu=v8 -Os -g
 * (section default).
 * Source forms the exact build depends on:
 *  - each table access is guarded by 'ch < 3' (as in DRV_HDMI_EQScan_FSM_PHY_RunAEQ), and the RCT read is an
 *    if/else that sets rct = 0 in the else arm;
 *  - the CCT values are passed as the shifted expression, not as a 16-bit field;
 *  - the function name is a separate static string.
 */
extern unsigned int dbg_hdmi_message_flags;
extern const unsigned short hdmi_phy_channel_regs_0x170[];
extern const unsigned short hdmi_phy_channel_eq_regs[];
extern unsigned char DAT_a0066df8[];
extern int dbg_printf(const void *, ...);
extern unsigned int timer_get_ticks(void);
extern unsigned int hdmi_phy_read_reg(unsigned int, unsigned short);
extern void hdmi_phy_write_bit(int, unsigned int, unsigned char, unsigned short);
extern void DRV_HDMI_PHY_Clr_EQ_Err(unsigned int);

#define HDMI_MSG_EQ_FLOW 0x02           /* bit of dbg_hdmi_message_flags: the "[EQ]" lines */

/* States of the EQ scan (index into hdmi_eq_scan_state_handlers). */
#define EQSCAN_STATE_CHKERROR 0x0b      /* DRV_HDMI_EQScan_FSM_PHY_ChkError */

#define R_TURNING_WAIT_PASSES 5         /* an AEQ scan stays in this state for this many calls first */
#define RCT_LIMIT             8         /* a channel with an RCT value below this is changed */
#define CH_REG_170_BIT16      0x10      /* bit set in register 0x170 of such a channel */

/* Channel registers at 0x1100 + 0x400 * channel; the EQ register is also listed in hdmi_phy_channel_eq_regs. */
#define PHY_CH_REG(ch, reg) (0x1100 + 0x400 * (ch) + (reg))
#define CH_REG_EQ           0x78        /* RCT bits 0..3, CFT bits 8..23 (printed as CCT) */

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
extern struct eq_scan_channels hdmi_eq_port_records[];
extern struct eq_scan_record hdmi_eq_scan_records[];

static const char routine_name[] = "DRV_HDMI_EQScan_FSM_PHY_R_Turning";

/*
 * EQ scan state 9. Counts its calls in wait_count. An AEQ scan (scan record byte +8 is 1) only clears the
 * EQ error state (DRV_HDMI_PHY_Clr_EQ_Err) on the first five calls and stays in this state. After that
 * (at once for a scan that is not AEQ) it prints the tick count and the CCT and RCT values of the three
 * channels, and for each channel whose RCT value is below 8 prints that and sets bit 16 of the channel's
 * register 0x170. It then resets wait_count and sets the next state to ChkError.
 * Always returns 0.
 *   port: PHY index (the letter in the prints is 'A' + port)
 */
int DRV_HDMI_EQScan_FSM_PHY_R_Turning(unsigned char port)
{
    unsigned char ch;
    unsigned char rct;

    hdmi_eq_port_records[port].wait_count++;
    if (hdmi_eq_scan_records[port].byte_0x8 == 1 && hdmi_eq_port_records[port].wait_count <= R_TURNING_WAIT_PASSES) {
        DRV_HDMI_PHY_Clr_EQ_Err(port);
        return 0;
    }
    if ((dbg_hdmi_message_flags & HDMI_MSG_EQ_FLOW) != 0)
        dbg_printf(DAT_a0066df8, (char)(port + 'A'), routine_name, hdmi_eq_port_records[port].wait_count);
    if ((dbg_hdmi_message_flags & HDMI_MSG_EQ_FLOW) != 0)
        dbg_printf("[EQ]: ## Port%c => Jay_EQ_R_Turning [%ld] ##\n\n", (char)(port + 'A'), timer_get_ticks());
    if ((dbg_hdmi_message_flags & HDMI_MSG_EQ_FLOW) != 0)
        dbg_printf("[EQ]: # Port%c  CH0 CCT [0x%04lx] RCT [0x%02lx]\n", (char)(port + 'A'),
                     (hdmi_phy_read_reg(port, PHY_CH_REG(0, CH_REG_EQ)) & 0xffff00) >> 8, hdmi_phy_read_reg(port, PHY_CH_REG(0, CH_REG_EQ)) & 0xf);
    if ((dbg_hdmi_message_flags & HDMI_MSG_EQ_FLOW) != 0)
        dbg_printf("[EQ]: # Port%c  CH1 CCT [0x%04lx] RCT [0x%02lx]\n", (char)(port + 'A'),
                     (hdmi_phy_read_reg(port, PHY_CH_REG(1, CH_REG_EQ)) & 0xffff00) >> 8, hdmi_phy_read_reg(port, PHY_CH_REG(1, CH_REG_EQ)) & 0xf);
    if ((dbg_hdmi_message_flags & HDMI_MSG_EQ_FLOW) != 0)
        dbg_printf("[EQ]: # Port%c  CH2 CCT [0x%04lx] RCT [0x%02lx]\n\n", (char)(port + 'A'),
                     (hdmi_phy_read_reg(port, PHY_CH_REG(2, CH_REG_EQ)) & 0xffff00) >> 8, hdmi_phy_read_reg(port, PHY_CH_REG(2, CH_REG_EQ)) & 0xf);
    for (ch = 0; ch <= 2; ch++) {
        if (ch < 3)
            rct = hdmi_phy_read_reg(port, hdmi_phy_channel_eq_regs[ch]) & 0xf;
        else
            rct = 0;
        if (rct < RCT_LIMIT) {
            if ((dbg_hdmi_message_flags & HDMI_MSG_EQ_FLOW) != 0)
                dbg_printf("[EQ]: # Port%c, CH%d, RCT = 0x%02x < 8 \n", (char)(port + 'A'), ch, rct);
            if (ch < 3)
                hdmi_phy_write_bit(1, CH_REG_170_BIT16, port, hdmi_phy_channel_regs_0x170[ch]);
        }
    }
    hdmi_eq_scan_records[port].state = EQSCAN_STATE_CHKERROR;
    hdmi_eq_port_records[port].wait_count = 0;
    return 0;
}
