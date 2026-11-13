/* sys_ddr_get_controller_base  (FUN_a00e0234)
 *
 * Return the base address of memory controller 0, 1 or 2.
 * Returns: address
 * Name basis: proven - 0xC0020000, 0xC0030000 or 0xC0040000; unused
 *
 * Matching notes
 * --------------
 * FUN_a00e0234 (leon2m 0xa00e0234-0xa00e0268, 52 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Source form: an initialised local array (built on the stack).
 */

/*
 * Return the base address of register block `controller` (0..2): 0xc0020000, 0xc0030000 or 0xc0040000. The
 * number is not checked. Nothing in the image calls it.
 */
unsigned int sys_ddr_get_controller_base(unsigned int controller)
{
    unsigned int base[3] = { 0xc0020000, 0xc0030000, 0xc0040000 };

    return base[controller];
}
