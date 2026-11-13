/* hdmi_rx21_get_hdmi_mode_copy  (FUN_a00a2994)
 *
 * Return the HDMI (not DVI) mode flag of an HDMI 2.1 input.
 *   receiver: HDMI 2.1 receiver 0/1
 * Returns: 1 for HDMI
 * Note: Identical copy of hdmi_rx21_get_hdmi_mode.
 * Name basis: proven - record byte +0x18 = 'HDMI Mode' of the mode info print; caller
 *   CONV2HDMITX_UpdateInterface
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00a2994 @ 0xa00a2994, flags -mcpu=v8 -Os -g.
 */
/* One HDMI 2.1 input record (400 bytes per receiver, table at 0xA807D7E0). Only the field read here is named. */
struct rx21_record {
    unsigned char before[24];
    unsigned char hdmi_mode;                  /* +0x18 */
    unsigned char after[400 - 24 - 1];
};
extern struct rx21_record hdmi_rx21_input_records[];

/* Byte +0x18 of the input record: the "HDMI Mode" value of the mode info print (1 = HDMI). receiver is 0 or 1. */
unsigned char hdmi_rx21_get_hdmi_mode_copy(unsigned int receiver)
{
    return hdmi_rx21_input_records[receiver & 0xff].hdmi_mode;
}
