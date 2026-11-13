/* DRV_HDMI_EQScan_FSM_Check_MEQ_Done  (DRV_HDMI_EQScan_FSM_Check_MEQ_Done)
 *
 * EQ scan step: check skew and error state after manual EQ, else restart the PHY.
 *   port: PHY
 * Note: State function of the EQ scan table run by hdmi_eq_run_scan_fsm.
 * Name basis: proven - original name printed: 'DRV_HDMI_EQScan_FSM_Check_MEQ_Done'
 *
 * Matching notes
 * --------------
 * DRV_HDMI_EQScan_FSM_Check_MEQ_Done (leon2s 0xa007d21c-0xa007d688, 1132 bytes), flags -mcpu=v8 -Os -g
 * (section default).
 * Source forms the exact build depends on:
 *  - the channel loop as in DRV_HDMI_EQScan_FSM_PHY_ChkError: ch initialised at its declaration, then
 *    'for (; ch < 3; ch++)' with each arm storing its whole expression in err_word[ch] (with an intermediate
 *    variable the compiler forms the ch == 1 address early);
 *  - the routine's name is a separate static string.
 */

/* Message groups of dbg_hdmi_message_flags: every print of the EQ scan is in group EQ_FLOW. */
#define HDMI_MSG_EQ_FLOW 0x02

/* States of the EQ scan: the index into hdmi_eq_scan_state_handlers. */
#define EQSCAN_STATE_PHY_INIT 0         /* "Back to Phy init" */
#define EQSCAN_STATE_DONE     0x10      /* DRV_HDMI_EQScan_FSM_Done */

#define WAIT_PASSES 6                   /* calls that only wait before the error words are read */

/* PHY registers read here. Each channel has a 16-bit error word: bits 0..14 are the count, bit 15 must be
   set (a clear bit 15 is reported as "CED wrong"). */
#define PHY_REG_ERR_COUNT_A 0x1ea0      /* ch 0 bits 8..23; ch 1 high byte 24..31 */
#define PHY_REG_ERR_COUNT_B 0x1ea4      /* ch 1 low byte 0..7; ch 2 bits 8..23 */
#define PHY_REG_1E94        0x1e94      /* bits 16..18 tested after a skew failure */
#define ERR_COUNT_MASK      0x7fff
#define ERR_COUNT_MAX       0x7fff      /* a count at this value is reported as "CED wrong" */
#define ERR_WORD_BIT15      0x8000

#define SKEW_FAILS_BEFORE_HOTPLUG 10    /* Deskew_HotPlug once the count goes above this */

/* The scan state of one port (12 bytes per port). byte_0x8 set: AEQ (the EQ step prints "AEQ"); clear: MEQ. */
struct eq_scan_record {
    unsigned int state;                 /* EQSCAN_STATE_*: the step hdmi_eq_run_scan_fsm runs next */
    unsigned char byte_0x4[3];
    unsigned char check_error_round;
    unsigned char byte_0x8;
    unsigned char pad[3];
};

/* The EQ scan work record of one port (0x898 bytes). Arrays of 3 are per channel. */
struct eq_scan_channels {
    unsigned char eq_table_index[3];    /* hdmi_eq_aeq_entries entry the EQ step loads in MEQ */
    unsigned char pre_aeq_index[3];
    unsigned char byte_0x6[3];
    unsigned char rvga_index[3];
    unsigned char byte_0xc[4];
    unsigned int search_step[3];
    unsigned char byte_0x1c[0x28 - 0x1c];
    unsigned char byte_0x28;
    unsigned char byte_0x29;
    unsigned char pre_aeq_done[3];
    unsigned char rvga_done[3];
    unsigned char wait_count;           /* passes of a waiting step so far */
    unsigned char channel_ok[3];        /* 1: the error check found no errors on this channel */
    unsigned char byte_0x34[3];
    unsigned char byte_0x37;
    unsigned int scdc_errors[178][3];
    unsigned char byte_0x890[6];
    unsigned char byte_0x896;
    unsigned char byte_0x897;
};
extern struct eq_scan_channels hdmi_eq_port_records[];
extern struct eq_scan_record hdmi_eq_scan_records[];
extern unsigned char hdmi_eq_tmds_bit_ratio_guess[];      /* printed as bTMDS_BIT_RATIO_GUESS[phyidx] */
extern unsigned char hdmi_eq_retry_enable;
extern unsigned char hdmi_eq_skew_fail_counts[];
extern unsigned char hdmi_eq_keep_results_flags[];
extern unsigned int dbg_hdmi_message_flags;
extern unsigned char DAT_a0067ba8[];    /* "[EQ]: MEQ Port%c , ch%d  SCDC %lx" */
extern int dbg_printf(const void *, ...);
extern int dbg_print_string(const char *);
extern unsigned int hdmi_phy_read_reg(unsigned int, unsigned short);
extern unsigned int hdmi_phy_test_bit(unsigned int, unsigned char, unsigned short);
extern void DRV_HDMI_PHY_Clr_EQ_Err(unsigned int);
extern unsigned char hdmi_eq_check_error_regs(unsigned char);
extern unsigned char hdmi_get_port_mode_byte(unsigned int);
extern void hdmi_set_port_mode_byte(unsigned int, unsigned char);
extern void Deskew_HotPlug(unsigned char);

