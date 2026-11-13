/* dp_get_msa_bit3  (FUN_a00ad7c8)
 *
 * Return bit 3 of indirect register 8 when a stream is present.
 * Returns: 0 or 1
 * Name basis: descriptive - index 0x73, data 0x7A
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00ad7c8 @ 0xa00ad7c8, flags -mcpu=v8 -Os -g.
 * Source form: the bit mask is a local "mask = 8". With a literal 8 the single-bit test is folded into a shift and
 * an "and 1"; the firmware keeps the "and" and compare form.
 */
extern unsigned int dp_reg_read8(unsigned char, unsigned short);
extern void dp_reg_write8(unsigned char, unsigned short, unsigned char);
extern unsigned char dp_is_stream_present(unsigned char);

/*
 * Return 0 when dp_is_stream_present(port) is 0. Otherwise write 0 to receiver register 0x70 and 8 to register
 * 0x73, and return bit 3 of register 0x7A. Mailbox command 0xA0 (status byte of input 2..5) replies with it
 * for ports 0 and 1; hdmi_tx_send_avi_infoframe and dp_get_color_format_code also call it.
 *   port: DP receiver
 */
unsigned int dp_get_msa_bit3(unsigned char port)
{
    unsigned int result = 0;
    unsigned int mask = 8;

    if (dp_is_stream_present(port) != 0) {
        dp_reg_write8(port, 0x70, 0);
        dp_reg_write8(port, 0x73, 8);
        result = (dp_reg_read8(port, 0x7a) & mask) != 0;
    }
    return result;
}
