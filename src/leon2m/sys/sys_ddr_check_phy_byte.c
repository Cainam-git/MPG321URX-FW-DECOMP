/* sys_ddr_check_phy_byte  (FUN_a00e47f8)
 *
 * Configure the memory interface registers of one data byte and check them.
 * Returns: 0, or -1 on a failed check
 * Name basis: proven - prints 'PSD_B%d: check_phy(...) fail' and 'byte_idx %d out of range.'
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00e47f8 @ 0xa00e47f8-0xa00e4f8c, flags -mcpu=v8 -O3 (no -g).
 * The check loop over i = 1..6 compiles to a switch with the jump table at 0xa00e47dc.
 * Source forms the exact build depends on: the twelve read-back values are separate variables set to 0 at the
 * start, filled by one switch on byte_idx and written by a second one; reg, mask and expect are set to 0 before
 * the switch on i, and every case sets all three.
 */

#define DDR_STEP_PSD        4   /* training step recorded for the messages, printed as "PSD" */
#define DDR_PHY_VERSION     2   /* the fixed values this step passes to sys_ddr_check_arguments */
#define DDR_GENERATION_MAX  4
#define BYTE_COUNT          4   /* data bytes 0..3 */
#define START_POLLS         5   /* polls of register 0x300 bit 7 after the start */

extern void sys_ddr_set_step(unsigned int, unsigned int, unsigned int);
extern int sys_ddr_check_arguments(unsigned int, unsigned int, unsigned int);
extern void sys_ddr_print_step(void);
extern void sys_ddr_print_error_prefix(void);
extern int dbg_printf(const char *fmt, ...);
extern void sys_ddr_phy_update_bits(unsigned int, unsigned int, unsigned int, unsigned int);
extern unsigned int sys_ddr_phy_read_masked(unsigned int, unsigned int, unsigned int);
extern int sys_ddr_check_phy_reg(unsigned int, unsigned int, unsigned int, unsigned int);
extern void sys_ddr_delay(unsigned int);
extern void sys_ddr_print_info_prefix(void);
extern void sys_ddr_reset_fifos(unsigned int);
extern unsigned int sys_ddr_phy_read(unsigned int, unsigned int);

/*
 * The PSD training step for data byte byte_idx (0..3) of memory interface phy. Run by the memory set-up script
 * (command 50 of sys_ddr_run_script); the two scripts of FW.021 run it for bytes 0..3 of interfaces 0 and 1,
 * with offset 20.
 *
 * Each data byte has its own set of registers; those of byte n lie 0xd * n above those of byte 0 (0x306, 0x308,
 * 0x309, 0x30e, 0x30f, 0x310, 0x312), except 0x33a + n and 0x161 + n. "Other bytes" below means the three bytes
 * that are not byte_idx.
 *
 * Phases:
 *  1. Record the step for the messages and check the arguments; byte_idx outside 0..3 prints
 *     "byte_idx %d out of range." and returns -1 at once.
 *  2. Prepare: fields 0xf0 = 0x80 and 0x0f = 0xc of register 0x30e of the byte; bits 0x13 set in register 0x306
 *     of the other bytes; bit 6 of register 1 cleared; the byte's bit (1 << byte_idx) set in 0x165, cleared in
 *     0x15f and 0x15a, cleared and set again in 0x6a; field 0x0f of register 0x306 of the byte cleared.
 *  3. Start: bits 0..1 of register 0x300 set to 2, then 3; delay 20; then up to START_POLLS polls
 *     (sys_ddr_check_phy_reg) for bit 7 of 0x300, with a "check_phy(...) wait" line after each failed one. When
 *     all fail the result is -1, and the routine goes on.
 *  4. Copy back: three registers of the byte (0x308 and 0x33a whole, 0x309 bits 0..6) are read and written to
 *     registers 0x310, 0x30f and 0x312 of the byte; the first value minus offset also goes to 0x161 + byte_idx.
 *  5. Restore: bits 0..1 of 0x300 cleared, bit 6 of register 1 set, the byte's bit set again in 0x15f and 0x15a,
 *     sys_ddr_reset_fifos, and byte_idx written to bits 2..3 of 0x300.
 *  6. Check registers 0x301 (0x78), 0x302..0x305 (0) and bit 7 of 0x306 (0); each mismatch sets the result to
 *     -1 and prints "PSD_B<byte>: check_phy(phy,reg,mask,expected)=<value read> fail".
 *  7. Clear bits 0x13 of register 0x306 of the other bytes again and return the result (0 or -1).
 */
