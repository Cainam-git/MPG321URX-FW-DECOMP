/* sys_ddr_train_qs_gate_byte  (FUN_a00e5fc8)
 *
 * Train the strobe gate of one data byte.
 * Name basis: proven - prints 'Error: qsen_wrap_dly_ b%d _reg = 15.'; search for the gate edge
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00e5fc8 @ 0xa00e5fc8-0xa00e724c (4740 bytes), flags -mcpu=v8 -O3 -g -msoft-float.
 * Source forms the exact build depends on:
 *  - register fields are read and written with the GET_FIELD / SET_FIELD statement macros (if (byte == -1) /
 *    else, as in sys_ddr_train_read_deskew); the six start-up writes qsen_dly_a_sel .. qs_gate_dly are one
 *    'if (byte == -1) { .. } else { .. }' block (one byte test, fw 0xa00e6050 / 0xa00e64e0);
 *  - the qs_gate_sel test and the qs_late bit tests use the conditional expression FIELD_VALUE (fw compares in
 *    both arms, 0xa00e61a8 / 0xa00e6294); the qsen_wrap_dly and qs_gate_field1 reads go into a variable that
 *    is compared once (0xa00e62fc, 0xa00e7080);
 *  - command 5 ends both arms of the first generation test (fw calls 0xa00e6014 and 0xa00e6430), written
 *    'if (generation != DDR3)' first: the other path keeps the second 'generation == DDR3' test (0xa00e601c)
 *    while the DDR3 path goes straight to the register switch (0xa00e6438);
 *  - the coarse loop handles a passing test inside its body ('if (check != 0) { first-try part;
 *    result = search_gate_edge(..); if (result != 0) return result; return 0; }'), and the qs_gate_sel == 3
 *    case ends with 'sys_ddr_reset_fifos(phy); continue;';
 *  - the edge search is the static helper search_gate_edge, inlined once, with plain returns; its result goes
 *    through 'if (result != 0) return result; return 0;' (0xa00e6950: cmp %g1, 0);
 *  - in each direction branch the step code and the qsen_dly_c_sel loop sit inside the wait loop (the 0x488 /
 *    0x4b8 / 0x668 table addresses are formed in the wait-loop preheader, 0xa00e674c..0xa00e677c); the bit-clear
 *    tests are written '(.. & 1) == 0' (with '!(..)' for the first one the two direction branches come out in
 *    the other order);
 *  - the qsen_dly_c_sel increment is its own 'value++;' statement between read and write (fw re-tests byte after
 *    the read at 0xa00e6c98 and 0xa00e6e24);
 *  - the -12 / 4 move is one call per arm of 'if (value == 1)' (0xa00e7080);
 *  - the qsen_dly_c_sel error test is 'at_max = sel == 7; if (late & at_max)' (0xa00e6d20: xor, subx, btst %l0
 *    and a separate btst 1 for the loop test);
 *  - the table spellings DAT_a8026698_qs_gate_dly_*_tbl, DAT_a8026668_qs_late_*, DAT_a80265d8_reg .. and
 *    sys_ddr_qs_gate_field1_shifts are those of sys_ddr_move_qs_gate / sys_ddr_search_qs_gate_late / sys_ddr_train_qs_gate: GCC orders the high parts of the
 *    table addresses by a hash of the symbol names.
 */
