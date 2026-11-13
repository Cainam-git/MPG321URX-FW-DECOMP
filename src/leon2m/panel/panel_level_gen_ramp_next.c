/* panel_level_gen_ramp_next  (FUN_a0101bb0)
 *
 * Advance the level generator's ramp value by one, with an optional reset first.
 * Returns: 0 at the end of the ramp
 * Name basis: descriptive - counter byte at 0xA802C981 into 0xCF016110 / 0xCF016114; returns 0 at the end
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0101bb0 @ 0xa0101bb0-0xa0101c64 (45 words), flags -mcpu=v8 -O3 -g.
 * Source form: the result is an unsigned char that starts at 1 and is returned as result & 1; at the end of the
 * ramp 0xCF016110 is cleared before the RAM value and 0xCF016114 after it.
 */
/* Registers of the level generator block written here. 0xCF016118 is reg_panel_level_gen_enable. */
#define reg_panel_level_gen_enable (*(volatile unsigned int *)0xcf016118)
#define LEVEL_GEN_REG_C4           (*(volatile unsigned int *)0xcf0160c4)
#define LEVEL_GEN_REG_D8           (*(volatile unsigned int *)0xcf0160d8)
#define LEVEL_GEN_REG_104          (*(volatile unsigned int *)0xcf016104)
#define LEVEL_GEN_REG_10C          (*(volatile unsigned int *)0xcf01610c)
#define LEVEL_GEN_REG_110          (*(volatile unsigned int *)0xcf016110)
#define LEVEL_GEN_REG_114          (*(volatile unsigned int *)0xcf016114)

#define LEVEL_GEN_BIT6     0x40     /* bit 6 of the enable register (panel_level_gen_set_bit6) */
#define RAMP_LAST_VALUE    0xff     /* the ramp counts 1..0xFF */

extern unsigned char panel_level_gen_ramp_value;

/*
 * Advance the generator's ramp by one: count the ramp value up and write it to registers 0xCF016110 and
 * 0xCF016114.
 *
 *   restart  nonzero: first put the block into its ramp start state (below) and start the count again at 0
 *
 * Returns 1 while the ramp goes on, 0 when the value has reached 0xFF; then both registers and the value are
 * set back to 0.
 *
 * The start state: bit 6 of the enable register cleared, register 0xCF0160C4 set to 2, bits 0..3 of 0xCF0160D8
 * cleared, 0xCF016104 set to 0, bit 0 of 0xCF01610C cleared.
 *
 * The only caller is panel_level_gen_ramp_step, which switches the generator on when 0 comes back.
 */
int panel_level_gen_ramp_next(unsigned char restart)
{
    unsigned char going_on = 1;

    if (restart) {
        reg_panel_level_gen_enable &= ~LEVEL_GEN_BIT6;
        LEVEL_GEN_REG_C4 = 0;
        LEVEL_GEN_REG_C4 |= 2;
        LEVEL_GEN_REG_D8 &= 0xf0;
        LEVEL_GEN_REG_104 = 0;
        LEVEL_GEN_REG_10C &= ~1;
        panel_level_gen_ramp_value = 0;
    }
    panel_level_gen_ramp_value++;
    LEVEL_GEN_REG_110 = panel_level_gen_ramp_value;
    LEVEL_GEN_REG_114 = panel_level_gen_ramp_value;
    if (panel_level_gen_ramp_value == RAMP_LAST_VALUE) {
        LEVEL_GEN_REG_110 = 0;
        panel_level_gen_ramp_value = 0;
        LEVEL_GEN_REG_114 = 0;
        going_on = 0;
    }
    return going_on & 1;
}
