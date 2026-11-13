/* dbg_ddr_phy_read_reg  (FUN_a0114570)
 *
 * Read one register of a memory interface's paged register block.
 * Returns: low byte of the register; 0 for a unit other than 0..2
 * Name basis: derived - unit number 0..2 selects the block 0xCF022800 / 0xCF023000 / 0xCF022C00, each with a
 *   page register at +0x3F8; no routine calls it
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0114570, flags -mcpu=v8 -O3 -g.
 * Source form: the result is an unsigned char cleared first; the unit cases are written in the order 0, 2, 1 (same
 * form as dbg_ddr_phy_get_reg_161 and the write routine dbg_ddr_phy_write_reg).
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

/*
 * Read register number reg of memory interface unit 0, 1 or 2 and return its low byte: bits 8..15 of reg go to the
 * unit's page register first. Any other unit reads nothing and returns 0. No routine calls it; the same code is
 * inline in sys_reset_memory_interfaces and dbg_ddr_test_second_setting.
 */
unsigned char dbg_ddr_phy_read_reg(unsigned char unit, unsigned short reg)
{
    unsigned char val;

    val = 0;
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
