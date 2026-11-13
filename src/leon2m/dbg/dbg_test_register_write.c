/* dbg_test_register_write  (FUN_a011553c)
 *
 * Write a test value to register 0xCF022800 and print it before and after.
 * Name basis: descriptive - unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a011553c, flags -mcpu=v8 -O2 -g.
 * The second print is a tail call with the same format string as the first (the firmware builds both from one
 * shared address), and the page register is written a second time right after the first print. volatile only on
 * the hardware registers (each access is real).
 */
extern int dbg_printf(const char *fmt, ...);

/* Register 0 of memory interface unit 0 and the page register of that unit (page 0 selects registers 0..0xFF). */
#define REG_cf022800 (*(volatile unsigned int *)0xcf022800)
#define REG_cf022bf8 (*(volatile unsigned int *)0xcf022bf8)

/*
 * Select page 0 of memory interface unit 0, print the low byte of register 0 ("Value = 0x.."), write 0xAA to it
 * and print it again. No routine calls it.
 */
void dbg_test_register_write(void)
{
    REG_cf022bf8 = 0;
    dbg_printf("\nValue = 0x%2X", REG_cf022800 & 0xff);
    REG_cf022bf8 = 0;
    REG_cf022800 = 0xaa;
    REG_cf022bf8 = 0;
    dbg_printf("\nValue = 0x%2X", REG_cf022800 & 0xff);
}
