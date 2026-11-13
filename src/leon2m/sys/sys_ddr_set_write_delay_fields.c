/* sys_ddr_set_write_delay_fields  (FUN_a00eb708)
 *
 * Write the write delay fields of a data byte from a stored value and a step.
 * Name basis: descriptive - entry b of the field tables
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00eb708 @ 0xa00eb708-0xa00eba64, flags -mcpu=v8 -O3 -g.
 * Source form the exact build depends on: each write is its own if (byte == -1)/else statement (GCC threads the
 * repeated tests); the step > 8 arm first; sys_ddr_write_delay_field5_value is read again for each value.
 */
extern unsigned int sys_ddr_write_delay_field5_value;
extern void sys_ddr_phy_write_field(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
extern unsigned int sys_ddr_write_delay_field5_regs[], sys_ddr_write_delay_field5_masks[], sys_ddr_write_delay_field5_shifts[], sys_ddr_write_delay_field4_regs[], sys_ddr_write_delay_field4_masks[], sys_ddr_write_delay_field4_shifts[], sys_ddr_write_delay_field3_regs[], sys_ddr_write_delay_field3_masks[], sys_ddr_write_delay_field3_shifts[], sys_ddr_write_delay_field6_regs[], sys_ddr_write_delay_field6_masks[], sys_ddr_write_delay_field6_shifts[], sys_ddr_write_delay_field2_regs[], sys_ddr_write_delay_field2_masks[], sys_ddr_write_delay_field2_shifts[], sys_ddr_write_delay_field1_regs[], sys_ddr_write_delay_field1_masks[], sys_ddr_write_delay_field1_shifts[], DAT_a8026798_clk_cdly_reg[], DAT_a8026788_clk_cdly_msk[], DAT_a8026778_clk_cdly_sft[], DAT_a8026748_eye_lcdly_reg[], DAT_a8026738_eye_lcdly_msk[], DAT_a8026728_eye_lcdly_sft[];

/*
 * Put the write delay of a data byte at the saved starting value plus a number of steps.
 *
 *   unit  memory interface number
 *   byte  data byte; with -1 the tables' own addresses are passed in place of an entry
 *   step  distance from the starting value
 *
 * The starting value is sys_ddr_write_delay_field5_value, the value of field 5 that sys_ddr_train_write_eye
 * reads before it searches. Written: field 5 = start, field 4 = start + step, field 3 = start + step - 4,
 * field 6 = 3 for a step above 8 and 0 otherwise; then the four finer fields (field 2, field 1, clk_cdly and
 * wr_eye_lcdly) are cleared. Called by sys_ddr_find_write_window_lower_edge and sys_ddr_train_write_eye.
 */
void sys_ddr_set_write_delay_fields(unsigned int unit, int byte, int step)
{
    if (byte == -1)
        sys_ddr_phy_write_field(unit, (unsigned int)sys_ddr_write_delay_field5_regs, (unsigned int)sys_ddr_write_delay_field5_masks, (unsigned int)sys_ddr_write_delay_field5_shifts, sys_ddr_write_delay_field5_value);
    else
        sys_ddr_phy_write_field(unit, sys_ddr_write_delay_field5_regs[byte], sys_ddr_write_delay_field5_masks[byte], sys_ddr_write_delay_field5_shifts[byte], sys_ddr_write_delay_field5_value);
    if (byte == -1)
        sys_ddr_phy_write_field(unit, (unsigned int)sys_ddr_write_delay_field4_regs, (unsigned int)sys_ddr_write_delay_field4_masks, (unsigned int)sys_ddr_write_delay_field4_shifts, sys_ddr_write_delay_field5_value + step);
    else
        sys_ddr_phy_write_field(unit, sys_ddr_write_delay_field4_regs[byte], sys_ddr_write_delay_field4_masks[byte], sys_ddr_write_delay_field4_shifts[byte], sys_ddr_write_delay_field5_value + step);
    if (byte == -1)
        sys_ddr_phy_write_field(unit, (unsigned int)sys_ddr_write_delay_field3_regs, (unsigned int)sys_ddr_write_delay_field3_masks, (unsigned int)sys_ddr_write_delay_field3_shifts, sys_ddr_write_delay_field5_value + step - 4);
    else
        sys_ddr_phy_write_field(unit, sys_ddr_write_delay_field3_regs[byte], sys_ddr_write_delay_field3_masks[byte], sys_ddr_write_delay_field3_shifts[byte], sys_ddr_write_delay_field5_value + step - 4);
    if (step > 8) {
        if (byte == -1)
            sys_ddr_phy_write_field(unit, (unsigned int)sys_ddr_write_delay_field6_regs, (unsigned int)sys_ddr_write_delay_field6_masks, (unsigned int)sys_ddr_write_delay_field6_shifts, 3);
        else
            sys_ddr_phy_write_field(unit, sys_ddr_write_delay_field6_regs[byte], sys_ddr_write_delay_field6_masks[byte], sys_ddr_write_delay_field6_shifts[byte], 3);
    } else {
        if (byte == -1)
            sys_ddr_phy_write_field(unit, (unsigned int)sys_ddr_write_delay_field6_regs, (unsigned int)sys_ddr_write_delay_field6_masks, (unsigned int)sys_ddr_write_delay_field6_shifts, 0);
        else
            sys_ddr_phy_write_field(unit, sys_ddr_write_delay_field6_regs[byte], sys_ddr_write_delay_field6_masks[byte], sys_ddr_write_delay_field6_shifts[byte], 0);
    }
    if (byte == -1)
        sys_ddr_phy_write_field(unit, (unsigned int)sys_ddr_write_delay_field2_regs, (unsigned int)sys_ddr_write_delay_field2_masks, (unsigned int)sys_ddr_write_delay_field2_shifts, 0);
    else
        sys_ddr_phy_write_field(unit, sys_ddr_write_delay_field2_regs[byte], sys_ddr_write_delay_field2_masks[byte], sys_ddr_write_delay_field2_shifts[byte], 0);
    if (byte == -1)
        sys_ddr_phy_write_field(unit, (unsigned int)sys_ddr_write_delay_field1_regs, (unsigned int)sys_ddr_write_delay_field1_masks, (unsigned int)sys_ddr_write_delay_field1_shifts, 0);
    else
        sys_ddr_phy_write_field(unit, sys_ddr_write_delay_field1_regs[byte], sys_ddr_write_delay_field1_masks[byte], sys_ddr_write_delay_field1_shifts[byte], 0);
    if (byte == -1)
        sys_ddr_phy_write_field(unit, (unsigned int)DAT_a8026798_clk_cdly_reg, (unsigned int)DAT_a8026788_clk_cdly_msk, (unsigned int)DAT_a8026778_clk_cdly_sft, 0);
    else
        sys_ddr_phy_write_field(unit, DAT_a8026798_clk_cdly_reg[byte], DAT_a8026788_clk_cdly_msk[byte], DAT_a8026778_clk_cdly_sft[byte], 0);
    if (byte == -1)
        sys_ddr_phy_write_field(unit, (unsigned int)DAT_a8026748_eye_lcdly_reg, (unsigned int)DAT_a8026738_eye_lcdly_msk, (unsigned int)DAT_a8026728_eye_lcdly_sft, 0);
    else
        sys_ddr_phy_write_field(unit, DAT_a8026748_eye_lcdly_reg[byte], DAT_a8026738_eye_lcdly_msk[byte], DAT_a8026728_eye_lcdly_sft[byte], 0);
}
