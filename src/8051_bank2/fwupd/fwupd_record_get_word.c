/* fwupd_record_get_word  (FUN_CODE_d64c)
 *
 * Return a 32-bit word of the record image, low byte first.
 *   offset: byte offset
 * Returns: word
 * Name basis: derived - image 0x06F7 (module of the record refresh); inverse of fwupd_record_set_word
 *
 * Matching notes
 * --------------
 * Built with OPTIMIZE(8,SPEED) LARGE. LARGE parameter offset (0x08F6, stored and read again per byte). One
 * expression (each step ?C?LSHL by 8, then OR). Own segment, not a member of the 8437 module's common-entry blocks.
 */
extern unsigned char xdata fwupd_record_buffer[32];

/* fwupd_record_get_word: return the 32-bit word at byte offset of fwupd_record_buffer (the 32-byte record image),
 * low byte first. fwupd_record_set_word stores one the same way. Caller: fwupd_refresh_flash_records. */
unsigned long fwupd_record_get_word(unsigned char offset)
{
    return ((((unsigned long)fwupd_record_buffer[offset + 3] << 8 | fwupd_record_buffer[offset + 2]) << 8
             | fwupd_record_buffer[offset + 1]) << 8) | fwupd_record_buffer[offset];
}
