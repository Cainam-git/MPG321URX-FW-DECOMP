/* panel_level_gen_set_cc_bit5  (FUN_a01018b0)
 *
 * Set or clear bit 5 of register 0xCF0160CC.
 * Name basis: descriptive - mechanics only
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01018b0 @ 0xa01018b0, flags -mcpu=v8 -O3 -g.
 * Source form: the 'on != 0' arm comes first, which gives the firmware's fall-through into the set case.
 */
#define LEVEL_GEN_REG_CC (*(volatile unsigned int *)0xcf0160cc)

#define CC_BIT5 0x20

/*
 * Set (on != 0) or clear (on == 0) bit 5 of the level generator's register 0xCF0160CC.
 * panel_level_gen_set_frequency keeps this bit when it rewrites the register. The only caller,
 * startup_init_level_generator, clears it.
 */
void panel_level_gen_set_cc_bit5(unsigned char on)
{
    if (on != 0) {
        LEVEL_GEN_REG_CC = LEVEL_GEN_REG_CC | CC_BIT5;
    } else {
        LEVEL_GEN_REG_CC = LEVEL_GEN_REG_CC & ~CC_BIT5;
    }
    return;
}
