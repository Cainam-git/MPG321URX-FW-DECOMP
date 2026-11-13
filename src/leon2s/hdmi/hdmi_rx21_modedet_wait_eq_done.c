/* hdmi_rx21_modedet_wait_eq_done  (Jay_EQ_End)
 *
 * Wait for the end of EQ tuning on an HDMI 2.1 input, then start mode detection.
 *   port_number: HDMI 2.1 receiver 0/1
 * Returns: 1 when mode detection starts
 * Name basis: derived - state 0 of table 0xA00B4258; prints 'EQ done', 'Run HDMI21 ModeDet', 'Jay_EQ_End' (a
 *   developer marker)
 *
 * Matching notes
 * --------------
 * Jay_EQ_End (leon2s 0xa009d5cc-0xa009d87c, 688 bytes), flags -mcpu=v8 -Os -g (section default).
 * Source forms the exact build depends on:
 *  - the two tests are separate if statements; the second one reads eq_done again after the
 *    hdmi_rx21_eq_wait_bytes store;
 *  - start_pll_check and drop_detection are static helpers with an unsigned char parameter; drop_detection
 *    gets the raw parameter port_number, so the narrowing is done again there;
 *  - eq_done is an unsigned int local; state is stored before pll_check_count.
 */

/* Message groups of dbg_hdmi_message_flags. */
#define HDMI_MSG_MODEDET_FLOW   0x04

/* States of the mode detection (index of the table hdmi_rx21_run_mode_detect_fsm runs). */
#define MODEDET_STATE_FRL_INIT      1   /* DRV_HDMI_ModeDetect_FSM_FRL_Init */
#define MODEDET_STATE_CHECK_PLL     4   /* hdmi_rx21_modedet_check_pll */

/* Link-training state (hdmi_rx21_rx_detect_states) in which the FRL path is taken. */
#define RX_DETECT_LTS_CHK_STABLE    9   /* DRV_HDMI21_RXDetect_FSM_LTS_Chk_Stable */

/* PHY numbers of the two HDMI 2.1 receivers. */
#define PHY_RX21_0              2
#define PHY_RX21_1              3

#define PLL_CHECK_PASSES        10      /* passes the PLL check state counts down */

/* Register bits (bit numbers for reg_set_bit / reg_clear_bit). */
#define BLOCK0_REG_2_BIT11      0xb     /* set by DRV_HDMI_ModeDetect_FSM_FRL_Init */
#define BLOCK0_REG_84_W         (0x84 / 4)
#define INTERNAL_PLL_BIT        0x14    /* bit 20: 'Use Internal PLL' in hdmi_rx21_modedet_set_pll_mode */

/* Bytes of the 400-byte record of an HDMI 2.1 receiver (hdmi_rx21_input_records). */
#define RX21_RECORD_SIZE        400
#define RX21_MODE_DETECTED      1       /* set by DRV_HDMI_ModeDetect_FSM_Complete */
#define RX21_BYTE_4             4       /* set by DRV_HDMI_ModeDetect_FSM_Complete */
#define RX21_CVTEM_PRESENT      0x2d

/* Register block addresses of one HDMI 2.1 receiver (0x34 bytes, hdmi_rx21_reg_blocks). */
struct rx21_reg_blocks {
    volatile unsigned int *block0;
    volatile unsigned int *block1;
    volatile unsigned int *block2;
    volatile unsigned int *block3;
    unsigned int blocks_4_to_7[4];
    volatile unsigned int *block8;
    unsigned char blocks_9_to_12[0x34 - 0x24];
};
/* Mode-detection state of one HDMI 2.1 receiver (24 bytes). */
struct rx21_mode_detect_state {
    unsigned int state;                 /* MODEDET_STATE_* */
    unsigned char pll_check_count;      /* passes left in the PLL check ("Mode Detect Check PLL Count") */
    unsigned char _5[0x18 - 5];
};
/* HDMI PHY record (24 bytes per PHY, hdmi_phy_records). */
struct hdmi_phy_record {
    unsigned char power;
    unsigned char eq_done;              /* the EQ scan sets it at its end */
    unsigned char _2[0x18 - 2];
};
extern struct rx21_reg_blocks hdmi_rx21_reg_blocks[];
extern unsigned char hdmi_rx21_input_records[];        /* HDMI 2.1 receiver records */
extern struct hdmi_phy_record hdmi_phy_records[];
extern unsigned int hdmi_rx21_rx_detect_states[];
extern struct rx21_mode_detect_state hdmi_rx21_mode_detect_states[];
extern unsigned char hdmi_rx21_eq_wait_bytes[];
extern unsigned char hdmi_rx21_two_port_mode_flags[];
extern unsigned int dbg_hdmi_message_flags;
extern int dbg_printf(const char *, ...);
extern void reg_set_bit(unsigned int, volatile unsigned int *);
extern void reg_clear_bit(unsigned int, volatile unsigned int *);
extern void hdmi_rx21_pulse_reg4c_bit0(unsigned char);
extern void hdmi_rx21_clear_mode_status(unsigned char);
extern void hdmi_rx21_clear_detect_flags(unsigned char);
extern void hdmi_rx21_clear_status_flags(unsigned int);
extern unsigned int timer_get_ticks(void);

