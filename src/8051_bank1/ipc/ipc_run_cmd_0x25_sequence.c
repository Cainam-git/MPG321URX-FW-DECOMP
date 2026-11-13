/* ipc_run_cmd_0x25_sequence  (FUN_CODE_4ec1)
 *
 * Run the timed port sequence started by main-processor command 0x25.
 * Note: Every give-up path writes 0xF17D = 1 and returns to state 0.
 * Name basis: descriptive - state 0xA35E reset by command 0x25 (port numbers 0xA3E0/0xA3E1 into the 0xF180
 *   table), timeouts 500/600/1200 ticks
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_4ec1 @ 0x4ec1..0x50c9 (520 bytes), OPTIMIZE(8,SPEED) LARGE.
 * Every give-up path is the same two stores (one shared tail in the firmware).
 * LARGE locals: first_ctrl at XDATA 0xA473, second_ctrl at 0xA476 (generic pointers, both initialised to 0).
 * volatile: the pointees (register bytes, read again for each test) and 0xDCB0 (read back between the set and
 *   the clear of bit 1).
 * Source form: the pointer tests are written 'p != (void *)0' / 'p == (void *)0' after the pointee test (the
 *   firmware tests the pointee first and then the pointer with the low byte reloaded). The bodies of cases 2 and 3
 *   start at 0x5079 and 0x5091.
 */
/* EDID slave port entry registers at XDATA 0xF180 + 2 * port (ports 0..6), as edid_set_port_entries uses them. */
struct edid_entry_regs { unsigned char entry, ctrl; };
extern struct edid_entry_regs xdata reg_edid0_entry[7];
extern unsigned char xdata ipc_cmd25_sequence_state;
extern unsigned char xdata ipc_cmd25_first_port, ipc_cmd25_second_port;
extern unsigned char volatile * xdata ipc_cmd25_port_entry_ptr;
extern unsigned int xdata ipc_cmd25_start_ticks, ipc_cmd25_step_ticks;
extern unsigned char xdata DAT_EXTMEM_a6ac;
extern unsigned char xdata DAT_EXTMEM_f17d;
extern unsigned char volatile xdata DAT_EXTMEM_dcb0;
extern unsigned int timer_get_ticks(void);
extern bit sys_test_port_event_bit(unsigned char port);

#define EDID_PORTS          7       /* port numbers 0..6 have an entry register pair */
#define ENTRY_CTRL_BITS     0x7f    /* bits 6..0 of the entry control byte: 0 ends the sequence */

/* ipc_cmd25_sequence_state (command 0x25 sets it to SEQ_STATE_START). */
#define SEQ_STATE_START     0
#define SEQ_STATE_WATCH     1
#define SEQ_STATE_TIMED_OUT 2       /* more than SEQ_TOTAL_TICKS since the start */
#define SEQ_STATE_QUIET     3       /* more than SEQ_QUIET_TICKS without a port event */

#define SEQ_TOTAL_TICKS     600
#define SEQ_QUIET_TICKS     500
#define SEQ_QUIET_END_TICKS 1200    /* state 3 ends no earlier than this after the start */

/* XDATA 0xF17D; command 0x25 writes SEQ_F17D_STOPPED before the sequence starts. */
#define SEQ_F17D_STOPPED    0x01
#define SEQ_F17D_STARTED    0x81

/* Bits of XDATA 0xDCB0 written here; bits 6 and 7 are the port events sys_test_port_event_bit reads. */
#define DCB0_SEQUENCE_ON    0x01
#define DCB0_EVENT_PULSE    0x02

/*
 * ipc_run_cmd_0x25_sequence - one step of the port sequence that mailbox command 0x25 starts. The command stores two
 * port numbers (ipc_cmd25_first_port / _second_port) and resets the state; sys_main calls this routine on every round
 * of its loop on chips whose reg_chip_id reads 0x1A or 0x20.
 *
 * Each step ends by giving up (0xF17D = SEQ_F17D_STOPPED, state back to SEQ_STATE_START) when the watched entry
 * control byte has bits 6..0 at 0:
 *   SEQ_STATE_START  take the entry control byte of the second port when its bits 6..0 are not 0, else that of
 *                    the first port (a port number above 6 has none). Give up when neither is usable, and also whenever the second port number is above 6 (even if the first port is usable). Otherwise
 *                    set bit 0 of 0xDCB0, 0xF17D = SEQ_F17D_STARTED, note the time twice and go to SEQ_STATE_WATCH.
 *   SEQ_STATE_WATCH  after more than 600 ticks since the start go to SEQ_STATE_TIMED_OUT; else after more than
 *                    500 ticks since the last port event go to SEQ_STATE_QUIET; else on an event of port 0 or 1
 *                    note the time and pulse bit 1 of 0xDCB0. Then the give-up test.
 *   SEQ_STATE_TIMED_OUT  only the give-up test.
 *   SEQ_STATE_QUIET  the give-up test, once more than 1200 ticks have passed since the start.
 */
