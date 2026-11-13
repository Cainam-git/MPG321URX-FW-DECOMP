/* ddc_build_vcp_reply  (FUN_a00cead4)
 *
 * Fill a DDC/CI VCP feature reply for maker code 0xFE with four given value bytes.
 *   reply: reply buffer
 *   byte6: reply byte 6 (maximum high in the standard layout)
 *   byte7: reply byte 7 (maximum low in the standard layout)
 *   byte8: reply byte 8 (current high in the standard layout)
 *   byte9: reply byte 9 (current low in the standard layout)
 * Note: Reply 6E 88 02 00 FE 01 + bytes 6..9; seeds the XOR checksum with 0x50. The caller puts brightness,
 *   contrast and part record bytes in byte 7 and colour values or the input code in byte 9.
 * Name basis: derived - MCCS Get VCP Feature reply layout with the code fixed at 0xFE; only caller
 *   ddc_answer_maker_vcp_get
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00cead4 @ 0xa00cead4, flags -mcpu=v8 -O3 -g.
 * Source form: the stores stand in the firmware's order (byte 9 first, byte 3 last, before the call).
 */
extern void ddc_set_checksum_byte(unsigned char checksum);

/* Reply byte 0 (docs/MAP.md: the DDC/CI address) and the first value of the reply XOR checksum. */
#define DDC_ADDRESS               0x6e
#define DDC_CHECKSUM_SEED         0x50
/* Reply byte 1: 0x80 + the number of bytes that follow it (before the checksum). */
#define DDC_LENGTH_BYTE(n)        ((n) + 0x80)
#define VCP_MAKER                 0xfe          /* the GetVCP code the reply is for (byte 4) */

/*
 * Write a complete 10-byte GetVCP reply for the maker code 0xFE into `reply`:
 *   6E 88 02 00 FE 01 byte6 byte7 byte8 byte9
 * and set the running reply checksum (ddc_set_checksum_byte) to DDC_CHECKSUM_SEED; the caller then adds the
 * checksum and queues the reply.
 *
 *   reply                 the reply buffer
 *   byte6 .. byte9        the four value bytes 6..9
 *
 * Only caller: ddc_answer_maker_vcp_get. It passes brightness, contrast and the part record bytes as byte7 with the
 * other three 0, the colour entry bytes and black levels as byte9 with bytes 6..8 = FF 00 00, and the
 * translated input source as byte9 with 03 01 00.
 */
void ddc_build_vcp_reply(unsigned char *reply, unsigned char byte6, unsigned char byte7, unsigned char byte8,
                 unsigned char byte9)

{
  reply[9] = byte9;
  *reply = DDC_ADDRESS;
  reply[1] = DDC_LENGTH_BYTE(8);
  reply[2] = 2;
  reply[4] = VCP_MAKER;
  reply[5] = 1;
  reply[6] = byte6;
  reply[7] = byte7;
  reply[8] = byte8;
  reply[3] = 0;
  ddc_set_checksum_byte(DDC_CHECKSUM_SEED);
  return;
}
