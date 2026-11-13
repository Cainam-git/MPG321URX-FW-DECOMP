/* flash_calc_window_room  (FUN_CODE_cd8c)
 *
 * Return the room left in the flash window after the extension offset.
 * Returns: 32-bit size
 * Name basis: descriptive - 0xA70D[1] - 0xA70D[0] - 0xA717; command 0x14 (result not used)
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_cd8c @ 0xcd8c  Byte-exact with OPTIMIZE(8,SPEED) (also level 7).
 * Source form: flash_window_base[0] and [1] (0xA70D, 0xA711) are read as one run (INC DPTR from 0xA710 to
 * 0xA711), so they are declared as one array of two longs.
 */
extern unsigned long xdata flash_window_base[];
extern unsigned long xdata flash_window_extension;

/*
 * Return flash_window_base[1] - flash_window_base[0] - flash_window_extension,
 * the reverse of the sum that flash_set_job_address stores. Only caller: the
 * code at 0x242B.
 */
unsigned long flash_calc_window_room(void)
{
    return flash_window_base[1] - flash_window_base[0] - flash_window_extension;
}
