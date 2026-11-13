/* uart_cmd_set_power_flag  (FUN_a00c0db4)
 *
 * Set the power request flag when the given state is 0 or 4.
 *   power_value: state value
 * Note: Byte 0xA802B09B; no reader of it was found.
 * Name basis: descriptive - same flag as uart_cmd_set_power_state
 *
 * Matching notes
 * --------------
 * Flags -mcpu=v8 -O2 -g (section default). Source form: a switch with cases 0 and 4. Nothing in the image calls
 * this routine.
 */
extern unsigned char uart_cmd_power_request;

/*
 * Set uart_cmd_power_request to 1 when power_value is 0 or 4; any other value changes nothing.
 * uart_cmd_set_power_state sets the same flag for the values 0 and 1 of the power state command. Nothing in the
 * image reads the flag.
 */
void uart_cmd_set_power_flag(unsigned char power_value)
{
    switch (power_value) {
    case 0:
    case 4:
        uart_cmd_power_request = 1;
        break;
    }
}
