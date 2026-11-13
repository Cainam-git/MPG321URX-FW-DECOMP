/* uart_cmd_adjust_pbp_split  (FUN_a00c9980)
 *
 * Accept, open or move the PBP custom split on a PC tool command.
 *   port: command port (2, 3 or 4)
 * Returns: 0, or 0xFF when refused
 * Note: Command 5b006>0; digit 0..3 = accept (store and close), open the editor, left, right; refused above 3
 *   or without PIP/PBP.
 * Name basis: derived - set frame 5b006>0; calls osd_accept_pbp_custom_split, osd_open_pbp_custom_split,
 *   OSDPBPAdjustL / OSDPBPAdjustR
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00c9980 @ 0xa00c9980-0xa00c9be0 (152 words), flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on:
 *  - the three port helpers are defined in this file, so GCC inlines them at -O3;
 *  - the value is copied from the unsigned short difference into an unsigned char local, and the actions are an
 *    if/else chain on it (a switch gives a compare tree; testing the cast directly gives btst for the 0 case).
 */

#define UART_CMD_REFUSED          0xff      /* result: the dispatcher answers "5600-" */
#define UART_CMD_OK_REPLY_LENGTH  6         /* "5600+\r" */
#define VALUE_CHAR_BASE           0x30      /* '0': a value byte of the frame is the value plus 0x30 */
#define VALUE_CHAR_OFFSET         9         /* frame byte 9: the one-digit value of the command */

/* Command values: the four keys of the PBP custom split editor. */
#define SPLIT_ACTION_ACCEPT       0         /* keep the split and close the editor (OK) */
#define SPLIT_ACTION_OPEN         1         /* switch to the custom split and open the editor */
#define SPLIT_ACTION_LEFT         2         /* move the split left one step */
#define SPLIT_ACTION_RIGHT        3         /* move the split right one step */

#define PIP_PBP_OFF               0         /* user_settings_pip_pbp_mode */

extern unsigned char uart_cmd_rx_state_port2, uart_cmd_rx_state_port3, uart_cmd_rx_count;
extern unsigned char uart_cmd_rx_record_port2[], uart_cmd_rx_record_port3[], uart_cmd_rx_record[];
extern unsigned char uart_cmd_tx_frame[], uart_cmd_tx_frame_port3[], uart_cmd_tx_frame_port2[];
extern unsigned char user_settings_pip_pbp_mode;
extern void osd_accept_pbp_custom_split(void);
extern void osd_open_pbp_custom_split(void);
extern void OSDPBPAdjustL(void);
extern void OSDPBPAdjustR(void);
extern void osd_user_apply_menu_timeout(void);
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
 * Set row 0x80 (128) of uart_cmd_dispatch_set ("006>0"): work the PBP custom split editor from the PC tool, with
 * the same routines the menu keys of that editor (menu state 0x109) call.
 *
 *   port  the command port the frame came in on (2, 3 or another); it selects the receive record and the reply
 *         frame
 *
 * Returns UART_CMD_REFUSED (0xFF) for a value above 3 (frame byte 9 minus 0x30) or while PIP/PBP is off; the
 * dispatcher then answers "5600-". Otherwise 0 after the "5600+" reply has been sent.
 *
 *   value 0  osd_accept_pbp_custom_split: store the split, switch PBP to it, close the editor
 *   value 1  osd_open_pbp_custom_split: switch PBP to the custom split and open the editor
 *   value 2  OSDPBPAdjustL, then the menu time-out is applied again
 *   value 3  OSDPBPAdjustR, then the menu time-out is applied again
 *
 * After any of them a save is requested and "5600+\r" is sent. uart_cmd_dispatch_set leaves the menu open
 * after this command while the menu state is 0x109.
 */
int uart_cmd_adjust_pbp_split(unsigned char port)
{
    unsigned char value_char;
    unsigned short value;
    unsigned char action;

    if (port == 2)
        value_char = uart_cmd_rx_record_port2[VALUE_CHAR_OFFSET];
    else if (port == 3)
        value_char = uart_cmd_rx_record_port3[VALUE_CHAR_OFFSET];
    else
        value_char = uart_cmd_rx_record[VALUE_CHAR_OFFSET];
    value = value_char - VALUE_CHAR_BASE;
    action = value;
    if (action > SPLIT_ACTION_RIGHT)
        return UART_CMD_REFUSED;
    if (user_settings_pip_pbp_mode == PIP_PBP_OFF)
        return UART_CMD_REFUSED;
    if (action == SPLIT_ACTION_ACCEPT)
        osd_accept_pbp_custom_split();
    else if (action == SPLIT_ACTION_OPEN)
        osd_open_pbp_custom_split();
    else if (action == SPLIT_ACTION_LEFT) {
        OSDPBPAdjustL();
        osd_user_apply_menu_timeout();
    } else if (action == SPLIT_ACTION_RIGHT) {
        OSDPBPAdjustR();
        osd_user_apply_menu_timeout();
    }
    osd_mark_settings_changed_copy();
    uart_cmd_build_ok_reply(port);
    uart_cmd_clear_rx(port);
    uart_cmd_send_tx_buffer(port, UART_CMD_OK_REPLY_LENGTH);
    return 0;
}
