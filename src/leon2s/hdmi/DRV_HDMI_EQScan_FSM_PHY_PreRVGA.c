/* DRV_HDMI_EQScan_FSM_PHY_PreRVGA  (DRV_HDMI_EQScan_FSM_PHY_PreRVGA)
 *
 * EQ scan step: choose the RVGA gain per channel, then the best RCT value.
 *   port: PHY
 * Note: State function of the EQ scan table run by hdmi_eq_run_scan_fsm.
 * Name basis: proven - original name printed: 'DRV_HDMI_EQScan_FSM_PHY_PreRVGA'
 *
 * Matching notes
 * --------------
 * DRV_HDMI_EQScan_FSM_PHY_PreRVGA (leon2s 0xa0076180-0xa0076e68, 3304 bytes), flags -mcpu=v8 -Os -g -msoft-float.
 * Source forms the exact build depends on:
 *  - old-style (K&R) definition with an unsigned char parameter (zero-extended at each use);
 *  - the limits are written '(byte_0x8 ? 3u : 1u)', '(byte_0x8 ? 9u : 0xdu)', '(byte_0x8 ? 4u : 6u)' and the
 *    divisor '(byte_0x8 ? 5u : 7u)' (byte_0x8 read again at each use);
 *  - the printed register value is an if/else into its own variable (reg_value);
 *  - the two zero tests of the second round are nested ifs;
 *  - the first row word is read with entry = 0 before the entry loop;
 *  - the entry index byte is stored before the count word;
 *  - the "u32TotalSCDC" format string is the same literal as in RCT_Value (one copy in the image).
 */

/* Message groups of dbg_hdmi_message_flags: every print of the EQ scan is in group EQ_FLOW. */
#define HDMI_MSG_EQ_FLOW 0x02

/* States of the EQ scan: the index into hdmi_eq_scan_state_handlers. */
#define EQSCAN_STATE_PHY_INIT 0         /* after hdmi_eq_find_best_rct has put the port into error mode */
#define EQSCAN_STATE_PRE_AEQ  7         /* DRV_HDMI_EQScan_FSM_PHY_PreAEQ */
#define EQSCAN_STATE_RUN_AEQ  8         /* DRV_HDMI_EQScan_FSM_PHY_RunAEQ */

#define ERR_COUNT_GOOD_BELOW 0x10       /* an error count below this makes a pre-AEQ entry good (as in R_ChkError) */

/* The RVGA gain field: bits 20..23 of the channel's register 0x128, written after bit 15 of its register
   0x134 is set (as in Search_Process). */
#define RVGA_FIELD_MASK     0xff0fffff
#define RVGA_FIELD_SHIFT    20
#define RVGA_ENABLE_BIT     0x0f
#define RVGA_HDMI21         0xf00000    /* the gain field value an HDMI 2.1 PHY always gets */

/* The scan state of one port (12 bytes per port). byte_0x8 set: AEQ, 3 RVGA indexes and pre-AEQ entries
   0..9 (halves of 5); clear: MEQ, 1 RVGA index and entries 0..13 (halves of 7). */
struct eq_scan_record {
    unsigned int state;                 /* EQSCAN_STATE_*: the step hdmi_eq_run_scan_fsm runs next */
    unsigned char byte_0x4[3];
    unsigned char check_error_round;
    unsigned char byte_0x8;
    unsigned char pad[3];
};

/* The result hdmi_eq_find_best_rct stores per channel. */
struct rct_result { unsigned char rct; unsigned char byte_1; unsigned short cct; };

