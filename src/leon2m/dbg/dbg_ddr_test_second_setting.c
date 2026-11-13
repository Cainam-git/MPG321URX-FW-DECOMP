/* dbg_ddr_test_second_setting  (FUN_a0116ff4)
 *
 * Change a second memory interface setting, measure the result and restore it.
 * Name basis: derived - sums two four-register reads; a step of the stress test
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0116ff4 @ 0xa0116ff4-0xa0117f48 (3924 bytes), flags -mcpu=v8 -O3 -g.
 * Source form: unit_write / unit_read as in dbg_ddr_phy_adjust_regs (each read nested in the argument of the
 * write; unit cases in the order 0, 2, 1); read_setting is a copy of dbg_ddr_phy_get_reg_161. The OR of the two
 * measurement results is inside measure's return expression (with result |= measure() GCC keeps a
 * zero-extension of the second sum). apply_setting is declared inline (without it GCC calls it instead of
 * inlining both copies). The offset > 7 arm is written as 'else if (offset > 7)'.
 */
#define REG(a) (*(volatile unsigned int *)(a))
#define PREG(n) REG(0xcf000000 | ((n) << 2))

/*
 * Memory interface register blocks as the stress test numbers them. Register r (low byte) of a block is the
 * word at 0xCF000000 | ((index base + r) << 2); the page register (block + 0x3F8, PHY_PAGE_REG_OFFSET) takes
 * bits 8..15 of the register number first.
 *   unit 0: block 0xCF022800      unit 1: block 0xCF023000      unit 2: block 0xCF022C00
 * Units 1 and 2 are in the other order than the sys_ddr_phy_* routines number their interfaces (PHY_TAB).
 */
#define UNIT0_PAGE_REG   REG(0xcf022bf8)
#define UNIT1_PAGE_REG   REG(0xcf0233f8)
#define UNIT2_PAGE_REG   REG(0xcf022ff8)
#define UNIT0_REG(r)     PREG(0x8a00 + (r))
#define UNIT1_REG(r)     PREG(0x8c00 + (r))
#define UNIT2_REG(r)     PREG(0x8b00 + (r))

/* The setting this test changes: one register per data byte (page 1). The stress test prints the byte-0..3
   values (dbg_ddr_phy_get_reg_161) in its result table. */
#define SETTING_REG_BYTE0 0x161
#define SETTING_REG_BYTE1 0x162
#define SETTING_REG_BYTE2 0x163
#define SETTING_REG_BYTE3 0x164

/* Bits set while the setting register is written and cleared right after. */
#define REG_008          0x008
#define REG_008_BIT5     0x20
#define REG_251          0x251
#define REG_251_BIT6     0x40

#define OFFSET_NONE      7          /* offset value that leaves the setting as it is */

/* Registers of the measurement sequence (purpose not documented; named by address). */
#define CTRL_12E00       REG(0xcf012e00)    /* saved, written 0x11, 1, 0x81 by each measurement, restored */
#define CTRL_12E40       REG(0xcf012e40)
#define CTRL_12F2C       REG(0xcf012f2c)    /* written 2, then 5; bit 7 read back */
#define RESULT_12F30     REG(0xcf012f30)    /* the four result bytes that are summed */
#define RESULT_12F34     REG(0xcf012f34)
#define RESULT_12F38     REG(0xcf012f38)
#define RESULT_12F3C     REG(0xcf012f3c)
#define PORT0_BLOCK_REG0 REG(0xcf013800)    /* register 0 of port block 0 (pq_port_read8's block table) */

/* Write one register of a unit: page first, then the register. */
static void unit_write(unsigned char unit, unsigned short reg, unsigned char value)
{
    switch (unit) {
    case 0:
        UNIT0_PAGE_REG = (unsigned char)(reg >> 8);
        UNIT0_REG((unsigned char)reg) = value;
        break;
    case 2:
        UNIT2_PAGE_REG = (unsigned char)(reg >> 8);
        UNIT2_REG((unsigned char)reg) = value;
        break;
    case 1:
        UNIT1_PAGE_REG = (unsigned char)(reg >> 8);
        UNIT1_REG((unsigned char)reg) = value;
        break;
    }
}

