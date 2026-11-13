/* input_port_sync_task  (FUN_a0142910)
 *
 * Run the per-port sync state machine and update the port status.
 * Name basis: proven - prints 'Go To SYNC_WAIT_STABLE', 'Go To SYNC_IS_STABLE2' and 'Exit SYNC_IS_STABLE';
 *   called from the main-loop task
 *
 * Matching notes
 * --------------
 * leon2m FUN_a0142910 @ 0xa0142910, flags -mcpu=v8 -O3 -g -msoft-float.
 * Source form: every port field is reached through the pointer p (the bit-fields too). The place of CLEAR_TIMING
 *   next to 'state = 2' and 'sync_lost = 1' is as written (gcc 3.4's first scheduling pass puts the last
 *   statement of a block first, which gives the firmware's order). Case 4 is written 'if (class != 5) {reset}
 *   else {...}' (it only changes the block order before layout, which drives the register choice of
 *   -frename-registers). The sync-mode choice for ports 6 / 7 and the register 0x1A write are if/else, not ?:.
 */

/* One port entry (0x12 bytes): the input as the control logic sees it. */
struct port_entry {
    unsigned short port_class:4;                /* +0 bits 12..15 */
    unsigned short bit11:1, bit10:1, bit9:1, bit8:1, bit7:1, bit6:1, bit5:1, bit4:1, bit3:1, bit2:1, bit1:1, bit0:1;
    unsigned short half2_bit15:1, half2_bits6_14:9, half2_bit5:1, half2_bits0_4:5;   /* +2 */
    unsigned char format_code, byte_0x05;       /* +4: copied to the port record's format_code */
    unsigned short half_0x06, half_0x08, half_0x0a, half_0x0c, half_0x0e;
    unsigned short bus_id;                      /* +0x10 */
};

/* One port record (0x2A bytes). */
struct port_record {
    unsigned short bit15:1, bit14:1, bit13:1, sync_lost:1, bit11:1, bit10:1, bit9:1, bit8:1, bit7:1, bit6:1,
                   bit5:1, low_bits:5;          /* +0: status halfword; bit 12 = sync lost */
    unsigned char state;                        /* +0x02: enum port_sync_state */
    unsigned char port_class;                   /* +0x03: class of the port entry */
    unsigned short half_0x04;                   /* +0x04 */
    unsigned short wait_start;                  /* +0x06: tick stamp when SYNC_WAIT_STABLE was entered */
    unsigned char previous_sync_mode;           /* +0x08: the sync mode SYNC_WAIT_STABLE started with */
    unsigned char sync_mode;                    /* +0x09: 1 = none recognised, 2..5 */
    unsigned char port_code;                    /* +0x0A */
    unsigned char block;                        /* +0x0B: input block read for entry 6 */
    unsigned char pad0c[6];
    unsigned short time_stamp;                  /* +0x12 */
    unsigned short half_0x14, half_0x16, half_0x18, half_0x1a, half_0x1c;
    unsigned short line_rate, refresh_rate;     /* +0x1E: 100 Hz units; +0x20: tenths of a hertz */
    unsigned char register_0x22, register_0x23, pixel_repeat, pad25;   /* +0x22..+0x24 */
    unsigned short pixel_clock_value;           /* +0x26 */
    unsigned char format_code, pad29;           /* +0x28 */
};
extern struct port_entry port_entries[];
extern struct port_record port_records[];
extern unsigned char input_port_id_to_entry_index(unsigned char);
extern void input_block_clear_flags_1e_1f(unsigned char);
extern unsigned char input_block_handle_mode_change(unsigned char, unsigned char, unsigned char);
extern unsigned short input_block_read_reg95_word(unsigned char), input_block_read_reg97_word(unsigned char), input_block_read_reg8f_word(unsigned char);
extern short input_block_read_13bit_count(unsigned char);
extern unsigned char input_block_get_signal_code(unsigned char);
extern void input_fill_port_timing(struct port_record *, unsigned char);
extern void input_block_set_reg5c_bit2(unsigned char, unsigned char);
extern void input_block_write_reg1a(unsigned char, unsigned char);
extern unsigned short timer_get_ticks16(void);
extern unsigned short timer_ticks_since(unsigned short);
extern unsigned char dbg_is_print_enabled(unsigned int);
extern int dbg_printf();

/* Port states (port record +2). The SYNC_ names are the firmware's own debug texts. */
enum port_sync_state {
    PORT_STATE_IDLE = 1,                /* no port entry; sys_set_channel_enable moves it on to 2 */
    PORT_STATE_SEARCH = 2,              /* wait for a sync mode other than 1 */
    SYNC_WAIT_STABLE = 3,               /* wait for the sync mode to stay the same */
    SYNC_IS_STABLE = 4                  /* timing measured; the bring-up of a channel may use the port */
};