/* The EQ scan work record of one port (0x898 bytes). Arrays of 3 are per channel. */
struct eq_scan_channels {
    unsigned char byte_0x0[9];
    unsigned char rvga_index[3];        /* RVGA gain index in use ("RVGA_Idx") */
    unsigned char byte_0xc[0x2d - 0xc];
    unsigned char rvga_done[3];         /* 1: "PreRVGA is done" for this channel */
    unsigned char wait_count;           /* passes of a waiting step so far */
    unsigned char byte_0x31[0x80 - 0x31];
    unsigned int pre_aeq_err_count[3][14][3];       /* [rvga][entry][ch], filled by R_ChkError */
    unsigned char byte_0x278[0x470 - 0x278];
    unsigned int pre_aeq_errors_lower[6][7][3];     /* +0x470: [rvga][entry][ch], first half of the entries */
    unsigned int pre_aeq_errors_upper[6][7][3];     /* +0x668: second half */
    unsigned short use_upper[6][3];                 /* +0x860: [rvga][ch], read by hdmi_eq_find_best_rct */
    struct rct_result result[3];                    /* +0x884 */
    unsigned char best_rvga_index[3];               /* +0x890: the RVGA index chosen here */
    unsigned char best_length[3];                   /* +0x893: its number of good entries ("u32BestLength") */
    unsigned char byte_0x896[2];
};
extern struct eq_scan_channels hdmi_eq_port_records[];
extern struct eq_scan_record hdmi_eq_scan_records[];
extern unsigned int dbg_hdmi_message_flags;
extern const unsigned char hdmi_eq_rvga_values[];
extern const unsigned short hdmi_phy_channel_regs_0x128[];
extern const unsigned short hdmi_phy_channel_regs_0x134[];
extern unsigned char DAT_a0066df8[];    /* "[EQ]: Port%c %s: (%u-th)" */
extern int dbg_printf(const void *, ...);
extern void *lib_memset(unsigned char *dst, unsigned char v, int n);
extern unsigned int hdmi_phy_read_reg(unsigned int, unsigned short);
extern void hdmi_phy_write_bit(int, unsigned int, unsigned char, unsigned short);
extern void hdmi_phy_update_reg(unsigned int, unsigned short, unsigned int, unsigned int);
extern unsigned char hdmi_is_hdmi21_phy(unsigned char);
extern unsigned char hdmi_eq_find_best_rct(int, int);
extern void hdmi_eq_print_channel_values(unsigned int port);

static const char fn_[] = "DRV_HDMI_EQScan_FSM_PHY_PreRVGA";

/*
 * EQ scan state 6. PreAEQ (state 7) comes here each time every channel has run through the pre-AEQ table
 * with its current RVGA index; BA turning (state 5, AEQ without the recheck flag) and the pre-check step
 * (state 10) come here as well.
 *
 *   port  HDMI receiver PHY (printed as the letter 'A' + port)
 *
 * Returns 0 when hdmi_eq_find_best_rct puts the port into error mode (the scan then goes back to state 0),
 * else 1 (hdmi_eq_run_scan_fsm runs the next state at once).
 *
 * Phases, per channel without a result (rvga_done clear):
 *  1. RVGA index still below the count (3 in AEQ, 1 in MEQ): write the gain of that index (0xf on an HDMI
 *     2.1 PHY, else hdmi_eq_rvga_values[rvga_index]) and leave the channel to PreAEQ.
 *  2. All RVGA indexes tried: for each RVGA index count the good entries (error count below 0x10) of
 *     pre_aeq_err_count, in total and per half, copy the counts into pre_aeq_errors_lower / _upper and set
 *     use_upper (always in AEQ, else when the upper half has at least as many good entries).
 *  3. First round: the RVGA index with the most good entries (the first one on a tie).
 *  4. Second round, only when no RVGA index has a good entry: per RVGA index the smallest count of one half
 *     (the lower half in MEQ, the upper half in AEQ), then the RVGA index with the smallest of those.
 *  5. Store best_length and best_rvga_index and let hdmi_eq_find_best_rct choose the RCT value; when it
 *     returns 0 go back to state 0. Else write the gain of the chosen RVGA index and mark the channel done.
 * Then clear wait_count and go to RunAEQ (state 8) after printing the channel values when all three channels
 * are done, else back to PreAEQ (state 7).
 */
