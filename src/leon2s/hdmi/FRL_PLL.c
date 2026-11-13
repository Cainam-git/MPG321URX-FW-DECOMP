/* FRL_PLL  (FRL_PLL)
 *
 * Set the FRL PLL of an HDMI 2.1 receiver for a target clock value in MHz.
 *   port_number: HDMI 2.1 receiver
 *   target: target value printed as 'Target %dM'
 * Note: The second parameter is the value printed as 'Target %dM'; the FRL rate printed next to it comes from
 *   the link-training record.
 * Name basis: proven - original name printed ('Port%c FRL_PLL Target %dM, FRL Rate %d')
 *
 * Matching notes
 * --------------
 * leon2s FRL_PLL @ 0xa0096538-0xa00967ec (692 bytes), flags -mcpu=v8 -Os -g (section default).
 * Source forms the exact build depends on:
 *  - the parameter port_number is an unsigned int copied into the unsigned char port; the letter in the print
 *    is made from the parameter itself;
 *  - sel is set to 2 and then to 3 for port 1;
 *  - each rate-range arm holds its own flag store and its own call of hdmi_rx21_set_pll_ctrl_bit5, and the
 *    halfword +0xa of the PHY record is stored before +8;
 *  - the registers are word arrays: register 0x58 of block 6 is addressed as [0x58 / 4].
 */
/* Register block addresses of one HDMI 2.1 receiver (0x34 bytes, hdmi_rx21_reg_blocks). */
struct rx21_reg_blocks {
    volatile unsigned int *block0;
    unsigned char blocks_1_to_5[0x14];
    volatile unsigned int *block6;
    unsigned char blocks_7_to_12[0x34 - 0x1c];
};
/* HDMI PHY record (24 bytes per PHY, hdmi_phy_records): entries 2 / 3 belong to HDMI 2.1 receivers 0 / 1. */
struct hdmi_phy_record {
    unsigned char bytes_0x0[8];
    unsigned short phy_clock_mhz;       /* +8 */
    unsigned short half_0xa;            /* +0xa: receives the same value */
    unsigned char bytes_0xc[0x18 - 0xc];
};
/* The fields of the link training record (0xB0 bytes per HDMI 2.1 receiver) used here. */
struct hdmi_rx21_lts_record {
    unsigned char lane_count;           /* +0 */
    unsigned char frl_rate;             /* +1: printed as "FRL Rate" */
    unsigned char bytes_0x2[0xb0 - 2];
};
extern struct rx21_reg_blocks hdmi_rx21_reg_blocks[];
extern struct hdmi_phy_record hdmi_phy_records[];
extern struct hdmi_rx21_lts_record hdmi_rx21_lts_records[];
extern unsigned char hdmi_rx21_two_port_mode_flags[];
extern int dbg_printf(const char *, ...);
extern void hdmi_rx21_set_pll_ctrl_bit5(unsigned char, unsigned char);
extern void hdmi_rx21_write_pll_params(unsigned char, unsigned int, unsigned int, unsigned int);
extern void reg_set_bit(unsigned int, volatile unsigned int *);
extern void reg_clear_bit(unsigned int, volatile unsigned int *);
extern void timer_delay_long_units(unsigned short);

#define PHY_ENTRY_RX21_FIRST    2       /* hdmi_phy_records entries 2 / 3 belong to HDMI 2.1 receivers 0 / 1 */

/* Ranges of the target (printed "Target %dM") that set bit 5 of the PLL control register. */
#define TARGET_TWO_PORT_ABOVE   0x3bb   /* above this: hdmi_rx21_two_port_mode_flags (printed "2PortMode") = 1 */
#define TARGET_HIGH_BASE        941     /* bit 5 set for 941..979 when the flag is 1 */
#define TARGET_HIGH_SPAN        0x26
#define TARGET_LOW_BASE         470     /* bit 5 set for 470..490 when the flag is 0 */
#define TARGET_LOW_SPAN         0x14
#define TARGET_SPLIT            0x31f   /* (target >> flag) at most this: parameter set A, else set B */

/* Block 0 words 1 and 2: bits pulsed in two-port mode. Block 6 word 0x58 / 4 = 0x16: the divider word. */
#define BLOCK0_REG_4            1
#define BLOCK0_REG_8            2
#define BLOCK6_DIVIDER          (0x58 / 4)
#define DIVIDER_NUMERATOR       0x3c00000
#define DIVIDER_SHIFT           9
#define DIVIDER_LOW_BITS        0x1c    /* low bits written together with the quotient */
#define DIVIDER_FINAL_LOW_BYTE  4       /* low byte after the pulse */
#define TARGET_LOW_LIMIT        0x32    /* at most this: fixed values go into words 0x44, 0x4c, 0x40, 0x04 of block 6 */

