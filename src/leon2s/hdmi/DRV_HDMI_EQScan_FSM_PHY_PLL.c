/* DRV_HDMI_EQScan_FSM_PHY_PLL  (DRV_HDMI_EQScan_FSM_PHY_PLL)
 *
 * EQ scan step: write the PLL registers for the measured clock range and go to the DPHY state.
 *   port: PHY
 * Returns: 1; 0 when it restarts the scan at PHY_INIT
 * Note: State function of the EQ scan table run by hdmi_eq_run_scan_fsm. Above 600 nothing clock-dependent is
 *   written; with clock-ratio and scramble mode both set, the fifth such pass restarts the scan.
 * Name basis: proven - original name printed: 'DRV_HDMI_EQScan_FSM_PHY_PLL'
 *
 * Matching notes
 * --------------
 * leon2s DRV_HDMI_EQScan_FSM_PHY_PLL @ 0xa007e7c0-0xa007ebd0, flags -mcpu=v8 -Os -g (section default).
 * Source forms the exact build depends on:
 *  - each clock range arm is written in full (crossjumping shares the tails), and the arm for the highest range
 *    reaches the third arm through 'goto' when hdmi_eq_get_clock_ratio_mode returns 0;
 *  - dbg_hdmi_message_flags is declared unsigned long (the alias set orders its reload after the record
 *    address set-up in the retry-limit path);
 *  - hdmi_is_hdmi21_phy is called once at the top (result r) and again in the third arm;
 *  - the first print is a string object DAT_a0067058 with the routine name from a static const char array.
 */
/* Message groups of dbg_hdmi_message_flags: every print of the EQ scan is in group EQ_FLOW. */
#define HDMI_MSG_EQ_FLOW 0x02

/* States of the EQ scan: the index into hdmi_eq_scan_state_handlers. */
#define EQSCAN_STATE_PHY_INIT 0         /* "FSM_EQSCAN_PHY_INIT" */
#define EQSCAN_STATE_PLL      1         /* this step */
#define EQSCAN_STATE_DPHY     2

/* Upper limits of the four clock ranges of phy_clock_mhz (below 100, 160, 300; up to 600 inclusive). */
#define EQ_CLOCK_LIMIT_100  100
#define EQ_CLOCK_LIMIT_160  160
#define EQ_CLOCK_LIMIT_300  300
#define EQ_CLOCK_LIMIT_600  600

#define RETRY_LIMIT         3           /* the fifth pass out of range restarts the scan */

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
/* The EQ scan work record of one port (0x898 bytes); only the counter at +0x896 is used here. */
struct eq_scan_channels { unsigned char pad_0x0[0x896]; unsigned char byte_0x896; unsigned char pad_0x897; };
extern struct hdmi_phy_record hdmi_phy_records[];
extern struct eq_scan_record hdmi_eq_scan_records[];
extern struct eq_scan_channels hdmi_eq_port_records[];
extern unsigned long dbg_hdmi_message_flags;
extern unsigned char DAT_a0067058[];            /* "[EQ]: Port%c %s:" (bold) */
extern int dbg_printf(const void *, ...);
extern int dbg_print_string(const char *);
extern unsigned char hdmi_is_hdmi21_phy(unsigned char);
extern unsigned char hdmi_eq_get_clock_ratio_mode(unsigned char);
extern unsigned char hdmi_eq_get_scramble_mode(unsigned char);
extern void hdmi_phy_write_bit(int, unsigned int, unsigned char, unsigned short);
extern void hdmi_phy_update_reg(unsigned int, unsigned short, unsigned int, unsigned int);

static const char fn_[] = "DRV_HDMI_EQScan_FSM_PHY_PLL";

