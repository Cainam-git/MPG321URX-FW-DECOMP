/* panel_level_gen_clear_10c_bit0  (FUN_a0101aa0)
 *
 * Clear bit 0 of register 0xCF01610C.
 * Name basis: descriptive - mechanics only; unused
 *
 * Matching notes
 * --------------
 * FUN_a0101aa0 (leon2m 0xa0101aa0-0xa0101abc, 28 bytes, leaf), no flags recorded: built with the section default
 * -mcpu=v8 -O2 -g (every optimised flag set of the section gives the same bytes).
 */
/* Register 0xCF01610C of the level generator block: bit 0, and the fields written by
   panel_level_gen_set_fields_10c from bit 1 up. */
#define LEVEL_GEN_REG_10C (*(volatile unsigned int *)0xcf01610c)

#define REG_10C_BIT0 1u

/*
 * Clear bit 0 of register 0xCF01610C; the other bits keep their value.
 * panel_level_gen_ramp_next clears the same bit in its reset step.
 *
 * Nothing in the firmware calls this routine or holds its address.
 */
void panel_level_gen_clear_10c_bit0(void)
{
    LEVEL_GEN_REG_10C &= ~REG_10C_BIT0;
}
