/* dbg_ddr_test_delay_offset  (FUN_a0115bd4)
 *
 * Shift the delay settings of a memory interface by an offset and measure the result.
 * Name basis: derived - moves the nibbles by x - 7 and runs two measurement sequences; a step of the stress
 *   test
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0115bd4 @ 0xa0115bd4-0xa01166d8 (2820 bytes), flags -mcpu=v8 -O3 -g.
 * Source form: the four nibble helpers are static copies of dbg_ddr_phy_get_delay_c6_c7, dbg_ddr_phy_get_delay_c8_c9, dbg_ddr_phy_set_delay_c6_c7 and
 * dbg_ddr_phy_set_delay_c8_c9 (unit cases in the order 0, 2, 1; the readers clear the value before the register number). The two
 * writers are declared inline (without it GCC calls them instead of inlining both copies) and write the page
 * register as (unsigned char)(reg >> 8) like the standalone writers. The offset > 7 arm is written as
 * 'else if (offset > 7)' (a plain else gives a different block layout).
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

/* Delay registers (page 0). Each holds the nibbles of two data bytes: the even byte in bits 0..3, the odd byte
   in bits 4..7. The stress test prints the 0xC6 / 0xC7 nibble of each byte in its result table. */
#define DELAY_REG_C6     0xc6       /* bytes 0 and 1 */
#define DELAY_REG_C7     0xc7       /* bytes 2 and 3 */
#define DELAY_REG_C8     0xc8       /* bytes 0 and 1, second set */
#define DELAY_REG_C9     0xc9       /* bytes 2 and 3, second set */

#define OFFSET_NONE      7          /* offset value that leaves the delays as they are */

/* Registers of the measurement sequence (purpose not documented; named by address). */
#define CTRL_12E00       REG(0xcf012e00)    /* saved, written 0x11, 1, 0x81 by each measurement, restored */
#define CTRL_12E40       REG(0xcf012e40)
#define CTRL_12F2C       REG(0xcf012f2c)    /* written 2, then 5; bit 7 read back */
#define RESULT_12F30     REG(0xcf012f30)    /* the four result bytes that are summed */
#define RESULT_12F34     REG(0xcf012f34)
#define RESULT_12F38     REG(0xcf012f38)
#define RESULT_12F3C     REG(0xcf012f3c)
#define PORT0_BLOCK_REG0 REG(0xcf013800)    /* register 0 of port block 0 (pq_port_read8's block table) */

extern void timer_sleep_ticks(int ticks);
extern void pq_block8_start(void);
extern void pq_port_set_reg10_bit0(unsigned char, unsigned char);
extern void pq_block8_stop(void);

/* Return the 0xC6 / 0xC7 delay nibble of one data byte (copy of dbg_ddr_phy_get_delay_c6_c7). */
static unsigned char read_delay_c6_c7(unsigned char unit, unsigned short byte)
{
    unsigned short reg;
    unsigned char value;

    value = 0;
    reg = 0;
    switch (byte) {
    case 0:
    case 1:
        reg = DELAY_REG_C6;
        break;
    case 2:
    case 3:
        reg = DELAY_REG_C7;
        break;
    }
    switch (unit) {
    case 0:
        UNIT0_PAGE_REG = 0;
        value = UNIT0_REG((unsigned char)reg);
        break;
    case 2:
        UNIT2_PAGE_REG = 0;
        value = UNIT2_REG((unsigned char)reg);
        break;
    case 1:
        UNIT1_PAGE_REG = 0;
        value = UNIT1_REG((unsigned char)reg);
        break;
    }
    switch (byte) {
    case 0:
    case 2:
        value = value & 0xf;
        break;
    case 1:
    case 3:
        value = value >> 4;
        break;
    }
    return value;
}

