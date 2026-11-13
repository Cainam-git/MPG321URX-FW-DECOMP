/* hdmi_rx21_modedet_set_pll_mode  (MODEDET_handler_2)
 *
 * Select the pixel PLL bit mode (8/10/12/16 bits) for an HDMI 2.1 input.
 *   port: HDMI 2.1 receiver 0/1
 * Note: Label MODEDET_handler_2 is not printed by the firmware.
 * Name basis: proven - prints 'Set PLL 8 / 10 / 12 / 16 bits Mode', 'Use Internal PLL'
 *
 * Matching notes
 * --------------
 * leon2s MODEDET_handler_2 @ 0xa009d87c-0xa009dd40 (1220 bytes), flags -mcpu=v8 -Os -g (section default).
 * Source forms the exact build depends on:
 *  - bits_per_colour[4] = {8, 10, 12, 16} is a local copy of the ROM table 0xa00b44fc (memcpy);
 *  - phy, setup_unit and pll_unit are declared with the port 0 values and then set per port in an
 *    'if (port == 0) / else if (port == 1) / else return' chain, each arm with 'setup_unit = phy;' (the
 *    firmware's move in the delay slot of the port 0 branch);
 *  - the two port tests on REG_1640 are switches;
 *  - the default arm of each mode switch comes first;
 *  - the final record index is a second unsigned char copy of the parameter (record_port).
 */

/* Colour depth codes (mode): the bits per colour of each code are the prints 'Set PLL 8 / 10 / 12 / 16 bits
   Mode'. The caller passes 4 when a CVTEM packet is present, else bits 8..11 of block 0 register 0x44. */
enum colour_depth_code {
    COLOUR_DEPTH_8_BITS  = 4,
    COLOUR_DEPTH_10_BITS = 5,
    COLOUR_DEPTH_12_BITS = 6,
    COLOUR_DEPTH_16_BITS = 7
};

#define PHY_RX21_0              2       /* PHY numbers of the HDMI 2.1 receivers 0 / 1 */
#define PHY_RX21_1              3

/* Receiver registers, as word indexes into the register blocks. */
#define BLOCK0_REG_08_W         (0x08 / 4)
#define BLOCK0_REG_2_BIT11      0xb     /* set by DRV_HDMI_ModeDetect_FSM_FRL_Init */
#define BLOCK0_REG_40_W         (0x40 / 4)
#define BLOCK0_REG_40_BIT13     0xd     /* set for 8 bits, cleared otherwise and for the internal PLL */
#define BLOCK0_REG_44_W         (0x44 / 4)
#define BLOCK0_DEPTH_FIELD      0xf00   /* bits 8..11: colour depth code, read by the caller */
#define BLOCK0_REG_84_W         (0x84 / 4)
#define INTERNAL_PLL_BIT        0x14    /* bit 20 set: 'Use Internal PLL' */
#define BLOCK0_REG_B4_W         (0xb4 / 4)
#define BLOCK0_REG_B4_BIT2      2       /* cleared with CVTEM; the caller sets it on every pass */
#define BLOCK1_REG_44_W         (0x44 / 4)
#define BLOCK1_BITS_5_6         0x60

/* Register 0xCF011640: bit 6 / 7 for HDMI 2.1 receiver 0 / 1 (hdmi_apply_color_depth uses bits 4 / 5 for the
   HDMI 2.0 receivers). */
#define REG_1640                (*(volatile unsigned int *)0xcf011640)
#define REG_1640_RX21_0         0x40
#define REG_1640_RX21_1         0x80

#define PHY_REG_1F08            0x1f08  /* internal PLL: bits 0..2 = colour depth code */
#define PHY_REG_1F08_KEEP       0xfffffff8

/* Values for hdmi_unit_write_setup (its register groups 4..6 and 8..10); the second value of each pair grows
   with the bit count in the ratio 8 : 10 : 12 : 16. */
#define SETUP_A                 0x80
#define PLL_A                   0xc0

#define CHIP_REV_81             0x81    /* newer chips (revision above this) set the PLL depth field directly */
#define HDMI_MSG_MODEDET_FLOW   0x04    /* dbg_hdmi_message_flags bit 2: '[MODEDET]' lines */

#define RX21_RECORD_SIZE        400     /* bytes per receiver in hdmi_rx21_input_records */
#define RX21_COLOUR_DEPTH       0x19    /* receiver record byte: bits per colour */