int DRV_HDMI_EQScan_FSM_PHY_PreRVGA(port)
    unsigned char port;
{
    unsigned char good_count[6][3];             /* [rvga][ch]: entries with an error count below 0x10 */
    unsigned char best_entry_index[6][3];       /* [rvga][ch]: second round, entry with the smallest count */
    unsigned int smallest_errors[6][3];         /* [rvga][ch]: second round, that count */
    unsigned char ch = 0;
    unsigned char rvga;
    unsigned char entry;
    unsigned char half_entry = 0;
    unsigned char best_entry = 0;
    unsigned char lower_good = 0;
    unsigned char upper_good = 0;
    unsigned char best_rvga;
    unsigned int best_length;
    unsigned int value;
    unsigned int smallest;
    unsigned int reg_value;

    lib_memset((unsigned char *)good_count, 0, sizeof(good_count));
    lib_memset((unsigned char *)best_entry_index, 0, sizeof(best_entry_index));
    lib_memset((unsigned char *)smallest_errors, 0, sizeof(smallest_errors));
    if ((dbg_hdmi_message_flags & HDMI_MSG_EQ_FLOW) != 0)
        dbg_printf(DAT_a0066df8, (char)(port + 'A'), fn_, hdmi_eq_port_records[port].wait_count);
    for (; ch < 3; ch++) {
        if (hdmi_eq_port_records[port].rvga_done[ch] == 1) {
            if ((dbg_hdmi_message_flags & HDMI_MSG_EQ_FLOW) != 0)
                dbg_printf("[EQ]: # Port%c, CH%d, -------1 PreRVGA is done, bypass PreAEQ------- \n",
                             (char)(port + 'A'), ch);
            continue;
        }

        /* Phase 1: the next RVGA gain to try. */
        if (hdmi_eq_port_records[port].rvga_index[ch] < (hdmi_eq_scan_records[port].byte_0x8 ? 3u : 1u)) {
            if (ch < 3)
                hdmi_phy_write_bit(1, RVGA_ENABLE_BIT, port, hdmi_phy_channel_regs_0x134[ch]);
            if (hdmi_is_hdmi21_phy(port)) {
                if (ch < 3)
                    hdmi_phy_update_reg(port, hdmi_phy_channel_regs_0x128[ch], RVGA_FIELD_MASK, RVGA_HDMI21);
            } else {
                if (ch < 3)
                    hdmi_phy_update_reg(port, hdmi_phy_channel_regs_0x128[ch], RVGA_FIELD_MASK,
                                 (hdmi_eq_rvga_values[hdmi_eq_port_records[port].rvga_index[ch]] & 0xf) << RVGA_FIELD_SHIFT);
            }
            if ((dbg_hdmi_message_flags & HDMI_MSG_EQ_FLOW) != 0) {
                if (ch < 3)
                    reg_value = (hdmi_phy_read_reg(port, hdmi_phy_channel_regs_0x128[ch]) >> RVGA_FIELD_SHIFT) & 0xf;
                else
                    reg_value = 0;
                dbg_printf("[EQ]: # Port%c, CH%d,  RVGA Reg value = 0x%02lx\n\n", (char)(port + 'A'), ch, reg_value);
            }
            continue;
        }

        /* Phase 2: good entries per RVGA index, and the counts split into the two halves. */
        for (rvga = 0; rvga < (hdmi_eq_scan_records[port].byte_0x8 ? 3u : 1u); rvga++) {
            for (entry = 0; entry <= (hdmi_eq_scan_records[port].byte_0x8 ? 9u : 0xdu); entry++) {
                if (hdmi_eq_port_records[port].pre_aeq_err_count[rvga][entry][ch] < ERR_COUNT_GOOD_BELOW) {
                    good_count[rvga][ch]++;
                    if (entry / (hdmi_eq_scan_records[port].byte_0x8 ? 5u : 7u) == 0)
                        lower_good++;
                    else
                        upper_good++;
                }
                if (entry / (hdmi_eq_scan_records[port].byte_0x8 ? 5u : 7u) == 0)
                    hdmi_eq_port_records[port].pre_aeq_errors_lower[rvga][entry % (hdmi_eq_scan_records[port].byte_0x8 ? 5u : 7u)][ch] =
                        hdmi_eq_port_records[port].pre_aeq_err_count[rvga][entry][ch];
                else
                    hdmi_eq_port_records[port].pre_aeq_errors_upper[rvga][entry % (hdmi_eq_scan_records[port].byte_0x8 ? 5u : 7u)][ch] =
                        hdmi_eq_port_records[port].pre_aeq_err_count[rvga][entry][ch];
            }
            hdmi_eq_port_records[port].use_upper[rvga][ch] = hdmi_eq_scan_records[port].byte_0x8 != 0 || upper_good >= lower_good;
            upper_good = 0;
            lower_good = 0;
        }
        if ((dbg_hdmi_message_flags & HDMI_MSG_EQ_FLOW) != 0)
            dbg_printf("[EQ]: # Port%c : =========================================\n", (char)(port + 'A'));
        for (rvga = 0; rvga < (hdmi_eq_scan_records[port].byte_0x8 ? 3u : 1u); rvga++) {
            if ((dbg_hdmi_message_flags & HDMI_MSG_EQ_FLOW) != 0)
                dbg_printf("[EQ]: RVGA : 0x%02x =>\n", rvga);
            if ((dbg_hdmi_message_flags & HDMI_MSG_EQ_FLOW) != 0)
                dbg_printf("[EQ]: Ch%d , length = 0x%d\n", ch, good_count[rvga][ch]);
        }

        /* Phase 3: first round, the most good entries. */
        if ((dbg_hdmi_message_flags & HDMI_MSG_EQ_FLOW) != 0)
            dbg_printf("[EQ]: # Port%c, CH%d, u8RVGA_Index = 0  , u32Length = %d  \n", (char)(port + 'A'), ch,
                         good_count[0][ch]);
        best_length = good_count[0][ch];
        best_rvga = 0;
        for (rvga = 1; rvga < (hdmi_eq_scan_records[port].byte_0x8 ? 3u : 1u); rvga++) {
            value = good_count[rvga][ch];
            if ((dbg_hdmi_message_flags & HDMI_MSG_EQ_FLOW) != 0)
                dbg_printf("[EQ]: # Port%c, CH%d, index = %d  u32Length = %ld  / u8BestRVGAIdx = %d  u32BestLength = %ld  \n",
                             (char)(port + 'A'), ch, rvga, value, best_rvga, best_length);
            if (value > best_length) {
                best_length = value;
                best_rvga = rvga;
            }
        }
        if ((dbg_hdmi_message_flags & HDMI_MSG_EQ_FLOW) != 0)
            dbg_printf("[EQ]: # Port%c, CH%d, 1-th round, u8BestRVGAIdx = %d  u32BestLength = %ld  \n",
                         (char)(port + 'A'), ch, best_rvga, best_length);

        /* Phase 4: second round, when no RVGA index has a good entry: the smallest error count. */
        if (best_rvga == 0) {
            if (best_length == 0) {
                for (rvga = 0; rvga < (hdmi_eq_scan_records[port].byte_0x8 ? 3u : 1u); rvga++) {
                    best_entry = 0;
                    half_entry = 0;
                    if (hdmi_eq_scan_records[port].byte_0x8 == 0)
                        smallest = hdmi_eq_port_records[port].pre_aeq_errors_lower[rvga][half_entry][ch];
                    else
                        smallest = hdmi_eq_port_records[port].pre_aeq_errors_upper[rvga][half_entry][ch];
                    for (half_entry = 0; half_entry <= (hdmi_eq_scan_records[port].byte_0x8 ? 4u : 6u); half_entry++) {
                        if (hdmi_eq_scan_records[port].byte_0x8 == 0)
                            value = hdmi_eq_port_records[port].pre_aeq_errors_lower[rvga][half_entry][ch];
                        else
                            value = hdmi_eq_port_records[port].pre_aeq_errors_upper[rvga][half_entry][ch];
                        if ((dbg_hdmi_message_flags & HDMI_MSG_EQ_FLOW) != 0)
                            dbg_printf("[EQ]: # Port%c, CH%d, index = %d  u32TotalSCDC = %ld  / u8BestRCTIdx = %d  u32BestSCDC = %ld  \n",
                                     (char)(port + 'A'), ch, half_entry, value, best_entry, smallest);
                        if (value < smallest) {
                            best_entry = half_entry;
                            smallest = value;
                        }
                    }
                    best_entry_index[rvga][ch] = best_entry;
                    smallest_errors[rvga][ch] = smallest;
                }
                smallest = smallest_errors[0][ch];
                best_rvga = 0;
                for (rvga = 0; rvga < (hdmi_eq_scan_records[port].byte_0x8 ? 3u : 1u); rvga++) {
                    value = smallest_errors[rvga][ch];
                    /* The index and best-entry values printed here are those left by the loop above. */
                    if ((dbg_hdmi_message_flags & HDMI_MSG_EQ_FLOW) != 0)
                        dbg_printf("[EQ]: # Port%c, CH%d, index = %d  u32TotalSCDC = %ld  / u8BestRCTIdx = %d  u32BestSCDC = %ld  \n",
                                 (char)(port + 'A'), ch, half_entry, value, best_entry, smallest);
                    if (value < smallest) {
                        smallest = value;
                        best_rvga = rvga;
                    }
                }
            }
        }
        if ((dbg_hdmi_message_flags & HDMI_MSG_EQ_FLOW) != 0)
            dbg_printf("[EQ]: # Port%c, CH%d, 2-th round, u8BestRVGAIdx = %d  u32BestLength = %ld  \n",
                         (char)(port + 'A'), ch, best_rvga, best_length);

        /* Phase 5: the RCT value for the chosen RVGA index, then its gain. */
        hdmi_eq_port_records[port].best_length[ch] = best_length;
        hdmi_eq_port_records[port].best_rvga_index[ch] = best_rvga;
        if (hdmi_eq_find_best_rct(port, ch) == 0) {
            hdmi_eq_scan_records[port].state = EQSCAN_STATE_PHY_INIT;
            return 0;
        }
        if (ch < 3)
            hdmi_phy_write_bit(1, RVGA_ENABLE_BIT, port, hdmi_phy_channel_regs_0x134[ch]);
        if (hdmi_is_hdmi21_phy(port)) {
            if (ch < 3)
                hdmi_phy_update_reg(port, hdmi_phy_channel_regs_0x128[ch], RVGA_FIELD_MASK, RVGA_HDMI21);
        } else {
            if (ch < 3)
                hdmi_phy_update_reg(port, hdmi_phy_channel_regs_0x128[ch], RVGA_FIELD_MASK, (hdmi_eq_rvga_values[best_rvga] & 0xf) << RVGA_FIELD_SHIFT);
        }
        hdmi_eq_port_records[port].rvga_done[ch] = 1;
    }

    /* All channels done: run AEQ with the results; else PreAEQ tries the next RVGA gain. */
    hdmi_eq_port_records[port].wait_count = 0;
    if (hdmi_eq_port_records[port].rvga_done[0] == 1 && hdmi_eq_port_records[port].rvga_done[1] == 1 && hdmi_eq_port_records[port].rvga_done[2] == 1) {
        hdmi_eq_print_channel_values(port);
        hdmi_eq_scan_records[port].state = EQSCAN_STATE_RUN_AEQ;
    } else {
        hdmi_eq_scan_records[port].state = EQSCAN_STATE_PRE_AEQ;
    }
    return 1;
}
