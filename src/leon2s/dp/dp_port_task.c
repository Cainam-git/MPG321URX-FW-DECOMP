/* dp_port_task  (FUN_a00b0738)
 *
 * Run the service of the DisplayPort inputs once: status, test requests and time-outs.
 * Name basis: derived - tick time stamps, receiver register 0x256 (bit 7 printed as 'DPCD 270 start phy test')
 *   and status bits; called from input_poll_port_services
 *
 * Matching notes
 * --------------
 * FUN_a00b0738 (leon2s 0xa00b0738-0xa00b0e54, 1820 bytes), flags -mcpu=v8 -Os -g.
 * Source forms the exact build depends on:
 *  - the four tick arrays are volatile: each store of a timer_get_ticks() result into them stays in front of the
 *    next call with an empty delay slot (st %o0; call; nop at 0xa00b0880, 0xa00b0894, 0xa00b08a8, 0xa00b0a38 and
 *    0xa00b0abc);
 *  - port is an old-style (K&R) unsigned char parameter;
 *  - the second dp_map_port result has its own local (block_again);
 *  - 'changed = (byte != byte)' is its own statement before 'if ((test_request >> 7) & changed)';
 *  - case 0x80 of the last switch keeps the unused 'setting = dp_reg_read8(port, 0x2b8)'.
 */

/* DP input record (300 bytes per DP receiver, dp_input_records). */
struct dp_input_record {
    unsigned char bytes_0x0[0x11f];
    unsigned char byte_0x11f;               /* 1 = status block read in the port interrupt */
    unsigned char bytes_0x120[5];
    unsigned char byte_0x125;               /* dp_run_link_state copies bit 7 of the port record's flags here */
    unsigned char bytes_0x126[2];
    unsigned char byte_0x128;               /* mailbox command 0x30: 1 = use byte_0x129 instead of byte_0x125 */
    unsigned char byte_0x129;               /* mailbox command 0x32 */
    unsigned char bytes_0x12a[2];
};
extern struct dp_input_record dp_input_records[];
extern unsigned char dp_block_event_handled_flags[];        /* 1 = block event handled; dp_run_link_state clears it */

/*
 * State of the lane count check, per DP receiver (0 and 1). The four tick values are time stamps of
 * timer_get_ticks().
 */
extern unsigned char dp_lcnt_check_running_flags[];           /* 1 = the check runs */
extern unsigned char dp_lcnt_check_settings[];           /* last setting seen (byte 0x125 or 0x129) */
extern signed char dp_last_phy_test_requests[];                   /* last value of register 0x256 (bit 7 = test) */
extern volatile unsigned int dp_lcnt_check_start_ticks[];   /* when the check started */
extern volatile unsigned int dp_lcnt_check_hold_ticks[];   /* when the check started or the pending bit was seen */
extern volatile unsigned int dp_lcnt_check_trained_ticks[];   /* when the link was last seen trained */
extern volatile unsigned int dp_lcnt_check_reg44_clear_ticks[];   /* when it was last seen trained with register 0x44 bits 0..1 clear */

#define LAST_DP_RECEIVER        1

/* Receiver registers (dp_reg_*). */
#define DP_REG_44               0x44        /* bits 0..1 are reported as 'Fifo Abnormal' by dp_run_link_state */
#define DP_REG_LCNT             0x21d       /* bits 0..4: the value FUN_a00ad38c writes (| 0x80) and prints as 'NTL LCnt' */
#define DP_REG_LCNT_MASK        0x1f
#define DP_REG_21E              0x21e       /* bits 6..7 = 2 sets paged register 0x499 */
#define DP_REG_TEST_REQUEST     0x256       /* bit 7 set: 'DPCD 270 start phy test' */
#define DP_REG_TEST_START       0x80
#define DP_REG_2B8              0x2b8       /* takes the value of 0x2b9 / 0x2ba / 0x2bb, by the test request */

/* Values for FUN_a00ad38c (dp_set_port_setting_11e, CONV2HDMITX_UpdateInterface_2). */
#define LCNT_1                  1
#define LCNT_2                  2
#define LCNT_4                  4

