/* DRV_HDMI_EQDetect_Timer  (DRV_HDMI_EQDetect_Timer)
 *
 * Check each HDMI port for clock changes and restart its EQ flow when needed.
 * Note: Periodic task created by hdmi_create_eq_detect_task.
 * Name basis: proven - original name printed: 'DRV_HDMI_EQDetect_Timer'
 *
 * Matching notes
 * --------------
 * DRV_HDMI_EQDetect_Timer (leon2s 0xa0083324-0xa0083618, 756 bytes), flags -mcpu=v8 -Os -g (section default).
 * Source forms the exact build depends on:
 *  - port and rx are initialised at their declarations;
 *  - the EQ reset clears the fields in the firmware's store order (phy_clock_mhz, scan state, recheck flag,
 *    eq_done, eq_reset_request);
 *  - the three callees without an entry in the names list are reached by their labels through the macros
 *    below the list (DRV_HDMI21_Set_PHY, sys_task_start, hdmi_eq_run_scan_fsm).
 */
/* Routines called by their address labels (symbols DRV_HDMI21_Set_PHY, CONV2HDMITX_UpdateInterface_4,
   FSM_EQSCAN_DONE). */
#define DRV_HDMI21_Set_PHY              FUN_a0080494
#define sys_task_start                  FUN_a00b2194
#define hdmi_eq_run_scan_fsm            FUN_a0079460

#define DBG_EQ_FLOW     0x02            /* debug flag bit 1: the "[EQ]" lines */
#define PORT_COUNT      4               /* HDMI PHYs 0..3; PHYs 2 and 3 are the HDMI 2.1 receivers 0 / 1 */
#define PHY_RX21_0      2
#define PHY_RX21_1      3

/* PHY register 0x1F0C: bit 18 of PHY 0 set skips the per-PHY work of the pass; bit 31, read with the
   receiver number in the PHY argument, sends an HDMI 2.1 port down the FRL rate path. */
#define PHY_REG_1F0C            0x1f0c
#define REG_1F0C_STOP_BIT       0x12
#define REG_1F0C_FRL_BIT        0x1f
#define PHY_REG_1F04            0x1f04  /* low byte set to 0x2F on all four PHYs when REG_CF0124A4 reads 4 */

#define REG_CF0124A4 (*(volatile unsigned int *)0xcf0124a4)    /* bits 0..2: the value 4 ends the check */

#define EQSCAN_STATE_PHY_INIT 0         /* first state of hdmi_eq_scan_state_handlers */
#define EQSCAN_STATE_DONE     0x10      /* "FSM_EQSCAN_DONE" */
#define RESTART_PRINT_NUMBER  0x237     /* number printed with "Restart EQ Flow" */

/* HDMI PHY record (24 bytes per PHY, table at 0xA807CC64). */
struct hdmi_phy_record {
    unsigned char power;                /* +0: 0 = port skipped here */
    unsigned char eq_done;              /* +1: set to 1 when the EQ scan reaches its done state */
    unsigned char eq_reset_request;     /* +2: set to 1 by hdmi_phy_request_eq_reset (TMDS_PowerOn, a command) */
    unsigned char clock_detect;         /* +3: bit 28 of PHY register 0x1C04, kept by hdmi_eq_check_clock_detect */
    unsigned char byte_0x4[4];
    unsigned short phy_clock_mhz;       /* +8: printed 'Phy Clk*1 %dMHz' / 'Phy Clk*4 %dMHz' */
    unsigned char rest_0xa[0x18 - 0xa];
};
/* EQ scan record of a port (12 bytes, table at 0xA807CCC4). */
struct eq_scan_record {
    unsigned int state;                 /* index into hdmi_eq_scan_state_handlers */
    unsigned int word_0x4;
    unsigned char byte_0x8;
    unsigned char pad[3];
};
/* The link training record (0xB0 bytes per HDMI 2.1 receiver, table at 0xA807D680). */
struct hdmi_rx21_lts_record {
    unsigned char lane_count;           /* +0 */
    unsigned char frl_rate;             /* +1: FRL rate taken over by hdmi_rx21_update_frl_rate */
    unsigned char rest_0x2[0xb0 - 2];
};
/* Timer descriptor passed to sys_task_start. */
struct timer_desc {
    unsigned int periodic;
    unsigned int period;
};
extern struct hdmi_phy_record hdmi_phy_records[];
extern struct eq_scan_record hdmi_eq_scan_records[];
extern struct hdmi_rx21_lts_record hdmi_rx21_lts_records[];
extern unsigned char hdmi_eq_keep_results_flags[];
extern unsigned char hdmi_eq_timer_frl_rates[];       /* per receiver: the frl_rate seen last */
extern struct timer_desc hdmi_eq_detect_task;
extern unsigned int hdmi_eq_detect_period;
extern unsigned int dbg_hdmi_message_flags;
extern int dbg_printf(const char *, ...);
extern unsigned int hdmi_phy_test_bit(unsigned int, unsigned char, unsigned short);
extern void hdmi_phy_restore_power(unsigned char);
extern unsigned char hdmi_is_hdmi21_phy(unsigned char);
extern void hdmi_rx21_set_frl_clock_wrapper(unsigned char, unsigned char);
extern void DRV_HDMI21_Set_PHY(unsigned char, unsigned char);
extern void sys_task_start(struct timer_desc *);
extern void hdmi_phy_update_reg(unsigned int, unsigned short, unsigned int, unsigned int);
extern void hdmi_eq_check_clock_detect(unsigned int);
extern void hdmi_eq_check_clock(unsigned char);
extern void hdmi_eq_run_scan_fsm(unsigned char);

static const char routine_name[] = "DRV_HDMI_EQDetect_Timer";

