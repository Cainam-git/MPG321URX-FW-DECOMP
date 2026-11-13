/* sys_delay_loop_medium  (FUN_a00de5c0)
 *
 * Wait in a loop of n times 40,000 idle instructions.
 * Name basis: derived - nop loop; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00de5c0 @ 0xa00de5c0-0xa00de604 (68 bytes, leaf), flags -mcpu=v8 -O2 -g.
 * Source form: the nop is inline asm (without volatile).
 */
/* Busy-wait: n rounds of 40000 (0x9C40) passes, each pass one nop instruction. Nothing in the image calls it. */
void sys_delay_loop_medium(unsigned int n)
{
    unsigned int i, j;

    for (i = 0; i < n; i++)
        for (j = 0; j <= 0x9c3f; j++)
            __asm__("nop");
}
