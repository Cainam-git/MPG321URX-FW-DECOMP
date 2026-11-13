/* reg_read32  (FUN_a002c250)
 *
 * Return the 32-bit word at addr.
 *   addr: register address
 * Returns: word read
 * Name basis: proven - code: single volatile load; used for every mailbox read
 *
 * Matching notes
 * --------------
 * leon2m FUN_a002c250 @ 0xa002c250 (RAM copy, run-time address 0x4008c250), flags -mcpu=v8 -O2 -g (the
 * section default).
 */

/*
 * Read one 32-bit register (or memory word). The program's common register read: the interrupt level
 * handlers, ipc_mailbox_read and many others go through it.
 */
unsigned int reg_read32(unsigned int addr)
{
    return *(volatile unsigned int *)addr;
}
