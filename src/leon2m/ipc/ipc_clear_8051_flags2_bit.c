/* ipc_clear_8051_flags2_bit  (FUN_a002c22c)
 *
 * Clear bit 'bit' of the shared 8051 byte at XDATA 0xF225.
 *   bit: bit number
 * Note: Nothing calls it.
 * Name basis: descriptive - 8051 window mapping; unreferenced
 *
 * Matching notes
 * --------------
 * FUN_a002c22c (leon2m 0xa002c22c-0xa002c250, 36 bytes, leaf), flags -mcpu=v8 -O2 -g (the section default).
 * Source form: a read-modify-write of the volatile word, 'REG &= ~(1 << bit)'.
 */
#define REG (*(volatile unsigned int *)0xcf03c894)

/*
 * Clear one bit of the shared port event register at 0xCF03C894 (the register read by ipc_read_8051_flags2).
 *   bit: bit number to clear.
 * Nothing calls this routine.
 */
void ipc_clear_8051_flags2_bit(unsigned int bit)
{
    REG &= ~(1 << bit);
}
