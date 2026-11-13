/* dbg_set_print_mask_bits  (FUN_a00dd5e0)
 *
 * Set or clear bits of the debug print mask.
 * Name basis: derived - word at 0xA802B0B0; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00dd5e0 @ 0xa00dd5e0-0xa00dd614 (13 words).
 * The second parameter is not used.
 */
extern unsigned int dbg_print_mask;

/*
 * Switch classes of debug messages on or off. Every bit of mask is one class; dbg_is_print_enabled tests the
 * bits before a message is printed.
 *
 *   mask    the class bits to change
 *   unused  not used
 *   on      non-zero sets the bits, 0 clears them
 *
 * Nothing in the image calls this routine.
 */
void dbg_set_print_mask_bits(unsigned int mask, unsigned int unused, unsigned int on)
{
    if (on)
        dbg_print_mask |= mask;
    else
        dbg_print_mask &= ~mask;
}
