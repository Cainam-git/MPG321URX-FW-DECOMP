/* panel_level_gen_set_fields_10c  (FUN_a0101abc)
 *
 * Write two fields of the level generator's register 0xCF01610C.
 * Name basis: descriptive - (a << 3) | (b * 2), bit 0 kept
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0101abc @ 0xa0101abc, no flags recorded: built with the section default -mcpu=v8 -O2 -g (every
 * optimised flag set of the section gives the same bytes).
 * Source form: one read-modify-write expression; the second field is written as (value & 0xff) * 2.
 */
/* Register 0xCF01610C of the level generator block: bit 0 (kept here), a field from bit 1 and a field
   from bit 3. */
#define LEVEL_GEN_REG_10C (*(volatile unsigned int *)0xcf01610c)

#define REG_10C_BIT0 1

/*
 * Write the two fields of register 0xCF01610C above bit 0.
 *
 *   upper  the field from bit 3 up (its low byte is shifted into place)
 *   lower  the field from bit 1 up (its low byte, doubled)
 *
 * Bit 0 keeps its value, every other bit comes from the two fields. Neither value is narrowed, so a large
 * lower value runs into the upper field. The only caller, startup_init_level_generator, passes upper 0 and
 * lower 1.
 */
void panel_level_gen_set_fields_10c(unsigned int upper, unsigned int lower)
{
  LEVEL_GEN_REG_10C = LEVEL_GEN_REG_10C & REG_10C_BIT0 | (upper & 0xff) << 3 | (lower & 0xff) * 2;
}
