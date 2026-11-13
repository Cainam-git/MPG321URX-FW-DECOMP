/* hdmi_tx_setup_clock_path  (FUN_a008e514)
 *
 * Set the HDMI TX clock ratio and colour depth fields for the chosen mode.
 *   port: HDMI TX port
 *   frl_mode: mode bit 4 of the TX record
 *   depth: record byte +0x11
 * Name basis: descriptive - older chips: the reg 5 / 6 / 0x7F setters; newer (revision > 0x81) the video_clk
 *   routine; TX command 7
 *
 * Matching notes
 * --------------
 * leon2s FUN_a008e514 @ 0xa008e514-0xa008e5ac, flags -mcpu=v8 -Os -g.
 * Source form: same form as hdmi_tx_set_regs_39_30: all byte locals first set to 0, then each arm assigns every
 * local (including the repeated 'clock_mode = 0' and 'depth_7f = depth').
 */
extern unsigned char sys_get_chip_revision(void);
extern void hdmi_tx_set_clock_mode_reg5(unsigned int param_1, unsigned char param_2);
extern void hdmi_tx_set_color_depth_reg6(unsigned int param_1, unsigned char param_2);
extern void hdmi_tx_set_clock_mode_reg7f(unsigned int param_1, unsigned char param_2);
extern void hdmi_tx_set_color_depth_reg7f(unsigned int param_1, unsigned char param_2);
extern void hdmi_tx_set_video_clock_ranges(unsigned char p1, unsigned char p2, unsigned char p3, unsigned char p4,
                         unsigned char p5, unsigned char p6);

#define CHIP_REV_81 0x81                /* sys_get_chip_revision: revisions above take the other path */
#define DEPTH_8_BITS 8                  /* bits per colour */

/*
 * Pick a clock mode and two colour-depth values from frl_mode and the depth, then hand them on:
 *   frl_mode == 0: clock mode 0, depth_6 = depth, depth_7f = depth;
 *   otherwise: clock mode 2, depth_6 = 8, depth_7f = depth.
 * On chips above revision 0x81 all of it goes to hdmi_tx_set_video_clock_ranges(port, frl_mode, clock_mode,
 * depth_6, 0, depth_7f). On older chips the four register setters run instead: clock mode of register 5,
 * depth of register 6, clock mode 0 of register 0x7F, depth of register 0x7F.
 *   port: HDMI TX port.  frl_mode: the channel record's frl_mode bit.  depth: the channel record's colour depth,
 *   or 8 when the caller passes DEPTH_8_BITS.
 * Called by hdmi_tx_run_step and hdmi_tx_is_frl_mode.
 */
void hdmi_tx_setup_clock_path(unsigned char port, unsigned char frl_mode, unsigned char depth)
{
    unsigned char clock_mode;
    unsigned char depth_6;
    unsigned char depth_7f;

    clock_mode = 0;
    depth_6 = 0;
    depth_7f = 0;
    if (frl_mode == 0) {
        clock_mode = 0;
        depth_6 = depth;
        depth_7f = depth;
    } else {
        clock_mode = 2;
        depth_6 = DEPTH_8_BITS;
        depth_7f = depth;
    }
    if (sys_get_chip_revision() > CHIP_REV_81) {
        hdmi_tx_set_video_clock_ranges(port, frl_mode, clock_mode, depth_6, 0, depth_7f);
        return;
    }
    hdmi_tx_set_clock_mode_reg5(port, clock_mode);
    hdmi_tx_set_color_depth_reg6(port, depth_6);
    hdmi_tx_set_clock_mode_reg7f(port, 0);
    hdmi_tx_set_color_depth_reg7f(port, depth_7f);
}
