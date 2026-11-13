/* dp_set_port_setting_11e  (CONV2HDMITX_UpdateInterface_2)
 *
 * Write a setting to register 0x21d of a port and print it, only when record byte 0x11e is non-zero.
 * Name basis: descriptive - byte 0x11E of the port's 300-byte record; prints the value and the port
 *
 * Matching notes
 * --------------
 * CONV2HDMITX_UpdateInterface_2 (leon2s, 0xa00ad38c-0xa00ad3e0, 84 bytes), flags -mcpu=v8 -Os -g.
 * Source form: the print is the last statement of the if body and is a sibling call.
 */
struct dp_input_record {
    unsigned char before_0x11e[0x11e];
    unsigned char byte_0x11e;                /* the setting this routine tests */
    unsigned char after_0x11e[300 - 0x11f];
};
extern struct dp_input_record dp_input_records[];    /* one 300-byte record per port */
extern void dp_reg_write8(unsigned int, unsigned short, unsigned char);
extern int dbg_printf(const char *, ...);

/*
 * Does nothing unless byte 0x11e of the port's record is non-zero. Then it writes
 * (setting | 0x80) to register 0x21d of the port and prints the setting and the port.
 *   port:    port number, index of the 300-byte record
 *   setting: value for register 0x21d (bit 7 is added)
 */
void dp_set_port_setting_11e(unsigned char port, unsigned char setting)
{
    if (dp_input_records[port].byte_0x11e != 0) {
        dp_reg_write8(port, 0x21d, setting | 0x80);
        dbg_printf("\033[0;38mNTL LCnt %d (link %d)\r\n\033[m", setting, port);
    }
}
