/* DRV_HDMI_EQScan_FSM_PHY_R_ChkError  (DRV_HDMI_EQScan_FSM_PHY_R_ChkError)
 *
 * EQ scan step: collect SCDC error counts per channel and step the pre-AEQ index.
 *   port: PHY
 * Note: State function of the EQ scan table run by hdmi_eq_run_scan_fsm.
 * Name basis: proven - original name printed: 'DRV_HDMI_EQScan_FSM_PHY_R_ChkError'
 *
 * Matching notes
 * --------------
 * leon2s DRV_HDMI_EQScan_FSM_PHY_R_ChkError @ 0xa0077f04-0xa00787f4 (2288 bytes), flags -mcpu=v8 -Os -g
 * (section default).
 * Source forms the exact build depends on:
 *  - wait_count is the 4th argument of the "(Done %u-th)" print;
 *  - the status bytes are assigned with '?:', so the array address is formed before the value;
 *  - the limit test is the inline helper pre_aeq_index_ok with an unsigned limit (its index argument is read
 *    before the byte_0x8 test);
 *  - the switch cases are in ascending order; the search_step word is addressed through a pointer taken
 *    between the two skip tests; the stores are in the firmware's order.
 */

/* Message groups of dbg_hdmi_message_flags: every print of the EQ scan is in group EQ_FLOW. */
#define HDMI_MSG_EQ_FLOW 0x02

/* States of the EQ scan: the index into hdmi_eq_scan_state_handlers. */
#define EQSCAN_STATE_PRE_AEQ 7          /* DRV_HDMI_EQScan_FSM_PHY_PreAEQ */

/* PHY registers read here. Each channel has a 16-bit error count: bits 0..14 are the count (printed as
   u32SCDCError), bit 15 is masked off. */
#define PHY_REG_ERR_COUNT_A 0x1ea0      /* bits 0..7 printed as "0xA0"; ch 0 bits 8..23; ch 1 high byte 24..31 */
#define PHY_REG_ERR_COUNT_B 0x1ea4      /* ch 1 low byte 0..7; ch 2 bits 8..23 */
#define PHY_REG_1E94        0x1e94      /* status byte of ch 0 (bits 24..31) */
#define PHY_REG_1E98        0x1e98      /* status bytes of ch 1 (bits 0..7) and ch 2 (bits 8..15) */

/* An error count below this ends a search step: the pre-AEQ index is good. */
#define ERR_COUNT_GOOD_BELOW 0x10

/* The scan state of one port (12 bytes per port). byte_0x8 sets the sizes of the scan: pre-AEQ indexes 0..9
   and three RVGA indexes when set, pre-AEQ indexes 0..13 and one RVGA index when clear. */
struct eq_scan_record {
    unsigned int state;                 /* EQSCAN_STATE_*: the step hdmi_eq_run_scan_fsm runs next */
    unsigned char byte_0x4[3];
    unsigned char check_error_round;    /* printed as the round by the error check */
    unsigned char byte_0x8;
    unsigned char pad[3];
};

/* The EQ scan work record of one port (0x898 bytes). Arrays of 3 are per channel. */
struct eq_scan_channels {
    unsigned char byte_0x0[3];
    unsigned char pre_aeq_index[3];     /* the pre-AEQ table entry PreAEQ applies next ("PreAEQ_Idx") */
    unsigned char byte_0x6[3];
    unsigned char rvga_index[3];        /* RVGA gain index in use ("RVGA_Idx") */
    unsigned char byte_0xc[4];
    unsigned int search_step[3];        /* 0..3: which edge of which half the pre-AEQ search looks for */
    unsigned char edge_index[4][3];     /* [search_step]: the pre-AEQ index that step ended on */
    unsigned char byte_0x28[2];
    unsigned char pre_aeq_done[3];      /* 1: all pre-AEQ indexes of this RVGA index are done */
    unsigned char rvga_done[3];         /* 1: "PreRVGA is done" for this channel */
    unsigned char wait_count;           /* passes of a waiting step so far */
    unsigned char byte_0x31[0x4f];
    unsigned int pre_aeq_err_count[3][14][3];   /* [rvga][pre][ch], printed as u32PreAEQErrCnt */
    unsigned char byte_0x278[0x898 - 0x80 - 3 * 14 * 3 * 4];
};
extern struct eq_scan_channels hdmi_eq_port_records[];
extern struct eq_scan_record hdmi_eq_scan_records[];
extern unsigned int dbg_hdmi_message_flags;
extern unsigned char hdmi_eq_wait_passes[];
extern unsigned char hdmi_eq_pre_aeq_fails_lower[][3];
extern unsigned char hdmi_eq_pre_aeq_fails_upper[][3];
extern unsigned char DAT_a0067428[], DAT_a0067450[];
extern int dbg_printf(const void *, ...);
extern void DRV_HDMI_PHY_Clr_EQ_Err(unsigned int);
extern unsigned int hdmi_phy_read_reg(unsigned int, unsigned short);
extern unsigned int hdmi_phy_test_bit(unsigned int, unsigned char, unsigned short);

