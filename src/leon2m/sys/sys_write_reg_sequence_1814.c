/* sys_write_reg_sequence_1814  (FUN_a01234b8)
 *
 * Clear register 0xCF011814 and write four values through the shared write sequence.
 * Name basis: descriptive - mechanics only; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01234b8 @ 0xa01234b8-0xa0123574, flags -mcpu=v8 -O3 -g.
 * Source form: the paged write (as in sys_write_paged_reg_76) is a static helper inlined four times.
 */
#define PAGE_SELECT (*(volatile unsigned int *)0xcf03d024)
#define PAGE_F_SETUP (*(volatile unsigned int *)0xcf01d858)
#define REG_1814 (*(volatile unsigned int *)0xcf011814)

/* Write value to register 0x7600 + reg under page; same steps as sys_write_paged_reg_76. */
static void write_paged_reg(unsigned char page, unsigned char reg, unsigned char value)
{
    unsigned char saved_page = PAGE_SELECT;

    if (page == 0xf) {
        PAGE_SELECT = 0xc;
        PAGE_F_SETUP = 0xff;
    }
    PAGE_SELECT = page;
    *(volatile unsigned int *)(0xcf000000 | ((reg + 0x7600) << 2)) = value;
    PAGE_SELECT = saved_page;
}

/*
 * Clear register 0xcf011814, then write four paged registers: (page 0xc, reg 0x11) = 1,
 * (0xc, 0x14) = 0x55, (0xc, 0x12) = 0x51 and (page 0, reg 3) = 0xf7. Name basis marks it unused: nothing calls it.
 */
void sys_write_reg_sequence_1814(void)
{
    REG_1814 = 0;
    write_paged_reg(0xc, 0x11, 1);
    write_paged_reg(0xc, 0x14, 0x55);
    write_paged_reg(0xc, 0x12, 0x51);
    write_paged_reg(0, 3, 0xf7);
}
