/* DRV_HDMI_EQScan_FSM_PHY_ChkError  (DRV_HDMI_EQScan_FSM_PHY_ChkError)
 *
 * EQ scan step: check the per-channel SCDC errors and step the RVGA index.
 *   port: PHY
 * Note: State function of the EQ scan table run by hdmi_eq_run_scan_fsm.
 * Name basis: proven - original name printed: 'DRV_HDMI_EQScan_FSM_PHY_ChkError'
 *
 * Matching notes
 * --------------
 * leon2s DRV_HDMI_EQScan_FSM_PHY_ChkError @ 0xa007d688-0xa007e7c0 (4408 bytes), flags -mcpu=v8 -Os -g
 * (section default).
 * Source forms the exact build depends on:
 *  - wait_count is the 4th argument of the first print and hdmi_eq_rct_try_indexes[0] the 3rd argument of
 *    the two "initial R/C" prints, which places them in %o3 / %o2;
 *  - the status bytes are assigned with '?:' (the array address is formed before the value);
 *  - the RVGA limit test is the inline helper rvga_index_ok (its index argument is read before the
 *    byte_0x8 test);
 *  - the try-index bytes are post-incremented inside the value expression;
 *  - ch is initialised at its declaration and the per-channel loops keep the firmware's 'ch < 3' tests,
 *    including the inner 'if (ch < 3)' of the R/C loop;
 *  - the debug prints are separate ifs (jump threading gives the nested shape).
 */

/* Message groups of dbg_hdmi_message_flags: every print of the EQ scan is in group EQ_FLOW. */
#define HDMI_MSG_EQ_FLOW 0x02

/* States of the EQ scan: the index into hdmi_eq_scan_state_handlers. */
#define EQSCAN_STATE_PHY_INIT       0       /* DRV_HDMI_EQScan_FSM_PHY_Init ("FSM_EQSCAN_PHY_INIT") */
#define EQSCAN_STATE_EQ             4       /* DRV_HDMI_EQScan_FSM_PHY_EQ */
#define EQSCAN_STATE_CHKERROR       0x0b    /* this step ("EN_FSM_PHY_CHKERROR") */
#define EQSCAN_STATE_SEARCH_PROCESS 0x0d    /* DRV_HDMI_EQScan_FSM_Search_Process */
#define EQSCAN_STATE_DONE           0x10    /* DRV_HDMI_EQScan_FSM_Done ("EN_FSM_PHY_DONE") */

#define WAIT_LAST_PASS 5                /* calls with wait_count 0..5 only wait */

/* PHY registers. Each channel has a 16-bit error word: bits 0..14 are the count, bit 15 must be set (a clear
   bit 15 is reported as "CED wrong"). A channel is OK when its word is exactly ERR_WORD_NO_ERRORS. */
#define PHY_REG_ERR_COUNT_A 0x1ea0      /* bits 0..7 printed as "0x1EA0"; ch 0 bits 8..23; ch 1 high byte 24..31;
                                           bit ch clear: the status byte of channel ch is read */
#define PHY_REG_ERR_COUNT_B 0x1ea4      /* ch 1 low byte 0..7; ch 2 bits 8..23 */
#define PHY_REG_1E94        0x1e94      /* status byte of ch 0 (bits 24..31); bits 16..18 tested after a skew failure */
#define PHY_REG_1E98        0x1e98      /* status bytes of ch 1 (bits 0..7) and ch 2 (bits 8..15) */
#define ERR_COUNT_MASK      0x7fff
#define ERR_COUNT_MAX       0x7fff      /* a count at this value is reported as "CED wrong" */
#define ERR_WORD_BIT15      0x8000
#define ERR_WORD_NO_ERRORS  0x8000      /* bit 15 set, count 0 */
#define STATUS_BIT5         0x20        /* must be clear for the channel to count as OK */

/* Registers of the three channels: each channel has the same set of registers at 0x1100 + 0x400 * ch, and a
   second set just below it at 0x1000 + 0x400 * ch. */
