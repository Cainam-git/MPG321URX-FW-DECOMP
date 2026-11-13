/* dp_mst_update_payload_table  (FUN_a00dae90)
 *
 * Read the payload table, list each stream's id, start and count, pass one change to the output.
 *   payload_id: id of the payload the request is about
 *   remove: 1 = take the id out
 *   clear: 1 = clear the whole table
 * Returns: 1 = done, 0 = a write to the output failed
 * Name basis: derived - 63-byte table collected into up to four runs of equal ids, printed 'ID : %d, Start :
 *   %d, Count : %d'; 3-byte record written to sink address 0x1C0
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00dae90 @ 0xa00dae90-0xa00db53c (1708 bytes), flags -mcpu=v8 -Os -g -msoft-float.
 * dbg_print_string, dbg_printf, dp_mst_read_payload_words, dp_tx_aux_request, dp_tx_aux_write_byte, lib_memset,
 * sys_return_zero and timer_delay_long_units are the labels func_0xa0f834c4, func_0xa0f83044, func_0xa0fc1394,
 * func_0xa0f963d4, func_0xa0f96360, func_0xa0fc15ac, func_0xa0f99e4c and func_0xa0fc1794.
 * Source forms the exact build depends on:
 *  - the scan loop reads the table byte into its own variable slot_id;
 *  - the table clear stores id, start, count in that order;
 *  - in the removal loop 'shift += count; removed id; removed start' in that order, and the moved entry is
 *    'id, start - shift, count';
 *  - each of the three record writes (clear, removal, per-entry loop) has its own print-and-return-0 arm, and
 *    all arms end at one 'return 1';
 *  - the results of sys_return_zero, dp_tx_aux_write_byte and dp_tx_aux_request are cast to unsigned char.
 */

/* The three entry tables, by the firmware's print "ID : %d, Start : %d, Count : %d". */
#define payload_ids                 dp_mst_payload_ids
#define payload_starts              dp_mst_payload_starts
#define payload_counts              dp_mst_payload_counts
/* Id and start of the entry taken out by the last removal; written to the output as {id, start, 0}. */
#define payload_removed_id          dp_mst_payload_removed_id
#define payload_removed_start       dp_mst_payload_removed_start

#define PAYLOAD_TABLE_BYTES         0x40    /* local copy; dp_mst_read_payload_words fills bytes 0..62 */
#define PAYLOAD_SCAN_BYTES          0x3f
#define PAYLOAD_ENTRIES             4       /* runs kept; a fifth different id ends the scan */
#define PAYLOAD_LAST_ENTRY          3

/* Words of the current port's MST register blocks (word index = byte offset / 4). */
#define MSG_WORD_0x258              (0x258 / 4)    /* bit 2 is waited for before the table is read */
#define MSG_0x258_WAIT_BIT          4
#define CTL_WORD_0xC0               (0xc0 / 4)     /* bit 7 is set while the table is read */
#define CTL_0xC0_READ_BIT           0x80
#define MSG_WORD_REMOVE_SELECT      (0x2ac / 4)    /* bits 6.. = number of the id to read, bits 0..5 kept */
#define MSG_REMOVE_SELECT_KEEP      0x3f
#define MSG_WORD_REMOVE_ID          (0x284 / 4)    /* the selected id ('Remove ID : %d') */

#define WAIT_TRIES                  0x13
#define WAIT_UNITS                  5       /* timer_delay_long_units per try */

#define DPTX_OUTPUT                 0       /* DP output 0 ('DPTX') */
#define AUX_CMD_WRITE               0x80
#define SINK_ADDR_0x2C0             0x2c0   /* 'Write 0x2C0h --> FALSE!' */
#define SINK_ADDR_0x1C0             0x1c0   /* 'Write 0x1C0h --> FALSE!' */
#define RECORD_LAST_BYTE            2       /* AUX length - 1: the 3-byte record {id, start, count} */
#define RECORD_CLEAR_COUNT          0x3f    /* count byte of the record written on a clear */

