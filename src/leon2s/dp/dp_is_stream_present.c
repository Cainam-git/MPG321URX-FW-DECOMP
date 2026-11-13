/* dp_is_stream_present  (FUN_a00ad784)
 *
 * Return whether a port receives a video stream.
 * Returns: 0 or 1
 * Name basis: derived - bit 6 of register 0x8F and bit 0 of register 0x461
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00ad784 @ 0xa00ad784, flags -mcpu=v8 -Os -g.
 * Source form: return type and result are unsigned char (an unsigned int result gives no final "and").
 */
extern unsigned int dp_reg_read8(unsigned int, unsigned short);
extern unsigned char dp_get_reg461_bit0(unsigned int);

/*
 * Return 1 when bit 6 of receiver register 0x8F is set and bit 0 of register 0x461 (dp_get_reg461_bit0) is
 * set, else 0. Callers: dp_update_port_status_flags, sys_dsc_dec_is_dp_source (for input codes 0x71 / 0x81), dp_get_msa_bit3.
 *   port: DP receiver
 */
unsigned char dp_is_stream_present(unsigned int port)
{
    unsigned char result = 0;
    port = port & 0xff;
    if ((dp_reg_read8(port, 0x8f) & 0x40) != 0) {
        if (dp_get_reg461_bit0(port) != 0)
            result = 1;
        else
            result = 0;
    }
    return result;
}
