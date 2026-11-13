/* hdmi_rx21_init_packet_switch  (FUN_a00a8694)
 *
 * Load the default packet-forwarding selections of an HDMI 2.1 receiver.
 *   port: HDMI 2.1 receiver
 * Name basis: derived - HDMI21RX2PacketSwitch for selections 0..2 with defaults (table 0xA00B4DC8); caller
 *   hdmi_rx21_init_port
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00a8694, flags -mcpu=v8 -Os -g.
 * Same code as hdmi_init_packet_switch with the HDMI 2.1 routine called.
 * Source form: the two small buffers are 4-byte arrays zero-initialised with '= { 0 }' and then one byte store
 * each; the third buffer is 8 bytes and receives 4 bytes from the default table through lib_memcpy.
 */
extern unsigned char hdmi_packet_switch_defaults[];
extern void HDMI21RX2PacketSwitch(unsigned char, unsigned char, unsigned char *);
extern void *lib_memcpy(void *, const void *, unsigned int);

/*
 * Load the default packet-forwarding selections 0, 1 and 2 into an HDMI 2.1 receiver:
 * selection 0 = {0, 0x10, 0, 0}, selection 1 = the 4 bytes of hdmi_packet_switch_defaults,
 * selection 2 = {0x40, 0, 0, 0}.
 *   port: HDMI 2.1 receiver
 */
void hdmi_rx21_init_packet_switch(unsigned char port)
{
  unsigned char selection0[4] = { 0 };
  unsigned char selection2[4] = { 0 };
  unsigned char selection1[8];

  selection0[1] = 0x10;
  selection2[0] = 0x40;

  lib_memcpy(selection1, hdmi_packet_switch_defaults, 4);
  HDMI21RX2PacketSwitch(port, 0, selection0);
  HDMI21RX2PacketSwitch(port, 1, selection1);
  HDMI21RX2PacketSwitch(port, 2, selection2);
}