void ipc_run_cmd_0x25_sequence(void)
{
    unsigned char volatile *first_ctrl = 0;
    unsigned char volatile *second_ctrl = 0;

    switch (ipc_cmd25_sequence_state) {
    case SEQ_STATE_START:
        if (ipc_cmd25_first_port < EDID_PORTS)
            first_ctrl = &reg_edid0_entry[ipc_cmd25_first_port].ctrl;
        if (ipc_cmd25_second_port < EDID_PORTS)
            second_ctrl = &reg_edid0_entry[ipc_cmd25_second_port].ctrl;
        if ((((*first_ctrl & ENTRY_CTRL_BITS) == 0 || first_ctrl == (void *)0) && (*second_ctrl & ENTRY_CTRL_BITS) == 0) || second_ctrl == (void *)0) {
            DAT_EXTMEM_f17d = SEQ_F17D_STOPPED;
            ipc_cmd25_sequence_state = SEQ_STATE_START;
            break;
        }
        /* The second port wins when both are usable. */
        if ((*first_ctrl & ENTRY_CTRL_BITS) && first_ctrl != (void *)0)
            ipc_cmd25_port_entry_ptr = first_ctrl;
        if ((*second_ctrl & ENTRY_CTRL_BITS) && second_ctrl != (void *)0)
            ipc_cmd25_port_entry_ptr = second_ctrl;
        DAT_EXTMEM_dcb0 |= DCB0_SEQUENCE_ON;
        DAT_EXTMEM_f17d = SEQ_F17D_STARTED;
        ipc_cmd25_sequence_state = SEQ_STATE_WATCH;
        ipc_cmd25_start_ticks = timer_get_ticks();
        ipc_cmd25_step_ticks = timer_get_ticks();
        DAT_EXTMEM_a6ac = 0;
        break;
    case SEQ_STATE_WATCH:
        if (timer_get_ticks() - ipc_cmd25_start_ticks > SEQ_TOTAL_TICKS)
            ipc_cmd25_sequence_state = SEQ_STATE_TIMED_OUT;
        else if (timer_get_ticks() - ipc_cmd25_step_ticks > SEQ_QUIET_TICKS)
            ipc_cmd25_sequence_state = SEQ_STATE_QUIET;
        else if (sys_test_port_event_bit(0) || sys_test_port_event_bit(1)) {
            ipc_cmd25_step_ticks = timer_get_ticks();
            DAT_EXTMEM_dcb0 |= DCB0_EVENT_PULSE;
            DAT_EXTMEM_dcb0 &= ~DCB0_EVENT_PULSE;
        }
        if ((*ipc_cmd25_port_entry_ptr & ENTRY_CTRL_BITS) == 0) {
            DAT_EXTMEM_f17d = SEQ_F17D_STOPPED;
            ipc_cmd25_sequence_state = SEQ_STATE_START;
        }
        break;
    case SEQ_STATE_TIMED_OUT:
        if ((*ipc_cmd25_port_entry_ptr & ENTRY_CTRL_BITS) == 0) {
            DAT_EXTMEM_f17d = SEQ_F17D_STOPPED;
            ipc_cmd25_sequence_state = SEQ_STATE_START;
        }
        break;
    case SEQ_STATE_QUIET:
        if (timer_get_ticks() - ipc_cmd25_start_ticks > SEQ_QUIET_END_TICKS) {
            if ((*ipc_cmd25_port_entry_ptr & ENTRY_CTRL_BITS) == 0) {
                DAT_EXTMEM_f17d = SEQ_F17D_STOPPED;
                ipc_cmd25_sequence_state = SEQ_STATE_START;
            }
        }
        break;
    }
}
