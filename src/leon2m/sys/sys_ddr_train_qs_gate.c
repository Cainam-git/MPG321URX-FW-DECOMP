/* sys_ddr_train_qs_gate  (FUN_a00e7254)
 *
 * Run the strobe gate training for one data byte (0..3), saving and restoring nine registers.
 * Returns: 0, -1 after an error, or the non-zero result of sys_ddr_train_qs_gate_byte or of the final gate
 *   move
 * Note: Any other byte value returns -1 before anything is changed; a failed byte training returns at once
 *   without restoring the registers.
 * Name basis: proven - prints 'Error: byte_idx sould be 0 ~ 3. Please check !!!'
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00e7254 @ 0xa00e7254-0xa00e7dc8 (2932 bytes), flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on:
 *  - each field write is its own 'if (byte == -1) .. else ..' statement (SET_FIELD); the reads compared in a
 *    condition are conditional expressions of two calls (FIELD_VALUE: '(byte == -1 ? read(..) : read(..)) != 0');
 *  - the run count update is 'if (..) hits_in_row++; else hits_in_row = 0;';
 *  - sys_ddr_phy_update_bits is declared void;
 *  - the table at 0xa8026468 is declared as sys_ddr_qs_gate_field1_shifts (the symbol name sets the order of the loop-invariant
 *    address pseudos); DAT_a8026698_qs_gate_dly_*_tbl and DAT_a80265d8_reg .. are spelled as in sys_ddr_move_qs_gate /
 *    sys_ddr_search_qs_gate_late;
 *  - the sweep counter `steps` is also the variable of the final 'return steps;' (steps = 0 before the
 *    final_offset test), which sets the register choice of the three loop-invariant qs_gate_dly table addresses.
 */
