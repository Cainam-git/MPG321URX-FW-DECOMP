/* fwupd_port_wait_ready  (FUN_a0123840)
 *
 * Wait, with a time limit, until one of the two update ports reports ready.
 * Returns: result
 * Name basis: derived - polls 0xCF03C640/0xCF03C648; remembers which port answered
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0123840 @ 0xa0123840-0xa01238e8 (42 words). flags -mcpu=v8 -O3 -g -msoft-float (the register addresses are
 * rebuilt inside the loop instead of being hoisted).
 * Source form: the result is an unsigned char returned as 'result & 1'; the start tick is an unsigned short local.
 */
/* The state registers of the two update ports (0xF190 and 0xF192 of the port window). */
#define PORT0_STATE_REG (*(volatile unsigned int *)0xcf03c640)
#define PORT1_STATE_REG (*(volatile unsigned int *)0xcf03c648)

#define PORT_READY_MIN_STATE 0x83       /* a state above this value counts as ready */
#define WAIT_TICKS           25000

extern unsigned short timer_get_ticks16(void);
extern unsigned short timer_ticks_since(unsigned short start);
extern void ipc_signal_alive(void);
extern unsigned char input_block_is_change_pending(unsigned char blk);
extern unsigned char fwupd_active_port;

/*
 * Wait, for at most WAIT_TICKS timer ticks, until one of the two update ports is ready.
 * Each round, in this order:
 *  - input_block_is_change_pending(0) returning 1 ends the wait with result 0;
 *  - port 0 state above PORT_READY_MIN_STATE sets fwupd_active_port to 0 and ends the wait with result 1;
 *  - the same for port 1, with fwupd_active_port 1;
 *  - otherwise ipc_signal_alive is called (the wait must not stop the sign of life to the 8051).
 * Returns 1 when a port is ready, 0 on a pending change or on timeout. Caller: fwupd_api_wait_port_ready.
 */
unsigned char fwupd_port_wait_ready(void)
{
    unsigned short start;

    start = timer_get_ticks16();
    unsigned char result = 0;

    do {
        if (input_block_is_change_pending(0) == 1)
            break;
        if (PORT0_STATE_REG > PORT_READY_MIN_STATE) {
            fwupd_active_port = 0;
            result = 1;
            break;
        }
        if (PORT1_STATE_REG > PORT_READY_MIN_STATE) {
            fwupd_active_port = 1;
            result = 1;
            break;
        }
        ipc_signal_alive();
    } while (timer_ticks_since(start) < WAIT_TICKS);
    return result & 1;
}
