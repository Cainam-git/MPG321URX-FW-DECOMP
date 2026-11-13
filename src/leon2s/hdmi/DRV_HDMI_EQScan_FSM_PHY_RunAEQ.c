/* DRV_HDMI_EQScan_FSM_PHY_RunAEQ  (DRV_HDMI_EQScan_FSM_PHY_RunAEQ)
 *
 * EQ scan step: write the found RCT/CFT values; an AEQ scan also pulses the channels and restores them.
 *   port: PHY
 * Note: State function of the EQ scan table run by hdmi_eq_run_scan_fsm. Next state: ChkError for an AEQ scan,
 *   else Check_MEQ_Done.
 * Name basis: proven - original name printed: 'DRV_HDMI_EQScan_FSM_PHY_RunAEQ'
 *
 * Matching notes
 * --------------
 * leon2s DRV_HDMI_EQScan_FSM_PHY_RunAEQ @ 0xa007731c-0xa007769c (896 bytes), flags -mcpu=v8 -Os -g
 * (section default).
 * Source forms the exact build depends on:
 *  - old-style (K&R) definition with an unsigned char port, masked at each use;
 *  - rct and cft are read into locals before the 'ch < 3' guards, and the port is copied into p inside the
 *    loop and again before the final stores;
 *  - the final state store is an if/else (a conditional expression is if-converted);
 *  - the format strings are the shared DAT_ objects (as in DRV_HDMI_EQScan_FSM_PHY_BA_Turning), the function
 *    name a separate static string.
 */
extern unsigned char hdmi_eq_wait_passes[];
extern unsigned char hdmi_eq_rct_try_indexes[];
extern unsigned char hdmi_eq_cft_try_indexes[];
extern unsigned int hdmi_eq_initial_cft_values[];
extern unsigned int hdmi_eq_initial_rct_values[];
extern unsigned char hdmi_eq_fixed_rct;
extern unsigned short hdmi_eq_fixed_cft;
extern unsigned int dbg_hdmi_message_flags;
extern const unsigned short hdmi_phy_channel_regs_0x170[];
extern const unsigned short hdmi_phy_channel_regs_0x17c[];
extern const unsigned short hdmi_phy_channel_eq_regs[];
extern unsigned char DAT_a0067170[];
extern unsigned char DAT_a0066b30[];
extern unsigned char DAT_a0066b58[];
extern unsigned char DAT_a0066b80[];
extern int dbg_printf(const void *, ...);
extern unsigned int hdmi_phy_read_reg(unsigned int, unsigned short);
extern void hdmi_phy_update_reg(unsigned int, unsigned short, unsigned int, unsigned int);
extern void hdmi_phy_write_bit(int, unsigned int, unsigned char, unsigned short);
extern void timer_delay_long_units(int);
extern unsigned char hdmi_is_hdmi21_phy(unsigned char);

#define HDMI_MSG_EQ_FLOW 0x02           /* bit of dbg_hdmi_message_flags: the "[EQ]" lines */

/* States of the EQ scan (index into hdmi_eq_scan_state_handlers). */
#define EQSCAN_STATE_CHKERROR       0x0b    /* DRV_HDMI_EQScan_FSM_PHY_ChkError */
#define EQSCAN_STATE_CHECK_MEQ_DONE 0x0f    /* DRV_HDMI_EQScan_FSM_Check_MEQ_Done */

#define PRE_AEQ_FLAGS_NORMAL    6       /* values of hdmi_eq_wait_passes[port] set here */
#define PRE_AEQ_FLAGS_BYTE28    0x32

/* PHY registers 0x170 and 0x17c of a channel (tables hdmi_phy_channel_regs_0x170 / _0x17c) and the EQ register
   0x178 (hdmi_phy_channel_eq_regs). */
#define EQ_REG_KEEP         0xff0000f0  /* keep mask of the RCT / CFT write: RCT bits 0..3, CFT bits 8..23 */
#define FIELD_KEEP          0xff00ffff  /* keep mask of the bits 16..23 writes */
#define REG_170_PULSE_VALUE 0x2c0000    /* bits 16..23 of register 0x170 during the pulse */
#define REG_17C_PULSE_VALUE 0xff0000    /* bits 16..23 of register 0x17c during the pulse */
#define REG_17C_BIT4        4
#define REG_170_BIT0        0
#define PULSE_DELAY_UNITS   1           /* timer_delay_long_units argument */

/* Channel registers at 0x1100 + 0x400 * channel. */
#define PHY_CH_REG(ch, reg) (0x1100 + 0x400 * (ch) + (reg))
#define CH_REG_48           0x48        /* bits 16..19: printed per channel ("Ch0" .. "Ch2") */

/* The scan state of one port (12 bytes per port, table at 0xA807CCC4). */
struct eq_scan_record {
    unsigned int state;                 /* EQSCAN_STATE_*: the step hdmi_eq_run_scan_fsm runs next */
    unsigned int word_0x4;
    unsigned char byte_0x8;             /* 1: AEQ scan (see ChkError) */
    unsigned char pad[3];
};
/* An RCT / CFT pair (same layout as the entries of the EQ tables). */
struct eq_entry {
    unsigned char rct;
    unsigned char byte_1;
    unsigned short cft;
};
/* The EQ scan work record of one port (0x898 bytes). */
struct eq_scan_channels {
    unsigned char bytes_0x0[0x28];
    unsigned char byte_0x28;            /* when set: pre_aeq_flags becomes 0x32, and this byte is cleared */
    unsigned char bytes_0x29[7];
    unsigned char wait_count;           /* passes of a waiting step so far */
    unsigned char bytes_0x31[0x884 - 0x31];
    struct eq_entry result[3];          /* +0x884: RCT / CFT found for each channel */
    unsigned char bytes_0x890[8];
};
extern struct eq_scan_channels hdmi_eq_port_records[];
extern struct eq_scan_record hdmi_eq_scan_records[];

