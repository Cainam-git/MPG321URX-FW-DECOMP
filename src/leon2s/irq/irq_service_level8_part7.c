/* irq_service_level8_part7  (FUN_a0060e70)
 *
 * The 'retl; nop' ending of the level-8 interrupt service routine.
 * Note: Ghidra piece 7 of the routine 0xA0060E1C..0xA0060E77, not callable on its own.
 * Name basis: proven - vector table 0xA8076040 slot 7 = 0xA0060E1C; bit 0x100 masked, cleared (0x9F120034,
 *   0x9F10009C) and unmasked, nothing called
 *
 * Matching notes
 * --------------
 * leon2s FUN_a0060e70 @ 0xa0060e70 (-mcpu=v8 -Os -g)
 */
/* Empty routine: returns at once. Same code as irq_empty_vector_handler. */
void irq_service_level8_part7(void)
{
}
