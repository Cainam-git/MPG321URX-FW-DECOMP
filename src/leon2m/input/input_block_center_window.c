/* input_block_center_window  (FUN_a00f93a0)
 *
 * Compute centred offsets from the capture registers and write them.
 * Name basis: derived - from registers 0x10..0x14 to registers 0x25..0x2F
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00f93a0 @ 0xa00f93a0, 88 words, flags -mcpu=v8 -O3 -g.
 * The divisions are signed int divisions whose results are kept as unsigned short.
 */
extern void input_capture_write8(unsigned char blk, unsigned char reg, unsigned char val);
extern unsigned short input_capture_read16(unsigned char blk, unsigned char reg);

/* Place a window of the given width and height in the middle of the capture area of the block and write the
 * result to registers 0x25 to 0x2F. Called by sys_api_center_channel_window.
 *
 * Register 0x32 is cleared first. The position is computed from the 16-bit registers 0x14, 0x12, 0x10 and 0x0C:
 *   x = (reg 0x14 - width) / 16 + reg 0x12
 *   y = (reg 0x10 - height) / 2 + reg 0x0C
 * y goes (low byte, high byte) to registers 0x25/0x26 and again to 0x27/0x28; the low byte of the height to
 * 0x29; x to 0x2B/0x2C; the low byte of width / 8 to 0x2D; 0 to 0x2A and 0x2E; and 1 to 0x2F. */
void input_block_center_window(unsigned char block, unsigned short width, unsigned short height)
{
  unsigned short x, y;

  input_capture_write8(block, 0x32, 0);
  x = (input_capture_read16(block, 0x14) - width) / 16 + input_capture_read16(block, 0x12);
  y = (input_capture_read16(block, 0x10) - height) / 2 + input_capture_read16(block, 0xc);
  input_capture_write8(block, 0x25, y & 0xff);
  input_capture_write8(block, 0x26, (y & 0xff00) >> 8);
  input_capture_write8(block, 0x27, y & 0xff);
  input_capture_write8(block, 0x28, (y & 0xff00) >> 8);
  input_capture_write8(block, 0x29, height & 0xff);
  input_capture_write8(block, 0x2a, 0);
  input_capture_write8(block, 0x2b, x & 0xff);
  input_capture_write8(block, 0x2c, (x & 0xff00) >> 8);
  input_capture_write8(block, 0x2d, (width >> 3) & 0xff);
  input_capture_write8(block, 0x2e, 0);
  input_capture_write8(block, 0x2f, 1);
}
