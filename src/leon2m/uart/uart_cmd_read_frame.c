/* uart_cmd_read_frame  (FUN_a00baef8)
 *
 * Collect received bytes of a port into its record and classify the frame.
 *   port: command port
 * Returns: frame class bits
 * Note: Returns 2 get frame, 4 set frame, 8/0x10/0x40 other states; uses app timer 0x0F as the frame timeout.
 * Name basis: derived - only caller uart_cmd_run_tool_task (port 4); tests frame bytes 0, 1, 4, 5 and the
 *   closing CR
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00baef8 @ 0xa00baef8..0xa00bb1c4 (716 bytes), flags -mcpu=v8 -O3 -g (also matches with -msoft-float).
 * Types the exact build depends on: cr_index is an unsigned int (bleu compare, '& 0x3f' index), received is an
 * unsigned short local on the stack, sys_app_timer_read returns unsigned short, uart_api_read_rx_ring is declared
 * (u8, u16, u8 *, u16 *).
 * Source form: the four 26-byte conditions are separate else-if arms (one || chain gives the opposite branch
 * prediction on the id_char4 == '2' test and lets the compiler hoist the cr_index = 10 sets); 0xa5 / 0xa7 / 0xa8 are
 * one arm (a separate 0xa8 arm changes 6 words).
 */
extern void uart_api_read_rx_ring(unsigned char, unsigned short, unsigned char *, unsigned short *);
extern unsigned short sys_app_timer_read(int);
extern void sys_app_timer_start(int, int);

extern unsigned char uart_cmd_rx_count, uart_cmd_wait_flag;
extern unsigned char uart_cmd_rx_record[];

/* Frame classes returned to uart_cmd_run_tool_task. */
#define FRAME_GET         0x02      /* complete "58" frame: answered by uart_cmd_dispatch_get */
#define FRAME_SET         0x04      /* complete "5b" frame: carried out by uart_cmd_dispatch_set */
#define FRAME_INCOMPLETE  0x08      /* nothing to do yet */
#define FRAME_BAD         0x10      /* no CR where the frame must end, or another second character */
#define FRAME_TIMEOUT     0x40      /* the wait for the rest of the frame ran out */

#define FRAME_TIMER       0xf       /* application timer of this port's frame wait */
#define STRAY_WAIT_MS     50        /* wait after a first byte that is not '5' */
#define FRAME_WAIT_MS     250       /* wait for the rest of a frame once 6 bytes are in */
#define RX_READ_LIMIT     0x30      /* the record (0x32 bytes) is filled up to byte 0x2f */
#define FRAME_MIN_BYTES   6         /* "5", the kind character and the first four id characters */

/*
 * Read what has arrived on the port into uart_cmd_rx_record (after the uart_cmd_rx_count bytes already there)
 * and say whether a whole frame of the PC tool is in.
 *
 *   port  serial port to read; the only caller, uart_cmd_run_tool_task, passes 4. The bytes always go to
 *         uart_cmd_rx_record and uart_cmd_rx_count, whatever the port.
 *
 * Returns one FRAME_* class. The frame is not cleared here; the caller clears it after FRAME_GET, FRAME_SET,
 * FRAME_BAD and FRAME_TIMEOUT.
 *
 * A frame starts with '5'; the second byte gives its kind and so the place of the closing CR:
 *   '8'  get frame, 8 bytes (CR at byte 7);
 *   'b'  set frame of 11, 26 or 42 bytes (CR at byte 10, 0x19 or 0x29), told apart by id bytes 4 and 5 the way
 *        the three set tables of uart_cmd_find_set_command hold them: byte 5 0xa6 is the one 42-byte frame;
 *        0xa5 / 0xa7 / 0xa8 are 11-byte rows; '6<', '2<', '2>', '2?', '1e'..'1g' and every byte 5 of 0x60 or
 *        more are 26-byte frames; the rest are 11-byte frames.
 *   any other kind gives FRAME_BAD (the CR is looked for at byte 0, which holds '5').
 *
 * The wait flag and timer FRAME_TIMER time a frame: a stray first byte starts a 50 ms wait, the first 6 bytes
 * of a frame a 250 ms wait (each only when the timer is not already running). A call that brings no new byte
 * after the time has run out, with the flag set, returns FRAME_TIMEOUT. A complete frame clears the flag.
 */
unsigned char uart_cmd_read_frame(unsigned char port)
{
    unsigned short received = 0;
    unsigned int cr_index = 0;
    unsigned char id_char4, id_char5;

    uart_api_read_rx_ring(port, RX_READ_LIMIT - uart_cmd_rx_count, &uart_cmd_rx_record[uart_cmd_rx_count], &received);
    if (received == 0 && sys_app_timer_read(FRAME_TIMER) == 0 && uart_cmd_wait_flag == 1) {
        uart_cmd_wait_flag = 0;
        return FRAME_TIMEOUT;
    }
    uart_cmd_rx_count += received;
    /* Something other than a frame start: give it STRAY_WAIT_MS, then the time-out clears it. */
    if (uart_cmd_rx_record[0] != '5' && uart_cmd_rx_record[0] != 0 && sys_app_timer_read(FRAME_TIMER) == 0) {
        uart_cmd_wait_flag = 1;
        sys_app_timer_start(FRAME_TIMER, STRAY_WAIT_MS);
    }
    if (uart_cmd_rx_record[0] != '5' || uart_cmd_rx_count < FRAME_MIN_BYTES)
        return FRAME_INCOMPLETE;
    if (sys_app_timer_read(FRAME_TIMER) == 0) {
        uart_cmd_wait_flag = 1;
        sys_app_timer_start(FRAME_TIMER, FRAME_WAIT_MS);
    }
    id_char4 = uart_cmd_rx_record[4];
    id_char5 = uart_cmd_rx_record[5];
    if (uart_cmd_rx_record[1] == '8')
        cr_index = 7;
    else if (uart_cmd_rx_record[1] == 'b') {
        if (id_char5 == 0xa6)
            cr_index = 0x29;
        else if (id_char5 == 0xa5 || id_char5 == 0xa7 || id_char5 == 0xa8)
            cr_index = 0xa;             /* 11-byte rows, kept out of the ">= 0x60" test below */
        else if (id_char5 == 0x3c && id_char4 == '6')
            cr_index = 0x19;
        else if ((id_char5 == 0x3c || id_char5 == 0x3e || id_char5 == 0x3f) && id_char4 == '2')
            cr_index = 0x19;
        else if ((unsigned char)(id_char5 - 0x65) < 3 && id_char4 == '1')
            cr_index = 0x19;
        else if ((id_char5 & 0xf0) > 0x5f)
            cr_index = 0x19;
        else
            cr_index = 0xa;
    }
    if (uart_cmd_rx_count <= (cr_index & 0x3f))
        return FRAME_INCOMPLETE;
    if (uart_cmd_rx_record[cr_index & 0x3f] != '\r')
        return FRAME_BAD;
    uart_cmd_wait_flag = 0;
    if (uart_cmd_rx_record[1] == '8')
        return FRAME_GET;
    return uart_cmd_rx_record[1] == 'b' ? FRAME_SET : FRAME_BAD;
}
