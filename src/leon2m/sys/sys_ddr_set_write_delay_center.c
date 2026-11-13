/* sys_ddr_set_write_delay_center  (FUN_a00ec340)
 *
 * Write the centre of the write delay window into the fields of a data byte.
 * Name basis: descriptive - (left + right - 1) / 2 divided by n
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00ec340 @ 0xa00ec340-0xa00ec6b8, flags -mcpu=v8 -O3 -g.
 * Source form the exact build depends on: each read and write is its own if (byte == -1)/else statement (GCC
 * threads the repeated tests); the '+ whole_counts' is part of the read statement; whole_counts is an int; the
 * whole_counts > 8 arm first.
 */
extern unsigned int sys_ddr_phy_read_field(unsigned int, unsigned int, unsigned int, unsigned int);
extern void sys_ddr_phy_write_field(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
extern unsigned int sys_ddr_write_delay_field5_regs[], sys_ddr_write_delay_field5_masks[], sys_ddr_write_delay_field5_shifts[], sys_ddr_write_delay_field4_regs[], sys_ddr_write_delay_field4_masks[], sys_ddr_write_delay_field4_shifts[], sys_ddr_write_delay_field3_regs[], sys_ddr_write_delay_field3_masks[], sys_ddr_write_delay_field3_shifts[], sys_ddr_write_delay_field6_regs[], sys_ddr_write_delay_field6_masks[], sys_ddr_write_delay_field6_shifts[], DAT_a8026798_clk_cdly_reg[], DAT_a8026788_clk_cdly_msk[], DAT_a8026778_clk_cdly_sft[], DAT_a8026748_eye_lcdly_reg[], DAT_a8026738_eye_lcdly_msk[], DAT_a8026728_eye_lcdly_sft[], sys_ddr_write_delay_field2_regs[], sys_ddr_write_delay_field2_masks[], sys_ddr_write_delay_field2_shifts[], sys_ddr_write_delay_field1_regs[], sys_ddr_write_delay_field1_masks[], sys_ddr_write_delay_field1_shifts[];

/*
 * Set the write delay of a data byte to the middle of the window found by the write window search.
 *
 *   unit             memory interface number
 *   byte             data byte; with -1 the tables' own addresses are passed in place of an entry
 *   left_edge        the two edges of the passing window, in delay units
 *   right_edge
 *   delay_per_count  value of the dly_per_cnt field, read by the caller (sys_ddr_train_write_eye)
 *
 * The middle is (left_edge + right_edge - 1) / 2. It is split into whole_counts of delay_per_count units and a
 * remainder. The whole counts are added to field 5; the sum is written to field 4, the sum minus 4 to field 3,
 * and field 6 gets 3 for more than 8 whole counts, else 0. The remainder is written in two parts: bits 3..7 to
 * clk_cdly and wr_eye_lcdly, bits 0..2 to field 2 and field 1.
 */
void sys_ddr_set_write_delay_center(unsigned int unit, int byte, int left_edge, int right_edge, unsigned int delay_per_count)
{
    unsigned int centre, remainder, remainder_high, remainder_low;
    int whole_counts, field5_plus_counts;

    centre = (left_edge + right_edge - 1U) >> 1;
    whole_counts = centre / delay_per_count;
    remainder = centre - whole_counts * delay_per_count;
    remainder_high = (remainder >> 3) & 0x1f;
    remainder_low = remainder & 7;
    if (byte == -1)
        field5_plus_counts = sys_ddr_phy_read_field(unit, (unsigned int)sys_ddr_write_delay_field5_regs, (unsigned int)sys_ddr_write_delay_field5_masks, (unsigned int)sys_ddr_write_delay_field5_shifts) + whole_counts;
    else
        field5_plus_counts = sys_ddr_phy_read_field(unit, sys_ddr_write_delay_field5_regs[byte], sys_ddr_write_delay_field5_masks[byte], sys_ddr_write_delay_field5_shifts[byte]) + whole_counts;
    if (byte == -1)
        sys_ddr_phy_write_field(unit, (unsigned int)sys_ddr_write_delay_field4_regs, (unsigned int)sys_ddr_write_delay_field4_masks, (unsigned int)sys_ddr_write_delay_field4_shifts, field5_plus_counts);
    else
        sys_ddr_phy_write_field(unit, sys_ddr_write_delay_field4_regs[byte], sys_ddr_write_delay_field4_masks[byte], sys_ddr_write_delay_field4_shifts[byte], field5_plus_counts);
    if (byte == -1)
        sys_ddr_phy_write_field(unit, (unsigned int)sys_ddr_write_delay_field3_regs, (unsigned int)sys_ddr_write_delay_field3_masks, (unsigned int)sys_ddr_write_delay_field3_shifts, field5_plus_counts - 4);
    else
        sys_ddr_phy_write_field(unit, sys_ddr_write_delay_field3_regs[byte], sys_ddr_write_delay_field3_masks[byte], sys_ddr_write_delay_field3_shifts[byte], field5_plus_counts - 4);
    if (whole_counts > 8) {
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
        sys_ddr_phy_write_field(unit, (unsigned int)DAT_a8026798_clk_cdly_reg, (unsigned int)DAT_a8026788_clk_cdly_msk, (unsigned int)DAT_a8026778_clk_cdly_sft, remainder_high);
    else
        sys_ddr_phy_write_field(unit, DAT_a8026798_clk_cdly_reg[byte], DAT_a8026788_clk_cdly_msk[byte], DAT_a8026778_clk_cdly_sft[byte], remainder_high);
    if (byte == -1)
        sys_ddr_phy_write_field(unit, (unsigned int)DAT_a8026748_eye_lcdly_reg, (unsigned int)DAT_a8026738_eye_lcdly_msk, (unsigned int)DAT_a8026728_eye_lcdly_sft, remainder_high);
    else
        sys_ddr_phy_write_field(unit, DAT_a8026748_eye_lcdly_reg[byte], DAT_a8026738_eye_lcdly_msk[byte], DAT_a8026728_eye_lcdly_sft[byte], remainder_high);
    if (byte == -1)
        sys_ddr_phy_write_field(unit, (unsigned int)sys_ddr_write_delay_field2_regs, (unsigned int)sys_ddr_write_delay_field2_masks, (unsigned int)sys_ddr_write_delay_field2_shifts, remainder_low);
    else
        sys_ddr_phy_write_field(unit, sys_ddr_write_delay_field2_regs[byte], sys_ddr_write_delay_field2_masks[byte], sys_ddr_write_delay_field2_shifts[byte], remainder_low);
    if (byte == -1)
        sys_ddr_phy_write_field(unit, (unsigned int)sys_ddr_write_delay_field1_regs, (unsigned int)sys_ddr_write_delay_field1_masks, (unsigned int)sys_ddr_write_delay_field1_shifts, remainder_low);
    else
        sys_ddr_phy_write_field(unit, sys_ddr_write_delay_field1_regs[byte], sys_ddr_write_delay_field1_masks[byte], sys_ddr_write_delay_field1_shifts[byte], remainder_low);
}
