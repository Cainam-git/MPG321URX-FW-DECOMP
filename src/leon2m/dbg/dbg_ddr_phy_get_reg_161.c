/* dbg_ddr_phy_get_reg_161  (FUN_a01166d8)
 *
 * Return one of the registers 0x161..0x164 of a memory interface.
 * Returns: byte
 * Name basis: descriptive - printed in the stress test's result table
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01166d8, flags -mcpu=v8 -O3 -g.
 * Source form: the register number is an unsigned short split with unsigned char casts; the result is an unsigned
 * char cleared first; the unit cases are written in the order 0, 2, 1 (same form as dbg_ddr_phy_get_delay_c6_c7).
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

/* One register per data byte 0..3. */
#define SETTING_REG_BYTE0 0x161
#define SETTING_REG_BYTE1 0x162
#define SETTING_REG_BYTE2 0x163
#define SETTING_REG_BYTE3 0x164

/*
 * Read the register of data byte 'data_byte' (0..3: registers 0x161..0x164; any other value reads register 0) of
 * memory interface unit 0, 1 or 2 and return its low byte. Any other unit reads nothing and returns 0. The stress
 * task (dbg_ddr_stress_task) calls it for the third column of its result table, with unit = row / 4 and
 * data_byte = row % 4.
 */
unsigned char dbg_ddr_phy_get_reg_161(unsigned char unit, unsigned short data_byte)
{
    unsigned short reg;
    unsigned char val;

    val = 0;
    reg = 0;
    switch (data_byte) {
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
        REG(UNIT0_PAGE_REG) = (unsigned char)(reg >> 8);
        val = PREG(UNIT0_BASE + (unsigned char)reg);
        break;
    case 2:
        REG(UNIT2_PAGE_REG) = (unsigned char)(reg >> 8);
        val = PREG(UNIT2_BASE + (unsigned char)reg);
        break;
    case 1:
        REG(UNIT1_PAGE_REG) = (unsigned char)(reg >> 8);
        val = PREG(UNIT1_BASE + (unsigned char)reg);
        break;
    }
    return val;
}
