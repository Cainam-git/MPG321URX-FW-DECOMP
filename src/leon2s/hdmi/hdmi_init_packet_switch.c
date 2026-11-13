/* hdmi_init_packet_switch  (FUN_a00a8844)
 *
 * Load the default packet-forwarding selections of an HDMI 2.0 receiver.
 *   port: HDMI 2.0 receiver
 * Name basis: derived - HDMI20RX2PacketSwitch for selections 0..2 with the same defaults; caller
 *   hdmi_init_receivers
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00a8844, flags -mcpu=v8 -Os -g.
 * Source form: both small buffers are 4-byte arrays zero-initialised with '= { 0 }' and then one byte store
 * each (a '{0, 0x10}' initialiser becomes a memcpy from .rodata); lib_memcpy copies bytes and is declared
 * returning void * (a void declaration moves 'mov %l0,%o0' out of the call delay slot). The third buffer is
 * 8 bytes and receives 4 bytes from the default table.
 */
extern unsigned char hdmi_packet_switch_defaults[];
extern void HDMI20RX2PacketSwitch(unsigned char, unsigned char, unsigned char *);
extern void *lib_memcpy(void *, const void *, unsigned int); /* memcpy: its asm copies via %o5 and returns %o0 = dest */

/*
 * Load the default packet-forwarding selections 0, 1 and 2 into an HDMI 2.0 receiver:
 * selection 0 = {0, 0x10, 0, 0}, selection 1 = the 4 bytes of hdmi_packet_switch_defaults,
 * selection 2 = {0x40, 0, 0, 0}.
 *   port: HDMI 2.0 receiver
 */
void hdmi_init_packet_switch(unsigned char port)
{
  unsigned char selection0[4] = { 0 };
  unsigned char selection2[4] = { 0 };
  unsigned char selection1[8];

  selection0[1] = 0x10;
  selection2[0] = 0x40;

  lib_memcpy(selection1, hdmi_packet_switch_defaults, 4);
  HDMI20RX2PacketSwitch(port, 0, selection0);
  HDMI20RX2PacketSwitch(port, 1, selection1);
  HDMI20RX2PacketSwitch(port, 2, selection2);
}
