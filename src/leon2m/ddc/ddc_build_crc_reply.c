/* ddc_build_crc_reply  (FUN_a00cfa68)
 *
 * Fill a DDC/CI reply with the CRC-16 of four request bytes.
 *   request
 *   reply: reply buffer
 * Note: Uncalled; reply 6E 83 02 crc_hi crc_lo.
 * Name basis: descriptive - lib_crc16_ccitt_update over request bytes 4..7
 *
 * Matching notes
 * --------------
 * Flags -mcpu=v8 -O3 -g. Nothing in the image calls this routine.
 * Source form: the stores to the reply are in ascending offset order; lib_crc16_ccitt_update takes (unsigned
 * char, unsigned short) and returns unsigned short (the callee ends with sll/srl 16 of its second argument); the
 * last call is a tail call.
 */
#define DDC_ADDRESS        0x6e         /* reply byte 0 (docs/MAP.md: the DDC/CI address) */
#define DDC_CHECKSUM_SEED  0x50         /* first value of the reply XOR checksum */
#define DDC_LENGTH_BYTE(n) ((n) + 0x80) /* reply byte 1: 0x80 + the number of bytes that follow it */

extern void ddc_set_checksum_byte(unsigned char);
extern unsigned short lib_crc16_ccitt_update(unsigned char, unsigned short);

/*
 * Answer with the CRC of four request bytes: reply = 6E 83 02 crc_high crc_low, the CRC taken over request bytes
 * 4..7 (lib_crc16_ccitt_update, starting from 0); then restart the reply checksum at DDC_CHECKSUM_SEED.
 * ddc_apply_maker_vcp_set has the same code as a static routine of its own.
 */
void ddc_build_crc_reply(unsigned char *request, unsigned char *reply)
{
  unsigned short crc = 0;
  unsigned char i;

  for (i = 4; i < 8; i++)
    crc = lib_crc16_ccitt_update(request[i], crc);
  reply[0] = DDC_ADDRESS;
  reply[1] = DDC_LENGTH_BYTE(3);
  reply[2] = 2;
  reply[3] = crc >> 8;
  reply[4] = crc;
  ddc_set_checksum_byte(DDC_CHECKSUM_SEED);
}
