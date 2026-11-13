/* dp_set_unit_format_field  (FUN_a00adf84)
 *
 * Write the 2-bit format field of the unit a port is mapped to.
 * Name basis: descriptive - registers 0xCF014798 / 0xCF01479C
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00adf84 @ 0xa00adf84, flags -mcpu=v8 -Os -g.
 * Source form: the four-arm if chain is written out for each register; the compiler shares the tails.
 * dp_get_reg9f_field is a call to a ROM address outside the image.
 */
extern unsigned int dp_get_reg9f_field(unsigned char);
extern unsigned char dp_map_port_lane_unit(unsigned char, unsigned char);

#define REG_CF014798 (*(volatile unsigned int *)0xcf014798)   /* 2-bit fields of units 0..3 */
#define REG_CF01479C (*(volatile unsigned int *)0xcf01479c)   /* 2-bit fields of units 4.. */

/*
 * Write a 2-bit field for the unit that "port" is mapped to (dp_map_port_lane_unit with the value of
 * dp_get_reg9f_field). The field of unit n is at bit 2 * n of register 0xCF014798 for units 0..3 and at
 * bit 2 * (n - 4) of 0xCF01479C above that. It gets 3 for mode 1, 2 for mode 2, 1 for mode 4 and 0 for any
 * other mode. dp_apply_format_code ends with a call with mode 8 / b.
 *   port: DP port
 *   mode: 1, 2 or 4, see above
 */
void dp_set_unit_format_field(unsigned char port, unsigned char mode)
{
    unsigned char unit;

    unit = dp_map_port_lane_unit(port, dp_get_reg9f_field(port));
    if (unit <= 3) {
        if (mode == 1)
            REG_CF014798 |= 3 << (unit * 2);
        else if (mode == 2)
            REG_CF014798 = (REG_CF014798 & ~(3 << (unit * 2))) | (mode << (unit * 2));
        else if (mode == 4)
            REG_CF014798 = (REG_CF014798 & ~(3 << (unit * 2))) | (1 << (unit * 2));
        else
            REG_CF014798 &= ~(3 << (unit * 2));
    } else {
        unit -= 4;
        if (mode == 1)
            REG_CF01479C |= 3 << (unit * 2);
        else if (mode == 2)
            REG_CF01479C = (REG_CF01479C & ~(3 << (unit * 2))) | (mode << (unit * 2));
        else if (mode == 4)
            REG_CF01479C = (REG_CF01479C & ~(3 << (unit * 2))) | (1 << (unit * 2));
        else
            REG_CF01479C &= ~(3 << (unit * 2));
    }
}