/* Time limits in ticks. */
#define CHECK_TICKS             5000        /* the check ends this long after it started */
#define HOLD_TICKS              1500        /* no step this long after the 0x9344 stamp */
#define UNTRAINED_TICKS         600         /* not trained this long: back to LCNT_1 */
#define FIFO_TICKS              1500        /* 'register 0x44' stamp older than this: next value */

#define CHIP_REV_80             0x80        /* sys_get_chip_revision */

extern unsigned char dp_map_port(unsigned char);
extern void dp_handle_block_event(unsigned char);
extern unsigned int dp_reg_read8(unsigned char, unsigned short);
extern void dp_reg_write8(unsigned char, unsigned short, unsigned char);
extern void dp_reg_update_bits(unsigned char, unsigned short, unsigned char, unsigned char);
extern void dp_paged_reg_write8(unsigned char, unsigned short, unsigned char);
extern unsigned char dp_get_reg461_bit0(unsigned char);
extern void dp_copy_tx_readings_to_rx(unsigned char);
extern void dp_api_pulse_reg30e_clear(unsigned char);
extern unsigned int timer_get_ticks(void);
extern unsigned char dp_get_port_pending_bit(unsigned char);
extern void dp_clear_port_pending_bit(unsigned char);
extern unsigned char dp_is_link_trained(unsigned char);
extern unsigned char dp_is_reg44_low_bits_set(unsigned char);
extern void dp_set_port_setting_11e(unsigned char, unsigned char);     /* dp_set_port_setting_11e */
extern int dbg_print_string(const char *);
extern unsigned int dp_paged_reg_read8(unsigned char, unsigned short);
extern unsigned char sys_get_chip_revision(void);
extern void timer_delay_long_units(unsigned short);

/*
 * Service one DP receiver once. Called by input_poll_port_services every main-loop pass, for port 0 and 1.
 *
 *   port  DP receiver; dp_map_port gives its register block (the two can be swapped)
 *
 * Phases, in order:
 *   1. While byte 0x11f of the input record is 1, a new block event goes to dp_handle_block_event (once, until
 *      dp_run_link_state clears dp_block_event_handled_flags). Paged register 0x499 = 1 while bits 6..7 of register 0x21E
 *      are 2, else 0. With byte 0x11f = 1 and bit 0 of register 0x461 set, dp_copy_tx_readings_to_rx runs;
 *      otherwise register 0xD6 = 0x86. Ports above 1 stop here.
 *   2. Setting: byte 0x129 of the input record when byte 0x128 is set, else byte 0x125. When it changes,
 *      register 0x30E is cleared (dp_api_pulse_reg30e_clear); a change to 1 starts the LCnt check and all four
 *      time stamps, any other change stops it.
 *   3. LCnt check (the value in register 0x21D that FUN_a00ad38c writes and prints as 'NTL LCnt'), while it
 *      runs: it ends CHECK_TICKS after it started. The pending bit of the port (dp_get_port_pending_bit)
 *      stops it and is cleared. A trained link (dp_is_link_trained returns 1) refreshes the 'trained'
 *      stamp, and also the 'register 0x44' stamp while register 0x44 bits 0..1 are clear. Once HOLD_TICKS
 *      have passed since the 0x9344 stamp: a 'trained' stamp older than UNTRAINED_TICKS gives LCnt 1;
 *      otherwise a 'register 0x44' stamp older than FIFO_TICKS steps LCnt from 1 to 2 or from 2 to 4. Every step
 *      restarts both stamps.
 *   4. Test start: when register 0x256 has bit 7 set and differs from the last value kept, print
 *      'DPCD 270 start phy test', keep the new value and set up the paged registers of the receiver block.
 *      The value 0x80 / 0x90 / 0xA0 / 0xB0 selects bit pair 0..1 / 2..3 / 4..5 / 6..7 of paged register
 *      0xAB, which goes into bits 1..2 of paged register 2 (with bit 7). On chip revision 0x80 and below,
 *      register 0x21D = 0x84 and paged register 0x403 = 0x80 are written first, between register 0xC0 = 0
 *      and 0x80.
 *   5. While the kept value has bit 7 set: for 0x90 / 0xA0 / 0xB0 copy register 0x2B9 / 0x2BA / 0x2BB into
 *      0x2B8 when they differ, with register 0x30 bit 7 set during the write.
 */
