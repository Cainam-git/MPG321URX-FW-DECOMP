/* hdmi_tx_copy_audio_info_from_dp  (FUN_a009332c)
 *
 * Build the HDMI TX audio InfoFrame from the audio data of a DP input.
 *   src: DP receiver
 *   dst: HDMI TX port
 * Name basis: derived - header 0x84 1 0x0A; payload read from DP receiver regs 0x60..0x6F; checksum
 *
 * Matching notes
 * --------------
 * leon2s FUN_a009332c @ 0xa009332c-0xa00934c0 (-mcpu=v8 -Os -g).
 * dp_reg_read8 returns a value masked with 0xff (unsigned char, as in its other matched users); the packed
 * byte is built in three statements on the u8 variable i.
 */
extern unsigned char dp_reg_read8(unsigned char, unsigned short);
extern void dp_reg_write8(unsigned char, unsigned short, unsigned char);
extern void hdmi_tx_reg_write8(unsigned int, unsigned int, unsigned short, unsigned char);
extern void hdmi_tx_reg_update_bits(unsigned int, unsigned int, unsigned short, unsigned int, unsigned int);

/*
 * Fill the 0x180 packet slot of HDMI TX 'dst' (bank 0) from the registers of DP receiver 'src'.
 *
 * Header registers 0x180..0x182 get 0x84, 1 and 10. Registers 0x11E..0x121 get DP receiver registers 0x6B..0x6E
 * and register 0x122 gets DP register 0x6F rearranged (v << 4) | ((v >> 3) & 0xe) | (v >> 7). With the enable
 * bits 5..4 of register 0x13E cleared, nine bytes are then read: for i = 0..8 the value (DP register 0x60 & 0xE0)
 * + i is written to DP register 0x60 and DP register 0x62 is read; the result goes to HDMI TX register 0x184 + i.
 * The sum of these bytes, started at 0x8F, is negated and
 * written to register 0x183. Finally the enable bits are set again.
 */
void hdmi_tx_copy_audio_info_from_dp(unsigned int src, unsigned char dst)
{
    unsigned char i;
    unsigned char v;
    unsigned char r;
    unsigned char sum;

    hdmi_tx_reg_write8(dst, 0, 0x180, 0x84);
    hdmi_tx_reg_write8(dst, 0, 0x181, 1);
    hdmi_tx_reg_write8(dst, 0, 0x182, 10);
    sum = 0x8f;
    for (i = 0; i < 4; i++)
        hdmi_tx_reg_write8(dst, 0, i + 0x11e, dp_reg_read8(src, i + 0x6b));
    r = dp_reg_read8(src, 0x6f);
    v = r;
    i = r << 4;
    i |= (v >> 3) & 0xe;
    i |= v >> 7;
    hdmi_tx_reg_write8(dst, 0, 0x122, i);
    hdmi_tx_reg_update_bits(dst, 0, 0x13e, 0x30, 0);
    v = dp_reg_read8(src, 0x60) & 0xe0;
    for (i = 0; i <= 8; i++) {
        dp_reg_write8(src, 0x60, v + i);
        r = dp_reg_read8(src, 0x62);
        hdmi_tx_reg_write8(dst, 0, i + 0x184, r);
        sum += r;
    }
    sum = -sum;
    hdmi_tx_reg_write8(dst, 0, 0x183, sum);
    hdmi_tx_reg_update_bits(dst, 0, 0x13e, 0x30, 1);
}
