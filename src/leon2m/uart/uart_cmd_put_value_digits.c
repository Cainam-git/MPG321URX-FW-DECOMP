/* uart_cmd_put_value_digits  (FUN_a00bad4c)
 *
 * Write a value as three ASCII decimal digits into the reply frame.
 *   value: value 0..255
 * Note: Unused standalone copy; bytes 7..9 of 0xA802D078.
 * Name basis: derived - same digit code as the get replies
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00bad4c, flags -mcpu=v8 -O3 -g.
 */
extern unsigned char uart_cmd_tx_frame[];

#define VALUE_HUNDREDS_OFFSET 7     /* reply frame bytes 7..9: the three value characters */
#define VALUE_TENS_OFFSET     8
#define VALUE_UNITS_DIGIT     9
#define VALUE_CHAR_BASE       0x30  /* '0' */

/* Write `value` (0..255) as three ASCII decimal digits into bytes 7..9 of the shared reply frame. Not called;
   the get replies store their digits themselves. */
void uart_cmd_put_value_digits(unsigned char value)
{
    unsigned char hundreds, tens;

    hundreds = value / 100;
    value -= hundreds * 100;
    tens = value / 10;
    value -= tens * 10;
    uart_cmd_tx_frame[VALUE_HUNDREDS_OFFSET] = hundreds + VALUE_CHAR_BASE;
    uart_cmd_tx_frame[VALUE_TENS_OFFSET] = tens + VALUE_CHAR_BASE;
    uart_cmd_tx_frame[VALUE_UNITS_DIGIT] = value + VALUE_CHAR_BASE;
}
