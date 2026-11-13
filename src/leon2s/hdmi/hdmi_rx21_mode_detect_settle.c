/* hdmi_rx21_mode_detect_settle  (FUN_a0097f04)
 *
 * Mode detection state 6 of an HDMI 2.1 receiver: step the hold count, acknowledge events, set state 7.
 *   port_arg: HDMI 2.1 receiver 0/1
 * Returns: 1
 * Note: The state changes to 7 in the same call whatever the hold count is; nothing waits for the count.
 * Name basis: descriptive - record byte +6 goes down by one, or to 0 when block 1 word +0x40 reads 0x82;
 *   events 0x16 (and 8, 0xB, 0xC on later chips) acknowledged; state word = 7 in both branches
 *
 * Matching notes
 * --------------
 * leon2s FUN_a0097f04 @ 0xa0097f04-0xa0097ff4 (240 bytes), flags -mcpu=v8 -Os -g.
 * Source forms the exact build depends on:
 *  - the hold_count step is a static helper taking the raw parameter as unsigned char (the firmware converts
 *    the port twice); the state record is indexed directly in every access;
 *  - hdmi_rx21_status30_bit4 is tested and both arms store MODEDET_STATE_COMPLETE (GCC keeps the test and
 *    both stores).
 */
/* One row per HDMI 2.1 receiver (hdmi_rx21_reg_blocks): the addresses of its register blocks. */
struct hdmi_rx21_reg_blocks {
    unsigned int block0;
    volatile unsigned int *block1;      /* +4 */
    unsigned char blocks_2_to_12[0x34 - 8];
};
/* Mode detection state of one HDMI 2.1 receiver (hdmi_rx21_mode_detect_states, 0x18 bytes). */
struct rx21_mode_detect_state {
    unsigned int state;                 /* index into the mode detection state table (MODEDET_STATE_*) */
    unsigned char byte_0x4;
    unsigned char stable_count;         /* +5 */
    unsigned char hold_count;           /* +6: set to 10 by FSM_MODE_DETECT_STANDBY on entering this state */
    unsigned char rest[0x18 - 7];
};
extern struct hdmi_rx21_reg_blocks ARR_a807db00[];
extern struct rx21_mode_detect_state hdmi_rx21_mode_detect_states[];
extern void hdmi_rx21_ack_event(unsigned char, unsigned int);
extern unsigned char sys_get_chip_revision(void);
extern unsigned char hdmi_rx21_status30_bit4(unsigned char);

#define MODEDET_STATE_COMPLETE  7       /* DRV_HDMI_ModeDetect_FSM_Complete */

#define BLOCK1_WORD_40          0x10    /* word index: block 1 + 0x40 */
#define BLOCK1_WORD_40_VALUE    0x82    /* low byte that clears hold_count */

/* Receiver events (status bits listed in hdmi_rx21_event_table). */
#define RX21_EVENT_08           0x08
#define RX21_EVENT_0B           0x0b
#define RX21_EVENT_0C           0x0c
#define RX21_EVENT_16           0x16

#define CHIP_REV_82             0x82    /* events 8, 0xB and 0xC are acknowledged only above this revision */

/* One step of hold_count: down by one while it is not 0 and block 1 word +0x40 does not read 0x82 in its low
   byte; otherwise it becomes 0. */
static void hold_count_step(unsigned char port)
{
    if (hdmi_rx21_mode_detect_states[port].hold_count != 0 && (ARR_a807db00[port].block1[BLOCK1_WORD_40] & 0xff) != BLOCK1_WORD_40_VALUE)
        hdmi_rx21_mode_detect_states[port].hold_count--;
    else
        hdmi_rx21_mode_detect_states[port].hold_count = 0;
}

/*
 * State 6 (MODEDET_STATE_SETTLE) of the HDMI 2.1 mode detection, entered from FSM_MODE_DETECT_STANDBY and run
 * through the state table of hdmi_rx21_run_mode_detect_fsm.
 *
 *   port_arg   HDMI 2.1 receiver 0 or 1
 *
 * In one call: one step of hold_count, acknowledgement of receiver event 0x16 (and of events 8, 0xB and 0xC
 * on chips above revision 0x82), then the move to MODEDET_STATE_COMPLETE. The state changes on every call,
 * whatever hold_count holds. Returns 1.
 */
int hdmi_rx21_mode_detect_settle(unsigned int port_arg)
{
    unsigned char port;

    hold_count_step(port_arg);
    port = port_arg;
    hdmi_rx21_ack_event(port, RX21_EVENT_16);
    if (sys_get_chip_revision() > CHIP_REV_82) {
        hdmi_rx21_ack_event(port, RX21_EVENT_08);
        hdmi_rx21_ack_event(port, RX21_EVENT_0B);
        hdmi_rx21_ack_event(port, RX21_EVENT_0C);
    }
    if (hdmi_rx21_status30_bit4(port) == 0)
        hdmi_rx21_mode_detect_states[port].state = MODEDET_STATE_COMPLETE;
    else
        hdmi_rx21_mode_detect_states[port].state = MODEDET_STATE_COMPLETE;
    return 1;
}
