/* hdmi_clear_packet_status  (FUN_a008fa30)
 *
 * Clear the latched packet status registers of an HDMI receiver.
 *   port: HDMI 2.0 receiver 0/1
 * Name basis: derived - 0xFF to regs 0x72, 0x73, 0x74, 0x84 (the bits the status poll tests)
 *
 * Matching notes
 * --------------
 * leon2s FUN_a008fa30 @ 0xa008fa30 (-mcpu=v8 -Os -g)
 * Source form: the routine keeps parameters 2 to 6 of the decompiled form; the last write passes parameters 4 to
 * 6 on (the firmware leaves its argument registers as they were).
 */

/* Latched status registers that hdmi_poll_rx_status reads; a bit is cleared by writing it back as 1. */
#define RX_STATUS_72  0x72
#define RX_STATUS_73  0x73
#define RX_STATUS_74  0x74
#define RX_STATUS_84  0x84

extern void hdmi_reg_write8();

/* Called on the way from STABLE to READY, so that the READY polls see only what arrives from then on.
   Every bit of the four status registers is written back as 1. */
void hdmi_clear_packet_status(unsigned char port, unsigned int param_2, unsigned int param_3, unsigned int param_4,
                              unsigned int param_5, unsigned int param_6)
{
    hdmi_reg_write8(port, RX_STATUS_72, 0xff);
    hdmi_reg_write8(port, RX_STATUS_73, 0xff);
    hdmi_reg_write8(port, RX_STATUS_74, 0xff);
    hdmi_reg_write8(port, RX_STATUS_84, 0xff, param_4, param_5, param_6);
}
