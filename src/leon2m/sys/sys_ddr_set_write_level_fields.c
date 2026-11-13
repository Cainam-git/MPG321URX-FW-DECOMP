/* sys_ddr_set_write_level_fields  (FUN_a00ed530)
 *
 * Write a write-levelling step into the fields of a data byte.
 * Name basis: descriptive - value & 0xF and a carry flag for values 6..11
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00ed530 @ 0xa00ed530, flags -mcpu=v8 -O3 (no -g: the -g build puts a nop between the last call and
 * the return).
 * Source form: each write is its own if (byte_idx == -1)/else statement (as in sys_ddr_train_write_leveling); step is masked to
 * 4 bits first.
 */
extern void sys_ddr_phy_write_field(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
extern unsigned int sys_ddr_write_delay_field5_regs[], sys_ddr_write_delay_field5_masks[], sys_ddr_write_delay_field5_shifts[];
extern unsigned int sys_ddr_write_level_field1_regs[], sys_ddr_write_level_field1_masks[], sys_ddr_write_level_field1_shifts[];
extern unsigned int sys_ddr_write_level_field2_regs[], sys_ddr_write_level_field2_masks[], sys_ddr_write_level_field2_shifts[];

/*
 * Write write-levelling step `step` (low 4 bits) into data byte `byte_idx` of memory interface `unit`.
 *
 * The step goes to the field of the sys_ddr_write_delay_field5_* tables. The two fields of the
 * sys_ddr_write_level_field1_* and _field2_* tables are then both set to 0 when the step is 6..11, and to 1 for
 * every other step.
 *
 * Each field is entry `byte_idx` of three parallel tables (register, mask, shift). With byte_idx == -1 the three
 * table addresses themselves are handed to the register access routine instead of an entry.
 * Always returns 0. Called by the write levelling (sys_ddr_train_write_leveling).
 */
int sys_ddr_set_write_level_fields(unsigned int unit, int byte_idx, unsigned char step)
{
    step &= 0xf;
    if (byte_idx == -1)
        sys_ddr_phy_write_field(unit, (unsigned int)sys_ddr_write_delay_field5_regs, (unsigned int)sys_ddr_write_delay_field5_masks, (unsigned int)sys_ddr_write_delay_field5_shifts, step & 0xf);
    else
        sys_ddr_phy_write_field(unit, sys_ddr_write_delay_field5_regs[byte_idx], sys_ddr_write_delay_field5_masks[byte_idx], sys_ddr_write_delay_field5_shifts[byte_idx], step & 0xf);
    if ((unsigned char)(step - 6) <= 5) {
        if (byte_idx == -1)
            sys_ddr_phy_write_field(unit, (unsigned int)sys_ddr_write_level_field1_regs, (unsigned int)sys_ddr_write_level_field1_masks, (unsigned int)sys_ddr_write_level_field1_shifts, 0);
        else
            sys_ddr_phy_write_field(unit, sys_ddr_write_level_field1_regs[byte_idx], sys_ddr_write_level_field1_masks[byte_idx], sys_ddr_write_level_field1_shifts[byte_idx], 0);
        if (byte_idx == -1)
            sys_ddr_phy_write_field(unit, (unsigned int)sys_ddr_write_level_field2_regs, (unsigned int)sys_ddr_write_level_field2_masks, (unsigned int)sys_ddr_write_level_field2_shifts, 0);
        else
            sys_ddr_phy_write_field(unit, sys_ddr_write_level_field2_regs[byte_idx], sys_ddr_write_level_field2_masks[byte_idx], sys_ddr_write_level_field2_shifts[byte_idx], 0);
    } else {
        if (byte_idx == -1)
            sys_ddr_phy_write_field(unit, (unsigned int)sys_ddr_write_level_field1_regs, (unsigned int)sys_ddr_write_level_field1_masks, (unsigned int)sys_ddr_write_level_field1_shifts, 1);
        else
            sys_ddr_phy_write_field(unit, sys_ddr_write_level_field1_regs[byte_idx], sys_ddr_write_level_field1_masks[byte_idx], sys_ddr_write_level_field1_shifts[byte_idx], 1);
        if (byte_idx == -1)
            sys_ddr_phy_write_field(unit, (unsigned int)sys_ddr_write_level_field2_regs, (unsigned int)sys_ddr_write_level_field2_masks, (unsigned int)sys_ddr_write_level_field2_shifts, 1);
        else
            sys_ddr_phy_write_field(unit, sys_ddr_write_level_field2_regs[byte_idx], sys_ddr_write_level_field2_masks[byte_idx], sys_ddr_write_level_field2_shifts[byte_idx], 1);
    }
    return 0;
}
