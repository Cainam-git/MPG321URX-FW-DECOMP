/* hdmi_tx_fill_packet_defaults  (FUN_a00a9380)
 *
 * Fill an 11-byte packet record with fixed values for one of two modes.
 *   flag: record
 *   packet: byte 0x127 of the DP input record; 1 gives byte 3 = 0x84, any other value 0xC4
 * Name basis: descriptive - bytes 0x7F, 0xC0, .., byte 3 = 0x84 / 0xC4; caller CONV2HDMITX_UpdatePacket
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00a9380, flags -mcpu=v8 -Os -g.
 * Source form: Ghidra's stores are kept in the firmware's order (bytes 0, 1, 2, 4, 5, 7, 9, 6, 8, then 3 and 10).
 */
/*
 * Fill the 11-byte VTEM packet record with fixed values. Bytes 0..9 are always the same except byte 3; the
 * last two bytes depend on `flag`:
 *   flag 1:       byte 3 = 0x84, byte 10 = 1
 *   any other:    byte 3 = 0xC4, byte 10 = 0
 * Called by CONV2HDMITX_UpdatePacket, which passes byte 0x127 of the DP input record as `flag` and then hands
 * the record to hdmi_tx_update_vtem_packet.
 *   flag:   byte 0x127 of the DP input record
 *   packet: the 11 bytes to fill
 */
void hdmi_tx_fill_packet_defaults(unsigned char flag, unsigned char *packet)

{
  *packet = 0x7f;
  packet[1] = 0xc0;
  packet[2] = 0;
  packet[4] = 0;
  packet[5] = 1;
  packet[7] = 1;
  packet[9] = 4;
  packet[6] = 0;
  packet[8] = 0;
  if (flag == '\x01') {
    packet[3] = 0x84;
    packet[10] = 1;
  }
  else {
    packet[3] = 0xc4;
    packet[10] = 0;
  }
}
