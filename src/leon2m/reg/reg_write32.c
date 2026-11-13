/* reg_write32  (FUN_a002c25c)
 *
 * Store a 32-bit value at addr.
 *   addr: register address
 *   value: word to write
 * Name basis: proven - code: single volatile store
 *
 * Matching notes
 * --------------
 * leon2m FUN_a002c25c @ 0xa002c25c (RAM copy, run-time address 0x4008c25c), flags -mcpu=v8 -O2 -g (the
 * section default). Source form: the pointer is volatile, so the store stays out of the retl delay slot.
 */

/*
 * Write one 32-bit register (or memory word); the counterpart of reg_read32. The interrupt level handlers
 * and ipc_mailbox_write (every word put into a mailbox portal) go through it.
 */
void reg_write32(unsigned int addr, unsigned int value)
{
    *(volatile unsigned int *)addr = value;
}
