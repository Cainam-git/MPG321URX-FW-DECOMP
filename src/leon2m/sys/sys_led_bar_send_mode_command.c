/* sys_led_bar_send_mode_command  (FUN_a00da9e4)
 *
 * Send the mode command with one digit to the LED light bar controller.
 * Name basis: derived - sends the 11 bytes "5b00;3000" + digit + carriage return over the serial link
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00da9e4 @ 0xa00da9e4-0xa00daa7c (38 words), flags -mcpu=v8 -O3 -g.
 * Source form: the halfword is updated through a pointer local set just before the update, after the buffer
 * stores (byte 0 is stored last).
 */
/* The halfword at +0x14 of the application state record. */
struct app_state_record_fields {
    unsigned char pad[0x14];
    unsigned short halfword_0x14;
};
extern struct app_state_record_fields app_state_record;
extern unsigned char sys_led_bar_tx_frame[11];
extern void uart_api_send_bytes(unsigned char port, unsigned short length, unsigned char *data);

/*
 * Send the 11 characters "5b00;3000" + digit + carriage return to the LED light bar (built in
 * sys_led_bar_tx_frame, sent with uart_api_send_bytes(2, ...)). The digit is the character '0' + n, with n
 * above 10 replaced by 1. Bit 15 of the application state halfword +0x14 is set as well. Called from
 * osd_check_panel_protect_prompt.
 */
void sys_led_bar_send_mode_command(unsigned char n)
{
    struct app_state_record_fields *state;

    if (n > 10)
        n = 1;
    sys_led_bar_tx_frame[1] = 'b';
    sys_led_bar_tx_frame[2] = '0';
    sys_led_bar_tx_frame[3] = '0';
    sys_led_bar_tx_frame[4] = ';';
    sys_led_bar_tx_frame[5] = '3';
    sys_led_bar_tx_frame[6] = '0';
    sys_led_bar_tx_frame[7] = '0';
    sys_led_bar_tx_frame[8] = '0';
    sys_led_bar_tx_frame[9] = n + '0';
    sys_led_bar_tx_frame[10] = '\r';
    sys_led_bar_tx_frame[0] = '5';
    state = &app_state_record;
    state->halfword_0x14 |= 0x8000;
    uart_api_send_bytes(2, 11, sys_led_bar_tx_frame);
}
