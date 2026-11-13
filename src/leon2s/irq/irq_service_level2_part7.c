/* irq_service_level2_part7  (FUN_a0060a50)
 *
 * The 'retl; nop' ending of the level-2 interrupt service routine.
 * Note: Ghidra piece 7 of the routine 0xA00609FC..0xA0060A57, not callable on its own.
 * Name basis: proven - vector table 0xA8076040 slot 1 = 0xA00609FC; bit 0x4 masked, cleared (0x9F120034,
 *   0x9F10009C) and unmasked, nothing called
 *
 * Matching notes
 * --------------
 * leon2s FUN_a0060a50 @ 0xa0060a50 (-mcpu=v8 -Os -g)
 */
/* Empty routine: returns at once. Same code as irq_empty_vector_handler. */
void irq_service_level2_part7(void)
{
}
