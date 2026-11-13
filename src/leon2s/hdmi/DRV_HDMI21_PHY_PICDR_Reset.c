/* DRV_HDMI21_PHY_PICDR_Reset  (DRV_HDMI21_PHY_PICDR_Reset)
 *
 * Reset the clock recovery of the HDMI 2.1 lanes, by method chosen by link rate.
 *   port: PHY
 * Name basis: proven - original name printed: 'DRV_HDMI21_PHY_PICDR_Reset'
 *
 * Matching notes
 * --------------
 * leon2s DRV_HDMI21_PHY_PICDR_Reset @ 0xa0080244, flags -mcpu=v8 -Os -g.
 * Source form: the function name is a separate static const char[] (the firmware keeps it as its own
 * .rodata object); both callees are tail calls.
 */
#define HDMI_MSG_HDMI21 0x800   /* debug message bit: '[HDMI21]' lines (dbg_hdmi_message_flags) */
#define LTS_FRL_RATE_IN_PHY 2   /* byte +2 of a 0xb0-byte link-training record ("u8FRL_Rate_SetInPhy") */

extern unsigned int dbg_hdmi_message_flags;
extern void DRV_HDMI21_PHY_INV_PICDR_Reset(unsigned char port);
extern int dbg_printf(const char *, ...);
extern void hdmi_rx21_pulse_lane_bit4_all(unsigned char port);
extern unsigned char hdmi_rx21_lts_records[];

static const char fn_[] = "DRV_HDMI21_PHY_PICDR_Reset";   /* function name kept as a separate .rodata object by the firmware */

/* Resets the clock recovery of the four lanes of an HDMI 2.1 receiver PHY. The method depends on the
 * link-rate byte the link training stored for this receiver: above 3 it pulses bit 4 of the lane
 * registers (hdmi_rx21_pulse_lane_bit4_all), otherwise it runs DRV_HDMI21_PHY_INV_PICDR_Reset.
 *   port: PHY page, 2 or 3 (receiver 0 or 1); any other value returns at once */
void DRV_HDMI21_PHY_PICDR_Reset(unsigned char port)
{
    unsigned char port_masked;
    unsigned char receiver;   /* receiver number, index of the link-training record */
    
    if ((dbg_hdmi_message_flags & HDMI_MSG_HDMI21) != 0) {
        dbg_printf("[HDMI21]: %s\n\n", fn_);
    }
    
    port_masked = port & 0xff;
    receiver = 0;
    if (port_masked == 2) {

    } else if (port_masked == 3) {
        receiver = 1;
    } else {
        return;
    }
    
    if (hdmi_rx21_lts_records[receiver * 0xb0 + LTS_FRL_RATE_IN_PHY] > 3) {
        hdmi_rx21_pulse_lane_bit4_all(port);
        return;
    } else {
        DRV_HDMI21_PHY_INV_PICDR_Reset(port);
        return;
    }
}