/* Register block addresses of an HDMI 2.1 receiver (13 words, hdmi_rx21_reg_blocks). */
struct hdmi_rx21_reg_blocks {
    volatile unsigned int *block0;      /* 0xCE009000 (+0x1000 for receiver 1) */
    volatile unsigned int *block1;
    unsigned char blocks_2_to_12[0x34 - 8];
};
extern struct hdmi_rx21_reg_blocks ARR_a807db00[];
extern unsigned char hdmi_rx21_input_records[];
extern unsigned int dbg_hdmi_message_flags;
extern void *memcpy(void *, const void *, unsigned int) __asm__("FUN_a00b15d8");
extern int dbg_printf(const char *, ...);
extern unsigned int reg_test_bit(unsigned int, volatile unsigned int *);
extern void hdmi_unit_write_setup(unsigned char unit, unsigned int a, unsigned int b);
extern unsigned char hdmi_rx21_has_cvtem(unsigned char port);
extern void reg_clear_bit(unsigned int bit, volatile unsigned int *p);
extern void reg_set_bit(unsigned int bit, volatile unsigned int *p);
extern unsigned char sys_get_chip_revision(void);
extern void hdmi_rx21_set_pll_color_depth(unsigned char port, unsigned char code);
extern void hdmi_rx21_set_deep_color_enable(unsigned char port, unsigned char on);
extern void hdmi_phy_update_reg(unsigned char phy, unsigned short reg, unsigned int mask, unsigned int v);

/*
 * Set the pixel PLL of an HDMI 2.1 receiver up for a colour depth.
 *
 *   arg   HDMI 2.1 receiver 0 or 1 (printed as 'A' + arg); any other value returns at once
 *   mode  colour depth code (enum colour_depth_code); other values are treated as 8 bits
 *
 * Called by hdmi_rx21_modedet_check_pll (mode-detection state 4, CHECK_PLL) on each counted pass.
 *
 * Phases:
 *   1. Units: phy = PHY 2 / 3 (also the unit of the first set-up write), pll_unit = 0 / 1.
 *   2. REG_1640: the receiver's bit follows bits 5 and 6 of block 1 register 0x44 (set only when both are set).
 *   3. Set-up write to unit phy: by the depth code when BLOCK0_REG_2_BIT11 is set, else the 8-bit value.
 *   4. PLL: with INTERNAL_PLL_BIT clear, the depth code goes to the PLL: on chips above CHIP_REV_81 through
 *      hdmi_rx21_set_pll_color_depth and hdmi_rx21_set_deep_color_enable, on older chips as a set-up write
 *      to pll_unit; for 8 bits with CVTEM the depth field of block 0 register 0x44 is set to 4 first. With
 *      INTERNAL_PLL_BIT set, the code goes into PHY register 0x1F08 ('Use Internal PLL').
 *   5. Store the bits per colour in the receiver record (byte 0x19).
 */
