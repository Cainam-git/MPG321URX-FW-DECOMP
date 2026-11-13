/* fwupd_parse_name_checksum  (FUN_a0147d0c)
 *
 * Read the four checksum digits that end a file name.
 * Returns: checksum from the name
 * Name basis: derived - digits at positions n-8..n-5 combined into a 16-bit value; unused
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0147d0c @ 0xa0147d0c-0xa0147d70 (25 words), flags -mcpu=v8 -O3 -g.
 */
extern unsigned char fwupd_hex_digit_value(int ch);

/*
 * Read the four hexadecimal digits that end a file name and return them as a 16-bit number.
 *   name    the file name
 *   length  its length in characters
 * The digits are the characters at length - 8 to length - 5, first digit in bits 12 to 15; the last four
 * characters of the name are not read. A character that is not a hexadecimal digit gives 0xAA
 * (fwupd_hex_digit_value) for that position. No direct caller was found.
 */
unsigned short fwupd_parse_name_checksum(unsigned char *name, unsigned char length)
{
    return (fwupd_hex_digit_value(name[length - 8]) << 12) | (fwupd_hex_digit_value(name[length - 7]) << 8) |
           (fwupd_hex_digit_value(name[length - 6]) << 4) | fwupd_hex_digit_value(name[length - 5]);
}
