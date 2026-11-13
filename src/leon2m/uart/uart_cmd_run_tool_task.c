/* uart_cmd_run_tool_task  (FUN_a00ce348)
 *
 * Receive one command from MSI's PC tool on port 4 and carry it out.
 * Note: Get frames go to uart_cmd_dispatch_get, set frames to uart_cmd_dispatch_set; replies '56006' / '5600-'
 *   on errors.
 * Name basis: proven - docs/MAP.md update path step 3 (command task called from sys_run_app_timer_task)
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00ce348 @ 0xa00ce348..0xa00ce5dc (660 bytes), flags -mcpu=v8 -O3 -g (also matches with
 * -msoft-float).
 * Source forms the exact build depends on:
 *  - uart_api_send_bytes is declared with three arguments (port, length, frame) and uart_cmd_dispatch_set with
 *    two; the set row from uart_cmd_find_set_command goes straight into that call, so it stays in %o1;
 *  - the switch cases stand in the order FRAME_CLASS_20, FRAME_BAD, FRAME_TIMEOUT / FRAME_CLASS_80, FRAME_GET,
 *    FRAME_SET, default; the two reply cases return, the others break to the clear after the switch; one local
 *    (row) holds both the get row and the set row;
 *  - find_get_row (the inlined uart_cmd_find_get_command) reads the receive record through the pointer constant
 *    (struct uart_rx_bytes *)0xa802d0d0, the form that also matches the standalone copy, while rx_clear uses
 *    the symbol uart_cmd_rx_record: the two addresses are separate expressions and the clear builds its own
 *    sethi as in the firmware.
 */
extern unsigned char uart_cmd_read_frame(unsigned char);
extern void uart_api_send_bytes(unsigned char, unsigned short, unsigned char *);
extern unsigned char sys_cmd_frame8_get_char(unsigned short, unsigned short);
extern void uart_cmd_dispatch_get(unsigned char, unsigned char);
extern unsigned char uart_cmd_find_set_command(unsigned char);
extern unsigned char uart_cmd_dispatch_set(unsigned char, unsigned char);

extern unsigned char uart_cmd_tx_frame[];
extern unsigned char uart_cmd_rx_record[];
extern unsigned char uart_cmd_rx_count;

#define TOOL_PORT           4       /* the command port this task serves */

/* Frame classes of uart_cmd_read_frame. */
#define FRAME_GET           0x02    /* complete "58" frame */
#define FRAME_SET           0x04    /* complete "5b" frame */
#define FRAME_BAD           0x10    /* no CR where the frame must end, or another kind character */
#define FRAME_CLASS_20      0x20    /* handled here, but uart_cmd_read_frame never returns it */
#define FRAME_TIMEOUT       0x40    /* the wait for the rest of the frame ran out */
#define FRAME_CLASS_80      0x80    /* handled here, but uart_cmd_read_frame never returns it */

#define GET_ROW_LAST        0x82    /* get rows 0..0x82 of the 8-byte command table (131 rows) */
#define SET_ROW_LAST        0x99    /* set rows 0..0x99 of uart_cmd_dispatch_set */
#define NO_COMMAND          0xff    /* row lookup: no row matches */
#define COMMAND_ANY_CHAR    0xff    /* table character that matches any received byte */
#define ID_FIRST            2       /* frame bytes 2..6 hold the command id */
#define ID_LAST             6
#define UART_CMD_REFUSED    0xff    /* result of uart_cmd_dispatch_set */
#define REPLY_LENGTH        6       /* "5600" + result character + CR */
#define REPLY_UNKNOWN_GET   '6'     /* "56006\r": no get row matches */
#define REPLY_REFUSED       '-'     /* "5600-\r" */

/* Make port 4 ready for the next frame: clear its byte count and bytes 0, 1, 7, 10 and 0x19 of its receive
   record. */
