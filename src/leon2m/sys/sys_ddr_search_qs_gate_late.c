/* sys_ddr_search_qs_gate_late  (FUN_a00e57b4)
 *
 * Step the strobe-enable delay until the 'late' flag clears.
 * Name basis: proven - prints 'Error: qs_late_b%d [1] = 1 and qsen_dly_b_sel_b%d = 3'b111.'
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00e57b4 @ 0xa00e57b4-0xa00e5fc8 (2068 bytes), flags -mcpu=v8 -O3 -g -msoft-float.
 * Source forms the exact build depends on:
 *  - every field access is a GET_FIELD / SET_FIELD statement macro, each with its own 'byte == -1' test, as in
 *    sys_ddr_train_read_deskew / sys_ddr_train_qs_gate_byte;
 *  - each increment is its own 'value++;' statement between read and write (fw re-tests byte after the read at
 *    0xa00e5958, 0xa00e5b6c, 0xa00e5d84);
 *  - both qsen_dly_a_sel loops are 'for (;;)' with the bit-clear 'break' before the '== 7' test, the first with
 *    the error print inside the loop (fw 0xa00e5948..0xa00e5a84, 0xa00e5b5c..0xa00e5ca4);
 *  - the qsen_dly_b_sel rounds are the label step_b inside the second loop's '== 7' arm, repeated with
 *    'if (late & 2) goto step_b;' (fw: their table addresses are formed in the second loop's preheader
 *    0xa00e5b28..0xa00e5b58, the byte == -1 high parts on the edges 0xa00e5c0c / 0xa00e5d68 / 0xa00e5d70);
 *  - phase 4 is the static helper finish_late_search; its result goes through 'if (result != 0) return result;
 *    return 0;' (0xa00e5b14: 'clr %o0; cmp %o0, 0');
 *  - the qsen_dly_b_sel error test is 'at_max = sel == 7; if ((late >> 1) & at_max)' (0xa00e5e14: xor, subx,
 *    srl, btst);
 *  - DDR3 and DDR4 are two tests with the same call in each arm (fw compares at 0xa00e5858 and 0xa00e5864, both
 *    branch to the one call at 0xa00e5ef0/0xa00e5ef4).
 * Table names: GCC orders the high parts of the table addresses by a hash of the symbol names (gcse.c). The
 * firmware needs the order shift < reg < mask for the tables 0xa8026638/628/618 and 0xa80265d8/5c8/5b8 and
 * mask < shift for 0xa8026668/658/648 (qs_late). The spellings DAT_a8026638_reg, DAT_a8026628_msk,
 * DAT_a8026618_shift (and the same pattern for the other two) give this order with one suffix style;
 * sys_ddr_train_qs_gate builds to the same bytes with them.
 */
