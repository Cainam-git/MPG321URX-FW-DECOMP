/* irq_empty_handler  (FUN_a00295e4)
 *
 * Return at once (its address stands in the word right after the interrupt level table).
 * Note: Its address is the word 0xA8027B8C, right after the 15 entries (0xA8027B50..0xA8027B88) that
 *   irq_dispatch reads for trap types 0x11..0x1F.
 * Name basis: derived - address word 0xA8027B8C behind the 15 level handlers of table 0xA8027B50; no call or
 *   other reference in the image
 *
 * Matching notes
 * --------------
 * leon2m irq_empty_handler @ 0xa00295e4-0xa00295ec (8 bytes), flags -mcpu=v8 -O2 -g.
 * Source form: an empty void function; keep the body empty so the compiler emits the same retl; nop.
 */
/*
 * Empty routine whose address stands right after the interrupt level table.
 *
 * It returns immediately. Its address is the word 0xA8027B8C, right behind the 15 level entries of the table at
 * 0xA8027B50; irq_dispatch reads only those 15 (trap types 0x11..0x1F), so this word is not used. The routines
 * irq_empty_handler_copy .. irq_empty_handler_copy7 are identical empty routines elsewhere in the image.
 */
void irq_empty_handler(void)
{
}