static const char fn_[] = "DRV_HDMI_EQScan_FSM_Check_MEQ_Done";

/*
 * EQ scan state 15: the last check of an MEQ scan. The run-AEQ step (state 8) comes here when byte_0x8 of the
 * scan record is clear.
 *
 *   port  HDMI receiver PHY (printed as the letter 'A' + port)
 *
 * Returns 0 while it waits and when it sends the scan back to state 0 (hdmi_eq_run_scan_fsm then stops
 * until its next call); 1 when the scan goes on to state 16 (DRV_HDMI_EQScan_FSM_Done).
 *
 * Phases:
 *  1. Wait: the first six calls only count wait_count up and return 0; the first of them clears the
 *     error counters (DRV_HDMI_PHY_Clr_EQ_Err).
 *  2. Read: the error word of each channel, printed as "MEQ ... SCDC".
 *  3. Skew check: mark all three channels OK, clear the error counters again and run
 *     hdmi_eq_check_error_regs. When it reports a bad value ("Need Retrain"): clear bTMDS_BIT_RATIO_GUESS
 *     (hdmi_eq_tmds_bit_ratio_guess) when a count is below 0x7fff and bits 16..18 of register 0x1e94 are all set,
 *     clear the port mode byte, count the failure in hdmi_eq_skew_fail_counts (above 10 failures:
 *     Deskew_HotPlug and the count starts again), clear the recheck flag and go back to state 0.
 *  4. Error words: a count of 0x7fff or a clear bit 15 on any channel prints "CED wrong, Back to Phy init"
 *     and goes back to state 0.
 *  5. Pass: set the recheck flag when hdmi_eq_retry_enable is set, clear byte_0x896 and go to state 16.
 * With byte_0x8 set the routine skips phases 3 to 5, prints "This function is MEQ only" and goes to state 16.
 */
