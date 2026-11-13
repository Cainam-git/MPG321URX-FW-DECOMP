/* uart_cmd_put_color_gain_digits  (FUN_a00badc0)
 *
 * Write the red, green and blue gain bytes as digits into the reply frame.
 * Note: Unused standalone copy (each byte + '0').
 * Name basis: descriptive - settings bytes +0x12..+0x14 (custom gains) into bytes 7..9 of 0xA802D078
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00badc0, flags -mcpu=v8 -O3 -g.
 */
/* Only the bytes of the user settings record this routine reads. */
struct user_settings_view {
    unsigned char pad[0x12];
    unsigned char red_gain;             /* +0x12: custom gains (see uart_cmd_get_color_gains) */
    unsigned char green_gain;           /* +0x13 */
    unsigned char blue_gain;            /* +0x14 */
};
extern struct user_settings_view user_settings;
extern unsigned char uart_cmd_tx_frame[];

/* Put the custom red, green and blue gains of the user settings, each plus '0', into reply frame bytes 7, 8 and
   9. Not called; uart_cmd_get_color_gains does the same and sends the reply. */
void uart_cmd_put_color_gain_digits(void)
{
    uart_cmd_tx_frame[7] = user_settings.red_gain + '0';
    uart_cmd_tx_frame[8] = user_settings.green_gain + '0';
    uart_cmd_tx_frame[9] = user_settings.blue_gain + '0';
}
