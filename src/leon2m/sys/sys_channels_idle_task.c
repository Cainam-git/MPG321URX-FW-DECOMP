/* sys_channels_idle_task  (FUN_a012f7a8)
 *
 * Step the port code of each enabled channel in port state 2 or 5, by group and time limit.
 * Note: Also keeps the port's time stamps and countdown (sys_set_channel_port does the step).
 * Name basis: descriptive - per channel with bit 24 set: tick stamp, or a countdown for port states 2 and 5
 *
 * Matching notes
 * --------------
 * leon2m FUN_a012f7a8 @ 0xa012f7a8-0xa012fc04 (1116 bytes), flags -mcpu=v8 -O3 -g -msoft-float.
 * Source forms the exact build depends on:
 *  - find_source_code_index and next_source_code_same_group are input_find_source_code_index (input_find_source_code_index) and
 *    input_next_source_code_same_group (input_next_source_code_same_group) inlined (int result); the helpers take the port record as
 *    a byte pointer and read the code as p[10];
 *  - the time test is 'if (elapsed < time_limit || flag_23 == 1) { same-group path } else { other-group path }'
 *    (tests at 0xa012f884 and 0xa012f898; the second path at 0xa012fa74 reads the port through the loop top's
 *    offset and base registers);
 *  - the countdown test is 'if (countdown != 0) countdown--; else { .. }' (0xa012f7d4);
 *  - first_source_code_other_group's fallback stores next_source_code_same_group's result in an unsigned char
 *    before returning it ('and 0xff' at 0xa012f9cc and 0xa012f9d4, none on the found path 0xa012fba0);
 *  - after the first time read the port record pointer is taken again, and the time stamps are written through
 *    port_records[...] instead of the pointer.
 */

/* The channel record (0x78 bytes): the first word and the flag word at +0x70. */
struct channel_record {
    union {
        unsigned int word;
        struct {
            unsigned int state : 4;             /* bits 28..31 */
            unsigned int bits_24 : 4, bits_20 : 4, bits_16 : 4;
            unsigned int port : 4;              /* bits 12..15 */
            unsigned int receiver_index : 4;    /* bits 8..11 */
            unsigned int bits_4 : 4;
            unsigned int path : 3;              /* bits 1..3 */
            unsigned int bit0 : 1;
        } f;
    } status_word;                              /* +0 */
    unsigned char pad04[0x70 - 0x04];
    union {
        unsigned int word;
        struct {
            unsigned int bits_25 : 7;
            unsigned int enabled : 1;           /* bit 24: written by sys_set_channel_enable */
            unsigned int flag_23 : 1;           /* bit 23 */
            unsigned int bits_0 : 23;
        } f;
    } flags;                                    /* +0x70 */
    unsigned char pad74[0x78 - 0x74];
};
/* The port record (0x2A bytes). */
struct port_record {
    unsigned char byte_0x00, byte_0x01;
    unsigned char state;                        /* +2 */
    unsigned char pad03[7];
    unsigned char port_code;                    /* +0xA: called the port's mode by input_set_port_mode */
    unsigned char pad0b[3];
    unsigned char countdown;                    /* +0xE: counted down here, one per call */
    unsigned char byte_0x0f;
    unsigned short half_0x10;                   /* +0x10: used here as a time limit in ticks */
    unsigned short time_stamp;                  /* +0x12 */
    unsigned short time_stamp_2;                /* +0x14 */
    unsigned char rest[0x2a - 0x16];
};
/* A port entry (0x12 bytes). */
struct port_entry { unsigned char pad00[0x10]; unsigned char bus_id; unsigned char byte_0x11; };

extern struct channel_record channel_records[4];
extern struct port_record port_records[];
extern struct port_entry port_entries[];
extern const unsigned char input_source_code_table[4];
extern unsigned int sys_config;
extern void (*sys_callback_table_slot7)(int, int);
extern unsigned short timer_get_ticks16(void);
extern unsigned short timer_ticks_since(unsigned short start);
extern unsigned char input_port_id_to_entry_index(unsigned char port_code);
extern unsigned char input_port_table_get_code(unsigned char bus_id);
extern void sys_set_channel_port(unsigned char channel, unsigned char port_code, unsigned char force);

#define LAST_CHANNEL        3
#define SOURCE_CODES        4                   /* entries of input_source_code_table */
#define SOURCE_GROUP_MASK   0xfc                /* bits 2..7 of a source code give its group */
#define NOT_FOUND           0xff
#define PORT_STATE_2        2                   /* the two port states that count down and switch codes */
#define PORT_STATE_5        5
#define SAME_GROUP_TICKS    0x50                /* ticks between two steps within the same group */
#define SYS_CONFIG_BIT21    0x200000            /* channel 3 follows channel 0's code */
#define SECOND_CHANNEL      3

