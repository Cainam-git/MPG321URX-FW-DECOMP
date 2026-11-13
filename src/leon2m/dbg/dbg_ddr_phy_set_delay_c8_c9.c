/* dbg_ddr_phy_set_delay_c8_c9  (FUN_a0115a44)
 *
 * Write one of the delay values in registers 0xC8/0xC9 of a memory interface.
 * Name basis: derived - read-modify-write; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0115a44 @ 0xa0115a44-0xa0115bd4 (400 bytes), flags -mcpu=v8 -O3 -g.
 * Source form: the page register value is written as (unsigned char)(reg >> 8), as in
 * dbg_ddr_phy_write_reg; GCC folds it to a stored 0, and the written-out form places the store ahead of the
 * byte test (a literal 0 does not).
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
 * Set the second-set delay nibble of one data byte, leaving the other nibble of the register as it is:
 * register 0xC8 holds bytes 0 and 1, register 0xC9 bytes 2 and 3; the even byte is the low nibble, the odd
 * byte the high nibble. nibble is the new value (only its low 4 bits count). The register is read, changed
 * and written back. For a byte number above 3 register 0 of the block is the one changed, as an odd byte
 * (high nibble). A unit other than 0, 1, 2 writes nothing.
 * Nothing calls it; dbg_ddr_test_delay_offset contains the same code as a private copy.
 * Counterpart of dbg_ddr_phy_get_delay_c8_c9.
 */
void dbg_ddr_phy_set_delay_c8_c9(unsigned char unit, unsigned short byte, unsigned char nibble)
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
        REG(UNIT0_PAGE_REG) = (unsigned char)(reg >> 8);
        if (byte == 0 || byte == 2)
            PREG(UNIT0_BASE + (unsigned char)reg) = (PREG(UNIT0_BASE + (unsigned char)reg) & 0xf0) | (nibble & 0xf);
        else
            PREG(UNIT0_BASE + (unsigned char)reg) = (PREG(UNIT0_BASE + (unsigned char)reg) & 0xf) | (nibble << 4);
        break;
    case 2:
        REG(UNIT2_PAGE_REG) = (unsigned char)(reg >> 8);
        if (byte == 0 || byte == 2)
            PREG(UNIT2_BASE + (unsigned char)reg) = (PREG(UNIT2_BASE + (unsigned char)reg) & 0xf0) | (nibble & 0xf);
        else
            PREG(UNIT2_BASE + (unsigned char)reg) = (PREG(UNIT2_BASE + (unsigned char)reg) & 0xf) | (nibble << 4);
        break;
    case 1:
        REG(UNIT1_PAGE_REG) = (unsigned char)(reg >> 8);
        if (byte == 0 || byte == 2)
            PREG(UNIT1_BASE + (unsigned char)reg) = (PREG(UNIT1_BASE + (unsigned char)reg) & 0xf0) | (nibble & 0xf);
        else
            PREG(UNIT1_BASE + (unsigned char)reg) = (PREG(UNIT1_BASE + (unsigned char)reg) & 0xf) | (nibble << 4);
        break;
    }
}
