/* sys_ddr_check_gate_fields  (FUN_a00e4f8c)
 *
 * Check the gate fields of a memory interface: DDR4 against a 64-bit pattern, others five fields.
 * Returns: pass or fail
 * Name basis: descriptive - generation 4 builds the expected value from sys_ddr_gate_pattern; otherwise fixed
 *   values
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00e4f8c @ 0xa00e4f8c-0xa00e52e8, flags -mcpu=v8 -O3 -g.
 * Source form the exact build depends on: each read is its own if (b == -1)/else statement; the five comparisons
 * of the DDR3 arm are kept in variables and the arm returns their && chain; the DDR4 arm builds the expected
 * value with __lshrdi3 / __ashldi3 library calls (64-bit shifts).
 */
extern unsigned int sys_ddr_phy_read_field(unsigned int, unsigned int, unsigned int, unsigned int);
extern unsigned long long sys_ddr_phy_read_8_registers(unsigned int unit, int byte);
extern unsigned int sys_ddr_gate_pattern;
extern unsigned int sys_ddr_gate_check_field3_regs[], sys_ddr_gate_check_field3_masks[], sys_ddr_gate_check_field3_shifts[], sys_ddr_gate_check_field4_regs[], sys_ddr_gate_check_field4_masks[], sys_ddr_gate_check_field4_shifts[],
    sys_ddr_gate_check_field2_regs[], sys_ddr_gate_check_field2_masks[], sys_ddr_gate_check_field2_shifts[], sys_ddr_gate_check_field1_regs[], sys_ddr_gate_check_field1_masks[], sys_ddr_gate_check_field1_shifts[], sys_ddr_gate_check_field5_regs[],
    sys_ddr_gate_check_field5_masks[], sys_ddr_gate_check_field5_shifts[];

/*
 * Tell whether the strobe gate of a data byte has settled where the gate training wants it.
 *
 *   unit            memory interface number
 *   ddr_generation  3 (DDR3) or 4 (DDR4), as the training passes it
 *   byte            data byte; with -1 the tables' own addresses are passed in place of an entry
 *
 * Returns 1 when the check holds, else 0. Called by sys_ddr_train_qs_gate_byte after each gate step.
 *
 * DDR4: the 64-bit value from sys_ddr_phy_read_8_registers must equal an expected value that is built from
 * sys_ddr_gate_pattern (the byte sent with mode register 0xB): its bits taken in reverse order, each set bit
 * standing for one 0xFF byte of the 64 bits. Then check field 5 is not 1.
 *
 * DDR3: field 1 and field 4 must read 0xFF, field 2 and field 3 must read 0 and field 5 must not be 1. All
 * five are read in every case.
 */
unsigned int sys_ddr_check_gate_fields(unsigned int unit, int ddr_generation, int byte)
{
    unsigned int result;
    unsigned int field3_is_zero, field4_is_ff, field2_is_zero, field5, field1_is_ff;
    unsigned long long read_back, pattern_reversed, expected;
    int i;

    if (ddr_generation == 4) {
        result = 0;
        read_back = sys_ddr_phy_read_8_registers(unit, byte);
        pattern_reversed = 0;
        expected = 0;
        /* The pattern byte with its bits in reverse order. */
        for (i = 0; i < 8; i++)
            pattern_reversed |= (((1 << i) & sys_ddr_gate_pattern) >> i) << (7 - i);
        /* Each set bit selects one 0xFF byte of the expected 64-bit value. */
        for (i = 0; i < 8; i++)
            if ((pattern_reversed >> i) & 1)
                expected |= 0xffULL << (i * 8);
        if (read_back == expected) {
            if (byte == -1)
                field5 = sys_ddr_phy_read_field(unit, (unsigned int)sys_ddr_gate_check_field5_regs, (unsigned int)sys_ddr_gate_check_field5_masks, (unsigned int)sys_ddr_gate_check_field5_shifts);
            else
                field5 = sys_ddr_phy_read_field(unit, sys_ddr_gate_check_field5_regs[byte], sys_ddr_gate_check_field5_masks[byte], sys_ddr_gate_check_field5_shifts[byte]);
            if (field5 != 1)
                result = 1;
        }
    } else {
        /* DDR3: the five fields are all read; the result is true when each has its expected value. */
        if (byte == -1)
            field3_is_zero = sys_ddr_phy_read_field(unit, (unsigned int)sys_ddr_gate_check_field3_regs, (unsigned int)sys_ddr_gate_check_field3_masks, (unsigned int)sys_ddr_gate_check_field3_shifts) == 0;
        else
            field3_is_zero = sys_ddr_phy_read_field(unit, sys_ddr_gate_check_field3_regs[byte], sys_ddr_gate_check_field3_masks[byte], sys_ddr_gate_check_field3_shifts[byte]) == 0;
        if (byte == -1)
            field4_is_ff = sys_ddr_phy_read_field(unit, (unsigned int)sys_ddr_gate_check_field4_regs, (unsigned int)sys_ddr_gate_check_field4_masks, (unsigned int)sys_ddr_gate_check_field4_shifts) == 0xff;
        else
            field4_is_ff = sys_ddr_phy_read_field(unit, sys_ddr_gate_check_field4_regs[byte], sys_ddr_gate_check_field4_masks[byte], sys_ddr_gate_check_field4_shifts[byte]) == 0xff;
        if (byte == -1)
            field2_is_zero = sys_ddr_phy_read_field(unit, (unsigned int)sys_ddr_gate_check_field2_regs, (unsigned int)sys_ddr_gate_check_field2_masks, (unsigned int)sys_ddr_gate_check_field2_shifts) == 0;
        else
            field2_is_zero = sys_ddr_phy_read_field(unit, sys_ddr_gate_check_field2_regs[byte], sys_ddr_gate_check_field2_masks[byte], sys_ddr_gate_check_field2_shifts[byte]) == 0;
        if (byte == -1)
            field1_is_ff = sys_ddr_phy_read_field(unit, (unsigned int)sys_ddr_gate_check_field1_regs, (unsigned int)sys_ddr_gate_check_field1_masks, (unsigned int)sys_ddr_gate_check_field1_shifts) == 0xff;
        else
            field1_is_ff = sys_ddr_phy_read_field(unit, sys_ddr_gate_check_field1_regs[byte], sys_ddr_gate_check_field1_masks[byte], sys_ddr_gate_check_field1_shifts[byte]) == 0xff;
        if (byte == -1)
            field5 = sys_ddr_phy_read_field(unit, (unsigned int)sys_ddr_gate_check_field5_regs, (unsigned int)sys_ddr_gate_check_field5_masks, (unsigned int)sys_ddr_gate_check_field5_shifts) != 1;
        else
            field5 = sys_ddr_phy_read_field(unit, sys_ddr_gate_check_field5_regs[byte], sys_ddr_gate_check_field5_masks[byte], sys_ddr_gate_check_field5_shifts[byte]) != 1;
        return field3_is_zero && field4_is_ff && field2_is_zero && field1_is_ff && field5;
    }
    return result;
}