/*
 * Sets the FRL PLL of an HDMI 2.1 receiver for a target value (the only caller,
 * DRV_HDMI_ModeDetect_FSM_FRL_Payload, passes hdmi_rx21_frl_payload_ticks of the receiver). In order:
 *  1. Targets above 955 set hdmi_rx21_two_port_mode_flags[port] ("2PortMode") to 1, others to 0. Bit 5 of the PLL
 *     control register (hdmi_rx21_set_pll_ctrl_bit5) is set for 941..979 in the first case and for 470..490
 *     in the second, otherwise cleared.
 *  2. The PLL parameters are written (hdmi_rx21_write_pll_params): 4, 2, 0x117 when the target shifted right
 *     by the flag is at most 0x31f, else 5, 2, 0x100.
 *  3. With the flag set: bit 12 set, bit 13 cleared and bit 15 set in block 0 word 2, then bit 8 of word 1 set
 *     for one timer unit and cleared.
 *  4. The target is stored in the PHY record of the receiver (entry 2 + port) and printed with the FRL rate
 *     of the link-training record and the flag.
 *  5. A target other than 0 sets the divider word 0x58 of block 6 to ((0x3c00000 / target) << 9) | 0x1c,
 *     pulses its bit 8 and then sets its low byte to 4.
 *  6. A target of 0x32 or less writes fixed values into words 0x44, 0x4c, 0x40 of block 6, clears bit 14 of
 *     the block's first word and sets the top byte of its word 1 to 0x39.
 *   port_number: HDMI 2.1 receiver 0 or 1 (the letter in the print is 'A' + port)
 *   target:      target value in MHz as printed ("Target %dM")
 */
void FRL_PLL(unsigned int port_number, unsigned int target)
{
    unsigned char port = port_number;
    unsigned char sel = PHY_ENTRY_RX21_FIRST;
    volatile unsigned int *r;

    if (port == 1)
        sel = PHY_ENTRY_RX21_FIRST + 1;
    if (target > TARGET_TWO_PORT_ABOVE) {
        hdmi_rx21_two_port_mode_flags[port] = 1;
        if (target - TARGET_HIGH_BASE <= TARGET_HIGH_SPAN)
            hdmi_rx21_set_pll_ctrl_bit5(port, 1);
        else
            hdmi_rx21_set_pll_ctrl_bit5(port, 0);
    } else if (target - TARGET_LOW_BASE <= TARGET_LOW_SPAN) {
        hdmi_rx21_two_port_mode_flags[port] = 0;
        hdmi_rx21_set_pll_ctrl_bit5(port, 1);
    } else {
        hdmi_rx21_two_port_mode_flags[port] = 0;
        hdmi_rx21_set_pll_ctrl_bit5(port, 0);
    }
    if ((target >> hdmi_rx21_two_port_mode_flags[port]) <= TARGET_SPLIT)
        hdmi_rx21_write_pll_params(port, 4, 2, 0x117);
    else
        hdmi_rx21_write_pll_params(port, 5, 2, 0x100);
    if (hdmi_rx21_two_port_mode_flags[port] != 0) {
        reg_set_bit(0xc, hdmi_rx21_reg_blocks[port].block0 + BLOCK0_REG_8);
        reg_clear_bit(0xd, hdmi_rx21_reg_blocks[port].block0 + BLOCK0_REG_8);
        reg_set_bit(0xf, hdmi_rx21_reg_blocks[port].block0 + BLOCK0_REG_8);
        reg_set_bit(8, hdmi_rx21_reg_blocks[port].block0 + BLOCK0_REG_4);
        timer_delay_long_units(1);
        reg_clear_bit(8, hdmi_rx21_reg_blocks[port].block0 + BLOCK0_REG_4);
    }
    hdmi_phy_records[sel].half_0xa = target;
    hdmi_phy_records[sel].phy_clock_mhz = target;
    dbg_printf("Port%c FRL_PLL Target %dM, FRL Rate %d, 2PortMode=%d\n", (char)(port_number + 'A'), (unsigned short)target,
                 hdmi_rx21_lts_records[port].frl_rate, hdmi_rx21_two_port_mode_flags[port]);
    if (target != 0) {
        hdmi_rx21_reg_blocks[port].block6[BLOCK6_DIVIDER] = ((DIVIDER_NUMERATOR / target) << DIVIDER_SHIFT) | DIVIDER_LOW_BITS;
        reg_set_bit(8, hdmi_rx21_reg_blocks[port].block6 + BLOCK6_DIVIDER);
        reg_clear_bit(8, hdmi_rx21_reg_blocks[port].block6 + BLOCK6_DIVIDER);
        hdmi_rx21_reg_blocks[port].block6[BLOCK6_DIVIDER] = (hdmi_rx21_reg_blocks[port].block6[BLOCK6_DIVIDER] & ~0xff) | DIVIDER_FINAL_LOW_BYTE;
    }
    if (target <= TARGET_LOW_LIMIT) {
        r = hdmi_rx21_reg_blocks[port].block6;
        r[0x44 / 4] = (r[0x44 / 4] & 0xffffff) | 0xb8000000;
        r[0x4c / 4] = (r[0x4c / 4] & 0xffff0000) | 0x40;
        r[0x40 / 4] = (r[0x40 / 4] & 0xff0000ff) | 0x20000;
        r[0x40 / 4] &= 0xffffff;
        r[0x44 / 4] = (r[0x44 / 4] & ~0xff) | 0x70;
        reg_clear_bit(0xe, r);
        hdmi_rx21_reg_blocks[port].block6[1] = (hdmi_rx21_reg_blocks[port].block6[1] & 0xffff) | 0x39000000;
    }
}
