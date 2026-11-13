/* dp_is_msa_bit4_clear  (FUN_a00ad6ec)
 *
 * Select indirect register 8 and return whether bit 4 of its value is clear.
 * Returns: 0 or 1
 * Name basis: descriptive - index 0x73, data 0x7A
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00ad6ec @ 0xa00ad6ec, flags -mcpu=v8 -Os -g.
 */
extern unsigned int dp_reg_read8(unsigned int, unsigned short);
extern void dp_reg_write8(unsigned int, unsigned short, unsigned int);

/*
 * Write 0 to receiver register 0x70 and 8 to register 0x73, then return 1 when bit 4 of register 0x7A is
 * clear, else 0. dp_get_color_format_code calls it.
 *   port_arg: DP receiver
 */
int dp_is_msa_bit4_clear(unsigned int port_arg)
{
    unsigned int bit4;
    unsigned int port;

    port = port_arg & 0xff;
    dp_reg_write8(port, 0x70, 0);
    dp_reg_write8(port, 0x73, 8);
    bit4 = dp_reg_read8(port, 0x7a) & 0x10;
    return (bit4 == 0) ? 1 : 0;
}
