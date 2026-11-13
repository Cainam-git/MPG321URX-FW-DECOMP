/* sys_ddr_move_qs_gate  (FUN_a00e55ec)
 *
 * Move the strobe gate of a data byte by a signed number of steps.
 * Name basis: derived - in parts of at most 8, carrying into the gate selection at the range limits
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00e55ec @ 0xa00e55ec-0xa00e57b4, flags -mcpu=v8 -O3 -g.
 * Names: the match depends on the names DAT_a8026698_qs_gate_dly_reg_tbl, DAT_a8026688_qs_gate_dly_mask_tbl and
 *   DAT_a8026678_qs_gate_dly_shift_tbl (gcse orders the three hoisted %hi parts by a hash of the names: fw
 *   0xa00e563c %l3, 0xa00e5644 %l2, 0xa00e5648 %l1).
 */
extern unsigned int sys_ddr_phy_read_field(unsigned int, unsigned int, unsigned int, unsigned int);
extern void sys_ddr_phy_write_field(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
extern int sys_ddr_add_qs_gate_sel(unsigned int unit, int byte, int steps);
extern unsigned int DAT_a8026678_qs_gate_dly_shift_tbl[];
extern unsigned int DAT_a8026688_qs_gate_dly_mask_tbl[];
extern unsigned int DAT_a8026698_qs_gate_dly_reg_tbl[];

/*
 * Move the strobe gate delay of a data byte by a signed number of steps.
 *
 *   unit   memory interface number
 *   byte   data byte; with -1 the tables' own addresses are passed in place of an entry
 *   steps  signed distance; 0 does nothing
 *
 * Returns 0, or the non-zero result of the failing step.
 *
 * A distance beyond 8 either way is done as calls of 8 steps (the routine calls itself). The gate delay is a
 * register field taken from the qs_gate_dly tables. When the field has less room left in the direction of the
 * move than the distance, one step is added to the gate selection first (sys_ddr_add_qs_gate_sel with +1 going
 * up, -1 going down); its failure is returned. The room is 12 - value up and value - 5 down while the value is
 * 5..12; otherwise 7 - ((value + 3) & 0xF) up and (value + 3) & 0xF down. The new value (old + steps) is then
 * written back.
 */
int sys_ddr_move_qs_gate(unsigned int unit, int byte, int steps)
{
    unsigned int gate_delay;
    int result;

    if (steps > 8) {
        while (steps > 8) {
            result = sys_ddr_move_qs_gate(unit, byte, 8);
            steps -= 8;
            if (result != 0)
                return result;
        }
    } else {
        while (steps < -8) {
            result = sys_ddr_move_qs_gate(unit, byte, -8);
            steps += 8;
            if (result != 0)
                return result;
        }
    }
    if (steps == 0)
        return 0;
    if (byte == -1)
        gate_delay = sys_ddr_phy_read_field(unit, (unsigned int)DAT_a8026698_qs_gate_dly_reg_tbl, (unsigned int)DAT_a8026688_qs_gate_dly_mask_tbl, (unsigned int)DAT_a8026678_qs_gate_dly_shift_tbl);
    else
        gate_delay = sys_ddr_phy_read_field(unit, DAT_a8026698_qs_gate_dly_reg_tbl[byte], DAT_a8026688_qs_gate_dly_mask_tbl[byte], DAT_a8026678_qs_gate_dly_shift_tbl[byte]);
    /* Compare the distance with the room left in the field; too little room: carry into the gate selection. */
    if (gate_delay >= 5 && gate_delay <= 12) {
        if (steps > 0) {
            if (12 - gate_delay < steps) {
                result = sys_ddr_add_qs_gate_sel(unit, byte, 1);
                if (result != 0)
                    return result;
            }
        } else if (steps < 0) {
            if (gate_delay - 5 < -steps) {
                result = sys_ddr_add_qs_gate_sel(unit, byte, -1);
                if (result != 0)
                    return result;
            }
        }
    } else {
        if (steps > 0) {
            if (7 - ((gate_delay + 3) & 0xf) < steps) {
                result = sys_ddr_add_qs_gate_sel(unit, byte, 1);
                if (result != 0)
                    return result;
            }
        } else if (steps < 0) {
            if (((gate_delay + 3) & 0xf) < -steps) {
                result = sys_ddr_add_qs_gate_sel(unit, byte, -1);
                if (result != 0)
                    return result;
            }
        }
    }
    gate_delay += steps;
    if (byte == -1)
        sys_ddr_phy_write_field(unit, (unsigned int)DAT_a8026698_qs_gate_dly_reg_tbl, (unsigned int)DAT_a8026688_qs_gate_dly_mask_tbl, (unsigned int)DAT_a8026678_qs_gate_dly_shift_tbl, gate_delay);
    else
        sys_ddr_phy_write_field(unit, DAT_a8026698_qs_gate_dly_reg_tbl[byte], DAT_a8026688_qs_gate_dly_mask_tbl[byte], DAT_a8026678_qs_gate_dly_shift_tbl[byte], gate_delay);
    return 0;
}
