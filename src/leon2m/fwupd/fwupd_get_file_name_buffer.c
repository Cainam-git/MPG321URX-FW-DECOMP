/* fwupd_get_file_name_buffer  (FUN_a0124174)
 *
 * Return the buffer that holds the file name read from the update port.
 * Returns: buffer
 * Name basis: derived - address 0xA802D850
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0124174 @ 0xa0124174, flags -mcpu=v8 -O2 -g (the section default).
 * Source form: returns the constant address as an unsigned int.
 */
/*
 * Return the address of the buffer that holds the file name read from the update port (fwupd_file_name,
 * 7 rows of 6 bytes). Callers: fwupd_verify_file_checksum, fwupd_find_and_verify_file,
 * fwupd_find_file.
 */
unsigned int fwupd_get_file_name_buffer(void)
{
  return 0xa802d850;
}
