/* DRV_HDMI_EQScan_FSM_PHY_PreAEQ  (DRV_HDMI_EQScan_FSM_PHY_PreAEQ)
 *
 * EQ scan step: step through the pre-AEQ table of RCT/CFT values per channel.
 *   port: PHY
 * Note: State function of the EQ scan table run by hdmi_eq_run_scan_fsm.
 * Name basis: proven - original name printed: 'DRV_HDMI_EQScan_FSM_PHY_PreAEQ'
 *
 * Matching notes
 * --------------
 * DRV_HDMI_EQScan_FSM_PHY_PreAEQ (leon2s 0xa0076e68-0xa007731c, 1204 bytes), flags -mcpu=v8 -Os -g
 * (section default).
 * Source forms the exact build depends on:
 *  - the limits are written '(byte_0x8 ? 10u : 14u)' and '(byte_0x8 ? 3u : 1u)' (unsigned compares,
 *    byte_0x8 read again at each test);
 *  - the routine's name is a separate static string.
 */

/* Message groups of dbg_hdmi_message_flags: every print of the EQ scan is in group EQ_FLOW. */
#define HDMI_MSG_EQ_FLOW 0x02

/* States of the EQ scan: the index into hdmi_eq_scan_state_handlers. */
#define EQSCAN_STATE_PRE_RVGA   6       /* DRV_HDMI_EQScan_FSM_PHY_PreRVGA */
#define EQSCAN_STATE_R_CHKERROR 0x0c    /* DRV_HDMI_EQScan_FSM_PHY_R_ChkError */

#define R_CHKERROR_WAIT_PASSES  1       /* value of hdmi_eq_wait_passes: R_ChkError measures on its first call */

/* Register values of the channels while the pre-AEQ entries are tried: the two values the EQ step writes
   for MEQ (it writes 0x2c / 0xff for AEQ). */
#define REG_BITS_16_23_KEEP     0xff00ffff
#define REG_170_MEQ_VALUE       0x2f0000    /* bits 16..23 of the channel's register 0x170 = 0x2f */
#define REG_17C_MEQ_VALUE       0x4f0000    /* bits 16..23 of the channel's register 0x17c = 0x4f */
#define EQ_REG_KEEP             0xff0000f0  /* keep mask of the RCT/CFT write (register 0x178) */

/* The scan state of one port (12 bytes per port). byte_0x8 set: AEQ, 10 pre-AEQ entries and 3 RVGA indexes;
   clear: MEQ, 14 entries and 1 RVGA index. */
struct eq_scan_record {
    unsigned int state;                 /* EQSCAN_STATE_*: the step hdmi_eq_run_scan_fsm runs next */
    unsigned char byte_0x4[3];
    unsigned char check_error_round;
    unsigned char byte_0x8;
    unsigned char pad[3];
};

/* The EQ scan work record of one port (0x898 bytes). Arrays of 3 are per channel. */
struct eq_scan_channels {
    unsigned char eq_table_index[3];
    unsigned char pre_aeq_index[3];     /* the pre-AEQ table entry applied here ("preAEQIdx") */
    unsigned char byte_0x6[3];
    unsigned char rvga_index[3];        /* RVGA gain index in use ("RVGA_Idx") */
    unsigned char byte_0xc[4];
    unsigned int search_step[3];        /* 0..3: the step of R_ChkError's search; cleared at entry 0 */
    unsigned char byte_0x1c[0x28 - 0x1c];
    unsigned char byte_0x28;
    unsigned char byte_0x29;
    unsigned char pre_aeq_done[3];      /* 1: all pre-AEQ indexes of this RVGA index are done */
    unsigned char rvga_done[3];         /* 1: "PreRVGA is done" for this channel */
    unsigned char wait_count;           /* passes of a waiting step so far */
    unsigned char channel_ok[3];
    unsigned char byte_0x34[3];
    unsigned char byte_0x37;
    unsigned int scdc_errors[178][3];
    unsigned char byte_0x890[8];
};

/* One pre-AEQ table entry: the RCT and CFT values written to a channel's register 0x178. */
struct eq_entry { unsigned char rct; unsigned char byte_1; unsigned short cft; };

