/* uart_cmd_set_low_blue_light  (FUN_a00c5c18)
 *
 * Set the Low Blue Light switch from a PC tool command and acknowledge it.
 *   port: command port (2, 3 or 4)
 * Returns: 0, or 0xFF when refused
 * Note: Command 5b00310; returns 0xFF for a bad value (the task then replies 5600-), else 0 after '5600+'.
 * Name basis: proven - set frame 5b00310; bit 4 of +0x11C (osd_toggle_low_blue_light)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00c5c18 @ 0xa00c5c18-0xa00c5e40 (138 words), flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on:
 *  - the three port helpers are defined in this file, so GCC inlines them at -O3;
 *  - the value is an unsigned short tested as an unsigned char;
 *  - Low Blue Light is a 1-bit bit-field of the professional flags word, stored from an unsigned char and read
 *    back from the bit-field for the test.
 */

#define UART_CMD_REFUSED          0xff      /* result: the dispatcher answers "5600-" */
#define UART_CMD_OK_REPLY_LENGTH  6         /* "5600+\r" */
#define VALUE_CHAR_BASE           0x30      /* '0': the value byte of the frame is the value plus 0x30 */
#define SWITCH_MAX                1         /* an on/off setting: 0 off, 1 on */

extern unsigned char uart_cmd_rx_state_port2, uart_cmd_rx_state_port3, uart_cmd_rx_count;
extern unsigned char uart_cmd_rx_record_port2[], uart_cmd_rx_record_port3[], uart_cmd_rx_record[];
extern unsigned char uart_cmd_tx_frame[], uart_cmd_tx_frame_port3[], uart_cmd_tx_frame_port2[];
/* The two fields of the user settings record used here. */
struct user_settings_record {
    unsigned char pad0[0x11c];
    struct {                                    /* +0x11C: professional flags */
        unsigned int bits_31_5 : 27,
                     low_blue_light : 1,        /*   bit 4: Low Blue Light */
                     bits_3_0 : 4;
    } professional_flags;
    unsigned char pad120[0x178 - 0x120];
    unsigned char byte_0x178;                   /* +0x178 */
};
extern struct user_settings_record user_settings;
extern void pq_user_apply_color_settings(void);
extern void sys_user_save_mode_slot(void);
extern void uart_api_send_bytes(unsigned char, unsigned short, unsigned char *);

/* Put the acknowledge "5600+\r" into the reply frame of the port. */
void uart_cmd_build_ok_reply(unsigned char port)
{
    if (port == 2) {
        uart_cmd_tx_frame_port2[0] = '5';
        uart_cmd_tx_frame_port2[1] = '6';
        uart_cmd_tx_frame_port2[2] = '0';
        uart_cmd_tx_frame_port2[3] = '0';
        uart_cmd_tx_frame_port2[4] = '+';
        uart_cmd_tx_frame_port2[5] = '\r';
    } else if (port == 3) {
        uart_cmd_tx_frame_port3[0] = '5';
        uart_cmd_tx_frame_port3[1] = '6';
        uart_cmd_tx_frame_port3[2] = '0';
        uart_cmd_tx_frame_port3[3] = '0';
        uart_cmd_tx_frame_port3[4] = '+';
        uart_cmd_tx_frame_port3[5] = '\r';
    } else {
        uart_cmd_tx_frame[0] = '5';
        uart_cmd_tx_frame[1] = '6';
        uart_cmd_tx_frame[2] = '0';
        uart_cmd_tx_frame[3] = '0';
        uart_cmd_tx_frame[4] = '+';
        uart_cmd_tx_frame[5] = '\r';
    }
}

/* Make the port ready for the next command: clear its receive state byte and bytes 0, 1, 7, 10 and 0x19 of its
   receive record. */
void uart_cmd_clear_rx(unsigned char port)
{
    if (port == 2) {
        uart_cmd_rx_state_port2 = 0;
        uart_cmd_rx_record_port2[0] = 0;
        uart_cmd_rx_record_port2[1] = 0;
        uart_cmd_rx_record_port2[7] = 0;
        uart_cmd_rx_record_port2[10] = 0;
        uart_cmd_rx_record_port2[0x19] = 0;
    } else if (port == 3) {
        uart_cmd_rx_state_port3 = 0;
        uart_cmd_rx_record_port3[0] = 0;
        uart_cmd_rx_record_port3[1] = 0;
        uart_cmd_rx_record_port3[7] = 0;
        uart_cmd_rx_record_port3[10] = 0;
        uart_cmd_rx_record_port3[0x19] = 0;
    } else {
        uart_cmd_rx_count = 0;
        uart_cmd_rx_record[0] = 0;
        uart_cmd_rx_record[1] = 0;
        uart_cmd_rx_record[7] = 0;
        uart_cmd_rx_record[10] = 0;
        uart_cmd_rx_record[0x19] = 0;
    }
}

/* Send the first `length` bytes of the port's reply frame through the 8051. */
void uart_cmd_send_tx_buffer(unsigned char port, unsigned char length)
{
    if (port == 2)
        uart_api_send_bytes(2, length, uart_cmd_tx_frame_port2);
    else if (port == 3)
        uart_api_send_bytes(3, length, uart_cmd_tx_frame_port3);
    else
        uart_api_send_bytes(port, length, uart_cmd_tx_frame);
}

/*
 * Set row 0x3D (61, row id 00310) of uart_cmd_dispatch_set: switch Low Blue Light on or off from a frame of MSI's
 * PC tool and apply it.
 *
 *   port  the command port the frame came in on (2, 3 or another); it selects the receive record and the reply
 *         frame
 *
 * Returns 0 after the "5600+" reply has been sent, or UART_CMD_REFUSED (0xFF) for a value above 1; then nothing
 * has changed and the dispatcher answers "5600-".
 *
 * Phases:
 *   1. Read the switch from frame byte 9 (0 or 1 plus 0x30).
 *   2. Store it in bit 4 of the professional flags; switching it on also clears settings byte +0x178.
 *   3. Apply the colour settings (pq_user_apply_color_settings) and copy the current picture settings into the
 *      slot of a picture mode (sys_user_save_mode_slot). No settings save is requested here.
 *   4. Reply "5600+\r".
 */
int uart_cmd_set_low_blue_light(unsigned char port)
{
    unsigned char value_char;
    unsigned short value;

    /* Phase 1. */
    if (port == 2)
        value_char = uart_cmd_rx_record_port2[9];
    else if (port == 3)
        value_char = uart_cmd_rx_record_port3[9];
    else
        value_char = uart_cmd_rx_record[9];
    value = value_char - VALUE_CHAR_BASE;
    if ((unsigned char)value > SWITCH_MAX)
        return UART_CMD_REFUSED;

    /* Phase 2. */
    user_settings.professional_flags.low_blue_light = (unsigned char)value;
    if (user_settings.professional_flags.low_blue_light)
        user_settings.byte_0x178 = 0;

    /* Phase 3. */
    pq_user_apply_color_settings();
    sys_user_save_mode_slot();

    /* Phase 4. */
    uart_cmd_build_ok_reply(port);
    uart_cmd_clear_rx(port);
    uart_cmd_send_tx_buffer(port, UART_CMD_OK_REPLY_LENGTH);
    return 0;
}
