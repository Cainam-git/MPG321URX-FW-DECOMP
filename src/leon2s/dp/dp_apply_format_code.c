/* dp_apply_format_code  (FUN_a00ae0dc)
 *
 * Write the register values for a format code and its unit format field.
 * Name basis: descriptive - values chosen by the code
 *
 * Matching notes
 * --------------
 * FUN_a00ae0dc (leon2s), flags -mcpu=v8 -Os -g.
 * Source form: dp_set_unit_format_field takes two parameters (it never reads the third); the third register at
 * the tail call holds the leftover value of "group_3". Each arm keeps its own dp_reg_update_bits call.
 */
extern unsigned char dp_is_format_code_group_3(unsigned char);
extern void dp_reg_update_bits(unsigned int, unsigned short, unsigned int, unsigned int);
extern void dp_reg_write8(unsigned char, unsigned short, unsigned char);
extern void dp_set_unit_format_field(unsigned char, unsigned char);

/*
 * Write receiver registers 0xD5 and 0xD7 for a format code, then set the 2-bit field of the port's unit.
 * Bit 0 of register 0xD5 is set; bit 5 of register 0xD5 is set when dp_is_format_code_group_3(code) is
 * non-zero, else cleared. Register 0xD7 gets 0x12 for divisor 8, 6 for divisor 4 and 2 for any other value.
 * Last it calls dp_set_unit_format_field(port, 8 / divisor). dp_run_link_state calls it with divisor 4 or 1.
 *   port: DP receiver
 *   divisor: 8, 4 or another value, see above (must not be 0)
 *   code: format code (the colour_space field of the port record)
 */
void dp_apply_format_code(unsigned char port, unsigned char divisor, unsigned char code)
{
    unsigned char group_3 = 0;

    if (dp_is_format_code_group_3(code))
        group_3 = 1;

    dp_reg_update_bits(port, 0xd5, 1, 1);
    if (divisor == 8) {
        dp_reg_update_bits(port, 0xd5, 0x20, group_3);
        dp_reg_write8(port, 0xd7, 0x12);
    } else if (divisor == 4) {
        dp_reg_update_bits(port, 0xd5, 0x20, group_3);
        dp_reg_write8(port, 0xd7, 6);
    } else {
        dp_reg_update_bits(port, 0xd5, 0x20, group_3);
        dp_reg_write8(port, 0xd7, 2);
    }
    dp_set_unit_format_field(port, 8 / divisor);
}
