/* lib_copy_to_work_array  (FUN_CODE_e0c9)
 *
 * Copy bytes into the work array at a given offset.
 * Name basis: descriptive - XDATA array at 0x064A
 *
 * Matching notes
 * --------------
 * 8051_bank2 FUN_CODE_e0c9 @ 0xe0c9 (60 B, 0xE0C9..0xE105), OPTIMIZE(8,SPEED) LARGE.
 * Source form: the index is cast to unsigned char; without the cast Keil adds with carry and keeps offset and i in
 * XDATA.
 */

/* The eight work bytes at XDATA 0x064A. fwupd_write_dualfw_tag copies all eight into the DUALFW tag block (in the
 * update modes without bit 2);
 * fwupd_svc_set_control_bit uses byte 0 and byte 5 as the high and low byte of a register number, byte 6 as the bit
 * mask and byte 7 to choose between setting and clearing those bits. */
extern unsigned char xdata fwupd_mailbox_work_bytes[];

/* Copy count bytes from src to the work bytes, starting at work byte offset.
 * Only caller: fwupd_run_mailbox_command. Mailbox command 0x41 copies five bytes from the mailbox (0xF19B..0xF19F)
 * to work bytes 0..4, command 0x42 copies three (0xF19B..0xF19D) to work bytes 5..7. */
void lib_copy_to_work_array(unsigned char offset, unsigned char *src, unsigned char count)
{
    unsigned char i;
    for (i = 0; i < count; i++) fwupd_mailbox_work_bytes[(unsigned char)(offset + i)] = src[i];
}
