/* hdcp_rx_hdmi21_load_hdcp2_tables  (FUN_a00c10c4)
 *
 * Load four byte tables into an HDMI 2.1 input.
 * Name basis: descriptive - index / data registers 0xA4..0xA7
 *
 * Matching notes
 * --------------
 * FUN_a00c10c4 (leon2s 0xa00c10c4-0xa00c12d8), flags -mcpu=v8 -Os -g.
 * Source form: unsigned short index; the third block's index is a separate unsigned short variable (j).
 */
extern unsigned char hdcp_rx_hdmi_hdcp2_bytes[];
extern void hdmi_rx21_reg_update_bits(unsigned char, unsigned short, unsigned char, unsigned char);
extern void hdmi_rx21_reg_write8(unsigned char, unsigned short, unsigned char);

#define HDCP2_VALUE_LENGTH 0x10                 /* bytes of the first table */
#define HDCP2_TABLE_LENGTH 0x20a                /* bytes of the second table */
#define HDCP2_FIXED_LENGTH 11                   /* bytes of hdcp_rx_hdmi_hdcp2_bytes */
#define HDCP2_EXTRA_LENGTH 0x140                /* bytes of the last table */

/*
 * Load the copy-protection tables of the second protection scheme into HDMI 2.1 receiver `port`; the HDMI 2.0
 * and DisplayPort receivers have twins (hdcp_rx_hdmi_load_hdcp2_tables, hdcp_rx_dp_load_hdcp2_tables).
 *
 * First bit 4 of register 0x40 is set. Every table is written through an index: register 0xA6 selects the
 * table, then for each byte the index goes to 0xA5 (low byte) and 0xA4 (high byte) and the byte to 0xA7:
 *   select 0x30: the 16 bytes of value
 *   select 9, index 1: the two bytes 0 and 1
 *   select 0x0A: the 0x20A bytes of table from index 0, then the 11 bytes of hdcp_rx_hdmi_hdcp2_bytes from
 *                index 0x20A
 *   select 0x20: the 0x140 bytes of extra
 * Called from InitHDCP for ports 0 and 1.
 *
 *   value  HDCP2_VALUE_LENGTH bytes
 *   table  HDCP2_TABLE_LENGTH bytes
 *   param_4  not used
 *   extra  HDCP2_EXTRA_LENGTH bytes
 */
void hdcp_rx_hdmi21_load_hdcp2_tables(unsigned char port, unsigned char *value, unsigned char *table, unsigned char *param_4, unsigned char *extra)
{
    unsigned short i, j;

    hdmi_rx21_reg_update_bits(port, 0x40, 0x10, 1);
    hdmi_rx21_reg_write8(port, 0xa6, 0x30);
    for (i = 0; i < HDCP2_VALUE_LENGTH; i++) {
        hdmi_rx21_reg_write8(port, 0xa5, i);
        hdmi_rx21_reg_write8(port, 0xa4, i >> 8);
        hdmi_rx21_reg_write8(port, 0xa7, value[i]);
    }
    hdmi_rx21_reg_write8(port, 0xa6, 9);
    hdmi_rx21_reg_write8(port, 0xa4, 0);
    hdmi_rx21_reg_write8(port, 0xa5, 1);
    hdmi_rx21_reg_write8(port, 0xa7, 0);
    hdmi_rx21_reg_write8(port, 0xa7, 1);
    hdmi_rx21_reg_write8(port, 0xa6, 0xa);
    for (i = 0; i < HDCP2_TABLE_LENGTH; i++) {
        hdmi_rx21_reg_write8(port, 0xa5, i);
        hdmi_rx21_reg_write8(port, 0xa4, i >> 8);
        hdmi_rx21_reg_write8(port, 0xa7, table[i]);
    }
    hdmi_rx21_reg_write8(port, 0xa6, 0xa);
    for (i = 0; i < HDCP2_FIXED_LENGTH; i++) {
        j = i + HDCP2_TABLE_LENGTH;
        hdmi_rx21_reg_write8(port, 0xa5, j);
        hdmi_rx21_reg_write8(port, 0xa4, j >> 8);
        hdmi_rx21_reg_write8(port, 0xa7, hdcp_rx_hdmi_hdcp2_bytes[i]);
    }
    hdmi_rx21_reg_write8(port, 0xa6, 0x20);
    for (i = 0; i < HDCP2_EXTRA_LENGTH; i++) {
        hdmi_rx21_reg_write8(port, 0xa5, i);
        hdmi_rx21_reg_write8(port, 0xa4, i >> 8);
        hdmi_rx21_reg_write8(port, 0xa7, extra[i]);
    }
}
