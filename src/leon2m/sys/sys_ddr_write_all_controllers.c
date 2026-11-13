/* sys_ddr_write_all_controllers  (FUN_a00e2258)
 *
 * Write a register of all three memory controllers.
 * Returns: the register number
 * Name basis: derived - bases 0xC0020000, 0xC0030000 and 0xC0040000; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00e2258 @ 0xa00e2258 (-mcpu=v8 -O2 -g)
 * Source form: sys_ddr_controller_write is declared without a parameter list, as the decompiler had it; the loop
 * is a do-while.
 */
extern int sys_ddr_controller_write();

/*
 * Write `value` to the register at byte offset `offset` in each of the three memory controllers (0, 1, 2).
 * Returns offset. Nothing in the image calls it.
 */
int sys_ddr_write_all_controllers(unsigned int offset, unsigned int value)
{
    int controller;

    controller = 0;
    do {
        sys_ddr_controller_write(controller, offset, value);
        controller = controller + 1;
    } while (controller < 3);
    return offset;
}
