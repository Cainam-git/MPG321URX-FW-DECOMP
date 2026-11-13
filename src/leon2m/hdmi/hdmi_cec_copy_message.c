/* hdmi_cec_copy_message  (FUN_a00fce0c)
 *
 * Copy the five stored CEC message bytes to a buffer.
 * Name basis: descriptive - bytes at 0xA802C968
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00fce0c @ 0xa00fce0c, flags -mcpu=v8 -O3 -g.
 * Source form: five plain byte assignments from an array declared with five bytes.
 */
extern unsigned char hdmi_cec_rx_message[5];

/*
 * Copy the five bytes kept from the last received message of code 0x47 (the code and four bytes) to `dest`.
 * Called only by hdmi_cec_api_copy_message.
 */
void hdmi_cec_copy_message(unsigned char *dest)
{
    dest[0] = hdmi_cec_rx_message[0];
    dest[1] = hdmi_cec_rx_message[1];
    dest[2] = hdmi_cec_rx_message[2];
    dest[3] = hdmi_cec_rx_message[3];
    dest[4] = hdmi_cec_rx_message[4];
}
