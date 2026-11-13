/* uart_cmd_set_auto_level  (FUN_a00c1adc)
 *
 * Set the automatic level setting from a PC tool command and acknowledge it.
 *   port: command port (2, 3 or 4)
 * Returns: 0, or 0xFF when refused
 * Note: Command 5b00240; returns 0xFF for a bad value (the task then replies 5600-), else 0 after '5600+'.
 * Name basis: derived - set frame 5b00240; bit 31 of +0x11C, applied by sys_user_apply_auto_level
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00c1adc @ 0xa00c1adc-0xa00c1d54 (158 words), flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on:
 *  - the three port helpers are defined in this file, so GCC inlines them at -O3 (as in uart_cmd_set_transparency);
 *  - value is an unsigned short, compared and stored through (unsigned char) casts;
 *  - the automatic level bit is a 1-bit bit-field of the word at +0x11C.
 */

#define UART_CMD_REFUSED          0xff      /* result: the dispatcher answers "5600-" */
#define UART_CMD_OK_REPLY_LENGTH  6         /* "5600+\r" */
#define VALUE_CHAR_BASE           0x30      /* '0': the value byte of the frame is the value plus 0x30 */

extern unsigned char uart_cmd_rx_state_port2, uart_cmd_rx_state_port3, uart_cmd_rx_count;
extern unsigned char uart_cmd_rx_record_port2[], uart_cmd_rx_record_port3[], uart_cmd_rx_record[];
extern unsigned char uart_cmd_tx_frame[], uart_cmd_tx_frame_port3[], uart_cmd_tx_frame_port2[];

/* The fields of the user settings record (user_settings, 0xA802D290) used here. */
struct user_settings_record {
    unsigned char pad000[0xb0];
    unsigned int blur_free_mode;                /* +0xB0: the blur reduction mode */
    unsigned char pad0b4[0x11c - 0xb4];
    unsigned int auto_level : 1,                /* +0x11C bit 31: automatic level (professional flags) */
                 professional_bits_30_0 : 31;
};
extern struct user_settings_record user_settings;
extern void sys_user_clear_second_picture_request(void);
extern void sys_user_apply_auto_level(void);
extern unsigned char gpio_is_aux_bit0_high(void);
extern void gpio_set_aux_bit0_high(void);
extern void sys_user_save_mode_slot(void);
extern void uart_api_send_bytes(unsigned char, unsigned short, unsigned char *);
extern void osd_mark_settings_changed_copy(void);

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
 * Set row 0x2B (43) of uart_cmd_dispatch_set (id 00240): switch the automatic level on (1) or off (0) from a frame
 * of MSI's PC tool and apply it.
 *
 *   port  the command port the frame came in on (2, 3 or another); it selects the receive record and the reply
 *         frame
 *
 * Returns 0 after the "5600+" reply has been sent, or UART_CMD_REFUSED (0xFF) for a value other than 0 or 1;
 * then nothing has changed and the dispatcher answers "5600-".
 *
 * Phases:
 *   1. Read the value from frame byte 9 (one digit); refuse anything but 0 and 1.
 *   2. Store it in the automatic level bit (+0x11C bit 31).
 *   3. Switching on with a blur reduction mode set: the blur reduction mode is cleared to 0, then
 *      sys_user_clear_second_picture_request runs (its test needs a non-zero blur reduction mode, so with the
 *      mode now 0 it changes nothing).
 *   4. Apply the setting (sys_user_apply_auto_level). Switched off: when gpio_is_aux_bit0_high reads 0,
 *      gpio_set_aux_bit0_high runs (both use GPIO port 0xFF).
 *   5. Copy the picture settings into the slot of the current mode (sys_user_save_mode_slot), request that the
 *      settings are saved, and reply "5600+\r".
 */
int uart_cmd_set_auto_level(unsigned char port)
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
    if ((unsigned char)value > 1)
        return UART_CMD_REFUSED;
    /* Phase 2. */
    user_settings.auto_level = (unsigned char)value;
    /* Phase 3: switching the automatic level on clears the blur reduction mode. */
    if (user_settings.auto_level && user_settings.blur_free_mode != 0) {
        user_settings.blur_free_mode = 0;
        sys_user_clear_second_picture_request();
    }
    /* Phase 4. */
    sys_user_apply_auto_level();
    if (!user_settings.auto_level) {
        if (gpio_is_aux_bit0_high() == 0)
            gpio_set_aux_bit0_high();
    }
    /* Phase 5. */
    sys_user_save_mode_slot();
    osd_mark_settings_changed_copy();
    uart_cmd_build_ok_reply(port);
    uart_cmd_clear_rx(port);
    uart_cmd_send_tx_buffer(port, UART_CMD_OK_REPLY_LENGTH);
    return 0;
}