int sys_ddr_check_phy_byte(unsigned int phy, unsigned int offset, int byte_idx)
{
    /* Values read back in phase 4, per byte: first from 0x308, second from 0x33a, third from 0x309. */
    unsigned int first_b0 = 0, first_b1 = 0, first_b2 = 0, first_b3 = 0;
    unsigned int second_b0 = 0, second_b1 = 0, second_b2 = 0, second_b3 = 0;
    unsigned int third_b0 = 0, third_b1 = 0, third_b2 = 0, third_b3 = 0;
    int result = 0;
    int i;
    unsigned int byte_bit, reg, mask, expect;

    /* 1. step record, argument checks */
    sys_ddr_set_step(DDR_STEP_PSD, phy, byte_idx);
    sys_ddr_check_arguments(phy, DDR_PHY_VERSION, DDR_GENERATION_MAX);
    if (byte_idx < 0 || byte_idx > BYTE_COUNT - 1) {
        sys_ddr_print_step();
        sys_ddr_print_error_prefix();
        dbg_printf("byte_idx %d out of range.\n", byte_idx);
        return -1;
    }

    /* 2. prepare */
    switch (byte_idx) {
    case 0:
        sys_ddr_phy_update_bits(phy, 0x30e, 0xf0, 0x80);
        sys_ddr_phy_update_bits(phy, 0x30e, 0xf, 0xc);
        break;
    case 1:
        sys_ddr_phy_update_bits(phy, 0x31b, 0xf0, 0x80);
        sys_ddr_phy_update_bits(phy, 0x31b, 0xf, 0xc);
        break;
    case 2:
        sys_ddr_phy_update_bits(phy, 0x328, 0xf0, 0x80);
        sys_ddr_phy_update_bits(phy, 0x328, 0xf, 0xc);
        break;
    case 3:
        sys_ddr_phy_update_bits(phy, 0x335, 0xf0, 0x80);
        sys_ddr_phy_update_bits(phy, 0x335, 0xf, 0xc);
        break;
    }
    if (byte_idx != 0)
        sys_ddr_phy_update_bits(phy, 0x306, 0x13, 0x13);
    if (byte_idx != 1)
        sys_ddr_phy_update_bits(phy, 0x313, 0x13, 0x13);
    if (byte_idx != 2)
        sys_ddr_phy_update_bits(phy, 0x320, 0x13, 0x13);
    if (byte_idx != 3)
        sys_ddr_phy_update_bits(phy, 0x32d, 0x13, 0x13);
    sys_ddr_phy_update_bits(phy, 1, 0x40, 0);
    byte_bit = 1 << byte_idx;
    sys_ddr_phy_update_bits(phy, 0x165, byte_bit, byte_bit);
    sys_ddr_phy_update_bits(phy, 0x15f, byte_bit, 0);
    sys_ddr_phy_update_bits(phy, 0x15a, byte_bit, 0);
    sys_ddr_phy_update_bits(phy, 0x6a, byte_bit, 0);
    sys_ddr_phy_update_bits(phy, 0x6a, byte_bit, byte_bit);
    switch (byte_idx) {
    case 0:
        sys_ddr_phy_update_bits(phy, 0x306, 0xf, 0);
        break;
    case 1:
        sys_ddr_phy_update_bits(phy, 0x313, 0xf, 0);
        break;
    case 2:
        sys_ddr_phy_update_bits(phy, 0x320, 0xf, 0);
        break;
    case 3:
        sys_ddr_phy_update_bits(phy, 0x32d, 0xf, 0);
        break;
    }

    /* 3. start, wait for bit 7 of 0x300 */
    sys_ddr_phy_update_bits(phy, 0x300, 3, 2);
    sys_ddr_phy_update_bits(phy, 0x300, 3, 3);
    sys_ddr_delay(20);
    for (i = 0; i < START_POLLS; i++) {
        if (sys_ddr_check_phy_reg(phy, 0x300, 0x80, 0x80) != 0)
            break;
        sys_ddr_print_info_prefix();
        dbg_printf("check_phy(%d,0x300,0x80,0x80) wait %d/%d\n", phy, i, START_POLLS);
    }
    if (i == START_POLLS)
        result = -1;

    /* 4. copy the read-back values */
    switch (byte_idx) {
    case 0:
        first_b0 = sys_ddr_phy_read_masked(phy, 0x308, 0xff);
        second_b0 = sys_ddr_phy_read_masked(phy, 0x33a, 0xff);
        third_b0 = sys_ddr_phy_read_masked(phy, 0x309, 0x7f);
        break;
    case 1:
        first_b1 = sys_ddr_phy_read_masked(phy, 0x315, 0xff);
        second_b1 = sys_ddr_phy_read_masked(phy, 0x33b, 0xff);
        third_b1 = sys_ddr_phy_read_masked(phy, 0x316, 0x7f);
        break;
    case 2:
        first_b2 = sys_ddr_phy_read_masked(phy, 0x322, 0xff);
        second_b2 = sys_ddr_phy_read_masked(phy, 0x33c, 0xff);
        third_b2 = sys_ddr_phy_read_masked(phy, 0x323, 0x7f);
        break;
    case 3:
        first_b3 = sys_ddr_phy_read_masked(phy, 0x32f, 0xff);
        second_b3 = sys_ddr_phy_read_masked(phy, 0x33d, 0xff);
        third_b3 = sys_ddr_phy_read_masked(phy, 0x330, 0x7f);
        break;
    }
    switch (byte_idx) {
    case 0:
        sys_ddr_phy_update_bits(phy, 0x310, 0xff, first_b0);
        sys_ddr_phy_update_bits(phy, 0x161, 0xff, first_b0 - offset);
        sys_ddr_phy_update_bits(phy, 0x30f, 0xff, second_b0);
        sys_ddr_phy_update_bits(phy, 0x312, 0x7f, third_b0);
        break;
    case 1:
        sys_ddr_phy_update_bits(phy, 0x31d, 0xff, first_b1);
        sys_ddr_phy_update_bits(phy, 0x162, 0xff, first_b1 - offset);
        sys_ddr_phy_update_bits(phy, 0x31c, 0xff, second_b1);
        sys_ddr_phy_update_bits(phy, 0x31f, 0x7f, third_b1);
        break;
    case 2:
        sys_ddr_phy_update_bits(phy, 0x32a, 0xff, first_b2);
        sys_ddr_phy_update_bits(phy, 0x163, 0xff, first_b2 - offset);
        sys_ddr_phy_update_bits(phy, 0x329, 0xff, second_b2);
        sys_ddr_phy_update_bits(phy, 0x32c, 0x7f, third_b2);
        break;
    case 3:
        sys_ddr_phy_update_bits(phy, 0x337, 0xff, first_b3);
        sys_ddr_phy_update_bits(phy, 0x164, 0xff, first_b3 - offset);
        sys_ddr_phy_update_bits(phy, 0x336, 0xff, second_b3);
        sys_ddr_phy_update_bits(phy, 0x339, 0x7f, third_b3);
        break;
    }

    /* 5. restore */
    sys_ddr_phy_update_bits(phy, 0x300, 3, 0);
    sys_ddr_phy_update_bits(phy, 1, 0x40, 0x40);
    byte_bit = 1 << byte_idx;
    sys_ddr_phy_update_bits(phy, 0x15f, byte_bit, byte_bit);
    sys_ddr_phy_update_bits(phy, 0x15a, byte_bit, byte_bit);
    sys_ddr_reset_fifos(phy);
    sys_ddr_phy_update_bits(phy, 0x300, 0xc, byte_idx << 2);

    /* 6. check registers 0x301..0x306 */
    for (i = 1; i <= 6; i++) {
        reg = 0; mask = 0; expect = 0;
        switch (i) {
        case 1:
            reg = 0x301; mask = 0xff; expect = 0x78;
            break;
        case 2:
            reg = 0x302; mask = 0xff; expect = 0;
            break;
        case 3:
            reg = 0x303; mask = 0xff; expect = 0;
            break;
        case 4:
            reg = 0x304; mask = 0xff; expect = 0;
            break;
        case 5:
            reg = 0x305; mask = 0xff; expect = 0;
            break;
        case 6:
            reg = 0x306; mask = 0x80; expect = 0;
            break;
        }
        if (sys_ddr_check_phy_reg(phy, reg, mask, expect) == 0) {
            result = -1;
            sys_ddr_print_step();
            sys_ddr_print_error_prefix();
            dbg_printf("PSD_B%d: check_phy(%d,0x%03x,0x%02x,0x%02x)=0x%02x fail\n",
                         byte_idx, phy, reg, mask, expect, sys_ddr_phy_read(phy, reg));
        }
    }

    /* 7. undo the bits 0x13 of the other bytes */
    if (byte_idx != 0)
        sys_ddr_phy_update_bits(phy, 0x306, 0x13, 0);
    if (byte_idx != 1)
        sys_ddr_phy_update_bits(phy, 0x313, 0x13, 0);
    if (byte_idx != 2)
        sys_ddr_phy_update_bits(phy, 0x320, 0x13, 0);
    if (byte_idx != 3)
        sys_ddr_phy_update_bits(phy, 0x32d, 0x13, 0);
    return result;
}
