/* uart_cmd_set_navi_key_up  (FUN_a00c1704)
 *
 * Set the Navi Key up function from a PC tool command and acknowledge it.
 *   port: command port (2, 3 or 4)
 * Returns: 0, or 0xFF when refused
 * Note: Command 5b00900. Nothing calls this copy: uart_cmd_dispatch_set carries the same code inside itself
 *   for row 0x41. Returns 0xFF for a bad value, else 0 after '5600+'.
 * Name basis: proven - set frame 5b00900; settings byte +0x18A
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00c1704 @ 0xa00c1704-0xa00c17e8 (57 words), flags -mcpu=v8 -O3 -g.
 * Source form: uart_cmd_parse_value is defined in this file and inlined by GCC at -O3; the other helpers are
 * called.
 */

#define UART_CMD_REFUSED          0xff      /* result: the dispatcher answers "5600-" */
#define UART_CMD_OK_REPLY_LENGTH  6         /* "5600+\r" */
#define BAD_VALUE                 0xff      /* uart_cmd_parse_value: the frame holds no valid number */
#define VALUE_HUNDREDS_OFFSET     7         /* bytes 7..9 of a set frame: the value as three decimal digits */
#define VALUE_TENS_OFFSET         8
#define VALUE_CHAR_OFFSET         9
#define NAVI_KEY_FUNCTION_MAX     11        /* Navi Key functions 0 (off) .. 11 (KVM) */

extern unsigned char uart_cmd_rx_record_port2[], uart_cmd_rx_record_port3[], uart_cmd_rx_record[];
extern unsigned char user_settings_navi_key_up;
extern void osd_mark_settings_changed_copy(void);
extern void uart_cmd_build_ok_reply(unsigned char);
extern void uart_cmd_clear_rx(unsigned char);
extern void uart_cmd_send_tx_buffer(unsigned char, unsigned char);

/* Read bytes 7..9 of the port's receive record as a three-digit decimal value 0..199; BAD_VALUE when a character
 * does not fit (the hundreds digit may only be '0' or '1'). */
unsigned char uart_cmd_parse_value(unsigned char port)
{
    unsigned char hundreds, tens, ones;
    unsigned short value;

    if (port == 2) {
        hundreds = uart_cmd_rx_record_port2[VALUE_HUNDREDS_OFFSET];
        tens = uart_cmd_rx_record_port2[VALUE_TENS_OFFSET];
        ones = uart_cmd_rx_record_port2[VALUE_CHAR_OFFSET];
    } else if (port == 3) {
        hundreds = uart_cmd_rx_record_port3[VALUE_HUNDREDS_OFFSET];
        tens = uart_cmd_rx_record_port3[VALUE_TENS_OFFSET];
        ones = uart_cmd_rx_record_port3[VALUE_CHAR_OFFSET];
    } else {
        hundreds = uart_cmd_rx_record[VALUE_HUNDREDS_OFFSET];
        tens = uart_cmd_rx_record[VALUE_TENS_OFFSET];
        ones = uart_cmd_rx_record[VALUE_CHAR_OFFSET];
    }
    if (hundreds < '0' || hundreds > '1')
        return BAD_VALUE;
    if (tens < '0' || tens > '9')
        return BAD_VALUE;
    if (ones < '0' || ones > '9')
        return BAD_VALUE;
    hundreds -= '0';
    tens -= '0';
    ones -= '0';
    value = hundreds * 100 + tens * 10 + ones;
    return value;
}

/*
 * Set the Navi Key up function (user settings byte +0x18A) from the set frame "5b00900" + three digits, a value
 * 0..NAVI_KEY_FUNCTION_MAX.
 *
 *   port  the command port the frame came in on (2, 3 or another); it selects the receive record and the reply
 *         frame
 *
 * Returns 0 after the "5600+" reply has been sent and a settings save has been requested, or UART_CMD_REFUSED
 * with nothing changed when the value is above 11 or not a number (BAD_VALUE is above 11 as well).
 *
 * Nothing in the firmware calls this routine: uart_cmd_dispatch_set has the same code inline for its row 0x41.
 */
int uart_cmd_set_navi_key_up(unsigned char port)
{
    unsigned char function;

    function = uart_cmd_parse_value(port);
    if (function > NAVI_KEY_FUNCTION_MAX)
        return UART_CMD_REFUSED;
    user_settings_navi_key_up = function;
    osd_mark_settings_changed_copy();
    uart_cmd_build_ok_reply(port);
    uart_cmd_clear_rx(port);
    uart_cmd_send_tx_buffer(port, UART_CMD_OK_REPLY_LENGTH);
    return 0;
}
