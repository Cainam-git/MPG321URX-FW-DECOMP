/* dbg_ddr_phy_get_delay_c6_c7  (FUN_a0115684)
 *
 * Return one of the four delay nibbles in registers 0xC6/0xC7 of a memory interface.
 * Returns: nibble
 * Name basis: derived - printed in the stress test's result table
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0115684 @ 0xa0115684-0xa011579c (280 bytes), flags -mcpu=v8 -O3 -g.
 * Source form: value is an unsigned char (the word read is copied into it at the join), reg an unsigned short
 * passed through an unsigned char cast; the unit cases are written in the order 0, 2, 1 and value is cleared
 * before reg.
 */
#define REG(a) (*(volatile unsigned int *)(a))
#define PREG(n) REG(0xcf000000 | ((n) << 2))

/*
 * Memory interface register blocks as the stress test numbers them. Register r (low byte) of a block is the
 * word at 0xCF000000 | ((index base + r) << 2); the page register (block + 0x3F8) takes bits 8..15 of the
 * register number first.
 *   unit 0: block 0xCF022800      unit 1: block 0xCF023000      unit 2: block 0xCF022C00
 */
#define UNIT0_PAGE_REG   0xcf022bf8
#define UNIT1_PAGE_REG   0xcf0233f8
#define UNIT2_PAGE_REG   0xcf022ff8
#define UNIT0_BASE       0x8a00
#define UNIT1_BASE       0x8c00
#define UNIT2_BASE       0x8b00

/* Delay registers: each holds the nibbles of two data bytes, the even byte in bits 0..3, the odd byte in
   bits 4..7. */
#define DELAY_REG_C6     0xc6       /* bytes 0 and 1 */
#define DELAY_REG_C7     0xc7       /* bytes 2 and 3 */

/*
 * Read the delay nibble of one data byte: register 0xC6 holds bytes 0 and 1, register 0xC7 bytes 2 and 3; the
 * even byte is the low nibble, the odd byte the high nibble. Page register 0 is selected first. For a byte
 * number above 3 register 0 of the block is read and returned whole. A unit other than 0, 1, 2 reads nothing
 * and returns 0.
 * Caller: dbg_ddr_stress_task, for the result table. Write counterpart: dbg_ddr_phy_set_delay_c6_c7.
 */
unsigned char dbg_ddr_phy_get_delay_c6_c7(unsigned char unit, unsigned short byte)
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
        REG(UNIT0_PAGE_REG) = 0;
        value = PREG(UNIT0_BASE + (unsigned char)reg);
        break;
    case 2:
        REG(UNIT2_PAGE_REG) = 0;
        value = PREG(UNIT2_BASE + (unsigned char)reg);
        break;
    case 1:
        REG(UNIT1_PAGE_REG) = 0;
        value = PREG(UNIT1_BASE + (unsigned char)reg);
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