#define PHY_CH_REG(ch, reg)     (0x1100 + 0x400 * (ch) + (reg))
#define PHY_CH_LOW_REG(ch, reg) (0x1000 + 0x400 * (ch) + (reg))
#define CH_REG_CTRL         0x00        /* bit 21 is set while new RCT/CFT values are written */
#define CH_REG_EQ           0x78        /* RCT bits 0..3, CFT bits 8..23 (printed as CCT) */
#define CH_LOW_REG_EOC      0x3c        /* bits 16..23 printed as EOC */
#define CH_CTRL_BIT21       0x15
#define RCT_MASK            0xf
#define CFT_FIELD           0xffff00
#define EQ_REG_KEEP         0xff0000f0  /* keep mask of the RCT/CFT write */

#define SKEW_FAILS_BEFORE_HOTPLUG 10    /* Deskew_HotPlug once the count goes above this */

/* The scan state of one port (12 bytes per port). byte_0x8 set: AEQ (the EQ step prints "AEQ"), three RVGA
   indexes; clear: MEQ, one RVGA index. */
struct eq_scan_record {
    unsigned int state;                 /* EQSCAN_STATE_*: the step hdmi_eq_run_scan_fsm runs next */
    unsigned char byte_0x4[3];
    unsigned char check_error_round;    /* printed as "Check Error Round" */
    unsigned char byte_0x8;
    unsigned char pad[3];
};

/* The EQ scan work record of one port (0x898 bytes). Arrays of 3 are per channel. */
struct eq_scan_channels {
    unsigned char eq_table_index[3];
    unsigned char pre_aeq_index[3];
    unsigned char byte_0x6[3];
    unsigned char rvga_index[3];        /* RVGA gain index in use ("RVGA_Idx") */
    unsigned char byte_0xc[0x30 - 0xc];
    unsigned char wait_count;           /* passes of a waiting step so far */
    unsigned char channel_ok[3];        /* 1: the error check found no errors on this channel */
    unsigned char byte_0x34[4];
    unsigned int scdc_errors[178][3];   /* [rvga_index][ch]: error count per RVGA index ("u32TotalSCDC") */
    unsigned char byte_0x890[6];
    unsigned char byte_0x896;
    unsigned char byte_0x897;
};
extern struct eq_scan_channels hdmi_eq_port_records[];
extern struct eq_scan_record hdmi_eq_scan_records[];
extern unsigned int dbg_hdmi_message_flags;
extern unsigned char hdmi_eq_skew_fail_counts[];
extern unsigned char hdmi_eq_keep_results_flags[];
extern unsigned char hdmi_eq_tmds_bit_ratio_guess[];      /* printed as bTMDS_BIT_RATIO_GUESS[phyidx] */
extern unsigned char hdmi_eq_retry_enable;
extern unsigned char hdmi_eq_zero_rct_flag;
extern unsigned char hdmi_eq_rct_try_indexes[];
extern unsigned char hdmi_eq_cft_try_indexes[];
extern unsigned int hdmi_eq_initial_cft_values[];
extern unsigned int hdmi_eq_initial_rct_values[];
extern unsigned short hdmi_phy_channel_eq_regs[];
extern unsigned char hdmi_eq_rvga_values[];
extern unsigned char DAT_a0066df8[];    /* "[EQ]: Port%c %s: (%u-th)" */
extern int dbg_printf(const void *, ...);
extern void DRV_HDMI_PHY_Clr_EQ_Err(unsigned int);
extern unsigned int hdmi_phy_read_reg(unsigned int, unsigned short);
extern void hdmi_phy_write_bit(int, unsigned int, unsigned char, unsigned short);
extern unsigned int hdmi_phy_test_bit(unsigned int, unsigned char, unsigned short);
extern void hdmi_phy_update_reg(unsigned int, unsigned short, unsigned int, unsigned int);
extern unsigned char hdmi_eq_check_error_regs(unsigned char);
extern unsigned char hdmi_get_port_mode_byte(unsigned int);
extern void hdmi_set_port_mode_byte(unsigned char, int);
extern void Deskew_HotPlug(unsigned char);