/* The path without link training: set the receiver up for the PLL check and enter it. */
static void start_pll_check(unsigned char port)
{
    unsigned char *record = hdmi_rx21_input_records + port * RX21_RECORD_SIZE;

    /* No horizontal shift (hdmi_rx21_two_port_mode_flags) on this path. */
    hdmi_rx21_two_port_mode_flags[port] = 0;
    reg_clear_bit(0xc, hdmi_rx21_reg_blocks[port].block0 + 2);
    reg_set_bit(0xd, hdmi_rx21_reg_blocks[port].block0 + 2);
    reg_clear_bit(0xf, hdmi_rx21_reg_blocks[port].block0 + 2);
    dbg_printf("EQ done %d\r\n", 1);
    record[RX21_CVTEM_PRESENT] = 0;
    /* DRV_HDMI_ModeDetect_FSM_FRL_Init clears INTERNAL_PLL_BIT and sets BLOCK0_REG_2_BIT11; this path does the
       reverse. */
    reg_set_bit(INTERNAL_PLL_BIT, hdmi_rx21_reg_blocks[port].block0 + BLOCK0_REG_84_W);
    hdmi_rx21_reg_blocks[port].block8[0x20] |= 7;
    reg_clear_bit(BLOCK0_REG_2_BIT11, hdmi_rx21_reg_blocks[port].block0 + 2);
    hdmi_rx21_mode_detect_states[port].state = MODEDET_STATE_CHECK_PLL;
    hdmi_rx21_mode_detect_states[port].pll_check_count = PLL_CHECK_PASSES;
    reg_clear_bit(0x1c, hdmi_rx21_reg_blocks[port].block1 + 13);
}

/* EQ not done, or a mode is still marked as detected: forget the receiver's detection results. */
static void drop_detection(unsigned char port)
{
    hdmi_rx21_input_records[port * RX21_RECORD_SIZE + RX21_MODE_DETECTED] = 0;
    hdmi_rx21_clear_detect_flags(port);
    hdmi_rx21_clear_status_flags(port);
}

/*
 * Mode-detection state 0 of an HDMI 2.1 receiver: wait until the EQ scan of the receiver's PHY is done, then
 * choose how the mode detection goes on.
 *
 *   port_number  HDMI 2.1 receiver 0 or 1 (printed as the letter 'A' + port); other values return 0 at once
 *
 * Returns 1 when the state changed (hdmi_rx21_run_mode_detect_fsm then runs the new state at once), else 0
 * (the state stays 0 until the next timer pass).
 *
 * On every call it first sets back some receiver registers (block 0 word 1 bit 12 set, block 1 word 12 bits
 * 24 and 25 cleared, a pulse on bit 0 of register 0x4C) and clears the detected-mode status when the record's
 * byte 4 is 1. Then, with eq_done of the PHY (2 for receiver 0, 3 for receiver 1):
 *  1. eq_done and the link training in LTS_Chk_Stable: bits 24 and 25 set again, bit 11 of block 3 register
 *     0x7C cleared, state 1 (FRL_INIT).
 *  2. eq_done and no mode marked as detected: the registers of the path without link training, state 4
 *     (CHECK_PLL) with PLL_CHECK_PASSES passes.
 *  3. Otherwise the detection results are cleared and the state stays 0.
 */
unsigned int hdmi_rx21_modedet_wait_eq_done(unsigned int port_number)
{
    unsigned char port;
    unsigned char phy;
    unsigned int eq_done;

    port = port_number;
    if (port == 0)
        phy = PHY_RX21_0;
    else if (port == 1)
        phy = PHY_RX21_1;
    else
        return 0;
    reg_set_bit(0xc, hdmi_rx21_reg_blocks[port].block0 + 1);
    reg_clear_bit(0x18, hdmi_rx21_reg_blocks[port].block1 + 12);
    reg_clear_bit(0x19, hdmi_rx21_reg_blocks[port].block1 + 12);
    hdmi_rx21_pulse_reg4c_bit0(port);
    if (hdmi_rx21_input_records[port * RX21_RECORD_SIZE + RX21_BYTE_4] == 1)
        hdmi_rx21_clear_mode_status(port);
    eq_done = hdmi_phy_records[phy].eq_done;
    hdmi_rx21_eq_wait_bytes[port] = 0;

    /* Case 1: link training in LTS_Chk_Stable, FRL path. */
    if (eq_done == 1 && hdmi_rx21_rx_detect_states[port] == RX_DETECT_LTS_CHK_STABLE) {
        reg_set_bit(0x18, hdmi_rx21_reg_blocks[port].block1 + 12);
        reg_set_bit(0x19, hdmi_rx21_reg_blocks[port].block1 + 12);
        hdmi_rx21_mode_detect_states[port].state = MODEDET_STATE_FRL_INIT;
        reg_clear_bit(0xb, hdmi_rx21_reg_blocks[port].block3 + 0x7c / 4);
        /* The text names port A for both receivers. */
        dbg_printf("PortA Run HDMI21 ModeDet %d \n", 0xde);
        return 1;
    }
    /* Case 2: EQ done, no mode marked as detected. */
    if (hdmi_phy_records[phy].eq_done == 1 && hdmi_rx21_input_records[port * RX21_RECORD_SIZE + RX21_MODE_DETECTED] == 0) {
        start_pll_check(port);
        if (dbg_hdmi_message_flags & HDMI_MSG_MODEDET_FLOW)
            dbg_printf("[MODEDET]: ## Port%c => Jay_EQ_End [%ld] ##\n\n", (char)(port_number + 'A'),
                         timer_get_ticks());
        return 1;
    }
    /* Case 3: keep waiting. */
    drop_detection(port_number);
    return 0;
}
