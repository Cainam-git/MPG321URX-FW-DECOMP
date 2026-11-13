/* panel_level_gen_is_ready  (FUN_a0101b78)
 *
 * Return whether the level generator reports ready.
 * Returns: 0 or 1
 * Name basis: descriptive - bit 3 of 0xCF0160C0 set and bits 5-6 of 0xCF0160F4 clear; unused
 *
 * Matching notes
 * --------------
 * FUN_a0101b78 (leon2m 0xa0101b78-0xa0101bb0, 56 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Source form: one if with && and an explicit return 1 / return 0.
 */
/* First control register of the level generator (reg_panel_level_gen_ctrl, 0xCF0160C0) and register
   0xCF0160F4 of the same block. */
#define reg_panel_level_gen_ctrl (*(volatile unsigned int *)0xcf0160c0)
#define LEVEL_GEN_REG_F4         (*(volatile unsigned int *)0xcf0160f4)

#define LEVEL_GEN_CTRL_BIT3  0x08   /* set by panel_level_gen_set_ctrl_high_bits */
#define F4_UPPER_FIELD_MASK  0x60   /* bits 5..6, written by panel_level_gen_set_f4_upper_field */

/*
 * Return 1 when bit 3 of the first control register is set and the field at bits 5..6 of register
 * 0xCF0160F4 is 0, else 0.
 *
 * Nothing in the firmware calls this routine or holds its address.
 */
int panel_level_gen_is_ready(void)
{
    if ((reg_panel_level_gen_ctrl & LEVEL_GEN_CTRL_BIT3) && (LEVEL_GEN_REG_F4 & F4_UPPER_FIELD_MASK) == 0)
        return 1;
    return 0;
}
