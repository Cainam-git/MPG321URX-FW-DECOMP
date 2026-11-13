/* ddc_set_checksum_byte  (FUN_a0089f60)
 *
 * Store v in the DDC/CI checksum byte.
 *   value
 * Note: Byte 0xA802AF9E, the running XOR used when building replies.
 * Name basis: derived - ddc_send_vcp_e6_reply XORs its message into the same byte
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0089f60, flags -mcpu=v8 -O2 -g.
 */
extern unsigned char ddc_reply_checksum;

/* Set the running XOR checksum of the DDC/CI reply being built (see ddc_send_vcp_e6_reply). */
void ddc_set_checksum_byte(unsigned char value)
{
    ddc_reply_checksum = value;
}
