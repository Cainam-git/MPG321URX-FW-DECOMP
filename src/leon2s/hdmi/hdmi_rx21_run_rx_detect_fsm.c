/* hdmi_rx21_run_rx_detect_fsm  (FUN_a009a41c)
 *
 * Run the link-training state machine of both HDMI 2.1 receivers and re-arm its timer.
 * Name basis: derived - calls the state routines of table 0xA00B4230 (DRV_HDMI21_RXDetect_FSM_*) per port, re-
 *   arms timer 0xA8079100
 *
 * Matching notes
 * --------------
 * leon2s FUN_a009a41c @ 0xa009a41c-0xa009a580 (356 bytes), flags -mcpu=v8 -Os -g.
 * Source form: the state handlers are called in an empty while loop; sys_task_start is the last call (the
 * firmware makes it a sibling call).
 */
/* HDMI PHY record (hdmi_phy_records, 0x18 bytes per PHY; PHYs 2 / 3 = HDMI 2.1 receivers 0 / 1). */
struct hdmi_phy_record {
    unsigned char bytes_0x0[6];
    unsigned char byte_0x6;             /* copy of bit 7 of the port record's flags (hdmi_rx21_run_link_state) */
    unsigned char rest[0x18 - 7];
};
struct TimerDesc { unsigned int periodic; unsigned int period; void (*fn)(void); };
extern struct hdmi_phy_record hdmi_phy_records[];
extern unsigned int hdmi_rx21_rx_detect_states[];
extern unsigned char hdmi_rx21_port_started_flags[];    /* per receiver: 1 from hdmi_rx21_start_port, 0 from hdmi_rx21_stop_port */
extern unsigned char hdmi_rx21_frl_rate_restart_requests[];    /* per receiver: set to 1 by hdmi_rx21_flag_frl_rate_change */
extern unsigned char hdmi_rx21_frl_rate_change_flags[];
extern unsigned char hdmi_rx21_lts_records[][0xb0];  /* struct hdmi_rx21_lts_record per receiver */
extern unsigned char (*const hdmi_rx21_rx_detect_state_handlers[])(unsigned char);
extern struct TimerDesc hdmi_rx21_rx_detect_timer;
extern unsigned char hdmi_rx21_rx_detect_period;
extern unsigned int hdmi_phy_test_bit(unsigned int, unsigned char, unsigned short);
extern unsigned char hdmi_rx21_get_phy_index(unsigned char);
extern unsigned char sys_get_chip_revision(void);
extern void sys_task_start(struct TimerDesc *);

#define RX21_COUNT              2

/* PHY register 0x1F0C of PHY 0: bit 20 set skips the state machines of both receivers (FLT_no_retrain
   tests the same bit). */
#define PHY_REG_1F0C            0x1f0c
#define REG_1F0C_BIT20          0x14
#define PHY_0                   0

/* States of the link-training state machine (index into hdmi_rx21_rx_detect_state_handlers). */
enum rx_detect_state {
    RX_DETECT_INIT = 0,
    RX_DETECT_LTS_1 = 1,
    RX_DETECT_LTS_3 = 3
};

#define LTS_FRL_RATE_IN_PHY     2       /* byte of the link-training record ('u8FRL_Rate_SetInPhy') */
#define CHIP_REV_82             0x82    /* the FRL rate restart below is done up to this revision */

/*
 * Timer task of the HDMI 2.1 link training (its timer is set up in DRV_HDMI_Init_Timer): runs the link-training state
 * machine of both receivers and enters its timer into the task table again with period
 * hdmi_rx21_rx_detect_period.
 *
 * Nothing but the re-arm happens while bit 20 of PHY register 0x1F0C of PHY 0 is set. Otherwise, for each
 * receiver whose hdmi_rx21_port_started_flags flag is set:
 *  1. When byte_0x6 of its PHY record is 0, the state goes back to RX_DETECT_INIT unless it is RX_DETECT_LTS_1.
 *  2. On chips up to revision 0x82, a pending FRL rate change (hdmi_rx21_frl_rate_restart_requests = 1) restarts the training at
 *     RX_DETECT_LTS_3 and clears that flag, the receiver's hdmi_rx21_frl_rate_change_flags entry and the
 *     link-training record's frl_rate_in_phy.
 *  3. The handler of the current state is called again and again until one returns 0.
 */
void hdmi_rx21_run_rx_detect_fsm(void)
{
    unsigned char i;
    unsigned char phy;

    if (hdmi_phy_test_bit(REG_1F0C_BIT20, PHY_0, PHY_REG_1F0C) == 0) {
        for (i = 0; i < RX21_COUNT; i++) {
            if (hdmi_rx21_port_started_flags[i] == 0)
                continue;
            phy = hdmi_rx21_get_phy_index(i);
            if (hdmi_phy_records[phy].byte_0x6 == 0 && hdmi_rx21_rx_detect_states[i] != RX_DETECT_LTS_1)
                hdmi_rx21_rx_detect_states[i] = RX_DETECT_INIT;
            if (sys_get_chip_revision() <= CHIP_REV_82 && hdmi_rx21_frl_rate_restart_requests[i] == 1) {
                hdmi_rx21_rx_detect_states[i] = RX_DETECT_LTS_3;
                hdmi_rx21_frl_rate_restart_requests[i] = 0;
                hdmi_rx21_frl_rate_change_flags[i] = 0;
                hdmi_rx21_lts_records[i][LTS_FRL_RATE_IN_PHY] = 0;
            }
            /* A non-zero return runs the handler of the (possibly new) current state at once. */
            while (hdmi_rx21_rx_detect_state_handlers[hdmi_rx21_rx_detect_states[i]](i))
                ;
        }
    }
    hdmi_rx21_rx_detect_timer.period = hdmi_rx21_rx_detect_period;
    sys_task_start(&hdmi_rx21_rx_detect_timer);
}
