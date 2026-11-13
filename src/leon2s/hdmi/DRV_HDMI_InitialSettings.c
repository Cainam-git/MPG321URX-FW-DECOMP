/* DRV_HDMI_InitialSettings  (DRV_HDMI_InitialSettings)
 *
 * Apply the initial PHY settings and trim/calibration values of the four HDMI ports.
 * Name basis: proven - original name printed: '[INIT]: DRV_HDMI_InitialSettings finish'; 'EFUSE Load H20/H21
 *   Trim', 'Z50 Calibration'
 *
 * Matching notes
 * --------------
 * leon2s DRV_HDMI_InitialSettings @ 0xa0073c44-0xa0074bf8 (4020 bytes), flags -mcpu=v8 -Os -g (section default).
 * Source forms the exact build depends on:
 *  - the port counter is an unsigned char (the firmware re-extends it at several joins);
 *  - the trim record of port 3 is chosen in an if/else chain followed by 'port < 2' (jump threading gives the
 *    firmware's compare chain);
 *  - the six byte arrays are declared with '= {0}' inside the branch of ports 2 and 3, and trim byte 3 is read
 *    before trim byte 0x10 there.
 */

/* Message groups of dbg_hdmi_message_flags: the start-up prints are in group INIT_INFO. */
#define HDMI_MSG_INIT_INFO 0x01

#define REG_CF011514 (*(volatile unsigned int *)0xcf011514)    /* bits 0..1 set here */

/* Bytes of a port's trim record (hdmi_phy_trim_port<n>). Ports 0 and 1 use bytes 0..0xf, ports 2 and 3
   bytes 0..0x23. */
#define TRIM_MARKER          0x00   /* TRIM_LOADED: values present, printed "EFUSE Load", else "Manual Load" */
#define TRIM_1C08            0x03   /* low byte of PHY register 0x1c08 (and 0x2c08) */
#define TRIM_H20_CHANNEL0    0x0d   /* bits 16..23 of 0x103c / 0x143c / 0x183c on ports 0 and 1 */
#define TRIM_H20_CHANNEL1    0x0e
#define TRIM_H20_CHANNEL2    0x0f
#define TRIM_H21_FIRST       0x10   /* ports 2 and 3: bytes 0x10..0x23, see the arrays below */
#define TRIM_LOADED          0xa0

/* Values used when the trim record is not loaded ("Manual Load"). */
#define TRIM_1C08_DEFAULT    9
#define TRIM_FIELD_DEFAULT   0x10

/* PHY register 0x1100: written before and read after the Z50 calibration. */
#define PHY_REG_Z50          0x1100
#define Z50_FAIL_BIT         0x18   /* bit 24: 0 = "Z50 Calibration OK" */
#define Z50_RESULT_SHIFT     28     /* bits 28..30: the calibration value */
/* PHY register 0x1c04 (0x2c04 on HDMI 2.1 PHYs): bits 4..6 take the Z50 value. */
#define Z50_FIELD_MASK       0xffffff8f
#define Z50_FIELD_FAILED     0x40   /* value 4 in bits 4..6 when the calibration fails */

