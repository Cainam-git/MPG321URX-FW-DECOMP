/* hdcp_tx_engine_read_384_bytes  (FUN_a00c9de8)
 *
 * Read a block from the engine into a cleared 384-byte buffer and write it back to bank 4.
 * Name basis: descriptive - cleared local buffer, block read, then a write-back
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00c9de8 @ 0xa00c9de8 (-mcpu=v8 -Os -g)
 * Source form: the buffer is the 384-byte local, cleared by lib_memset first.
 */
extern int hdcp_tx_engine_write_block();
extern void hdcp_tx_engine_read_block();
extern int lib_memset();

#define TABLE_BYTES     0x180           /* size of the local buffer: 384 bytes */

/*
 * Read a block from the protection engine of one unit into a cleared 384-byte buffer and write the same buffer
 * straight back.
 *
 * The read uses bank 6 and the write uses bank 4 with mode 0 (see hdcp_tx_engine_read_block and
 * hdcp_tx_engine_write_block). length is the length argument of both calls. The buffer is local; nothing is
 * handed back to the caller.
 */
void hdcp_tx_engine_read_384_bytes(unsigned int unit, unsigned short length)
{
  unsigned char buffer [TABLE_BYTES];

  lib_memset(buffer,0,TABLE_BYTES);
  hdcp_tx_engine_read_block(unit & 0xff,buffer,6,length & 0xffff);
  hdcp_tx_engine_write_block(unit & 0xff,buffer,4,0,length & 0xffff);
}
