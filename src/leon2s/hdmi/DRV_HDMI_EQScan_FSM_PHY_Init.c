/* DRV_HDMI_EQScan_FSM_PHY_Init  (HDMI_LINK_DESCRAMBLE_BIT_RATIO_AUTO_MODE)
 *
 * EQ scan step: initialise the PHY of a port for its clock and scrambling mode.
 *   phy
 * Note: The old label was a printed mode name ('HDMI_LINK_DESCRAMBLE_BIT_RATIO_AUTO_MODE ENABLE').
 * Name basis: proven - prints its name 'DRV_HDMI_EQScan_FSM_PHY_Init' through %s; first state of the EQ scan
 *   table
 *
 * Matching notes
 * --------------
 * leon2s HDMI_LINK_DESCRAMBLE_BIT_RATIO_AUTO_MODE @ 0xa007ed88-0xa007f634 (2220 bytes), flags -mcpu=v8 -Os -g.
 * Source forms the exact build depends on:
 *  - the PHY 2 call variants are written as separate calls in if/else arms;
 *  - hdmi_eq_mode_override_flags[phy] is read into a local before the phy_clock_mhz store;
 *  - the six try-index clears in array order;
 *  - the routine's name is a static string (state_name) passed to the prints.
 */

/* HDMI PHY record, 24 bytes per PHY (hdmi_phy_records), fields used here. */
struct hdmi_phy_record {
    unsigned char _0[7];
    unsigned char option_byte;          /* set by main-processor command 0x15 (ipc_set_hdmi_phy_option_byte) */
    unsigned short phy_clock_mhz;       /* printed 'Phy Clk*1 %dMHz' / 'Phy Clk*4 %dMHz' */
    unsigned short measured_clock;      /* hdmi_phy_read_clock_count; phy_clock_mhz is it times 1 or 4 */
    unsigned char _c[0xc];
};

/* EQ scan record, 12 bytes per PHY (hdmi_eq_scan_records). */
struct eq_scan_record {
    unsigned int state;                 /* index into hdmi_eq_scan_state_handlers */
    unsigned char b4[3];
    unsigned char check_error_round;    /* printed 'Check Error Round' by DRV_HDMI_EQScan_FSM_PHY_ChkError */
    unsigned char b8;
    unsigned char pad[3];
};

/* EQ data of one PHY, 0x898 bytes (hdmi_eq_port_records); with eq_scan_record the 'port_EQ' that is cleaned here. */
struct eq_port_data { unsigned char _0[0x30]; unsigned char byte_0x30; unsigned char _31[0x898 - 0x31]; };

/* States of hdmi_eq_scan_state_handlers: this routine is state 0. */
#define EQ_STATE_PHY_PLL       1        /* DRV_HDMI_EQScan_FSM_PHY_PLL */

#define PHY_HDMI21_RX0         2        /* PHYs 2 and 3 are the HDMI 2.1 receivers (hdmi_is_hdmi21_phy) */
#define OPTION_BYTE_ON         1        /* option_byte 1: hdmi_eq_get_clock_ratio_mode returns 0 */
#define GUESS_CLOCK_MIN        0x4a     /* above this ... */
#define GUESS_CLOCK_MAX        0x96     /* ... and up to this measured clock (75..150, printed in MHz) */
#define DBG_EQ_FLOW            2        /* dbg_hdmi_message_flags bit 1, EN_HDMI_MSG_EQ_FLOW */

/* hdmi_rx21_reg_blocks_rx0_block3 is word 3 of row 0 of the HDMI 2.1 register block table (hdmi_rx21_reg_blocks): block 3 of
   HDMI 2.1 receiver 0, address 0xCE009300 (filled by hdmi_rx21_init_register_pointers). */
#define RX0_BLOCK3_WORD_74     (0x74 / 4)
#define RX0_BLOCK3_FIELD_16_18 0x70000  /* set to 5 for PHY 2 while scrambling, else cleared */