/* A record written to the output: rec[0] id, rec[1] start, rec[2] count. */
enum { RECORD_ID = 0, RECORD_START = 1, RECORD_COUNT = 2 };

extern unsigned char dp_mst_message_state_port;
extern unsigned char dp_mst_option_word;
extern unsigned char dp_mst_payload_removed_id;
extern unsigned char dp_mst_payload_removed_start;
extern unsigned char dp_mst_payload_counts[];
extern unsigned char dp_mst_payload_ids[];
extern unsigned char dp_mst_payload_starts[];
extern volatile unsigned int *dp_mst_msg_reg_blocks[];
extern volatile unsigned int *dp_mst_ctl_reg_blocks[];
extern const char DAT_9f1cca08[];   /* "\033[1;36mPLDtable:%s\r\n\033[m" */
extern const char DAT_9f1cca20[];   /* " " */
extern const char DAT_9f1cca28[];   /* "* " */
extern const char DAT_9f1cca38[];   /* "%s\r\n" */
extern const char DAT_9f1cca40[];   /* "*" */
extern const char DAT_9f1cca48[];   /* "Receive :\r\n\r" */
extern const char DAT_9f1cca58[];   /* "ID : %d, Start : %d, Count : %d\r\n" */
extern const char DAT_9f1cca80[];   /* "Remove ID : %d\r\n" */
extern const char DAT_9f1cca98[];   /* "Transform %d:\r\n" */
extern const char DAT_9f1ccaa8[];   /* "Write 0x2C0h --> FALSE!\r" */
extern const char DAT_9f1ccac8[];   /* "Write 0x1C0h --> FALSE!\r" */
extern void *lib_memset(void *, int, unsigned int);
extern void timer_delay_long_units(unsigned int);
extern int dp_mst_read_payload_words(int, unsigned char *);
extern int dbg_printf(const char *, ...);
extern void dbg_print_string(const char *);
extern int sys_return_zero(int);
extern int dp_tx_aux_write_byte(int, int, int, int);
extern int dp_tx_aux_request(int, int, int, int, unsigned char *);

/*
 * Bring the payload table of the current MST port (dp_mst_message_state_port) up to date and pass the change on
 * to DP output 0. Returns 1, or 0 when one of the AUX writes to the output fails.
 *
 *   payload_id  id of the payload the request is about (body byte 2 of an ALLOCATE_PAYLOAD request)
 *   remove      1: take the entry of payload_id out of the table
 *   clear       1: the whole table is cleared (request CLEAR_PAYLOAD_ID_TABLE); the table is not read
 *
 * Callers: dp_mst_forward_down_request with (id, 0, 0) for an ALLOCATE_PAYLOAD request whose body bytes 3 and 4
 * are not both 0, and with (0, 1, 1) for CLEAR_PAYLOAD_ID_TABLE; dp_mst_fetch_downstream_message with (id, 1, 0)
 * for an ALLOCATE_PAYLOAD message whose body bytes 3 and 4 are both 0.
 *
 * sys_return_zero always returns 0, so its tests below always take the 0 arm: starts are position + 1, the
 * "Remove ID" step and the "Transform" print always run.
 *
 * Phases, in order (1..4 only when clear is 0):
 *   1. Wait up to 19 x 5 delay units for bit 2 of message word 0x258, then read the 63 table bytes from the
 *      hardware (dp_mst_read_payload_words) with bit 7 of control word 0xC0 set. Print the table as 8 rows of 8.
 *   2. Collect the runs of equal non-zero bytes into at most four entries {id, start, count}, start = position
 *      + 1. A zero byte between two bytes of the same id does not end the run. When byte 0 is zero, entry 0
 *      stays empty and the first run goes into entry 1. Print the entries ("Receive :").
 *   3. For each of the dp_mst_option_word ids that the message block reports ("Remove ID"), set that entry's
 *      count to 0 and lower the start of every other used entry by the old count.
 *   4. With remove set: take the entry of payload_id out, keep its id and start in payload_removed_id /
 *      payload_removed_start, and move the later entries down with their starts lowered by its count. The
 *      tables are not cleared behind the moved entries.
 *   5. Print the entries again ("Transform 1:"); this print runs on a clear too.
 *   6. Write 1 to sink address 0x2C0 of output 0, then the 3-byte record to sink address 0x1C0:
 *      clear: {0, 0, 0x3F}; remove: {removed id, removed start, 0} (the stored values of an earlier removal
 *      when payload_id was not found); otherwise one record {id, start, count} for each entry of payload_id.
 */