/* Return the 0xC8 / 0xC9 delay nibble of one data byte (copy of dbg_ddr_phy_get_delay_c8_c9). */
static unsigned char read_delay_c8_c9(unsigned char unit, unsigned short byte)
{
    unsigned short reg;
    unsigned char value;

    value = 0;
    reg = 0;
    switch (byte) {
    case 0:
    case 1:
        reg = DELAY_REG_C8;
        break;
    case 2:
    case 3:
        reg = DELAY_REG_C9;
        break;
    }
    switch (unit) {
    case 0:
        UNIT0_PAGE_REG = 0;
        value = UNIT0_REG((unsigned char)reg);
        break;
    case 2:
        UNIT2_PAGE_REG = 0;
        value = UNIT2_REG((unsigned char)reg);
        break;
    case 1:
        UNIT1_PAGE_REG = 0;
        value = UNIT1_REG((unsigned char)reg);
        break;
    }
    switch (byte) {
    case 0:
    case 2:
        value = value & 0xf;
        break;
    case 1:
    case 3:
        value = value >> 4;
        break;
    }
    return value;
}

/* Write the 0xC6 / 0xC7 delay nibble of one data byte, keeping the other nibble (copy of
   dbg_ddr_phy_set_delay_c6_c7). */
static inline void write_delay_c6_c7(unsigned char unit, unsigned short byte, unsigned char nibble)
{
    unsigned short reg;

    reg = 0;
    switch (byte) {
    case 0:
    case 1:
        reg = DELAY_REG_C6;
        break;
    case 2:
    case 3:
        reg = DELAY_REG_C7;
        break;
    }
    switch (unit) {
    case 0:
        UNIT0_PAGE_REG = (unsigned char)(reg >> 8);
        if (byte == 0 || byte == 2)
            UNIT0_REG((unsigned char)reg) = (UNIT0_REG((unsigned char)reg) & 0xf0) | (nibble & 0xf);
        else
            UNIT0_REG((unsigned char)reg) = (UNIT0_REG((unsigned char)reg) & 0xf) | (nibble << 4);
        break;
    case 2:
        UNIT2_PAGE_REG = (unsigned char)(reg >> 8);
        if (byte == 0 || byte == 2)
            UNIT2_REG((unsigned char)reg) = (UNIT2_REG((unsigned char)reg) & 0xf0) | (nibble & 0xf);
        else
            UNIT2_REG((unsigned char)reg) = (UNIT2_REG((unsigned char)reg) & 0xf) | (nibble << 4);
        break;
    case 1:
        UNIT1_PAGE_REG = (unsigned char)(reg >> 8);
        if (byte == 0 || byte == 2)
            UNIT1_REG((unsigned char)reg) = (UNIT1_REG((unsigned char)reg) & 0xf0) | (nibble & 0xf);
        else
            UNIT1_REG((unsigned char)reg) = (UNIT1_REG((unsigned char)reg) & 0xf) | (nibble << 4);
        break;
    }
}

/* Write the 0xC8 / 0xC9 delay nibble of one data byte, keeping the other nibble (copy of
   dbg_ddr_phy_set_delay_c8_c9). */
static inline void write_delay_c8_c9(unsigned char unit, unsigned short byte, unsigned char nibble)
{
    unsigned short reg;

    reg = 0;
    switch (byte) {
    case 0:
    case 1:
        reg = DELAY_REG_C8;
        break;
    case 2:
    case 3:
        reg = DELAY_REG_C9;
        break;
    }
    switch (unit) {
    case 0:
        UNIT0_PAGE_REG = (unsigned char)(reg >> 8);
        if (byte == 0 || byte == 2)
            UNIT0_REG((unsigned char)reg) = (UNIT0_REG((unsigned char)reg) & 0xf0) | (nibble & 0xf);
        else
            UNIT0_REG((unsigned char)reg) = (UNIT0_REG((unsigned char)reg) & 0xf) | (nibble << 4);
        break;
    case 2:
        UNIT2_PAGE_REG = (unsigned char)(reg >> 8);
        if (byte == 0 || byte == 2)
            UNIT2_REG((unsigned char)reg) = (UNIT2_REG((unsigned char)reg) & 0xf0) | (nibble & 0xf);
        else
            UNIT2_REG((unsigned char)reg) = (UNIT2_REG((unsigned char)reg) & 0xf) | (nibble << 4);
        break;
    case 1:
        UNIT1_PAGE_REG = (unsigned char)(reg >> 8);
        if (byte == 0 || byte == 2)
            UNIT1_REG((unsigned char)reg) = (UNIT1_REG((unsigned char)reg) & 0xf0) | (nibble & 0xf);
        else
            UNIT1_REG((unsigned char)reg) = (UNIT1_REG((unsigned char)reg) & 0xf) | (nibble << 4);
        break;
    }
}