extern int sys_ddr_move_qs_gate(unsigned int, int, int);
extern unsigned int sys_ddr_phy_read_field(unsigned int, unsigned int, unsigned int, unsigned int);
extern void sys_ddr_phy_write_field(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
extern void sys_ddr_reset_fifos(unsigned int);
extern void sys_ddr_send_mode_register(unsigned int, unsigned int, unsigned int, unsigned int);
extern void sys_ddr_phy_write(unsigned int, unsigned int, unsigned int);
extern void sys_ddr_print_step(void);
extern void sys_ddr_print_error_prefix(void);
extern int dbg_printf(const char *fmt, ...);
extern unsigned int DAT_a8026638_reg[], DAT_a8026628_msk[], DAT_a8026618_shift[];
extern unsigned int DAT_a80265d8_reg[], DAT_a80265c8_msk[], DAT_a80265b8_shift[];
extern unsigned int DAT_a8026668_qs_late_reg[], DAT_a8026658_qs_late_msk[], DAT_a8026648_qs_late_shift[];
extern unsigned int sys_ddr_qsen_dly_a_sel_regs[], sys_ddr_qsen_dly_a_sel_masks[], sys_ddr_qsen_dly_a_sel_shifts[];
extern unsigned int sys_ddr_qsen_dly_b_sel_regs[], sys_ddr_qsen_dly_b_sel_masks[], sys_ddr_qsen_dly_b_sel_shifts[];
extern unsigned int sys_ddr_qs_gate_field6_regs[], sys_ddr_qs_gate_field6_masks[], sys_ddr_qs_gate_field6_shifts[];

/*
 * A field of a data byte is entry `byte` of three tables: register, mask and bit position. With byte == -1 the
 * addresses of the tables themselves are passed in place of an entry. Fields without a name are called by the
 * address of their register table here: field 0x638 = tables 0xA8026638 / 0xA8026628 / 0xA8026618, field 0x5D8 =
 * tables 0xA80265D8 / 0xA80265C8 / 0xA80265B8.
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
#define GET_QS_LATE(x)      GET_FIELD(x, DAT_a8026668_qs_late_reg, DAT_a8026658_qs_late_msk, DAT_a8026648_qs_late_shift)
#define GET_DLY_A_SEL(x)    GET_FIELD(x, sys_ddr_qsen_dly_a_sel_regs, sys_ddr_qsen_dly_a_sel_masks, sys_ddr_qsen_dly_a_sel_shifts)
#define SET_DLY_A_SEL(v)    SET_FIELD(sys_ddr_qsen_dly_a_sel_regs, sys_ddr_qsen_dly_a_sel_masks, sys_ddr_qsen_dly_a_sel_shifts, v)
#define GET_DLY_B_SEL(x)    GET_FIELD(x, sys_ddr_qsen_dly_b_sel_regs, sys_ddr_qsen_dly_b_sel_masks, sys_ddr_qsen_dly_b_sel_shifts)
#define SET_DLY_B_SEL(v)    SET_FIELD(sys_ddr_qsen_dly_b_sel_regs, sys_ddr_qsen_dly_b_sel_masks, sys_ddr_qsen_dly_b_sel_shifts, v)
#define GET_FIELD_638(x)    GET_FIELD(x, DAT_a8026638_reg, DAT_a8026628_msk, DAT_a8026618_shift)
#define SET_FIELD_638(v)    SET_FIELD(DAT_a8026638_reg, DAT_a8026628_msk, DAT_a8026618_shift, v)
#define SET_FIELD_5D8(v)    SET_FIELD(DAT_a80265d8_reg, DAT_a80265c8_msk, DAT_a80265b8_shift, v)
#define SET_GATE_FIELD6(v)  SET_FIELD(sys_ddr_qs_gate_field6_regs, sys_ddr_qs_gate_field6_masks, sys_ddr_qs_gate_field6_shifts, v)

#define DDR3 3                          /* DDR generations accepted by sys_ddr_check_arguments */
#define DDR4 4
#define QS_LATE_BIT1 2                  /* bit 1 of qs_late, "qs_late_b%d [1]" in the firmware's messages */
#define QSEN_DLY_SEL_MAX 7              /* highest qsen_dly_*_sel value, "3'b111" in the messages */

/* Phase 4: settle the gate after the search. */
static int finish_late_search(unsigned int phy, int byte)
{
    int result;

    sys_ddr_reset_fifos(phy);
    /* Bit 3 of register 0x61 decides between a further 8-step move down (field6 = 1) and none (field6 = 0). */
    if (sys_ddr_phy_read_field(phy, 0x61, 8, 3) == 1) {
        SET_GATE_FIELD6(1);
        result = sys_ddr_move_qs_gate(phy, byte, -8);
        if (result != 0)
            return result;
        sys_ddr_reset_fifos(phy);
    } else {
        SET_GATE_FIELD6(0);
    }
    sys_ddr_phy_write(phy, 0x54, 0);
    return 0;
}

/*
 * Last part of the strobe gate training of one data byte (training step QSEN): with the gate moved 4 steps down,
 * raise the strobe-enable delay selections until bit 1 of the qs_late field reads 0, then move the gate back.
 *
 *   phy         memory interface
 *   generation  DDR3 or DDR4
 *   byte        data byte; the only caller, sys_ddr_train_qs_gate_byte, passes on the byte that
 *               sys_ddr_train_qs_gate has checked to be 0..3, so the byte == -1 arms of the macros do not run
 *
 * Returns 0, -1 after printing an error, or the non-zero result of sys_ddr_move_qs_gate.
 * Called by sys_ddr_train_qs_gate_byte as the last step of its gate edge search.
 *
 * Phases:
 *  1. Move the gate 4 steps down (sys_ddr_move_qs_gate). Set bit 1 of field 0x638 and write 1 to field 0x5D8,
 *     reset the FIFOs and, for DDR3 or DDR4, send command 5 (payload 0x1000). Read qs_late.
 *  2a. qs_late bit 1 reads 0: clear bit 1 of field 0x638 and write 0 to field 0x5D8 again. Then raise
 *     qsen_dly_a_sel by one per round (at least once; FIFO reset and command 5 after each step) until qs_late
 *     bit 1 reads 0. Still 1 with qsen_dly_a_sel at 7: error.
 *  2b. qs_late bit 1 reads 1: the same rounds on qsen_dly_a_sel; when it is at 7 with the bit still 1, the
 *     rounds go on with qsen_dly_b_sel. Still 1 with qsen_dly_b_sel at 7: error. Fields 0x638 and 0x5D8 keep
 *     the values of phase 1 on this path.
 *  3. Move the gate 4 steps up again.
 *  4. finish_late_search: reset the FIFOs; when bit 3 of register 0x61 reads 1, write 1 to qs_gate_field6 and
 *     move the gate 8 steps down (FIFO reset after it), otherwise write 0 to qs_gate_field6. Write 0 to
 *     register 0x54.
 */
int sys_ddr_search_qs_gate_late(unsigned int phy, int generation, int byte)
{
    unsigned int value, sel;
    unsigned int late;
    int at_max, result;

    /* Phase 1: gate 4 steps down, first test. */
    result = sys_ddr_move_qs_gate(phy, byte, -4);
    if (result != 0)
        return result;
    GET_FIELD_638(value);
    SET_FIELD_638(value | 2);
    SET_FIELD_5D8(1);
    sys_ddr_reset_fifos(phy);
    if (generation == DDR3)
        sys_ddr_send_mode_register(phy, 5, 0, 0x1000);
    else if (generation == DDR4)
        sys_ddr_send_mode_register(phy, 5, 0, 0x1000);
    GET_QS_LATE(late);
    if (!(late & QS_LATE_BIT1)) {
        /* Phase 2a: undo the two writes of phase 1, then step qsen_dly_a_sel. */
        GET_FIELD_638(value);
        SET_FIELD_638(value & ~2);
        SET_FIELD_5D8(0);
        for (;;) {
            GET_DLY_A_SEL(value);
            value++;
            SET_DLY_A_SEL(value);
            sys_ddr_reset_fifos(phy);
            sys_ddr_send_mode_register(phy, 5, 0, 0x1000);
            GET_QS_LATE(late);
            GET_DLY_A_SEL(sel);
            if (!(late & QS_LATE_BIT1))
                break;
            if (sel == QSEN_DLY_SEL_MAX) {
                sys_ddr_print_step();
                sys_ddr_print_error_prefix();
                dbg_printf("Error: qsen_dly_a_sel_b%d = 3'b111 and qs_late_b%d [1] = 1.\n", byte, byte);
                return -1;
            }
        }
    } else {
        /* Phase 2b: step qsen_dly_a_sel, then qsen_dly_b_sel when a_sel has run out. */
        for (;;) {
            GET_DLY_A_SEL(value);
            value++;
            SET_DLY_A_SEL(value);
            sys_ddr_reset_fifos(phy);
            sys_ddr_send_mode_register(phy, 5, 0, 0x1000);
            GET_QS_LATE(late);
            GET_DLY_A_SEL(sel);
            if (!(late & QS_LATE_BIT1))
                break;
            if (sel == QSEN_DLY_SEL_MAX) {
step_b:
                GET_DLY_B_SEL(value);
                value++;
                SET_DLY_B_SEL(value);
                sys_ddr_reset_fifos(phy);
                sys_ddr_send_mode_register(phy, 5, 0, 0x1000);
                GET_QS_LATE(late);
                GET_DLY_B_SEL(sel);
                at_max = sel == QSEN_DLY_SEL_MAX;
                if ((late >> 1) & at_max) {
                    sys_ddr_print_step();
                    sys_ddr_print_error_prefix();
                    dbg_printf("Error: qs_late_b%d [1] = 1 and qsen_dly_b_sel_b%d = 3'b111.\n", byte, byte);
                    return -1;
                }
                if (late & QS_LATE_BIT1)
                    goto step_b;
                break;
            }
        }
    }
    /* Phase 3: gate back up. */
    result = sys_ddr_move_qs_gate(phy, byte, 4);
    if (result != 0)
        return result;
    result = finish_late_search(phy, byte);
    if (result != 0)
        return result;
    return 0;
}