unsigned char dp_mst_update_payload_table(unsigned char payload_id, unsigned char remove, unsigned char clear)
{
    unsigned char table[64];
    unsigned char record[3];
    unsigned char i;
    unsigned char j;
    unsigned char id;
    unsigned char shift;
    unsigned char entry_id;
    unsigned char slot_id;

    lib_memset(table, 0, PAYLOAD_TABLE_BYTES);
    if (clear == 0) {
        /* Phase 1: read the table from the hardware. */
        for (i = WAIT_TRIES; !(dp_mst_msg_reg_blocks[dp_mst_message_state_port][MSG_WORD_0x258] & MSG_0x258_WAIT_BIT) && i != 0; i--)
            timer_delay_long_units(WAIT_UNITS);
        dp_mst_ctl_reg_blocks[dp_mst_message_state_port][CTL_WORD_0xC0] |= CTL_0xC0_READ_BIT;
        dp_mst_read_payload_words(0, table);
        dp_mst_ctl_reg_blocks[dp_mst_message_state_port][CTL_WORD_0xC0] &= ~CTL_0xC0_READ_BIT;
        for (i = 0; i < PAYLOAD_ENTRIES; i++) {
            payload_ids[i] = 0;
            payload_starts[i] = 0;
            payload_counts[i] = 0;
        }
        dbg_printf(DAT_9f1cca08, DAT_9f1cca20);
        for (i = 0; i < 8; i++) {
            dbg_printf(DAT_9f1cca28);
            for (j = 0; j < 8; j++)
                dbg_printf("%02X ", table[i * 8 + j]);
            dbg_printf(DAT_9f1cca38, DAT_9f1cca40);
        }

        /* Phase 2: runs of equal ids; j is the entry being filled. */
        j = 0;
        for (i = 0; i < PAYLOAD_SCAN_BYTES; i++) {
            slot_id = table[i];
            if (slot_id != 0) {
                if (i == 0) {
                    payload_ids[j] = table[0];
                    if (table[0] != 0) {
                        if ((unsigned char)sys_return_zero(0) == 1)
                            payload_starts[j] = 0;
                        else
                            payload_starts[j] = 1;
                        payload_counts[j] = 1;
                    }
                } else if (slot_id == payload_ids[j]) {
                    payload_counts[j]++;
                } else {
                    /* A new id: next entry, unless all four are used. */
                    if (j + 1 > PAYLOAD_LAST_ENTRY)
                        break;
                    j++;
                    payload_ids[j] = slot_id;
                    if (slot_id != 0) {
                        if ((unsigned char)sys_return_zero(0) == 1)
                            payload_starts[j] = i;
                        else
                            payload_starts[j] = i + 1;
                        payload_counts[j] = 1;
                    }
                }
            }
        }
        dbg_print_string(DAT_9f1cca48);
        for (i = 0; i < PAYLOAD_ENTRIES; i++)
            dbg_printf(DAT_9f1cca58, payload_ids[i], payload_starts[i], payload_counts[i]);

        if ((unsigned char)sys_return_zero(0) == 0) {
            /* Phase 3: the ids the message block reports are dropped; the entries behind them close up. */
            for (j = 0; j < dp_mst_option_word; j++) {
                dp_mst_msg_reg_blocks[dp_mst_message_state_port][MSG_WORD_REMOVE_SELECT] =
                    (dp_mst_msg_reg_blocks[dp_mst_message_state_port][MSG_WORD_REMOVE_SELECT] & MSG_REMOVE_SELECT_KEEP) | (j << 6);
                id = dp_mst_msg_reg_blocks[dp_mst_message_state_port][MSG_WORD_REMOVE_ID];
                dbg_printf(DAT_9f1cca80, id);
                shift = 0;
                for (i = 0; i < PAYLOAD_ENTRIES; i++) {
                    if (payload_ids[i] == id) {
                        shift = payload_counts[i];
                        payload_counts[i] = 0;
                        break;
                    }
                }
                for (i = 0; i < PAYLOAD_ENTRIES; i++)
                    if (payload_ids[i] != 0 && payload_counts[i] != 0)
                        payload_starts[i] -= shift;
            }
            dp_mst_msg_reg_blocks[dp_mst_message_state_port][MSG_WORD_REMOVE_SELECT] &= MSG_REMOVE_SELECT_KEEP;

            if (remove) {
                /* Phase 4: take payload_id out; j is where the next kept entry goes. */
                shift = 0;
                j = 0;
                for (i = 0; i < PAYLOAD_ENTRIES; i++) {
                    id = payload_ids[i];
                    if (id == 0)
                        break;
                    if (id == payload_id) {
                        shift += payload_counts[i];
                        payload_removed_id = id;
                        payload_removed_start = payload_starts[i];
                    } else {
                        if (shift != 0) {
                            payload_ids[j] = id;
                            payload_starts[j] = payload_starts[i] - shift;
                            payload_counts[j] = payload_counts[i];
                        }
                        j++;
                    }
                }
            }
        }
    }
    /* Phase 5. */
    if ((unsigned char)sys_return_zero(0) == 0) {
        dbg_printf(DAT_9f1cca98, 1);
        for (i = 0; i < PAYLOAD_ENTRIES; i++)
            dbg_printf(DAT_9f1cca58, payload_ids[i], payload_starts[i], payload_counts[i]);
    }

    /* Phase 6: pass the change on to output 0 (dp_tx_aux_write_byte returns 0 on success). */
    if ((unsigned char)dp_tx_aux_write_byte(DPTX_OUTPUT, AUX_CMD_WRITE, SINK_ADDR_0x2C0, 1) != 0) {
        dbg_print_string(DAT_9f1ccaa8);
        return 0;
    }
    if (clear != 0) {
        record[RECORD_COUNT] = RECORD_CLEAR_COUNT;
        record[RECORD_ID] = 0;
        record[RECORD_START] = 0;
        if ((unsigned char)dp_tx_aux_request(DPTX_OUTPUT, AUX_CMD_WRITE, SINK_ADDR_0x1C0, RECORD_LAST_BYTE, record) == 0) {
            dbg_print_string(DAT_9f1ccac8);
            return 0;
        }
    } else if (remove) {
        record[RECORD_ID] = payload_removed_id;
        record[RECORD_START] = payload_removed_start;
        record[RECORD_COUNT] = 0;
        if ((unsigned char)dp_tx_aux_request(DPTX_OUTPUT, AUX_CMD_WRITE, SINK_ADDR_0x1C0, RECORD_LAST_BYTE, record) == 0) {
            dbg_print_string(DAT_9f1ccac8);
            return 0;
        }
    } else {
        for (i = 0; i < PAYLOAD_ENTRIES; i++) {
            entry_id = payload_ids[i];
            if (entry_id == 0)
                break;
            if (entry_id == payload_id) {
                record[RECORD_ID] = entry_id;
                record[RECORD_START] = payload_starts[i];
                record[RECORD_COUNT] = payload_counts[i];
                if ((unsigned char)dp_tx_aux_request(DPTX_OUTPUT, AUX_CMD_WRITE, SINK_ADDR_0x1C0, RECORD_LAST_BYTE, record) == 0) {
                    dbg_print_string(DAT_9f1ccac8);
                    return 0;
                }
            }
        }
    }
    return 1;
}