extern struct eq_scan_channels hdmi_eq_port_records[];
extern struct eq_scan_record hdmi_eq_scan_records[];
extern unsigned char hdmi_eq_wait_passes[];
extern unsigned char hdmi_eq_error_mode_flags[];
extern unsigned int dbg_hdmi_message_flags;
extern const struct eq_entry hdmi_eq_pre_aeq_entries_rx21[];
extern const struct eq_entry hdmi_eq_pre_aeq_entries[];
extern const struct eq_entry hdmi_eq_pre_aeq_entries_byte8_set[];
extern const unsigned short hdmi_phy_channel_regs_0x170[];
extern const unsigned short hdmi_phy_channel_regs_0x17c[];
extern const unsigned short hdmi_phy_channel_eq_regs[];
extern unsigned char DAT_a0067058[];    /* "[EQ]: Port%c %s:" */
extern int dbg_printf(const void *, ...);
extern unsigned char hdmi_is_hdmi21_phy(unsigned char);
extern void hdmi_phy_update_reg(unsigned int, unsigned short, unsigned int, unsigned int);
extern void DRV_HDMI_PHY_Clr_EQ_Err(unsigned int);

static const char fn_[] = "DRV_HDMI_EQScan_FSM_PHY_PreAEQ";

/*
 * EQ scan state 7. PreRVGA (state 6) comes here while some channel has no RVGA result yet, and R_ChkError
 * (state 12) comes back here after it has measured an entry and chosen the next pre_aeq_index. Together the
 * two steps try the entries of the pre-AEQ table on each channel for each RVGA index.
 *
 *   port  HDMI receiver PHY (printed as the letter 'A' + port)
 *
 * Always returns 0, so hdmi_eq_run_scan_fsm stops until its next call.
 *
 * The table: hdmi_eq_pre_aeq_entries_byte8_set (10 entries) in AEQ, hdmi_eq_pre_aeq_entries (14 entries) in
 * MEQ, and on an HDMI 2.1 PHY in MEQ with hdmi_eq_error_mode_flags set hdmi_eq_pre_aeq_entries_rx21. Each
 * table holds the same row of RCT values twice, first with the lower CFT value, then with the higher one.
 *
 * Phases:
 *  1. Per channel without an RVGA result (rvga_done clear):
 *     - while its pre_aeq_index is inside the table: set bits 16..23 of its registers 0x170 / 0x17c to 0x2f /
 *       0x4f and write the RCT/CFT of that entry to register 0x178 (at entry 0 the search_step starts at 0);
 *     - once the index has run past the table ("preAEQ done for RVGAidx"): move the RVGA index one on and
 *       start the entries again from 0 when an RVGA index is left (the index may end at the count, 3 or 1),
 *       and mark the channel pre_aeq_done.
 *  2. Every channel pre_aeq_done: clear wait_count and the pre_aeq_done flags of the channels that still have
 *     an RVGA index to try, and go to PreRVGA (state 6), which writes the next RVGA gain or picks the result.
 *  3. Otherwise: go to R_ChkError (state 12) with hdmi_eq_wait_passes = 1 and wait_count = 0 (it measures
 *     on its first call), and clear the error counters (DRV_HDMI_PHY_Clr_EQ_Err).
 */
