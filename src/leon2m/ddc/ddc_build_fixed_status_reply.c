/* ddc_build_fixed_status_reply  (FUN_a00cfa14)
 *
 * Fill a fixed DDC/CI reply carrying the value 0x36F.
 *   reply: reply buffer
 * Note: Uncalled copy of the reply built by the 0xE1 arm of ddc_apply_maker_vcp_set.
 * Name basis: descriptive - reply bytes 6E 87 02 03 6F 03 FF 96 FF
 *
 * Matching notes
 * --------------
 * Flags -mcpu=v8 -O2 -g (section default). Nothing in the image calls this routine.
 * Source form: the reply bytes 3 and 4 are written from the unsigned short value (v >> 8 and v), as in
 * ddc_apply_maker_vcp_set: the firmware keeps 0x36f in the register for the byte store of reply[4]. The call at the end
 * is a tail call (the return address is handed on).
 */
#define DDC_ADDRESS        0x6e         /* reply byte 0 (docs/MAP.md: the DDC/CI address) */
#define DDC_CHECKSUM_SEED  0x50         /* first value of the reply XOR checksum */
#define DDC_LENGTH_BYTE(n) ((n) + 0x80) /* reply byte 1: 0x80 + the number of bytes that follow it */
#define CEC_PWM_OFF_KNEE   0x36f        /* the value in reply bytes 3 and 4 */

extern void ddc_set_checksum_byte(unsigned char);

/*
 * Fill the reply buffer with the fixed 9-byte reply 6E 87 02 03 6F 03 FF 96 FF (bytes 3 and 4 are the high and
 * low byte of CEC_PWM_OFF_KNEE), then restart the reply checksum at DDC_CHECKSUM_SEED.
 * ddc_apply_maker_vcp_set writes the same reply inline for the factory switch E1 A7 13 with value 1 (CEC PWM Adjust
 * on).
 */
void ddc_build_fixed_status_reply(unsigned char *reply)
{
  unsigned short value;

  value = CEC_PWM_OFF_KNEE;
  reply[0] = DDC_ADDRESS;
  reply[1] = DDC_LENGTH_BYTE(7);
  reply[2] = 2;
  reply[3] = value >> 8;
  reply[4] = value;
  reply[5] = 3;
  reply[6] = 0xff;
  reply[7] = 0x96;
  reply[8] = 0xff;
  ddc_set_checksum_byte(DDC_CHECKSUM_SEED);
}
