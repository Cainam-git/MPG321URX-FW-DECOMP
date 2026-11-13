/* hdmi_eq_find_best_rct  (RCT_Value)
 *
 * Choose the RCT equaliser value of one channel from the error counts of the candidates.
 *   port: PHY
 *   ch: channel
 * Returns: 1 when a value was stored, 0 when it switched to the error mode instead
 * Note: All candidates error-free: mean of the first and last; some: mean of the first good one from each
 *   side; none: the one with the fewest errors.
 * Name basis: proven - prints 'find best R/C value', 'Best RCT idx = %d, RCT_Value = 0x%02x'
 *
 * Matching notes
 * --------------
 * leon2s RCT_Value @ 0xa0075858-0xa0075ffc (1956 bytes), flags -mcpu=v8 -Os -g (section default).
 * Source forms the exact build depends on:
 *  - old-style (K&R) definition with unsigned char parameters (the arguments arrive as int and are
 *    zero-extended at each use);
 *  - the last index is written '(byte_0x8 ? 4u : 6u)' and re-read at each use;
 *  - the RCT value is computed into a local (rct) before the two stores, written rct first, then cct;
 *  - the upper-half pointer (upper) is taken before the first scan, separate from counts;
 *  - in the error-mode test the 'upper_all_errors = 1' start value is set inside the 'all_have_errors != 1'
 *    arm, right before the upper-half scan.
 */

#define HDMI_MSG_EQ_FLOW        0x02    /* dbg_hdmi_message_flags bit 1: the '[EQ]' lines */
#define ERROR_FREE_LIMIT        0x10    /* left / right search: a count below this counts as good */
#define ERROR_MODE_MIN_GOOD     3       /* fewer error-free entries than this (with no error-free upper entry)
                                           switch the port to error mode */

/* Result of one channel: what DRV_HDMI_EQScan_FSM_PHY_RunAEQ writes to the PHY ('RCT=0x%02x, CCT=0x%04x'). */
struct rct_result { unsigned char rct; unsigned char byte_1; unsigned short cct; };

/* EQ scan data of one PHY (0x898 bytes, hdmi_eq_port_records); the fields used here, each per channel [3]. The
   pre-AEQ error counts of each RVGA index are split by DRV_HDMI_EQScan_FSM_PHY_PreRVGA into a lower and an
   upper half of 7 entries (5 with byte_0x8 set); entry i of a half belongs to RCT candidate i. */
struct eq_scan_channels {
    unsigned char pad_0x0[0x34];
    unsigned char byte_0x34[3];                     /* set to 1 here once the channel's RCT is chosen */
    unsigned char pad_0x37[0x470 - 0x37];
    unsigned int pre_aeq_errors_lower[6][7][3];     /* +0x470: [RVGA index][entry][channel] */
    unsigned int pre_aeq_errors_upper[6][7][3];     /* +0x668 */
    unsigned short use_upper[6][3];                 /* +0x860: 1 = byte_0x8 set or the upper half has at least
                                                       as many good counts as the lower */
    struct rct_result result[3];                    /* +0x884 */
    unsigned char best_rvga_index[3];               /* +0x890: chosen by DRV_HDMI_EQScan_FSM_PHY_PreRVGA */
    unsigned char pad_0x893[0x898 - 0x893];
};
/* EQ scan record of one PHY (12 bytes, hdmi_eq_scan_records). */
struct eq_scan_record {
    unsigned int state;                             /* index into hdmi_eq_scan_state_handlers */
    unsigned int word_0x4;
    unsigned char byte_0x8;                         /* set: 3 RVGA indexes, 10 pre-AEQ entries, 5 RCT candidates;
                                                       clear: 1, 14 and 7 */
    unsigned char pad[3];
};
extern struct eq_scan_channels hdmi_eq_port_records[];
extern struct eq_scan_record hdmi_eq_scan_records[];
extern unsigned char hdmi_eq_error_mode_flags[];
extern unsigned int dbg_hdmi_message_flags;
extern const unsigned char hdmi_eq_rct_candidates_byte8_set[];   /* 6, 8, 10, 12, 15 */
extern const unsigned char hdmi_eq_rct_candidates[];             /* 1, 3, 5, 7, 9, 12, 15 */
extern int dbg_printf(const char *, ...);