int DRV_HDMI_EQScan_FSM_PHY_PreAEQ(unsigned char port)
{
    const struct eq_entry *table;
    unsigned char ch;
    unsigned short cft;
    unsigned char rct;

    if ((dbg_hdmi_message_flags & HDMI_MSG_EQ_FLOW) != 0)
        dbg_printf(DAT_a0067058, (char)(port + 'A'), fn_);
    table = hdmi_eq_scan_records[port].byte_0x8 ? hdmi_eq_pre_aeq_entries_byte8_set : hdmi_eq_pre_aeq_entries;
    if (hdmi_is_hdmi21_phy(port)) {
        if (hdmi_eq_scan_records[port].byte_0x8 == 0 && hdmi_eq_error_mode_flags[port] == 1)
            table = hdmi_eq_pre_aeq_entries_rx21;
    }

    /* Phase 1: apply the current entry of each channel, or end its run through the table. */
    for (ch = 0; ch <= 2; ch++) {
        if (hdmi_eq_port_records[port].rvga_done[ch] == 1) {
            if ((dbg_hdmi_message_flags & HDMI_MSG_EQ_FLOW) != 0)
                dbg_printf("[EQ]: # Port%c, CH%d, -------2 PreRVGA is done, bypass PreAEQ------- \n\n",
                             (char)(port + 'A'), ch);
            continue;
        }
        if (hdmi_eq_port_records[port].pre_aeq_index[ch] < (hdmi_eq_scan_records[port].byte_0x8 ? 10u : 14u)) {
            /* A new run through the table starts R_ChkError's search from its first step. */
            if (hdmi_eq_port_records[port].pre_aeq_index[ch] == 0)
                hdmi_eq_port_records[port].search_step[ch] = 0;
            if (ch < 3) {
                hdmi_phy_update_reg(port, hdmi_phy_channel_regs_0x170[ch], REG_BITS_16_23_KEEP, REG_170_MEQ_VALUE);
                hdmi_phy_update_reg(port, hdmi_phy_channel_regs_0x17c[ch], REG_BITS_16_23_KEEP, REG_17C_MEQ_VALUE);
            }
            cft = table[hdmi_eq_port_records[port].pre_aeq_index[ch]].cft;
            rct = table[hdmi_eq_port_records[port].pre_aeq_index[ch]].rct;
            if (ch < 3)
                hdmi_phy_update_reg(port, hdmi_phy_channel_eq_regs[ch], EQ_REG_KEEP, (rct & 0xf) | (cft << 8));
            if ((dbg_hdmi_message_flags & HDMI_MSG_EQ_FLOW) != 0)
                dbg_printf("[EQ]: # Port%c, CH%d, preAEQIdx = %d, RCT = 0x%02x , CFT = 0x%04x\n",
                             (char)(port + 'A'), ch, hdmi_eq_port_records[port].pre_aeq_index[ch], rct, cft);
        } else {
            if ((dbg_hdmi_message_flags & HDMI_MSG_EQ_FLOW) != 0)
                dbg_printf("[EQ]: # Port%c, CH%d, preAEQ done for RVGAidx (%d) !!!\n",
                             (char)(port + 'A'), ch, hdmi_eq_port_records[port].rvga_index[ch]);
            if (hdmi_eq_port_records[port].rvga_index[ch] < (hdmi_eq_scan_records[port].byte_0x8 ? 3u : 1u)) {
                hdmi_eq_port_records[port].rvga_index[ch]++;
                if ((dbg_hdmi_message_flags & HDMI_MSG_EQ_FLOW) != 0)
                    dbg_printf("[EQ]: # Port%c, CH%d, next preRVGAIdx = %d\n",
                                 (char)(port + 'A'), ch, hdmi_eq_port_records[port].rvga_index[ch]);
                hdmi_eq_port_records[port].pre_aeq_index[ch] = 0;
            }
            hdmi_eq_port_records[port].pre_aeq_done[ch] = 1;
        }
    }

    if (hdmi_eq_port_records[port].pre_aeq_done[0] == 1 && hdmi_eq_port_records[port].pre_aeq_done[1] == 1 && hdmi_eq_port_records[port].pre_aeq_done[2] == 1) {
        /* Phase 2: every channel has finished this RVGA index. */
        hdmi_eq_port_records[port].wait_count = 0;
        for (ch = 0; ch <= 2; ch++) {
            if (hdmi_eq_port_records[port].rvga_index[ch] < (hdmi_eq_scan_records[port].byte_0x8 ? 3u : 1u))
                hdmi_eq_port_records[port].pre_aeq_done[ch] = 0;
        }
        hdmi_eq_scan_records[port].state = EQSCAN_STATE_PRE_RVGA;
    } else {
        /* Phase 3: measure the entries just written. */
        hdmi_eq_scan_records[port].state = EQSCAN_STATE_R_CHKERROR;
        hdmi_eq_wait_passes[port] = R_CHKERROR_WAIT_PASSES;
        hdmi_eq_port_records[port].wait_count = 0;
        DRV_HDMI_PHY_Clr_EQ_Err(port);
    }
    return 0;
}
