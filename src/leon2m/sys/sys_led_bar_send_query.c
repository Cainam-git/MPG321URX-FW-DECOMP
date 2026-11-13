/* sys_led_bar_send_query  (FUN_a00daa7c)
 *
 * Send the fixed query command to the LED light bar controller.
 * Name basis: derived - text command '5800;40' over the serial link
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00daa7c @ 0xa00daa7c-0xa00daad0 (21 words), flags -mcpu=v8 -O3 -g.
 * Source form: the stores are in ascending index order in the source (scheduling gives the firmware order
 * 0, 1, 4, 5, 6, 7, 2, 3). The buffer address stays in %o2 into the final call, which is a tail call;
 * uart_api_send_bytes forwards %o2.
 */
extern unsigned char sys_led_bar_tx_frame[8];
extern void uart_api_send_bytes(unsigned char port, unsigned short length, unsigned char *data);

/*
 * Send the 8 characters "5800;40" + carriage return to the LED light bar (built in sys_led_bar_tx_frame and
 * sent with uart_api_send_bytes(2, 8, ...)). Called from osd_run_periodic_task and others.
 */
void sys_led_bar_send_query(void)
{
    sys_led_bar_tx_frame[0] = 0x35;     /* '5' */
    sys_led_bar_tx_frame[1] = 0x38;     /* '8' */
    sys_led_bar_tx_frame[2] = 0x30;     /* '0' */
    sys_led_bar_tx_frame[3] = 0x30;     /* '0' */
    sys_led_bar_tx_frame[4] = 0x3b;     /* ';' */
    sys_led_bar_tx_frame[5] = 0x34;     /* '4' */
    sys_led_bar_tx_frame[6] = 0x30;     /* '0' */
    sys_led_bar_tx_frame[7] = 0xd;      /* carriage return */
    uart_api_send_bytes(2, 8, sys_led_bar_tx_frame);
}
