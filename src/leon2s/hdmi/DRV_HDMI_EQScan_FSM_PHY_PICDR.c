/* DRV_HDMI_EQScan_FSM_PHY_PICDR  (DRV_HDMI_EQScan_FSM_PHY_PICDR)
 *
 * EQ scan step: set the clock-recovery (PI-CDR) registers for the clock range.
 *   port: PHY
 * Note: State function of the EQ scan table run by hdmi_eq_run_scan_fsm.
 * Name basis: proven - original name printed: 'DRV_HDMI_EQScan_FSM_PHY_PICDR'
 *
 * Matching notes
 * --------------
 * leon2s DRV_HDMI_EQScan_FSM_PHY_PICDR @ 0xa007c4b8-0xa007cea4 (2540 bytes), flags -mcpu=v8 -Os -g
 * (section default).
 * Source forms the exact build depends on:
 *  - the compare chain clock < 100 / 160 / 300 / <= 600; the 300..600 arm reaches the 160..300 arm through
 *    'goto' when hdmi_eq_get_clock_ratio_mode returns 0 (the firmware extends port again at that join);
 *  - the register 0x1f44 test is written 'clock <= 300' first.
 */

/* Message groups of dbg_hdmi_message_flags: every print of the EQ scan is in group EQ_FLOW. */
#define HDMI_MSG_EQ_FLOW 0x02

/* States of the EQ scan: the index into hdmi_eq_scan_state_handlers. */
#define EQSCAN_STATE_EQ     4           /* DRV_HDMI_EQScan_FSM_PHY_EQ */

/* Limits of the PHY clock (phy_clock_mhz) for the register sets below: below 100, below 160, below 300,
   up to 600 (above that: "out clk range"). */
#define EQ_CLOCK_LIMIT_100  100
#define EQ_CLOCK_LIMIT_160  160
#define EQ_CLOCK_LIMIT_300  300
#define EQ_CLOCK_LIMIT_600  600

#define ICDR_CLOCK_MASK     0x3ff       /* low 10 bits of register 0x11f4: "Set ICDR Clock" */

/* Registers of the three channels: each channel has the same set of registers at 0x1100 + 0x400 * ch, and a
   second set just below it at 0x1000 + 0x400 * ch. */
#define PHY_CH_REG(ch, reg)     (0x1100 + 0x400 * (ch) + (reg))
#define PHY_CH_LOW_REG(ch, reg) (0x1000 + 0x400 * (ch) + (reg))
#define CH_REG_04           0x04        /* low byte = 3 */
#define CH_REG_08           0x08        /* low byte = 5, bits 8..15 = 1 */
#define CH_REG_40           0x40        /* bit 0: cleared on channel 0, set on channels 1 and 2 */
#define CH_LOW_REG_14       0x14        /* top byte by clock range (0xf3 / 0xf7) */
#define CH_LOW_REG_18       0x18        /* bits 16..20 = 4, bits 21..22 by clock range */

/* Registers written only once (most of them in channel 0's set). */
#define PHY_REG_114C        0x114c      /* bits 8..15 = 6 */
#define PHY_REG_1154        0x1154      /* top byte = 2, low byte = 0xf0, bits 8..12 = 0 */
#define PHY_REG_115C        0x115c      /* bits 16..17 = 0, bits 18..22 = 1, 0, 0, 0, 1 */
#define PHY_REG_1160        0x1160      /* bits 24..25 by clock range, bits 26..27 = 1, bit 28 clear, 29..30 set */
#define PHY_REG_11F0        0x11f0      /* low byte: 0, or 0x80 from 160 MHz up */
#define PHY_REG_ICDR_CLOCK  0x11f4      /* low 10 bits printed as "ICDR Clock"; bits 12..15 from 160 MHz up */
#define PHY_REG_1C00        0x1c00      /* low byte cleared */
#define PHY_REG_1E80        0x1e80      /* bit 6, read on PHY 0 for every port */
#define PHY_REG_1F00        0x1f00      /* bits 8..15: 0 below 100 MHz, else 7 */
#define PHY_REG_1F40        0x1f40      /* bit 26: clear below 100 MHz, else set */
#define PHY_REG_1F44        0x1f44      /* HDMI 2.1 PHY: low 6 bits 0x1f up to 300 MHz, else 0x3f */
#define PHY_REG_3534        0x3534      /* bits 8..15 = 0x40 */

