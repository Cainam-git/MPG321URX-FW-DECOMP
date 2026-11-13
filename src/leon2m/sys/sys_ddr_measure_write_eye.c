/* sys_ddr_measure_write_eye  (FUN_a00edc70)
 *
 * Measure the write window with six fields saved and restored.
 * Name basis: derived - sys_ddr_train_write_eye in between; scales the two results
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00edc70 @ 0xa00edc70-0xa00ee188, flags -mcpu=v8 -O3 -g.
 * Source form the exact build depends on: each read and write is its own if (byte == -1)/else statement; the
 * table at 0xa8026718 is declared as sys_ddr_write_delay_field1_regs: the symbol name sets the order of the address pseudos and so
 * the register choices.
 */
struct write_window { int low; int high; };
extern void sys_ddr_delay(unsigned int);
extern void sys_ddr_send_mode_register(unsigned int, unsigned int, unsigned int, unsigned int);
extern unsigned int sys_ddr_phy_read_field(unsigned int, unsigned int, unsigned int, unsigned int);
extern void sys_ddr_phy_write_field(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
extern struct write_window sys_ddr_train_write_eye(unsigned int, unsigned int, unsigned int, int, unsigned int, unsigned int);
extern unsigned char sys_ddr_vref_table[][3];
extern unsigned int sys_ddr_write_delay_field4_regs[], sys_ddr_write_delay_field4_masks[], sys_ddr_write_delay_field4_shifts[];
extern unsigned int sys_ddr_write_delay_field3_regs[], sys_ddr_write_delay_field3_masks[], sys_ddr_write_delay_field3_shifts[];
extern unsigned int DAT_a8026798_clk_cdly_reg[], DAT_a8026788_clk_cdly_msk[], DAT_a8026778_clk_cdly_sft[];
extern unsigned int sys_ddr_write_delay_field2_regs[], sys_ddr_write_delay_field2_masks[], sys_ddr_write_delay_field2_shifts[];
extern unsigned int DAT_a8026748_eye_lcdly_reg[], DAT_a8026738_eye_lcdly_msk[], DAT_a8026728_eye_lcdly_sft[];
extern unsigned int sys_ddr_write_delay_field1_regs[], sys_ddr_write_delay_field1_masks[], sys_ddr_write_delay_field1_shifts[];


/*
 * Set one reference voltage step, run the write window training with it and return the window it finds.
 *
 *   unit            memory interface number
 *   phy_version     with ddr_generation, passed on to the write window training
 *   ddr_generation
 *   tccd_index      the tCCD_L index (0..3) put into bits 10 and up of the mode register 6 value
 *   vref_index      row of sys_ddr_vref_table (three bytes: mode register 6 value and the percentage)
 *   byte            data byte; with -1 the tables' own addresses are passed in place of an entry
 *   delay_per_count the dly_per_cnt field value that the caller has read
 *   bit_mode        passed on to the write window training
 *   delay_step      passed on to the write window training as its starting step
 *
 * Returns the two edges of the window, each scaled to delay units as (edge >> 8) * delay_per_count +
 * (edge & 0xFF); both -1 when the index is not valid (above 0x49, or the table byte & 0x3F above 0x32) or when
 * the training found no window. Called by sys_ddr_train_vref, which compares the windows of several steps.
 *
 * Mode register 6 is sent twice: first with only the tCCD_L index and bit 7, then, after a delay of 1, with the
 * table byte added. The six write delay fields (field 4, field 3, clk_cdly, field 2, wr_eye_lcdly, field 1) are
 * saved before the training and written back after it, so the measurement leaves the delays as they were.
 */
struct write_window sys_ddr_measure_write_eye(unsigned int unit, unsigned int phy_version, unsigned int ddr_generation, unsigned int tccd_index, unsigned int vref_index, int byte,
                        int delay_per_count, unsigned int bit_mode, unsigned int delay_step)
{
    struct write_window window;
    unsigned char vref_value;
    unsigned int saved_field4, saved_field3, saved_clk_cdly, saved_field2, saved_eye_lcdly, saved_field1;

    /* Reject a row beyond the table or with a mode register value above 0x32 (low six bits). */
    if (vref_index > 0x49 || (sys_ddr_vref_table[vref_index][0] & 0x3f) > 0x32U) {
        window.high = -1;
        window.low = -1;
        return window;
    }
    vref_value = sys_ddr_vref_table[vref_index][0];
    /* Mode register 6: bit 7 alone first, then the chosen step. */
    sys_ddr_send_mode_register(unit, 6, 6, (tccd_index << 10) | 0x80);
    sys_ddr_delay(1);
    sys_ddr_send_mode_register(unit, 6, 6, (tccd_index << 10) | vref_value | 0x80);
    /* Save the six write delay fields; the training changes them. */
    if (byte == -1)
        saved_field4 = sys_ddr_phy_read_field(unit, (unsigned int)sys_ddr_write_delay_field4_regs, (unsigned int)sys_ddr_write_delay_field4_masks, (unsigned int)sys_ddr_write_delay_field4_shifts);
    else
        saved_field4 = sys_ddr_phy_read_field(unit, sys_ddr_write_delay_field4_regs[byte], sys_ddr_write_delay_field4_masks[byte], sys_ddr_write_delay_field4_shifts[byte]);
    if (byte == -1)
        saved_field3 = sys_ddr_phy_read_field(unit, (unsigned int)sys_ddr_write_delay_field3_regs, (unsigned int)sys_ddr_write_delay_field3_masks, (unsigned int)sys_ddr_write_delay_field3_shifts);
    else
        saved_field3 = sys_ddr_phy_read_field(unit, sys_ddr_write_delay_field3_regs[byte], sys_ddr_write_delay_field3_masks[byte], sys_ddr_write_delay_field3_shifts[byte]);
    if (byte == -1)
        saved_clk_cdly = sys_ddr_phy_read_field(unit, (unsigned int)DAT_a8026798_clk_cdly_reg, (unsigned int)DAT_a8026788_clk_cdly_msk, (unsigned int)DAT_a8026778_clk_cdly_sft);
    else
        saved_clk_cdly = sys_ddr_phy_read_field(unit, DAT_a8026798_clk_cdly_reg[byte], DAT_a8026788_clk_cdly_msk[byte], DAT_a8026778_clk_cdly_sft[byte]);
    if (byte == -1)
        saved_field2 = sys_ddr_phy_read_field(unit, (unsigned int)sys_ddr_write_delay_field2_regs, (unsigned int)sys_ddr_write_delay_field2_masks, (unsigned int)sys_ddr_write_delay_field2_shifts);
    else
        saved_field2 = sys_ddr_phy_read_field(unit, sys_ddr_write_delay_field2_regs[byte], sys_ddr_write_delay_field2_masks[byte], sys_ddr_write_delay_field2_shifts[byte]);
    if (byte == -1)
        saved_eye_lcdly = sys_ddr_phy_read_field(unit, (unsigned int)DAT_a8026748_eye_lcdly_reg, (unsigned int)DAT_a8026738_eye_lcdly_msk, (unsigned int)DAT_a8026728_eye_lcdly_sft);
    else
        saved_eye_lcdly = sys_ddr_phy_read_field(unit, DAT_a8026748_eye_lcdly_reg[byte], DAT_a8026738_eye_lcdly_msk[byte], DAT_a8026728_eye_lcdly_sft[byte]);
    if (byte == -1)
        saved_field1 = sys_ddr_phy_read_field(unit, (unsigned int)sys_ddr_write_delay_field1_regs, (unsigned int)sys_ddr_write_delay_field1_masks, (unsigned int)sys_ddr_write_delay_field1_shifts);
    else
        saved_field1 = sys_ddr_phy_read_field(unit, sys_ddr_write_delay_field1_regs[byte], sys_ddr_write_delay_field1_masks[byte], sys_ddr_write_delay_field1_shifts[byte]);
    /* Train with the new reference voltage; the argument order is that of sys_ddr_train_write_eye. */
    window = sys_ddr_train_write_eye(unit, phy_version, ddr_generation, byte, delay_step, bit_mode);
    if (byte == -1)
        sys_ddr_phy_write_field(unit, (unsigned int)sys_ddr_write_delay_field4_regs, (unsigned int)sys_ddr_write_delay_field4_masks, (unsigned int)sys_ddr_write_delay_field4_shifts, saved_field4);
    else
        sys_ddr_phy_write_field(unit, sys_ddr_write_delay_field4_regs[byte], sys_ddr_write_delay_field4_masks[byte], sys_ddr_write_delay_field4_shifts[byte], saved_field4);
    if (byte == -1)
        sys_ddr_phy_write_field(unit, (unsigned int)sys_ddr_write_delay_field3_regs, (unsigned int)sys_ddr_write_delay_field3_masks, (unsigned int)sys_ddr_write_delay_field3_shifts, saved_field3);
    else
        sys_ddr_phy_write_field(unit, sys_ddr_write_delay_field3_regs[byte], sys_ddr_write_delay_field3_masks[byte], sys_ddr_write_delay_field3_shifts[byte], saved_field3);
    if (byte == -1)
        sys_ddr_phy_write_field(unit, (unsigned int)DAT_a8026798_clk_cdly_reg, (unsigned int)DAT_a8026788_clk_cdly_msk, (unsigned int)DAT_a8026778_clk_cdly_sft, saved_clk_cdly);
    else
        sys_ddr_phy_write_field(unit, DAT_a8026798_clk_cdly_reg[byte], DAT_a8026788_clk_cdly_msk[byte], DAT_a8026778_clk_cdly_sft[byte], saved_clk_cdly);
    if (byte == -1)
        sys_ddr_phy_write_field(unit, (unsigned int)sys_ddr_write_delay_field2_regs, (unsigned int)sys_ddr_write_delay_field2_masks, (unsigned int)sys_ddr_write_delay_field2_shifts, saved_field2);
    else
        sys_ddr_phy_write_field(unit, sys_ddr_write_delay_field2_regs[byte], sys_ddr_write_delay_field2_masks[byte], sys_ddr_write_delay_field2_shifts[byte], saved_field2);
    if (byte == -1)
        sys_ddr_phy_write_field(unit, (unsigned int)DAT_a8026748_eye_lcdly_reg, (unsigned int)DAT_a8026738_eye_lcdly_msk, (unsigned int)DAT_a8026728_eye_lcdly_sft, saved_eye_lcdly);
    else
        sys_ddr_phy_write_field(unit, DAT_a8026748_eye_lcdly_reg[byte], DAT_a8026738_eye_lcdly_msk[byte], DAT_a8026728_eye_lcdly_sft[byte], saved_eye_lcdly);
    if (byte == -1)
        sys_ddr_phy_write_field(unit, (unsigned int)sys_ddr_write_delay_field1_regs, (unsigned int)sys_ddr_write_delay_field1_masks, (unsigned int)sys_ddr_write_delay_field1_shifts, saved_field1);
    else
        sys_ddr_phy_write_field(unit, sys_ddr_write_delay_field1_regs[byte], sys_ddr_write_delay_field1_masks[byte], sys_ddr_write_delay_field1_shifts[byte], saved_field1);
    if (window.high == -1 && window.low == -1)
        return window;
    /* Convert each edge from (count << 8 | rest) to delay units. */
    window.low = (window.low >> 8) * delay_per_count + (window.low & 0xff);
    window.high = (window.high >> 8) * delay_per_count + (window.high & 0xff);
    return window;
}
