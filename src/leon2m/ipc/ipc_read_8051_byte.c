/* ipc_read_8051_byte  (FUN_a002c194)
 *
 * Return shared 8051 byte ch (XDATA 0xF200 + ch - 1, ch 1..4), else 0.
 *   channel: byte number 1..4
 * Returns: byte value
 * Name basis: derived - same window as ipc_write_8051_byte; callers poll it for 0x55 / 0xAA
 *
 * Matching notes
 * --------------
 * FUN_a002c194 (leon2m 0xa002c194-0xa002c204, 28 words, leaf), flags -mcpu=v8 -O3 -g.
 * Source form: same as ipc_write_8051_byte, one return per case. The volatile qualifier is only on the 0xCF03Cxxx
 * hardware register accesses.
 */
#define REG(a) (*(volatile unsigned int *)(a))

/*
 * Read one of the four shared registers that ipc_write_8051_byte writes.
 *   channel: 1..4 selects the register at 0xCF03C800 + 4 * (channel - 1).
 * Returns the low byte of the register; 0 for any other channel.
 */
unsigned char ipc_read_8051_byte(unsigned char channel)
{
  switch (channel) {
  case 1: return REG(0xcf03c800);
  case 2: return REG(0xcf03c804);
  case 3: return REG(0xcf03c808);
  case 4: return REG(0xcf03c80c);
  }
  return 0;
}
