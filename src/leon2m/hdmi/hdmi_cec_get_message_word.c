/* hdmi_cec_get_message_word  (FUN_a00fcdd8)
 *
 * Return the four stored CEC message bytes as one word.
 * Returns: word
 * Name basis: descriptive - bytes at 0xA802C978
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00fcdd8 @ 0xa00fcdd8, flags -mcpu=v8 -O3 -g.
 */
extern unsigned char hdmi_cec_rx_word[4];

/*
 * Return the four bytes kept from the last received message of code 0x87 (the code and the three bytes after
 * it) as one word, byte 0 lowest. Called only by hdmi_cec_api_get_message_word.
 */
unsigned int hdmi_cec_get_message_word(void)
{
    return hdmi_cec_rx_word[0] + (hdmi_cec_rx_word[1] << 8) + (hdmi_cec_rx_word[2] << 16) + (hdmi_cec_rx_word[3] << 24);
}
