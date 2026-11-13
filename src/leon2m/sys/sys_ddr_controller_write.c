/* sys_ddr_controller_write  (FUN_a00e02a0)
 *
 * Write a register of memory controller 0, 1 or 2.
 * Name basis: proven - base + offset
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00e02a0 @ 0xa00e02a0 (-mcpu=v8 -O3 -g)
 * Source form: the base table is a local array filled by three separate stores (at %sp+0x60..%sp+0x68); the
 * final store is st [%g1 + %o1] with %g1 = the selected base and %o1 = the offset.
 */
extern void sys_ddr_controller_write(int controller, int offset, unsigned int value);

/*
 * Write `value` to the 32-bit register at byte offset `offset` in register block `controller` (0..2; bases
 * 0xc0020000, 0xc0030000, 0xc0040000). The number is not checked. Called by sys_ddr_write_all_controllers
 * and sys_ddr_controller_write_reg194.
 */
void sys_ddr_controller_write(int controller, int offset, unsigned int value)
{
    unsigned int base[3];

    base[0] = 0xc0020000;
    base[1] = 0xc0030000;
    base[2] = 0xc0040000;

    *(unsigned int *)(base[controller] + offset) = value;
}
