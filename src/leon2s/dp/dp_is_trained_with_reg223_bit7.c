/* dp_is_trained_with_reg223_bit7  (FUN_a00ad320)
 *
 * Return whether port setting 0x115 is on, the link is trained and bit 7 of register 0x223 is set.
 * Returns: 0 or 1
 * Name basis: descriptive - setting byte 0x115 of the port record, dp_is_link_trained, receiver register 0x223
 *   bit 7; result published as a port flag
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00ad320 @ 0xa00ad320, flags -mcpu=v8 -Os -g.
 * Source form: the record array is addressed as bytes, port * 300 + 0x115.
 */
extern unsigned int dp_is_link_trained(unsigned char port);
extern unsigned int dp_reg_read8(unsigned char port, unsigned short reg);
extern unsigned char dp_input_records[];            /* 300-byte record per port */

/*
 * Return 1 when byte 0x115 of the port's record is non-zero, dp_is_link_trained(port) is 1 and bit 7 of
 * receiver register 0x223 is set; otherwise 0. Callers: dp_update_port_status_flags, dp_update_reg46_bit3.
 *   port: DP receiver
 */
unsigned char dp_is_trained_with_reg223_bit7(unsigned char port)
{
    unsigned char result;

    port = port & 0xff;
    result = 0;
    if (dp_input_records[port * 300 + 0x115] == 0) {
        return result;
    }
    if ((dp_is_link_trained(port) & 0xff) == 1) {
        if ((dp_reg_read8(port, 0x223) & 0x80) != 0) {
            result = 1;
        }
    }
    return result;
}