/*
 * One pass of the periodic HDMI equaliser check over the four HDMI PHYs. The task record is
 * hdmi_eq_detect_task; each pass ends by entering it again with hdmi_eq_detect_period (sys_task_start),
 * except on the REG_CF0124A4 path, which returns without doing so.
 *
 * Phases, per PHY 0..3 (skipped as a whole while bit 18 of register 0x1F0C of PHY 0 is set):
 *  1. EQ reset request: print "EQ reset, set state to INIT state", put the scan state back to
 *     EQSCAN_STATE_PHY_INIT and clear phy_clock_mhz, the recheck flag, eq_done and the request.
 *  2. A PHY with power 0 is skipped. Otherwise switch the PHY on again if it reports itself off
 *     (hdmi_phy_restore_power).
 *  3. HDMI 2.1 PHYs (2 / 3 = receivers 0 / 1) with bit 31 of register 0x1F0C (receiver number as PHY
 *     argument) set: when the receiver's frl_rate differs from the one seen last, note it and, unless it is
 *     0, set the receiver clock for it, set the PHY up for it (DRV_HDMI21_Set_PHY) and print it. Then
 *     re-arm the task and go on with the next PHY.
 *  4. Bits 0..2 of REG_CF0124A4 equal to 4: write 0x2F into the low byte of register 0x1F04 of all four
 *     PHYs and return.
 *  5. Follow the clock detect bit (hdmi_eq_check_clock_detect). With the clock detected: a PHY whose
 *     EQ is done checks its clock (hdmi_eq_check_clock); otherwise a scan that had reached
 *     EQSCAN_STATE_DONE starts again from EQSCAN_STATE_PHY_INIT ("Restart EQ Flow"), and the scan state
 *     machine runs (hdmi_eq_run_scan_fsm).
 */
void DRV_HDMI_EQDetect_Timer(void)
{
    unsigned char port = 0;
    unsigned char rx = 0;

    if (hdmi_phy_test_bit(REG_1F0C_STOP_BIT, 0, PHY_REG_1F0C) == 0) {
        for (; port <= PORT_COUNT - 1; port++) {
            /* 1. EQ reset request. */
            if (hdmi_phy_records[port].eq_reset_request == 1) {
                if (dbg_hdmi_message_flags & DBG_EQ_FLOW)
                    dbg_printf("[EQ]: Port%c EQ reset, set state to INIT state\n\n", (char)(port + 'A'));
                hdmi_phy_records[port].phy_clock_mhz = 0;
                hdmi_eq_scan_records[port].state = EQSCAN_STATE_PHY_INIT;
                hdmi_eq_keep_results_flags[port] = 0;
                hdmi_phy_records[port].eq_done = 0;
                hdmi_phy_records[port].eq_reset_request = 0;
            }

            /* 2. */
            if (hdmi_phy_records[port].power == 0)
                continue;
            hdmi_phy_restore_power(port);

            /* 3. HDMI 2.1: follow the FRL rate. */
            if (hdmi_is_hdmi21_phy(port)) {
                if (port == PHY_RX21_0)
                    rx = 0;
                else if (port == PHY_RX21_1)
                    rx = 1;
                if (hdmi_phy_test_bit(REG_1F0C_FRL_BIT, rx, PHY_REG_1F0C)) {
                    if (hdmi_rx21_lts_records[rx].frl_rate != hdmi_eq_timer_frl_rates[rx]) {
                        hdmi_eq_timer_frl_rates[rx] = hdmi_rx21_lts_records[rx].frl_rate;
                        if (hdmi_rx21_lts_records[rx].frl_rate != 0) {
                            hdmi_rx21_set_frl_clock_wrapper(rx, hdmi_rx21_lts_records[rx].frl_rate);
                            DRV_HDMI21_Set_PHY(port, hdmi_eq_timer_frl_rates[rx]);
                            if (dbg_hdmi_message_flags & DBG_EQ_FLOW)
                                dbg_printf("[EQ]: %s EQDetect Timer u8FRL_Rate = %d\n", routine_name, hdmi_eq_timer_frl_rates[rx]);
                        }
                    }
                    hdmi_eq_detect_task.period = hdmi_eq_detect_period;
                    sys_task_start(&hdmi_eq_detect_task);
                    continue;
                }
            }

            /* 4. Stop: the task is not entered again. */
            if ((REG_CF0124A4 & 7) == 4) {
                hdmi_phy_update_reg(0, PHY_REG_1F04, 0xffffff00, 0x2f);
                hdmi_phy_update_reg(1, PHY_REG_1F04, 0xffffff00, 0x2f);
                hdmi_phy_update_reg(2, PHY_REG_1F04, 0xffffff00, 0x2f);
                hdmi_phy_update_reg(3, PHY_REG_1F04, 0xffffff00, 0x2f);
                return;
            }

            /* 5. Clock detect, then the EQ scan. */
            hdmi_eq_check_clock_detect(port);
            if (hdmi_phy_records[port].clock_detect == 0)
                continue;
            if (hdmi_phy_records[port].eq_done == 1) {
                hdmi_eq_check_clock(port);
                continue;
            }
            if (hdmi_eq_scan_records[port].state == EQSCAN_STATE_DONE) {
                if (dbg_hdmi_message_flags & DBG_EQ_FLOW)
                    dbg_printf("[EQ]: # Port%c Restart EQ Flow, %d\n", (char)(port + 'A'), RESTART_PRINT_NUMBER);
                hdmi_eq_scan_records[port].state = EQSCAN_STATE_PHY_INIT;
            }
            hdmi_eq_run_scan_fsm(port);
        }
    }
    hdmi_eq_detect_task.period = hdmi_eq_detect_period;
    sys_task_start(&hdmi_eq_detect_task);
}
