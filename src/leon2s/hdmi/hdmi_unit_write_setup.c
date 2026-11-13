/* hdmi_unit_write_setup  (FUN_a00b1d00)
 *
 * Write the set-up registers (two 24-bit values) of a PLL unit and pulse its control register.
 * Name basis: descriptive - registers 0, 1, 4..6, 8..10 and 3 through hdmi_pll_reg_write8 (PLL units 0..8);
 *   called by input_init_phy_registers for units 0..7 and by hdmi_rx21_modedet_set_pll_mode
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00b1d00 @ 0xa00b1d00-0xa00b1e2c (300 bytes; jump table 0xa00b1cdc), flags -mcpu=v8 -Os -g
 * (section default).
 * Source forms the exact build depends on:
 *  - every case of the switch has its own body, although they give only two values; case 8 falls through into
 *    the default body (same value), which gives the firmware's block layout after the jump table;
 *  - the unit is an unsigned char copy taken after the switch; the test for unit 8 uses the parameter.
 */

/* Byte registers of a pixel PLL unit (hdmi_pll_reg_write8; units 0..8, bases in hdmi_pll_reg_bases). */
#define UNIT_REG_0           0
#define UNIT_REG_1           1
#define UNIT_REG_CTRL        3          /* written 3, 7, 3 at the end */
#define UNIT_REG_FIRST_0     4          /* 4..6: first_value, low byte first */
#define UNIT_REG_SECOND_0    8          /* 8..10: second_value, low byte first */

#define UNIT_REG0_DEFAULT    0xd0
#define UNIT_REG0_UNITS_4_6  0          /* register 0 of units 4 and 6 */
#define UNIT_REG1_VALUE      0xea
#define UNIT8_REG1_VALUE     0xaa

#define CTRL_IDLE            3
#define CTRL_BIT2            4          /* set for one wait, then cleared */

/* Unit 8 has base 0x6000, the block hdmi_tx_sys_reg_bases gives for HDMI output 0. */
#define UNIT_8               8
#define REG_44AC             (*(volatile unsigned int *)0xcf0144ac)
#define REG_44AC_BIT7        0x80       /* set before unit 8 is written */

extern void hdmi_pll_reg_write8(unsigned char, unsigned char, unsigned char);
extern void timer_delay_long_units(int);

/*
 * Program pixel PLL unit `unit` (0..8) with two 24-bit values.
 *
 *   first_value   written to unit registers 4, 5, 6 (bits 0..7, 8..15, 16..23)
 *   second_value  written to unit registers 8, 9, 10 in the same way
 *
 * Register 0 gets 0 on units 4 and 6 and 0xD0 on all others, register 1 gets 0xEA. Unit 8 also sets bit 7
 * of register 0xCF0144AC and then writes 0xAA to its register 1. After the two values, register 3 goes from
 * 3 to 7 and back to 3 with one wait unit (timer_delay_long_units(1)) between.
 *
 * Callers: input_init_phy_registers (units 0..7 at start-up) and hdmi_rx21_modedet_set_pll_mode (the
 * second value grows with the PLL bit mode, 8 / 10 / 12 / 16 bits).
 */
void hdmi_unit_write_setup(unsigned int unit, unsigned int first_value, unsigned int second_value)
{
    unsigned char reg0_value;
    unsigned char unit_number;

    switch (unit) {
    case 0:
        reg0_value = UNIT_REG0_DEFAULT;
        break;
    case 1:
        reg0_value = UNIT_REG0_DEFAULT;
        break;
    case 2:
        reg0_value = UNIT_REG0_DEFAULT;
        break;
    case 3:
        reg0_value = UNIT_REG0_DEFAULT;
        break;
    case 4:
        reg0_value = UNIT_REG0_UNITS_4_6;
        break;
    case 5:
        reg0_value = UNIT_REG0_DEFAULT;
        break;
    case 6:
        reg0_value = UNIT_REG0_UNITS_4_6;
        break;
    case 7:
        reg0_value = UNIT_REG0_DEFAULT;
        break;
    case 8:
        reg0_value = UNIT_REG0_DEFAULT;
    default:
        reg0_value = UNIT_REG0_DEFAULT;
        break;
    }
    unit_number = unit;
    hdmi_pll_reg_write8(unit_number, UNIT_REG_0, reg0_value);
    hdmi_pll_reg_write8(unit_number, UNIT_REG_1, UNIT_REG1_VALUE);
    if (unit == UNIT_8) {
        REG_44AC |= REG_44AC_BIT7;
        hdmi_pll_reg_write8(UNIT_8, UNIT_REG_1, UNIT8_REG1_VALUE);
    }
    hdmi_pll_reg_write8(unit_number, UNIT_REG_FIRST_0, first_value);
    hdmi_pll_reg_write8(unit_number, UNIT_REG_FIRST_0 + 1, first_value >> 8);
    hdmi_pll_reg_write8(unit_number, UNIT_REG_FIRST_0 + 2, first_value >> 16);
    hdmi_pll_reg_write8(unit_number, UNIT_REG_SECOND_0, second_value);
    hdmi_pll_reg_write8(unit_number, UNIT_REG_SECOND_0 + 1, second_value >> 8);
    hdmi_pll_reg_write8(unit_number, UNIT_REG_SECOND_0 + 2, second_value >> 16);
    hdmi_pll_reg_write8(unit_number, UNIT_REG_CTRL, CTRL_IDLE);
    hdmi_pll_reg_write8(unit_number, UNIT_REG_CTRL, CTRL_IDLE | CTRL_BIT2);
    timer_delay_long_units(1);
    hdmi_pll_reg_write8(unit_number, UNIT_REG_CTRL, CTRL_IDLE);
}
