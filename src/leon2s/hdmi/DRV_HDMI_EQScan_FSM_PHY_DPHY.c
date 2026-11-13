/* DRV_HDMI_EQScan_FSM_PHY_DPHY  (DRV_HDMI_EQScan_FSM_PHY_DPHY)
 *
 * EQ scan step: write four fixed PHY register fields for a clock up to 600 and go to the PICDR state.
 *   port: PHY
 * Returns: 0
 * Note: State function of the EQ scan table run by hdmi_eq_run_scan_fsm. The values are the same for every
 *   clock range; above 600 only a message is printed.
 * Name basis: proven - original name printed: 'DRV_HDMI_EQScan_FSM_PHY_DPHY'
 *
 * Matching notes
 * --------------
 * leon2s DRV_HDMI_EQScan_FSM_PHY_DPHY @ 0xa007cea4-0xa007cfec, flags -mcpu=v8 -Os -g (section default).
 * Source forms the exact build depends on:
 *  - each clock range arm is written in full (crossjumping shares the tails), and the arm for the highest range
 *    reaches the third arm through 'goto' when hdmi_eq_get_clock_ratio_mode returns 0, as in
 *    DRV_HDMI_EQScan_FSM_PHY_PLL;
 *  - the first print is a literal in the call with the routine name from a static const char array;
 */
/* Message groups of dbg_hdmi_message_flags: every print of the EQ scan is in group EQ_FLOW. */
#define HDMI_MSG_EQ_FLOW 0x02

/* States of the EQ scan: the index into hdmi_eq_scan_state_handlers. */
#define EQSCAN_STATE_DPHY   2           /* this step */
#define EQSCAN_STATE_PICDR  3

/* Upper limits of the four clock ranges of phy_clock_mhz (below 100, 160, 300; up to 600 inclusive). */
#define EQ_CLOCK_LIMIT_100  100
#define EQ_CLOCK_LIMIT_160  160
#define EQ_CLOCK_LIMIT_300  300
#define EQ_CLOCK_LIMIT_600  600

#define PHY_REG_1E90        0x1e90      /* bit 7 set, then bit 2 cleared */
#define PHY_REG_1F08        0x1f08      /* bits 0..2 = 4 */
#define PHY_REG_119C        0x119c      /* bits 16..23 = 0 */

/* The fields of the PHY record (0x18 bytes per PHY, table at 0xA807CC64) used here. */
struct hdmi_phy_record {
    unsigned char pad_0x0[8];
    unsigned short phy_clock_mhz;       /* +8 */
    unsigned char pad_0xa[0x18 - 0xa];
};
/* The scan state of one port (12 bytes per port). */
struct eq_scan_record {
    unsigned int state;                 /* EQSCAN_STATE_*: the step hdmi_eq_run_scan_fsm runs next */
    unsigned int word_0x4;
    unsigned char byte_0x8;
    unsigned char pad[3];
};
extern struct hdmi_phy_record hdmi_phy_records[];
extern struct eq_scan_record hdmi_eq_scan_records[];
extern unsigned int dbg_hdmi_message_flags;
extern int dbg_printf(const char *, ...);
extern unsigned int dbg_print_string(const char *);
extern unsigned char hdmi_eq_get_clock_ratio_mode(unsigned char);
extern void hdmi_phy_write_bit(int, unsigned int, unsigned char, unsigned short);
extern void hdmi_phy_update_reg(unsigned int, unsigned short, unsigned int, unsigned int);
static const char fn_[] = "DRV_HDMI_EQScan_FSM_PHY_DPHY";

/*
 * EQ scan state EQSCAN_STATE_DPHY (step of the table run by hdmi_eq_run_scan_fsm): write the PHY registers
 * that depend on the measured clock, then go to EQSCAN_STATE_PICDR.
 *
 *   port  PHY
 *
 * Returns 0, so hdmi_eq_run_scan_fsm stops after this step and runs the next state on its next call.
 *
 * Bit 7 of PHY register 0x1E90 is set and bits 0..2 of 0x1F08 are set to 4. For a clock (phy_clock_mhz) up to
 * 600 bit 2 of 0x1E90 is cleared and bits 16..23 of 0x119C are set to 0: all four ranges do the same, and the
 * range 300..600 does it whether or not hdmi_eq_get_clock_ratio_mode is set. Above 600 only the
 * message "HDMI Mode : out clk range!!!" is printed (debug flag bit 1). The state is EQSCAN_STATE_PICDR in
 * every case.
 */
int DRV_HDMI_EQScan_FSM_PHY_DPHY(unsigned char port)
{
    unsigned short phy_clock_mhz = hdmi_phy_records[port].phy_clock_mhz;

    if (dbg_hdmi_message_flags & HDMI_MSG_EQ_FLOW)
        dbg_printf("[EQ]: \033[1mPort%c %s: \n\n\033[m", (char)(port + 'A'), fn_);
    hdmi_phy_write_bit(1, 7, port, PHY_REG_1E90);
    hdmi_phy_update_reg(port, PHY_REG_1F08, -8, 4);
    if (phy_clock_mhz < EQ_CLOCK_LIMIT_100) {
        hdmi_phy_write_bit(0, 2, port, PHY_REG_1E90);
        hdmi_phy_update_reg(port, PHY_REG_119C, 0xff00ffff, 0);
    } else if (phy_clock_mhz < EQ_CLOCK_LIMIT_160) {
        hdmi_phy_write_bit(0, 2, port, PHY_REG_1E90);
        hdmi_phy_update_reg(port, PHY_REG_119C, 0xff00ffff, 0);
    } else if (phy_clock_mhz < EQ_CLOCK_LIMIT_300) {
l300:
        hdmi_phy_write_bit(0, 2, port, PHY_REG_1E90);
        hdmi_phy_update_reg(port, PHY_REG_119C, 0xff00ffff, 0);
    } else if (phy_clock_mhz <= EQ_CLOCK_LIMIT_600) {
        if (!hdmi_eq_get_clock_ratio_mode(port))
            goto l300;
        hdmi_phy_write_bit(0, 2, port, PHY_REG_1E90);
        hdmi_phy_update_reg(port, PHY_REG_119C, 0xff00ffff, 0);
    } else {
        if (dbg_hdmi_message_flags & HDMI_MSG_EQ_FLOW)
            dbg_print_string("[EQ]: HDMI Mode : out clk range!!!");
    }
    hdmi_eq_scan_records[port].state = EQSCAN_STATE_PICDR;
    return 0;
}
