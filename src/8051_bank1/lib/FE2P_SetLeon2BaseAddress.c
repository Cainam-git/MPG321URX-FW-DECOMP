/* FE2P_SetLeon2BaseAddress  (FUN_CODE_d095)
 *
 * Store the flash window base address for the main processor and log it.
 *   base: flash window base
 * Name basis: proven - (original name printed: 'FE2P_SetLeon2BaseAddress %08lx')
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_d095 @ 0xd095 (55 B)  Byte-exact with OPTIMIZE(8,SPEED) LARGE.
 * LARGE model: the parameter lives at XDATA 0xA473 and is reloaded for each use; the printf argument block starts
 * at 0xA51A; printf is reached with a tail jump.
 */
extern unsigned long xdata flash_window_base[];
extern void lib_printf517(void *fmt, ...) large;   /* printf */

/*
 * Store the flash window base address (flash_window_base[0], the value that
 * flash_calc_window_room and flash_set_job_address start from) and print it.
 * Only caller: the code at 0x408D.
 */
void FE2P_SetLeon2BaseAddress(unsigned long base)
{
    flash_window_base[0] = base;
    lib_printf517((void code *)0xc4cd /* "FE2P_SetLeon2BaseAddress %08lx\r\n" */, base);
}
