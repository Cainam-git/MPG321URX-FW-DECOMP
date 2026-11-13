/* DRV_HDMI_EQScan_FSM_Search_Process  (DRV_HDMI_EQScan_FSM_Search_Process)
 *
 * EQ scan step: apply the RVGA table entry or search for the fewest errors.
 *   port: PHY
 * Note: State function of the EQ scan table run by hdmi_eq_run_scan_fsm.
 * Name basis: proven - original name printed: 'DRV_HDMI_EQScan_FSM_Search_Process'
 *
 * Matching notes
 * --------------
 * DRV_HDMI_EQScan_FSM_Search_Process (leon2s 0xa007890c-0xa0078dc8, 1212 bytes), flags -mcpu=v8 -Os -g
 * (section default).
 * Source forms the exact build depends on:
 *  - the RVGA limit is written '(byte_0x8 ? 3u : 1u)' (unsigned compares, byte_0x8 read again at each test);
 *  - the two register calls of the apply branch each have their own 'if (ch < 3)' (one shared if keeps the
 *    masked port across the first call);
 *  - the routine's name is a separate static string;
 *  - the clears are written in the order pre_aeq_index, pre_aeq_done, byte_0x34.
 */

/* Message groups of dbg_hdmi_message_flags: every print of the EQ scan is in group EQ_FLOW. */
#define HDMI_MSG_EQ_FLOW 0x02

/* States of the EQ scan: the index into hdmi_eq_scan_state_handlers. */
#define EQSCAN_STATE_CHKERROR       0x0b    /* DRV_HDMI_EQScan_FSM_PHY_ChkError */
#define EQSCAN_STATE_SEARCH_EQTABLE 0x0e    /* DRV_HDMI_EQScan_FSM_Search_EQTable */
#define EQSCAN_STATE_DONE           0x10    /* DRV_HDMI_EQScan_FSM_Done */

#define EQ_TABLE_LAST_INDEX     0x17    /* Search_EQTable loads entries while every channel's index is <= this */
#define RVGA_FIELD_MASK         0xff0fffff  /* keeps all but bits 20..23 of the channel's register 0x128 */
#define RVGA_FIELD_SHIFT        20
#define RVGA_ENABLE_BIT         0x0f    /* bit set in the channel's register 0x134 before the RVGA write */
#define EQ_WAIT_PASSES          6       /* value of hdmi_eq_wait_passes: the calls state 12 waits */

/* The scan state of one port (12 bytes per port). byte_0x8 sets the sizes of the scan: pre-AEQ indexes 0..9
   and three RVGA indexes when set, pre-AEQ indexes 0..13 and one RVGA index when clear. */
struct eq_scan_record {
    unsigned int state;                 /* EQSCAN_STATE_*: the step hdmi_eq_run_scan_fsm runs next */
    unsigned int word_0x4;
    unsigned char byte_0x8;
    unsigned char pad[3];
};

/* The EQ scan work record of one port (0x898 bytes). Arrays of 3 are per channel. */
struct eq_scan_channels {
    unsigned char eq_table_index[3];    /* next entry Search_EQTable loads ("eqtable index") */
    unsigned char pre_aeq_index[3];     /* the pre-AEQ table entry PreAEQ applies next ("PreAEQ_Idx") */
    unsigned char byte_0x6[3];
    unsigned char rvga_index[3];        /* RVGA gain index in use ("RVGA_Idx") */
    unsigned char byte_0xc[0x28 - 0xc];
    unsigned char byte_0x28;            /* 1: RunAEQ sets hdmi_eq_wait_passes to 50 instead of 6 */
    unsigned char byte_0x29;
    unsigned char pre_aeq_done[3];      /* 1: all pre-AEQ indexes of this RVGA index are done */
    unsigned char byte_0x2d[3];
    unsigned char wait_count;           /* passes of a waiting step so far */
    unsigned char channel_ok[3];        /* 1: the error check found no errors on this channel */
    unsigned char byte_0x34[3];
    unsigned char byte_0x37;
    unsigned int scdc_errors[178][3];   /* [rvga][ch]: error count per RVGA index ("u32TotalSCDC") */
    unsigned char byte_0x890[6];
    unsigned char byte_0x896;
    unsigned char byte_0x897;
};
extern struct eq_scan_channels hdmi_eq_port_records[];
extern struct eq_scan_record hdmi_eq_scan_records[];
extern unsigned char hdmi_eq_wait_passes[];
extern unsigned int dbg_hdmi_message_flags;
extern const unsigned char hdmi_eq_rvga_values[];
extern const unsigned short hdmi_phy_channel_regs_0x128[];
extern const unsigned short hdmi_phy_channel_regs_0x134[];
extern unsigned char DAT_a0067058[];
extern int dbg_printf(const void *, ...);
extern void hdmi_phy_write_bit(int, unsigned int, unsigned char, unsigned short);
extern void hdmi_phy_update_reg(unsigned int, unsigned short, unsigned int, unsigned int);
extern void hdmi_phy_pulse_channel_regs(unsigned char);

