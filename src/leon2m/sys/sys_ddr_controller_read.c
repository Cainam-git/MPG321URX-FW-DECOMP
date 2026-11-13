/* sys_ddr_controller_read  (FUN_a00e0268)
 *
 * Read a register of memory controller 0, 1 or 2.
 * Returns: word
 * Name basis: proven - base + offset; unused
 *
 * Matching notes
 * --------------
 * FUN_a00e0268 (leon2m 0xa00e0268-0xa00e02a0, 56 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Source form: an initialised local array (built on the stack); the word is read through a volatile pointer.
 */

/*
 * Return the 32-bit register at byte offset `offset` in register block `controller` (0..2; bases 0xc0020000,
 * 0xc0030000, 0xc0040000, the same table as sys_ddr_controller_write). Nothing in the image calls it.
 */
unsigned int sys_ddr_controller_read(unsigned int controller, unsigned int offset)
{
    unsigned int base[3] = { 0xc0020000, 0xc0030000, 0xc0040000 };

    return *(volatile unsigned int *)(base[controller] + offset);
}
