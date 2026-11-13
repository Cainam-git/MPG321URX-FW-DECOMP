/* hdcp_rx_dp_load_hdcp2_tables  (FUN_a00c1550)
 *
 * Load the HDCP 2 tables into the DisplayPort input.
 * Name basis: descriptive - twin of hdcp_rx_hdmi_load_hdcp2_tables on the registers 0x400..0x406
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00c1550 @ 0xa00c1550, flags -mcpu=v8 -Os -g (the section default).
 * Source form: the saved control byte must be an unsigned char (it is read twice, once for the saved copy and
 * once for the value with bits 3-4 cleared); the byte read from each table is held in an unsigned char before
 * it is written; every loop is a do/while with a post-increment test against its last index.
 */
extern void dp_reg_write8(unsigned int, unsigned int, unsigned int);
extern void dp_reg_update_bits(unsigned int, unsigned int, unsigned int, unsigned int);
extern unsigned char hdcp_rx_dp_hdcp2_bytes[];

#define _DAT_cf00f21c (*(volatile unsigned int *)0xcf00f21c)

#define EXTRA_LENGTH  0x140     /* bytes taken from the extra buffer (0x80 filled from the store, the rest 0) */
#define TABLE_LENGTH  0x20a     /* bytes of the large table */
#define ZERO_LENGTH   0x18      /* zero bytes in front of the 16-byte value */
#define VALUE_LENGTH  0x10      /* bytes of the value */
#define FIXED_LENGTH  0xb       /* bytes of hdcp_rx_dp_hdcp2_bytes */

/*
 * Load the HDCP 2 tables into one DisplayPort receiver.
 *
 *   port    the receiver, 0 or 1
 *   value   16-byte value (OTP address 0x270 or the built-in one)
 *   table   0x20A-byte table
 *   unused  not read (InitHDCP passes 0)
 *   extra   0x140-byte buffer, 0x80 bytes of stored or built-in data followed by zeros
 *
 * Called by InitHDCP for ports 0 and 1. Each of the four blocks is written byte by byte to register 0x401
 * after the same three steps: a code into register 0x400, 0 into register 0x403 and bit 7 of register
 * 0x402 set. The blocks, in order, with the code written to register 0x400 first:
 *   code 0       the extra buffer from its last byte to its first (0x140 bytes), then 0x80 into register 0x406;
 *   code 2       the table in order (0x20A bytes);
 *   code 0x11    24 zero bytes, then the value from its last byte to its first (16 bytes);
 *   code 3       the 11 bytes of hdcp_rx_dp_hdcp2_bytes in order.
 * Bits 3-4 of register 0xCF00F21C are cleared for the whole load and the saved byte is written back at the end.
 */
void hdcp_rx_dp_load_hdcp2_tables(unsigned int port, unsigned char *value, unsigned char *table, int unused, unsigned char *extra)
{
    unsigned int masked_control;
    unsigned char saved_control;
    unsigned short i;
    unsigned char byte;

    saved_control = _DAT_cf00f21c;
    masked_control = _DAT_cf00f21c;
    masked_control &= ~0x18;
    port &= 0xff;
    _DAT_cf00f21c = masked_control;

    dp_reg_write8(port, 0x400, 0);
    dp_reg_write8(port, 0x403, 0);
    dp_reg_update_bits(port, 0x402, 0x80, 1);

    i = 0;
    do {
        byte = extra[EXTRA_LENGTH - 1 - i];
        dp_reg_write8(port, 0x401, byte);
    } while (++i <= EXTRA_LENGTH - 1);

    dp_reg_write8(port, 0x406, 0x80);
    dp_reg_write8(port, 0x400, 2);
    dp_reg_write8(port, 0x403, 0);
    dp_reg_update_bits(port, 0x402, 0x80, 1);

    i = 0;
    do {
        byte = table[i];
        dp_reg_write8(port, 0x401, byte);
    } while (++i <= TABLE_LENGTH - 1);

    dp_reg_write8(port, 0x400, 0x11);
    dp_reg_write8(port, 0x403, 0);
    dp_reg_update_bits(port, 0x402, 0x80, 1);

    i = 0;
    do {
        dp_reg_write8(port, 0x401, 0);
    } while (++i <= ZERO_LENGTH - 1);

    i = 0;
    do {
        byte = value[VALUE_LENGTH - 1 - i];
        dp_reg_write8(port, 0x401, byte);
    } while (++i <= VALUE_LENGTH - 1);

    dp_reg_write8(port, 0x400, 3);
    dp_reg_write8(port, 0x403, 0);
    dp_reg_update_bits(port, 0x402, 0x80, 1);

    i = 0;
    do {
        byte = hdcp_rx_dp_hdcp2_bytes[i];
        dp_reg_write8(port, 0x401, byte);
    } while (++i <= FIXED_LENGTH - 1);

    _DAT_cf00f21c = saved_control;
}