/*
 * EQ scan state EQSCAN_STATE_PLL (step of the table run by hdmi_eq_run_scan_fsm): write the PHY registers that
 * depend on the measured clock, then go to EQSCAN_STATE_DPHY.
 *
 *   port  PHY
 *
 * Returns 1, so hdmi_eq_run_scan_fsm runs the next state at once; 0 when the scan is sent back to
 * EQSCAN_STATE_PHY_INIT (see the last step).
 *
 * 1. Fixed part: bit 21 of PHY register 0x1C04 and bits 22, 23 of 0x1C00 are cleared on PHY 0 (a literal 0 as
 *    PHY). On an HDMI 2.1 PHY (r) bits 0, 1 and 8 of 0x3600 are cleared. Then bits 24..31 of 0x1028 = 0x30,
 *    bits 16..23 of 0x1034 = 0xF0, of 0x1014 = 0x8C, bit 18 of 0x1C04 is set and bits 16..23 of 0x1014 = 0x8D.
 * 2. By the measured clock (phy_clock_mhz of the PHY record):
 *    - below EQ_CLOCK_LIMIT_100 / below EQ_CLOCK_LIMIT_160: bits 24..31 of 0x1008 = 0x2B / 0x1B, bit 8 of
 *      0x100C set, bits 9..10 of 0x100C = 3, and on an HDMI 2.1 PHY bits 16..23 of 0x3608 = 5;
 *    - below EQ_CLOCK_LIMIT_300, and up to EQ_CLOCK_LIMIT_600 when hdmi_eq_get_clock_ratio_mode is 0: 0x1008 =
 *      0x1B, bit 8 of 0x100C set, bits 9..10 of 0x100C = 2, on an HDMI 2.1 PHY 0x3608 = 5;
 *    - up to EQ_CLOCK_LIMIT_600 with hdmi_eq_get_clock_ratio_mode set: bits 16..23 of 0x1014 = 0xFD, bits
 *      24..31 of 0x1008 = 0x3B, bit 8 of 0x100C set; on an HDMI 2.1 PHY bits 9..10 of 0x100C = 1, bits 16..23
 *      of 0x3608 = 0xC and bit 8 of 0x3600 set, on any other PHY bits 9..10 of 0x100C = 0;
 *    - above EQ_CLOCK_LIMIT_600: print "out clk range!!!" (debug flag bit 1), write nothing more.
 * 3. Above EQ_CLOCK_LIMIT_600 with both hdmi_eq_get_clock_ratio_mode and hdmi_eq_get_scramble_mode set, the
 *    counter byte_0x896 of the port's work record is incremented. When it was already above RETRY_LIMIT, the
 *    state is set to EQSCAN_STATE_PHY_INIT, the counter cleared and the step returns 0 (messages "clear
 *    scramble bit and ratio bit" and "go to FSM_EQSCAN_PHY_INIT 5", debug flag bit 1).
 * 4. Otherwise (also for a clock above EQ_CLOCK_LIMIT_600) the state is set to EQSCAN_STATE_DPHY.
 */
