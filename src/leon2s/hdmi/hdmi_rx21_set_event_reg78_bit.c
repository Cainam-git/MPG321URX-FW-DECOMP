/* hdmi_rx21_set_event_reg78_bit  (FUN_a00a0b98)
 *
 * Set or clear one bit of event register 0x78 of an HDMI 2.1 receiver.
 *   port: receiver
 *   bit
 *   on: 1 = set
 * Note: Bits 24..31 of the register are written as 0 on every call.
 * Name basis: descriptive - DRV_HDMI_Setup_IntIRQ_Events sets bits 0x10, 0x15, 0x12, 0xD and 0x11;
 *   hdmi_rx21_service_sync_events clears 0x10, the SPD and audio InfoFrame callbacks clear 0x11 and 0x12
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00a0b98, flags -mcpu=v8 -Os -g (section default). Returns void (the firmware leaves %i0 = port).
 */
/* Register block addresses of an HDMI 2.1 receiver (13 words per receiver, table at 0xA807DB00). */
struct rx21_reg_blocks {
    unsigned int *block0;               /* 0xCE009000 (+0x1000 for receiver 1) */
    unsigned char blocks_1_to_12[0x30];
};
extern struct rx21_reg_blocks hdmi_rx21_reg_blocks[];

#define EVENT_REG_78 0x1e               /* word index of byte offset 0x78 in register block 0 */

/*
 * Set or clear one bit of the word at byte offset 0x78 of register block 0 of receiver `port`. Bits 24..31 of
 * the word are written as 0 in both cases. Called by DRV_HDMI_Setup_IntIRQ_Events,
 * hdmi_rx21_service_sync_events and the packet callbacks hdmi_rx21_on_spd_packet and
 * hdmi_rx21_on_audio_infoframe (which clear bits 0x11 and 0x12).
 *   port  HDMI 2.1 receiver 0/1
 *   bit   bit number
 *   on    1 = set the bit; any other value clears it
 */
void hdmi_rx21_set_event_reg78_bit(unsigned char port, unsigned int bit, unsigned char on)
{
    if (on == 1)
        hdmi_rx21_reg_blocks[port].block0[EVENT_REG_78] = (hdmi_rx21_reg_blocks[port].block0[EVENT_REG_78] & 0xffffff) | (on << bit);
    else
        hdmi_rx21_reg_blocks[port].block0[EVENT_REG_78] = hdmi_rx21_reg_blocks[port].block0[EVENT_REG_78] & ~(1 << bit) & 0xffffff;
}
