/* uart_cmd_parse_value  (FUN_a00bae38)
 *
 * Read the three ASCII digits of a received set command as a number.
 *   port: command port (2, 3 or 4)
 * Returns: value, or 0xFF when not digits
 * Note: Bytes 7..9 of the port's receive record; result 0..199.
 * Name basis: derived - callers are set handlers (navi keys, ...)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00bae38, flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on: each port arm loads the three bytes itself (the compiler merges the
 * port 2 and default arms and keeps the port 3 arm as a separate copy); the digits are range-tested as characters
 * before '0' is subtracted; the sum goes through an unsigned short local, which keeps the zero extension of the
 * last digit before the final add.
 */
extern unsigned char uart_cmd_rx_record_port2[], uart_cmd_rx_record_port3[], uart_cmd_rx_record[];

#define VALUE_HUNDREDS_OFFSET 7     /* receive record bytes 7..9: the three value characters of a set frame */
#define VALUE_TENS_OFFSET     8
#define VALUE_UNITS_DIGIT     9
#define BAD_VALUE             0xff  /* result when the characters are not a number from 000 to 199 */

/* Read the three value characters of the set frame received on `port` as a number 0..199. The hundreds
   character must be '0' or '1', the others '0'..'9'; otherwise the result is BAD_VALUE. Port 2 and port 3 have
   their own record; every other port uses uart_cmd_rx_record. */
unsigned char uart_cmd_parse_value(unsigned char port)
{
    unsigned char hundreds, tens, units;
    unsigned short number;

    if (port == 2) {
        hundreds = uart_cmd_rx_record_port2[VALUE_HUNDREDS_OFFSET];
        tens = uart_cmd_rx_record_port2[VALUE_TENS_OFFSET];
        units = uart_cmd_rx_record_port2[VALUE_UNITS_DIGIT];
    } else if (port == 3) {
        hundreds = uart_cmd_rx_record_port3[VALUE_HUNDREDS_OFFSET];
        tens = uart_cmd_rx_record_port3[VALUE_TENS_OFFSET];
        units = uart_cmd_rx_record_port3[VALUE_UNITS_DIGIT];
    } else {
        hundreds = uart_cmd_rx_record[VALUE_HUNDREDS_OFFSET];
        tens = uart_cmd_rx_record[VALUE_TENS_OFFSET];
        units = uart_cmd_rx_record[VALUE_UNITS_DIGIT];
    }
    if (hundreds < '0' || hundreds > '1')
        return BAD_VALUE;
    if (tens < '0' || tens > '9')
        return BAD_VALUE;
    if (units < '0' || units > '9')
        return BAD_VALUE;
    hundreds -= '0';
    tens -= '0';
    units -= '0';
    number = hundreds * 100 + tens * 10 + units;
    return number;
}
