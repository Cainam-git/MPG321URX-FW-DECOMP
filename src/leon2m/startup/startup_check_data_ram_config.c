/* startup_check_data_ram_config  (FUN_a00de70c)
 *
 * Check that the data memory window of the processor matches the program's layout.
 * Name basis: proven - prints 'DataRam register config : 0x%08X, ld config : 0x%08X' when the core registers
 *   do not match; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00de70c @ 0xa00de70c-0xa00de7c4 (46 words).
 * Source form: the compare is written pointer to pointer, (char *)bottom != link_address (an integer compare
 * swaps the cmp operands). The data start is a linker symbol (sethi + 'or %lo' = 0), not a constant: it is
 * declared as the array sys_fake_sleep_led_flag, which starts at 0xA8024000.
 */

#define DATARAM_REG_ZEROS    0x9f020204     /* bits 0..23: every bit that is 0 counts one block */
#define DATARAM_REG_ONES     0x9f020200     /* bits 4..27: every bit that is 1 counts one block */
#define DATARAM_TOP          0xa803c000     /* the data RAM bottom is this minus 4 KiB per counted block */
#define DATARAM_BLOCK_SHIFT  12             /* 4 KiB */

extern unsigned int reg_read32(unsigned int addr);
extern int dbg_printf(const char *fmt, ...);
extern char sys_fake_sleep_led_flag[];      /* first byte of the initialised data: the address the linker gave the data RAM */

/*
 * Compare the size of the data RAM window, as the two core registers 0x9F020204 and 0x9F020200 give it, with
 * the address where the linker put the initialised data. When they differ, print both values and stay in an
 * endless loop (no timeout, no reset).
 *
 * The window bottom is 0xA803C000 minus 4 KiB for each zero bit in bits 0..23 of 0x9F020204 and each one bit
 * in bits 4..27 of 0x9F020200.
 *
 * Nothing calls this routine; startup_init_core contains the same check and is the one that runs.
 */
void startup_check_data_ram_config(void)
{
    unsigned int register_value;
    unsigned char bit;
    unsigned char blocks;
    unsigned int bottom;
    char *link_address = sys_fake_sleep_led_flag;

    blocks = 0;
    register_value = reg_read32(DATARAM_REG_ZEROS);
    for (bit = 0; bit < 24; bit++)
        if (!((register_value >> bit) & 1))
            blocks++;
    register_value = reg_read32(DATARAM_REG_ONES);
    for (bit = 27; bit > 3; bit--)
        if ((register_value >> bit) & 1)
            blocks++;
    bottom = DATARAM_TOP - (blocks << DATARAM_BLOCK_SHIFT);
    if ((char *)bottom != link_address) {
        dbg_printf("\033[1;31mDataRam register config : 0x%08X, ld config : 0x%08X\r\n\033[m", bottom, link_address);
        for (;;)
            ;
    }
}