/* 1 when index is a valid pre-AEQ index: up to 9 when byte_0x8 of the port's scan record is set, else up
   to 13. The index one past that ends the search of a channel. */
static inline int pre_aeq_index_ok(unsigned char port, unsigned char index)
{
    return index <= (hdmi_eq_scan_records[port].byte_0x8 ? 9u : 0xdu);
}

/*
 * EQ scan state 12. Runs after the pre-AEQ step (state 7) has written the RCT/CFT entry of pre_aeq_index to
 * the channels: it records how many errors each channel shows with that entry and chooses the next index.
 *
 *   port  HDMI receiver PHY (0..3; printed as the letter 'A' + port)
 *
 * Returns 0 while it waits (hdmi_eq_run_scan_fsm then stops until its next call), 1 when it has moved the
 * scan on to state 7.
 *
 * Phases:
 *  1. Wait: the step returns 0 until it has been called hdmi_eq_wait_passes[port] times. On the first
 *     pass, with more than one pass to wait, it calls DRV_HDMI_PHY_Clr_EQ_Err first. The pre-AEQ step
 *     sets that pass count to 1, clears wait_count and calls DRV_HDMI_PHY_Clr_EQ_Err itself before it
 *     hands over, so from there the step measures on its first call.
 *  2. Read: per channel not yet done (rvga_done), the 15-bit error count; it is printed and stored in
 *     pre_aeq_err_count[rvga_index][pre_aeq_index][channel] while the index is valid.
 *  3. Step: per channel still searching, pick the next pre-AEQ index. The valid indexes form two halves,
 *     0..4 / 5..9 when byte_0x8 is set, 0..6 / 7..13 when it is clear, and the search_step says what is
 *     being looked for:
 *       step 0  up from 0 for the first good index of the lower half,
 *       step 1  down from the top of the lower half,
 *       step 2  up from the start of the upper half,
 *       step 3  down from the top of the upper half.
 *     A good count (below 0x10) stores the index in edge_index[step] and jumps to the start of the next
 *     step; a bad one moves the index one on. Moving down onto the edge found by the step before ends that
 *     step with both edges equal. Step 3 ends the channel by setting the index past the end, and so does
 *     the upper half once it has had more bad counts than the lower half (both counted from index 0).
 *  4. Back to state 7, which applies the new indexes (or marks a channel done when its index is past the end).
 */
