/* panel_level_gen_stop_ramp  (FUN_a0101904)
 *
 * Clear bit 6 of the control register and write 0xFF to register 0xCF016114.
 * Name basis: descriptive - mechanics only; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0101904 @ 0xa0101904-0xa010192c (40 bytes, leaf), flags -mcpu=v8 -O2 -g (section default; -O3 -g
 * and -Os -g give the same bytes).
 */
#define reg_panel_level_gen_enable (*(volatile unsigned int *)0xcf016118)  /* bit 7 enable, bit 6 option */
#define LEVEL_GEN_REG_114          (*(volatile unsigned int *)0xcf016114)

#define LEVEL_GEN_OPTION_BIT 0x40u

/*
 * Clear bit 6 of the level generator's register 0xCF016118 (the register whose bit 7 switches the generator on)
 * and write 0xFF to register 0xCF016114.
 *
 * Nothing in the image calls this routine.
 */
void panel_level_gen_stop_ramp(void)
{
    reg_panel_level_gen_enable &= ~LEVEL_GEN_OPTION_BIT;
    LEVEL_GEN_REG_114 = 0xff;
}