extern void sys_ddr_reset_fifos(unsigned int);
extern void sys_ddr_phy_write(unsigned int, unsigned int, unsigned int);
extern void sys_ddr_phy_update_bits(unsigned int, unsigned int, unsigned int, unsigned int);
extern unsigned int sys_ddr_phy_read_field(unsigned int, unsigned int, unsigned int, unsigned int);
extern void sys_ddr_phy_write_field(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
extern unsigned int sys_ddr_read_reg1b_word(unsigned int);
extern void sys_ddr_send_mode_register(unsigned int, unsigned int, unsigned int, unsigned int);
extern unsigned int sys_ddr_check_gate_fields(unsigned int, int, int);
extern int sys_ddr_add_qsen_wrap_delay(unsigned int, int, int);
extern int sys_ddr_move_qs_gate(unsigned int, int, int);
extern int sys_ddr_search_qs_gate_late(unsigned int, int, int);
extern void sys_ddr_print_step(void);
extern void sys_ddr_print_error_prefix(void);
extern int dbg_printf(const char *, ...);
extern unsigned int sys_ddr_gate_pattern;
extern unsigned int DAT_a80265d8_reg[], DAT_a80265c8_msk[], DAT_a80265b8_shift[];
extern unsigned int sys_ddr_qsen_dly_a_sel_regs[], sys_ddr_qsen_dly_a_sel_masks[], sys_ddr_qsen_dly_a_sel_shifts[];
extern unsigned int sys_ddr_qsen_dly_b_sel_regs[], sys_ddr_qsen_dly_b_sel_masks[], sys_ddr_qsen_dly_b_sel_shifts[];
extern unsigned int sys_ddr_qsen_dly_c_sel_regs[], sys_ddr_qsen_dly_c_sel_masks[], sys_ddr_qsen_dly_c_sel_shifts[];
extern unsigned int sys_ddr_qsen_wrap_dly_regs[], sys_ddr_qsen_wrap_dly_masks[], sys_ddr_qsen_wrap_dly_shifts[];
extern unsigned int sys_ddr_qs_gate_sel_regs[], sys_ddr_qs_gate_sel_masks[], sys_ddr_qs_gate_sel_shifts[];
extern unsigned int DAT_a8026698_qs_gate_dly_reg_tbl[], DAT_a8026688_qs_gate_dly_mask_tbl[], DAT_a8026678_qs_gate_dly_shift_tbl[];
extern unsigned int DAT_a8026668_qs_late_reg[], DAT_a8026658_qs_late_msk[], DAT_a8026648_qs_late_shift[];
extern unsigned int sys_ddr_qs_gate_field1_regs[], sys_ddr_qs_gate_field1_masks[], sys_ddr_qs_gate_field1_shifts[];

/*
 * A field of a data byte is entry `byte` of three tables: register, mask and bit position. With byte == -1 the
 * addresses of the tables themselves are passed in place of an entry. The tables at 0xA8026698 / 0xA8026688 /
 * 0xA8026678 hold qs_gate_dly, those at 0xA8026668 / 0xA8026658 / 0xA8026648 qs_late, and sys_ddr_qs_gate_field1_shifts holds the
 * bit positions of qs_gate_field1. Field 0x5D8 = the tables at 0xA80265D8 / 0xA80265C8 / 0xA80265B8.
 */
#define GET_FIELD(x, r, m, s)                                                               \
    do {                                                                                    \
        if (byte == -1)                                                                     \
            x = sys_ddr_phy_read_field(phy, (unsigned int)r, (unsigned int)m, (unsigned int)s);       \
        else                                                                                \
            x = sys_ddr_phy_read_field(phy, r[byte], m[byte], s[byte]);                               \
    } while (0)
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
#define QS_LATE_VALUE       FIELD_VALUE(DAT_a8026668_qs_late_reg, DAT_a8026658_qs_late_msk, DAT_a8026648_qs_late_shift)
#define GET_QS_LATE(x)      GET_FIELD(x, DAT_a8026668_qs_late_reg, DAT_a8026658_qs_late_msk, DAT_a8026648_qs_late_shift)
#define GATE_SEL_VALUE      FIELD_VALUE(sys_ddr_qs_gate_sel_regs, sys_ddr_qs_gate_sel_masks, sys_ddr_qs_gate_sel_shifts)
#define SET_GATE_SEL(v)     SET_FIELD(sys_ddr_qs_gate_sel_regs, sys_ddr_qs_gate_sel_masks, sys_ddr_qs_gate_sel_shifts, v)
#define SET_GATE_DLY(v)     SET_FIELD(DAT_a8026698_qs_gate_dly_reg_tbl, DAT_a8026688_qs_gate_dly_mask_tbl, DAT_a8026678_qs_gate_dly_shift_tbl, v)
#define GET_WRAP_DLY(x)     GET_FIELD(x, sys_ddr_qsen_wrap_dly_regs, sys_ddr_qsen_wrap_dly_masks, sys_ddr_qsen_wrap_dly_shifts)
#define GET_DLY_C_SEL(x)    GET_FIELD(x, sys_ddr_qsen_dly_c_sel_regs, sys_ddr_qsen_dly_c_sel_masks, sys_ddr_qsen_dly_c_sel_shifts)
#define SET_DLY_C_SEL(v)    SET_FIELD(sys_ddr_qsen_dly_c_sel_regs, sys_ddr_qsen_dly_c_sel_masks, sys_ddr_qsen_dly_c_sel_shifts, v)
#define GET_GATE_FIELD1(x)  GET_FIELD(x, sys_ddr_qs_gate_field1_regs, sys_ddr_qs_gate_field1_masks, sys_ddr_qs_gate_field1_shifts)
#define SET_FIELD_5D8(v)    SET_FIELD(DAT_a80265d8_reg, DAT_a80265c8_msk, DAT_a80265b8_shift, v)

#define DDR3 3                          /* DDR generations accepted by sys_ddr_check_arguments */
#define DDR4 4
#define QS_LATE_BIT0 1                  /* the qs_late bit this search follows */
#define QSEN_DLY_SEL_MAX 7              /* highest qsen_dly_*_sel value, "3'b111" in the messages */
#define QSEN_WRAP_DLY_MAX 15            /* highest qsen_wrap_dly value (sys_ddr_add_qsen_wrap_delay) */
#define QS_GATE_SEL_FIRST 1             /* the two values of qs_gate_sel, as in sys_ddr_add_qs_gate_sel */
#define QS_GATE_SEL_SECOND 3

/*
 * Phases 4 to 6: search the gate step at which bit 0 of qs_late changes, step qsen_dly_c_sel, then hand over to
 * sys_ddr_search_qs_gate_late. The two branches are the two directions; they differ only in the move per round
 * (down when the bit starts at 0, up when it starts at 1) and in one extra step down at the end of the upward one.
 */
static inline int search_gate_edge(unsigned int phy, int generation, int byte)
{
    unsigned int value, late, sel, at_max;
    int result;

    sys_ddr_reset_fifos(phy);
    if ((QS_LATE_VALUE & QS_LATE_BIT0) == 0) {
        /* Bit 0 starts at 0: move the gate down one step per round. */
        for (;;) {
            result = sys_ddr_move_qs_gate(phy, byte, -1);
            if (result != 0)
                return result;
            sys_ddr_reset_fifos(phy);
            for (;;) {
                /* Gate test: DDR4 sends a new pattern (command 0xB) first. */
                if (generation == DDR4) {
                    sys_ddr_gate_pattern = ~sys_ddr_gate_pattern & 0xff;
                    sys_ddr_send_mode_register(phy, 0xb, 0, sys_ddr_gate_pattern);
                    sys_ddr_send_mode_register(phy, 5, 0, 0x1000);
                } else if (generation == DDR3) {
                    sys_ddr_send_mode_register(phy, 5, 0, 0x1000);
                }
                if (sys_ddr_check_gate_fields(phy, generation, byte) == 0) {
                    /* Failing test: one wrap delay step on, then test again. */
                    result = sys_ddr_add_qsen_wrap_delay(phy, byte, 1);
                    if (result != 0)
                        return result;
                    sys_ddr_reset_fifos(phy);
                    continue;
                }
                if ((QS_LATE_VALUE & QS_LATE_BIT0) == 0)
                    break;
                /* Phase 5: bit 0 has changed; place the gate. */
                if (generation == DDR4) {
                    result = sys_ddr_add_qsen_wrap_delay(phy, byte, 1);
                    if (result != 0)
                        return result;
                } else if (generation == DDR3) {
                    result = sys_ddr_move_qs_gate(phy, byte, 0xc);
                    if (result != 0)
                        return result;
                }
                sys_ddr_reset_fifos(phy);
                if (generation == DDR4) {
                    /* Take the wrap delay step back when the gate test now fails. */
                    sys_ddr_gate_pattern = ~sys_ddr_gate_pattern & 0xff;
                    sys_ddr_send_mode_register(phy, 0xb, 0, sys_ddr_gate_pattern);
                    sys_ddr_send_mode_register(phy, 5, 0, 0x1000);
                    if (sys_ddr_check_gate_fields(phy, generation, byte) == 0) {
                        result = sys_ddr_add_qsen_wrap_delay(phy, byte, -1);
                        if (result != 0)
                            return result;
                    }
                } else if (generation == DDR3) {
                    /* qs_gate_field1 decides: back 12 steps (to where the edge was found) or 4 more up. */
                    sys_ddr_send_mode_register(phy, 5, 0, 0x1000);
                    GET_GATE_FIELD1(value);
                    if (value == 1)
                        result = sys_ddr_move_qs_gate(phy, byte, -12);
                    else
                        result = sys_ddr_move_qs_gate(phy, byte, 4);
                    if (result != 0)
                        return result;
                }
                /* Phase 6: raise qsen_dly_c_sel until bit 0 of qs_late reads 0. */
                do {
                    GET_DLY_C_SEL(value);
                    value++;
                    SET_DLY_C_SEL(value);
                    sys_ddr_reset_fifos(phy);
                    sys_ddr_send_mode_register(phy, 5, 0, 0x1000);
                    GET_QS_LATE(late);
                    GET_DLY_C_SEL(sel);
                    at_max = sel == QSEN_DLY_SEL_MAX;
                    if (late & at_max) {
                        sys_ddr_print_step();
                        sys_ddr_print_error_prefix();
                        dbg_printf("Error: qsen_dly_c_sel_b%d = 3'b111.\n", byte);
                        return -1;
                    }
                } while (late & QS_LATE_BIT0);
                return sys_ddr_search_qs_gate_late(phy, generation, byte);
            }
        }
    } else {
        /* Bit 0 starts at 1: move the gate up one step per round. */
        for (;;) {
            result = sys_ddr_move_qs_gate(phy, byte, 1);
            if (result != 0)
                return result;
            sys_ddr_reset_fifos(phy);
            for (;;) {
                if (generation == DDR4) {
                    sys_ddr_gate_pattern = ~sys_ddr_gate_pattern & 0xff;
                    sys_ddr_send_mode_register(phy, 0xb, 0, sys_ddr_gate_pattern);
                    sys_ddr_send_mode_register(phy, 5, 0, 0x1000);
                } else if (generation == DDR3) {
                    sys_ddr_send_mode_register(phy, 5, 0, 0x1000);
                }
                if (sys_ddr_check_gate_fields(phy, generation, byte) == 0) {
                    result = sys_ddr_add_qsen_wrap_delay(phy, byte, 1);
                    if (result != 0)
                        return result;
                    sys_ddr_reset_fifos(phy);
                    continue;
                }
                if (QS_LATE_VALUE & QS_LATE_BIT0)
                    break;
                /* Phase 5, as in the other direction. */
                if (generation == DDR4) {
                    result = sys_ddr_add_qsen_wrap_delay(phy, byte, 1);
                    if (result != 0)
                        return result;
                } else if (generation == DDR3) {
                    result = sys_ddr_move_qs_gate(phy, byte, 0xc);
                    if (result != 0)
                        return result;
                }
                sys_ddr_reset_fifos(phy);
                if (generation == DDR4) {
                    sys_ddr_gate_pattern = ~sys_ddr_gate_pattern & 0xff;
                    sys_ddr_send_mode_register(phy, 0xb, 0, sys_ddr_gate_pattern);
                    sys_ddr_send_mode_register(phy, 5, 0, 0x1000);
                    if (sys_ddr_check_gate_fields(phy, generation, byte) == 0) {
                        result = sys_ddr_add_qsen_wrap_delay(phy, byte, -1);
                        if (result != 0)
                            return result;
                    }
                } else if (generation == DDR3) {
                    sys_ddr_send_mode_register(phy, 5, 0, 0x1000);
                    GET_GATE_FIELD1(value);
                    if (value == 1)
                        result = sys_ddr_move_qs_gate(phy, byte, -12);
                    else
                        result = sys_ddr_move_qs_gate(phy, byte, 4);
                    if (result != 0)
                        return result;
                }
                /* Going up, the gate ends one step lower. */
                result = sys_ddr_move_qs_gate(phy, byte, -1);
                if (result != 0)
                    return result;
                /* Phase 6. */
                do {
                    GET_DLY_C_SEL(value);
                    value++;
                    SET_DLY_C_SEL(value);
                    sys_ddr_reset_fifos(phy);
                    sys_ddr_send_mode_register(phy, 5, 0, 0x1000);
                    GET_QS_LATE(late);
                    GET_DLY_C_SEL(sel);
                    at_max = sel == QSEN_DLY_SEL_MAX;
                    if (late & at_max) {
                        sys_ddr_print_step();
                        sys_ddr_print_error_prefix();
                        dbg_printf("Error: qsen_dly_c_sel_b%d = 3'b111.\n", byte);
                        return -1;
                    }
                } while (late & QS_LATE_BIT0);
                return sys_ddr_search_qs_gate_late(phy, generation, byte);
            }
        }
    }
}

/*
 * Strobe gate training of one data byte (training step QSEN): find a gate setting at which
 * sys_ddr_check_gate_fields passes, search from there the step at which bit 0 of qs_late changes, then finish
 * with sys_ddr_search_qs_gate_late.
 *
 *   phy         memory interface
 *   generation  DDR3 or DDR4
 *   byte        data byte; the only caller, sys_ddr_train_qs_gate, has checked it to be 0..3, so the
 *               byte == -1 arms of the macros do not run
 *
 * Returns 0, -1 after printing an error, or the first non-zero result of sys_ddr_add_qsen_wrap_delay,
 * sys_ddr_move_qs_gate or sys_ddr_search_qs_gate_late.
 *
 * The gate setting is spread over three fields: sys_ddr_move_qs_gate moves qs_gate_dly and carries into
 * qs_gate_sel (1 or 3), which carries into qsen_wrap_dly (0..15). A gate test is: for DDR4 invert the low 8 bits
 * of sys_ddr_gate_pattern and send them with command 0xB; send command 5 (payload 0x1000); then
 * sys_ddr_check_gate_fields.
 *
 * Phases:
 *  1. Set-up. Not DDR3: command 2 (0x400); DDR4 also command 6 with field 3 and the value of registers
 *     0x1B/0x1C masked with 0x7F8, bit 2 set; command 0xB with 0; command 5. DDR3: 0x50 into the low 7 bits of
 *     the byte's two registers (byte 0: 0x146 / 0x117, 1: 0x113 / 0xF4, 2: 0x101 / 0x145, 3: 0xEF / 0xF5),
 *     command 2 (0x400), command 6 (field 3, value 4), the bits 0x07 / 0x70 / 0x07 / 0x70 of registers 0x142 /
 *     0x11A / 0x121 / 0x102 cleared, command 5, then 0x0F into the low 7 bits of the same two registers.
 *  2. Start values: register 0x54 = 0x84 / 0xA4 / 0x94 / 0xB4 for byte 0..3; DDR3: field 0x5D8 = 0;
 *     qsen_dly_a_sel, _b_sel, _c_sel and qsen_wrap_dly = 0, qs_gate_sel = 1, qs_gate_dly = 0xD; FIFO reset.
 *  3. Coarse search: gate tests until one passes. After a failing test qs_gate_sel 1 becomes 3 with qs_gate_dly
 *     5, and qs_gate_sel 3 becomes qsen_wrap_dly + 1 with qs_gate_sel 1 and qs_gate_dly 0xD; qsen_wrap_dly
 *     already at 15 is an error. When the very first test passes, qsen_wrap_dly is raised by one and the
 *     fields are checked again after command 5 alone; if that check fails, the step is taken back and the
 *     routine returns 0 here.
 *  4. Edge search (search_gate_edge): the value of qs_late bit 0 picks the direction, and the gate moves one
 *     step per round until a passing gate test shows the bit changed. A failing test inside a round raises
 *     qsen_wrap_dly by one and tests again.
 *  5. Placing: DDR4 raises qsen_wrap_dly by one and takes it back when the next gate test fails. DDR3 moves
 *     the gate 12 steps up, sends command 5 and then moves it 12 steps down when qs_gate_field1 reads 1, else
 *     4 steps further up. In the upward direction the gate then moves one step down.
 *  6. qsen_dly_c_sel is raised by one per round (at least once) until qs_late bit 0 reads 0; still 1 with
 *     qsen_dly_c_sel at 7 is an error. Then sys_ddr_search_qs_gate_late.
 */
int sys_ddr_train_qs_gate_byte(unsigned int phy, int generation, int byte)
{
    unsigned int wrap_delay;
    int first_try, result;

    /* Phase 1: set-up commands. */
    if (generation != DDR3) {
        sys_ddr_send_mode_register(phy, 2, 0, 0x400);
        if (generation == DDR4)
            sys_ddr_send_mode_register(phy, 6, 3, (sys_ddr_read_reg1b_word(phy) & 0x7f8) | 4);
        sys_ddr_send_mode_register(phy, 0xb, 0, 0);
        sys_ddr_send_mode_register(phy, 5, 0, 0x1000);
    } else {
        switch (byte) {
        case 0:
            sys_ddr_phy_update_bits(phy, 0x146, 0x7f, 0x50);
            sys_ddr_phy_update_bits(phy, 0x117, 0x7f, 0x50);
            break;
        case 1:
            sys_ddr_phy_update_bits(phy, 0x113, 0x7f, 0x50);
            sys_ddr_phy_update_bits(phy, 0xf4, 0x7f, 0x50);
            break;
        case 2:
            sys_ddr_phy_update_bits(phy, 0x101, 0x7f, 0x50);
            sys_ddr_phy_update_bits(phy, 0x145, 0x7f, 0x50);
            break;
        case 3:
            sys_ddr_phy_update_bits(phy, 0xef, 0x7f, 0x50);
            sys_ddr_phy_update_bits(phy, 0xf5, 0x7f, 0x50);
            break;
        }
        sys_ddr_send_mode_register(phy, 2, 0, 0x400);
        sys_ddr_send_mode_register(phy, 6, 3, 4);
        sys_ddr_phy_update_bits(phy, 0x142, 7, 0);
        sys_ddr_phy_update_bits(phy, 0x11a, 0x70, 0);
        sys_ddr_phy_update_bits(phy, 0x121, 7, 0);
        sys_ddr_phy_update_bits(phy, 0x102, 0x70, 0);
        sys_ddr_send_mode_register(phy, 5, 0, 0x1000);
    }
    if (generation == DDR3) {
        switch (byte) {
        case 0:
            sys_ddr_phy_update_bits(phy, 0x146, 0x7f, 0xf);
            sys_ddr_phy_update_bits(phy, 0x117, 0x7f, 0xf);
            break;
        case 1:
            sys_ddr_phy_update_bits(phy, 0x113, 0x7f, 0xf);
            sys_ddr_phy_update_bits(phy, 0xf4, 0x7f, 0xf);
            break;
        case 2:
            sys_ddr_phy_update_bits(phy, 0x101, 0x7f, 0xf);
            sys_ddr_phy_update_bits(phy, 0x145, 0x7f, 0xf);
            break;
        case 3:
            sys_ddr_phy_update_bits(phy, 0xef, 0x7f, 0xf);
            sys_ddr_phy_update_bits(phy, 0xf5, 0x7f, 0xf);
            break;
        }
    }
    /* Phase 2: start values. */
    switch (byte) {
    case 0:
        sys_ddr_phy_write(phy, 0x54, 0x84);
        break;
    case 1:
        sys_ddr_phy_write(phy, 0x54, 0xa4);
        break;
    case 2:
        sys_ddr_phy_write(phy, 0x54, 0x94);
        break;
    case 3:
        sys_ddr_phy_write(phy, 0x54, 0xb4);
        break;
    }
    if (generation == DDR3) {
        SET_FIELD_5D8(0);
    }
    if (byte == -1) {
        sys_ddr_phy_write_field(phy, (unsigned int)sys_ddr_qsen_dly_a_sel_regs, (unsigned int)sys_ddr_qsen_dly_a_sel_masks, (unsigned int)sys_ddr_qsen_dly_a_sel_shifts, 0);
        sys_ddr_phy_write_field(phy, (unsigned int)sys_ddr_qsen_dly_b_sel_regs, (unsigned int)sys_ddr_qsen_dly_b_sel_masks, (unsigned int)sys_ddr_qsen_dly_b_sel_shifts, 0);
        sys_ddr_phy_write_field(phy, (unsigned int)sys_ddr_qsen_dly_c_sel_regs, (unsigned int)sys_ddr_qsen_dly_c_sel_masks, (unsigned int)sys_ddr_qsen_dly_c_sel_shifts, 0);
        sys_ddr_phy_write_field(phy, (unsigned int)sys_ddr_qsen_wrap_dly_regs, (unsigned int)sys_ddr_qsen_wrap_dly_masks, (unsigned int)sys_ddr_qsen_wrap_dly_shifts, 0);
        sys_ddr_phy_write_field(phy, (unsigned int)sys_ddr_qs_gate_sel_regs, (unsigned int)sys_ddr_qs_gate_sel_masks, (unsigned int)sys_ddr_qs_gate_sel_shifts, 1);
        sys_ddr_phy_write_field(phy, (unsigned int)DAT_a8026698_qs_gate_dly_reg_tbl, (unsigned int)DAT_a8026688_qs_gate_dly_mask_tbl, (unsigned int)DAT_a8026678_qs_gate_dly_shift_tbl, 0xd);
    } else {
        sys_ddr_phy_write_field(phy, sys_ddr_qsen_dly_a_sel_regs[byte], sys_ddr_qsen_dly_a_sel_masks[byte], sys_ddr_qsen_dly_a_sel_shifts[byte], 0);
        sys_ddr_phy_write_field(phy, sys_ddr_qsen_dly_b_sel_regs[byte], sys_ddr_qsen_dly_b_sel_masks[byte], sys_ddr_qsen_dly_b_sel_shifts[byte], 0);
        sys_ddr_phy_write_field(phy, sys_ddr_qsen_dly_c_sel_regs[byte], sys_ddr_qsen_dly_c_sel_masks[byte], sys_ddr_qsen_dly_c_sel_shifts[byte], 0);
        sys_ddr_phy_write_field(phy, sys_ddr_qsen_wrap_dly_regs[byte], sys_ddr_qsen_wrap_dly_masks[byte], sys_ddr_qsen_wrap_dly_shifts[byte], 0);
        sys_ddr_phy_write_field(phy, sys_ddr_qs_gate_sel_regs[byte], sys_ddr_qs_gate_sel_masks[byte], sys_ddr_qs_gate_sel_shifts[byte], 1);
        sys_ddr_phy_write_field(phy, DAT_a8026698_qs_gate_dly_reg_tbl[byte], DAT_a8026688_qs_gate_dly_mask_tbl[byte], DAT_a8026678_qs_gate_dly_shift_tbl[byte], 0xd);
    }
    sys_ddr_reset_fifos(phy);
    /* Phase 3: coarse search. */
    first_try = 1;
    for (;;) {
        if (generation == DDR4) {
            sys_ddr_gate_pattern = ~sys_ddr_gate_pattern & 0xff;
            sys_ddr_send_mode_register(phy, 0xb, 0, sys_ddr_gate_pattern);
        }
        sys_ddr_send_mode_register(phy, 5, 0, 0x1000);
        if (sys_ddr_check_gate_fields(phy, generation, byte) != 0) {
            if (first_try) {
                /* Passed at the start values: one wrap delay step on; when that fails, stay at the start. */
                result = sys_ddr_add_qsen_wrap_delay(phy, byte, 1);
                if (result != 0)
                    return result;
                sys_ddr_reset_fifos(phy);
                sys_ddr_send_mode_register(phy, 5, 0, 0x1000);
                if (sys_ddr_check_gate_fields(phy, generation, byte) == 0) {
                    result = sys_ddr_add_qsen_wrap_delay(phy, byte, -1);
                    if (result != 0)
                        return result;
                    sys_ddr_reset_fifos(phy);
                    return 0;
                }
            }
            /* Phases 4 to 6. */
            result = search_gate_edge(phy, generation, byte);
            if (result != 0)
                return result;
            return 0;
        }
        first_try = 0;
        if (GATE_SEL_VALUE == QS_GATE_SEL_SECOND) {
            /* qs_gate_sel 3 -> next wrap delay with qs_gate_sel 1. */
            GET_WRAP_DLY(wrap_delay);
            if (wrap_delay == QSEN_WRAP_DLY_MAX) {
                sys_ddr_print_step();
                sys_ddr_print_error_prefix();
                dbg_printf("Error: qsen_wrap_dly_ b%d _reg = 15.\n", byte);
                return -1;
            }
            result = sys_ddr_add_qsen_wrap_delay(phy, byte, 1);
            if (result != 0)
                return result;
            SET_GATE_SEL(QS_GATE_SEL_FIRST);
            SET_GATE_DLY(0xd);
            sys_ddr_reset_fifos(phy);
            continue;
        }
        /* qs_gate_sel 1 -> 3. */
        SET_GATE_SEL(QS_GATE_SEL_SECOND);
        SET_GATE_DLY(5);
        sys_ddr_reset_fifos(phy);
    }
}
