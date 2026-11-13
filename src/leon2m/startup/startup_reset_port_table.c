/* startup_reset_port_table  (FUN_a01427d4)
 *
 * Reset the eight-entry port table.
 * Name basis: derived - called from start-up
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01427d4 @ 0xa01427d4, flags -mcpu=v8 -O3 -g.
 * Source form: b9 (the byte at +9) is written before the state (gcc schedules them reversed); bits 12 and 4 of
 * halfword 0 are 1-bit fields (two 'and's on one load / store); the loop counters are u8 (the 'and 0xff'
 * compares); the table is indexed by i (smul 42).
 */

#define PORT_RECORD_COUNT 8         /* records of port_records */
#define PORT_STATE_IDLE   1         /* idle state */
#define PORT_STATE_SEARCH 2         /* state in which the sync state machine of input_port_sync_task starts to look for a signal */

/* One port record (0x2A bytes, docs/DATA.md): status bits in halfword 0, state at +2, type at +9. */
struct port_record {
    unsigned short bits_15_13:3, bit_12:1, bits_11_5:7, bit_4:1, bits_3_0:4;    /* +0 */
    unsigned char state;                /* +2 */
    unsigned char byte_3;               /* +3 */
    unsigned char pad4[5];
    unsigned char type;                 /* +9: set to 1 here */
    unsigned char mode;                 /* +0xA */
    unsigned char port_number;          /* +0xB */
    unsigned char rest[30];
};
extern struct port_record port_records[];

/*
 * Reset the eight port records at power-on: the port number (+0xB) of record i becomes i, state becomes 1, +9
 * becomes 1, and bits 12 and 4 of the status halfword are cleared. Then the records 0..3 get state 2 (the state
 * in which input_port_sync_task's sync state machine starts looking for a signal). RAM only; it cannot fail or wait.
 * Called by the system start-up (startup_bring_up_system, phase 5).
 */
void startup_reset_port_table(void)
{
    unsigned char i;
    for (i = 0; i < PORT_RECORD_COUNT; i++) {
        port_records[i].port_number = i;
        port_records[i].type = 1;
        port_records[i].state = PORT_STATE_IDLE;
        port_records[i].bit_12 = 0;
        port_records[i].bit_4 = 0;
    }
    for (i = 0; i < 4; i++)
        port_records[i].state = PORT_STATE_SEARCH;
}