/*
 * Choose the RCT value of one channel of a PHY from the error counts of the chosen RVGA index.
 *
 *   port  PHY (printed as 'A' + port)
 *   ch    channel 0..2
 *
 * Returns 0 when the port goes into error mode ('Go Into Error Handing'; the caller then sets the scan state
 * to 0), else 1 with the channel's result stored. Called by DRV_HDMI_EQScan_FSM_PHY_PreRVGA for each channel
 * after it has chosen best_rvga_index.
 *
 * Phases:
 *   1. Half: use_upper of the chosen RVGA index picks the lower or the upper error counts, and with them the
 *      candidate table (the byte8_set table only for the upper half with byte_0x8 set) and the CCT value
 *      (lower: 0, or 0xFF; upper: 0xFF, or 0xFFF; the first of each pair in error mode with byte_0x8 clear).
 *   2. Count: are all entries zero (error-free), all non-zero, and how many are zero.
 *   3. Error mode (byte_0x8 clear and not yet in error mode): entered when no entry is zero, or when fewer
 *      than ERROR_MODE_MIN_GOOD are zero and no upper-half entry is zero; then return 0.
 *   4. Pick:  all zero ('all port error free'): the mean of the first and last candidate;
 *             all non-zero: the candidate with the smallest count (the first on ties);
 *             else: the mean of the candidates at the first good entry from the left and from the right
 *             (index 0 when none is found).
 *   5. Store rct and cct in the channel's result, set byte_0x34, return 1.
 */
