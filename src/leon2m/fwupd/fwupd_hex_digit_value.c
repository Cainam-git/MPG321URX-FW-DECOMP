/* fwupd_hex_digit_value  (FUN_a0123c4c)
 *
 * Convert a hexadecimal digit character to its value.
 * Returns: value or 0xAA
 * Name basis: proven - '0'..'9' and 'A'..'F' to 0..15, else 0xAA
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0123c4c @ 0xa0123c4c-0xa0123c80 (13 words), flags -mcpu=v8 -O2 -g (the section default).
 * Source form: the range tests are on the unsigned char differences (the firmware masks both with 'and 0xff'
 * before comparing with 9 and 5), and the routine is written with early returns; a single result variable gives
 * the inverted inner branch.
 */
#define HEX_DIGIT_INVALID 0xaa          /* returned when the character is not 0-9 or A-F */

/*
 * Convert one hexadecimal digit character to its value.
 *   ch: the character; '0'..'9' and upper case 'A'..'F' are accepted (lower case is not).
 * Returns 0..15, or HEX_DIGIT_INVALID. Callers: fwupd_parse_name_checksum, fwupd_verify_file_checksum.
 */
unsigned char fwupd_hex_digit_value(int ch)
{
    if ((unsigned char)(ch - '0') <= 9)
        return ch - '0';
    if ((unsigned char)(ch - 'A') <= 5)
        return ch - 0x37;               /* 'A' - 10 */
    return HEX_DIGIT_INVALID;
}
