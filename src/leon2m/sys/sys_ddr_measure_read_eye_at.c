/* sys_ddr_measure_read_eye_at  (FUN_a00e9b34)
 *
 * Set three fields and measure the read window at that setting.
 * Returns: left and right edge
 * Name basis: derived - then sys_ddr_find_read_eye
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00e9b34 @ 0xa00e9b34, flags -mcpu=v8 -O3 -g.
 * Source form: each write is its own if (byte_idx == -1)/else statement (as in sys_ddr_train_read_eye); the structure
 * result is stored in a local and returned from it (the copy through fp-16 into the caller's return slot).
 */
/* The two values sys_ddr_find_read_eye returns. */
struct read_eye_result { int first; int second; };
extern void sys_ddr_phy_write_field(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
extern struct read_eye_result sys_ddr_find_read_eye(unsigned int, unsigned int, unsigned int, int, unsigned int);
extern unsigned int sys_ddr_read_deskew_field3_regs[], sys_ddr_read_deskew_field3_masks[], sys_ddr_read_deskew_field3_shifts[];
extern unsigned int sys_ddr_read_eye_field2_regs[], sys_ddr_read_eye_field2_masks[], sys_ddr_read_eye_field2_shifts[];
extern unsigned int sys_ddr_read_eye_field1_regs[], sys_ddr_read_eye_field1_masks[], sys_ddr_read_eye_field1_shifts[];

/*
 * Write three register fields of data byte `byte_idx` of memory interface `unit`, then run
 * sys_ddr_find_read_eye and return its result.
 *
 *   deskew_value  goes to the field of the read deskew tables (sys_ddr_read_deskew_field3_*)
 *   eye_value     goes to both fields of the read eye tables (sys_ddr_read_eye_field1_*, _field2_*)
 *   arg2, arg3, arg6   passed on to sys_ddr_find_read_eye unchanged
 *
 * Each field is entry `byte_idx` of three parallel tables (register, mask, shift). With byte_idx == -1 the three
 * table addresses themselves are handed to the register access routine instead of an entry.
 * Called by sys_ddr_train_read_eye (sys_ddr_train_read_eye).
 */
struct read_eye_result sys_ddr_measure_read_eye_at(unsigned int unit, unsigned int arg2, unsigned int arg3, int eye_value, int byte_idx, int deskew_value, unsigned int arg6)
{
    struct read_eye_result result;

    if (byte_idx == -1)
        sys_ddr_phy_write_field(unit, (unsigned int)sys_ddr_read_deskew_field3_regs, (unsigned int)sys_ddr_read_deskew_field3_masks, (unsigned int)sys_ddr_read_deskew_field3_shifts, deskew_value);
    else
        sys_ddr_phy_write_field(unit, sys_ddr_read_deskew_field3_regs[byte_idx], sys_ddr_read_deskew_field3_masks[byte_idx], sys_ddr_read_deskew_field3_shifts[byte_idx], deskew_value);
    if (byte_idx == -1)
        sys_ddr_phy_write_field(unit, (unsigned int)sys_ddr_read_eye_field2_regs, (unsigned int)sys_ddr_read_eye_field2_masks, (unsigned int)sys_ddr_read_eye_field2_shifts, eye_value);
    else
        sys_ddr_phy_write_field(unit, sys_ddr_read_eye_field2_regs[byte_idx], sys_ddr_read_eye_field2_masks[byte_idx], sys_ddr_read_eye_field2_shifts[byte_idx], eye_value);
    if (byte_idx == -1)
        sys_ddr_phy_write_field(unit, (unsigned int)sys_ddr_read_eye_field1_regs, (unsigned int)sys_ddr_read_eye_field1_masks, (unsigned int)sys_ddr_read_eye_field1_shifts, eye_value);
    else
        sys_ddr_phy_write_field(unit, sys_ddr_read_eye_field1_regs[byte_idx], sys_ddr_read_eye_field1_masks[byte_idx], sys_ddr_read_eye_field1_shifts[byte_idx], eye_value);
    result = sys_ddr_find_read_eye(unit, arg2, arg3, byte_idx, arg6);
    return result;
}
