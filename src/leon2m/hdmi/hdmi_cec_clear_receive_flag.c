/* hdmi_cec_clear_receive_flag  (FUN_a00fc318)
 *
 * Acknowledge the CEC receive flag and clear the stored state.
 * Name basis: descriptive - 1 to 0xCF012034, byte at 0xA802C97C cleared; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00fc318 @ 0xa00fc318, flags -mcpu=v8 -O3 -g.
 */
#define CEC_STATUS            (*(volatile unsigned int *)0xcf012034)
#define CEC_STATUS_RX_READY   0x01      /* written back to say that the message has been read */
extern unsigned char hdmi_cec_rx_flags;

/* Write CEC_STATUS_RX_READY back to CEC_STATUS and clear the kept-message bits. Nothing calls this routine. */
void hdmi_cec_clear_receive_flag(void)
{
    CEC_STATUS = CEC_STATUS_RX_READY;
    hdmi_cec_rx_flags = 0;
}
