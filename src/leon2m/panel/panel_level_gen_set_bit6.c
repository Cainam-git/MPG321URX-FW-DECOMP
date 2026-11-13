/* panel_level_gen_set_bit6  (FUN_a0101b20)
 *
 * Write bit 6 of the level generator's control register.
 * Name basis: descriptive - register 0xCF016118
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0101b20 @ 0xa0101b20, no flags recorded: built with the section default -mcpu=v8 -O2 -g (every
 * optimised flag set of the section gives the same bytes).
 * Source form: one read-modify-write expression; the value is not narrowed to one bit.
 */
/* Register 0xCF016118 of the level generator (reg_panel_level_gen_enable): bit 7 switches the generator on,
   bit 6 is the one written here. */
#define reg_panel_level_gen_enable (*(volatile unsigned int *)0xcf016118)

#define LEVEL_GEN_BIT6_KEEP  0xbf   /* every bit of the low byte except bit 6 */
#define LEVEL_GEN_BIT6_SHIFT 6

/*
 * Write bit 6 of the generator's enable register.
 *
 *   value  0 or 1 (its low byte is shifted into place)
 *
 * The other bits of the low byte keep their value, bits 8..31 are written as 0. The only caller,
 * startup_init_level_generator, sets the bit; panel_level_gen_ramp_next and panel_level_gen_stop_ramp clear it
 * directly.
 */
void panel_level_gen_set_bit6(unsigned int value)
{
  reg_panel_level_gen_enable = reg_panel_level_gen_enable & LEVEL_GEN_BIT6_KEEP | (value & 0xff) << LEVEL_GEN_BIT6_SHIFT;
}