extern struct hdmi_phy_record hdmi_phy_records[];
extern struct eq_scan_record hdmi_eq_scan_records[];
extern struct eq_port_data hdmi_eq_port_records[];
extern unsigned int dbg_hdmi_message_flags;
extern unsigned int *hdmi_rx21_reg_blocks_rx0_block3;
extern unsigned char hdmi_eq_rct_try_indexes[];
extern unsigned char hdmi_eq_cft_try_indexes[];
extern unsigned char hdmi_only_scramble_guess_mode[];    /* printed 'bHDMI_ONLYSCRAMBLE_GUESSMODE'; read by hdmi_get_port_mode_byte */
extern unsigned char hdmi_eq_mode_override_flags[];
extern unsigned char hdmi_eq_keep_results_flags[];
extern unsigned char hdmi_eq_tmds_bit_ratio_guess[];      /* printed 'bTMDS_BIT_RATIO_GUESS[phyidx]' */
extern unsigned char hdmi_eq_zero_rct_flag;
extern unsigned char DAT_a0068250[];    /* '[EQ]: ## Port%c => Jay_EQ_Start [%ld] ##' (with colour codes) */
extern unsigned char DAT_a0067058[];    /* '[EQ]: Port%c %s:' */
extern int dbg_printf(const void *, ...);
extern int dbg_print_string(const char *);
extern unsigned int timer_get_ticks(void);
extern unsigned char hdmi_is_hdmi21_phy(unsigned char);
extern void hdmi_phy_write_bit(int, unsigned int, unsigned char, unsigned short);
extern unsigned int hdmi_phy_test_bit(unsigned int, unsigned char, unsigned short);
extern void hdmi_phy_update_reg(unsigned int, unsigned short, unsigned int, unsigned int);
extern void timer_delay_units(unsigned int);
extern unsigned short hdmi_phy_read_clock_count(unsigned char);
extern unsigned char hdmi_get_port_mode_byte(unsigned int);
extern unsigned char hdmi_scdc_scrambling_enabled(unsigned char);
extern unsigned char hdmi_scdc_bit_ratio_40(unsigned char);
extern unsigned char hdmi_eq_get_clock_ratio_mode(unsigned char);
extern unsigned char hdmi_eq_get_scramble_mode(unsigned char);
extern void hdmi_set_descramble_auto_mode(unsigned char, unsigned char);
extern void hdmi_set_descramble_mode(unsigned char, unsigned char, unsigned char);
extern void hdmi_clear_descramble_override(unsigned char);
extern void *lib_memset(void *, int, unsigned int);

static const char state_name[] = "DRV_HDMI_EQScan_FSM_PHY_Init";

/*
 * State 0 of the EQ scan of HDMI PHY `phy`: set the PHY up, measure the incoming clock and choose how the
 * receiver treats scrambling and the clock ratio, then hand over to state 1 (DRV_HDMI_EQScan_FSM_PHY_PLL).
 *
 *   phy  HDMI PHY index (2 and 3 are the HDMI 2.1 receivers)
 *
 * Returns 1: hdmi_eq_run_scan_fsm runs the next state at once.
 *
 * All prints appear only with dbg_hdmi_message_flags bit 1 (EQ flow messages).
 *
 * Phases:
 *   1. Print the start tick and the state name.
 *   2. Clear the per-channel RCT and CFT try indexes.
 *   3. PHY set-up: on HDMI 2.1 PHYs first clear bit 3 of registers 0x2070..0x3070 and bits 0x18 / 0x11 of the
 *      0x2028.. registers; then fixed writes, and a pulse of bit 0x17 of 0x1148 / 0x1548 / 0x1948 and bit 0x12
 *      of 0x1F08 around a delay of 10 units.
 *   4. Measure the clock into measured_clock.
 *   5. Choose the scrambling handling, first match:
 *        a. bHDMI_ONLYSCRAMBLE_GUESSMODE set: print only ('Only scramble flow on');
 *        b. the source's SCDC shows neither scrambling nor the bit-clock ratio, option_byte is not 1 and the
 *           clock is above 0x4A and at most 0x96: use the stored modes (override flag 1), clear the scramble
 *           status bit, and invert bTMDS_BIT_RATIO_GUESS when bits 16..18 of PHY register 0x1E94 are all 0;
 *        c. otherwise 'HDMI_LINK_DESCRAMBLE_BIT_RATIO_AUTO_MODE ENABLE': override flag 0, descramble mode
 *           (0, 0) and scramble status bit 1; PHY 2 only clears the status bit.
 *   6. phy_clock_mhz: in guess mode the measured clock, with descramble mode (1, 0) (PHY 2: (1, 1)) and the
 *      status bit cleared; with clock-ratio mode 1 four times the clock (override: descramble mode (1, 1),
 *      printed '0x05'); else the clock itself (override: descramble mode (0, 0), printed '0x00').
 *   7. Scrambling mode on: clear the descramble override ('Bypass Data Align'); for PHY 2 bits 16..18 of
 *      receiver 0 block 3 word 0x74 become 5. Off: PHY 2 clears those bits.
 *   8. Unless the recheck flag of the PHY is set, clear its EQ records ('clean port_EQ!').
 *   9. Next state PHY_PLL, check-error round 0, byte_0x30 0, zero-RCT flag 0.
 */
