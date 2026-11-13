/* uart_cmd_answer_panel_protect  (FUN_a00caf0c)
 *
 * Answer the OLED Panel Protect prompt on behalf of the user (PC tool command)
 *   port: command port (2, 3 or 4)
 * Returns: 0, or 0xFF when refused
 * Note: Command 5b00;30; digit 0..2; returns 0xFF for a bad value (the task then replies 5600-), else 0 after
 *   '5600+'.
 * Name basis: derived - set frame 5b00;30; set uses osd_accept_panel_protect_prompt
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00caf0c @ 0xa00caf0c-0xa00cb1c8 (700 bytes), flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on:
 *  - the three port helpers are defined in this file, so GCC inlines them at -O3 and each copy repeats the port
 *    test;
 *  - the frame byte is held in an unsigned char, the byte minus 0x30 in an unsigned short, and the test is made
 *    on that value as an unsigned char;
 *  - bit 15 of the halfwords +0xE and +0x14 of app_state_record and bits 31 / 30 of oled_care_flags are
 *    single-bit bit-fields; bit 31 is set before bit 30.
 */

#define UART_CMD_REFUSED             0xff   /* result: the dispatcher answers "5600-" */
#define UART_CMD_OK_REPLY_LENGTH     6      /* "5600+\r" */
#define VALUE_CHAR_BASE              0x30   /* '0': a value byte of the frame is the value plus 0x30 */
#define VALUE_CHAR_OFFSET            9      /* frame byte that carries a one-character value */
#define OSD_REQUEST_SETTINGS_CHANGED 0x02   /* bit 1 of osd_request_bits */

/* The answers this command accepts (frame byte 9 minus 0x30). */
enum {
    PROTECT_ANSWER_CLEAR = 0,               /* clears bit 15 of half_0xe */
    PROTECT_ANSWER_SET   = 1,               /* sets bit 15 of half_0xe */
    PROTECT_ANSWER_RUN   = 2                /* clears bit 15 of half_0xe and sets the Panel Protect bits */
};
#define PROTECT_ANSWER_MAX           PROTECT_ANSWER_RUN

extern unsigned char uart_cmd_rx_state_port2, uart_cmd_rx_state_port3, uart_cmd_rx_count;
extern unsigned char uart_cmd_rx_record_port2[], uart_cmd_rx_record_port3[], uart_cmd_rx_record[];
extern unsigned char uart_cmd_tx_frame[], uart_cmd_tx_frame_port3[], uart_cmd_tx_frame_port2[];

/* The fields of the application state record (app_state_record, 0xA802CFF4) used here. */
struct app_state_fields {
    unsigned char pad00[0xe];
    unsigned short half_0xe_bit15 : 1,          /* +0xE bit 15: read by osd_accept_panel_protect_prompt */
                   half_0xe_rest : 15;
    unsigned char pad10[4];
    unsigned short half_0x14_bit15 : 1,         /* +0x14 bit 15: while set, osd_run_periodic_task does not look
                                                   for a new panel protect step */
                   half_0x14_rest : 15;
};
extern struct app_state_fields app_state_record;

/* The fields of the user settings record (user_settings, 0xA802D290) used here. */
struct user_settings_record {
    unsigned char pad000[0x1dc];
    unsigned int panel_protect_run : 1,         /* +0x1DC bit 31: Panel Protect run */
                 panel_protect_request : 1,     /* +0x1DC bit 30: Panel Protect request */
                 oled_care_rest : 30;           /* (oled_care_flags) */
    unsigned char pad1e0[0x1ee - 0x1e0];
    unsigned char protect_notice;               /* +0x1EE: Protect Notice */
};
extern struct user_settings_record user_settings;

extern unsigned char osd_request_bits;
extern void osd_accept_panel_protect_prompt(void);
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
 * Set row 0x7A (122, row id 00;30) of uart_cmd_dispatch_set: answer the OLED Panel Protect prompt from one frame
 * of the PC tool, the way the OK key on the prompt does.
 *
 *   port  the command port the frame came in on (2, 3 or another; uart_cmd_run_tool_task passes 4); it selects
 *         the receive record and the reply frame
 *
 * Returns 0 after the "5600+" reply has been sent, or UART_CMD_REFUSED (0xFF) for an answer above 2; then the
 * dispatcher answers "5600-" and nothing has changed.
 *
 * Phases:
 *   1. Take the answer from frame byte 9 (the answer plus 0x30, 0..2).
 *   2. Store it: 1 sets and 0 clears bit 15 of app_state_record half_0xe. 2 clears that bit, sets Protect Notice
 *      (+0x1EE) and the Panel Protect run and request bits (+0x1DC bits 31 and 30) and requests a settings save;
 *      these are the same changes that button 2 of the panel protect dialogs makes in
 *      osd_accept_panel_protect_prompt.
 *   3. Clear bit 15 of app_state_record half_0x14, so that osd_run_periodic_task looks for a new panel protect
 *      step again.
 *   4. Run osd_accept_panel_protect_prompt, the OK key handler of the prompt. It works with the button and row
 *      held in osd_edit_value and osd_choice_row, which this routine does not set. Then request a settings save.
 *   5. Reply "5600+\r".
 */
int uart_cmd_answer_panel_protect(unsigned char port)
{
    unsigned char frame_byte;
    unsigned short value;
    unsigned char answer;

    /* Phase 1: the answer. */
    if (port == 2)
        frame_byte = uart_cmd_rx_record_port2[VALUE_CHAR_OFFSET];
    else if (port == 3)
        frame_byte = uart_cmd_rx_record_port3[VALUE_CHAR_OFFSET];
    else
        frame_byte = uart_cmd_rx_record[VALUE_CHAR_OFFSET];
    value = frame_byte - VALUE_CHAR_BASE;
    answer = value;
    if (answer > PROTECT_ANSWER_MAX)
        return UART_CMD_REFUSED;

    /* Phase 2: store it. */
    if (answer == PROTECT_ANSWER_SET) {
        app_state_record.half_0xe_bit15 = 1;
    } else if (answer == PROTECT_ANSWER_CLEAR) {
        app_state_record.half_0xe_bit15 = 0;
    } else {
        app_state_record.half_0xe_bit15 = 0;
        user_settings.protect_notice = 1;
        user_settings.panel_protect_run = 1;
        user_settings.panel_protect_request = 1;
        osd_request_bits |= OSD_REQUEST_SETTINGS_CHANGED;
    }

    /* Phase 3: let the menu task check the protect steps again. */
    app_state_record.half_0x14_bit15 = 0;

    /* Phase 4: carry the answer out as the prompt's OK key does. */
    osd_accept_panel_protect_prompt();
    osd_mark_settings_changed_copy();

    /* Phase 5: acknowledge. */
    uart_cmd_build_ok_reply(port);
    uart_cmd_clear_rx(port);
    uart_cmd_send_tx_buffer(port, UART_CMD_OK_REPLY_LENGTH);
    return 0;
}
