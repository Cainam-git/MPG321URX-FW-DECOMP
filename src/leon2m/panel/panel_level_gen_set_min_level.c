/* panel_level_gen_set_min_level  (FUN_a0101c9c)
 *
 * Write the low byte of level generator register 0xCF0160C8.
 * Note: Nothing calls it. The register receives the minimum level byte in panel_level_gen_set_level_pair.
 * Name basis: descriptive - register 0xCF0160C8, the one that receives the minimum level byte; no caller
 *
 * Matching notes
 * --------------
 * FUN_a0101c9c (leon2m 0xa0101c9c-0xa0101cb4, 24 bytes, leaf), no flags recorded: built with the section default
 * -mcpu=v8 -O2 -g (every optimised flag set of the section gives the same bytes).
 * Source form: a volatile register store of an unsigned char parameter (and 0xff; the store stays before retl).
 */
/* Level register of the level generator (reg_panel_level_gen_min_level, 0xCF0160C8). */
#define reg_panel_level_gen_min_level (*(volatile unsigned int *)0xcf0160c8)

/*
 * Write the generator's level register.
 *
 *   level  the new level
 *
 * Nothing in the firmware calls this routine or holds its address; the callers that set the level use
 * panel_level_gen_set_level_pair.
 */
void panel_level_gen_set_min_level(unsigned char level)
{
    reg_panel_level_gen_min_level = level;
}