/* The EQ scan state of one port (12 bytes per port), cleared here. */
struct eq_scan_record {
    unsigned int state;
    unsigned int word_0x4;
    unsigned char byte_0x8;
    unsigned char pad[3];
};
/* HDMI PHY record (24 bytes per PHY), cleared here. */
struct hdmi_phy_record { unsigned char bytes[0x18]; };
extern struct eq_scan_record hdmi_eq_scan_records[];
extern struct hdmi_phy_record hdmi_phy_records[];
extern unsigned char hdmi_eq_port_records[][0x898];         /* EQ scan work record of each port */
extern unsigned int dbg_hdmi_message_flags;
extern unsigned char hdmi_eq_retry_enable;
extern unsigned char hdmi_phy_trim_port0[], hdmi_phy_trim_port1[], hdmi_phy_trim_port2[], hdmi_phy_trim_port3[];
extern char DAT_a0066838[];
extern int dbg_printf(const void *, ...);
extern int dbg_print_string(const char *);
extern unsigned char hdmi_is_hdmi21_phy(unsigned char);
extern void hdmi_phy_run_ctrl_sequence(unsigned char);
extern void hdmi_phy_set_power_flag(unsigned int, unsigned char);
extern unsigned int hdmi_phy_read_reg(unsigned int, unsigned short);
extern void hdmi_phy_write_bit(int, unsigned int, unsigned char, unsigned short);
extern unsigned int hdmi_phy_test_bit(unsigned int, unsigned char, unsigned short);
extern void hdmi_phy_update_reg(unsigned int, unsigned short, unsigned int, unsigned int);
extern void timer_delay_long_units(unsigned short);
extern void *lib_memset(void *, int, unsigned int);

/*
 * Set up the four HDMI receiver PHYs at start-up. Called once by DRV_HDMIRx_Phy_Init.
 *
 * hdmi_phy_write_bit takes (value, bit, phy, register), hdmi_phy_update_reg (phy, register, mask of the bits
 * kept, new bits). Registers 0x1xxx are the PHY's first register set; PHYs 2 and 3 (hdmi_is_hdmi21_phy) also
 * have a second set at 0x2xxx, and the registers of their four lanes sit at 0x2000 / 0x2400 / 0x2800 / 0x3000
 * (as in the hdmi_rx21_lane_regs_* lists).
 *
 * Phases:
 *  1. Print the EQ version (V2.2 when hdmi_eq_retry_enable is set, else V1.0) and make the settings common
 *     to all PHYs.
 *  2. Per port 0..3:
 *     a. trim values: from the port's trim record when its marker byte is 0xA0 ("EFUSE Load"), else
 *        defaults ("Manual Load"); ports 0 and 1 take three channel values ("H20 Trim"), ports 2 and 3
 *        three channel and five sets of four lane values ("H21 Trim");
 *     b. Z50 calibration: bits 24..31 of register 0x1100 are set to 2, then 3; after a wait, bit 24 clear
 *        means "Z50 Calibration OK" and bits 28..30 go to bits 4..6 of 0x1c04, else those bits get 4;
 *     c. further fixed settings; part of them are written to PHY 0 on every pass, whatever the port;
 *     d. the port's EQ scan records and PHY link table entry are cleared;
 *     e. PHYs 2 and 3: the "H21 LC_PLL OFF" settings;
 *     f. hdmi_phy_set_power_flag(port, 1) records power state 1 in the PHY link table entry.
 *  3. Print "DRV_HDMI_InitialSettings finish".
 */