/* 1 when index is an RVGA index the scan uses: 0..2 when byte_0x8 of the port's scan record is set, else
   only 0. */
static inline int rvga_index_ok(unsigned char port, unsigned char index)
{
    if (hdmi_eq_scan_records[port].byte_0x8 != 0)
        return index <= 2;
    return index == 0;
}

/*
 * EQ scan state 11: the error check. The pre-check step (state 10), the run-AEQ step (state 8, AEQ), the R
 * turning step (state 9), the EQ table search (state 14) and Search_Process (state 13) come here, and this
 * step comes back to itself after it has changed the R/C values.
 *
 *   port  HDMI receiver PHY (printed as the letter 'A' + port)
 *
 * Returns 0 while it waits and after a skew failure (hdmi_eq_run_scan_fsm then stops until its next call),
 * 1 when the next state is to run at once. The exit "CED wrong" returns 0 as well.
 *
 * Phases:
 *  1. Wait: the first six calls only count wait_count up and return 0; the first of them clears the
 *     error counters (DRV_HDMI_PHY_Clr_EQ_Err).
 *  2. Read: per channel the status byte and the error word. A channel is OK when the word shows no errors
 *     and bit 5 of the status is clear; a word that shows errors marks it not OK and stores the count in
 *     scdc_errors[rvga_index][ch] (for an RVGA index in use). A clean word with status bit 5 set leaves
 *     channel_ok as it was.
 *  3. AEQ only (byte_0x8 set): when the RCT field of any channel reads 0, set hdmi_eq_zero_rct_flag and go
 *     back to the EQ step (state 4), which then prints "Force MEQ" and runs the scan as MEQ.
 *  4. All three channels OK: run hdmi_eq_check_error_regs. A bad value ("Need Retrain") is a skew failure:
 *     clear bTMDS_BIT_RATIO_GUESS (hdmi_eq_tmds_bit_ratio_guess) when a count is below 0x7fff and bits 16..18 of
 *     register 0x1e94 are all set, clear the port mode byte, count the failure in hdmi_eq_skew_fail_counts (above
 *     10: Deskew_HotPlug and the count starts again), clear the recheck flag and go back to state 0.
 *     Otherwise print the RCT/CCT values, set the recheck flag when hdmi_eq_retry_enable is set and go to
 *     state 16.
 *  5. Some channel not OK: print the counts, RCT/CCT, EOC and RVGA values ("EQ setting abnormal").
 *  6. Next try, only when hdmi_eq_retry_enable is 1 (else back to state 0):
 *     - AEQ with a failing channel whose RVGA index is in use: move the RVGA index of each such channel one
 *       on and go to Search_Process (state 13), which writes the new gain;
 *     - else, while the first R/C try index is 0: write the R/C entry of each channel's try index
 *       (hdmi_eq_initial_rct_values / _cft_values) and move the index one on ("Change R/C value"), clear
 *       wait_count and run this check again (state 11);
 *     - else ("still fail, Force EQ done"): a wrong error word ("CED wrong") goes back to state 0, else the
 *       scan ends in state 16 with the values it has.
 */
