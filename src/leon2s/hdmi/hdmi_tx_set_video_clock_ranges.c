/* hdmi_tx_set_video_clock_ranges  (FUN_a0095f20)
 *
 * Compute the HDMI TX video clock and set the clock-range registers.
 *   port: HDMI TX port
 *   frl_mode: 1 = FRL
 *   clock_mode: clock shift
 *   depth: bits per colour
 *   frl_clock_mode: FRL clock shift
 *   frl_depth: FRL bits per colour
 * Name basis: proven - prints '[HDMI_TX]: video_clk = %d' / 'FRL_video_clk = %d' and register read-backs
 *   8700..8780
 *
 * Matching notes
 * --------------
 * leon2s FUN_a0095f20 @ 0xa0095f20-0xa00961e8, flags -mcpu=v8 -Os -g.
 * Source form: each clock range assigns both values (the firmware repeats the depth = 8 store);
 * hdmi_tx_reg_read8 is declared with a short result and its value masked with 0xff at each print.
 */
/* The HDMI TX channel record (28 bytes per TX port, hdmi_tx_output_records); only the pixel clock is read here. */
struct hdmi_tx_channel_record {
    unsigned int word_0x0;
    unsigned int word_0x4;
    int pixel_clock;                    /* +8, MHz */
    unsigned char rest[0x1c - 0xc];
};
extern struct hdmi_tx_channel_record hdmi_tx_output_records[];
extern int dbg_printf(const char *, ...);
extern void hdmi_tx_reg_update_bits(unsigned int port, unsigned int bank, short reg, unsigned int mask, unsigned int mode);
extern void hdmi_tx_set_clock_mode_reg5(unsigned int, unsigned char);
extern void hdmi_tx_set_color_depth_reg6(unsigned int, unsigned char);
extern void hdmi_tx_set_clock_mode_reg7f(unsigned int, unsigned char);
extern void hdmi_tx_set_color_depth_reg7f(unsigned int, unsigned char);
extern short hdmi_tx_reg_read8(unsigned int, unsigned short, unsigned short);

#define HDMI_TX_BANK_PHY    1
#define BITS_CLEAR          0       /* mode argument of hdmi_tx_reg_update_bits */
#define BITS_SET            1

/* Bank 1 registers. TMDS uses registers 0, 5 and 6, FRL registers 0x80 and 0x7F. */
#define PHY_REG_0           0       /* bit 4: set for a video clock of 25..49 */
#define PHY_REG_5           5       /* bits 6..7: set, then cleared above 79; bits 2..3: clock mode */
#define PHY_REG_6           6       /* bits 2..3: 10 / 12-bit colour depth */
#define PHY_REG_80          0x80    /* bit 0: set for a video clock of 25..49 */
#define PHY_REG_7F          0x7f    /* bits 6..7 as register 5; bits 2..3: clock mode; bits 4..5: depth */
#define REG_0_BIT4          0x10
#define REG_80_BIT0         1
#define BITS_6_7            0xc0

#define DEPTH_8_BITS        8

/*
 * Compute the video clock of an HDMI TX port, print it and choose the clock mode by its range. Only
 * hdmi_tx_setup_clock_path calls it, on chips above revision 0x81, with (port, frl_mode, clock_mode,
 * depth_6, 0, depth_7f): for TMDS (0, depth, 0, depth), for FRL (2, 8, 0, depth).
 *
 *   port            HDMI TX port
 *   frl_mode        0: TMDS, the TMDS pair (clock_mode, depth) is chosen; else FRL, the FRL pair
 *   clock_mode      clock mode of register 5 (0 / 1 / 2)
 *   depth           bits per colour for register 6
 *   frl_clock_mode  clock mode of register 0x7F
 *   frl_depth       bits per colour for register 0x7F
 *
 * video clock = pixel_clock * (depth / 2) / (4 >> clock_mode), with the pair of the chosen link. That pair is
 * then replaced by the clock range:
 *
 *   video clock     clock mode   depth   also
 *     up to 12          2          8
 *     13..24            1          8
 *     25..49            1          8      bit 4 of register 0 (FRL: bit 0 of 0x80) set
 *     50..79            0          8
 *     80 and above      0          8      bits 6..7 of register 5 (FRL: 0x7F) cleared again
 *
 * Both pairs are then written (clock modes to registers 5 / 0x7F, depths to 6 / 0x7F); the pair of the other
 * link keeps the caller's values. The registers of the chosen link are read back and printed.
 */
