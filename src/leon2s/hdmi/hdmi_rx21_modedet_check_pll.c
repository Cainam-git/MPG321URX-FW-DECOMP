/* hdmi_rx21_modedet_check_pll  (MODEDET_handler_3)
 *
 * Mode-detect state 4: wait until the active line count is stable, then go to STANDBY, or restart EQ.
 *   port: HDMI 2.1 receiver 0/1
 * Returns: 1 when it moved on to STANDBY, else 0
 * Note: Label MODEDET_handler_3 is not printed by the firmware. The 'PLL Count' is a pass counter (set to 10
 *   on entry), not a hardware reading.
 * Name basis: proven - state 4 of table 0xA00B4258; 'Mode Detect Check PLL Count', 'PLL Checking Timeout,
 *   Restart EQ Flow'
 *
 * Matching notes
 * --------------
 * MODEDET_handler_3 (leon2s 0xa009dd40-0xa009dfa8, 616 bytes), flags -mcpu=v8 -Os -g (section default).
 * Source forms the exact build depends on:
 *  - an int return and a K&R unsigned char parameter;
 *  - the depth code expression is written out twice (call argument and record store);
 *  - the tests after the DE_Line compare are nested in 'if (difference <= 1)', with one 'return 0' at the end
 *    of the function for every other path.
 */

/* Message groups of dbg_hdmi_message_flags. */
#define HDMI_MSG_MODEDET_FLOW   0x04

/* States of the mode detection (index of the table hdmi_rx21_run_mode_detect_fsm runs). */
#define MODEDET_STATE_WAIT_EQ_END   0   /* hdmi_rx21_modedet_wait_eq_done */
#define MODEDET_STATE_STANDBY       5   /* FSM_MODE_DETECT_STANDBY */

/* PHY numbers of the two HDMI 2.1 receivers. */
#define PHY_RX21_0              2
#define PHY_RX21_1              3

#define COLOUR_DEPTH_8_BITS     4       /* enum colour_depth_code of hdmi_rx21_modedet_set_pll_mode */
#define SPEED_UP_COUNT          3       /* passes left after the first stable DE_Line ("Speed Up PLL Checking") */

/* Words of register block 0 (word indexes). */
#define BLOCK0_HTOTAL           (0x38 / 4)  /* bits 16..31 */
#define BLOCK0_VTOTAL           (0x3c / 4)
#define BLOCK0_REG_44           (0x44 / 4)  /* bits 8..11: colour depth code */
#define BLOCK0_HACTIVE          (0x4c / 4)  /* "DE": bits 16..31 */
#define BLOCK0_VACTIVE          (0x50 / 4)  /* "DE_Line" */
#define BLOCK0_REG_B4           (0xb4 / 4)
#define BLOCK0_REG_B4_BIT2      2       /* DRV_HDMI_ModeDetect_FSM_Complete clears it when a CVTEM packet is present */

/* Register block addresses of one HDMI 2.1 receiver (0x34 bytes, hdmi_rx21_reg_blocks). */
struct rx21_reg_blocks {
    volatile unsigned int *block0;
    volatile unsigned int *block1;
    unsigned char blocks_2_to_7[0x18];
    volatile unsigned int *block8;      /* +0x20 */
    unsigned char blocks_9_to_12[0x34 - 0x24];
};
/* Mode-detection state of one HDMI 2.1 receiver (24 bytes). */
struct rx21_mode_detect_state {
    unsigned int state;                 /* MODEDET_STATE_* */
    unsigned char pll_check_count;      /* passes left; hdmi_rx21_modedet_wait_eq_done sets 10 */
    unsigned char stable_count;         /* "Sync Stable Count" of the standby state */
    unsigned char _6[0x18 - 6];
};
/* The record of one HDMI 2.1 receiver (400 bytes, hdmi_rx21_input_records): the part used here. */
struct rx21_record {
    unsigned char _00[6];
    unsigned char vrr_flags;            /* set by hdmi_rx21_detect_vrr_signalling */
    unsigned char _07[0x1a - 7];
    unsigned short htotal;              /* +0x1a */
    unsigned short vtotal;
    unsigned short hactive;
    unsigned short vactive;             /* +0x20 */
    unsigned char _22[0x2c - 0x22];
    unsigned char depth_code;           /* +0x2c: code last passed to hdmi_rx21_modedet_set_pll_mode */
    unsigned char _2d[0x190 - 0x2d];
};
/* HDMI PHY record (24 bytes per PHY, hdmi_phy_records). */
struct hdmi_phy_record {
    unsigned char power;
    unsigned char eq_done;              /* the EQ scan sets it at its end */
    unsigned char _2[0x18 - 2];
};
extern struct rx21_reg_blocks hdmi_rx21_reg_blocks[];
extern struct rx21_mode_detect_state hdmi_rx21_mode_detect_states[];
extern struct rx21_record hdmi_rx21_input_records[];
extern struct hdmi_phy_record hdmi_phy_records[];
extern unsigned char hdmi_rx21_two_port_mode_flags[];
extern unsigned int dbg_hdmi_message_flags;
extern int dbg_printf(const char *, ...);
extern void reg_set_bit(unsigned int, volatile unsigned int *);
extern unsigned char hdmi_rx21_has_cvtem(unsigned char);
extern void hdmi_rx21_modedet_set_pll_mode(unsigned int, unsigned int);      /* hdmi_rx21_modedet_set_pll_mode */
extern void hdmi_rx21_reset_reg84_blocks(unsigned int);
extern void hdmi_rx21_update_irq_bits(unsigned int);