unsigned char hdmi_eq_find_best_rct(port, ch)
    unsigned char port, ch;
{
    unsigned int (*counts)[3];
    unsigned int (*upper)[3];
    const unsigned char *candidates;
    unsigned short cct;
    unsigned char all_zero, all_have_errors, upper_all_errors, error_free_count, i;
    unsigned char left, right, j, rct;
    unsigned int best_errors, errors;

    if ((dbg_hdmi_message_flags & HDMI_MSG_EQ_FLOW) != 0)
        dbg_printf("[EQ]: # Port%c, Ch%d, ------- find best R/C value ------- , (%d)\n", (char)(port + 'A'), ch,
                     hdmi_eq_port_records[port].use_upper[hdmi_eq_port_records[port].best_rvga_index[ch]][ch]);

    /* 1. Lower or upper half of the chosen RVGA index. */
    if (hdmi_eq_port_records[port].use_upper[hdmi_eq_port_records[port].best_rvga_index[ch]][ch] == 0) {
        if (hdmi_eq_scan_records[port].byte_0x8 == 0 && hdmi_eq_error_mode_flags[port] == 1)
            cct = 0;
        else
            cct = 0xff;
        counts = hdmi_eq_port_records[port].pre_aeq_errors_lower[hdmi_eq_port_records[port].best_rvga_index[ch]];
        candidates = hdmi_eq_rct_candidates;
    } else {
        if (hdmi_eq_scan_records[port].byte_0x8 == 0 && hdmi_eq_error_mode_flags[port] == 1)
            cct = 0xff;
        else
            cct = 0xfff;
        counts = hdmi_eq_port_records[port].pre_aeq_errors_upper[hdmi_eq_port_records[port].best_rvga_index[ch]];
        if (hdmi_eq_scan_records[port].byte_0x8 != 0)
            candidates = hdmi_eq_rct_candidates_byte8_set;
        else
            candidates = hdmi_eq_rct_candidates;
    }
    upper = hdmi_eq_port_records[port].pre_aeq_errors_upper[hdmi_eq_port_records[port].best_rvga_index[ch]];

    /* 2. Error-free entries. */
    all_zero = 1;
    all_have_errors = 1;
    error_free_count = 0;
    for (i = 0; i <= (hdmi_eq_scan_records[port].byte_0x8 ? 4u : 6u); i++) {
        if (counts[i][ch] == 0) {
            all_have_errors = 0;
            error_free_count++;
        } else {
            all_zero = 0;
        }
    }

    /* 3. Error mode. */
    if (hdmi_eq_scan_records[port].byte_0x8 == 0 && hdmi_eq_error_mode_flags[port] == 0) {
        if (all_have_errors == 1) {
            hdmi_eq_error_mode_flags[port] = 1;
        } else {
            upper_all_errors = 1;
            for (i = 0; i <= (hdmi_eq_scan_records[port].byte_0x8 ? 4u : 6u); i++)
                if (upper[i][ch] == 0)
                    upper_all_errors = 0;
            if (upper_all_errors == 1 && error_free_count < ERROR_MODE_MIN_GOOD)
                hdmi_eq_error_mode_flags[port] = 1;
        }
        if (hdmi_eq_error_mode_flags[port] == 1) {
            if ((dbg_hdmi_message_flags & HDMI_MSG_EQ_FLOW) != 0)
                dbg_printf("[EQ]: # Port%c, Ch%d , ------- Go Into Error Handing ------- \n", (char)(port + 'A'), ch);
            return 0;
        }
    }

    /* 4. Pick the RCT value. */
    if (all_zero) {
        if ((dbg_hdmi_message_flags & HDMI_MSG_EQ_FLOW) != 0)
            dbg_printf("[EQ]: # Port%c, Ch%d , ------- all port error free ------- \n", (char)(port + 'A'), ch);
        rct = (candidates[0] + candidates[hdmi_eq_scan_records[port].byte_0x8 ? 4u : 6u]) >> 1;
        hdmi_eq_port_records[port].result[ch].rct = rct;
        hdmi_eq_port_records[port].result[ch].cct = cct;
        hdmi_eq_port_records[port].byte_0x34[ch] = 1;
        return 1;
    }
    left = 0;
    right = 0;
    if (all_have_errors) {
        /* Smallest count; left holds its index. */
        best_errors = counts[0][ch];
        for (j = 1; j <= (hdmi_eq_scan_records[port].byte_0x8 ? 4u : 6u); j++) {
            errors = counts[j][ch];
            if ((dbg_hdmi_message_flags & HDMI_MSG_EQ_FLOW) != 0)
                dbg_printf("[EQ]: # Port%c, CH%d, index = %d  u32TotalSCDC = %ld  / u8BestRCTIdx = %d  u32BestSCDC = %ld  \n",
                             (char)(port + 'A'), ch, j, errors, left, best_errors);
            if (errors < best_errors) {
                best_errors = errors;
                left = j;
            }
        }
        if ((dbg_hdmi_message_flags & HDMI_MSG_EQ_FLOW) != 0)
            dbg_printf("[EQ]: # Port%c, CH%d, Best RCT idx = %d, RCT_Value = 0x%02x\n\n", (char)(port + 'A'), ch, left,
                         candidates[left]);
        rct = candidates[left];
        hdmi_eq_port_records[port].result[ch].rct = rct;
        hdmi_eq_port_records[port].result[ch].cct = cct;
        hdmi_eq_port_records[port].byte_0x34[ch] = 1;
        return 1;
    }
    /* Some entries are error-free: the middle between the first good entry from each side. The prints show
       the upper-half count whichever half is used. */
    for (i = 0; i <= (hdmi_eq_scan_records[port].byte_0x8 ? 4u : 6u); i++) {
        if ((dbg_hdmi_message_flags & HDMI_MSG_EQ_FLOW) != 0)
            dbg_printf("[EQ]: # Port%c, CH%d, L RCTidx = %d, SDCD = 0x%04lx \n\n", (char)(port + 'A'), ch, i,
                         hdmi_eq_port_records[port].pre_aeq_errors_upper[hdmi_eq_port_records[port].best_rvga_index[ch]][i][ch]);
        if (counts[i][ch] < ERROR_FREE_LIMIT) {
            left = i;
            break;
        }
    }
    for (i = hdmi_eq_scan_records[port].byte_0x8 ? 4u : 6u; i != 0; i--) {
        if ((dbg_hdmi_message_flags & HDMI_MSG_EQ_FLOW) != 0)
            dbg_printf("[EQ]: # Port%c, CH%d, R RCTidx = %d, SDCD = 0x%04lx \n\n", (char)(port + 'A'), ch, i,
                         hdmi_eq_port_records[port].pre_aeq_errors_upper[hdmi_eq_port_records[port].best_rvga_index[ch]][i][ch]);
        if (counts[i][ch] < ERROR_FREE_LIMIT) {
            right = i;
            break;
        }
    }
    if ((dbg_hdmi_message_flags & HDMI_MSG_EQ_FLOW) != 0)
        dbg_printf("[EQ]: # Port%c, CH%d, u8Left = %d, u8Right = %d\n\n", (char)(port + 'A'), ch, left, right);

    /* 5. Store the result. */
    rct = (candidates[left] + candidates[right]) >> 1;
    hdmi_eq_port_records[port].result[ch].rct = rct;
    hdmi_eq_port_records[port].result[ch].cct = cct;
    hdmi_eq_port_records[port].byte_0x34[ch] = 1;
    return 1;
}
