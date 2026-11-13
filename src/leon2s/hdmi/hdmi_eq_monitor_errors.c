/* hdmi_eq_monitor_errors  (FUN_a0079054)
 *
 * Check the channel error counters and restart or confirm the EQ values.
 *   port: PHY
 *   force: 1 = check now
 * Name basis: derived - reads error registers 0x1EA0/0x1EA4 every 100 ticks, prints 'ERROR : %04x' and the
 *   CCT/RCT lines
 *
 * Matching notes
 * --------------
 * leon2s FUN_a0079054 @ 0xa0079054-0xa0079460 (1036 bytes), flags -mcpu=v8 -Os -g (section default).
 * Source forms the exact build depends on:
 *  - every register read is its own call (the three counts re-read 0x1ea0 / 0x1ea4 for each part, the RCT and
 *    CCT of a channel are two reads of the same register);
 *  - the count expressions keep their firmware form (A & 0xffffff00 | ...) & 0x7fff;
 *  - the initialisers of rct[] and cct[] are copied by memcpy (lib_memcpy) from read-only data that
 *    follows the unreferenced string "DRV_HDMI_EQScan_FSM_Search_EQTable" in the firmware (0xa00b3db0,
 *    initialisers at 0xa00b3dd3 and 0xa00b3dd6). That string is declared here with __attribute__((used)) so
 *    the read-only data has the firmware layout (the 3-byte rct initialiser is followed directly by the
 *    2-aligned cct initialiser); it emits no instructions.
 */

/* The EQ scan record of one PHY (12 bytes, hdmi_eq_scan_records). */
struct eq_scan_record {
    unsigned int state;
    unsigned char byte_0x4[3];
    unsigned char check_error_round;
    unsigned char byte_0x8;             /* set by the EQ step when it chose AEQ, clear for MEQ */
    unsigned char pad[3];
};
extern struct eq_scan_record hdmi_eq_scan_records[];
extern unsigned int hdmi_eq_monitor_ticks[];        /* per PHY: tick count of the last check */
extern unsigned char hdmi_eq_monitor_flags[];       /* per PHY: 1 = write the EQ values back at the next clean check */
extern void *memcpy(void *, const void *, unsigned int) __asm__("FUN_a00b15d8");
extern int dbg_printf(const char *, ...);
extern unsigned int timer_get_ticks(void);
extern unsigned int hdmi_phy_read_reg(unsigned int, unsigned short);
extern void hdmi_phy_update_reg(unsigned int, unsigned short, unsigned int, unsigned int);
extern void hdmi_phy_pulse_channel_regs(unsigned char);

static const char fn_[] __attribute__((used)) = "DRV_HDMI_EQScan_FSM_Search_EQTable";

/* Error counts of the three channels, 15 bits each, high byte first: channel 0 = bytes 1 and 2 of register A,
   channel 1 = byte 3 of A and byte 0 of B, channel 2 = bytes 1 and 2 of B (byte n = bits 8n..8n+7). */
#define PHY_REG_ERR_COUNT_A 0x1ea0
#define PHY_REG_ERR_COUNT_B 0x1ea4
#define ERR_COUNT_MASK      0x7fff
#define ERR_COUNT_LIMIT     0x80        /* a count above this is an error */
#define ERR_CTRL_KEEP       0xffffff00  /* bits 0..7 of PHY_REG_ERR_COUNT_A are rewritten: */
#define ERR_CTRL_IDLE       0x87        /*   0x87, 0xc7, 0x87 */
#define ERR_CTRL_PULSE      0xc7

/* Registers of channel ch (0..2). */
#define PHY_CH_REG(ch, reg) (0x1100 + 0x400 * (ch) + (reg))
#define CH_REG_70           0x70
#define CH_REG_70_KEEP      0xff00ffff  /* bits 16..23 are rewritten */
#define CH_REG_70_ERROR     0x2c0000    /* 0x2c after an error */
#define CH_REG_70_OK        0x2f0000    /* 0x2f after the EQ values were written back */
#define CH_REG_EQ           0x78        /* RCT bits 0..3, CCT bits 8..23 */
#define EQ_REG_KEEP         0xff0000f0  /* keep mask of the RCT / CCT write */

#define CHECK_PERIOD_TICKS  100

/*
 * Watch the error counters of an HDMI PHY while it receives, and react to errors.
 *
 *   port   the HDMI PHY
 *   force  1: check now, and mark the PHY so that its EQ values are written back at the first clean check;
 *          0: check only when more than CHECK_PERIOD_TICKS ticks have passed since the last check of this PHY
 *
 * Called with force = 1 when the EQ scan finishes (FSM_EQSCAN_DONE) and with force = 0 by the HDMI link
 * state routine LINK_STANDBY while the link is ready.
 *
 * A check reads the three channel error counts. If any of them is above ERR_COUNT_LIMIT it prints them and
 * writes bits 0..7 of PHY_REG_ERR_COUNT_A to 0x87, 0xc7, 0x87. When the scan record shows AEQ (byte_0x8 == 1)
 * it also marks the PHY again, sets bits 16..23 of channel register 0x70 to 0x2c on all three channels and
 * pulses the channel control registers (hdmi_phy_pulse_channel_regs).
 * With no count above the limit, in AEQ and with the PHY marked, the mark is cleared, each channel's RCT and
 * CCT are read from its EQ register and written back to the same fields, bits 16..23 of register 0x70 are set
 * to 0x2f on all channels, and the values are printed.
 */