/* The HDMI PHY record (24 bytes per PHY). */
struct hdmi_phy_record {
    unsigned char power;
    unsigned char eq_done;
    unsigned char eq_reset_request;
    unsigned char clock_detect;
    unsigned char byte_0x4[4];
    unsigned short phy_clock_mhz;       /* +8: printed 'Phy Clk*1 %dMHz' / 'Phy Clk*4 %dMHz' */
    unsigned char rest_0xa[0x18 - 0xa];
};

/* The scan state of one port (12 bytes per port). */
struct eq_scan_record {
    unsigned int state;                 /* EQSCAN_STATE_*: the step hdmi_eq_run_scan_fsm runs next */
    unsigned char byte_0x4[3];
    unsigned char check_error_round;
    unsigned char byte_0x8;
    unsigned char pad[3];
};
extern struct hdmi_phy_record hdmi_phy_records[];
extern struct eq_scan_record hdmi_eq_scan_records[];
extern unsigned int dbg_hdmi_message_flags;
extern unsigned char DAT_a0067ac0[];    /* "[EQ]: Port%c %s: " */
extern int dbg_printf(const void *, ...);
extern int dbg_print_string(const char *);
extern unsigned char hdmi_is_hdmi21_phy(unsigned char);
extern unsigned char hdmi_eq_get_clock_ratio_mode(unsigned char);
extern void hdmi_phy_write_bit(int, unsigned int, unsigned char, unsigned short);
extern void hdmi_phy_update_reg(unsigned int, unsigned short, unsigned int, unsigned int);
extern void timer_delay_long_units(unsigned short);

extern unsigned int hdmi_phy_test_bit(unsigned int, unsigned char, unsigned short);

/*
 * EQ scan state 3. The D-PHY step (state 2) comes here; this step always goes on to the EQ step (state 4).
 *
 *   port  HDMI receiver PHY (printed as the letter 'A' + port)
 *
 * Always returns 0, so hdmi_eq_run_scan_fsm stops until its next call.
 *
 * Phases:
 *  1. Fixed values: registers 0x3534, 0x1154, 0x114c, 0x115c and the 0x04 / 0x08 registers of the three
 *     channels (0x1104 / 0x1108, 0x1504 / 0x1508, 0x1904 / 0x1908).
 *  2. Clock range, by the PHY clock (phy_clock_mhz): the registers 0x1014 / 0x1018 of the three channels and
 *     0x1f40, 0x1f00, 0x1160, 0x11f0, 0x11f4.
 *       below 100 MHz   the ICDR clock field of 0x11f4 = the PHY clock,
 *       below 160 MHz   the ICDR clock field = half the PHY clock,
 *       below 300 MHz   bits 12..15 of 0x11f4 = 8; bits 24..25 of 0x1160 = 3 when bit 6 of PHY 0's
 *                       register 0x1e80 is set, else 0,
 *       up to 600 MHz   with hdmi_eq_get_clock_ratio_mode non-zero: bits 12..15 of 0x11f4 = 0xf and
 *                       0x3534 written again; with 0 the values of the range below 300 MHz,
 *       above 600 MHz   nothing ("out clk range").
 *  3. HDMI 2.1 PHY only: low 6 bits of 0x1f44 = 0x1f up to 300 MHz, else 0x3f.
 *  4. Bit 0 of 0x1140 cleared and of 0x1540 / 0x1940 set, low byte of 0x1c00 cleared, a short wait, and on to
 *     the EQ step.
 */
