/* ipc_write_8051_byte  (FUN_a002c11c)
 *
 * Write v to shared 8051 byte ch (XDATA 0xF200 + ch - 1, ch 1..4)
 *   channel: byte number 1..4
 *   value
 * Note: Register 0xCF03C800 + 4 * (ch - 1); the 8051 sees it at XDATA 0xF200 + (ch - 1).
 * Name basis: derived - 8051 register window XDATA 0xF000 + n = 0xCF03C000 + 4n (ipc_signal_alive header);
 *   handshake caller ipc_handshake_8051_bytes
 *
 * Matching notes
 * --------------
 * FUN_a002c11c (leon2m 0xa002c11c-0xa002c194, 30 words, leaf), flags -mcpu=v8 -O3 -g.
 * Source form: one case per register, each a full-word store through a volatile pointer; this gives the firmware's
 * case tree. The volatile qualifier is only on the 0xCF03Cxxx hardware register accesses.
 */
#define REG(a) (*(volatile unsigned int *)(a))

/*
 * Write a byte value to one of four shared registers.
 *   channel: 1..4 selects the register at 0xCF03C800 + 4 * (channel - 1); any other value writes nothing.
 *   value:   byte stored (as a full word) in the register.
 * Each of these words is one byte of the 8051's data memory window (data names reg_ipc_8051_shared_*, which map
 * 0xCF03C844 to 0xF211). ipc_read_8051_byte reads the same registers back.
 * Callers: ipc_handshake_8051_bytes and the start-up code.
 */
void ipc_write_8051_byte(unsigned char channel, unsigned char value)
{
  switch (channel) {
  case 1: REG(0xcf03c800) = value; break;
  case 2: REG(0xcf03c804) = value; break;
  case 3: REG(0xcf03c808) = value; break;
  case 4: REG(0xcf03c80c) = value; break;
  }
}