/* Read one register of a unit; an unknown unit reads 0. */
static unsigned char unit_read(unsigned char unit, unsigned short reg)
{
    unsigned char value;

    value = 0;
    switch (unit) {
    case 0:
        UNIT0_PAGE_REG = (unsigned char)(reg >> 8);
        value = UNIT0_REG((unsigned char)reg);
        break;
    case 2:
        UNIT2_PAGE_REG = (unsigned char)(reg >> 8);
        value = UNIT2_REG((unsigned char)reg);
        break;
    case 1:
        UNIT1_PAGE_REG = (unsigned char)(reg >> 8);
        value = UNIT1_REG((unsigned char)reg);
        break;
    }
    return value;
}

extern void timer_sleep_ticks(int ticks);
extern void dbg_ddr_phy_adjust_regs(unsigned char unit);
extern void pq_block8_start(void);
extern void pq_port_set_reg10_bit0(unsigned char, unsigned char);
extern void pq_block8_stop(void);

/* Return the setting of one data byte (copy of dbg_ddr_phy_get_reg_161). */
static unsigned char read_setting(unsigned char unit, unsigned short byte)
{
    unsigned short reg;
    unsigned char value;

    value = 0;
    reg = 0;
    switch (byte) {
    case 0:
        reg = SETTING_REG_BYTE0;
        break;
    case 1:
        reg = SETTING_REG_BYTE1;
        break;
    case 2:
        reg = SETTING_REG_BYTE2;
        break;
    case 3:
        reg = SETTING_REG_BYTE3;
        break;
    }
    switch (unit) {
    case 0:
        UNIT0_PAGE_REG = (unsigned char)(reg >> 8);
        value = UNIT0_REG((unsigned char)reg);
        break;
    case 2:
        UNIT2_PAGE_REG = (unsigned char)(reg >> 8);
        value = UNIT2_REG((unsigned char)reg);
        break;
    case 1:
        UNIT1_PAGE_REG = (unsigned char)(reg >> 8);
        value = UNIT1_REG((unsigned char)reg);
        break;
    }
    return value;
}

/* Write the setting register of one data byte. */
static void write_setting(unsigned char unit, unsigned short byte, unsigned char value)
{
    unsigned short reg;

    reg = 0;
    switch (byte) {
    case 0:
        reg = SETTING_REG_BYTE0;
        break;
    case 1:
        reg = SETTING_REG_BYTE1;
        break;
    case 2:
        reg = SETTING_REG_BYTE2;
        break;
    case 3:
        reg = SETTING_REG_BYTE3;
        break;
    }
    unit_write(unit, reg, value);
}

/* Write the setting with bit 5 of register 0x008 and bit 6 of 0x251 set around it, one tick of wait after
   each write. */
static inline void apply_setting(unsigned char unit, unsigned short byte, unsigned char value)
{
    unit_write(unit, REG_008, (unit_read(unit, REG_008) & 0xdf) | REG_008_BIT5);
    timer_sleep_ticks(1);
    unit_write(unit, REG_251, (unit_read(unit, REG_251) & 0xbf) | REG_251_BIT6);
    timer_sleep_ticks(1);
    write_setting(unit, byte, value);
    timer_sleep_ticks(1);
    unit_write(unit, REG_008, unit_read(unit, REG_008) & 0xdf);
    timer_sleep_ticks(1);
    unit_write(unit, REG_251, unit_read(unit, REG_251) & 0xbf);
    timer_sleep_ticks(1);
}

/*
 * One measurement: write the control sequence with waits, read the four result bytes and return
 * previous | (sum of the four bytes). The one pattern 0, 0, 0x10, 0 with bit 7 of 0xCF012F2C clear counts as
 * all zero. Same sequence as in dbg_ddr_test_delay_offset.
 */
