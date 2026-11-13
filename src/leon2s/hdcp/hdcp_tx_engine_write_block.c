/* hdcp_tx_engine_write_block  (FUN_a00c99a4)
 *
 * Write a block of bytes to the protection engine of an output.
 * Name basis: descriptive - indirect register window; counting loop
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00c99a4 @ 0xa00c99a4 (-mcpu=v8 -Os -g)
 * Source form: the word count length >> 4 is recomputed in every loop test and in the index; the loop counter is
 * an unsigned char tested after masking with 0xff. The result of the original return expression has no effect
 * and is left out.
 */
extern void hdcp_tx_engine_reg_write8();

#define ENGINE_REG_BANK    4           /* receives mode * 0x11 */
#define ENGINE_REG_STROBE  5           /* 0x80 then 0 restarts the block */
#define ENGINE_REG_HIGH    6           /* high byte of each word */
#define ENGINE_REG_LOW     7           /* low byte of each word */

#define FILL_BUFFER        0           /* write the words of the buffer */
#define FILL_THREE_BYTES   3           /* write 3 bytes of the buffer, then zero words */
#define FILL_ZERO          4           /* write only zero words */

/*
 * Write a block of 16-bit words to the protection engine of one output through its indirect register window.
 *
 *   unit    engine unit of the output (0..3)
 *   buffer  the bytes to write; not read in fill mode FILL_ZERO
 *   mode    block number: mode * 0x11 is written to engine register 4, then register 5 gets 0x80 and 0
 *           (callers pass 0 and 3 to 6)
 *   fill    what follows the set-up (see below)
 *   length  size of the block; length / 16 is the number of words (callers pass 0xc00 for the 0x180-byte
 *           engine buffer and 0x400 for 128 bytes)
 *
 * Each word is written as two bytes, high byte to register 6 and low byte to register 7.
 *   FILL_BUFFER       the words of the buffer, last word first: word k from the end is buffer[2k-1] (high)
 *                     and buffer[2k-2] (low)
 *   FILL_THREE_BYTES  buffer[2], buffer[1] and buffer[0] as the first two words (the low byte of the second is
 *                     0), then zero words up to the word count
 *   FILL_ZERO         zero words only
 * Any other fill value writes nothing after the set-up.
 * Counterpart of hdcp_tx_engine_read_block.
 */
void hdcp_tx_engine_write_block(unsigned int unit, unsigned char *buffer, unsigned char mode, unsigned char fill, unsigned short length)

{
  unsigned int words;
  int word_from_end;
  unsigned int unit_byte;
  unsigned char i;
  
  unit_byte = unit & 0xff;
  hdcp_tx_engine_reg_write8(unit_byte,ENGINE_REG_BANK,(unsigned char)(mode * 0x11));
  hdcp_tx_engine_reg_write8(unit_byte,ENGINE_REG_STROBE,0x80);
  hdcp_tx_engine_reg_write8(unit_byte,ENGINE_REG_STROBE,0);
  if (fill == FILL_BUFFER) {
    for (i = 0; (i & 0xff) < (unsigned int)((length & 0xffff) >> 4); i = i + 1) {
        words = (length & 0xffff) >> 4;
        word_from_end = words - (i & 0xff);
        hdcp_tx_engine_reg_write8(unit_byte,ENGINE_REG_HIGH,buffer[word_from_end * 2 + -1]);
        hdcp_tx_engine_reg_write8(unit_byte,ENGINE_REG_LOW,buffer[word_from_end * 2 + -2]);
    }
  }
  else if (fill == FILL_THREE_BYTES) {
    hdcp_tx_engine_reg_write8(unit_byte,ENGINE_REG_HIGH,buffer[2]);
    hdcp_tx_engine_reg_write8(unit_byte,ENGINE_REG_LOW,buffer[1]);
    hdcp_tx_engine_reg_write8(unit_byte,ENGINE_REG_HIGH,*buffer);
    hdcp_tx_engine_reg_write8(unit_byte,ENGINE_REG_LOW,0);
    i = 2;
    if (2 < (length & 0xffff) >> 4) {
      do {
        hdcp_tx_engine_reg_write8(unit_byte,ENGINE_REG_HIGH,0);
        hdcp_tx_engine_reg_write8(unit_byte,ENGINE_REG_LOW,0);
        i = i + 1;
      } while ((i & 0xff) < (length & 0xffff) >> 4);
    }
  }
  else if ((fill == FILL_ZERO) && (i = 0, (length & 0xffff) >> 4 != 0)) {
    do {
      hdcp_tx_engine_reg_write8(unit_byte,ENGINE_REG_HIGH,0);
      hdcp_tx_engine_reg_write8(unit_byte,ENGINE_REG_LOW,0);
      i = i + 1;
    } while ((i & 0xff) < (length & 0xffff) >> 4);
  }
}