void DRV_HDMI_InitialSettings(void)
{
    unsigned char port;
    unsigned char is_hdmi21;
    unsigned char *trim;
    unsigned char trim_1c08;
    unsigned char z50;

    /* Phase 1: version print and settings common to all PHYs. */
    if ((dbg_hdmi_message_flags & HDMI_MSG_INIT_INFO) != 0)
        dbg_printf(DAT_a0066838, "DRV_HDMI_InitialSettings");
    if (hdmi_eq_retry_enable != 0) {
        if ((dbg_hdmi_message_flags & HDMI_MSG_INIT_INFO) != 0)
            dbg_print_string("[INIT]: EQ V2.2 \n");
    } else {
        if ((dbg_hdmi_message_flags & HDMI_MSG_INIT_INFO) != 0)
            dbg_print_string("[INIT]: EQ V1.0 \n");
    }
    REG_CF011514 |= 3;
    hdmi_phy_write_bit(1, 0, 2, 0x3534);
    hdmi_phy_write_bit(1, 0, 3, 0x3534);
    for (port = 0; port < 4; port++) {
        hdmi_phy_update_reg(port, 0x1000, 0xffffff00, 0xf9);
        hdmi_phy_update_reg(port, 0x1f04, 0xffffff00, 0x5f);
    }

    /* Phase 2: each port in turn. */
    for (port = 0; port < 4; port++) {
        is_hdmi21 = hdmi_is_hdmi21_phy(port);
        if (is_hdmi21) {
            hdmi_phy_write_bit(1, 0x10, port, 0x361c);
            hdmi_phy_write_bit(1, 0x11, port, 0x361c);
            hdmi_phy_write_bit(1, 0x12, port, 0x361c);
            hdmi_phy_update_reg(port, 0x361c, 0xff8fffff, 0x600000);
        }
        hdmi_phy_update_reg(0, 0x1104, 0xfcffffff, 0x3000000);     /* PHY 0 on every pass */

        /* 2a: trim values. */
        if (port == 0)
            trim = hdmi_phy_trim_port0;
        else if (port == 1)
            trim = hdmi_phy_trim_port1;
        else if (port == 2)
            trim = hdmi_phy_trim_port2;
        else
            trim = hdmi_phy_trim_port3;
        if (port < 2) {
            /* Ports 0 and 1: one value per channel. */
            if (trim[TRIM_MARKER] == TRIM_LOADED) {
                if ((dbg_hdmi_message_flags & HDMI_MSG_INIT_INFO) != 0)
                    dbg_printf("[INIT]: Port%c EFUSE Load H20 Trim !!! \r\n", (char)(port + 'A'));
                trim_1c08 = trim[TRIM_1C08];
                hdmi_phy_update_reg(port, 0x1c08, 0xffffff, 0x60000000);
                hdmi_phy_update_reg(port, 0x1c08, 0xffffff00, trim_1c08);
                hdmi_phy_update_reg(port, 0x103c, 0xffff, trim[TRIM_H20_CHANNEL0] << 16 | 0x1f000000);
                hdmi_phy_update_reg(port, 0x143c, 0xffff, trim[TRIM_H20_CHANNEL1] << 16 | 0x1f000000);
                hdmi_phy_update_reg(port, 0x183c, 0xffff, trim[TRIM_H20_CHANNEL2] << 16 | 0x1f000000);
            } else {
                if ((dbg_hdmi_message_flags & HDMI_MSG_INIT_INFO) != 0)
                    dbg_printf("[INIT]: Port%c Manual Load H20 Trim !!! \r\n", (char)(port + 'A'));
                hdmi_phy_update_reg(port, 0x1c08, 0xffffff, 0x60000000);
                hdmi_phy_update_reg(port, 0x1c08, 0xffffff00, TRIM_1C08_DEFAULT);
                hdmi_phy_update_reg(port, 0x103c, 0xffff, 0x1f100000);
                hdmi_phy_update_reg(port, 0x143c, 0xffff, 0x1f100000);
                hdmi_phy_update_reg(port, 0x183c, 0xffff, 0x1f100000);
            }
        } else {
            /* Ports 2 and 3: trim bytes 0x10..0x12 go to the three channels, bytes 0x10..0x23 in groups of
               four to the four lanes (the first group repeats the channel bytes). */
            unsigned char channel_trim[3] = {0};    /* bytes 0x10..0x12: bits 16..23 of 0x103c / 0x143c / 0x183c */
            unsigned char lane_trim_3c[4] = {0};    /* bytes 0x10..0x13: bits 16..23 of lane register 0x3c */
            unsigned char lane_trim_54[4] = {0};    /* bytes 0x14..0x17: bits 11..15 of lane register 0x54 */
            unsigned char lane_trim_68_low[4] = {0};    /* bytes 0x18..0x1b: bits 3..7 of lane register 0x68 */
            unsigned char lane_trim_68_high[4] = {0};   /* bytes 0x1c..0x1f: bits 11..15 of lane register 0x68 */
            unsigned char lane_trim_70[4] = {0};    /* bytes 0x20..0x23: bits 11..15 of lane register 0x70 */

            if (trim[TRIM_MARKER] == TRIM_LOADED) {
                if ((dbg_hdmi_message_flags & HDMI_MSG_INIT_INFO) != 0)
                    dbg_printf("[INIT]: Port%c EFUSE Load H21 Trim !!! \r\n", (char)(port + 'A'));
                trim_1c08 = trim[TRIM_1C08];
                channel_trim[0] = trim[0x10];
                channel_trim[1] = trim[0x11];
                channel_trim[2] = trim[0x12];
                lane_trim_3c[0] = trim[0x10];
                lane_trim_3c[1] = trim[0x11];
                lane_trim_3c[2] = trim[0x12];
                lane_trim_3c[3] = trim[0x13];
                lane_trim_54[0] = trim[0x14];
                lane_trim_54[1] = trim[0x15];
                lane_trim_54[2] = trim[0x16];
                lane_trim_54[3] = trim[0x17];
                lane_trim_68_low[0] = trim[0x18];
                lane_trim_68_low[1] = trim[0x19];
                lane_trim_68_low[2] = trim[0x1a];
                lane_trim_68_low[3] = trim[0x1b];
                lane_trim_68_high[0] = trim[0x1c];
                lane_trim_68_high[1] = trim[0x1d];
                lane_trim_68_high[2] = trim[0x1e];
                lane_trim_68_high[3] = trim[0x1f];
                lane_trim_70[0] = trim[0x20];
                lane_trim_70[1] = trim[0x21];
                lane_trim_70[2] = trim[0x22];
                lane_trim_70[3] = trim[0x23];
            } else {
                if ((dbg_hdmi_message_flags & HDMI_MSG_INIT_INFO) != 0)
                    dbg_printf("[INIT]: Port%c Manual Load H21 Trim !!! \r\n", (char)(port + 'A'));
                channel_trim[0] = TRIM_FIELD_DEFAULT;
                channel_trim[1] = TRIM_FIELD_DEFAULT;
                channel_trim[2] = TRIM_FIELD_DEFAULT;
                lane_trim_3c[0] = TRIM_FIELD_DEFAULT;
                lane_trim_3c[1] = TRIM_FIELD_DEFAULT;
                lane_trim_3c[2] = TRIM_FIELD_DEFAULT;
                lane_trim_3c[3] = TRIM_FIELD_DEFAULT;
                lane_trim_54[0] = TRIM_FIELD_DEFAULT;
                lane_trim_54[1] = TRIM_FIELD_DEFAULT;
                lane_trim_54[2] = TRIM_FIELD_DEFAULT;
                lane_trim_54[3] = TRIM_FIELD_DEFAULT;
                lane_trim_68_low[0] = TRIM_FIELD_DEFAULT;
                lane_trim_68_low[1] = TRIM_FIELD_DEFAULT;
                lane_trim_68_low[2] = TRIM_FIELD_DEFAULT;
                lane_trim_68_low[3] = TRIM_FIELD_DEFAULT;
                lane_trim_68_high[0] = TRIM_FIELD_DEFAULT;
                lane_trim_68_high[1] = TRIM_FIELD_DEFAULT;
                lane_trim_68_high[2] = TRIM_FIELD_DEFAULT;
                lane_trim_68_high[3] = TRIM_FIELD_DEFAULT;
                lane_trim_70[0] = TRIM_FIELD_DEFAULT;
                lane_trim_70[1] = TRIM_FIELD_DEFAULT;
                lane_trim_70[2] = TRIM_FIELD_DEFAULT;
                lane_trim_70[3] = TRIM_FIELD_DEFAULT;
                trim_1c08 = TRIM_1C08_DEFAULT;
            }
            hdmi_phy_update_reg(port, 0x1c08, 0xffffff, 0x60000000);
            hdmi_phy_update_reg(port, 0x2c08, 0xffffff, 0x60000000);
            hdmi_phy_update_reg(port, 0x1c08, 0xffffff00, trim_1c08);
            hdmi_phy_update_reg(port, 0x2c08, 0xffffff00, trim_1c08);
            hdmi_phy_update_reg(port, 0x103c, 0xffff, channel_trim[0] << 16 | 0x1f000000);
            hdmi_phy_update_reg(port, 0x143c, 0xffff, channel_trim[1] << 16 | 0x1f000000);
            hdmi_phy_update_reg(port, 0x183c, 0xffff, channel_trim[2] << 16 | 0x1f000000);
            hdmi_phy_update_reg(port, 0x203c, 0xffff, lane_trim_3c[0] << 16 | 0x1f000000);
            hdmi_phy_update_reg(port, 0x243c, 0xffff, lane_trim_3c[1] << 16 | 0x1f000000);
            hdmi_phy_update_reg(port, 0x283c, 0xffff, lane_trim_3c[2] << 16 | 0x1f000000);
            hdmi_phy_update_reg(port, 0x303c, 0xffff, lane_trim_3c[3] << 16 | 0x1f000000);
            hdmi_phy_update_reg(port, 0x2034, 0xffffffff, 0xf0000000);
            hdmi_phy_update_reg(port, 0x2434, 0xffffffff, 0xf0000000);
            hdmi_phy_update_reg(port, 0x2834, 0xffffffff, 0xf0000000);
            hdmi_phy_update_reg(port, 0x3034, 0xffffffff, 0xf0000000);
            hdmi_phy_update_reg(port, 0x2054, 0xffff07ff, (lane_trim_54[0] & 0x1f) << 11);
            hdmi_phy_update_reg(port, 0x2454, 0xffff07ff, (lane_trim_54[1] & 0x1f) << 11);
            hdmi_phy_update_reg(port, 0x2854, 0xffff07ff, (lane_trim_54[2] & 0x1f) << 11);
            hdmi_phy_update_reg(port, 0x3054, 0xffff07ff, (lane_trim_54[3] & 0x1f) << 11);
            hdmi_phy_update_reg(port, 0x2068, 0xffffff07, (lane_trim_68_low[0] & 0x1f) << 3);
            hdmi_phy_update_reg(port, 0x2468, 0xffffff07, (lane_trim_68_low[1] & 0x1f) << 3);
            hdmi_phy_update_reg(port, 0x2868, 0xffffff07, (lane_trim_68_low[2] & 0x1f) << 3);
            hdmi_phy_update_reg(port, 0x3068, 0xffffff07, (lane_trim_68_low[3] & 0x1f) << 3);
            hdmi_phy_update_reg(port, 0x2068, 0xffff07ff, (lane_trim_68_high[0] & 0x1f) << 11);
            hdmi_phy_update_reg(port, 0x2468, 0xffff07ff, (lane_trim_68_high[1] & 0x1f) << 11);
            hdmi_phy_update_reg(port, 0x2868, 0xffff07ff, (lane_trim_68_high[2] & 0x1f) << 11);
            hdmi_phy_update_reg(port, 0x3068, 0xffff07ff, (lane_trim_68_high[3] & 0x1f) << 11);
            hdmi_phy_update_reg(port, 0x2070, 0xffff07ff, (lane_trim_70[0] & 0x1f) << 11);
            hdmi_phy_update_reg(port, 0x2470, 0xffff07ff, (lane_trim_70[1] & 0x1f) << 11);
            hdmi_phy_update_reg(port, 0x2870, 0xffff07ff, (lane_trim_70[2] & 0x1f) << 11);
            hdmi_phy_update_reg(port, 0x3070, 0xffff07ff, (lane_trim_70[3] & 0x1f) << 11);
        }
        hdmi_phy_write_bit(1, 0x11, port, 0x1c04);
        if (is_hdmi21) {
            hdmi_phy_write_bit(1, 0x11, port, 0x2c04);
            hdmi_phy_run_ctrl_sequence(port);
            hdmi_phy_update_reg(port, 0x361c, 0xffffff00, 0xb0);
            hdmi_phy_update_reg(port, 0x361c, 0xffffff00, 0xb3);
            timer_delay_long_units(1);
            hdmi_phy_update_reg(port, 0x361c, 0xffffff00, 0x33);
            hdmi_phy_update_reg(port, 0x361c, 0xffff00ff, 0x3300);
            hdmi_phy_update_reg(port, 0x361c, 0xff00ffff, 0x670000);
            hdmi_phy_update_reg(port, 0x3618, 0xffffff, 0x13000000);
        }
        hdmi_phy_update_reg(port, 0x1028, 0xfffffcff, 0x300);
        hdmi_phy_update_reg(port, 0x1008, 0xffff00ff, 0xf00);
        /* Bit 7 of 0x1c04 / 0x2c04 is the input enable (as in hdmi_phy_set_input_enable). */
        hdmi_phy_write_bit(1, 7, port, 0x1c04);
        hdmi_phy_write_bit(1, 7, port, 0x2c04);

        /* 2b: Z50 calibration. */
        hdmi_phy_update_reg(port, PHY_REG_Z50, 0xffffff, 0x2000000);
        hdmi_phy_update_reg(port, PHY_REG_Z50, 0xffffff, 0x3000000);
        timer_delay_long_units(1);
        if (hdmi_phy_test_bit(Z50_FAIL_BIT, port, PHY_REG_Z50) == 0) {
            z50 = (hdmi_phy_read_reg(port, PHY_REG_Z50) >> Z50_RESULT_SHIFT) & 7;
            if ((dbg_hdmi_message_flags & HDMI_MSG_INIT_INFO) != 0)
                dbg_printf("[INIT]: Port%c Z50 Calibration OK [%d] !!!\n", (char)(port + 'A'), z50 & 7);
            hdmi_phy_update_reg(port, 0x1c04, Z50_FIELD_MASK, (z50 & 7) << 4);
            if (is_hdmi21)
                hdmi_phy_update_reg(port, 0x2c04, Z50_FIELD_MASK, (z50 & 7) << 4);
        } else {
            if ((dbg_hdmi_message_flags & HDMI_MSG_INIT_INFO) != 0)
                dbg_printf("[INIT]: Port%c Z50 Calibration Fail !!!n", (char)(port + 'A'));
            hdmi_phy_update_reg(port, 0x1c04, Z50_FIELD_MASK, Z50_FIELD_FAILED);
            if (is_hdmi21)
                hdmi_phy_update_reg(port, 0x2c04, Z50_FIELD_MASK, Z50_FIELD_FAILED);
        }

        /* 2c: further fixed settings. */
        if (!is_hdmi21) {
            hdmi_phy_write_bit(1, 8, port, 0x1014);
            hdmi_phy_write_bit(1, 8, port, 0x1034);
            hdmi_phy_write_bit(1, 8, port, 0x1414);
            hdmi_phy_write_bit(1, 8, port, 0x1434);
            hdmi_phy_write_bit(1, 8, port, 0x1814);
            hdmi_phy_write_bit(1, 8, port, 0x1834);
        }
        hdmi_phy_update_reg(port, 0x1f44, 0xffffffc0, 0x1f);
        hdmi_phy_write_bit(1, 0x15, port, 0x1c00);
        if (is_hdmi21) {
            hdmi_phy_write_bit(1, 0x15, port, 0x2c00);
            hdmi_phy_update_reg(port, 0x2c00, 0xfff0ffff, 0x80000);
        }
        hdmi_phy_update_reg(port, 0x1c00, 0xfff0ffff, 0x80000);
        hdmi_phy_write_bit(1, 0x1b, port, 0x1c00);
        if (is_hdmi21)
            hdmi_phy_write_bit(1, 0x1b, port, 0x2c00);
        hdmi_phy_update_reg(port, 0x1000, 0xff00ffff, 0x6e0000);
        hdmi_phy_write_bit(1, 0x18, port, 0x1f40);
        hdmi_phy_write_bit(1, 8, port, 0x3608);
        if (is_hdmi21) {
            hdmi_phy_write_bit(1, 9, port, 0x3608);
            hdmi_phy_update_reg(port, 0x3608, 0xffffc7ff, 0x3700);
        }
        timer_delay_long_units(1);
        hdmi_phy_write_bit(1, 0x10, port, 0x1c04);
        /* These eight writes go to PHY 0 on every pass. */
        hdmi_phy_write_bit(0, 0x15, 0, 0x1c04);
        hdmi_phy_write_bit(0, 7, 0, 0x1e80);
        hdmi_phy_update_reg(0, 0x1c04, 0xffff00ff, 0x4d00);
        hdmi_phy_write_bit(0, 0xf, 0, 0x1c04);
        hdmi_phy_write_bit(0, 0x19, 0, 0x1160);
        hdmi_phy_write_bit(0, 0x16, 0, 0x1c00);
        hdmi_phy_write_bit(0, 0x17, 0, 0x1c00);
        hdmi_phy_write_bit(1, 0x18, 0, 0x1c0c);
        hdmi_phy_write_bit(1, 2, port, 0x1c04);

        /* 2d: the port's EQ state starts empty. */
        lib_memset(&hdmi_eq_scan_records[port], 0, 0xc);
        lib_memset(hdmi_eq_port_records[port], 0, 0x898);
        lib_memset(&hdmi_phy_records[port], 0, 0x18);
        if ((dbg_hdmi_message_flags & HDMI_MSG_INIT_INFO) != 0)
            dbg_printf("[INIT]: Port%c HDMIRX20_PHYPORT Init %d\r\n", (char)(port + 'A'), port);

        /* 2e: HDMI 2.1 PHYs: the "LC_PLL OFF" settings of the second register set. */
        if (is_hdmi21) {
            if ((dbg_hdmi_message_flags & HDMI_MSG_INIT_INFO) != 0)
                dbg_printf("[INIT]: Port%c H21 LC_PLL OFF %d\r\n", (char)(port + 'A'), port);
            hdmi_phy_write_bit(0, 0x13, port, 0x2c34);
            hdmi_phy_write_bit(1, 0x19, port, 0x2c34);
            hdmi_phy_write_bit(0, 0x10, port, 0x2c34);
            hdmi_phy_write_bit(0, 0x11, port, 0x2c34);
            hdmi_phy_write_bit(0, 0x12, port, 0x2c34);
            hdmi_phy_update_reg(port, 0x2c30, 0xfff0ffff, 0xb0000);
            hdmi_phy_update_reg(port, 0x2c30, 0xff0fffff, 0x400000);
            hdmi_phy_update_reg(port, 0x2c30, 0xf0ffffff, 0xd000000);
            hdmi_phy_update_reg(port, 0x2c30, 0xfffffff, 0x20000000);
            hdmi_phy_write_bit(0, 0, port, 0x2c30);
            hdmi_phy_update_reg(port, 0x2c34, 0xff1fffff, 0xc00000);
            hdmi_phy_update_reg(port, 0x2c38, 0xfffff1ff, 0);
            hdmi_phy_update_reg(port, 0x2c34, 0xfffff3ff, 0);
            hdmi_phy_write_bit(0, 0x14, port, 0x2c34);
            hdmi_phy_update_reg(port, 0x2c24, 0xfcffffff, 0);
            hdmi_phy_write_bit(0, 5, port, 0x2c20);
            hdmi_phy_write_bit(0, 4, port, 0x2c20);
        }

        /* 2f */
        hdmi_phy_set_power_flag(port, 1);
    }

    /* Phase 3 */
    if ((dbg_hdmi_message_flags & HDMI_MSG_INIT_INFO) != 0)
        dbg_printf("[INIT]: DRV_HDMI_InitialSettings finish %d\r\n", 0x378);
}
