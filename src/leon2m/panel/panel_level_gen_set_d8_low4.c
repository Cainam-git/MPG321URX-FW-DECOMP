/* panel_level_gen_set_d8_low4  (FUN_a010192c)
 *
 * Write the low four bits of register 0xCF0160D8.
 * Name basis: descriptive - mechanics only
 *
 * Matching notes
 * --------------
 * leon2m FUN_a010192c @ 0xa010192c, no flags recorded: built with the section default -mcpu=v8 -O2 -g (every
 * optimised flag set of the section gives the same bytes).
 * Source form: one read-modify-write expression on the volatile register.
 */
/* Register 0xCF0160D8 of the level generator block; only its low four bits are written here. */
#define LEVEL_GEN_REG_D8 (*(volatile unsigned int *)0xcf0160d8)

/*
 * Put a 4-bit value into bits 0..3 of register 0xCF0160D8.
 *
 *   value  the new bits 0..3; higher bits of it are ignored
 *
 * Bits 4..7 of the register keep their value, bits 8..31 are written as 0.
 * startup_init_level_generator writes 0xF, panel_level_gen_set_target writes 0.
 */
void panel_level_gen_set_d8_low4(unsigned int value)
{
  LEVEL_GEN_REG_D8 = LEVEL_GEN_REG_D8 & 0xf0 | value & 0xf;
}
