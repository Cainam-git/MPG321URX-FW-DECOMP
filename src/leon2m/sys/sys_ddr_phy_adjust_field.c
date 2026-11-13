/* sys_ddr_phy_adjust_field  (FUN_a00e0134)
 *
 * Add or subtract a step in a register field of a memory interface, with a limit check.
 * Name basis: proven - prints 'Invalid mask from phy_reg_add/sub (non-continued set bits)'
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00e0134 @ 0xa00e0134, flags -mcpu=v8 -O3 -g.
 * Source form: sat is cut to the mask before the mask check, delta and limit after it; the clamp path is a goto
 * label shared by the add and the subtract arm; the declarations are in the order prev, bit, edges, i, cur, v,
 * m.
 */
extern void sys_ddr_print_step(void);
extern void sys_ddr_print_error_prefix(void);
extern int dbg_printf(const char *fmt, ...);
extern unsigned int sys_ddr_phy_read(int phy, unsigned int addr);
extern void sys_ddr_phy_write(int phy, unsigned int addr, unsigned int val);

/*
 * Add a step to, or subtract a step from, one bit field of an 8-bit register of a memory interface, and keep the
 * field inside a limit.
 *
 *   phy    memory interface number
 *   addr   register address inside the interface
 *   delta  the step, cut to the field by mask and used in place (not shifted down)
 *   mask   the field: one run of consecutive set bits
 *   limit  upper bound when adding, lower bound when subtracting; cut to the field by mask, in place
 *   keep   when the result would pass the limit: not 0 = leave the register as it is, 0 = write sat instead
 *   sat    the field value written when the limit is passed and keep is 0; cut to the field by mask
 *   add    not 0 = add delta, 0 = subtract it
 *
 * The mask is checked first: it must have exactly one run of consecutive set bits (the number of 0/1 changes
 * along bits 0..31, starting from an implicit 0 below bit 0, must be 1 or 2). Otherwise the step line, the
 * "ddr_err: " prefix and "Invalid mask from phy_reg_add/sub (non-continued set bits), abort command" are printed
 * and nothing is read or written (a mask of 0 fails too).
 *
 * Then the register is read and the field (register value and mask) is changed by delta, as an 8-bit result.
 * An add that gives more than limit, or a subtract that gives less than limit, passes the limit: with keep set
 * nothing is written, otherwise the field is set to sat. When the limit is not passed, the register is written
 * back with all bits outside the mask unchanged and the new field value inside it.
 *
 * Caller: sys_ddr_run_script, for the script commands 42 (add) and 43 (subtract), once for every memory
 * interface of the unit range the command names.
 */
void sys_ddr_phy_adjust_field(int phy, unsigned int addr, unsigned int delta, unsigned int mask,
                  unsigned int limit, int keep, unsigned int sat, int add)
{
    unsigned int prev, bit, edges;
    int i;
    unsigned int reg_value, result, field;

    prev = 0;
    edges = 0;
    for (i = 0; i < 32; i++) {
        bit = (mask >> i) & 1;
        edges += bit ^ prev;
        prev = bit;
    }
    sat &= mask;
    if (edges - 1 > 1) {
        sys_ddr_print_step();
        sys_ddr_print_error_prefix();
        dbg_printf("Invalid mask from phy_reg_add/sub (non-continued set bits), abort command\n");
        return;
    }
    delta &= mask;
    limit &= mask;
    reg_value = sys_ddr_phy_read(phy, addr);
    field = reg_value & mask;
    if (add != 0) {
        result = (field + delta) & 0xff;
        if (result > limit)
            goto clamp;
    } else {
        result = (field - delta) & 0xff;
        if (result < limit)
            goto clamp;
    }
    sys_ddr_phy_write(phy, addr, ((unsigned char)reg_value & ~mask) | (result & mask));
    return;
clamp:
    if (keep != 0)
        return;
    sys_ddr_phy_write(phy, addr, ((unsigned char)reg_value & ~mask) | sat);
}
