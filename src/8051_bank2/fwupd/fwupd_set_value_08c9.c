/* fwupd_set_value_08c9  (FUN_CODE_cfa5)
 *
 * Store a 32-bit value built from four bytes at XDATA 0x08C9.
 *   byte_31_24: bits 31..24
 *   byte_23_16: bits 23..16
 *   byte_15_8: bits 15..8
 *   byte_7_0: bits 7..0
 * Name basis: descriptive - code: 0x08C9 = a:b:c:d; caller fwupd_run_mailbox_command, command 0x31, with
 *   mailbox bytes 0xF19C..0xF19F
 *
 * Matching notes
 * --------------
 * Built with OPTIMIZE(8,SPEED) LARGE. LARGE parameter block at XDATA 0x08EE: byte_23_16 and byte_15_8 arrive in R5 / R3
 * and are stored at 0x08EF / 0x08F0 at entry; the fourth parameter does not fit in registers and is passed in its
 * slot 0x08F1. Each step is its own statement (?C?LSHL by 8, ?C?LSTXDATA store).
 */
extern unsigned long xdata usb_mem_base;

/* fwupd_set_value_08c9: set usb_mem_base (XDATA 0x08C9) to the four bytes byte_31_24 .. byte_7_0, most
 * significant first. usb_select_controller computes each port's memory from this base.
 * Caller: fwupd_run_mailbox_command, command MBOX_CMD_SET_MEM_BASE (0x31), with mailbox bytes 0xF19C..0xF19F. */
void fwupd_set_value_08c9(unsigned char byte_31_24, unsigned char byte_23_16, unsigned char byte_15_8, unsigned char byte_7_0)
{
    usb_mem_base = byte_31_24;
    usb_mem_base = (usb_mem_base << 8) + byte_23_16;
    usb_mem_base = (usb_mem_base << 8) + byte_15_8;
    usb_mem_base = (usb_mem_base << 8) + byte_7_0;
}
