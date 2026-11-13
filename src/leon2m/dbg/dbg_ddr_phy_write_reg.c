/* dbg_ddr_phy_write_reg  (FUN_a0114498)
 *
 * Write one register of a memory interface's paged register block.
 * Name basis: derived - unit number 0..2 selects the block 0xCF022800 / 0xCF023000 / 0xCF022C00, each with a
 *   page register at +0x3F8; no routine calls it
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0114498, flags -mcpu=v8 -O3 -g.
 * Source form: reg is an unsigned short split with unsigned char casts; the unit cases are written in the order
 * 0, 2, 1 (same form as dbg_ddr_phy_get_delay_c6_c7 and dbg_ddr_phy_get_reg_161).
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
 * Write val to register number reg of memory interface unit 0, 1 or 2: bits 8..15 of reg go to the unit's page
 * register, then val to the word of the register's low byte. Any other unit writes nothing. No routine calls it.
 */
void dbg_ddr_phy_write_reg(unsigned char unit, unsigned short reg, unsigned char val)
{
    switch (unit) {
    case 0:
        REG(UNIT0_PAGE_REG) = (unsigned char)(reg >> 8);
        PREG(UNIT0_BASE + (unsigned char)reg) = val;
        break;
    case 2:
        REG(UNIT2_PAGE_REG) = (unsigned char)(reg >> 8);
        PREG(UNIT2_BASE + (unsigned char)reg) = val;
        break;
    case 1:
        REG(UNIT1_PAGE_REG) = (unsigned char)(reg >> 8);
        PREG(UNIT1_BASE + (unsigned char)reg) = val;
        break;
    }
}
