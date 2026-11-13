/* hdmi_rx21_run_mode_detect_fsm  (FLT_no_retrain)
 *
 * Run the mode-detect state machine of both HDMI 2.1 receivers and re-arm its timer.
 * Note: Label FLT_no_retrain is a printed text, not the routine name.
 * Name basis: derived - calls the state routines of table 0xA00B4258 per port, re-arms timer 0xA80790F4;
 *   prints 'FLT_no_retrain'
 *
 * Matching notes
 * --------------
 * leon2s FLT_no_retrain @ 0xa009c9b4-0xa009cb34 (384 bytes), flags -mcpu=v8 -Os -g (section default).
 * Source forms the exact build depends on:
 *  - the register block address is a plain unsigned int (struct field w18) and the byte offset 0x90 is added to
 *    it, so reg_test_bit takes an unsigned int and not a pointer;
 *  - the NO_RETRAIN bit is read twice (the second read only when the first test fails), and the link-training
 *    records are an array of 0xb0-byte arrays;
 *  - the state handlers are called in a while loop with an empty body.
 */
/* Register block addresses of one HDMI 2.1 receiver (0x34 bytes, hdmi_rx21_reg_blocks): block 6 at +0x18. */
struct rx21_reg_blocks {
    unsigned char blocks_0_to_5[0x18];
    unsigned int block6;
    unsigned char blocks_7_to_12[0x34 - 0x1c];
};
/* Mode-detection state of one HDMI 2.1 receiver (24 bytes). */
struct rx21_mode_detect_state {
    unsigned int state;                 /* index into hdmi_rx21_mode_detect_state_handlers */
    unsigned char bytes_0x4[0x18 - 4];
};
struct timer_desc { unsigned int periodic; unsigned int period; void (*fn)(void); };
extern struct rx21_mode_detect_state hdmi_rx21_mode_detect_states[];
extern struct rx21_reg_blocks hdmi_rx21_reg_blocks[];
extern unsigned char hdmi_rx21_port_started_flags[];        /* one byte per receiver, set by hdmi_rx21_set_port_flag */
extern unsigned char hdmi_rx21_lts_records[][0xb0];  /* link-training records */
extern unsigned char (*const hdmi_rx21_mode_detect_state_handlers[])(unsigned char);
extern struct timer_desc hdmi_rx21_mode_detect_timer;
extern unsigned char hdmi_rx21_mode_detect_period;
extern unsigned int hdmi_phy_test_bit(unsigned int, unsigned char, unsigned short);
extern unsigned int reg_test_bit(unsigned int, unsigned int);
extern unsigned int dbg_print_string(const char *);
extern void hdmi_rx21_force_mode_detect_standby(unsigned char);
extern void sys_task_start(struct timer_desc *);

#define RX21_COUNT              2
#define PHY_REG_1F0C            0x1f0c      /* bit 20 of PHY 0 set: the no-retrain check below is skipped */
#define REG_1F0C_SKIP_BIT       0x14
#define B6_LTS_STATUS           0x90        /* byte offset in block 6 */
#define NO_RETRAIN_BIT          0x11        /* in B6_LTS_STATUS; printed as "FLT_no_retrain" */
#define LTS_NO_RETRAIN_NOTED    0x35        /* byte of the link-training record: 1 = "FLT_no_retrain" already printed */

/*
 * Timer task of the HDMI 2.1 mode detection: runs the mode-detect state machine of both receivers once and
 * enters itself into the task table again with period hdmi_rx21_mode_detect_period.
 * For each receiver 0 and 1 (skipped while its flag hdmi_rx21_port_started_flags[rx] is 0):
 *  1. Unless bit 20 of PHY register 0x1F0C of PHY 0 is set: with the FLT_no_retrain bit of block 6 set and
 *     the mode-detect state above 1, mark the record (print "FLT_no_retrain" the first time) and skip the
 *     receiver for this pass; with the bit clear, clear the mark.
 *  2. Otherwise send the mode detection back to standby when EQ is not ready
 *     (hdmi_rx21_force_mode_detect_standby), then call the handler of the current mode-detect state again
 *     and again until one returns 0.
 */
void hdmi_rx21_run_mode_detect_fsm(void)
{
    unsigned char i;

    for (i = 0; i < RX21_COUNT; i++) {
        if (hdmi_rx21_port_started_flags[i] == 0)
            continue;
        if (hdmi_phy_test_bit(REG_1F0C_SKIP_BIT, 0, PHY_REG_1F0C) == 0) {
            if (reg_test_bit(NO_RETRAIN_BIT, hdmi_rx21_reg_blocks[i].block6 + B6_LTS_STATUS) && hdmi_rx21_mode_detect_states[i].state > 1) {
                if (hdmi_rx21_lts_records[i][LTS_NO_RETRAIN_NOTED] == 0) {
                    hdmi_rx21_lts_records[i][LTS_NO_RETRAIN_NOTED] = 1;
                    dbg_print_string("FLT_no_retrain\n");
                }
                continue;
            }
            if (reg_test_bit(NO_RETRAIN_BIT, hdmi_rx21_reg_blocks[i].block6 + B6_LTS_STATUS) == 0)
                hdmi_rx21_lts_records[i][LTS_NO_RETRAIN_NOTED] = 0;
        }
        hdmi_rx21_force_mode_detect_standby(i);
        while (hdmi_rx21_mode_detect_state_handlers[hdmi_rx21_mode_detect_states[i].state](i))
            ;
    }
    hdmi_rx21_mode_detect_timer.period = hdmi_rx21_mode_detect_period;
    sys_task_start(&hdmi_rx21_mode_detect_timer);
}