void hdmi_tx_set_video_clock_ranges(unsigned char port, unsigned char frl_mode, unsigned char clock_mode, unsigned char depth, unsigned char frl_clock_mode, unsigned char frl_depth)
{
    int video_clock;

    if (frl_mode == 0) {
        video_clock = hdmi_tx_output_records[port].pixel_clock * (depth >> 1) / (4 >> clock_mode);
        dbg_printf("\x1b[0;34m[HDMI_TX]: video_clk = %d\n\r", video_clock);
        hdmi_tx_reg_update_bits(port, HDMI_TX_BANK_PHY, PHY_REG_0, REG_0_BIT4, BITS_CLEAR);
        hdmi_tx_reg_update_bits(port, HDMI_TX_BANK_PHY, PHY_REG_5, BITS_6_7, BITS_SET);
        if (video_clock <= 12) {
            clock_mode = 2;
            depth = DEPTH_8_BITS;
        } else if (video_clock <= 24) {
            clock_mode = 1;
            depth = DEPTH_8_BITS;
        } else if (video_clock <= 49) {
            clock_mode = 1;
            depth = DEPTH_8_BITS;
            hdmi_tx_reg_update_bits(port, HDMI_TX_BANK_PHY, PHY_REG_0, REG_0_BIT4, BITS_SET);
        } else if (video_clock <= 79) {
            clock_mode = 0;
            depth = DEPTH_8_BITS;
        } else {
            clock_mode = 0;
            depth = DEPTH_8_BITS;
            hdmi_tx_reg_update_bits(port, HDMI_TX_BANK_PHY, PHY_REG_5, BITS_6_7, BITS_CLEAR);
        }
    } else {
        video_clock = hdmi_tx_output_records[port].pixel_clock * (frl_depth >> 1) / (4 >> frl_clock_mode);
        dbg_printf("\x1b[0;34m[HDMI_TX]: FRL_video_clk = %d\n\r", video_clock);
        hdmi_tx_reg_update_bits(port, HDMI_TX_BANK_PHY, PHY_REG_80, REG_80_BIT0, BITS_CLEAR);
        hdmi_tx_reg_update_bits(port, HDMI_TX_BANK_PHY, PHY_REG_7F, BITS_6_7, BITS_SET);
        if (video_clock <= 12) {
            frl_clock_mode = 2;
            frl_depth = DEPTH_8_BITS;
        } else if (video_clock <= 24) {
            frl_clock_mode = 1;
            frl_depth = DEPTH_8_BITS;
        } else if (video_clock <= 49) {
            frl_clock_mode = 1;
            frl_depth = DEPTH_8_BITS;
            hdmi_tx_reg_update_bits(port, HDMI_TX_BANK_PHY, PHY_REG_80, REG_80_BIT0, BITS_SET);
        } else if (video_clock <= 79) {
            frl_clock_mode = 0;
            frl_depth = DEPTH_8_BITS;
        } else {
            frl_clock_mode = 0;
            frl_depth = DEPTH_8_BITS;
            hdmi_tx_reg_update_bits(port, HDMI_TX_BANK_PHY, PHY_REG_7F, BITS_6_7, BITS_CLEAR);
        }
    }
    hdmi_tx_set_clock_mode_reg5(port, clock_mode);
    hdmi_tx_set_color_depth_reg6(port, depth);
    hdmi_tx_set_clock_mode_reg7f(port, frl_clock_mode);
    hdmi_tx_set_color_depth_reg7f(port, frl_depth);
    if (frl_mode == 0) {
        dbg_printf("\x1b[0;34m[HDMI_TX]: 8700 = %02X\n\r", hdmi_tx_reg_read8(port, HDMI_TX_BANK_PHY, PHY_REG_0) & 0xff);
        dbg_printf("\x1b[0;34m[HDMI_TX]: 8705 = %02X\n\r", hdmi_tx_reg_read8(port, HDMI_TX_BANK_PHY, PHY_REG_5) & 0xff);
        dbg_printf("\x1b[0;34m[HDMI_TX]: 8706 = %02X\n\r", hdmi_tx_reg_read8(port, HDMI_TX_BANK_PHY, PHY_REG_6) & 0xff);
    } else {
        dbg_printf("\x1b[0;34m[HDMI_TX]: 8780 = %02X\n\r", hdmi_tx_reg_read8(port, HDMI_TX_BANK_PHY, PHY_REG_80) & 0xff);
        dbg_printf("\x1b[0;34m[HDMI_TX]: 877F = %02X\n\r", hdmi_tx_reg_read8(port, HDMI_TX_BANK_PHY, PHY_REG_7F) & 0xff);
    }
}
