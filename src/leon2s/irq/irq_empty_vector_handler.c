/* irq_empty_vector_handler  (FUN_a00608f0)
 *
 * Return at once (its address stands in the word right after the interrupt vector table).
 * Note: Its only reference is the word 0xA807607C, right after the 15 vectors at 0xA8076040 that irq_entry
 *   reads for trap types 0x11..0x1F.
 * Name basis: descriptive - empty body; address stored only at 0xA807607C next to the vector table
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00608f0 @ 0xa00608f0 (-mcpu=v8 -Os -g)
 */
/*
 * Empty routine: returns at once. Its address is the word 0xA807607C, the word after the 15 entries of the
 * interrupt vector table at 0xA8076040.
 */
void irq_empty_vector_handler(void)
{
}