int DRV_HDMI_EQScan_FSM_PHY_Init(unsigned char phy)
{
    unsigned char override;

    /* Phase 1. */
    if ((dbg_hdmi_message_flags & DBG_EQ_FLOW) != 0)
        dbg_printf(DAT_a0068250, (char)(phy + 'A'), timer_get_ticks());
    if ((dbg_hdmi_message_flags & DBG_EQ_FLOW) != 0)
        dbg_printf(DAT_a0067058, (char)(phy + 'A'), state_name);

    /* Phase 2: one index per channel. */
    hdmi_eq_rct_try_indexes[0] = 0;
    hdmi_eq_rct_try_indexes[1] = 0;
    hdmi_eq_rct_try_indexes[2] = 0;
    hdmi_eq_cft_try_indexes[0] = 0;
    hdmi_eq_cft_try_indexes[1] = 0;
    hdmi_eq_cft_try_indexes[2] = 0;

    /* Phase 3: PHY set-up. */
    if (hdmi_is_hdmi21_phy(phy)) {
        hdmi_phy_write_bit(0, 3, phy, 0x2070);
        hdmi_phy_write_bit(0, 3, phy, 0x2470);
        hdmi_phy_write_bit(0, 3, phy, 0x2870);
        hdmi_phy_write_bit(0, 3, phy, 0x3070);
        hdmi_phy_write_bit(0, 0x18, phy, 0x2028);
        hdmi_phy_write_bit(0, 0x11, phy, 0x2028);
        hdmi_phy_write_bit(0, 0x11, phy, 0x2428);
        hdmi_phy_write_bit(0, 0x11, phy, 0x2828);
        hdmi_phy_write_bit(0, 0x11, phy, 0x3028);
    }
    hdmi_phy_write_bit(0, 0xd, phy, 0x1168);
    hdmi_phy_update_reg(phy, 0x1020, 0xffcfffff, 0x100000);
    hdmi_phy_update_reg(phy, 0x1420, 0xffcfffff, 0x100000);
    hdmi_phy_update_reg(phy, 0x1820, 0xffcfffff, 0x100000);
    hdmi_phy_update_reg(phy, 0x1c00, 0xffffff00, 2);
    hdmi_phy_write_bit(1, 0x15, phy, 0x1100);
    hdmi_phy_write_bit(1, 0x15, phy, 0x1500);
    hdmi_phy_write_bit(1, 0x15, phy, 0x1900);
    hdmi_phy_update_reg(phy, 0x1168, 0xffff00ff, 0);
    hdmi_phy_update_reg(phy, 0x1038, 0xffffff00, 0);
    hdmi_phy_write_bit(1, 0x12, phy, 0x1f08);
    hdmi_phy_write_bit(1, 0x17, phy, 0x1148);
    hdmi_phy_write_bit(1, 0x17, phy, 0x1548);
    hdmi_phy_write_bit(1, 0x17, phy, 0x1948);
    timer_delay_units(10);
    hdmi_phy_write_bit(0, 0x17, phy, 0x1948);
    hdmi_phy_write_bit(0, 0x17, phy, 0x1548);
    hdmi_phy_write_bit(0, 0x17, phy, 0x1148);
    hdmi_phy_write_bit(0, 0x12, phy, 0x1f08);

    /* Phase 4. */
    hdmi_phy_records[phy].measured_clock = hdmi_phy_read_clock_count(phy);

    /* Phase 5: scrambling handling. */
    if (hdmi_get_port_mode_byte(phy)) {
        /* 5a. */
        if ((dbg_hdmi_message_flags & DBG_EQ_FLOW) != 0)
            dbg_printf("[EQ]: Port%c, Only scramble flow on\r\n", (char)(phy + 'A'));
        if ((dbg_hdmi_message_flags & DBG_EQ_FLOW) != 0)
            dbg_printf("[EQ]: Pos: Port %c, bHDMI_ONLYSCRAMBLE_GUESSMODE = %d\r\n", (char)(phy + 'A'), hdmi_only_scramble_guess_mode[phy]);
    } else if (hdmi_scdc_scrambling_enabled(phy) == 0 && hdmi_scdc_bit_ratio_40(phy) == 0 && hdmi_phy_records[phy].option_byte != OPTION_BYTE_ON
               && hdmi_phy_records[phy].measured_clock > GUESS_CLOCK_MIN && hdmi_phy_records[phy].measured_clock <= GUESS_CLOCK_MAX) {
        /* 5b. */
        hdmi_eq_mode_override_flags[phy] = 1;
        hdmi_set_descramble_auto_mode(phy, 0);
        if ((dbg_hdmi_message_flags & DBG_EQ_FLOW) != 0)
            dbg_printf("[EQ]: PRE: Port %c, bTMDS_BIT_RATIO_GUESS[phyidx] = %d\r\n", (char)(phy + 'A'), hdmi_eq_tmds_bit_ratio_guess[phy]);
        if (hdmi_phy_test_bit(0x10, phy, 0x1e94) == 0 && hdmi_phy_test_bit(0x11, phy, 0x1e94) == 0
            && hdmi_phy_test_bit(0x12, phy, 0x1e94) == 0) {
            hdmi_eq_tmds_bit_ratio_guess[phy] = ~hdmi_eq_tmds_bit_ratio_guess[phy] & 1;
            if ((dbg_hdmi_message_flags & DBG_EQ_FLOW) != 0)
                dbg_printf("[EQ]: Port%c, TMDS_BIT_RATIO_GUESS invert\r\n", (char)(phy + 'A'));
        }
        if ((dbg_hdmi_message_flags & DBG_EQ_FLOW) != 0)
            dbg_printf("[EQ]: Pos: Port %c, bTMDS_BIT_RATIO_GUESS = %d\r\n", (char)(phy + 'A'), hdmi_eq_tmds_bit_ratio_guess[phy]);
    } else {
        /* 5c. */
        hdmi_eq_mode_override_flags[phy] = 0;
        if (phy != PHY_HDMI21_RX0) {
            hdmi_set_descramble_mode(phy, 0, 0);
            hdmi_set_descramble_auto_mode(phy, 1);
        } else {
            hdmi_set_descramble_auto_mode(phy, 0);
        }
        if ((dbg_hdmi_message_flags & DBG_EQ_FLOW) != 0)
            dbg_printf("[EQ]: Port%c, HDMI_LINK_DESCRAMBLE_BIT_RATIO_AUTO_MODE ENABLE\r\n", (char)(phy + 'A'));
    }

    /* Phase 6: PHY clock. */
    if (hdmi_get_port_mode_byte(phy)) {
        hdmi_set_descramble_auto_mode(phy, 0);
        if (phy != PHY_HDMI21_RX0)
            hdmi_set_descramble_mode(phy, 1, 0);
        else
            hdmi_set_descramble_mode(phy, 1, 1);
        hdmi_phy_records[phy].phy_clock_mhz = hdmi_phy_records[phy].measured_clock;
        if ((dbg_hdmi_message_flags & DBG_EQ_FLOW) != 0)
            dbg_printf("[EQ]: Port%c Phy Clk*1 %dMHz\n", (char)(phy + 'A'), hdmi_phy_records[phy].phy_clock_mhz);
    } else if (hdmi_eq_get_clock_ratio_mode(phy) == 1) {
        override = hdmi_eq_mode_override_flags[phy];
        hdmi_phy_records[phy].phy_clock_mhz = hdmi_phy_records[phy].measured_clock << 2;
        if (override == 1) {
            hdmi_set_descramble_mode(phy, 1, 1);
            if ((dbg_hdmi_message_flags & DBG_EQ_FLOW) != 0)
                dbg_printf("[EQ]: Port%c, HDMI_SET_DESCRAMBLE_MODE = 0x05\r\n", (char)(phy + 'A'));
        }
        if ((dbg_hdmi_message_flags & DBG_EQ_FLOW) != 0)
            dbg_printf("[EQ]: Port%c Phy Clk*4 %dMHz\n", (char)(phy + 'A'), hdmi_phy_records[phy].phy_clock_mhz);
    } else {
        override = hdmi_eq_mode_override_flags[phy];
        hdmi_phy_records[phy].phy_clock_mhz = hdmi_phy_records[phy].measured_clock;
        if (override == 1) {
            hdmi_set_descramble_mode(phy, 0, 0);
            if ((dbg_hdmi_message_flags & DBG_EQ_FLOW) != 0)
                dbg_printf("[EQ]: Port%c, HDMI_SET_DESCRAMBLE_MODE = 0x00\r\n", (char)(phy + 'A'));
        }
        if ((dbg_hdmi_message_flags & DBG_EQ_FLOW) != 0)
            dbg_printf("[EQ]: Port%c Phy Clk*1 %dMHz\n", (char)(phy + 'A'), hdmi_phy_records[phy].phy_clock_mhz);
    }

    /* Phase 7: scrambling mode. */
    if (hdmi_eq_get_scramble_mode(phy)) {
        if (phy == PHY_HDMI21_RX0)
            hdmi_rx21_reg_blocks_rx0_block3[RX0_BLOCK3_WORD_74] = (hdmi_rx21_reg_blocks_rx0_block3[RX0_BLOCK3_WORD_74] & ~RX0_BLOCK3_FIELD_16_18) | 0x50000;
        hdmi_clear_descramble_override(phy);
        if ((dbg_hdmi_message_flags & DBG_EQ_FLOW) != 0)
            dbg_printf("[EQ]: # Port%c %s: Bypass Data Align \n", (char)(phy + 'A'), state_name);
    } else if (phy == PHY_HDMI21_RX0) {
        hdmi_rx21_reg_blocks_rx0_block3[RX0_BLOCK3_WORD_74] &= ~RX0_BLOCK3_FIELD_16_18;
    }

    /* Phase 8. */
    if (hdmi_eq_keep_results_flags[phy] == 0) {
        if ((dbg_hdmi_message_flags & DBG_EQ_FLOW) != 0)
            dbg_print_string("[EQ]: clean port_EQ!\n");
        lib_memset(&hdmi_eq_scan_records[phy], 0, 0xc);
        lib_memset(&hdmi_eq_port_records[phy], 0, 0x898);
    }

    /* Phase 9: on to the next state. */
    hdmi_eq_scan_records[phy].state = EQ_STATE_PHY_PLL;
    hdmi_eq_scan_records[phy].check_error_round = 0;
    hdmi_eq_port_records[phy].byte_0x30 = 0;
    hdmi_eq_zero_rct_flag = 0;
    return 1;
}