#define PORT_COUNT          4
#define NO_ENTRY            0xff        /* input_port_id_to_entry_index: the port code has no entry */
#define ENTRY_6             6           /* entry whose values come from the input block registers */
#define PORT_CLASS_5        5           /* the only class the state machine brings to SYNC_IS_STABLE */
#define SYNC_MODE_NONE      1           /* input_block_detect_sync_mode: no sync mode recognised */
#define SYNC_MODE_5         5
#define SIGNAL_CODE_B1      0xb1
#define STABLE_TICKS        100         /* the sync mode must stay the same this long */
#define DBG_PORT_SYNC       2           /* debug class of the messages here */

/* Clear the measured values of a port (a braced block of stores, used five times). */
#define CLEAR_TIMING(p) { (p)->half_0x04 = 0; (p)->half_0x16 = 0; (p)->half_0x18 = 0; (p)->half_0x1a = 0; \
    (p)->half_0x1c = 0; (p)->line_rate = 0; (p)->refresh_rate = 0; (p)->register_0x22 = 0; \
    (p)->register_0x23 = 0; (p)->pixel_repeat = 0; (p)->pixel_clock_value = 0; }

/*
 * One pass of the sync state machine over ports 0..3, called on every pass of sys_main_loop_periodic_task (after
 * input_refresh_port_entries, before input_channel_bring_up_task). Port state 4 (SYNC_IS_STABLE) without the
 * sync-lost bit is what input_channel_bring_up_task waits for.
 *
 * For each port:
 * 1. PORT_STATE_IDLE: sync mode 1, the flag registers 0x1E / 0x1F of the block cleared, nothing more.
 * 2. Find the port's entry from its port code; with none the port goes to PORT_STATE_IDLE.
 * 3. Copy from the entry. Entry 6: class 5, the values +0x1A / +0x1C / +0x16 / +0x18 read from registers 0x95,
 *    0x97, 0x8F and the 13-bit count of the port's input block, status bits 15 and 14 cleared. Other entries: the
 *    entry's class, and for class 5 also the four values from entry +6 / +8 / +0xA / +0xC, the format code and
 *    status bits 15, 14, 13, 11, 10, 9, 8, 6, 7 and 5 from entry bits 10, 9, 8, 5, 4, 3, 2, 1, 0 and +2 bit 15.
 *    A port of another class keeps its old status bits.
 * 4. The sync mode: input_block_handle_mode_change(port, line rate, last sync mode).
 * 5. The state:
 *    PORT_STATE_SEARCH  bit 2 of register 0x5C cleared and register 0x1A written (0xB0 when entry +2 bit 5 is set,
 *                       else 4) on every pass; a class-5 port with a sync mode other than 1 stamps both time
 *                       fields, keeps the mode and goes to SYNC_WAIT_STABLE.
 *    SYNC_WAIT_STABLE   back to the search when the sync mode changes or is 1; mode 2..5 unchanged for more
 *                       than STABLE_TICKS: input_fill_port_timing measures the timing, then SYNC_IS_STABLE.
 *    SYNC_IS_STABLE     input_fill_port_timing on every pass while the sync mode is not 1. Sync mode 1: back to
 *                       the search with a new stamp, the values cleared and the sync-lost bit set ("Exit
 *                       SYNC_IS_STABLE"); input_channel_bring_up_task clears that bit when it takes the port again.
 *    In both waiting states a port that is not class 5 is cleared and goes back to the search (from
 *    SYNC_IS_STABLE with the sync-lost bit set). A port with status bit 11 whose signal code is not 0xB1 is
 *    cleared and goes back to the search too, without the sync-lost bit.
 */
