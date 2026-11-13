/* dp_mst_crc8_data  (FUN_a00d9988)
 *
 * Compute the 8-bit checksum of a message body.
 * Returns: checksum
 * Name basis: derived - bitwise CRC over the data bytes; appended to each chunk
 *
 * Matching notes
 * --------------
 * FUN_a00d9988 (leon2s 0xa00d9988-0xa00d9a78, 240 bytes), flags -mcpu=v8 -Os -g.
 * Source form: crc is an unsigned short updated in place ('crc <<= 1; ...; if (crc & 0x100) crc ^= 0xd5;'), the
 * second loop decrements its counter after the shift.
 */
/*
 * 8-bit checksum over `length` bytes of the ring buffer `buf`, starting at byte `pos` and wrapping to 0 at
 * `size`; returns the low byte of the result.
 *
 * Bits are taken most significant first. The checksum starts at 0; for each bit it is shifted left by one with
 * the data bit or-ed in, and when bit 8 is then set it is XORed with 0xD5. After the data, eight zero bits are
 * shifted in the same way. Called by dp_mst_write_chunk_body (over the body bytes written to the registers)
 * and by dp_mst_queue_clear_payload_table_request (over the first byte of a record, pos 0, size 0x30).
 */
unsigned char dp_mst_crc8_data(unsigned char *buf, unsigned char length, unsigned short pos, unsigned short size)
{
  unsigned char mask = 0x80;
  unsigned char shift = 7;
  unsigned short bits_left = length * 8;
  unsigned short crc = 0;
  while (bits_left != 0)
  {
    crc <<= 1;
    crc |= (buf[pos] & mask) >> shift;
    bits_left--;
    mask >>= 1;
    shift--;
    if (mask == 0)
    {
      pos = (pos + 1) % size;
      mask = 0x80;
      shift = 7;
    }
    if (crc & 0x100)
      crc ^= 0xd5;
  }

  bits_left = 8;
  while (bits_left != 0)
  {
    crc <<= 1;
    bits_left--;
    if (crc & 0x100)
      crc ^= 0xd5;
  }

  return crc;
}
