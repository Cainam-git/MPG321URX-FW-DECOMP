/* dbg_ddr_phy_set_reg_161  (FUN_a01167ec)
 *
 * Write one of the registers 0x161..0x164 of a memory interface.
 * Name basis: descriptive - unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01167ec, flags -mcpu=v8 -O3 -g.
 * Source form: the write is a static copy of dbg_ddr_phy_write_reg (wr) that GCC inlines.
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

/* Write val to register number reg of unit 0, 1 or 2 (page register first); another unit writes nothing. */
static void wr(unsigned char unit, unsigned short reg, unsigned char val)
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

/*
 * Write val to the register of data byte 'data_byte' (0..3: registers 0x161..0x164; any other value writes
 * register 0) of memory interface unit 0, 1 or 2. Write counterpart of dbg_ddr_phy_get_reg_161. No routine calls
 * it; dbg_ddr_test_second_setting has the same code inline.
 */
void dbg_ddr_phy_set_reg_161(unsigned char unit, unsigned short data_byte, unsigned char val)
{
    unsigned short reg;

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
    wr(unit, reg, val);
}