int DRV_HDMI_EQScan_FSM_Check_MEQ_Done(unsigned char port)
{
    unsigned int err_word[3] = {0, 0, 0};
    unsigned char ch = 0;

    /* Phase 1: let the channels run on the MEQ values for a few calls. */
    if (hdmi_eq_port_records[port].wait_count < WAIT_PASSES) {
        if (hdmi_eq_port_records[port].wait_count == 0)
            DRV_HDMI_PHY_Clr_EQ_Err(port);
        hdmi_eq_port_records[port].wait_count++;
        return 0;
    }

    /* Phase 2: the error word of each channel is put together from bytes of two registers. */
    for (; ch < 3; ch++) {
        if (ch == 0)
            err_word[ch] = (hdmi_phy_read_reg(port, PHY_REG_ERR_COUNT_A) & 0xff00) | ((hdmi_phy_read_reg(port, PHY_REG_ERR_COUNT_A) >> 16) & 0xff);
        else if (ch == 1)
            err_word[ch] = ((hdmi_phy_read_reg(port, PHY_REG_ERR_COUNT_A) & 0xff000000) >> 16) | (hdmi_phy_read_reg(port, PHY_REG_ERR_COUNT_B) & 0xff);
        else
            err_word[ch] = (hdmi_phy_read_reg(port, PHY_REG_ERR_COUNT_B) & 0xff00) | ((hdmi_phy_read_reg(port, PHY_REG_ERR_COUNT_B) >> 16) & 0xff);
        if ((dbg_hdmi_message_flags & HDMI_MSG_EQ_FLOW) != 0)
            dbg_printf(DAT_a0067ba8, (char)(port + 'A'), ch, err_word[ch] & ERR_COUNT_MASK);
    }

    if (hdmi_eq_scan_records[port].byte_0x8 == 0) {
        /* Phase 3: skew check. */
        if ((dbg_hdmi_message_flags & HDMI_MSG_EQ_FLOW) != 0)
            dbg_printf("[EQ]: \033[1m%s: Port%c\n\033[m", fn_, (char)(port + 'A'));
        for (ch = 0; ch <= 2; ch++)
            hdmi_eq_port_records[port].channel_ok[ch] = 1;
        DRV_HDMI_PHY_Clr_EQ_Err(port);
        if (hdmi_eq_check_error_regs(port) == 0) {
            dbg_printf("MEQ:Yung TMDS Skew Fail retrain %d\n\n", 99);
            if ((err_word[0] & ERR_COUNT_MASK) < ERR_COUNT_MAX || (err_word[1] & ERR_COUNT_MASK) < ERR_COUNT_MAX || (err_word[2] & ERR_COUNT_MASK) < ERR_COUNT_MAX) {
                if (hdmi_phy_test_bit(0x10, port, PHY_REG_1E94) == 1 && hdmi_phy_test_bit(0x11, port, PHY_REG_1E94) == 1 &&
                    hdmi_phy_test_bit(0x12, port, PHY_REG_1E94) == 1) {
                    hdmi_eq_tmds_bit_ratio_guess[port] = 0;
                    if ((dbg_hdmi_message_flags & HDMI_MSG_EQ_FLOW) != 0)
                        dbg_printf("[EQ]: Port%c Skew Fail bTMDS_BIT_RATIO_GUESS[phyidx] = 0\r\n",
                                     (char)(port + 'A'));
                }
            }
            if (hdmi_get_port_mode_byte(port))
                hdmi_set_port_mode_byte(port, 0);
            hdmi_eq_skew_fail_counts[port]++;
            hdmi_eq_keep_results_flags[port] = 0;
            /* Too many skew failures in a row: ask for a hot-plug toggle of the port. */
            if (hdmi_eq_skew_fail_counts[port] > SKEW_FAILS_BEFORE_HOTPLUG) {
                Deskew_HotPlug(port);
                hdmi_eq_skew_fail_counts[port] = 0;
            }
            hdmi_eq_scan_records[port].state = EQSCAN_STATE_PHY_INIT;
            return 0;
        }

        /* Phase 4: a saturated count or a clear bit 15 starts the whole scan again. */
        if ((err_word[0] & ERR_COUNT_MASK) == ERR_COUNT_MAX || (err_word[1] & ERR_COUNT_MASK) == ERR_COUNT_MAX || (err_word[2] & ERR_COUNT_MASK) == ERR_COUNT_MAX ||
            !(err_word[0] & ERR_WORD_BIT15) || !(err_word[1] & ERR_WORD_BIT15) || !(err_word[2] & ERR_WORD_BIT15)) {
            if ((dbg_hdmi_message_flags & HDMI_MSG_EQ_FLOW) != 0)
                dbg_printf("[EQ]: Port%c CED wrong, Back to Phy init\r\n", (char)(port + 'A'));
            hdmi_eq_scan_records[port].state = EQSCAN_STATE_PHY_INIT;
            return 0;
        }

        /* Phase 5: passed. */
        if (hdmi_eq_retry_enable != 0)
            hdmi_eq_keep_results_flags[port] = 1;
        hdmi_eq_port_records[port].byte_0x896 = 0;
    } else {
        dbg_print_string("This function is MEQ only\n");
    }
    hdmi_eq_scan_records[port].state = EQSCAN_STATE_DONE;
    return 1;
}
