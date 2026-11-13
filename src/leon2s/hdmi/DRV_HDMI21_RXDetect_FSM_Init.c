/* DRV_HDMI21_RXDetect_FSM_Init  (DRV_HDMI21_RXDetect_FSM_Init)
 *
 * Run the start state of the HDMI 2.1 link-training state machine.
 *   port: HDMI 2.1 receiver 0/1
 * Name basis: proven - original name printed ('%s, PortID = %d'); state 0 of 0xA00B4230, clears the TxFFE
 *   fields, sets state 1
 *
 * Matching notes
 * --------------
 * leon2s DRV_HDMI21_RXDetect_FSM_Init @ 0xa009bef0-0xa009c09c, flags -mcpu=v8 -Os -g (section default).
 * Source forms the exact build depends on:
 *  - the lane request clearing loop is the static inline helper clear_lane_requests of
 *    DRV_HDMI21_RXDetect_FSM_LTS_3, called with p; the later accesses index hdmi_rx21_reg_blocks[port & 0xff] directly;
 *  - the register blocks are volatile (hardware);
 *  - the routine name is a static const char array, not a string literal in the call.
 */
#define HDMI_MSG_HDMI21 0x800           /* debug flag bit 11: the "[HDMI21]" lines */

/* Link-training states: index into hdmi_rx21_rx_detect_state_handlers (state routine names). */
enum rx_detect_state {
    RX_DETECT_INIT              = 0,    /* this routine */
    RX_DETECT_LTS_1             = 1
};

/* Registers of receiver register block 6 (byte offsets). */
#define B6_LTS_CONTROL  0x80            /* bit 4 LTS_P_PASS_BIT, bit 5 FLT_UPDATE_BIT */
#define LTS_P_PASS_BIT  4
#define FLT_UPDATE_BIT  5
#define B6_LTS_STATUS   0x90            /* bits 24..27 FRL rate */
#define B6_LANE_REQ_01  0xa0            /* lane request fields: lane 0 bits 24..27, lane 1 bits 28..31 */
#define B6_LANE_REQ_23  0xa4            /* lane 2 bits 0..3, lane 3 bits 4..7 */
#define PHY_REG_2F08    0x2f08          /* PHY register: bit 20 is set and cleared again */

/* Register block addresses of an HDMI 2.1 receiver (13 words, table at 0xA807DB00). */
struct hdmi_rx21_reg_blocks {
    volatile unsigned int *block0;      /* 0xCE009000 (+0x1000 for receiver 1) */
    unsigned char block1_5[0x18 - 4];
    volatile unsigned int *block6;      /* 0xCE009600 */
    unsigned char block7_12[0x34 - 0x1c];
};
/* The fields of the link training record (0xB0 bytes, table at 0xA807D680) used here. */
struct hdmi_rx21_lts_record {
    unsigned char lane_count;           /* +0 */
    unsigned char pad_0x1[0x2f];
    unsigned int last_state;            /* +0x30: rx-detect state seen at the last pass */
    unsigned char pad_0x34[0xb0 - 0x34];
};

extern struct hdmi_rx21_reg_blocks ARR_a807db00[];
extern struct hdmi_rx21_lts_record hdmi_rx21_lts_records[];
extern unsigned int hdmi_rx21_rx_detect_states[];
extern unsigned int dbg_hdmi_message_flags;
extern int dbg_printf(const char *, ...);
extern unsigned char hdmi_rx21_get_phy_index(unsigned char);
extern void DRV_HDMI21_LTS_STS_InitialSettings(unsigned char);        /* DRV_HDMI21_LTS_STS_InitialSettings */
extern void reg_clear_bit(unsigned int, volatile unsigned int *);
extern void hdmi_phy_write_bit(int mode, unsigned int bit, unsigned char reg, unsigned short val);
static const char fn_[] = "DRV_HDMI21_RXDetect_FSM_Init";

/* Clear the request field of each of the four lanes. */
static inline void clear_lane_requests(unsigned int port)
{
    unsigned char i;

    for (i = 0; i < 4; i++) {
        if (i == 0)
            ARR_a807db00[port & 0xff].block6[B6_LANE_REQ_01 / 4] &= 0xf0ffffff;
        else if (i == 1)
            ARR_a807db00[port & 0xff].block6[B6_LANE_REQ_01 / 4] &= 0x0fffffff;
        else if (i == 2)
            ARR_a807db00[port & 0xff].block6[B6_LANE_REQ_23 / 4] &= ~0xf;
        else if (i == 3)
            ARR_a807db00[port & 0xff].block6[B6_LANE_REQ_23 / 4] &= ~0xf0;
    }
}

/*
 * Link-training state RX_DETECT_INIT of an HDMI 2.1 receiver: the first state, which puts the receiver's
 * link-training registers in their start condition and moves on to RX_DETECT_LTS_1.
 *
 *   port  HDMI 2.1 receiver 0/1 (not checked; it indexes the tables directly)
 *
 * Returns 0: hdmi_rx21_run_rx_detect_fsm, which calls the state routines, moves on to the next receiver.
 *
 * In order: remember the current state in last_state (so the next state sees a state change), run
 * DRV_HDMI21_LTS_STS_InitialSettings (clears the link training record and sets the start-up PHY registers),
 * clear the lane requests, clear bit 22 of B6_LANE_REQ_01, LTS_P_PASS_BIT, the FRL rate field of
 * B6_LTS_STATUS and FLT_UPDATE_BIT, pulse bit 20 of PHY register 0x2F08, and set the state to RX_DETECT_LTS_1.
 * The "[HDMI21]" line with the routine name and port is printed first when debug flag bit 11 is set.
 */
int DRV_HDMI21_RXDetect_FSM_Init(unsigned int port)
{
    unsigned char p = port;
    unsigned char phy;

    phy = hdmi_rx21_get_phy_index(p);
    if (dbg_hdmi_message_flags & HDMI_MSG_HDMI21)
        dbg_printf("[HDMI21]: \x1b[1m%s, PortID = %d\n\x1b[m", fn_, p);
    hdmi_rx21_lts_records[p].last_state = hdmi_rx21_rx_detect_states[p];
    DRV_HDMI21_LTS_STS_InitialSettings(p);
    clear_lane_requests(p);
    reg_clear_bit(0x16, ARR_a807db00[port & 0xff].block6 + B6_LANE_REQ_01 / 4);
    reg_clear_bit(LTS_P_PASS_BIT, ARR_a807db00[port & 0xff].block6 + B6_LTS_CONTROL / 4);
    ARR_a807db00[port & 0xff].block6[B6_LTS_STATUS / 4] &= ~0x0f000000;
    reg_clear_bit(FLT_UPDATE_BIT, ARR_a807db00[port & 0xff].block6 + B6_LTS_CONTROL / 4);
    hdmi_phy_write_bit(1, 0x14, phy, PHY_REG_2F08);
    hdmi_phy_write_bit(0, 0x14, phy, PHY_REG_2F08);
    hdmi_rx21_rx_detect_states[port & 0xff] = RX_DETECT_LTS_1;
    return 0;
}