/* Index of a code in input_source_code_table, or 0xFF. */
static inline unsigned char find_source_code_index(unsigned char c)
{
    unsigned char i;
    for (i = 0; i < SOURCE_CODES; i++) {
        unsigned char v = input_source_code_table[i];
        if (c == v)
            return i;
    }
    return NOT_FOUND;
}

/* The next table entry after the port's code, wrapping round, in the same group (the code itself when no other
   entry is in its group). */
static inline int next_source_code_same_group(const unsigned char *p)
{
    unsigned char i = find_source_code_index(p[10]);
    unsigned char j;
    unsigned int k;
    for (j = 1; j <= 4; j++) {
        k = (i + j) & 3;
        if ((input_source_code_table[k] & SOURCE_GROUP_MASK) == (input_source_code_table[i] & SOURCE_GROUP_MASK))
            return k;
    }
    return i;
}

/* The next table entry after the port's code in another group whose port entry exists and whose input has a
   code in the port table; else next_source_code_same_group. */
static inline int first_source_code_other_group(const unsigned char *p)
{
    unsigned char i = find_source_code_index(p[10]);
    unsigned char j, r;
    unsigned int k;
    for (j = 1; j <= 4; j++) {
        k = (i + j) & 3;
        if ((input_source_code_table[k] & SOURCE_GROUP_MASK) != (input_source_code_table[i] & SOURCE_GROUP_MASK)) {
            r = input_port_id_to_entry_index(input_source_code_table[k]);
            if (r == NOT_FOUND)
                continue;
            if (input_port_table_get_code(port_entries[r].bus_id) == NOT_FOUND)
                continue;
            return k;
        }
    }
    r = next_source_code_same_group(p);
    return r;
}

/*
 * One pass over the four channels: step the port codes of enabled channels whose port is in state 2 or 5.
 *
 * Called from GlobalModeHandler on every run.
 *
 * Phases, for each enabled channel (flag bit 24) and its port record:
 *  1. Port state other than 2 and 5: stamp time_stamp with the current tick and go on.
 *  2. State 2 or 5 with a countdown above 0: count it down by one and go on.
 *  3. Once half_0x10 ticks have passed since time_stamp and flag bit 23 is clear: give the channel the first
 *     code of another group (first_source_code_other_group), restart both time stamps and call the callback in
 *     sys_callback_table_slot7 with (0, 0) when one is set.
 *  4. Otherwise, once more than 0x50 ticks have passed since time_stamp_2: give the channel the next code of
 *     the same group and restart time_stamp_2.
 * In 3 and 4, when the channel is 0 and bit 21 of sys_config is set, channel 3 gets the same code.
 */
void sys_channels_idle_task(void)
{
    unsigned char channel, port_code, index;
    unsigned short elapsed, time_limit;
    struct channel_record *record;
    struct port_record *port;

    for (channel = 0; channel <= LAST_CHANNEL; channel++) {
        record = &channel_records[channel];
        if (record->flags.f.enabled) {
            port = &port_records[record->status_word.f.port];
            if (port->state == PORT_STATE_2 || port->state == PORT_STATE_5) {
                /* 2. */
                if (port->countdown != 0)
                    port->countdown--;
                else {
                    elapsed = timer_ticks_since(port->time_stamp);
                    port = &port_records[record->status_word.f.port];
                    time_limit = port->half_0x10;
                    if (elapsed < time_limit || record->flags.f.flag_23 == 1) {
                        /* 4. Step within the same group. */
                        if (timer_ticks_since(port->time_stamp_2) > SAME_GROUP_TICKS) {
                            port = &port_records[record->status_word.f.port];
                            index = next_source_code_same_group((const unsigned char *)port);
                            port_code = input_source_code_table[index];
                            sys_set_channel_port(channel, port_code, 0);
                            port_records[record->status_word.f.port].time_stamp_2 = timer_get_ticks16();
                            if (channel == 0 && (sys_config & SYS_CONFIG_BIT21))
                                sys_set_channel_port(SECOND_CHANNEL, port_code, 0);
                        }
                    } else {
                        /* 3. Time is up: change to another group. */
                        index = first_source_code_other_group((const unsigned char *)port);
                        port_code = input_source_code_table[index];
                        sys_set_channel_port(channel, port_code, 0);
                        port_records[record->status_word.f.port].time_stamp = timer_get_ticks16();
                        port_records[record->status_word.f.port].time_stamp_2 = timer_get_ticks16();
                        if (sys_callback_table_slot7 != 0)
                            sys_callback_table_slot7(0, 0);
                        if (channel == 0 && (sys_config & SYS_CONFIG_BIT21))
                            sys_set_channel_port(SECOND_CHANNEL, port_code, 0);
                    }
                }
            } else
                /* 1. */
                port->time_stamp = timer_get_ticks16();
        }
    }
}
