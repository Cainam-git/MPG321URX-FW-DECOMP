/* uart_cmd_read_frame_port2  (FUN_a00bb560)
 *
 * Collect received bytes of port 2 and classify the frame.
 *   port: port whose receive ring is read; the one caller passes 2, and the bytes go to the port-2 record
 *       whatever the value
 * Returns: frame class bits: 2 get frame, 4 set frame, 8 nothing yet, 0x10 bad frame or wait ran out
 * Note: Count 0xA802B09A, busy flag 0xA802B099, timer 0x10; '00+' / '00-' frames are dropped.
 * Name basis: derived - same layout as uart_cmd_read_frame; caller uart_cmd_poll_port2
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00bb560 @ 0xa00bb560..0xa00bb86c (780 bytes), flags -mcpu=v8 -O3 -g.
 * Types as in uart_cmd_read_frame: cr_index unsigned int ('& 0xf' index), received an unsigned short stack local.
 * Source form: the two "00+" / "00-" tests are separate ifs with their own clear loops (the firmware reads byte 2
 * again for the second test).
 */
extern void uart_api_read_rx_ring(unsigned char, unsigned short, unsigned char *, unsigned short *);
extern unsigned short sys_app_timer_read(int);
extern void sys_app_timer_start(int, int);

/* The one field of the application state record used here. */
struct app_state_record {
    unsigned char pad0[0x18];
    unsigned short half_0x18;           /* +0x18: bit 10 = LED_BAR_FLAG10 */
};
extern struct app_state_record app_state_record;
extern unsigned char uart_cmd_rx_state_port2, uart_cmd_wait_flag_port2;
extern unsigned char uart_cmd_rx_record_port2[];

/* Frame classes returned to uart_cmd_poll_port2 (same values as uart_cmd_read_frame). */
#define FRAME_GET         0x02      /* complete "58" frame */
#define FRAME_SET         0x04      /* complete "5b" frame */
#define FRAME_INCOMPLETE  0x08      /* nothing to do yet (also after a dropped "5600+" / "5600-") */
#define FRAME_BAD         0x10      /* bad frame, or the wait for the rest of the frame ran out */

#define FRAME_TIMER       0x10      /* application timer of port 2's frame wait */
#define STRAY_WAIT_MS     50        /* wait after a first byte that is not '5' */
#define FRAME_WAIT_MS     250       /* wait for the rest of a frame once 6 bytes are in */
#define RX_READ_LIMIT     0x30
#define RX_RECORD_SIZE    0x32
#define FRAME_MIN_BYTES   6

/* Bit 10 of app_state_record +0x18; sys_led_bar_get_flag10 reads it back (osd_check_panel_protect_prompt shows
   no prompt while it is 1). */
#define LED_BAR_FLAG10    0x400

/*
 * The port-2 copy of uart_cmd_read_frame: read what has arrived on the port into uart_cmd_rx_record_port2 (after
 * the uart_cmd_rx_state_port2 bytes already there) and say whether a whole frame is in.
 *
 *   port  serial port to read; the only caller, uart_cmd_poll_port2, passes 2.
 *
 * Returns one FRAME_* class. Differences from uart_cmd_read_frame:
 *   - the wait runs on its own flag (uart_cmd_wait_flag_port2) and timer FRAME_TIMER, and a wait that ran out
 *     gives FRAME_BAD (no time-out class);
 *   - a count that reaches 0x30 starts again at 0;
 *   - every 'b' frame is taken as 11 bytes (CR at byte 10). A 'b' frame with id bytes 4, 5 = ';', '4' also sets
 *     LED_BAR_FLAG10 when byte 9 is '1' and clears it otherwise - this happens as soon as the first 6 bytes are
 *     in, before the CR is checked;
 *   - a '6' frame ("5600+\r" / "5600-\r", the answer frames, CR at byte 5) is dropped: the record and its count
 *     are cleared and FRAME_INCOMPLETE is returned. Other '6' frames are FRAME_BAD.
 */
unsigned char uart_cmd_read_frame_port2(unsigned char port)
{
    unsigned short received = 0;
    unsigned int cr_index = 0;
    unsigned char i;

    uart_api_read_rx_ring(port, RX_READ_LIMIT - uart_cmd_rx_state_port2, &uart_cmd_rx_record_port2[uart_cmd_rx_state_port2], &received);
    if (received == 0 && sys_app_timer_read(FRAME_TIMER) == 0 && uart_cmd_wait_flag_port2 == 1) {
        uart_cmd_wait_flag_port2 = 0;
        return FRAME_BAD;
    }
    uart_cmd_rx_state_port2 += received;
    if (uart_cmd_rx_state_port2 > 0x2f)
        uart_cmd_rx_state_port2 = 0;
    /* Something other than a frame start: give it STRAY_WAIT_MS, then the time-out clears it. */
    if (uart_cmd_rx_record_port2[0] != '5' && uart_cmd_rx_record_port2[0] != 0 && sys_app_timer_read(FRAME_TIMER) == 0) {
        uart_cmd_wait_flag_port2 = 1;
        sys_app_timer_start(FRAME_TIMER, STRAY_WAIT_MS);
    }
    if (uart_cmd_rx_record_port2[0] != '5' || uart_cmd_rx_state_port2 < FRAME_MIN_BYTES)
        return FRAME_INCOMPLETE;
    if (sys_app_timer_read(FRAME_TIMER) == 0) {
        uart_cmd_wait_flag_port2 = 1;
        sys_app_timer_start(FRAME_TIMER, FRAME_WAIT_MS);
    }
    if (uart_cmd_rx_record_port2[1] == '8')
        cr_index = 7;
    else if (uart_cmd_rx_record_port2[1] == 'b') {
        cr_index = 10;
        if (uart_cmd_rx_record_port2[4] == ';' && uart_cmd_rx_record_port2[5] == '4') {
            if (uart_cmd_rx_record_port2[9] == '1')
                app_state_record.half_0x18 |= LED_BAR_FLAG10;
            else
                app_state_record.half_0x18 &= ~LED_BAR_FLAG10;
        }
    } else if (uart_cmd_rx_record_port2[1] == '6')
        cr_index = 5;
    if (uart_cmd_rx_state_port2 <= (cr_index & 0xf))
        return FRAME_INCOMPLETE;
    if (uart_cmd_rx_record_port2[cr_index & 0xf] != '\r')
        return FRAME_BAD;
    uart_cmd_wait_flag_port2 = 0;
    if (uart_cmd_rx_record_port2[1] == '8')
        return FRAME_GET;
    if (uart_cmd_rx_record_port2[1] == 'b')
        return FRAME_SET;
    /* "5600+" and "5600-" are answers, not commands: forget them without a reply. */
    if (uart_cmd_rx_record_port2[2] == '0' && uart_cmd_rx_record_port2[3] == '0' && uart_cmd_rx_record_port2[4] == '+') {
        uart_cmd_rx_state_port2 = 0;
        for (i = 0; i < RX_RECORD_SIZE; i++)
            uart_cmd_rx_record_port2[i] = 0;
        return FRAME_INCOMPLETE;
    }
    if (uart_cmd_rx_record_port2[2] == '0' && uart_cmd_rx_record_port2[3] == '0' && uart_cmd_rx_record_port2[4] == '-') {
        uart_cmd_rx_state_port2 = 0;
        for (i = 0; i < RX_RECORD_SIZE; i++)
            uart_cmd_rx_record_port2[i] = 0;
        return FRAME_INCOMPLETE;
    }
    return FRAME_BAD;
}