static const char fn_[] = "DRV_HDMI_EQScan_FSM_Search_Process";

/*
 * EQ scan state 13. The error check (state 11) comes here with byte_0x8 set after it has moved the RVGA
 * index of each failing channel one on; the BA turning step (state 5) comes here with byte_0x8 clear.
 *
 *   port  HDMI receiver PHY (printed as the letter 'A' + port)
 *
 * Always returns 1, so hdmi_eq_run_scan_fsm runs the next state at once.
 *
 * Phases, byte_0x8 set (three RVGA indexes):
 *  1. Per channel that is not OK: while its RVGA index is below 3, write the RVGA value of that index into
 *     bits 20..23 of the channel's register 0x128; once the index is 3 (all three tried), write the value of
 *     the index with the fewest errors in scdc_errors instead (the first one on a tie). An index above 3
 *     leaves the channel alone.
 *  2. Pulse the channel registers, set hdmi_eq_wait_passes to 6 and byte_0x28 to 1, clear wait_count and
 *     the pre-AEQ state of the channels that are not OK, and go to the error check (state 11).
 * Byte_0x8 clear:
 *  3. Go to the EQ table search (state 14) while any channel's EQ table index is 0x17 or below, else to the
 *     final state 16.
 */
int DRV_HDMI_EQScan_FSM_Search_Process(unsigned char port)
{
    unsigned char ch = 0;
    unsigned char i;
    unsigned char best_index;
    unsigned int best_errors;
    unsigned int errors;

    if ((dbg_hdmi_message_flags & HDMI_MSG_EQ_FLOW) != 0)
        dbg_printf(DAT_a0067058, (char)(port + 'A'), fn_);
    if (hdmi_eq_scan_records[port].byte_0x8 == 1) {
        /* Phase 1: set the RVGA gain of every channel that still fails. */
        for (ch = 0; ch <= 2; ch++) {
            if (hdmi_eq_port_records[port].channel_ok[ch] == 1)
                continue;
            if (hdmi_eq_port_records[port].rvga_index[ch] > (hdmi_eq_scan_records[port].byte_0x8 ? 3u : 1u))
                continue;
            if (hdmi_eq_port_records[port].rvga_index[ch] < (hdmi_eq_scan_records[port].byte_0x8 ? 3u : 1u)) {
                /* Try the next RVGA index. */
                if (ch < 3)
                    hdmi_phy_write_bit(1, RVGA_ENABLE_BIT, port, hdmi_phy_channel_regs_0x134[ch]);
                if (ch < 3)
                    hdmi_phy_update_reg(port, hdmi_phy_channel_regs_0x128[ch], RVGA_FIELD_MASK,
                                 (hdmi_eq_rvga_values[hdmi_eq_port_records[port].rvga_index[ch]] & 0xf) << RVGA_FIELD_SHIFT);
                if ((dbg_hdmi_message_flags & HDMI_MSG_EQ_FLOW) != 0)
                    dbg_printf("[EQ]: # Port%c, CH%d, apply HDMI_RVGA_TABLE[%d] = 0x%02x\n\n", (char)(port + 'A'),
                                 ch, hdmi_eq_port_records[port].rvga_index[ch], hdmi_eq_rvga_values[hdmi_eq_port_records[port].rvga_index[ch]]);
            } else {
                /* Every RVGA index failed: take the one with the fewest errors. */
                best_errors = hdmi_eq_port_records[port].scdc_errors[0][ch];
                best_index = 0;
                for (i = 1; i < (hdmi_eq_scan_records[port].byte_0x8 ? 3u : 1u); i++) {
                    errors = hdmi_eq_port_records[port].scdc_errors[i][ch];
                    if ((dbg_hdmi_message_flags & HDMI_MSG_EQ_FLOW) != 0)
                        dbg_printf("[EQ]: # Port%c, CH%d, index = %d  u32TotalSCDC = %ld  vs u8BestVGAIdx = %d  u32BestSCDC = %ld  \n",
                                     (char)(port + 'A'), ch, i, errors, best_index, best_errors);
                    if (errors < best_errors) {
                        best_errors = errors;
                        best_index = i;
                    }
                }
                if ((dbg_hdmi_message_flags & HDMI_MSG_EQ_FLOW) != 0)
                    dbg_printf("[EQ]: # Port%c, CH%d, RVGA is all fail, find Best RVGA !!!!\n", (char)(port + 'A'), ch);
                if ((dbg_hdmi_message_flags & HDMI_MSG_EQ_FLOW) != 0)
                    dbg_printf("[EQ]: # Port%c, CH%d, Best RVGA idx = %d, RVGA_Value = 0x%02x\n\n", (char)(port + 'A'),
                                 ch, best_index, hdmi_eq_rvga_values[best_index]);
                if (ch < 3)
                    hdmi_phy_update_reg(port, hdmi_phy_channel_regs_0x128[ch], RVGA_FIELD_MASK, (hdmi_eq_rvga_values[best_index] & 0xf) << RVGA_FIELD_SHIFT);
            }
        }

        /* Phase 2: check the errors again with the new gains. */
        hdmi_phy_pulse_channel_regs(port);
        hdmi_eq_wait_passes[port] = EQ_WAIT_PASSES;
        hdmi_eq_port_records[port].byte_0x28 = 1;
        hdmi_eq_port_records[port].wait_count = 0;
        for (ch = 0; ch <= 2; ch++) {
            if (hdmi_eq_port_records[port].channel_ok[ch] != 1) {
                hdmi_eq_port_records[port].pre_aeq_index[ch] = 0;
                hdmi_eq_port_records[port].pre_aeq_done[ch] = 0;
                hdmi_eq_port_records[port].byte_0x34[ch] = 0;
            }
        }
        hdmi_eq_scan_records[port].state = EQSCAN_STATE_CHKERROR;
        hdmi_eq_port_records[port].wait_count = 0;
        return 1;
    }

    /* Phase 3 (byte_0x8 clear): more EQ table entries to try, or finish. */
    if (hdmi_eq_port_records[port].eq_table_index[0] <= EQ_TABLE_LAST_INDEX || hdmi_eq_port_records[port].eq_table_index[1] <= EQ_TABLE_LAST_INDEX ||
        hdmi_eq_port_records[port].eq_table_index[2] <= EQ_TABLE_LAST_INDEX) {
        if ((dbg_hdmi_message_flags & HDMI_MSG_EQ_FLOW) != 0)
            dbg_printf("[EQ]: # Port%c,Goto FSM_EQSCAN_SEARCH_EQTABLE\n", (char)(port + 'A'));
        hdmi_eq_scan_records[port].state = EQSCAN_STATE_SEARCH_EQTABLE;
    } else {
        hdmi_eq_scan_records[port].state = EQSCAN_STATE_DONE;
        hdmi_eq_port_records[port].byte_0x896 = 0;
    }
    return 1;
}
