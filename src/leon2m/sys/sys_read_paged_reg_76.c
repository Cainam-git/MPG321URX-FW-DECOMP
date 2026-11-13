/* sys_read_paged_reg_76  (FUN_a0122e24)
 *
 * Read register reg of group 0x76 through the indirect registers, with the given page selected.
 * Returns: value
 * Name basis: descriptive - registers 0xCF011820..0xCF011828 (select 0x76, index, data); no direct caller, its
 *   address is taken
 *
 * Matching notes
 * --------------
 * Flags -mcpu=v8 -O2 -g (the section default).
 * leon2m FUN_a0122e24 @ 0xa0122e24-0xa0122e80 (23 words).
 * The kept values and the result are unsigned char locals, which gives the and 0xff before each store and the
 * register window (save) of the firmware.
 */
#define PAGE_SELECT (*(volatile unsigned int *)0xcf03d024)
#define INDIRECT_SELECT (*(volatile unsigned int *)0xcf011820)  /* receives 0x76 */
#define INDIRECT_INDEX (*(volatile unsigned int *)0xcf011824)   /* receives the register number */
#define INDIRECT_DATA (*(volatile unsigned int *)0xcf011828)    /* the value is read from here */
#define INDIRECT_TARGET 0x76

/*
 * Read register reg of the group 0x76 through the three indirect registers 0xcf011820..0xcf011828, with page
 * selected in PAGE_SELECT. The old PAGE_SELECT and INDIRECT_INDEX values are put back afterwards.
 * Returns the low byte read. Its address is taken somewhere (no direct caller).
 */
unsigned char sys_read_paged_reg_76(unsigned char page, unsigned char reg)
{
    unsigned char saved_page = PAGE_SELECT;
    unsigned char saved_index = INDIRECT_INDEX;
    unsigned char value;

    PAGE_SELECT = page;
    INDIRECT_SELECT = INDIRECT_TARGET;
    INDIRECT_INDEX = reg;
    value = INDIRECT_DATA;
    INDIRECT_INDEX = saved_index;
    PAGE_SELECT = saved_page;
    return value;
}
