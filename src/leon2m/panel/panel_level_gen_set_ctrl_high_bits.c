/* panel_level_gen_set_ctrl_high_bits  (FUN_a0101950)
 *
 * Put a 4-bit value in bits 4..7 of the level generator's first control register, then set bit 3.
 * Note: Bits 0..3 are kept. The only caller, panel_level_gen_set_target, passes 8 and is itself never called.
 * Name basis: descriptive - 0xCF0160C0: (old & 0xF) | value << 4, then bit 3
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0101950 @ 0xa0101950-0xa0101984 (13 words), flags -mcpu=v8 -O3 -g.
 * Source form: two separate read-modify-writes of the volatile register, so it is read twice.
 */
/* First control register of the level generator (reg_panel_level_gen_ctrl, 0xCF0160C0). */
#define reg_panel_level_gen_ctrl (*(volatile unsigned int *)0xcf0160c0)

#define LEVEL_GEN_CTRL_BIT3 0x08    /* tested by panel_level_gen_is_ready, cleared by panel_level_gen_clear_ctrl_bit3 */

/*
 * Put a 4-bit value into bits 4..7 of the level generator's first control register, then set bit 3.
 *
 *   value  the new bits 4..7; only its low four bits are used
 *
 * Bits 0..3 of the register keep their value, bits 8..31 are written as 0.
 * The only caller, panel_level_gen_set_target (itself never called), passes 8.
 */
void panel_level_gen_set_ctrl_high_bits(unsigned int value)
{
    reg_panel_level_gen_ctrl = (reg_panel_level_gen_ctrl & 0xf) | (value & 0xf) << 4;
    reg_panel_level_gen_ctrl |= LEVEL_GEN_CTRL_BIT3;
}
