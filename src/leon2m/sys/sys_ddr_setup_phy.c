/* sys_ddr_setup_phy  (FUN_a00eecd0)
 *
 * Write the start register values of one memory interface.
 * Name basis: derived - uses a byte of the identification record when a full set-up is asked
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00eecd0 @ 0xa00eecd0-0xa00eef3c, flags -mcpu=v8 -O3 -g.
 * Source form the exact build depends on: an if/else-if chain with one call per arm (the firmware cross-jumps
 * them); 'rzq_trim = 0x10' stands before 'if (full_setup != 0)' (the firmware fills the first branch delay slot
 * with it; written inside the arm it does not match); the local n is declared and not used.
 */
extern int dbg_printf(const char *fmt, ...);
extern void sys_ddr_print_step(void);
extern void sys_ddr_check_arguments(unsigned int, unsigned int, unsigned int);
extern void sys_ddr_delay(unsigned int);
extern void sys_ddr_set_step(unsigned int, unsigned int, unsigned int);
extern unsigned int sys_ddr_phy_read(unsigned int, unsigned int);
extern unsigned int sys_ddr_phy_read_masked(unsigned int, unsigned int, unsigned int);
extern void sys_ddr_phy_update_bits(unsigned int, unsigned int, unsigned int, unsigned int);
extern void sys_ddr_print_error_prefix(void);
extern int sys_read_id_record_byte(int);

/*
 * Write the start values of the registers of one memory interface and copy two measured values from the
 * calibration registers into the registers that use them.
 *
 *   unit        memory interface number (0..2)
 *   full_setup  non-zero: first write the RZQ trim value of this interface to the low five bits of register
 *               0x110; zero: write 0x10 there after the common registers
 *
 * Returns 0. Called by sys_ddr_run_script (with full_setup 1) for each interface of the unit range that the
 * script command names.
 *
 * The trim value is a byte of the identification record (sys_read_id_record_byte with selector 0, 1 or 2 for
 * interface 0, 1 or 2); when that read gives -1 it is 0x10. For another interface number the error text
 * "Invalid phy_id %d for RZQ trim, fallback to 0x%x" is printed and the value stays 0x10.
 *
 * After the writes to registers 0x24D, 0x24C, 0x243 and 0x240 the routine waits for bit 5 of register 0x24A, then
 * reads registers 0x247 and 0x248 and writes the first to registers 0x241, 0x274 and 0x275 and the second to
 * 0x242, 0x270 and 0x271 (five bits each), and finishes with writes to registers 0x240 and 0x277.
 */
int sys_ddr_setup_phy(unsigned int unit, int full_setup)
{
    int rzq_trim;
    int n;
    unsigned int read_0x247, read_0x248;

    /* Training step 2 (ZQK in the step names), no data byte; the record is used by the error messages. */
    sys_ddr_set_step(2, unit, 0xffffffff);
    /* Interface version 2, DDR4. */
    sys_ddr_check_arguments(unit, 2, 4);
    rzq_trim = 0x10;
    if (full_setup != 0) {
        if (unit == 0)
            rzq_trim = sys_read_id_record_byte(0);
        else if (unit == 1)
            rzq_trim = sys_read_id_record_byte(1);
        else if (unit == 2)
            rzq_trim = sys_read_id_record_byte(2);
        else {
            sys_ddr_print_step();
            sys_ddr_print_error_prefix();
            dbg_printf("Invalid phy_id %d for RZQ trim, fallback to 0x%x\n", unit, 0x10);
        }
        if (rzq_trim == -1)
            rzq_trim = 0x10;
        sys_ddr_phy_update_bits(unit, 0x110, 0x1f, rzq_trim);
        sys_ddr_delay(1);
    }
    sys_ddr_phy_update_bits(unit, 1, 0x40, 0x40);
    sys_ddr_phy_update_bits(unit, 0, 2, 2);
    if (full_setup == 0)
        sys_ddr_phy_update_bits(unit, 0x110, 0x1f, 0x10);
    sys_ddr_phy_update_bits(unit, 0x24d, 0xff, 2);
    sys_ddr_phy_update_bits(unit, 0x24c, 0xff, 0xfc);
    sys_ddr_phy_update_bits(unit, 0x243, 0x1f, 0x10);
    sys_ddr_phy_update_bits(unit, 0x240, 0x80, 0);
    sys_ddr_phy_update_bits(unit, 0x240, 0x20, 0x20);
    sys_ddr_delay(2);
    /* Wait for bit 5 of register 0x24A. */
    while (!(sys_ddr_phy_read(unit, 0x24a) & 0x20))
        ;
    read_0x247 = sys_ddr_phy_read_masked(unit, 0x247, 0x1f);
    read_0x248 = sys_ddr_phy_read_masked(unit, 0x248, 0x1f);
    sys_ddr_phy_update_bits(unit, 0x241, 0x1f, read_0x247 & 0xff);
    sys_ddr_phy_update_bits(unit, 0x242, 0x1f, read_0x248 & 0xff);
    sys_ddr_phy_update_bits(unit, 0x274, 0x1f, read_0x247 & 0xff);
    sys_ddr_phy_update_bits(unit, 0x270, 0x1f, read_0x248 & 0xff);
    sys_ddr_phy_update_bits(unit, 0x275, 0x1f, read_0x247 & 0xff);
    sys_ddr_phy_update_bits(unit, 0x271, 0x1f, read_0x248 & 0xff);
    sys_ddr_phy_update_bits(unit, 0x240, 0x80, 0x80);
    sys_ddr_phy_update_bits(unit, 0x277, 0xc0, 0xc0);
    sys_ddr_phy_update_bits(unit, 0x240, 0x20, 0);
    return 0;
}