void input_port_sync_task(void)
{
    unsigned char i, k;
    struct port_record *p;
    struct port_entry *e;

    for (i = 0; i < PORT_COUNT; i++) {
        p = &port_records[i];
        if (p->state == PORT_STATE_IDLE) {
            p->sync_mode = SYNC_MODE_NONE;
            input_block_clear_flags_1e_1f(i);
            continue;
        }
        k = input_port_id_to_entry_index(p->port_code);
        if (k == NO_ENTRY) {
            p->state = PORT_STATE_IDLE;
            continue;
        }
        if (k == ENTRY_6) {
            p->port_class = PORT_CLASS_5;
            p->half_0x1a = input_block_read_reg95_word(p->block);
            p->half_0x1c = input_block_read_reg97_word(p->block);
            p->half_0x16 = input_block_read_reg8f_word(p->block);
            p->half_0x18 = input_block_read_13bit_count(p->block);
            p->bit15 = 0;
            p->bit14 = 0;
        } else {
            p->port_class = port_entries[k].port_class;
            if (port_entries[k].port_class == PORT_CLASS_5) {
                e = &port_entries[k];
                p->half_0x1a = e->half_0x06;
                p->half_0x1c = e->half_0x08;
                p->half_0x16 = e->half_0x0a;
                p->half_0x18 = e->half_0x0c;
                p->bit15 = e->bit10;
                p->bit14 = e->bit9;
                p->bit13 = e->bit8;
                p->port_class = e->port_class;
                p->format_code = e->format_code;
                p->bit11 = e->bit5;
                p->bit10 = e->bit4;
                p->bit9 = e->bit3;
                p->bit8 = e->bit2;
                p->bit6 = e->bit1;
                p->bit7 = e->bit0;
                p->bit5 = e->half2_bit15;
            }
        }
        /* The arm for ports 6 and 7 never runs: i is 0..3 here. */
        if ((i == 6 || i == 7) && p->bit11)
            if (p->port_class == PORT_CLASS_5) p->sync_mode = SYNC_MODE_5; else p->sync_mode = SYNC_MODE_NONE;
        else
            p->sync_mode = input_block_handle_mode_change(i, p->line_rate, p->sync_mode);
        switch (p->state) {
        case PORT_STATE_SEARCH:
            input_block_set_reg5c_bit2(i, 0);
            if (port_entries[k].half2_bit5)
                input_block_write_reg1a(i, 0xb0);
            else
                input_block_write_reg1a(i, 4);
            if (p->sync_mode != SYNC_MODE_NONE && p->port_class == PORT_CLASS_5) {
                p->wait_start = timer_get_ticks16();
                p->time_stamp = timer_get_ticks16();
                p->state = SYNC_WAIT_STABLE;
                p->previous_sync_mode = p->sync_mode;
                if (dbg_is_print_enabled(DBG_PORT_SYNC))
                    dbg_printf("Go To SYNC_WAIT_STABLE(%d, %d)\r\n", i, p->wait_start);
            }
            break;
        case SYNC_WAIT_STABLE:
            if (p->port_class == PORT_CLASS_5) {
                if (p->bit11 && input_block_get_signal_code(i) != SIGNAL_CODE_B1 && i <= 3) {
                    CLEAR_TIMING(p);
                    p->state = PORT_STATE_SEARCH;
                } else if (p->previous_sync_mode != p->sync_mode) {
                    /* The mode changed while waiting: start again. */
                    p->previous_sync_mode = p->sync_mode;
                    p->state = PORT_STATE_SEARCH;
                } else {
                    switch (p->previous_sync_mode) {
                    case SYNC_MODE_NONE:
                        p->previous_sync_mode = p->sync_mode;
                        p->state = PORT_STATE_SEARCH;
                        break;
                    case 2: case 3: case 4: case 5:
                        if (timer_ticks_since(p->wait_start) > STABLE_TICKS) {
                            input_fill_port_timing(p, i);
                            p->state = SYNC_IS_STABLE;
                            if (dbg_is_print_enabled(DBG_PORT_SYNC))
                                dbg_printf("Go To SYNC_IS_STABLE2 (%d)\r\n", i);
                        }
                        break;
                    }
                }
            } else {
                CLEAR_TIMING(p);
                p->state = PORT_STATE_SEARCH;
            }
            break;
        case SYNC_IS_STABLE:
            if (p->port_class != PORT_CLASS_5) {
                CLEAR_TIMING(p);
                p->state = PORT_STATE_SEARCH;
                p->sync_lost = 1;
            } else {
                if (p->bit11 && input_block_get_signal_code(i) != SIGNAL_CODE_B1 && i <= 3) {
                    CLEAR_TIMING(p);
                    p->state = PORT_STATE_SEARCH;
                } else if (p->sync_mode == SYNC_MODE_NONE) {
                    /* Sync lost: back to the search and mark the port for the channel bring-up. */
                    p->previous_sync_mode = p->sync_mode;
                    p->state = PORT_STATE_SEARCH;
                    p->wait_start = timer_get_ticks16();
                    CLEAR_TIMING(p);
                    p->sync_lost = 1;
                    if (dbg_is_print_enabled(DBG_PORT_SYNC))
                        dbg_printf("Exit SYNC_IS_STABLE (%d)\r\n", i);
                } else {
                    /* Still stable: measure again. */
                    input_fill_port_timing(p, i);
                }
            }
            break;
        }
    }
}
