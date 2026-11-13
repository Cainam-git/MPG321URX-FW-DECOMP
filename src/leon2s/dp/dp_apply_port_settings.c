/* dp_apply_port_settings  (FUN_a00af98c)
 *
 * Write the register sequence that applies a port's stored settings.
 * Name basis: derived - register writes and the unit fields; called by commands from the main processor
 *
 * Matching notes
 * --------------
 * FUN_a00af98c (leon2s 0xa00af98c-0xa00afbbc, 560 bytes), flags -mcpu=v8 -Os -g.
 * The two ROM routines are reached through the labels func_0x9f1c65a0 (dp_set_reg9f_field) and func_0x9f1b6760
 * (dp_set_reg2a8_mode).
 * Source forms: the 'else' arms come second (byte 0x115 != 0 first, port != 0 first); the last record accesses go
 * through one record pointer.
 */
#define R46B0 (*(volatile unsigned int *)0xcf0046b0)

/* The 300-byte record of one DP input (array dp_input_records); only the used bytes are named. */
struct dp_input_record {
    unsigned char _000[0x112];
    unsigned char byte_0x112;
    unsigned char _113[2];
    unsigned char byte_0x115;
    unsigned char byte_0x116;
    unsigned char _117[0x126 - 0x117];
    unsigned char byte_0x126;
    unsigned char _127[0x12c - 0x127];
};
extern struct dp_input_record dp_input_records[];
extern void dp_reg_update_bits(unsigned char, unsigned short, unsigned int, unsigned int);
extern void dp_reg_write8(unsigned char, unsigned short, unsigned int);
extern unsigned int dp_reg_read8(unsigned char, unsigned short);
extern void dp_unit_write_two_24bit_values(unsigned char, unsigned int, unsigned int);
extern void dp_unit_set_field(unsigned char);
extern void dp_set_reg9f_field(unsigned char, unsigned char);
extern void dp_set_reg2a8_mode(unsigned char, unsigned char, unsigned char);

/* Writes the register sequence that applies the stored settings of a DP input.
 *
 * Fixed writes first: register 0x46 = 0x13; clear bit 2 of 0xd3; bit 7 of 0x4d is set when record byte 0x115 is
 * 0 and cleared otherwise; clear bit 5 of register 3; 0xbc = 0xd0; set bit 3 of 0x39, bit 4 of 0x43 and bit 0 of
 * 0x404. Then the unit set-up (dp_unit_write_two_24bit_values with 0x90dfe and 0xc5427, then dp_unit_set_field):
 * once for ports other than 0; for port 0 four times, each time after dp_set_reg9f_field(0, n) with n = 3, 2, 1, 0.
 * Port 0 then sets bits 0, 1 and 2 of register 0xcf0046b0 (one write each) when record 0 byte 0x112 is not 0.
 * Last, dp_set_reg2a8_mode(port, byte 0x126, byte 0x116 != 0 && byte 0x112 == 0) and bits 0 and 1 of register
 * 0x2d are cleared.
 *
 * port: DP input. Called by dp_reset_port, by the setters of record bytes 0x115, 0x116 and (port 0) 0x112, and
 * by the main-processor command 0x21 (ipc_dispatch_command).
 */
void dp_apply_port_settings(unsigned char port)
{
    struct dp_input_record *r;

    dp_reg_write8(port, 0x46, 0x13);
    dp_reg_update_bits(port, 0xd3, 4, 0);
    if (dp_input_records[port].byte_0x115 != 0)
        dp_reg_update_bits(port, 0x4d, 0x80, 0);
    else
        dp_reg_update_bits(port, 0x4d, 0x80, 1);
    dp_reg_update_bits(port, 3, 0x20, 0);
    dp_reg_write8(port, 0xbc, 0xd0);
    dp_reg_update_bits(port, 0x39, 8, 1);
    dp_reg_update_bits(port, 0x43, 0x10, 1);
    dp_reg_update_bits(port, 0x404, 1, 1);
    if (port != 0) {
        dp_unit_write_two_24bit_values(port, 0x90dfe, 0xc5427);
        dp_unit_set_field(port);
    } else {
        /* Port 0 runs the unit set-up four times, after dp_set_reg9f_field values 3, 2, 1, 0. */
        dp_set_reg9f_field(0, 3);
        dp_unit_write_two_24bit_values(0, 0x90dfe, 0xc5427);
        dp_unit_set_field(0);
        dp_set_reg9f_field(0, 2);
        dp_unit_write_two_24bit_values(0, 0x90dfe, 0xc5427);
        dp_unit_set_field(0);
        dp_set_reg9f_field(0, 1);
        dp_unit_write_two_24bit_values(0, 0x90dfe, 0xc5427);
        dp_unit_set_field(0);
        dp_set_reg9f_field(0, 0);
        dp_unit_write_two_24bit_values(0, 0x90dfe, 0xc5427);
        dp_unit_set_field(0);
        if (dp_input_records[0].byte_0x112 != 0) {
            R46B0 |= 1;
            R46B0 |= 2;
            R46B0 |= 4;
        }
    }
    r = &dp_input_records[port];
    dp_set_reg2a8_mode(port, r->byte_0x126, r->byte_0x116 != 0 && r->byte_0x112 == 0);
    dp_reg_write8(port, 0x2d, dp_reg_read8(port, 0x2d) & 0xfc);
}
