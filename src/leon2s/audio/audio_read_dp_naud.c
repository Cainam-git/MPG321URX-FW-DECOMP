/* audio_read_dp_naud  (FUN_a008b850)
 *
 * Return the audio N value (Naud) of a DP receiver, never 0.
 *   port: DP receiver 0/1
 * Returns: Naud (1 when 0)
 * Name basis: derived - 24-bit regs 0x66..0x68; divisor in audio_calc_dp_sample_rate
 *
 * Matching notes
 * --------------
 * leon2s FUN_a008b850 @ 0xa008b850 (-mcpu=v8 -Os -g).
 * Source form: the port is masked once; each byte is masked after the read.
 */
extern unsigned int dp_reg_read8(unsigned int param_1, unsigned short param_2);

/*
 * Return the audio N value (Naud) of a DP receiver: registers 0x68, 0x67 and 0x66 as the high, middle and low
 * byte. A value of 0 is returned as 1, so the caller audio_calc_dp_sample_rate can divide by it.
 *   port: DP receiver 0 or 1
 */
unsigned int audio_read_dp_naud(unsigned int port)
{
    unsigned int naud;

    port = port & 0xff;
    naud = dp_reg_read8(port, 0x68) & 0xff;
    naud = (naud << 8) | (dp_reg_read8(port, 0x67) & 0xff);
    naud = (naud << 8) | (dp_reg_read8(port, 0x66) & 0xff);
    if (naud == 0)
        naud = 1;
    return naud;
}