/*
 * One measurement: write the control sequence with waits, read the four result bytes and return
 * previous | (sum of the four bytes). The one pattern 0, 0, 0x10, 0 with bit 7 of 0xCF012F2C clear counts as
 * all zero.
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
 * Shift both delay nibbles of one data byte by an offset, run two measurements and put the nibbles back.
 *
 *   unit    memory interface block 0..2 (see UNIT0_PAGE_REG); another value reads 0 and writes nothing
 *   byte    data byte 0..3, numbered as in dbg_ddr_phy_get_delay_c6_c7
 *   offset  biased by 7: 7 leaves the delays as they are, 0..6 moves them down by 7 - offset, 8..15 up by
 *           offset - 7; the nibbles wrap round modulo 16
 *
 * Returns the OR of the two measurement sums; dbg_ddr_stress_task counts the steps in a row that return 0.
 * Called only by dbg_ddr_run_test_step (test mode 0), which saves and sets a group of registers before and
 * restores them after.
 *
 * Phases:
 *   1. read the current 0xC6/0xC7 and 0xC8/0xC9 nibbles of the byte; save 0xCF012E00; port block 0 register 0 = 0;
 *   2. unless the offset is 7: compute the two shifted nibbles and write them, one tick of wait after each;
 *   3. 0xCF012E40 = 0x71, start picture block 8, pq_port_set_reg10_bit0(0, 0);
 *   4. measure once with port block 0 register 0 = 0 and once with 0x30, ORing the sums;
 *   5. restore 0xCF012E00, stop picture block 8 and write the original nibbles back.
 */
unsigned char dbg_ddr_test_delay_offset(unsigned char unit, unsigned short byte, unsigned char offset)
{
    unsigned char delay_c6_c7, delay_c8_c9, new_c6_c7, new_c8_c9, saved_ctrl, result;

    /* 1. Keep the current settings to put them back at the end. */
    new_c6_c7 = 0;
    new_c8_c9 = 0;
    delay_c6_c7 = read_delay_c6_c7(unit, byte);
    delay_c8_c9 = read_delay_c8_c9(unit, byte);
    saved_ctrl = CTRL_12E00;
    PORT0_BLOCK_REG0 = 0;

    /* 2. Move both nibbles by offset - 7, modulo 16. */
    if (offset != OFFSET_NONE) {
        if (offset < OFFSET_NONE) {
            new_c6_c7 = (delay_c6_c7 - (OFFSET_NONE - offset)) & 0xf;
            new_c8_c9 = (delay_c8_c9 - (OFFSET_NONE - offset)) & 0xf;
        } else if (offset > OFFSET_NONE) {
            new_c6_c7 = (delay_c6_c7 + (offset - OFFSET_NONE)) & 0xf;
            new_c8_c9 = (delay_c8_c9 + (offset - OFFSET_NONE)) & 0xf;
        }
        write_delay_c6_c7(unit, byte, new_c6_c7);
        timer_sleep_ticks(1);
        write_delay_c8_c9(unit, byte, new_c8_c9);
        timer_sleep_ticks(1);
    }

    /* 3. Set-up before the measurements. */
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
    write_delay_c6_c7(unit, byte, delay_c6_c7);
    timer_sleep_ticks(1);
    write_delay_c8_c9(unit, byte, delay_c8_c9);
    timer_sleep_ticks(1);
    return result;
}