void dp_port_task(port)
    unsigned char port;
{
    unsigned char block, block_again, setting, field;
    unsigned int test_request, paged_ab;
    unsigned int changed;

    /* Phase 1. */
    block = dp_map_port(port);
    if (dp_input_records[port].byte_0x11f == 1 && dp_block_event_handled_flags[port] == 0)
        dp_handle_block_event(port);
    if ((dp_reg_read8(port, DP_REG_21E) & 0xc0) == 0x80)
        dp_paged_reg_write8(block, 0x499, 1);
    else
        dp_paged_reg_write8(block, 0x499, 0);
    if (dp_input_records[port].byte_0x11f == 1 && dp_get_reg461_bit0(port))
        dp_copy_tx_readings_to_rx(port);
    else
        dp_reg_write8(port, 0xd6, 0x86);
    if (port > LAST_DP_RECEIVER)
        return;

    /* Phase 2. */
    if (dp_input_records[port].byte_0x128)
        setting = dp_input_records[port].byte_0x129;
    else
        setting = dp_input_records[port].byte_0x125;
    if (dp_lcnt_check_settings[port] != setting) {
        dp_api_pulse_reg30e_clear(port);
        if (setting == 1) {
            dp_lcnt_check_running_flags[port] = 1;
            dp_lcnt_check_start_ticks[port] = timer_get_ticks();
            dp_lcnt_check_hold_ticks[port] = timer_get_ticks();
            dp_lcnt_check_trained_ticks[port] = timer_get_ticks();
            dp_lcnt_check_reg44_clear_ticks[port] = timer_get_ticks();
        } else {
            dp_lcnt_check_running_flags[port] = 0;
        }
        dp_lcnt_check_settings[port] = setting;
    }

    /* Phase 3. */
    if (timer_get_ticks() - dp_lcnt_check_start_ticks[port] > CHECK_TICKS && dp_lcnt_check_running_flags[port] == 1)
        dp_lcnt_check_running_flags[port] = 0;
    if (dp_get_port_pending_bit(port) == 1) {
        dp_lcnt_check_running_flags[port] = 0;
        dp_lcnt_check_hold_ticks[port] = timer_get_ticks();
        dp_clear_port_pending_bit(port);
    }
    if (dp_lcnt_check_running_flags[port] == 1) {
        if (dp_is_link_trained(port) == 1) {
            dp_lcnt_check_trained_ticks[port] = timer_get_ticks();
            if (!dp_is_reg44_low_bits_set(port))
                dp_lcnt_check_reg44_clear_ticks[port] = timer_get_ticks();
        }
    }
    if (dp_lcnt_check_running_flags[port] == 1) {
        if (timer_get_ticks() - dp_lcnt_check_hold_ticks[port] > HOLD_TICKS) {
            if (timer_get_ticks() - dp_lcnt_check_trained_ticks[port] > UNTRAINED_TICKS) {
                dp_set_port_setting_11e(port, LCNT_1);
                dp_lcnt_check_trained_ticks[port] = timer_get_ticks();
                dp_lcnt_check_reg44_clear_ticks[port] = timer_get_ticks();
            } else if (timer_get_ticks() - dp_lcnt_check_reg44_clear_ticks[port] > FIFO_TICKS) {
                if ((dp_reg_read8(port, DP_REG_LCNT) & DP_REG_LCNT_MASK) == LCNT_1) {
                    dp_set_port_setting_11e(port, LCNT_2);
                    dp_lcnt_check_trained_ticks[port] = timer_get_ticks();
                    dp_lcnt_check_reg44_clear_ticks[port] = timer_get_ticks();
                } else if ((dp_reg_read8(port, DP_REG_LCNT) & DP_REG_LCNT_MASK) == LCNT_2) {
                    dp_set_port_setting_11e(port, LCNT_4);
                    dp_lcnt_check_trained_ticks[port] = timer_get_ticks();
                    dp_lcnt_check_reg44_clear_ticks[port] = timer_get_ticks();
                }
            }
        }
    }

    /* Phase 4. */
    test_request = dp_reg_read8(port, DP_REG_TEST_REQUEST);
    field = 0;
    changed = (unsigned char)dp_last_phy_test_requests[port] != (unsigned char)test_request;
    if ((test_request >> 7) & changed) {
        dbg_print_string("DPCD 270 start phy test\r");
        dp_last_phy_test_requests[port] = dp_reg_read8(port, DP_REG_TEST_REQUEST);
        block_again = dp_map_port(port);
        paged_ab = dp_paged_reg_read8(block_again, 0xab);
        switch ((unsigned char)dp_last_phy_test_requests[port]) {
        case 0x80:
            field = paged_ab & 3;
            break;
        case 0x90:
            field = (paged_ab & 0xc) >> 2;
            break;
        case 0xa0:
            field = (paged_ab & 0x30) >> 4;
            break;
        case 0xb0:
            field = (paged_ab & 0xc0) >> 6;
            break;
        }
        if (sys_get_chip_revision() <= CHIP_REV_80) {
            dp_reg_write8(port, DP_REG_LCNT, 0x84);
            dp_reg_write8(port, 0xc0, 0);
            dp_paged_reg_write8(block_again, 0x403, 0x80);
            dp_reg_write8(port, 0xc0, 0x80);
        }
        timer_delay_long_units(5);
        dp_paged_reg_write8(block_again, 0x47d, 0);
        dp_paged_reg_write8(block_again, 0x525, 0);
        dp_paged_reg_write8(block_again, 0x625, 0);
        dp_paged_reg_write8(block_again, 0x725, 0);
        dp_paged_reg_write8(block_again, 0x825, 0);
        dp_paged_reg_write8(block_again, 0x469, 0x2d);
        dp_paged_reg_write8(block_again, 3, 0x90);
        dp_paged_reg_write8(block_again, 0x43, 0xf0);
        dp_paged_reg_write8(block_again, 0x471, 0xf0);
        dp_paged_reg_write8(block_again, 2, (field << 1) | 0x80);
        dp_paged_reg_write8(block_again, 0x470, 0);
        dp_paged_reg_write8(block_again, 0x510, 1);
        dp_paged_reg_write8(block_again, 0x610, 1);
        dp_paged_reg_write8(block_again, 0x710, 1);
        dp_paged_reg_write8(block_again, 0x810, 1);
    }

    /* Phase 5. */
    if (dp_last_phy_test_requests[port] < 0) {
        switch ((unsigned char)dp_last_phy_test_requests[port]) {
        case 0x80:
            setting = dp_reg_read8(port, DP_REG_2B8);
            break;
        case 0x90:
            if ((unsigned char)dp_reg_read8(port, 0x2b9) != (unsigned char)dp_reg_read8(port, 0x2b8)) {
                dp_reg_update_bits(port, 0x30, 0x80, 1);
                dp_reg_write8(port, 0x2b8, dp_reg_read8(port, 0x2b9));
                dp_reg_update_bits(port, 0x30, 0x80, 0);
            }
            break;
        case 0xa0:
            if ((unsigned char)dp_reg_read8(port, 0x2ba) != (unsigned char)dp_reg_read8(port, 0x2b8)) {
                dp_reg_update_bits(port, 0x30, 0x80, 1);
                dp_reg_write8(port, 0x2b8, dp_reg_read8(port, 0x2ba));
                dp_reg_update_bits(port, 0x30, 0x80, 0);
            }
            break;
        case 0xb0:
            if ((unsigned char)dp_reg_read8(port, 0x2bb) != (unsigned char)dp_reg_read8(port, 0x2b8)) {
                dp_reg_update_bits(port, 0x30, 0x80, 1);
                dp_reg_write8(port, 0x2b8, dp_reg_read8(port, 0x2bb));
                dp_reg_update_bits(port, 0x30, 0x80, 0);
            }
            break;
        }
    }
}
