/* leon2m FUN_a00f93a0 @ 0xa00f93a0-0xa00f9500 (88 words), flags -mcpu=v8 -O3 -g. Called by FUN_a0148aec.
 * Per-block 8-bit registers: write reg 0x32 = 0 (FUN_a00f1ad4), read the 16-bit values at regs 0x14, 0x12,
 * 0x10 and 0xc (FUN_a00f1ce4). x = (r14 - w) / 16 + r12 and y = (r10 - h) / 2 + rc (signed int division,
 * kept as u16). Writes y to regs 0x25/0x26 and 0x27/0x28 (low, high byte), h low byte to 0x29, 0 to 0x2a,
 * x to 0x2b/0x2c, (w >> 3) low byte to 0x2d, 0 to 0x2e, and 1 to 0x2f.
 */
extern void FUN_a00f1ad4(unsigned char blk, unsigned char reg, unsigned char val);
extern unsigned short FUN_a00f1ce4(unsigned char blk, unsigned char reg);

void FUN_a00f93a0(unsigned char blk, unsigned short w, unsigned short h)
{
  unsigned short x, y;

  FUN_a00f1ad4(blk, 0x32, 0);
  x = (FUN_a00f1ce4(blk, 0x14) - w) / 16 + FUN_a00f1ce4(blk, 0x12);
  y = (FUN_a00f1ce4(blk, 0x10) - h) / 2 + FUN_a00f1ce4(blk, 0xc);
  FUN_a00f1ad4(blk, 0x25, y & 0xff);
  FUN_a00f1ad4(blk, 0x26, (y & 0xff00) >> 8);
  FUN_a00f1ad4(blk, 0x27, y & 0xff);
  FUN_a00f1ad4(blk, 0x28, (y & 0xff00) >> 8);
  FUN_a00f1ad4(blk, 0x29, h & 0xff);
  FUN_a00f1ad4(blk, 0x2a, 0);
  FUN_a00f1ad4(blk, 0x2b, x & 0xff);
  FUN_a00f1ad4(blk, 0x2c, (x & 0xff00) >> 8);
  FUN_a00f1ad4(blk, 0x2d, (w >> 3) & 0xff);
  FUN_a00f1ad4(blk, 0x2e, 0);
  FUN_a00f1ad4(blk, 0x2f, 1);
}