int DRV_HDMI_EQScan_FSM_PHY_R_ChkError(unsigned char port)
{
    unsigned int status[3] = {0};       /* read and not used further */
    unsigned int err_count[3] = {0};
    unsigned char ch;
    unsigned char pre;
    unsigned char rvga;
    unsigned int count;
    unsigned int *step;

    /* Phase 1: wait for the channels to settle on the new entry. */
    if (hdmi_eq_port_records[port].wait_count == 0) {
        if ((dbg_hdmi_message_flags & HDMI_MSG_EQ_FLOW) != 0)
            dbg_printf(DAT_a0067428, (char)(port + 'A'), "DRV_HDMI_EQScan_FSM_PHY_R_ChkError");
    }
    if (hdmi_eq_port_records[port].wait_count == 0 && hdmi_eq_wait_passes[port] > 1)
        DRV_HDMI_PHY_Clr_EQ_Err(port);
    if (++hdmi_eq_port_records[port].wait_count < hdmi_eq_wait_passes[port])
        return 0;
    if ((dbg_hdmi_message_flags & HDMI_MSG_EQ_FLOW) != 0)
        dbg_printf(DAT_a0067450, (char)(port + 'A'), "DRV_HDMI_EQScan_FSM_PHY_R_ChkError",
                     hdmi_eq_port_records[port].wait_count);

    /* Phase 2: read and store the error count of every channel that is not done. */
    for (ch = 0; ch < 3; ch++) {
        if (hdmi_eq_port_records[port].rvga_done[ch] == 1)
            continue;
        if (ch == 0) {
            status[ch] = hdmi_phy_test_bit(0, port, PHY_REG_ERR_COUNT_A) == 0 ? hdmi_phy_read_reg(port, PHY_REG_1E94) >> 24 : 0;
            err_count[ch] = (hdmi_phy_read_reg(port, PHY_REG_ERR_COUNT_A) & 0xff00) | ((hdmi_phy_read_reg(port, PHY_REG_ERR_COUNT_A) >> 16) & 0xff);
        } else if (ch == 1) {
            status[ch] = hdmi_phy_test_bit(1, port, PHY_REG_ERR_COUNT_A) == 0 ? hdmi_phy_read_reg(port, PHY_REG_1E98) & 0xff : 0;
            err_count[ch] = ((hdmi_phy_read_reg(port, PHY_REG_ERR_COUNT_A) & 0xff000000) >> 16) | (hdmi_phy_read_reg(port, PHY_REG_ERR_COUNT_B) & 0xff);
        } else {
            status[ch] = hdmi_phy_test_bit(2, port, PHY_REG_ERR_COUNT_A) == 0 ? (hdmi_phy_read_reg(port, PHY_REG_1E98) >> 8) & 0xff : 0;
            err_count[ch] = (hdmi_phy_read_reg(port, PHY_REG_ERR_COUNT_B) & 0xff00) | ((hdmi_phy_read_reg(port, PHY_REG_ERR_COUNT_B) >> 16) & 0xff);
        }
        if ((dbg_hdmi_message_flags & HDMI_MSG_EQ_FLOW) != 0)
            dbg_printf("[EQ]: # Port%c, CH%d , u32SCDCError[%d] = 0x%04lx , 0xA0 = 0x%02lx #\n", (char)(port + 'A'), ch, ch, err_count[ch] & 0x7fff,
                         hdmi_phy_read_reg(port, PHY_REG_ERR_COUNT_A) & 0xff);
        if (pre_aeq_index_ok(port, hdmi_eq_port_records[port].pre_aeq_index[ch])) {
            pre = hdmi_eq_port_records[port].pre_aeq_index[ch];
            rvga = hdmi_eq_port_records[port].rvga_index[ch];
            count = err_count[ch] & 0x7fff;
            hdmi_eq_port_records[port].pre_aeq_err_count[rvga][pre][ch] = count;
            if ((dbg_hdmi_message_flags & HDMI_MSG_EQ_FLOW) != 0)
                dbg_printf("[EQ]: # Port%c, CH%d , u32PreAEQErrCnt[%d][%d][%d] = 0x%04lx #\n", (char)(port + 'A'), ch, rvga, pre, ch, count);
        }
    }

    /* Phase 3: choose the next pre-AEQ index of every channel still searching. */
    for (ch = 0; ch < 3; ch++) {
        if (hdmi_eq_port_records[port].rvga_done[ch] == 1)
            continue;
        step = &hdmi_eq_port_records[port].search_step[ch];
        if (hdmi_eq_port_records[port].pre_aeq_done[ch] != 0)
            continue;
        if (!pre_aeq_index_ok(port, hdmi_eq_port_records[port].pre_aeq_index[ch]))
            continue;
        /* A new search (index 0) starts both bad counts from zero. */
        if (hdmi_eq_port_records[port].pre_aeq_index[ch] == 0) {
            hdmi_eq_pre_aeq_fails_lower[port][ch] = 0;
            hdmi_eq_pre_aeq_fails_upper[port][ch] = 0;
        }
        if ((err_count[ch] & 0x7fff) < ERR_COUNT_GOOD_BELOW) {
            /* Good: this index is the edge the step looked for; go to the start of the next step. */
            hdmi_eq_port_records[port].edge_index[*step][ch] = hdmi_eq_port_records[port].pre_aeq_index[ch];
            switch (*step) {
            case 0:     /* top of the lower half */
                hdmi_eq_port_records[port].pre_aeq_index[ch] = hdmi_eq_scan_records[port].byte_0x8 ? 4 : 6;
                break;
            case 1:     /* start of the upper half */
                hdmi_eq_port_records[port].pre_aeq_index[ch] = hdmi_eq_scan_records[port].byte_0x8 ? 5 : 7;
                break;
            case 2:     /* top of the upper half */
                hdmi_eq_port_records[port].pre_aeq_index[ch] = hdmi_eq_scan_records[port].byte_0x8 ? 9 : 0xd;
                break;
            case 3:     /* past the end: this channel is finished */
                hdmi_eq_port_records[port].pre_aeq_index[ch] = hdmi_eq_scan_records[port].byte_0x8 ? 10 : 0xe;
                break;
            }
            if (pre_aeq_index_ok(port, hdmi_eq_port_records[port].pre_aeq_index[ch]))
                *step = *step + 1;
        } else {
            /* Bad: count it. In the upper half (steps 2 and 3) the search ends once it has had more
               bad counts than the lower half. */
            if (*step - 2 < 2) {
                if (++hdmi_eq_pre_aeq_fails_upper[port][ch] > hdmi_eq_pre_aeq_fails_lower[port][ch])
                    hdmi_eq_port_records[port].pre_aeq_index[ch] = hdmi_eq_scan_records[port].byte_0x8 ? 10 : 0xe;
            } else {
                hdmi_eq_pre_aeq_fails_lower[port][ch]++;
            }
            if (pre_aeq_index_ok(port, hdmi_eq_port_records[port].pre_aeq_index[ch])) {
                switch (*step) {
                case 0:
                case 2:
                    /* Up; running out of the lower half skips step 1. */
                    if (++hdmi_eq_port_records[port].pre_aeq_index[ch] == (hdmi_eq_scan_records[port].byte_0x8 ? 5 : 7))
                        *step = 2;
                    break;
                case 1:
                    /* Down; reaching the lower edge leaves both edges of the lower half equal. */
                    if (--hdmi_eq_port_records[port].pre_aeq_index[ch] == hdmi_eq_port_records[port].edge_index[0][ch]) {
                        *step = 2;
                        hdmi_eq_port_records[port].pre_aeq_index[ch] = hdmi_eq_scan_records[port].byte_0x8 ? 5 : 7;
                        hdmi_eq_port_records[port].edge_index[1][ch] = hdmi_eq_port_records[port].edge_index[0][ch];
                    }
                    break;
                case 3:
                    /* Down; reaching the lower edge of the upper half ends the channel. */
                    if (--hdmi_eq_port_records[port].pre_aeq_index[ch] == hdmi_eq_port_records[port].edge_index[2][ch]) {
                        hdmi_eq_port_records[port].pre_aeq_index[ch] = hdmi_eq_scan_records[port].byte_0x8 ? 10 : 0xe;
                        hdmi_eq_port_records[port].edge_index[3][ch] = hdmi_eq_port_records[port].edge_index[2][ch];
                    }
                    break;
                }
            }
        }
        if ((dbg_hdmi_message_flags & HDMI_MSG_EQ_FLOW) != 0)
            dbg_printf("[EQ]: * Port%c, CH%d, next PreAEQ_Idx = %d\n", (char)(port + 'A'), ch, hdmi_eq_port_records[port].pre_aeq_index[ch]);
    }

    /* Phase 4: the pre-AEQ step applies the new indexes. */
    hdmi_eq_scan_records[port].state = EQSCAN_STATE_PRE_AEQ;
    return 1;
}