void hdmi_eq_monitor_errors(unsigned char port, unsigned char force)
{
    unsigned short err[3] = { 0, 0, 0 };
    unsigned char rct[3] = { 8, 8, 8 };
    unsigned short cct[3] = { 0xfff, 0xfff, 0xfff };

    if (force == 1)
        hdmi_eq_monitor_flags[port] = 1;
    if (timer_get_ticks() - hdmi_eq_monitor_ticks[port] > CHECK_PERIOD_TICKS || force == 1) {
        hdmi_eq_monitor_ticks[port] = timer_get_ticks();
        err[0] = ((hdmi_phy_read_reg(port, PHY_REG_ERR_COUNT_A) & 0xffffff00) | ((hdmi_phy_read_reg(port, PHY_REG_ERR_COUNT_A) & 0xff0000) >> 16)) & ERR_COUNT_MASK;
        err[1] = (((hdmi_phy_read_reg(port, PHY_REG_ERR_COUNT_A) & 0xff000000) >> 16) | (hdmi_phy_read_reg(port, PHY_REG_ERR_COUNT_B) & 0xff)) & ERR_COUNT_MASK;
        err[2] = ((hdmi_phy_read_reg(port, PHY_REG_ERR_COUNT_B) & 0xffffff00) | ((hdmi_phy_read_reg(port, PHY_REG_ERR_COUNT_B) & 0xff0000) >> 16)) & ERR_COUNT_MASK;
        if (err[0] > ERR_COUNT_LIMIT || err[1] > ERR_COUNT_LIMIT || err[2] > ERR_COUNT_LIMIT) {
            dbg_printf("ERROR : %04x, %04x, %04x  \n", err[0], err[1], err[2]);
            hdmi_phy_update_reg(port, PHY_REG_ERR_COUNT_A, ERR_CTRL_KEEP, ERR_CTRL_IDLE);
            hdmi_phy_update_reg(port, PHY_REG_ERR_COUNT_A, ERR_CTRL_KEEP, ERR_CTRL_PULSE);
            hdmi_phy_update_reg(port, PHY_REG_ERR_COUNT_A, ERR_CTRL_KEEP, ERR_CTRL_IDLE);
            if (hdmi_eq_scan_records[port].byte_0x8 == 1) {
                /* AEQ only: the mark makes the first clean check write the EQ values back. */
                hdmi_eq_monitor_flags[port] = 1;
                hdmi_phy_update_reg(port, PHY_CH_REG(0, CH_REG_70), CH_REG_70_KEEP, CH_REG_70_ERROR);
                hdmi_phy_update_reg(port, PHY_CH_REG(1, CH_REG_70), CH_REG_70_KEEP, CH_REG_70_ERROR);
                hdmi_phy_update_reg(port, PHY_CH_REG(2, CH_REG_70), CH_REG_70_KEEP, CH_REG_70_ERROR);
                hdmi_phy_pulse_channel_regs(port);
            }
        } else if (hdmi_eq_scan_records[port].byte_0x8 == 1 && hdmi_eq_monitor_flags[port] == 1) {
            hdmi_eq_monitor_flags[port] = 0;
            /* Read the EQ values of the channels and write them back unchanged. */
            rct[0] = hdmi_phy_read_reg(port, PHY_CH_REG(0, CH_REG_EQ)) & 0xf;
            cct[0] = (hdmi_phy_read_reg(port, PHY_CH_REG(0, CH_REG_EQ)) & 0xffff00) >> 8;
            rct[1] = hdmi_phy_read_reg(port, PHY_CH_REG(1, CH_REG_EQ)) & 0xf;
            cct[1] = (hdmi_phy_read_reg(port, PHY_CH_REG(1, CH_REG_EQ)) & 0xffff00) >> 8;
            rct[2] = hdmi_phy_read_reg(port, PHY_CH_REG(2, CH_REG_EQ)) & 0xf;
            cct[2] = (hdmi_phy_read_reg(port, PHY_CH_REG(2, CH_REG_EQ)) & 0xffff00) >> 8;
            hdmi_phy_update_reg(port, PHY_CH_REG(0, CH_REG_EQ), EQ_REG_KEEP, (rct[0] & 0xf) | (cct[0] << 8));
            hdmi_phy_update_reg(port, PHY_CH_REG(1, CH_REG_EQ), EQ_REG_KEEP, (rct[1] & 0xf) | (cct[1] << 8));
            hdmi_phy_update_reg(port, PHY_CH_REG(2, CH_REG_EQ), EQ_REG_KEEP, (rct[2] & 0xf) | (cct[2] << 8));
            hdmi_phy_update_reg(port, PHY_CH_REG(0, CH_REG_70), CH_REG_70_KEEP, CH_REG_70_OK);
            hdmi_phy_update_reg(port, PHY_CH_REG(1, CH_REG_70), CH_REG_70_KEEP, CH_REG_70_OK);
            hdmi_phy_update_reg(port, PHY_CH_REG(2, CH_REG_70), CH_REG_70_KEEP, CH_REG_70_OK);
            dbg_printf(" Port%d, CH0 CCT [0x%04x] RCT [0x%02x]\n", port, cct[0], rct[0]);
            dbg_printf(" Port%d, CH1 CCT [0x%04x] RCT [0x%02x]\n", port, cct[1], rct[1]);
            dbg_printf(" Port%d, CH2 CCT [0x%04x] RCT [0x%02x]\n\n", port, cct[2], rct[2]);
        }
    }
}
