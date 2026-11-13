/* uart_cmd_poll_port2  (FUN_a00bbabc)
 *
 * Receive commands on port 2, answer unknown or bad ones and log set commands.
 * Note: Set commands are only printed ('##ucCmdIndex=%d', '##ucCmdStatus=%d'), not carried out.
 * Name basis: proven - prints '##ucCmdIndex' / '##ucCmdStatus'; called from sys_run_app_timer_task
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00bbabc @ 0xa00bbabc-0xa00bbda0 (185 words), flags -mcpu=v8 -O3 -g.
 * Source form: the case order 0x80, 0x40, 0x20, 0x10, 2, 4 decides the block layout; the three reply-'-' cases
 * are written out separately. rx_clear, reply and find_command are static helpers the compiler inlines.
 */
extern unsigned char uart_cmd_read_frame_port2(unsigned char);
extern void uart_api_send_bytes(unsigned char, unsigned short, unsigned char *);
extern unsigned char sys_cmd_frame8_get_char(unsigned short, unsigned short);
extern unsigned char uart_cmd_find_set_command_port2(unsigned char);
extern int dbg_printf();
extern unsigned char uart_cmd_tx_frame_port2[];
extern unsigned char uart_cmd_rx_record_port2[];
extern unsigned char uart_cmd_rx_state_port2, uart_cmd_wait_flag_port2;

#define COMMAND_PORT_2     2
#define ANSWER_LENGTH      6        /* "5600" + answer character + CR */
#define ANSWER_REFUSED     '-'      /* "5600-": bad frame */
#define ANSWER_UNKNOWN     '6'      /* "56006": no get row has this id */
#define LAST_GET_ROW       0x82     /* rows 0..0x82 of the get command table uart_cmd_get_rows */
#define COMMAND_ANY_CHAR   0xff     /* a table character that matches any received character */
#define NO_COMMAND         0xff

/* Frame classes of uart_cmd_read_frame_port2. It returns only 2, 4, 8 and 0x10; the cases 0x20, 0x40 and 0x80
   below are never reached, and 8 (frame not complete) falls out of the switch. */
#define FRAME_GET          0x02
#define FRAME_SET          0x04
#define FRAME_BAD          0x10
#define FRAME_CLASS_20     0x20
#define FRAME_CLASS_40     0x40
#define FRAME_CLASS_80     0x80

/* Forget the received frame: count to 0 and all 0x32 bytes of the record cleared. */
static void rx_clear(void)
{
    unsigned char i;

    uart_cmd_rx_state_port2 = 0;
    for (i = 0; i <= 0x31; i++)
        uart_cmd_rx_record_port2[i] = 0;
}

/* Send the 6-byte answer "5600" + answer + CR from port 2's reply frame. */
static void reply(unsigned char answer)
{
    uart_cmd_tx_frame_port2[0] = '5';
    uart_cmd_tx_frame_port2[1] = '6';
    uart_cmd_tx_frame_port2[2] = '0';
    uart_cmd_tx_frame_port2[3] = '0';
    uart_cmd_tx_frame_port2[4] = answer;
    uart_cmd_tx_frame_port2[5] = '\r';
    uart_api_send_bytes(COMMAND_PORT_2, ANSWER_LENGTH, uart_cmd_tx_frame_port2);
}

/* The first get row whose characters 2..6 equal the received ones (COMMAND_ANY_CHAR matches anything), or
   NO_COMMAND. */
static unsigned char find_command(void)
{
    unsigned char row, column;

    for (row = 0; row <= LAST_GET_ROW; row++) {
        for (column = 2; column <= 6; column++) {
            if (sys_cmd_frame8_get_char(row, column) != COMMAND_ANY_CHAR && sys_cmd_frame8_get_char(row, column) != uart_cmd_rx_record_port2[column])
                break;
        }
        if (column == 7)
            return row;
    }
    return NO_COMMAND;
}

/*
 * Handle what has come in on command port 2. Called from sys_run_app_timer_task on each pass, right after
 * uart_cmd_run_tool_task has handled port 4.
 *
 * Unlike port 4, nothing received here is carried out:
 *   - a bad frame, or one whose wait ran out (FRAME_BAD): cleared, answered "5600-";
 *   - a get frame: answered "56006" when no get row has its id; a known id gets no answer. Cleared either way;
 *   - a set frame: its set row is looked up and printed ("##ucCmdIndex"), the frame is cleared, a status of 0 is
 *     printed ("##ucCmdStatus") and the wait flag is cleared. No answer is sent;
 *   - a frame that is not complete yet: nothing.
 * The one effect of a port-2 command is the one in uart_cmd_read_frame_port2 itself (LED_BAR_FLAG10 from a
 * "5b00;4" frame).
 */
void uart_cmd_poll_port2(void)
{
    unsigned char row;

    switch (uart_cmd_read_frame_port2(COMMAND_PORT_2)) {
    case FRAME_CLASS_80:
        rx_clear();
        break;
    case FRAME_CLASS_40:
        rx_clear();
        reply(ANSWER_REFUSED);
        break;
    case FRAME_CLASS_20:
        rx_clear();
        reply(ANSWER_REFUSED);
        break;
    case FRAME_BAD:
        rx_clear();
        reply(ANSWER_REFUSED);
        break;
    case FRAME_GET:
        row = find_command();
        if (row > LAST_GET_ROW)
            reply(ANSWER_UNKNOWN);
        rx_clear();
        break;
    case FRAME_SET:
        row = uart_cmd_find_set_command_port2(COMMAND_PORT_2);
        dbg_printf("##ucCmdIndex=%d\r\n", row);
        rx_clear();
        dbg_printf("##ucCmdStatus=%d\r\n", 0);
        uart_cmd_wait_flag_port2 = 0;
        break;
    }
}
