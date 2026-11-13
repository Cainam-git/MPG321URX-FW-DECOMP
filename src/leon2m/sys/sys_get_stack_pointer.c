/* sys_get_stack_pointer  (FUN_a00de9d8)
 *
 * Return the current stack pointer.
 * Returns: stack pointer
 * Name basis: proven - leaf routine: mov %sp, %o0
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00de9d8 @ 0xa00de9d8-0xa00de9e0 (2 words), flags -mcpu=v8 -O2 -g.
 * Source form: a leaf 'retl; mov %sp,%o0' with no frame. A GNU local register variable bound to %sp is the only
 * C way to name %sp; __builtin_frame_address(0) would force a save/restore frame and give other code. No
 * volatile, no inline asm statement.
 */
/* Return the current stack pointer. Used by dbg_print_stack_usage for the "Curr" value. */
void *sys_get_stack_pointer(void)
{
    register void *sp __asm__("sp");

    return sp;
}