/*
 * Mode-detection state 4 of an HDMI 2.1 receiver: set the pixel PLL up for the colour depth and wait until
 * the DE_Line count (block 0 register 0x50) stays the same from one pass to the next.
 *
 *   port  HDMI 2.1 receiver 0 or 1 (printed as the letter 'A' + port)
 *
 * Returns 1 when the check passed and the state is now 5 (STANDBY; hdmi_rx21_run_mode_detect_fsm runs it at
 * once), else 0.
 *
 * Each pass sets bit 2 of block 0 register 0xB4 and uses up one of pll_check_count's passes:
 *  - none left: state 0 and eq_done of the PHY cleared ("PLL Checking Timeout, Restart EQ Flow");
 *  - else the PLL gets the colour depth code (COLOUR_DEPTH_8_BITS with a CVTEM packet, else bits 8..11 of
 *    block 0 register 0x44), which is also kept in the record, and the new DE_Line is stored. When it differs
 *    from the last one by more than 1 the check goes on next pass. When it is stable with more than 2 passes
 *    left, the passes left become SPEED_UP_COUNT; with 2 or fewer the check has passed: the stable count is
 *    cleared, the record gets H_Total, V_Total and DE (the horizontal values shifted by
 *    hdmi_rx21_two_port_mode_flags) for the standby state to compare with, the register 0x84 blocks are reset, the
 *    event bits updated, vrr_flags cleared and bit 24 of block 8 register 0x38 set.
 */
int hdmi_rx21_modedet_check_pll(port)
    unsigned char port;
{
    unsigned char phy = PHY_RX21_0;
    unsigned int htotal_word, vtotal_word, hactive_word;
    unsigned short old_vactive;

    if (port == 1)
        phy = PHY_RX21_1;
    reg_set_bit(BLOCK0_REG_B4_BIT2, hdmi_rx21_reg_blocks[port].block0 + BLOCK0_REG_B4);
    if (hdmi_rx21_mode_detect_states[port].pll_check_count != 0) {
        hdmi_rx21_mode_detect_states[port].pll_check_count--;
        if (dbg_hdmi_message_flags & HDMI_MSG_MODEDET_FLOW)
            dbg_printf("[MODEDET]: Port%c : Mode Detect Check PLL Count = %d \n", (char)(port + 'A'),
                         hdmi_rx21_mode_detect_states[port].pll_check_count);
        hdmi_rx21_modedet_set_pll_mode(port, hdmi_rx21_has_cvtem(port) == 1 ? COLOUR_DEPTH_8_BITS : (hdmi_rx21_reg_blocks[port].block0[BLOCK0_REG_44] >> 8) & 0xf);
        hdmi_rx21_input_records[port].depth_code = hdmi_rx21_has_cvtem(port) == 1 ? COLOUR_DEPTH_8_BITS : (hdmi_rx21_reg_blocks[port].block0[BLOCK0_REG_44] >> 8) & 0xf;
        old_vactive = hdmi_rx21_input_records[port].vactive;
        hdmi_rx21_input_records[port].vactive = hdmi_rx21_reg_blocks[port].block0[BLOCK0_VACTIVE];
        if (__builtin_abs((unsigned short)hdmi_rx21_reg_blocks[port].block0[BLOCK0_VACTIVE] - old_vactive) <= 1) {
            if (hdmi_rx21_mode_detect_states[port].pll_check_count > 2) {
                /* Stable early: finish after fewer passes. */
                hdmi_rx21_mode_detect_states[port].pll_check_count = SPEED_UP_COUNT;
                if (dbg_hdmi_message_flags & HDMI_MSG_MODEDET_FLOW)
                    dbg_printf("[MODEDET]: Port%c Speed Up PLL Checking\n", (char)(port + 'A'));
            } else {
                /* Passed: hand over to the standby state. */
                hdmi_rx21_mode_detect_states[port].stable_count = 0;
                htotal_word = hdmi_rx21_reg_blocks[port].block0[BLOCK0_HTOTAL];
                vtotal_word = hdmi_rx21_reg_blocks[port].block0[BLOCK0_VTOTAL];
                hactive_word = hdmi_rx21_reg_blocks[port].block0[BLOCK0_HACTIVE];
                hdmi_rx21_mode_detect_states[port].state = MODEDET_STATE_STANDBY;
                hdmi_rx21_input_records[port].htotal = (htotal_word >> 16) << hdmi_rx21_two_port_mode_flags[port];
                hdmi_rx21_input_records[port].vtotal = vtotal_word;
                hdmi_rx21_input_records[port].hactive = (hactive_word >> 16) << hdmi_rx21_two_port_mode_flags[port];
                hdmi_rx21_reset_reg84_blocks(port);
                hdmi_rx21_update_irq_bits(port);
                hdmi_rx21_input_records[port].vrr_flags = 0;
                reg_set_bit(0x18, hdmi_rx21_reg_blocks[port].block8 + 0x38 / 4);
                return 1;
            }
        }
    } else {
        /* Timeout: back to the wait for EQ, with the PHY's EQ marked as not done. */
        hdmi_rx21_mode_detect_states[port].state = MODEDET_STATE_WAIT_EQ_END;
        hdmi_phy_records[phy].eq_done = 0;
        if (dbg_hdmi_message_flags & HDMI_MSG_MODEDET_FLOW)
            dbg_printf("[MODEDET]: Port%c PLL Checking Timeout, Restart EQ Flow\n", (char)(port + 'A'));
    }
    return 0;
}
