/* leon2m FUN_a00de9d8 @ 0xa00de9d8-0xa00de9e0 (2 words), flags -mcpu=v8 -O3 -g.
 * Code facts: leaf 'retl; mov %sp,%o0': returns the current stack pointer (no frame).
 * Source form: a GNU local register variable bound to %sp; __builtin_frame_address(0) forces a save/restore frame
 * and gives other code.
 * Compiler aids: the register-asm variable is the only C way to name %sp; no volatile, no inline asm statement.
 */
void *FUN_a00de9d8(void)
{
    register void *sp __asm__("sp");

    return sp;
}