static unsigned char measure(unsigned char previous)
{
    unsigned char a, b, c, d;

    CTRL_12E00 = 0x11;
    timer_sleep_ticks(0x28);
    CTRL_12E00 = 1;
    timer_sleep_ticks(0x28);
    CTRL_12E00 = 0x81;
    timer_sleep_ticks(0x14);
    CTRL_12F2C = 2;
    timer_sleep_ticks(0x14);
    CTRL_12F2C = 5;
    timer_sleep_ticks(0x14);
    a = RESULT_12F30;
    b = RESULT_12F34;
    c = RESULT_12F38;
    d = RESULT_12F3C;
    if (!(CTRL_12F2C & 0x80) && a == 0 && b == 0 && c == 0x10 && d == 0)
        c = 0;
    return previous | (a + b + c + d);
}

/*
 * Move the high nibble of one data byte's setting register (0x161..0x164) by an offset, run two measurements
 * and put the setting back.
 *
 *   unit    memory interface block 0..2 (see UNIT0_PAGE_REG); another value reads 0 and writes nothing
 *   byte    data byte 0..3, numbered as in dbg_ddr_phy_get_reg_161
 *   offset  biased by 7: 7 leaves the setting as it is, 0..6 subtracts (7 - offset) * 16, 8..15 adds
 *           (offset - 7) * 16 (written as offset * 16 - 0x70). A lowered value whose high nibble is 0xF
 *           becomes 0; a raised value wraps round at 0x100.
 *
 * Returns the OR of the two measurement sums; dbg_ddr_stress_task counts the steps in a row that return 0.
 * Called only by dbg_ddr_run_test_step (test mode 1), which saves and sets a group of registers before and
 * restores them after.
 *
 * Phases:
 *   1. read the current setting; save 0xCF012E00; port block 0 register 0 = 0;
 *   2. unless the offset is 7: compute the new value and write it (apply_setting);
 *   3. dbg_ddr_phy_adjust_regs twice; 0xCF012E40 = 0x71, start picture block 8, pq_port_set_reg10_bit0(0, 0);
 *   4. measure once with port block 0 register 0 = 0 and once with 0x30, ORing the sums;
 *   5. restore 0xCF012E00, stop picture block 8, write the original setting back and run
 *      dbg_ddr_phy_adjust_regs twice again.
 */
unsigned char dbg_ddr_test_second_setting(unsigned char unit, unsigned short byte, unsigned char offset)
{
    unsigned char setting, new_setting, saved_ctrl, result;

    /* 1. Keep the current setting to put it back at the end. */
    new_setting = 0;
    setting = read_setting(unit, byte);
    saved_ctrl = CTRL_12E00;
    PORT0_BLOCK_REG0 = 0;

    /* 2. Move the high nibble by offset - 7. */
    if (offset != OFFSET_NONE) {
        if (offset < OFFSET_NONE) {
            new_setting = setting - (OFFSET_NONE - offset) * 16;
            if ((new_setting & 0xf0) == 0xf0)
                new_setting = 0;
        } else if (offset > OFFSET_NONE) {
            new_setting = setting + offset * 16 - 0x70;
        }
        apply_setting(unit, byte, new_setting);
    }

    /* 3. Set-up before the measurements. */
    dbg_ddr_phy_adjust_regs(unit);
    dbg_ddr_phy_adjust_regs(unit);
    CTRL_12E40 = 0x71;
    pq_block8_start();
    pq_port_set_reg10_bit0(0, 0);

    /* 4. Two measurements; any non-zero sum makes the result non-zero. */
    result = measure(0);
    PORT0_BLOCK_REG0 = 0x30;
    result = measure(result);

    /* 5. Put everything back. */
    CTRL_12E00 = saved_ctrl;
    pq_block8_stop();
    apply_setting(unit, byte, setting);
    dbg_ddr_phy_adjust_regs(unit);
    dbg_ddr_phy_adjust_regs(unit);
    return result;
}