int DRV_HDMI_EQScan_FSM_PHY_ChkError(unsigned char port)
{
    unsigned int status[3] = {0};
    unsigned int err_word[3] = {0};
    unsigned char ch = 0;

    /* Phase 1: let the channels settle for a few calls. */
    if (hdmi_eq_port_records[port].wait_count <= WAIT_LAST_PASS) {
        if (hdmi_eq_port_records[port].wait_count == 0)
            DRV_HDMI_PHY_Clr_EQ_Err(port);
        hdmi_eq_port_records[port].wait_count++;
        return 0;
    }
    if ((dbg_hdmi_message_flags & HDMI_MSG_EQ_FLOW) != 0)
        dbg_printf(DAT_a0066df8, (char)(port + 'A'), "DRV_HDMI_EQScan_FSM_PHY_ChkError",
                     hdmi_eq_port_records[port].wait_count);

    /* Phase 2: status byte and error word of each channel. */
    for (; ch < 3; ch++) {
        if (ch == 0) {
            status[ch] = hdmi_phy_test_bit(0, port, PHY_REG_ERR_COUNT_A) == 0 ? hdmi_phy_read_reg(port, PHY_REG_1E94) >> 24 : 0;
            err_word[ch] = (hdmi_phy_read_reg(port, PHY_REG_ERR_COUNT_A) & 0xff00) | ((hdmi_phy_read_reg(port, PHY_REG_ERR_COUNT_A) >> 16) & 0xff);
        } else if (ch == 1) {
            status[ch] = hdmi_phy_test_bit(1, port, PHY_REG_ERR_COUNT_A) == 0 ? hdmi_phy_read_reg(port, PHY_REG_1E98) & 0xff : 0;
            err_word[ch] = ((hdmi_phy_read_reg(port, PHY_REG_ERR_COUNT_A) & 0xff000000) >> 16) | (hdmi_phy_read_reg(port, PHY_REG_ERR_COUNT_B) & 0xff);
        } else {
            status[ch] = hdmi_phy_test_bit(2, port, PHY_REG_ERR_COUNT_A) == 0 ? (hdmi_phy_read_reg(port, PHY_REG_1E98) >> 8) & 0xff : 0;
            err_word[ch] = (hdmi_phy_read_reg(port, PHY_REG_ERR_COUNT_B) & 0xff00) | ((hdmi_phy_read_reg(port, PHY_REG_ERR_COUNT_B) >> 16) & 0xff);
        }
        if ((status[ch] & STATUS_BIT5) == 0 && err_word[ch] == ERR_WORD_NO_ERRORS) {
            if ((dbg_hdmi_message_flags & HDMI_MSG_EQ_FLOW) != 0)
                dbg_printf("[EQ]: Port%c , ch%d -OK- SCDC %lx , 0x1EA0 = 0x%02lx \n", (char)(port + 'A'), ch, err_word[ch] & ERR_COUNT_MASK,
                             hdmi_phy_read_reg(port, PHY_REG_ERR_COUNT_A) & 0xff);
            hdmi_eq_port_records[port].channel_ok[ch] = 1;
        } else if (err_word[ch] != ERR_WORD_NO_ERRORS) {
            if ((dbg_hdmi_message_flags & HDMI_MSG_EQ_FLOW) != 0)
                dbg_printf("[EQ]: # Port%c, ch%d -NG-H20 SCDC %ld \n", (char)(port + 'A'), ch, err_word[ch] & ERR_COUNT_MASK);
            hdmi_eq_port_records[port].channel_ok[ch] = 0;
            /* Keep the count of this RVGA index for Search_Process's choice of the best one. */
            if (rvga_index_ok(port, hdmi_eq_port_records[port].rvga_index[ch]))
                hdmi_eq_port_records[port].scdc_errors[hdmi_eq_port_records[port].rvga_index[ch]][ch] = err_word[ch] & ERR_COUNT_MASK;
        }
    }

    /* Phase 3: an AEQ result with RCT 0 on any channel: start again from the EQ step as MEQ. */
    if (hdmi_eq_scan_records[port].byte_0x8 != 0) {
        if ((hdmi_phy_read_reg(port, PHY_CH_REG(0, CH_REG_EQ)) & RCT_MASK) == 0 || (hdmi_phy_read_reg(port, PHY_CH_REG(1, CH_REG_EQ)) & RCT_MASK) == 0
            || (hdmi_phy_read_reg(port, PHY_CH_REG(2, CH_REG_EQ)) & RCT_MASK) == 0) {
            if ((dbg_hdmi_message_flags & HDMI_MSG_EQ_FLOW) != 0)
                dbg_printf("[EQ]: Port%c , AEQ result R(CH0,CH1,CH2) = (0x%lx,0x%lx,0x%lx)\n", (char)(port + 'A'), hdmi_phy_read_reg(port, PHY_CH_REG(0, CH_REG_EQ)) & RCT_MASK,
                             hdmi_phy_read_reg(port, PHY_CH_REG(1, CH_REG_EQ)) & RCT_MASK, hdmi_phy_read_reg(port, PHY_CH_REG(2, CH_REG_EQ)) & RCT_MASK);
            hdmi_eq_scan_records[port].state = EQSCAN_STATE_EQ;
            hdmi_eq_zero_rct_flag = 1;
            return 1;
        }
    }

    /* Phase 4: every channel is free of errors. */
    if (hdmi_eq_port_records[port].channel_ok[0] == 1 && hdmi_eq_port_records[port].channel_ok[1] == 1 && hdmi_eq_port_records[port].channel_ok[2] == 1) {
        if (hdmi_eq_check_error_regs(port) == 0) {
            /* Skew failure: start the scan again from PHY init. */
            dbg_printf("Yung TMDS Skew Fail retrain %d\n\n", 99);
            hdmi_eq_skew_fail_counts[port]++;
            hdmi_eq_keep_results_flags[port] = 0;
            if ((err_word[0] & ERR_COUNT_MASK) < ERR_COUNT_MAX || (err_word[1] & ERR_COUNT_MASK) < ERR_COUNT_MAX || (err_word[2] & ERR_COUNT_MASK) < ERR_COUNT_MAX) {
                if (hdmi_phy_test_bit(0x10, port, PHY_REG_1E94) == 1 && hdmi_phy_test_bit(0x11, port, PHY_REG_1E94) == 1
                    && hdmi_phy_test_bit(0x12, port, PHY_REG_1E94) == 1) {
                    hdmi_eq_tmds_bit_ratio_guess[port] = 0;
                    if ((dbg_hdmi_message_flags & HDMI_MSG_EQ_FLOW) != 0)
                        dbg_printf("[EQ]: Port%c Skew Fail bTMDS_BIT_RATIO_GUESS[phyidx] = 0\r\n", (char)(port + 'A'));
                }
            }
            if (hdmi_get_port_mode_byte(port))
                hdmi_set_port_mode_byte(port, 0);
            if (hdmi_eq_skew_fail_counts[port] > SKEW_FAILS_BEFORE_HOTPLUG) {
                Deskew_HotPlug(port);
                hdmi_eq_skew_fail_counts[port] = 0;
            }
            hdmi_eq_scan_records[port].state = EQSCAN_STATE_PHY_INIT;
            return 0;
        }
        if ((dbg_hdmi_message_flags & HDMI_MSG_EQ_FLOW) != 0)
            dbg_printf("[EQ]: # Port%c  CH0 CCT [0x%04lx] RCT [0x%02lx]\n", (char)(port + 'A'), (hdmi_phy_read_reg(port, PHY_CH_REG(0, CH_REG_EQ)) & CFT_FIELD) >> 8,
                         hdmi_phy_read_reg(port, PHY_CH_REG(0, CH_REG_EQ)) & RCT_MASK);
        if ((dbg_hdmi_message_flags & HDMI_MSG_EQ_FLOW) != 0)
            dbg_printf("[EQ]: # Port%c  CH1 CCT [0x%04lx] RCT [0x%02lx]\n", (char)(port + 'A'), (hdmi_phy_read_reg(port, PHY_CH_REG(1, CH_REG_EQ)) & CFT_FIELD) >> 8,
                         hdmi_phy_read_reg(port, PHY_CH_REG(1, CH_REG_EQ)) & RCT_MASK);
        if ((dbg_hdmi_message_flags & HDMI_MSG_EQ_FLOW) != 0)
            dbg_printf("[EQ]: # Port%c  CH2 CCT [0x%04lx] RCT [0x%02lx]\n\n", (char)(port + 'A'), (hdmi_phy_read_reg(port, PHY_CH_REG(2, CH_REG_EQ)) & CFT_FIELD) >> 8,
                         hdmi_phy_read_reg(port, PHY_CH_REG(2, CH_REG_EQ)) & RCT_MASK);
        if ((dbg_hdmi_message_flags & HDMI_MSG_EQ_FLOW) != 0)
            dbg_printf("[EQ]: Port%c , Goto EN_FSM_PHY_DONE!!!\n", (char)(port + 'A'));
        if (hdmi_eq_retry_enable != 0)
            hdmi_eq_keep_results_flags[port] = 1;
        hdmi_eq_scan_records[port].state = EQSCAN_STATE_DONE;
        hdmi_eq_port_records[port].byte_0x896 = 0;
        return 1;
    }

    /* Phase 5: report the failing state. */
    if ((dbg_hdmi_message_flags & HDMI_MSG_EQ_FLOW) != 0)
        dbg_printf("[EQ]: \033[31;1m=====================================EQ setting abnormal start\n\033[m");
    if ((dbg_hdmi_message_flags & HDMI_MSG_EQ_FLOW) != 0)
        dbg_printf("[EQ]:  Port%c, Check Error Round = %d\n", (char)(port + 'A'), hdmi_eq_scan_records[port].check_error_round);
    if ((dbg_hdmi_message_flags & HDMI_MSG_EQ_FLOW) != 0)
        dbg_printf("[EQ]:  Port%c, CH0 , SCDC %ld , 0xA0 = 0x%02lx\n", (char)(port + 'A'), err_word[0] & ERR_COUNT_MASK, hdmi_phy_read_reg(port, PHY_REG_ERR_COUNT_A) & 0xff);
    if ((dbg_hdmi_message_flags & HDMI_MSG_EQ_FLOW) != 0)
        dbg_printf("[EQ]:  Port%c, CH1 , SCDC %ld \n", (char)(port + 'A'), err_word[1] & ERR_COUNT_MASK);
    if ((dbg_hdmi_message_flags & HDMI_MSG_EQ_FLOW) != 0)
        dbg_printf("[EQ]:  Port%c, CH2 , SCDC %ld \n\n", (char)(port + 'A'), err_word[2] & ERR_COUNT_MASK);
    if ((dbg_hdmi_message_flags & HDMI_MSG_EQ_FLOW) != 0)
        dbg_printf("[EQ]:  Port%c, CH0 CCT [0x%04lx] RCT [0x%02lx]\n", (char)(port + 'A'), (hdmi_phy_read_reg(port, PHY_CH_REG(0, CH_REG_EQ)) & CFT_FIELD) >> 8,
                     hdmi_phy_read_reg(port, PHY_CH_REG(0, CH_REG_EQ)) & RCT_MASK);
    if ((dbg_hdmi_message_flags & HDMI_MSG_EQ_FLOW) != 0)
        dbg_printf("[EQ]:  Port%c, CH1 CCT [0x%04lx] RCT [0x%02lx]\n", (char)(port + 'A'), (hdmi_phy_read_reg(port, PHY_CH_REG(1, CH_REG_EQ)) & CFT_FIELD) >> 8,
                     hdmi_phy_read_reg(port, PHY_CH_REG(1, CH_REG_EQ)) & RCT_MASK);
    if ((dbg_hdmi_message_flags & HDMI_MSG_EQ_FLOW) != 0)
        dbg_printf("[EQ]:  Port%c, CH2 CCT [0x%04lx] RCT [0x%02lx]\n\n", (char)(port + 'A'), (hdmi_phy_read_reg(port, PHY_CH_REG(2, CH_REG_EQ)) & CFT_FIELD) >> 8,
                     hdmi_phy_read_reg(port, PHY_CH_REG(2, CH_REG_EQ)) & RCT_MASK);
    if ((dbg_hdmi_message_flags & HDMI_MSG_EQ_FLOW) != 0)
        dbg_printf("[EQ]:  Port%c, CH0  EOC [0x%02lx]\n", (char)(port + 'A'), (hdmi_phy_read_reg(port, PHY_CH_LOW_REG(0, CH_LOW_REG_EOC)) >> 16) & 0xff);
    if ((dbg_hdmi_message_flags & HDMI_MSG_EQ_FLOW) != 0)
        dbg_printf("[EQ]:  Port%c, CH1  EOC [0x%02lx]\n", (char)(port + 'A'), (hdmi_phy_read_reg(port, PHY_CH_LOW_REG(1, CH_LOW_REG_EOC)) >> 16) & 0xff);
    if ((dbg_hdmi_message_flags & HDMI_MSG_EQ_FLOW) != 0)
        dbg_printf("[EQ]:  Port%c, CH2  EOC [0x%02lx]\n\n", (char)(port + 'A'), (hdmi_phy_read_reg(port, PHY_CH_LOW_REG(2, CH_LOW_REG_EOC)) >> 16) & 0xff);
    if ((dbg_hdmi_message_flags & HDMI_MSG_EQ_FLOW) != 0)
        dbg_printf("[EQ]:  Port%c, CH0, RVGA_Idx = %d, RVGA_Value = 0x%02x\n", (char)(port + 'A'), hdmi_eq_port_records[port].rvga_index[0],
                     hdmi_eq_rvga_values[hdmi_eq_port_records[port].rvga_index[0]]);
    if ((dbg_hdmi_message_flags & HDMI_MSG_EQ_FLOW) != 0)
        dbg_printf("[EQ]:  Port%c, CH1, RVGA_Idx = %d, RVGA_Value = 0x%02x\n", (char)(port + 'A'), hdmi_eq_port_records[port].rvga_index[1],
                     hdmi_eq_rvga_values[hdmi_eq_port_records[port].rvga_index[1]]);
    if ((dbg_hdmi_message_flags & HDMI_MSG_EQ_FLOW) != 0)
        dbg_printf("[EQ]:  Port%c, CH2, RVGA_Idx = %d, RVGA_Value = 0x%02x\n", (char)(port + 'A'), hdmi_eq_port_records[port].rvga_index[2],
                     hdmi_eq_rvga_values[hdmi_eq_port_records[port].rvga_index[2]]);
    if ((dbg_hdmi_message_flags & HDMI_MSG_EQ_FLOW) != 0)
        dbg_printf("[EQ]: \033[31;1m=====================================EQ Setting abnormal end\n\n\033[m");

    /* Phase 6: choose the next try. */
    if (hdmi_eq_retry_enable == 1) {
        if (((rvga_index_ok(port, hdmi_eq_port_records[port].rvga_index[0]) && hdmi_eq_port_records[port].channel_ok[0] == 0)
             || (rvga_index_ok(port, hdmi_eq_port_records[port].rvga_index[1]) && hdmi_eq_port_records[port].channel_ok[1] == 0)
             || (rvga_index_ok(port, hdmi_eq_port_records[port].rvga_index[2]) && hdmi_eq_port_records[port].channel_ok[2] == 0))
            && hdmi_eq_scan_records[port].byte_0x8 == 1) {
            /* AEQ: the next RVGA gain for every failing channel. */
            for (ch = 0; ch < 3; ch++) {
                if (rvga_index_ok(port, hdmi_eq_port_records[port].rvga_index[ch]) && hdmi_eq_port_records[port].channel_ok[ch] == 0)
                    hdmi_eq_port_records[port].rvga_index[ch]++;
            }
            hdmi_eq_scan_records[port].state = EQSCAN_STATE_SEARCH_PROCESS;
        } else if (hdmi_eq_rct_try_indexes[0] == 0) {
            /* The next R/C pair, written with bit 21 of the channel control registers set. */
            if ((dbg_hdmi_message_flags & HDMI_MSG_EQ_FLOW) != 0)
                dbg_printf("[EQ]: # Port%c, initial R/C [%d] fail, Change R/C value !!!\n", (char)(port + 'A'), hdmi_eq_rct_try_indexes[0]);
            hdmi_phy_write_bit(1, CH_CTRL_BIT21, port, PHY_CH_REG(0, CH_REG_CTRL));
            hdmi_phy_write_bit(1, CH_CTRL_BIT21, port, PHY_CH_REG(1, CH_REG_CTRL));
            hdmi_phy_write_bit(1, CH_CTRL_BIT21, port, PHY_CH_REG(2, CH_REG_CTRL));
            for (ch = 0; ch < 3; ch++) {
                if (ch < 3) {
                    hdmi_phy_update_reg(port, hdmi_phy_channel_eq_regs[ch], EQ_REG_KEEP,
                                 (hdmi_eq_initial_rct_values[hdmi_eq_rct_try_indexes[ch]++] & RCT_MASK) | ((hdmi_eq_initial_cft_values[hdmi_eq_cft_try_indexes[ch]++] & 0xffff) << 8));
                }
            }
            hdmi_phy_write_bit(0, CH_CTRL_BIT21, port, PHY_CH_REG(0, CH_REG_CTRL));
            hdmi_phy_write_bit(0, CH_CTRL_BIT21, port, PHY_CH_REG(1, CH_REG_CTRL));
            hdmi_phy_write_bit(0, CH_CTRL_BIT21, port, PHY_CH_REG(2, CH_REG_CTRL));
            hdmi_eq_port_records[port].wait_count = 0;
            if ((dbg_hdmi_message_flags & HDMI_MSG_EQ_FLOW) != 0)
                dbg_printf("[EQ]: # Port%c, AEQ Goto EN_FSM_PHY_CHKERROR!!!\n", (char)(port + 'A'));
            hdmi_eq_scan_records[port].state = EQSCAN_STATE_CHKERROR;
        } else {
            /* Nothing left to try. */
            hdmi_eq_port_records[port].byte_0x896 = 0;
            if ((err_word[0] & ERR_COUNT_MASK) == ERR_COUNT_MAX || (err_word[1] & ERR_COUNT_MASK) == ERR_COUNT_MAX || (err_word[2] & ERR_COUNT_MASK) == ERR_COUNT_MAX
                || (err_word[0] & ERR_WORD_BIT15) == 0 || (err_word[1] & ERR_WORD_BIT15) == 0 || (err_word[2] & ERR_WORD_BIT15) == 0) {
                if ((dbg_hdmi_message_flags & HDMI_MSG_EQ_FLOW) != 0)
                    dbg_printf("[EQ]: Port%c CED wrong, Back to Phy init\r\n", (char)(port + 'A'));
                hdmi_eq_scan_records[port].state = EQSCAN_STATE_PHY_INIT;
                return 0;
            }
            if ((dbg_hdmi_message_flags & HDMI_MSG_EQ_FLOW) != 0)
                dbg_printf("[EQ]: # Port%c, initial R/C [%d] still fail, Force EQ done  !!!\n", (char)(port + 'A'), hdmi_eq_rct_try_indexes[0]);
            if ((dbg_hdmi_message_flags & HDMI_MSG_EQ_FLOW) != 0)
                dbg_printf("[EQ]: # Port%c, AEQ Goto FSM_PHY_DONE  EQ fail fail check cable!!!\n", (char)(port + 'A'));
            hdmi_eq_scan_records[port].state = EQSCAN_STATE_DONE;
        }
    } else {
        if ((dbg_hdmi_message_flags & HDMI_MSG_EQ_FLOW) != 0)
            dbg_printf("[EQ]: Port%c , AEQ Goto FSM_EQSCAN_PHY_INIT!!!\n", (char)(port + 'A'));
        hdmi_eq_scan_records[port].state = EQSCAN_STATE_PHY_INIT;
    }
    return 1;
}
