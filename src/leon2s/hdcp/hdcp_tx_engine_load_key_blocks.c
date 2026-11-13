/* hdcp_tx_engine_load_key_blocks  (FUN_a00c9cc8)
 *
 * Write the two prepared blocks to the engine.
 * Name basis: descriptive - 3 bytes from 0xA807CE48 (hdcp_tx_message_tail) and the block
 *   hdcp_tx_exchange_buffer at 0xA807CDB8, 0x400 each
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00c9cc8 @ 0xa00c9cc8 (-mcpu=v8 -Os -g)
 * Source form: the four calls keep the firmware's extra argument words (arg4 to arg6 of this routine are passed on
 * to the last register write); the second block address is the literal 0xa807ce48.
 */
extern unsigned int hdcp_tx_exchange_buffer;
extern void hdcp_tx_engine_write_block();
extern int hdcp_tx_engine_reg_write8();

#define HDCP_TX_MESSAGE_TAIL    0xa807ce48      /* address of hdcp_tx_message_tail (3 bytes) */
#define BLOCK_LENGTH            0x400           /* length argument of both block writes */

/*
 * Write the two prepared blocks to the protection engine of one unit, then write engine registers 0 and 3.
 *
 * Block 1 is the data at hdcp_tx_message_tail, written with bank 5 and mode 3. Block 2 is
 * hdcp_tx_exchange_buffer, written with bank 0 and mode 0. Afterwards register 0 is set to 0 and register 3 to 1.
 * unit selects the engine register window (as in hdcp_tx_engine_write_block). arg2 to arg6 are not used here;
 * arg4 to arg6 are passed on to the last register write only because the exact build does so.
 */
void hdcp_tx_engine_load_key_blocks(unsigned char unit, unsigned int arg2, unsigned int arg3, unsigned int arg4,
                                    unsigned int arg5, unsigned int arg6)
{
  hdcp_tx_engine_write_block(unit, HDCP_TX_MESSAGE_TAIL, 5, 3, BLOCK_LENGTH);
  hdcp_tx_engine_write_block(unit, &hdcp_tx_exchange_buffer, 0, 0, BLOCK_LENGTH);
  hdcp_tx_engine_reg_write8(unit, 0, 0);
  hdcp_tx_engine_reg_write8(unit, 3, 1, arg4, arg5, arg6);
  return;
}
