/* uart_cmd_set_brightness  (FUN_a00c6424)
 *
 * Set the Brightness from a PC tool command and acknowledge it.
 *   port: command port (2, 3 or 4)
 * Returns: 0, or 0xFF when refused
 * Note: Command 5b00400; three digits; returns 0xFF for a bad value (the task then replies 5600-), else 0
 *   after '5600+'.
 * Name basis: proven - set frame 5b00400; settings byte +0x9 (sys_user_apply_brightness, brightness slider)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00c6424 @ 0xa00c6424-0xa00c6690 (620 bytes), flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on:
 *  - uart_cmd_parse_value and the three port helpers are defined in this file, so GCC inlines them at -O3;
 *  - the two settings tests are one '&&' condition nested inside the BAD_VALUE test, with the automatic level
 *    bit read as a 1-bit bit-field, and the shared refusal is the last statement.
 */

#define UART_CMD_REFUSED          0xff      /* result: the dispatcher answers "5600-" */
#define UART_CMD_OK_REPLY_LENGTH  6         /* "5600+\r" */
#define BAD_VALUE                 0xff      /* uart_cmd_parse_value: the three bytes are not a number 0..199 */
#define BRIGHTNESS_MAX            100

extern unsigned char uart_cmd_rx_state_port2, uart_cmd_rx_state_port3, uart_cmd_rx_count;
extern unsigned char uart_cmd_rx_record_port2[], uart_cmd_rx_record_port3[], uart_cmd_rx_record[];
extern unsigned char uart_cmd_tx_frame[], uart_cmd_tx_frame_port3[], uart_cmd_tx_frame_port2[];

/* The fields of the user settings record (user_settings, 0xA802D290) used here. */
struct user_settings_record {
    unsigned char pad000[9];
    unsigned char brightness;                   /* +0x09: Brightness */
    unsigned char pad00a[0xb0 - 0xa];
    unsigned int blur_free_mode;                /* +0xB0: the blur reduction mode */
    unsigned char pad0b4[0x11c - 0xb4];
    struct {                                    /* +0x11C: professional flags */
        unsigned int auto_level : 1,            /*   bit 31: automatic level */
                     bits_30_5 : 26,
                     low_blue_light : 1,        /*   bit 4: Low Blue Light */
                     bits_3_0 : 4;
    } professional_flags;
};
extern struct user_settings_record user_settings;
extern void sys_user_apply_brightness(void);
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

/* The value of a set frame: bytes 7, 8 and 9 of the port's receive record as three ASCII digits. The hundreds
   digit may only be '0' or '1', so the result is 0..199; any other byte gives BAD_VALUE (0xFF). */
unsigned char uart_cmd_parse_value(unsigned char port)
{
    unsigned char hundreds, tens, units;
    unsigned short value;

    if (port == 2) {
        hundreds = uart_cmd_rx_record_port2[7];
        tens = uart_cmd_rx_record_port2[8];
        units = uart_cmd_rx_record_port2[9];
    } else if (port == 3) {
        hundreds = uart_cmd_rx_record_port3[7];
        tens = uart_cmd_rx_record_port3[8];
        units = uart_cmd_rx_record_port3[9];
    } else {
        hundreds = uart_cmd_rx_record[7];
        tens = uart_cmd_rx_record[8];
        units = uart_cmd_rx_record[9];
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
    value = hundreds * 100 + tens * 10 + units;
    return value;
}

/*
 * Set row 3 of uart_cmd_dispatch_set: set the Brightness from a frame of MSI's PC tool and apply it.
 *
 *   port  the command port the frame came in on (2, 3 or another); it selects the receive record and the reply
 *         frame
 *
 * Returns 0 after the "5600+" reply has been sent, or UART_CMD_REFUSED (0xFF); then nothing has changed and the
 * dispatcher answers "5600-".
 *
 * Phases:
 *   1. Read the three-digit value from frame bytes 7..9 (uart_cmd_parse_value).
 *   2. Refused: a frame that is not a number, any blur reduction mode other than 0, the automatic level on, or
 *      a value above 100.
 *   3. Store the brightness, apply it (sys_user_apply_brightness), copy the picture settings into the slot of
 *      the current mode (sys_user_save_mode_slot) and request that the settings are saved.
 *   4. Reply "5600+\r".
 */
int uart_cmd_set_brightness(unsigned char port)
{
    unsigned char brightness;

    /* Phase 1. */
    brightness = uart_cmd_parse_value(port);
    if (brightness != BAD_VALUE) {
        /* Phase 2: the brightness can only be set with blur reduction and automatic level both off. */
        if (user_settings.blur_free_mode == 0 && !user_settings.professional_flags.auto_level) {
            if (brightness > BRIGHTNESS_MAX)
                return UART_CMD_REFUSED;
            /* Phase 3. */
            user_settings.brightness = brightness;
            sys_user_apply_brightness();
            sys_user_save_mode_slot();
            osd_mark_settings_changed_copy();
            /* Phase 4. */
            uart_cmd_build_ok_reply(port);
            uart_cmd_clear_rx(port);
            uart_cmd_send_tx_buffer(port, UART_CMD_OK_REPLY_LENGTH);
            return 0;
        }
    }
    return UART_CMD_REFUSED;
}
