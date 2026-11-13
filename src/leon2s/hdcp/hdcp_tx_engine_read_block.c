/* hdcp_tx_engine_read_block  (FUN_a00c9d28)
 *
 * Read a block of bytes from the protection engine of an output.
 * Name basis: descriptive - indirect register window: write the index, read the data
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00c9d28 @ 0xa00c9d28 (-mcpu=v8 -Os -g)
 * Source form: the byte index is rebuilt from the word count on every pass, as the firmware does; the return
 * value (the unit number) is kept.
 */
extern void hdcp_tx_engine_reg_write8();
extern int hdcp_tx_engine_reg_read8();

/*
 * Read a block of bytes from the protection engine of one unit.
 *
 * unit   engine register window to use.
 * buffer receives the bytes.
 * bank   data bank to read; its value times 0x11 is written to register 4.
 * length number of bytes asked for; length / 16 pairs of bytes are read (see below).
 *
 * Register 5 is written 0x80 and then 0, then register 7 is read once and the value is dropped. After that, for
 * each pair, register 6 is read into the byte above register 7's byte; the pairs are stored from the end of the
 * range towards the start. The counterpart that writes is hdcp_tx_engine_write_block.
 * Returns the unit number.
 */
int hdcp_tx_engine_read_block(unsigned int unit, int buffer, unsigned char bank, unsigned short length)
{
  unsigned char value;
  int pair_end;
  unsigned int pair_count;
  unsigned int port;
  unsigned short pair;

  port = unit & 0xff;
  hdcp_tx_engine_reg_write8(port,4,(unsigned char)(bank * 0x11));
  hdcp_tx_engine_reg_write8(port,5,0x80);
  hdcp_tx_engine_reg_write8(port,5,0);
  hdcp_tx_engine_reg_read8(port,7);
  pair = 0;
  if ((length & 0xffff) >> 4 != 0) {
    do {
      pair_count = (length & 0xffff) >> 4;
      value = hdcp_tx_engine_reg_read8(port,6);
      pair_end = (pair_count - (pair & 0xffff)) * 2 + buffer;
      *(unsigned char *)(pair_end + -1) = value;
      value = hdcp_tx_engine_reg_read8(port,7);
      pair = pair + 1;
      *(unsigned char *)(pair_end + -2) = value;
    } while ((pair & 0xffff) < pair_count);
  }
  return port;
}