static const char routine_name[] = "DRV_HDMI_EQScan_FSM_PHY_RunAEQ";

/*
 * EQ scan state 8. Writes the RCT / CFT values the scan found for each channel (result[ch]) into the
 * channel's EQ register 0x178. In an AEQ scan (scan record byte +8 set) it then pulses the channel's
 * registers 0x17c and 0x170: bit 4 of 0x17c set and bit 0 of 0x170 cleared, bits 16..23 of 0x170 and 0x17c
 * set to 0x2c and 0xff, one timer unit of waiting, then bit 0 of 0x170 set and bit 4 of 0x17c cleared. After
 * that it writes the start values back to the EQ register: the entries of hdmi_eq_initial_rct_values /
 * hdmi_eq_initial_cft_values picked by the channel's try indexes on an HDMI 2.1 PHY, otherwise the fixed
 * hdmi_eq_fixed_rct / _cft.
 * Last, it clears wait_count, sets pre_aeq_flags[port] to 0x32 (and clears byte +0x28) if byte +0x28 was
 * set, else to 6, and sets the next state: ChkError for an AEQ scan, Check_MEQ_Done otherwise.
 * Always returns 0.
 *   port: PHY index (the letter in the prints is 'A' + port)
 */
int DRV_HDMI_EQScan_FSM_PHY_RunAEQ(port)
    unsigned char port;
{
    unsigned char ch = 0;
    unsigned char p;
    unsigned char rct;
    unsigned short cft;

    if ((dbg_hdmi_message_flags & HDMI_MSG_EQ_FLOW) != 0)
        dbg_printf(DAT_a0067170, (char)(port + 'A'), routine_name);
    if ((dbg_hdmi_message_flags & HDMI_MSG_EQ_FLOW) != 0)
        dbg_printf(DAT_a0066b30, (char)(port + 'A'), routine_name,
                     (hdmi_phy_read_reg(port, PHY_CH_REG(0, CH_REG_48)) >> 16) & 0xf);
    if ((dbg_hdmi_message_flags & HDMI_MSG_EQ_FLOW) != 0)
        dbg_printf(DAT_a0066b58, (char)(port + 'A'), routine_name,
                     (hdmi_phy_read_reg(port, PHY_CH_REG(1, CH_REG_48)) >> 16) & 0xf);
    if ((dbg_hdmi_message_flags & HDMI_MSG_EQ_FLOW) != 0)
        dbg_printf(DAT_a0066b80, (char)(port + 'A'), routine_name,
                     (hdmi_phy_read_reg(port, PHY_CH_REG(2, CH_REG_48)) >> 16) & 0xf);
    for (; ch <= 2; ch++) {
        p = port;
        rct = hdmi_eq_port_records[p].result[ch].rct;
        cft = hdmi_eq_port_records[p].result[ch].cft;
        if (ch < 3)
            hdmi_phy_update_reg(p, hdmi_phy_channel_eq_regs[ch], EQ_REG_KEEP, (rct & 0xf) | (cft << 8));
        if (hdmi_eq_scan_records[p].byte_0x8 == 0)
            continue;
        /* AEQ scan: pulse the channel, then restore the start values. */
        if (ch < 3) {
            hdmi_phy_write_bit(1, REG_17C_BIT4, p, hdmi_phy_channel_regs_0x17c[ch]);
            hdmi_phy_write_bit(0, REG_170_BIT0, p, hdmi_phy_channel_regs_0x170[ch]);
            hdmi_phy_update_reg(p, hdmi_phy_channel_regs_0x170[ch], FIELD_KEEP, REG_170_PULSE_VALUE);
            hdmi_phy_update_reg(p, hdmi_phy_channel_regs_0x17c[ch], FIELD_KEEP, REG_17C_PULSE_VALUE);
        }
        timer_delay_long_units(PULSE_DELAY_UNITS);
        if (ch < 3) {
            hdmi_phy_write_bit(1, REG_170_BIT0, p, hdmi_phy_channel_regs_0x170[ch]);
            hdmi_phy_write_bit(0, REG_17C_BIT4, p, hdmi_phy_channel_regs_0x17c[ch]);
        }
        if (hdmi_is_hdmi21_phy(p)) {
            rct = hdmi_eq_initial_rct_values[hdmi_eq_rct_try_indexes[ch]];
            cft = hdmi_eq_initial_cft_values[hdmi_eq_cft_try_indexes[ch]];
        } else {
            rct = hdmi_eq_fixed_rct;
            cft = hdmi_eq_fixed_cft;
        }
        if (ch < 3)
            hdmi_phy_update_reg(p, hdmi_phy_channel_eq_regs[ch], EQ_REG_KEEP, (rct & 0xf) | (cft << 8));
    }
    p = port;
    hdmi_eq_port_records[p].wait_count = 0;
    if (hdmi_eq_port_records[p].byte_0x28) {
        hdmi_eq_wait_passes[p] = PRE_AEQ_FLAGS_BYTE28;
        hdmi_eq_port_records[p].byte_0x28 = 0;
    } else
        hdmi_eq_wait_passes[p] = PRE_AEQ_FLAGS_NORMAL;
    if (hdmi_eq_scan_records[p].byte_0x8)
        hdmi_eq_scan_records[p].state = EQSCAN_STATE_CHKERROR;
    else
        hdmi_eq_scan_records[p].state = EQSCAN_STATE_CHECK_MEQ_DONE;
    return 0;
}
