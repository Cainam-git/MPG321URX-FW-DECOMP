/* dbg_ddr_phy_adjust_regs  (FUN_a0116914)
 *
 * Adjust three registers of a memory interface with waits in between.
 * Name basis: descriptive - registers 0x2CE, 0x2CD and 0x5A
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0116914 @ 0xa0116914-0xa0116ff4 (1760 bytes), flags -mcpu=v8 -O3 -g.
 * Source form: unit_write / unit_read are static helpers that GCC inlines; each read is nested in the argument
 * of the write, unit_write(unit, r, unit_read(unit, r) & m), because with the value in a separate variable
 * GCC shares one zero-extension of unit across the first read and write. The unit cases are written in the
 * order 0, 2, 1. Same access form as dbg_ddr_phy_write_reg and dbg_ddr_phy_get_reg_161.
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

/* The three registers adjusted here. Their numbers are above 0xFF except 0x5A, so the page register gets 2 for
   the first two. */
#define ADJUST_REG_2CE   0x2ce
#define ADJUST_REG_2CD   0x2cd
#define ADJUST_REG_5A    0x05a

/* Write one register of a unit (page register first); a unit other than 0, 1, 2 writes nothing. */
static void unit_write(unsigned char unit, unsigned short reg, unsigned char val)
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

/* Read one register of a unit (page register first); a unit other than 0, 1, 2 reads nothing and gives 0. */
static unsigned char unit_read(unsigned char unit, unsigned short reg)
{
    unsigned char value;

    value = 0;
    switch (unit) {
    case 0:
        REG(UNIT0_PAGE_REG) = (unsigned char)(reg >> 8);
        value = PREG(UNIT0_BASE + (unsigned char)reg);
        break;
    case 2:
        REG(UNIT2_PAGE_REG) = (unsigned char)(reg >> 8);
        value = PREG(UNIT2_BASE + (unsigned char)reg);
        break;
    case 1:
        REG(UNIT1_PAGE_REG) = (unsigned char)(reg >> 8);
        value = PREG(UNIT1_BASE + (unsigned char)reg);
        break;
    }
    return value;
}

extern void timer_sleep_ticks(int ticks);

/*
 * Run a fixed three-register sequence on one memory interface unit (0, 1, 2). After every write it waits
 * timer_sleep_ticks(1), which is 2 timer ticks:
 *   registers 0x2CE and then 0x2CD: first keep bits 4..6 and set bit 7, then set bits 0..3 and 7 as well
 *   (OR 0x8F);
 *   register 0x5A: clear bit 7, then set it again.
 * The purpose of the registers is not documented. The caller, dbg_ddr_test_second_setting, runs the routine
 * twice before and twice after its changes to the second memory setting.
 */
void dbg_ddr_phy_adjust_regs(unsigned char unit)
{
    unit_write(unit, ADJUST_REG_2CE, (unit_read(unit, ADJUST_REG_2CE) & 0x70) | 0x80);
    timer_sleep_ticks(1);
    unit_write(unit, ADJUST_REG_2CE, unit_read(unit, ADJUST_REG_2CE) | 0x8f);
    timer_sleep_ticks(1);
    unit_write(unit, ADJUST_REG_2CD, (unit_read(unit, ADJUST_REG_2CD) & 0x70) | 0x80);
    timer_sleep_ticks(1);
    unit_write(unit, ADJUST_REG_2CD, unit_read(unit, ADJUST_REG_2CD) | 0x8f);
    timer_sleep_ticks(1);
    unit_write(unit, ADJUST_REG_5A, unit_read(unit, ADJUST_REG_5A) & 0x7f);
    timer_sleep_ticks(1);
    unit_write(unit, ADJUST_REG_5A, unit_read(unit, ADJUST_REG_5A) | 0x80);
    timer_sleep_ticks(1);
}