extern int sys_ddr_phy_read(unsigned int, unsigned int);
extern void sys_ddr_phy_write();
extern unsigned int sys_ddr_phy_read_masked(unsigned int, unsigned int, unsigned int);
extern void sys_ddr_phy_update_bits(unsigned int, unsigned int, unsigned int, unsigned int);
extern unsigned int sys_ddr_phy_read_field(unsigned int, unsigned int, unsigned int, unsigned int);
extern void sys_ddr_phy_write_field(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
extern void sys_ddr_send_mode_register(unsigned int, unsigned int, unsigned int, unsigned int);
extern unsigned int sys_ddr_read_reg1b_word(unsigned int);
extern int sys_ddr_move_qs_gate(unsigned int, int, int);
extern int sys_ddr_train_qs_gate_byte();
extern void sys_ddr_set_step(unsigned int, unsigned int, unsigned int);
extern int sys_ddr_check_arguments(unsigned int, unsigned int, unsigned int);
extern void sys_ddr_delay_short(int);
extern void sys_ddr_print_step(void);
extern void sys_ddr_print_error_prefix(void);
extern int dbg_printf(const char *, ...);
extern unsigned char sys_ddr_gate_pattern_low_byte;
extern unsigned int DAT_a80265d8_reg[], DAT_a80265c8_msk[], DAT_a80265b8_shift[], sys_ddr_qs_gate_field4_regs[], sys_ddr_qs_gate_field4_masks[], sys_ddr_qs_gate_field4_shifts[];
extern unsigned int sys_ddr_qs_gate_field3_regs[], sys_ddr_qs_gate_field3_masks[], sys_ddr_qs_gate_field3_shifts[], sys_ddr_qs_gate_field2_regs[], sys_ddr_qs_gate_field2_masks[], sys_ddr_qs_gate_field2_shifts[];
extern unsigned int sys_ddr_qsen_wrap_dly_regs[], sys_ddr_qsen_wrap_dly_masks[], sys_ddr_qsen_wrap_dly_shifts[], sys_ddr_qs_gate_sel_regs[], sys_ddr_qs_gate_sel_masks[], sys_ddr_qs_gate_sel_shifts[];
extern unsigned int DAT_a8026698_qs_gate_dly_reg_tbl[], DAT_a8026688_qs_gate_dly_mask_tbl[], DAT_a8026678_qs_gate_dly_shift_tbl[], sys_ddr_qs_gate_field1_regs[], sys_ddr_qs_gate_field1_masks[], sys_ddr_qs_gate_field1_shifts[];

/*
 * A field of a data byte is entry `byte` of three tables: register, mask and bit position. With byte == -1 the
 * addresses of the tables themselves are passed in place of an entry. The tables at 0xA8026698 / 0xA8026688 /
 * 0xA8026678 hold qs_gate_dly, and sys_ddr_qs_gate_field1_shifts holds the bit positions of qs_gate_field1. Field 0x5D8 = the
 * tables at 0xA80265D8 / 0xA80265C8 / 0xA80265B8.
 */
#define SET_FIELD(r, m, s, v)                                                               \
    do {                                                                                    \
        if (byte == -1)                                                                     \
            sys_ddr_phy_write_field(phy, (unsigned int)r, (unsigned int)m, (unsigned int)s, v);        \
        else                                                                                \
            sys_ddr_phy_write_field(phy, r[byte], m[byte], s[byte], v);                                \
    } while (0)
#define FIELD_VALUE(r, m, s)                                                                \
    (byte == -1 ? sys_ddr_phy_read_field(phy, (unsigned int)r, (unsigned int)m, (unsigned int)s)      \
                : sys_ddr_phy_read_field(phy, r[byte], m[byte], s[byte]))
#define SET_WRAP_DLY(v)     SET_FIELD(sys_ddr_qsen_wrap_dly_regs, sys_ddr_qsen_wrap_dly_masks, sys_ddr_qsen_wrap_dly_shifts, v)
#define SET_GATE_SEL(v)     SET_FIELD(sys_ddr_qs_gate_sel_regs, sys_ddr_qs_gate_sel_masks, sys_ddr_qs_gate_sel_shifts, v)
#define SET_GATE_DLY(v)     SET_FIELD(DAT_a8026698_qs_gate_dly_reg_tbl, DAT_a8026688_qs_gate_dly_mask_tbl, DAT_a8026678_qs_gate_dly_shift_tbl, v)
#define WRAP_DLY_VALUE      FIELD_VALUE(sys_ddr_qsen_wrap_dly_regs, sys_ddr_qsen_wrap_dly_masks, sys_ddr_qsen_wrap_dly_shifts)
#define GATE_SEL_VALUE      FIELD_VALUE(sys_ddr_qs_gate_sel_regs, sys_ddr_qs_gate_sel_masks, sys_ddr_qs_gate_sel_shifts)
#define GATE_DLY_VALUE      FIELD_VALUE(DAT_a8026698_qs_gate_dly_reg_tbl, DAT_a8026688_qs_gate_dly_mask_tbl, DAT_a8026678_qs_gate_dly_shift_tbl)
#define GATE_FIELD1_VALUE   FIELD_VALUE(sys_ddr_qs_gate_field1_regs, sys_ddr_qs_gate_field1_masks, sys_ddr_qs_gate_field1_shifts)

#define DDR3 3                          /* DDR generations accepted by sys_ddr_check_arguments */
#define DDR4 4
#define DDR_STEP_QSEN 6                 /* training step number, printed as "QSEN" in the error messages */
#define LAST_BYTE 3                     /* data bytes 0..3 */

/*
 * Strobe gate training of one data byte (training step QSEN). One of the memory training steps that
 * sys_ddr_run_script runs (script commands 49 and 57).
 *
 *   phy           memory interface
 *   phy_version   version of the interface, checked together with phy and generation
 *   generation    DDR3 or DDR4
 *   byte          data byte 0..3; any other value, -1 included (the test is unsigned), prints "byte_idx sould
 *                 be 0 ~ 3" and returns -1 before anything is changed
 *   sweep         non-zero: run the sweep of phase 2a in place of phases 2b and 3
 *   sweep_to_end  for the sweep: 0 ends it where the gate is first placed, non-zero lets it run on
 *   offset_down   non-zero: final_offset is applied downwards
 *   final_offset  gate steps (sys_ddr_move_qs_gate) applied at the end; 0 = none
 *
 * sys_ddr_run_script passes 0 for sweep and sweep_to_end. Script command 57 passes its argument bytes 4 and 5
 * as offset_down and final_offset; command 49 passes 0 for both.
 *
 * Returns 0, -1 after printing an error, or the non-zero result of sys_ddr_train_qs_gate_byte or of the final
 * gate move. When sys_ddr_train_qs_gate_byte fails, the routine returns at once, without phase 4.
 *
 * Phases:
 *  1. Save registers 0x54, 0x149, 0x14B, 0x14A, 0x14C, 0x142, 0x11A, 0x121 and 0x102; record step QSEN for the
 *     error messages; check the arguments (the result is not used); check byte.
 *  2a. Sweep: field 0x5D8 = 0, qs_gate_field4 = 2, qs_gate_field3 = 0, qs_gate_field2 = 0, qsen_wrap_dly = 0,
 *     qs_gate_sel = 1, qs_gate_dly = 0xD; all bits of registers 0x149 and 0x14A and bits 0xC0 of registers
 *     0xDE and 0xE1 set. Each round sends command 5 (0x1000), counts the round (n) and counts the rounds in a
 *     row in which qs_gate_field1 reads non-zero. When that run passes 5 rounds (DDR3) or 9 rounds (DDR4) the
 *     gate is placed from n: qsen_wrap_dly = n / 16 - 1 (DDR3; with n below 16 the message "idx < 16, cannot
 *     -16." ends the sweep) or n / 16 (DDR4), qs_gate_dly = (n + 13) & 0xF, qs_gate_sel = 3 when bit 3 of n is
 *     set, else 1. After each round the gate moves one step up; the sweep ends when that move fails, when
 *     qs_gate_dly, qs_gate_sel and qsen_wrap_dly read 0xC, 3 and 15, or (sweep_to_end 0) when the gate has been
 *     placed. The last two ends set the register bits of the start once more.
 *  2b. Command 2 (0x400). DDR3: command 6 (field 3, value 4) and the bits 0x07 / 0x70 / 0x07 / 0x70 of
 *     registers 0x142 / 0x11A / 0x121 / 0x102 cleared; DDR4: command 6 with the value of registers 0x1B/0x1C
 *     masked with 0x7F8, bit 2 set. Then DDR3: bits 0xC0 of registers 0xDE and 0xE1 set, register 0x149 =
 *     0xFF, 0x14A = 0, 0x14C = 0, the low 5 bits of registers 0x241 and 0x242 saved and set to 0x1F, bit 7 of
 *     register 0x240 set; DDR4: command 0xB with sys_ddr_gate_pattern_low_byte.
 *  3. sys_ddr_train_qs_gate_byte. Then DDR3: bits 0xC0 of registers 0xDE and 0xE1 cleared, registers 0x149,
 *     0x14A and 0x14C = 0, the low 3 bits of registers 0x142 and 0x121 = 1, bits 0x70 of registers 0x11A and
 *     0x102 = 0x10, the saved low 5 bits of registers 0x241 and 0x242 back, a short delay. Command 6 with the
 *     value of registers 0x1B/0x1C masked with 0x1FF8.
 *  4. Write the nine saved registers back and move the gate by final_offset (negated when offset_down is set).
 */
int sys_ddr_train_qs_gate(unsigned int phy, unsigned int phy_version, unsigned int generation, unsigned int byte,
                 unsigned int sweep, unsigned int sweep_to_end, int offset_down, int final_offset)
{
    unsigned int saved_reg54, saved_reg149, saved_reg14b, saved_reg14a, saved_reg14c, saved_reg142, saved_reg11a, saved_reg121, saved_reg102;
    unsigned int saved_reg241, saved_reg242, steps, hits_in_row;
    int result;

    /* Phase 1: save, record the step, check. */
    saved_reg54 = sys_ddr_phy_read(phy, 0x54);
    saved_reg149 = sys_ddr_phy_read(phy, 0x149);
    saved_reg14b = sys_ddr_phy_read(phy, 0x14b);
    saved_reg14a = sys_ddr_phy_read(phy, 0x14a);
    saved_reg14c = sys_ddr_phy_read(phy, 0x14c);
    saved_reg142 = sys_ddr_phy_read(phy, 0x142);
    saved_reg11a = sys_ddr_phy_read(phy, 0x11a);
    saved_reg121 = sys_ddr_phy_read(phy, 0x121);
    saved_reg102 = sys_ddr_phy_read(phy, 0x102);
    sys_ddr_set_step(DDR_STEP_QSEN, phy, byte);
    sys_ddr_check_arguments(phy, phy_version, generation);
    saved_reg241 = 0;
    saved_reg242 = 0;
    if (byte > LAST_BYTE) {
        sys_ddr_print_step();
        sys_ddr_print_error_prefix();
        dbg_printf("Error: byte_idx sould be 0 ~ 3. Please check !!!\n");
        return -1;
    }
    if (sweep != 0) {
        /* Phase 2a: the sweep. Start values. */
        SET_FIELD(DAT_a80265d8_reg, DAT_a80265c8_msk, DAT_a80265b8_shift, 0);
        SET_FIELD(sys_ddr_qs_gate_field4_regs, sys_ddr_qs_gate_field4_masks, sys_ddr_qs_gate_field4_shifts, 2);
        SET_FIELD(sys_ddr_qs_gate_field3_regs, sys_ddr_qs_gate_field3_masks, sys_ddr_qs_gate_field3_shifts, 0);
        SET_FIELD(sys_ddr_qs_gate_field2_regs, sys_ddr_qs_gate_field2_masks, sys_ddr_qs_gate_field2_shifts, 0);
        SET_WRAP_DLY(0);
        SET_GATE_SEL(1);
        SET_GATE_DLY(0xd);
        sys_ddr_phy_update_bits(phy, 0x149, 0xff, 0xff);
        sys_ddr_phy_update_bits(phy, 0x14a, 0xff, 0xff);
        sys_ddr_phy_update_bits(phy, 0xde, 0xc0, 0xc0);
        sys_ddr_phy_update_bits(phy, 0xe1, 0xc0, 0xc0);
        steps = 0;
        hits_in_row = 0;
        do {
            sys_ddr_send_mode_register(phy, 5, 0, 0x1000);
            steps++;
            if (GATE_FIELD1_VALUE != 0)
                hits_in_row++;
            else
                hits_in_row = 0;
            /* A long enough run places the gate from the round count. */
            if (generation == DDR3) {
                if (hits_in_row > 5) {
                    if (steps < 16) {
                        sys_ddr_print_step();
                        sys_ddr_print_error_prefix();
                        dbg_printf("idx < 16, cannot -16.\n");
                        goto restore;
                    }
                    SET_WRAP_DLY((steps >> 4) - 1);
                    SET_GATE_DLY((steps + 13) & 0xf);
                    SET_GATE_SEL((steps & 8) >> 2 | 1);
                    if (sweep_to_end == 0)
                        goto finish;
                    /* Sweep on; no generation matches any more, so the gate is placed only once. */
                    generation = 0;
                }
            } else if (generation == DDR4) {
                if (hits_in_row > 9) {
                    SET_WRAP_DLY(steps >> 4);
                    SET_GATE_DLY((steps + 13) & 0xf);
                    SET_GATE_SEL((steps & 8) >> 2 | 1);
                    if (sweep_to_end == 0)
                        goto finish;
                    generation = 0;
                }
            }
            if (GATE_DLY_VALUE == 0xc && GATE_SEL_VALUE == 3 && WRAP_DLY_VALUE == 0xf) {
finish:
                sys_ddr_phy_update_bits(phy, 0x149, 0xff, 0xff);
                sys_ddr_phy_update_bits(phy, 0x14a, 0xff, 0xff);
                sys_ddr_phy_update_bits(phy, 0xde, 0xc0, 0xc0);
                sys_ddr_phy_update_bits(phy, 0xe1, 0xc0, 0xc0);
                goto restore;
            }
        } while (sys_ddr_move_qs_gate(phy, byte, 1) == 0);
        goto restore;
    }
    /* Phase 2b: set-up for sys_ddr_train_qs_gate_byte. */
    sys_ddr_send_mode_register(phy, 2, 0, 0x400);
    if (generation == DDR3) {
        sys_ddr_send_mode_register(phy, 6, 3, 4);
        sys_ddr_phy_update_bits(phy, 0x142, 7, 0);
        sys_ddr_phy_update_bits(phy, 0x11a, 0x70, 0);
        sys_ddr_phy_update_bits(phy, 0x121, 7, 0);
        sys_ddr_phy_update_bits(phy, 0x102, 0x70, 0);
    } else if (generation == DDR4) {
        sys_ddr_send_mode_register(phy, 6, 3, (sys_ddr_read_reg1b_word(phy) & 0x7f8) | 4);
    }
    if (generation == DDR3) {
        sys_ddr_phy_update_bits(phy, 0xde, 0xc0, 0xc0);
        sys_ddr_phy_update_bits(phy, 0xe1, 0xc0, 0xc0);
        sys_ddr_phy_write(phy, 0x149, 0xff);
        sys_ddr_phy_write(phy, 0x14a, 0);
        sys_ddr_phy_write(phy, 0x14c, 0);
        saved_reg241 = sys_ddr_phy_read_masked(phy, 0x241, 0x1f);
        saved_reg242 = sys_ddr_phy_read_masked(phy, 0x242, 0x1f);
        sys_ddr_phy_update_bits(phy, 0x240, 0x80, 0x80);
        sys_ddr_phy_update_bits(phy, 0x241, 0x1f, 0x1f);
        sys_ddr_phy_update_bits(phy, 0x242, 0x1f, 0x1f);
    } else if (generation == DDR4) {
        sys_ddr_send_mode_register(phy, 0xb, 0, sys_ddr_gate_pattern_low_byte);
    }
    /* Phase 3: the training itself, then undo the DDR3 set-up. */
    result = sys_ddr_train_qs_gate_byte(phy, generation, byte);
    if (result != 0)
        return result;
    if (generation == DDR3) {
        sys_ddr_phy_update_bits(phy, 0xde, 0xc0, 0);
        sys_ddr_phy_update_bits(phy, 0xe1, 0xc0, 0);
        sys_ddr_phy_write(phy, 0x149, 0);
        sys_ddr_phy_write(phy, 0x14a, 0);
        sys_ddr_phy_write(phy, 0x14c, 0);
        sys_ddr_phy_update_bits(phy, 0x142, 7, 1);
        sys_ddr_phy_update_bits(phy, 0x11a, 0x70, 0x10);
        sys_ddr_phy_update_bits(phy, 0x121, 7, 1);
        sys_ddr_phy_update_bits(phy, 0x102, 0x70, 0x10);
        sys_ddr_phy_update_bits(phy, 0x241, 0x1f, saved_reg241);
        sys_ddr_phy_update_bits(phy, 0x242, 0x1f, saved_reg242);
        sys_ddr_delay_short(1);
    }
    sys_ddr_send_mode_register(phy, 6, 3, sys_ddr_read_reg1b_word(phy) & 0x1ff8);
restore:
    /* Phase 4: registers back, final gate offset. */
    sys_ddr_phy_write(phy, 0x54, saved_reg54);
    sys_ddr_phy_write(phy, 0x149, saved_reg149);
    sys_ddr_phy_write(phy, 0x14b, saved_reg14b);
    sys_ddr_phy_write(phy, 0x14a, saved_reg14a);
    sys_ddr_phy_write(phy, 0x14c, saved_reg14c);
    sys_ddr_phy_write(phy, 0x142, saved_reg142);
    sys_ddr_phy_write(phy, 0x11a, saved_reg11a);
    sys_ddr_phy_write(phy, 0x121, saved_reg121);
    sys_ddr_phy_write(phy, 0x102, saved_reg102);
    steps = 0;
    if (final_offset != 0) {
        if (offset_down != 0)
            final_offset = -final_offset;
        result = sys_ddr_move_qs_gate(phy, byte, final_offset);
        if (result != 0)
            return result;
    }
    return steps;
}
