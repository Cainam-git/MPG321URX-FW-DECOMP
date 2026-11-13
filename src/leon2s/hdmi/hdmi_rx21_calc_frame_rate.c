/* hdmi_rx21_calc_frame_rate  (FUN_a00a2cf4)
 *
 * Compute the line rate and frame rate of an HDMI 2.1 input from its PHY clock.
 *   port: receiver
 *   line_rate_out
 *   frame_rate_out: frame rate x100 out
 * Returns: 0, 0x23 for a bad port
 * Name basis: derived - PHY register 0x1F1C clock / htotal / vtotal; frame rate in 1/100 Hz; caller
 *   FSM_Complete
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00a2cf4 @ 0xa00a2cf4-0xa00a2e48 (340 bytes), flags -mcpu=v8 -Os -g.
 * Source forms the exact build depends on:
 *  - the clock is accumulated in the member of the zero-initialised local struct `clk` (fraction first, then
 *    'clk.hz = whole MHz part + clk.hz'), and the zero arm stores clk.hz. A member store is expanded through a
 *    temporary and a copy, so the sum keeps the whole-MHz term as its first operand, and the initialiser makes
 *    clk.hz the cse class head, so the copy becomes the add into the fraction's register (firmware
 *    'add %o0, %o4, %o4');
 *  - the register block pointer is 'volatile unsigned long *'.
 */

/* Table of register block addresses, one 0x34-byte row per HDMI 2.1 receiver (filled by
   hdmi_rx21_init_register_pointers). This routine reads block 0 only. */
struct rx21_reg_blocks {
    volatile unsigned long *block0;
    unsigned int block1;
    unsigned char blocks_2_to_12[0x34 - 8];
};

/* HDMI PHY record (24 bytes per PHY, hdmi_phy_records): the fields used here. */
struct hdmi_phy_record {
    unsigned char _0[4];
    unsigned char clock_ratio_mode;     /* +4: when not 0 the measured clock is multiplied by 4 */
    unsigned char _5[7];
    unsigned int clock_hz;              /* +0xC: the clock computed here */
    unsigned char _10[8];
};

#define PHY_RX21_0           2          /* PHY numbers of the HDMI 2.1 receivers 0 / 1 */
#define PHY_RX21_1           3
#define RESULT_BAD_PORT      0x23       /* returned for a receiver other than 0 or 1 */

/* Words of register block 0. */
#define BLOCK0_REG_08        (0x08 / 4) /* bits 6..7: the clock is divided by this value + 1 */
#define BLOCK0_HTOTAL        (0x38 / 4) /* bits 16..31, shifted left by hdmi_rx21_two_port_mode_flags */
#define BLOCK0_VTOTAL        (0x3c / 4)

/* PHY register with the PHY clock: bits 0..9 are read as whole MHz, bits 12..15 as sixteenths of a MHz. */
#define PHY_REG_CLOCK        0x1f1c
#define HZ_PER_MHZ           1000000

extern struct rx21_reg_blocks hdmi_rx21_reg_blocks[];
extern unsigned char hdmi_rx21_two_port_mode_flags[];
extern struct hdmi_phy_record hdmi_phy_records[];
extern unsigned int hdmi_phy_read_reg(unsigned int, unsigned short);

/*
 * Compute the line rate and the frame rate of HDMI 2.1 receiver `port` from its PHY clock and its measured
 * line and frame lengths.
 *
 *   port             HDMI 2.1 receiver 0 or 1 (PHY 2 or 3)
 *   line_rate_out    clock / htotal (lines per second)
 *   frame_rate_out   line rate * 100 / vtotal (frames per second, in hundredths)
 *
 * Returns 0, or RESULT_BAD_PORT (outputs untouched) for another port. When htotal or vtotal reads 0 both
 * outputs are 0 and the PHY record is not changed.
 *
 * The clock in Hz is the PHY clock register converted to Hz, divided by (block 0 word 2 bits 6..7) + 1 and
 * multiplied by 4 when the PHY's clock_ratio_mode is set; it is also kept in the PHY record's clock_hz.
 * Only caller: DRV_HDMI_ModeDetect_FSM_Complete, at 'Sync Stable'; it does not use the outputs further.
 */
unsigned int hdmi_rx21_calc_frame_rate(unsigned char port, unsigned int *line_rate_out, unsigned int *frame_rate_out)
{
    unsigned char phy;
    unsigned short htotal, vtotal;
    unsigned int clock_reg, clock, line_rate;
    struct { unsigned int hz; } clk = { 0 };

    if (port == 0)
        phy = PHY_RX21_0;
    else if (port == 1)
        phy = PHY_RX21_1;
    else
        return RESULT_BAD_PORT;
    htotal = (hdmi_rx21_reg_blocks[port].block0[BLOCK0_HTOTAL] >> 16) << hdmi_rx21_two_port_mode_flags[port];
    vtotal = hdmi_rx21_reg_blocks[port].block0[BLOCK0_VTOTAL];
    if (htotal == 0 || vtotal == 0) {
        *line_rate_out = clk.hz;
        *frame_rate_out = clk.hz;
    } else {
        clock_reg = hdmi_phy_read_reg(phy, PHY_REG_CLOCK);
        clk.hz = ((clock_reg >> 12) & 0xf) * HZ_PER_MHZ / 16;
        clk.hz = (clock_reg & 0x3ff) * HZ_PER_MHZ + clk.hz;
        clock = clk.hz / (((hdmi_rx21_reg_blocks[port].block0[BLOCK0_REG_08] & 0xc0) >> 6) + 1);
        if (hdmi_phy_records[phy].clock_ratio_mode != 0)
            clock <<= 2;
        hdmi_phy_records[phy].clock_hz = clock;
        line_rate = clock / htotal;
        *line_rate_out = line_rate;
        *frame_rate_out = line_rate * 100 / vtotal;
    }
    return 0;
}