void hdmi_rx21_modedet_set_pll_mode(unsigned int arg, unsigned int mode)
{
    unsigned int bits_per_colour[4] = {8, 10, 12, 16};
    unsigned char port = arg;
    unsigned char phy = PHY_RX21_0;
    unsigned char setup_unit = PHY_RX21_0;
    unsigned char pll_unit = 0;
    unsigned char record_port;

    /* 1. Units of the receiver. */
    if (port == 0) {
        phy = PHY_RX21_0;
        pll_unit = 0;
        setup_unit = phy;
    } else if (port == 1) {
        phy = PHY_RX21_1;
        pll_unit = 1;
        setup_unit = phy;
    } else {
        return;
    }

    /* 2. Receiver bit of REG_1640. */
    if ((ARR_a807db00[port].block1[BLOCK1_REG_44_W] & BLOCK1_BITS_5_6) == BLOCK1_BITS_5_6) {
        switch (port) {
        case 0:
            REG_1640 |= REG_1640_RX21_0;
            break;
        case 1:
            REG_1640 |= REG_1640_RX21_1;
            break;
        }
    } else {
        switch (port) {
        case 0:
            REG_1640 &= ~REG_1640_RX21_0;
            break;
        case 1:
            REG_1640 &= ~REG_1640_RX21_1;
            break;
        }
    }

    /* 3. Set-up write by depth code. */
    if (reg_test_bit(BLOCK0_REG_2_BIT11, ARR_a807db00[port].block0 + BLOCK0_REG_08_W) != 0) {
        switch (mode) {
        case COLOUR_DEPTH_10_BITS:
            hdmi_unit_write_setup(setup_unit, SETUP_A, 0x50);
            break;
        case COLOUR_DEPTH_12_BITS:
            hdmi_unit_write_setup(setup_unit, SETUP_A, 0x60);
            break;
        case COLOUR_DEPTH_16_BITS:
            hdmi_unit_write_setup(setup_unit, SETUP_A, 0x80);
            break;
        default:
            hdmi_unit_write_setup(setup_unit, SETUP_A, 0x40);
            break;
        }
    } else {
        hdmi_unit_write_setup(setup_unit, SETUP_A, 0x40);
    }

    /* 4. The PLL. */
    if (reg_test_bit(INTERNAL_PLL_BIT, ARR_a807db00[port].block0 + BLOCK0_REG_84_W) == 0) {
        switch (mode) {
        default:
            /* 8 bits. With CVTEM: clear bit 2 of block 0 register 0xB4 and set the depth field to 8 bits. */
            if (hdmi_rx21_has_cvtem(port) == 1) {
                reg_clear_bit(BLOCK0_REG_B4_BIT2, ARR_a807db00[port].block0 + BLOCK0_REG_B4_W);
                ARR_a807db00[port].block0[BLOCK0_REG_44_W] = (ARR_a807db00[port].block0[BLOCK0_REG_44_W] & ~BLOCK0_DEPTH_FIELD) | 0x400;
            }
            reg_set_bit(BLOCK0_REG_40_BIT13, ARR_a807db00[port].block0 + BLOCK0_REG_40_W);
            if (sys_get_chip_revision() > CHIP_REV_81) {
                hdmi_rx21_set_pll_color_depth(port, COLOUR_DEPTH_8_BITS);
                hdmi_rx21_set_deep_color_enable(port, 0);
            } else {
                hdmi_unit_write_setup(pll_unit, PLL_A, 0xc0);
            }
            if ((dbg_hdmi_message_flags & HDMI_MSG_MODEDET_FLOW) != 0)
                dbg_printf("[MODEDET]: Port%c Set PLL 8 bits Mode\n", (char)(arg + 'A'));
            break;
        case COLOUR_DEPTH_10_BITS:
            reg_clear_bit(BLOCK0_REG_40_BIT13, ARR_a807db00[port].block0 + BLOCK0_REG_40_W);
            if ((dbg_hdmi_message_flags & HDMI_MSG_MODEDET_FLOW) != 0)
                dbg_printf("[MODEDET]: Port%c Set PLL 10 bits Mode\n", (char)(arg + 'A'));
            if (sys_get_chip_revision() > CHIP_REV_81) {
                hdmi_rx21_set_pll_color_depth(port, COLOUR_DEPTH_10_BITS);
                hdmi_rx21_set_deep_color_enable(port, 1);
            } else {
                hdmi_unit_write_setup(pll_unit, PLL_A, 0xf0);
            }
            break;
        case COLOUR_DEPTH_12_BITS:
            reg_clear_bit(BLOCK0_REG_40_BIT13, ARR_a807db00[port].block0 + BLOCK0_REG_40_W);
            if ((dbg_hdmi_message_flags & HDMI_MSG_MODEDET_FLOW) != 0)
                dbg_printf("[MODEDET]: Port%c Set PLL 12 bits Mode\n", (char)(arg + 'A'));
            if (sys_get_chip_revision() > CHIP_REV_81) {
                hdmi_rx21_set_pll_color_depth(port, COLOUR_DEPTH_12_BITS);
                hdmi_rx21_set_deep_color_enable(port, 1);
            } else {
                hdmi_unit_write_setup(pll_unit, PLL_A, 0x120);
            }
            break;
        case COLOUR_DEPTH_16_BITS:
            reg_clear_bit(BLOCK0_REG_40_BIT13, ARR_a807db00[port].block0 + BLOCK0_REG_40_W);
            if ((dbg_hdmi_message_flags & HDMI_MSG_MODEDET_FLOW) != 0)
                dbg_printf("[MODEDET]: Port%c Set PLL 16 bits Mode\n", (char)(arg + 'A'));
            if (sys_get_chip_revision() > CHIP_REV_81) {
                hdmi_rx21_set_pll_color_depth(port, COLOUR_DEPTH_16_BITS);
                hdmi_rx21_set_deep_color_enable(port, 1);
            } else {
                hdmi_unit_write_setup(pll_unit, PLL_A, 0x180);
            }
            break;
        }
    } else {
        reg_clear_bit(BLOCK0_REG_40_BIT13, ARR_a807db00[port].block0 + BLOCK0_REG_40_W);
        switch (mode) {
        default:
            hdmi_phy_update_reg(phy, PHY_REG_1F08, PHY_REG_1F08_KEEP, COLOUR_DEPTH_8_BITS);
            break;
        case COLOUR_DEPTH_10_BITS:
            hdmi_phy_update_reg(phy, PHY_REG_1F08, PHY_REG_1F08_KEEP, COLOUR_DEPTH_10_BITS);
            break;
        case COLOUR_DEPTH_12_BITS:
            hdmi_phy_update_reg(phy, PHY_REG_1F08, PHY_REG_1F08_KEEP, COLOUR_DEPTH_12_BITS);
            break;
        case COLOUR_DEPTH_16_BITS:
            hdmi_phy_update_reg(phy, PHY_REG_1F08, PHY_REG_1F08_KEEP, COLOUR_DEPTH_16_BITS);
            break;
        }
        if ((dbg_hdmi_message_flags & HDMI_MSG_MODEDET_FLOW) != 0)
            dbg_printf("[MODEDET]: Port%c Use Internal PLL\n", (char)(arg + 'A'));
    }

    /* 5. Bits per colour into the receiver record. */
    record_port = arg;
    if (mode >= COLOUR_DEPTH_8_BITS && mode <= COLOUR_DEPTH_16_BITS)
        hdmi_rx21_input_records[record_port * RX21_RECORD_SIZE + RX21_COLOUR_DEPTH] = bits_per_colour[mode - COLOUR_DEPTH_8_BITS];
    else
        hdmi_rx21_input_records[record_port * RX21_RECORD_SIZE + RX21_COLOUR_DEPTH] = 8;
}
