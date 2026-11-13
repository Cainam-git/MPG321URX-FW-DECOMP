/* sys_ddr_controller_write_reg194  (FUN_a00e0078)
 *
 * Write 0x10000 to register 0x194 of a memory controller.
 * Name basis: descriptive - unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00e0078 @ 0xa00e0078-0xa00e0090 (6 words), flags -mcpu=v8 -O2 -g.
 * Source form: a plain call, compiled as a tail call. The caller's return address is handed on, so the callee
 * returns straight to this routine's caller. The last word is the nop the compiler places behind such a call
 * sequence.
 */
extern void sys_ddr_controller_write(int controller, int offset, unsigned int value);

/*
 * Write 0x10000 to the register at byte offset 0x194 of memory controller `controller` (0..2). Nothing in the
 * image calls it or stores its address.
 */
void sys_ddr_controller_write_reg194(int controller)
{
    sys_ddr_controller_write(controller, 0x194, 0x10000);
}