static void rx_clear(void)
{
    uart_cmd_rx_count = 0;
    uart_cmd_rx_record[0x0] = 0;
    uart_cmd_rx_record[0x1] = 0;
    uart_cmd_rx_record[0x7] = 0;
    uart_cmd_rx_record[0xa] = 0;
    uart_cmd_rx_record[0x19] = 0;
}

/* Send "5600" + result + CR on port 4. */
static void send_reply(unsigned char result)
{
    uart_cmd_tx_frame[0] = '5';
    uart_cmd_tx_frame[1] = '6';
    uart_cmd_tx_frame[2] = '0';
    uart_cmd_tx_frame[3] = '0';
    uart_cmd_tx_frame[4] = result;
    uart_cmd_tx_frame[5] = '\r';
    uart_api_send_bytes(TOOL_PORT, REPLY_LENGTH, uart_cmd_tx_frame);
}

/* The receive record of port 4 (uart_cmd_rx_record, 0x32 bytes). */
struct uart_rx_bytes {
    unsigned char bytes[0x32];
};

/* The first get row whose id characters 2..6 in the 8-byte command table match frame bytes 2..6, or
   NO_COMMAND. Same code as the uncalled uart_cmd_find_get_command. */
static unsigned char find_get_row(void)
{
    struct uart_rx_bytes *record = (struct uart_rx_bytes *)0xa802d0d0;    /* uart_cmd_rx_record */
    unsigned char row, column;

    for (row = 0; row <= GET_ROW_LAST; row++) {
        for (column = ID_FIRST; column <= ID_LAST; column++) {
            if (sys_cmd_frame8_get_char(row, column) != COMMAND_ANY_CHAR && sys_cmd_frame8_get_char(row, column) != record->bytes[column])
                break;
        }
        if (column == ID_LAST + 1)
            return row;
    }
    return NO_COMMAND;
}

/*
 * Serve the PC tool on command port 4 once: collect what has arrived and, when a whole frame is in, carry it
 * out. Step 13 of sys_run_app_timer_task.
 *
 * By the class uart_cmd_read_frame returns:
 *   FRAME_GET      look up the get row of the frame; a known row is answered by uart_cmd_dispatch_get, an
 *                  unknown one with "56006\r".
 *   FRAME_SET      look up the set row (uart_cmd_find_set_command); uart_cmd_dispatch_set carries it out and
 *                  sends its own reply. A row above SET_ROW_LAST (the lookup found none) or a refused command
 *                  gets "5600-\r".
 *   FRAME_BAD      "5600-\r".
 *   FRAME_TIMEOUT  nothing is sent.
 *   anything else  (FRAME_INCOMPLETE): the frame is kept and nothing happens.
 * Each of these four clears the receive record (FRAME_BAD before its reply), so the next frame starts at byte
 * 0. The two classes
 * 0x20 (reply "56006\r") and 0x80 (clear only) are handled too, but uart_cmd_read_frame does not return them.
 */
void uart_cmd_run_tool_task(void)
{
    unsigned char row;

    switch (uart_cmd_read_frame(TOOL_PORT)) {
    case FRAME_CLASS_20:
        rx_clear();
        send_reply(REPLY_UNKNOWN_GET);
        return;
    case FRAME_BAD:
        rx_clear();
        send_reply(REPLY_REFUSED);
        return;
    case FRAME_TIMEOUT:
    case FRAME_CLASS_80:
        break;
    case FRAME_GET:
        row = find_get_row();
        if (row <= GET_ROW_LAST)
            uart_cmd_dispatch_get(TOOL_PORT, row);
        else
            send_reply(REPLY_UNKNOWN_GET);
        break;
    case FRAME_SET:
        row = uart_cmd_find_set_command(TOOL_PORT);
        if (row > SET_ROW_LAST || uart_cmd_dispatch_set(TOOL_PORT, row) == UART_CMD_REFUSED)
            send_reply(REPLY_REFUSED);
        break;
    default:
        /* FRAME_INCOMPLETE: wait for more bytes. */
        return;
    }
    rx_clear();
}
