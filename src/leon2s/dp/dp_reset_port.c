/* dp_reset_port  (FUN_a00afbbc)
 *
 * Reset a DisplayPort input and apply its settings again.
 * Name basis: derived - register resets, then the port set-up calls; used by dp_init_port
 *
 * Matching notes
 * --------------
 * FUN_a00afbbc (leon2s, 0xa00afbbc-0xa00afd04, 328 bytes), flags -mcpu=v8 -Os -g.
 * The record is dp_input_records as a 300-byte struct (a mid-record name with byte offsets splits the address
 * arithmetic). volatile only on the 0xcf011758 hardware register.
 */
extern unsigned char dp_reset_byte;
extern unsigned int dp_input_record0_byte_0x11f;
#define _DAT_cf011758 (*(volatile unsigned int *)0xcf011758)
extern int sys_get_chip_revision();
extern void dp_reg_write8(unsigned int, unsigned short, unsigned int);
extern void dp_reg_update_bits(unsigned int, unsigned short, unsigned int, unsigned int);
extern void dp_write_rate_divider_regs(unsigned int, unsigned short, unsigned int);
extern void dp_set_port_flag_bit(unsigned int, unsigned int);
extern void dp_reset_port_logic(unsigned int, unsigned int, unsigned int, unsigned int);
extern int dp_program_port(unsigned int);
extern int dp_setup_port_regs(unsigned int);
extern int dp_apply_port_settings(unsigned int);
/* The 300-byte record of one DP input (array dp_input_records); only the used fields are named. */
struct dp_input_record { unsigned char pad[0x11f]; unsigned char byte_0x11f; unsigned short half_0x120; unsigned char pad2[300 - 0x122]; };
extern struct dp_input_record dp_input_records[];

/* Resets a DP input and applies its settings again.
 *
 * Order: register 0x2f = 0x30 and 0xf7 = 0; dp_write_rate_divider_regs(port, record halfword 0x120, 1); bits 2
 * and 3 of register 0xc2 set (one write each); on chip revision above 0x81 bit 4 of 0xcf011758 set;
 * dp_program_port, dp_setup_port_regs, dp_apply_port_settings; dp_reset_port_logic(port, 1, 1, 0) when record
 * byte 0x11f is 1; dp_set_port_flag_bit(port, 0); registers 0xc5 = 4 and 0xc4 = 0x55; bits port and port + 4 of
 * dp_reset_byte cleared; registers 0x51 = 0xa0 and 0x23 = 0x40.
 *
 * port_arg: DP input (receiver 0 or 1). Called by dp_init_port.
 */
void dp_reset_port(unsigned char port_arg)
{
    unsigned int port;
    unsigned int chip_revision;

    port = port_arg & 0xff;
    dp_reg_write8(port, 0x2f, 0x30);
    dp_reg_write8(port, 0xf7, 0);
    dp_write_rate_divider_regs(port, dp_input_records[port].half_0x120, 1);
    dp_reg_update_bits(port, 0xc2, 4, 1);
    dp_reg_update_bits(port, 0xc2, 8, 1);
    chip_revision = sys_get_chip_revision();
    if ((chip_revision & 0xff) > 0x81) {
        _DAT_cf011758 = _DAT_cf011758 | 0x10;
    }
    dp_program_port(port);
    dp_setup_port_regs(port);
    dp_apply_port_settings(port);
    if (dp_input_records[port].byte_0x11f == 1) {
        dp_reset_port_logic(port, 1, 1, 0);
    }
    dp_set_port_flag_bit(port, 0);
    dp_reg_write8(port, 0xc5, 4);
    dp_reg_write8(port, 0xc4, 0x55);
    dp_reset_byte = dp_reset_byte & ~(1 << port_arg) & ~(0x10 << port_arg);
    dp_reg_write8(port, 0x51, 0xa0);
    dp_reg_write8(port, 0x23, 0x40);
}