int DRV_HDMI_EQScan_FSM_PHY_PLL(unsigned char port)
{
    unsigned short phy_clock_mhz = hdmi_phy_records[port].phy_clock_mhz;
    unsigned char r;                    /* 1 for an HDMI 2.1 PHY */
    unsigned char n;

    if ((dbg_hdmi_message_flags & HDMI_MSG_EQ_FLOW) != 0)
        dbg_printf(DAT_a0067058, (char)(port + 'A'), fn_);
    hdmi_phy_write_bit(0, 0x15, 0, 0x1c04);
    hdmi_phy_write_bit(0, 0x16, 0, 0x1c00);
    hdmi_phy_write_bit(0, 0x17, 0, 0x1c00);
    r = hdmi_is_hdmi21_phy(port);
    if (r) {
        hdmi_phy_write_bit(0, 0, port, 0x3600);
        hdmi_phy_write_bit(0, 1, port, 0x3600);
        hdmi_phy_write_bit(0, 8, port, 0x3600);
    }
    hdmi_phy_update_reg(port, 0x1028, 0xffffff, 0x30000000);
    hdmi_phy_update_reg(port, 0x1034, 0xff00ffff, 0xf00000);
    hdmi_phy_update_reg(port, 0x1014, 0xff00ffff, 0x8c0000);
    hdmi_phy_write_bit(1, 0x12, port, 0x1c04);
    hdmi_phy_update_reg(port, 0x1014, 0xff00ffff, 0x8d0000);
    if (phy_clock_mhz < EQ_CLOCK_LIMIT_100) {
        hdmi_phy_update_reg(port, 0x1008, 0xffffff, 0x2b000000);
        hdmi_phy_write_bit(1, 8, port, 0x100c);
        hdmi_phy_update_reg(port, 0x100c, 0xfffff9ff, 0x600);
        if (r)
            hdmi_phy_update_reg(port, 0x3608, 0xff00ffff, 0x50000);
    } else if (phy_clock_mhz < EQ_CLOCK_LIMIT_160) {
        hdmi_phy_update_reg(port, 0x1008, 0xffffff, 0x1b000000);
        hdmi_phy_write_bit(1, 8, port, 0x100c);
        hdmi_phy_update_reg(port, 0x100c, 0xfffff9ff, 0x600);
        if (r)
            hdmi_phy_update_reg(port, 0x3608, 0xff00ffff, 0x50000);
    } else if (phy_clock_mhz < EQ_CLOCK_LIMIT_300) {
l300:
        hdmi_phy_update_reg(port, 0x1008, 0xffffff, 0x1b000000);
        hdmi_phy_write_bit(1, 8, port, 0x100c);
        hdmi_phy_update_reg(port, 0x100c, 0xfffff9ff, 0x400);
        if (hdmi_is_hdmi21_phy(port))
            hdmi_phy_update_reg(port, 0x3608, 0xff00ffff, 0x50000);
    } else if (phy_clock_mhz <= EQ_CLOCK_LIMIT_600) {
        if (!hdmi_eq_get_clock_ratio_mode(port))
            goto l300;
        hdmi_phy_update_reg(port, 0x1014, 0xff00ffff, 0xfd0000);
        hdmi_phy_update_reg(port, 0x1008, 0xffffff, 0x3b000000);
        hdmi_phy_write_bit(1, 8, port, 0x100c);
        if (r) {
            hdmi_phy_update_reg(port, 0x100c, 0xfffff9ff, 0x200);
            hdmi_phy_update_reg(port, 0x3608, 0xff00ffff, 0xc0000);
            hdmi_phy_write_bit(1, 8, port, 0x3600);
        } else {
            hdmi_phy_update_reg(port, 0x100c, 0xfffff9ff, 0);
        }
    } else {
        if ((dbg_hdmi_message_flags & HDMI_MSG_EQ_FLOW) != 0)
            dbg_printf("[EQ]: HDMI Mode : Phy EQ Clk = %d, out clk range!!!\n", phy_clock_mhz);
        if (hdmi_eq_get_clock_ratio_mode(port) && hdmi_eq_get_scramble_mode(port)) {
            n = hdmi_eq_port_records[port].byte_0x896;
            hdmi_eq_port_records[port].byte_0x896 = n + 1;
            if (n > RETRY_LIMIT) {
                if ((dbg_hdmi_message_flags & HDMI_MSG_EQ_FLOW) != 0)
                    dbg_print_string("[EQ]: \nclear scramble bit and ratio bit");
                hdmi_eq_scan_records[port].state = EQSCAN_STATE_PHY_INIT;
                hdmi_eq_port_records[port].byte_0x896 = 0;
                if ((dbg_hdmi_message_flags & HDMI_MSG_EQ_FLOW) != 0)
                    dbg_printf("[EQ]: go to FSM_EQSCAN_PHY_INIT %d\r\n", 5);
                return 0;
            }
        }
    }
    hdmi_eq_scan_records[port].state = EQSCAN_STATE_DPHY;
    return 1;
}
