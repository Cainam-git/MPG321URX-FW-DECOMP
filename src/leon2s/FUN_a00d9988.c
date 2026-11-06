/* FUN_a00d9988 (leon2s 0xa00d9988-0xa00d9a78, 240 bytes), flags -mcpu=v8 -Os -g.
 * 8-bit CRC (polynomial 0xd5) over len bytes of the ring buffer buf, starting at pos (wraps at size), most
 * significant bit first; crc starts at 0. Per bit: crc is shifted left by one with the data bit or-ed in, and
 * XORed with 0xd5 when bit 8 is set. Then eight more zero bits are shifted in the same way. Returns the low byte.
 * Source form: crc is an unsigned short updated in place ('crc <<= 1; ...; if (crc & 0x100) crc ^= 0xd5;'), the
 * second loop decrements its counter after the shift.
 */
unsigned char FUN_a00d9988(unsigned char *buf, unsigned char len, unsigned short pos, unsigned short size)
{
  unsigned char mask = 0x80;
  unsigned char sh = 7;
  unsigned short n = len * 8;
  unsigned short crc = 0;
  unsigned int t;
  while (n != 0)
  {
    crc <<= 1;
    crc |= (buf[pos] & mask) >> sh;
    n--;
    mask >>= 1;
    sh--;
    if (mask == 0)
    {
      pos = (pos + 1) % size;
      mask = 0x80;
      sh = 7;
    }
    if (crc & 0x100)
      crc ^= 0xd5;
  }

  n = 8;
  while (n != 0)
  {
    crc <<= 1;
    n--;
    if (crc & 0x100)
      crc ^= 0xd5;
  }

  return crc;
}
