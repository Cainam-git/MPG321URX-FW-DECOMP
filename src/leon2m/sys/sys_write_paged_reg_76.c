/* sys_write_paged_reg_76  (FUN_a0122dbc)
 *
 * Write a paged register 0x7600 + n with the page register saved and restored.
 * Name basis: descriptive - page register 0xCF03D024; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0122dbc @ 0xa0122dbc-0xa0122e24, flags -mcpu=v8 -O3 -g.
 */
/* Page select register; its low byte is saved and restored around the write. */
#define PAGE_SELECT (*(volatile unsigned int *)0xcf03d024)
#define PAGE_F_SETUP (*(volatile unsigned int *)0xcf01d858)
#define PAGE_F 0xf                              /* page value that needs the extra set-up below */
#define PAGED_REG_BASE 0x7600                   /* register number of paged register 0 */

/*
 * Write value to the register 0x7600 + reg, with page selected in PAGE_SELECT.
 * The old page value is put back afterwards. For page 0xf, PAGE_SELECT first gets 0xc and 0xcf01d858 gets 0xff.
 * Name basis marks it unused: nothing calls it.
 */
void sys_write_paged_reg_76(unsigned char page, unsigned char reg, unsigned char value)
{
    unsigned char saved_page = PAGE_SELECT;

    if (page == PAGE_F) {
        PAGE_SELECT = 0xc;
        PAGE_F_SETUP = 0xff;
    }
    PAGE_SELECT = page;
    *(volatile unsigned int *)(0xcf000000 | ((reg + PAGED_REG_BASE) << 2)) = value;
    PAGE_SELECT = saved_page;
}
