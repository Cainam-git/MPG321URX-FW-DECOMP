/* hdmi_rx21_on_audio_infoframe  (FUN_a00a146c)
 *
 * Mark the audio InfoFrame received and read it when allowed.
 *   port: receiver
 * Name basis: derived - packet-event callback; calls hdmi_rx21_read_audio_infoframe into record +0xBC
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00a146c, flags -mcpu=v8 -Os -g (section default).
 * Source form: the stores are in ascending source order e6, e7 (the firmware emits e7 first and e6 in the bne delay
 * slot); the record is a flat byte array with an integer index (a struct record gives the other add operand order).
 */
#define RX21_AUDIO_INFOFRAME  0xbc      /* audio InfoFrame block of the 400-byte record; ends in three status bytes */
#define RX21_AUDIO_IF_SEEN    0xe6
#define RX21_AUDIO_IF_UPDATE  0xe7
#define RX21_AUDIO_IF_HOLD    0xe8

extern unsigned char hdmi_rx21_input_records[];
extern void hdmi_rx21_read_audio_infoframe(unsigned char, unsigned char *);
extern void hdmi_rx21_set_event_reg78_bit(unsigned char, int, int);

/*
 * Packet callback for the audio InfoFrame of receiver `port` (event 0x12, slot 2 in
 * hdmi_rx21_service_packet_events): set seen and update, read the InfoFrame with hdmi_rx21_read_audio_infoframe
 * unless hold is set, then clear bit 0x12 of the event word 0x78.
 *   port  HDMI 2.1 receiver 0/1
 */
void hdmi_rx21_on_audio_infoframe(unsigned char port)
{
  unsigned int index = port * 400;
  unsigned char hold;

  hdmi_rx21_input_records[index + RX21_AUDIO_IF_SEEN] = 1;
  hdmi_rx21_input_records[index + RX21_AUDIO_IF_UPDATE] = 1;
  hold = hdmi_rx21_input_records[index + RX21_AUDIO_IF_HOLD];
  if (hold == 0)
    hdmi_rx21_read_audio_infoframe(port, &hdmi_rx21_input_records[index + RX21_AUDIO_INFOFRAME]);
  hdmi_rx21_set_event_reg78_bit(port, 0x12, 0);
}
