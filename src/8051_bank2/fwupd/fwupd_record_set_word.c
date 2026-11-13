/* fwupd_record_set_word  (FUN_CODE_d8c4)
 *
 * Store a 32-bit word into the record image, low byte first.
 *   offset: byte offset
 *   value: word
 * Name basis: derived - image 0x06F7; inverse of fwupd_record_get_word
 *
 * Matching notes
 * --------------
 * Built with OPTIMIZE(8,SPEED) LARGE. offset stays in R3; value is read from its LARGE parameter home
 * 0x08F7..0x08FA (the caller stores it there). The shifts by 8 / 16 / 24 are ?C?ULSHR. Own segment, not one of
 * the common-entry members of the fwupd_refresh_flash_records module.
 */
extern unsigned char xdata fwupd_record_buffer[32];

/* fwupd_record_set_word: store value at byte offset of fwupd_record_buffer (the 32-byte record image), low byte
 * first; fwupd_record_get_word reads it back the same way. Caller: fwupd_refresh_flash_records. */
void fwupd_record_set_word(unsigned char offset, unsigned long value)
{
    fwupd_record_buffer[offset] = value;
    fwupd_record_buffer[offset + 1] = value >> 8;
    fwupd_record_buffer[offset + 2] = value >> 16;
    fwupd_record_buffer[offset + 3] = value >> 24;
}
