/* dbg_ddr_phy_get_delay_c8_c9  (FUN_a011579c)
 *
 * Return one of the delay values in registers 0xC8/0xC9 of a memory interface.
 * Returns: value
 * Name basis: derived - unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a011579c @ 0xa011579c-0xa01158b4 (280 bytes), flags -mcpu=v8 -O3 -g.
 * Source form: as dbg_ddr_phy_get_delay_c6_c7 (value an unsigned char cleared before reg, unit cases in the
 * order 0, 2, 1).
 */
#define REG(a) (*(volatile unsigned int *)(a))
#define PREG(n) REG(0xcf000000 | ((n) << 2))

/* Memory interface units, register blocks and page registers: see dbg_ddr_phy_get_delay_c6_c7. */
#define UNIT0_PAGE_REG   0xcf022bf8
#define UNIT1_PAGE_REG   0xcf0233f8
#define UNIT2_PAGE_REG   0xcf022ff8
#define UNIT0_BASE       0x8a00
#define UNIT1_BASE       0x8c00
#define UNIT2_BASE       0x8b00

#define DELAY_REG_C8     0xc8       /* bytes 0 and 1, second set */
#define DELAY_REG_C9     0xc9       /* bytes 2 and 3, second set */

/*
 * Read the second-set delay nibble of one data byte: the same as dbg_ddr_phy_get_delay_c6_c7 with registers
 * 0xC8 (bytes 0 and 1) and 0xC9 (bytes 2 and 3); the even byte is the low nibble, the odd byte the high nibble.
 * For a byte number above 3 register 0 of the block is read and returned whole. A unit other than 0, 1, 2
 * reads nothing and returns 0.
 * Nothing calls it; dbg_ddr_test_delay_offset contains the same code as a private copy.
 */
unsigned char dbg_ddr_phy_get_delay_c8_c9(unsigned char unit, unsigned short byte)
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
