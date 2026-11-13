/* hdcp_rx_hdmi_load_hdcp2_tables  (FUN_a00c0f88)
 *
 * Load the four tables (16, 522, 11 and 320 bytes) into an HDMI 2.0 input.
 * Name basis: descriptive - register-port loads
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00c0f88 @ 0xa00c0f88, flags -mcpu=v8 -Os.
 * Source forms: unsigned short loop counters; the register value of 0x309 is built as (v & ~3) | 1 in an unsigned
 * char and then masked with 0xfd, which gives the firmware's bit sequence; the fourth parameter is not read.
 */
extern int hdmi_reg_read8(int, int); // 0xa0fb657c
extern int hdmi_reg_write8(int, int, int); // 0xa0fb65c4
extern unsigned char hdcp_rx_hdmi_hdcp2_bytes[]; // 0xa8078620

#define HDCP2_VALUE_LENGTH 0x10                 /* bytes of the first table */
#define HDCP2_TABLE_LENGTH 0x20a                /* bytes of the second table */
#define HDCP2_FIXED_LENGTH 11                   /* bytes of hdcp_rx_hdmi_hdcp2_bytes */
#define HDCP2_EXTRA_LENGTH 0x140                /* bytes of the last table */

/*
 * Load the four copy-protection tables of the second protection scheme into HDMI 2.0 receiver `port`.
 * Register 0x310 selects the table and register 0x312 takes its bytes one by one:
 *   0x310 = 0x21: the 16 bytes of value
 *   register 0x309 is rewritten with bit 0 set and bit 1 cleared; table bytes go to register 0x30B
 *   0x310 = 0x2D: the 11 bytes of hdcp_rx_hdmi_hdcp2_bytes
 *   0x310 = 0x20: the 0x140 bytes of extra
 * The routine writes the same four tables as hdcp_rx_dp_load_hdcp2_tables (DisplayPort receiver) and the
 * HDMI 2.1 twin. Called from InitHDCP for ports 0 and 1.
 *
 *   port   HDMI 2.0 receiver (0 or 1)
 *   value  HDCP2_VALUE_LENGTH bytes
 *   table  HDCP2_TABLE_LENGTH bytes
 *   param_4  not used
 *   extra  HDCP2_EXTRA_LENGTH bytes
 */
void hdcp_rx_hdmi_load_hdcp2_tables(unsigned int port, unsigned char *value, unsigned char *table, int param_4, unsigned char *extra)
{
    unsigned int receiver;
    unsigned short i;
    int reg309;

    receiver = port & 0xff;
    hdmi_reg_write8(receiver, 0x310, 0x21);
    i = 0;
    do {
        hdmi_reg_write8(receiver, 0x312, value[i]);
        i = i + 1;
    } while (i < HDCP2_VALUE_LENGTH);
    reg309 = hdmi_reg_read8(receiver, 0x309);
    { unsigned char v = (reg309 & ~3) | 1; reg309 = v & 0xfd; }
    hdmi_reg_write8(receiver, 0x309, reg309);
    i = 0;
    do {
        hdmi_reg_write8(receiver, 0x30b, table[i]);
        i = i + 1;
    } while (i < HDCP2_TABLE_LENGTH);
    hdmi_reg_write8(receiver, 0x310, 0x2d);
    i = 0;
    do {
        hdmi_reg_write8(receiver, 0x312, hdcp_rx_hdmi_hdcp2_bytes[i]);
        i = i + 1;
    } while (i < HDCP2_FIXED_LENGTH);
    hdmi_reg_write8(receiver, 0x310, 0x20);
    i = 0;
    do {
        hdmi_reg_write8(receiver, 0x312, extra[i]);
        i = i + 1;
    } while (i < HDCP2_EXTRA_LENGTH);
}
