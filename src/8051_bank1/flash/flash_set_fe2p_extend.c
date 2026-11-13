/* flash_set_fe2p_extend  (FUN_CODE_dee8)
 *
 * Store the FE2P extended address sent by the main processor.
 *   extension: extended address
 * Name basis: derived - mailbox command 0x26, printed 'CMD_FE2P_SETEXTEND : %02X%02X%02X'; long 0xA717
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_dee8 @ 0xdee8  OPTIMIZE(8,SPEED)
 * The 32-bit value is already in R4..R7: 'MOV DPTR,#0xA717' and a tail jump to the library store ?C?LSTXDATA
 * (lib_c_lstxdata); level 8 gives the tail jump.
 */
#define FLASH_WINDOW_EXTENSION 0xa717   /* flash_window_extension, an unsigned long */

/*
 * Store the extension that flash job addresses add to the window base (flash_window_extension at 0xA717).
 * extension: 24-bit value. Only caller: ipc_run_command, mailbox command 0x26 (IPC_8051_CMD_FLASH_EXTEND), which
 * prints "CMD_FE2P_SETEXTEND : %02X%02X%02X" and passes (arg1 << 16) | (arg2 << 8) | arg3. flash_set_job_address
 * adds it, flash_calc_window_room subtracts it again.
 */
void flash_set_fe2p_extend(unsigned long extension) {
    *(unsigned long xdata *)FLASH_WINDOW_EXTENSION = extension;
}