int DRV_HDMI_EQScan_FSM_PHY_PICDR(unsigned char port)
{
    unsigned short clock = hdmi_phy_records[port].phy_clock_mhz;

    if ((dbg_hdmi_message_flags & HDMI_MSG_EQ_FLOW) != 0)
        dbg_printf(DAT_a0067ac0, (char)(port + 'A'), "DRV_HDMI_EQScan_FSM_PHY_PICDR");

    /* Phase 1: values for every clock. */
    hdmi_phy_update_reg(port, PHY_REG_3534, 0xffff00ff, 0x4000);
    hdmi_phy_update_reg(port, PHY_REG_1154, 0xffffff, 0x2000000);
    hdmi_phy_update_reg(port, PHY_CH_REG(0, CH_REG_04), 0xffffff00, 3);
    hdmi_phy_update_reg(port, PHY_CH_REG(0, CH_REG_08), 0xffffff00, 5);
    hdmi_phy_update_reg(port, PHY_CH_REG(0, CH_REG_08), 0xffff00ff, 0x100);
    hdmi_phy_update_reg(port, PHY_CH_REG(1, CH_REG_04), 0xffffff00, 3);
    hdmi_phy_update_reg(port, PHY_CH_REG(1, CH_REG_08), 0xffffff00, 5);
    hdmi_phy_update_reg(port, PHY_CH_REG(1, CH_REG_08), 0xffff00ff, 0x100);
    hdmi_phy_update_reg(port, PHY_CH_REG(2, CH_REG_04), 0xffffff00, 3);
    hdmi_phy_update_reg(port, PHY_CH_REG(2, CH_REG_08), 0xffffff00, 5);
    hdmi_phy_update_reg(port, PHY_CH_REG(2, CH_REG_08), 0xffff00ff, 0x100);
    hdmi_phy_update_reg(port, PHY_REG_1154, 0xffffff00, 0xf0);
    hdmi_phy_update_reg(port, PHY_REG_1154, 0xffffe0ff, 0);
    hdmi_phy_update_reg(port, PHY_REG_114C, 0xffff00ff, 0x600);
    hdmi_phy_update_reg(port, PHY_REG_115C, 0xfffcffff, 0);
    hdmi_phy_write_bit(1, 0x12, port, PHY_REG_115C);
    hdmi_phy_write_bit(0, 0x13, port, PHY_REG_115C);
    hdmi_phy_write_bit(0, 0x14, port, PHY_REG_115C);
    hdmi_phy_write_bit(0, 0x15, port, PHY_REG_115C);
    hdmi_phy_write_bit(1, 0x16, port, PHY_REG_115C);

    /* Phase 2: values by clock range. */
    if (clock < EQ_CLOCK_LIMIT_100) {
        hdmi_phy_update_reg(port, PHY_CH_LOW_REG(0, CH_LOW_REG_14), 0xffffff, 0xf3000000);
        hdmi_phy_update_reg(port, PHY_CH_LOW_REG(1, CH_LOW_REG_14), 0xffffff, 0xf3000000);
        hdmi_phy_update_reg(port, PHY_CH_LOW_REG(2, CH_LOW_REG_14), 0xffffff, 0xf3000000);
        hdmi_phy_write_bit(0, 0x1a, port, PHY_REG_1F40);
        hdmi_phy_update_reg(port, PHY_CH_LOW_REG(0, CH_LOW_REG_18), 0xffe0ffff, 0x40000);
        hdmi_phy_update_reg(port, PHY_CH_LOW_REG(0, CH_LOW_REG_18), 0xff9fffff, 0x400000);
        hdmi_phy_update_reg(port, PHY_CH_LOW_REG(1, CH_LOW_REG_18), 0xffe0ffff, 0x40000);
        hdmi_phy_update_reg(port, PHY_CH_LOW_REG(1, CH_LOW_REG_18), 0xff9fffff, 0x400000);
        hdmi_phy_update_reg(port, PHY_CH_LOW_REG(2, CH_LOW_REG_18), 0xffe0ffff, 0x40000);
        hdmi_phy_update_reg(port, PHY_CH_LOW_REG(2, CH_LOW_REG_18), 0xff9fffff, 0x400000);
        hdmi_phy_update_reg(port, PHY_REG_1F00, 0xffff00ff, 0);
        hdmi_phy_update_reg(port, PHY_REG_1160, 0xfcffffff, 0);
        hdmi_phy_update_reg(port, PHY_REG_1160, 0xf3ffffff, 0x4000000);
        hdmi_phy_write_bit(0, 0x1c, port, PHY_REG_1160);
        hdmi_phy_write_bit(1, 0x1d, port, PHY_REG_1160);
        hdmi_phy_write_bit(1, 0x1e, port, PHY_REG_1160);
        if ((dbg_hdmi_message_flags & HDMI_MSG_EQ_FLOW) != 0)
            dbg_printf("[EQ]: # Port%c, Set ICDR Clock = 0x%04x\n\n", (char)(port + 'A'), clock);
        hdmi_phy_update_reg(port, PHY_REG_11F0, 0xffffff00, 0);
        hdmi_phy_update_reg(port, PHY_REG_ICDR_CLOCK, 0xfffffc00, clock & ICDR_CLOCK_MASK);
    } else if (clock < EQ_CLOCK_LIMIT_160) {
        hdmi_phy_update_reg(port, PHY_CH_LOW_REG(0, CH_LOW_REG_14), 0xffffff, 0xf7000000);
        hdmi_phy_update_reg(port, PHY_CH_LOW_REG(1, CH_LOW_REG_14), 0xffffff, 0xf7000000);
        hdmi_phy_update_reg(port, PHY_CH_LOW_REG(2, CH_LOW_REG_14), 0xffffff, 0xf7000000);
        hdmi_phy_write_bit(1, 0x1a, port, PHY_REG_1F40);
        hdmi_phy_update_reg(port, PHY_CH_LOW_REG(0, CH_LOW_REG_18), 0xffe0ffff, 0x40000);
        hdmi_phy_update_reg(port, PHY_CH_LOW_REG(0, CH_LOW_REG_18), 0xff9fffff, 0x400000);
        hdmi_phy_update_reg(port, PHY_CH_LOW_REG(1, CH_LOW_REG_18), 0xffe0ffff, 0x40000);
        hdmi_phy_update_reg(port, PHY_CH_LOW_REG(1, CH_LOW_REG_18), 0xff9fffff, 0x400000);
        hdmi_phy_update_reg(port, PHY_CH_LOW_REG(2, CH_LOW_REG_18), 0xffe0ffff, 0x40000);
        hdmi_phy_update_reg(port, PHY_CH_LOW_REG(2, CH_LOW_REG_18), 0xff9fffff, 0x400000);
        hdmi_phy_update_reg(port, PHY_REG_1F00, 0xffff00ff, 0x700);
        hdmi_phy_update_reg(port, PHY_REG_1160, 0xfcffffff, 0);
        hdmi_phy_update_reg(port, PHY_REG_1160, 0xf3ffffff, 0x4000000);
        hdmi_phy_write_bit(0, 0x1c, port, PHY_REG_1160);
        hdmi_phy_write_bit(1, 0x1d, port, PHY_REG_1160);
        hdmi_phy_write_bit(1, 0x1e, port, PHY_REG_1160);
        if ((dbg_hdmi_message_flags & HDMI_MSG_EQ_FLOW) != 0)
            dbg_printf("[EQ]: # Port%c, Set ICDR Clock = 0x%04x\n\n", (char)(port + 'A'), clock >> 1);
        hdmi_phy_update_reg(port, PHY_REG_11F0, 0xffffff00, 0);
        hdmi_phy_update_reg(port, PHY_REG_ICDR_CLOCK, 0xfffffc00, (clock >> 1) & ICDR_CLOCK_MASK);
    } else if (clock < EQ_CLOCK_LIMIT_300) {
range_300:
        hdmi_phy_update_reg(port, PHY_CH_LOW_REG(0, CH_LOW_REG_14), 0xffffff, 0xf7000000);
        hdmi_phy_update_reg(port, PHY_CH_LOW_REG(1, CH_LOW_REG_14), 0xffffff, 0xf7000000);
        hdmi_phy_update_reg(port, PHY_CH_LOW_REG(2, CH_LOW_REG_14), 0xffffff, 0xf7000000);
        hdmi_phy_write_bit(1, 0x1a, port, PHY_REG_1F40);
        hdmi_phy_update_reg(port, PHY_CH_LOW_REG(0, CH_LOW_REG_18), 0xffe0ffff, 0x40000);
        hdmi_phy_update_reg(port, PHY_CH_LOW_REG(0, CH_LOW_REG_18), 0xff9fffff, 0x200000);
        hdmi_phy_update_reg(port, PHY_CH_LOW_REG(1, CH_LOW_REG_18), 0xffe0ffff, 0x40000);
        hdmi_phy_update_reg(port, PHY_CH_LOW_REG(1, CH_LOW_REG_18), 0xff9fffff, 0x200000);
        hdmi_phy_update_reg(port, PHY_CH_LOW_REG(2, CH_LOW_REG_18), 0xffe0ffff, 0x40000);
        hdmi_phy_update_reg(port, PHY_CH_LOW_REG(2, CH_LOW_REG_18), 0xff9fffff, 0x200000);
        hdmi_phy_update_reg(port, PHY_REG_1F00, 0xffff00ff, 0x700);
        if (hdmi_phy_test_bit(6, 0, PHY_REG_1E80) == 1)
            hdmi_phy_update_reg(port, PHY_REG_1160, 0xfcffffff, 0x3000000);
        else
            hdmi_phy_update_reg(port, PHY_REG_1160, 0xfcffffff, 0);
        hdmi_phy_update_reg(port, PHY_REG_1160, 0xf3ffffff, 0x4000000);
        hdmi_phy_write_bit(0, 0x1c, port, PHY_REG_1160);
        hdmi_phy_write_bit(1, 0x1d, port, PHY_REG_1160);
        hdmi_phy_write_bit(1, 0x1e, port, PHY_REG_1160);
        hdmi_phy_update_reg(port, PHY_REG_11F0, 0xffffff00, 0x80);
        hdmi_phy_update_reg(port, PHY_REG_ICDR_CLOCK, 0xffff0fff, 0x8000);
    } else if (clock <= EQ_CLOCK_LIMIT_600) {
        /* Clock ratio mode 0: the values of the range below 300 MHz. */
        if (!hdmi_eq_get_clock_ratio_mode(port))
            goto range_300;
        hdmi_phy_update_reg(port, PHY_CH_LOW_REG(0, CH_LOW_REG_14), 0xffffff, 0xf7000000);
        hdmi_phy_update_reg(port, PHY_CH_LOW_REG(1, CH_LOW_REG_14), 0xffffff, 0xf7000000);
        hdmi_phy_update_reg(port, PHY_CH_LOW_REG(2, CH_LOW_REG_14), 0xffffff, 0xf7000000);
        hdmi_phy_write_bit(1, 0x1a, port, PHY_REG_1F40);
        hdmi_phy_update_reg(port, PHY_REG_3534, 0xffff00ff, 0x4000);
        hdmi_phy_update_reg(port, PHY_CH_LOW_REG(0, CH_LOW_REG_18), 0xffe0ffff, 0x40000);
        hdmi_phy_update_reg(port, PHY_CH_LOW_REG(0, CH_LOW_REG_18), 0xff9fffff, 0x200000);
        hdmi_phy_update_reg(port, PHY_CH_LOW_REG(1, CH_LOW_REG_18), 0xffe0ffff, 0x40000);
        hdmi_phy_update_reg(port, PHY_CH_LOW_REG(1, CH_LOW_REG_18), 0xff9fffff, 0x200000);
        hdmi_phy_update_reg(port, PHY_CH_LOW_REG(2, CH_LOW_REG_18), 0xffe0ffff, 0x40000);
        hdmi_phy_update_reg(port, PHY_CH_LOW_REG(2, CH_LOW_REG_18), 0xff9fffff, 0x200000);
        hdmi_phy_update_reg(port, PHY_REG_1F00, 0xffff00ff, 0x700);
        hdmi_phy_update_reg(port, PHY_REG_1160, 0xfcffffff, 0x3000000);
        hdmi_phy_update_reg(port, PHY_REG_1160, 0xf3ffffff, 0x4000000);
        hdmi_phy_write_bit(0, 0x1c, port, PHY_REG_1160);
        hdmi_phy_write_bit(1, 0x1d, port, PHY_REG_1160);
        hdmi_phy_write_bit(1, 0x1e, port, PHY_REG_1160);
        hdmi_phy_update_reg(port, PHY_REG_11F0, 0xffffff00, 0x80);
        hdmi_phy_update_reg(port, PHY_REG_ICDR_CLOCK, 0xffff0fff, 0xf000);
    } else {
        if ((dbg_hdmi_message_flags & HDMI_MSG_EQ_FLOW) != 0)
            dbg_print_string("[EQ]: HDMI Mode : out clk range!!!\n");
    }

    /* Phase 3: HDMI 2.1 PHYs only. */
    if (hdmi_is_hdmi21_phy(port)) {
        if (clock <= EQ_CLOCK_LIMIT_300)
            hdmi_phy_update_reg(port, PHY_REG_1F44, 0xffffffc0, 0x1f);
        else
            hdmi_phy_update_reg(port, PHY_REG_1F44, 0xffffffc0, 0x3f);
    }

    /* Phase 4: last register writes, then on to the EQ step. */
    hdmi_phy_write_bit(0, 0x0, port, PHY_CH_REG(0, CH_REG_40));
    hdmi_phy_write_bit(1, 0x0, port, PHY_CH_REG(1, CH_REG_40));
    hdmi_phy_write_bit(1, 0x0, port, PHY_CH_REG(2, CH_REG_40));
    hdmi_phy_update_reg(port, PHY_REG_1C00, 0xffffff00, 0);
    timer_delay_long_units(1);
    hdmi_eq_scan_records[port].state = EQSCAN_STATE_EQ;
    return 0;
}
