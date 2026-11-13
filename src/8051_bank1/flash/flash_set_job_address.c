/* flash_set_job_address  (FUN_CODE_c965)
 *
 * Compute the flash address of the next flash job from the window base.
 *   offset: 16-bit offset
 * Name basis: derived - 0xA711 = 0xA70D + 0xA717 (CMD_FE2P_SETEXTEND) + w; command 0x14 ('Update FE2P Addr');
 *   used by commands 0x11..0x13
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_c965 @ 0xc965 (75 B)  Byte-exact with OPTIMIZE(8,SPEED) LARGE.
 * LARGE: 'offset' is stored in its XDATA parameter slot 0xA4B3 at entry and read back for the last addition; the
 * sum is written with a tail jump to ?C?LSTXDATA.
 */
extern unsigned long xdata flash_window_base[];
extern unsigned long xdata flash_window_extension;

/*
 * Set the flash job address (flash_window_base[1]) to the window base
 * (flash_window_base[0]) + the extension + a 16-bit offset.
 * flash_calc_window_room computes the reverse difference. Only caller:
 * command 0x14 of the command switch, offset = (byte 2 << 8) + byte 3.
 */
void flash_set_job_address(unsigned int offset)
{
    flash_window_base[1] = flash_window_base[0] + flash_window_extension + offset;
}
