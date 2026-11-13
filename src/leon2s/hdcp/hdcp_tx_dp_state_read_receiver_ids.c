/* hdcp_tx_dp_state_read_receiver_ids  (FUN_a00cef6c)
 *
 * State handler: read the device list message over AUX, check its value with the engine, take counts.
 * Note: Header at AUX 0x69330, 16-byte value at 0x69335, 5-byte device entries from 0x69345.
 * Name basis: derived - one state handler of the per-port copy-protection state machine; AUX reads at 0x69330
 *   / 0x69335 / 0x69345, engine command 0x0B, record fields device count, level, overflow bits and message
 *   counter
 *
 * Matching notes
 * --------------
 * FUN_a00cef6c (leon2s 0xa00cef6c-0xa00cf6bc, 1872 bytes), flags -mcpu=v8 -Os -g.
 * Source forms the exact build depends on:
 *  - the first test of the count byte reads it into an unsigned char with an unsigned int copy for the 0xC test;
 *    the high-nibble test after header bit 0 reads it again (as does the else-if test), so the else-if test
 *    keeps its own load;
 *  - the address of the list read is 'list_address + i * 5', with list_address set before the loop;
 *  - the record bytes use the level byte directly and the count byte through an unsigned char with an int copy,
 *    as in hdcp_tx_hdmi_update_record.
 */

/* Protection record of an output (24 bytes, docs/DATA.md; the fields used here). */
struct hdcp_tx_record {
    unsigned int bits_28_31 : 4;
    unsigned int tries_left : 4;        /* word 0 bits 24..27 */
    unsigned int bit23 : 1;
    unsigned int bits_18_22 : 5;
    unsigned int step_result : 2;       /* bits 16..17: STEP_* below, read by hdcp_tx_select_next_state */
    unsigned int state : 8;             /* +2: the state hdcp_tx_dp_run_state dispatches on */
    unsigned char device_count;         /* +3 */
    unsigned char level;                /* +4 */
    unsigned char count_overflow;       /* +5 */
    unsigned char level_overflow;       /* +6 */
    unsigned char byte_0x7;             /* +7: bit 0 of the count byte */
    unsigned char byte_0x8;             /* +8: bit 1 of the count byte */
    unsigned char pad9[3];
    unsigned int message_counter;       /* +0xC: header bytes 2..4 of the last message; 0 after hdcp_tx_init_port_record */
    unsigned char pad10[8];
};

/* Result of a state handler. hdcp_tx_select_next_state picks the next state from it; for this state (0x4A):
   STEP_NEXT -> 0x4B, STEP_OTHER -> 0 with bit23 set, STEP_BACK -> 0x40, STEP_AGAIN -> state kept. */
enum {
    STEP_BACK  = 0,
    STEP_NEXT  = 1,
    STEP_OTHER = 2,
    STEP_AGAIN = 3
};

#define AUX_CMD_READ        0x90
#define AUX_RXSTATUS        0x69493     /* one byte, printed as 'Rxstatus' */
#define AUX_HEADER          0x69330     /* 5 header bytes */
#define AUX_CHECK_VALUE     0x69335     /* 16 bytes, compared with the engine's result */
#define AUX_LIST            0x69345     /* the device list, 5 bytes per device */

#define RXSTATUS_BIT3       8           /* set: STEP_BACK */
#define RXSTATUS_BIT0       1           /* clear: STEP_AGAIN */

/* Byte offsets in the header (the layout of message bytes 1..5 in hdcp_tx_hdmi_update_record). */
#define HDR_LEVEL_BYTE      0           /* bits 1..3 level, bit 0 = bit 4 of the device count */
#define HDR_COUNT_BYTE      1           /* bits 4..7 device count bits 0..3, bit 3 count overflow, bit 2 level
                                           overflow, bit 1 -> byte_0x8, bit 0 -> byte_0x7 */
#define HDR_COUNTER         2           /* 3 bytes, high byte first */
#define HEADER_LENGTH       5
#define CHECK_VALUE_LENGTH  16
#define ID_LENGTH           5           /* bytes of a receiver id; also of each device list entry */
#define DP_OUTPUT           2           /* row of the DisplayPort output in the per-output tables */

/* Registers of the output's protection block (hdcp_tx_reg_*). */
#define PROT_REG_DATA       1           /* bytes to and from the engine */
#define PROT_REG_2          2
#define PROT_REG_6          6           /* 0xE0 starts; bit 7 reads 1 while busy */

#define ENGINE_CMD_0B       0xb         /* hdcp_tx_engine_start_command code */
#define ENGINE_ZERO_BYTES   0xb6        /* zero bytes written after the first 0x8000 command */

extern struct hdcp_tx_record hdcp_tx_records[];
extern unsigned char hdcp_tx_message_buffer[];
extern unsigned char hdcp_tx_work_block[];
extern unsigned char hdcp_tx_ksv_table[];
extern unsigned char hdcp_tx_receiver_ids[][5];
extern const char DAT_9f1c2190[];       /* "\nRxstatus = %02X" */
extern unsigned char hdcp_rx_get_port_status_bit(int);
extern void hdcp_tx_engine_start_command(unsigned char, unsigned char, unsigned short);
extern void hdcp_tx_reg_write(unsigned char, unsigned short, unsigned char);
extern unsigned char hdcp_tx_reg_read(unsigned char, unsigned short);
extern int dp_tx_aux_request_copy(int, int, int, int, unsigned char *);
extern int dbg_printf(const char *, ...);

/*
 * State 0x4A of the DisplayPort output: read the message the downstream device has waiting (header, 16-byte
 * value, device list) over AUX, check the value with the output's engine, and take the device's counts into
 * the record. The DisplayPort counterpart of hdcp_tx_hdmi_update_record.
 *
 *   port  the output, 2
 *
 * Called by hdcp_tx_dp_run_state in state 0x4A, and by hdcp_tx_service_port for output 2 when bit 2 of
 * dp_tx_get_hpd_event_bits(0) is set, the repeater bit is set and the state is above 0x4A; there STEP_NEXT sets
 * state 0x4A, STEP_BACK restarts the record (hdcp_tx_init_port_record) and STEP_AGAIN becomes STEP_NEXT.
 * The AUX reads use channel 0.
 *
 * Phases, in order:
 *   1. step_result = STEP_NEXT. STEP_AGAIN when hdcp_rx_get_port_status_bit(port) is set; the Rxstatus byte
 *      (AUX 0x69493): bit 3 set gives STEP_BACK, bit 0 clear STEP_AGAIN; else it is printed.
 *   2. Header (5 bytes at AUX 0x69330, also copied to hdcp_tx_message_buffer). Its counter (bytes 2..4): a record
 *      value of 0xFFFFFF followed by 0, or a record value of 0 followed by anything else, gives STEP_BACK; the
 *      value is then kept in message_counter (0 is kept as 1).
 *   3. The 16 bytes at AUX 0x69335 go to hdcp_tx_work_block.
 *   4. Engine: command 0x0B with 0x8000 and 0xB6 zero bytes; command 0x0B with 0x8000 and the header; for each of
 *      the header's devices (5-bit count) its 5 list bytes (AUX 0x69345 + i * 5) after command 0x0B with
 *      0x4015 + i * 5; the header again, 0x80, 0 to register 2, 0xE0 to register 6, and a wait with no limit
 *      until bit 7 of register 6 reads 0.
 *   5. Counts, as in hdcp_tx_hdmi_update_record: an overflow bit already set (count byte bits 2, 3) gives
 *      STEP_OTHER; the device count goes up by one (at 31 its overflow bit and count_overflow are set), the
 *      level by one while below 4 (else its overflow bit and level_overflow); the record gets device_count,
 *      level, the two overflow bits ORed in, and bits 0 and 1 as byte_0x7 and byte_0x8.
 *   6. Without STEP_OTHER: command 0x0B with 0x4005 and read 16 bytes from the engine; the first that differs from
 *      hdcp_tx_work_block gives STEP_BACK and ends the handler; else 0 to register 2.
 *   7. Command 0x0B with 0x4010 + (header device count) * 5, then the output's receiver id; the receiver id of
 *      output 2 is copied to entry 2 of hdcp_tx_ksv_table.
 */
void hdcp_tx_dp_state_read_receiver_ids(unsigned char port)
{
    unsigned char header[16];
    unsigned char buf[16];
    unsigned short i;
    unsigned short j;
    unsigned char list_count;
    unsigned char count_byte;
    unsigned int count_bits;
    unsigned int list_address;
    unsigned char new_count_byte;
    int new_count_bits;

    /* 1. Status checks. */
    hdcp_tx_records[port].step_result = STEP_NEXT;
    if ((unsigned char)hdcp_rx_get_port_status_bit(port) != 0) {
        hdcp_tx_records[port].step_result = STEP_AGAIN;
        return;
    }
    dp_tx_aux_request_copy(0, AUX_CMD_READ, AUX_RXSTATUS, 0, header);
    if (header[0] & RXSTATUS_BIT3) {
        hdcp_tx_records[port].step_result = STEP_BACK;
        return;
    }
    if ((header[0] & RXSTATUS_BIT0) == 0) {
        hdcp_tx_records[port].step_result = STEP_AGAIN;
        return;
    }
    dbg_printf(DAT_9f1c2190, header[0]);
    /* 2. Header; its counter may not go from 0xFFFFFF to 0, and must read 0 while the record holds 0. */
    dp_tx_aux_request_copy(0, AUX_CMD_READ, AUX_RXSTATUS, 0, header);
    dp_tx_aux_request_copy(0, AUX_CMD_READ, AUX_HEADER, HEADER_LENGTH - 1, header);
    for (i = 0; i < HEADER_LENGTH; i++)
        hdcp_tx_message_buffer[i] = header[i];
    if (hdcp_tx_records[port].message_counter == 0xffffff && header[HDR_COUNTER] == 0 && header[HDR_COUNTER + 1] == 0
        && header[HDR_COUNTER + 2] == 0) {
        hdcp_tx_records[port].step_result = STEP_BACK;
        return;
    }
    if (hdcp_tx_records[port].message_counter == 0
        && (header[HDR_COUNTER] != 0 || header[HDR_COUNTER + 1] != 0 || header[HDR_COUNTER + 2] != 0)) {
        hdcp_tx_records[port].step_result = STEP_BACK;
        return;
    }
    hdcp_tx_records[port].message_counter = (header[HDR_COUNTER] << 16) | (header[HDR_COUNTER + 1] << 8)
        | header[HDR_COUNTER + 2];
    if (hdcp_tx_records[port].message_counter == 0)
        hdcp_tx_records[port].message_counter = 1;
    /* 3. The device's 16-byte value. */
    dp_tx_aux_request_copy(0, AUX_CMD_READ, AUX_CHECK_VALUE, CHECK_VALUE_LENGTH - 1, buf);
    for (i = 0; i < CHECK_VALUE_LENGTH; i++)
        hdcp_tx_work_block[i] = buf[i];
    /* 4. Let the engine compute its value over header and list. */
    hdcp_tx_engine_start_command(port, ENGINE_CMD_0B, 0x8000);
    for (i = 0; i < ENGINE_ZERO_BYTES; i++)
        hdcp_tx_reg_write(port, PROT_REG_DATA, 0);
    hdcp_tx_engine_start_command(port, ENGINE_CMD_0B, 0x8000);
    for (i = 0; i < HEADER_LENGTH; i++)
        hdcp_tx_reg_write(port, PROT_REG_DATA, header[i]);
    list_count = ((header[HDR_LEVEL_BYTE] & 1) << 4) + (header[HDR_COUNT_BYTE] >> 4);
    list_address = AUX_LIST;
    for (i = 0; i < list_count; i++) {
        dp_tx_aux_request_copy(0, AUX_CMD_READ, list_address + i * ID_LENGTH, ID_LENGTH - 1, buf);
        hdcp_tx_engine_start_command(port, ENGINE_CMD_0B, i * ID_LENGTH + 0x4015);
        for (j = 0; j < ID_LENGTH; j++)
            hdcp_tx_reg_write(port, PROT_REG_DATA, buf[j]);
    }
    for (i = 0; i < HEADER_LENGTH; i++)
        hdcp_tx_reg_write(port, PROT_REG_DATA, hdcp_tx_message_buffer[i]);
    hdcp_tx_reg_write(port, PROT_REG_DATA, 0x80);
    hdcp_tx_reg_write(port, PROT_REG_2, 0);
    hdcp_tx_reg_write(port, PROT_REG_6, 0xe0);
    while (hdcp_tx_reg_read(port, PROT_REG_6) & 0x80)
        ;
    /* 5. Counts: an overflow reported by the device takes the other way out. */
    count_byte = header[HDR_COUNT_BYTE];
    count_bits = count_byte;
    if (count_bits & 0xc)
        hdcp_tx_records[port].step_result = STEP_OTHER;
    /* Device count + 1, with bit 0 of the level byte as its bit 4. */
    if ((header[HDR_LEVEL_BYTE] & 1) && (header[HDR_COUNT_BYTE] & 0xf0) == 0xf0) {
        hdcp_tx_records[port].count_overflow = 1;
        header[HDR_COUNT_BYTE] = count_byte | 8;
    } else if ((header[HDR_COUNT_BYTE] & 0xf0) == 0xf0) {
        header[HDR_COUNT_BYTE] &= 0xf;
        header[HDR_LEVEL_BYTE] |= 1;
    } else {
        header[HDR_COUNT_BYTE] += 0x10;
    }
    /* Level + 1 while below 4. */
    if ((header[HDR_LEVEL_BYTE] & 0xe) < 8) {
        header[HDR_LEVEL_BYTE] += 2;
    } else {
        hdcp_tx_records[port].level_overflow = 1;
        header[HDR_LEVEL_BYTE] |= 4;
    }
    new_count_byte = header[HDR_COUNT_BYTE];
    new_count_bits = new_count_byte;
    hdcp_tx_records[port].device_count = ((header[HDR_LEVEL_BYTE] & 1) << 4) | (new_count_byte >> 4);
    hdcp_tx_records[port].level = (header[HDR_LEVEL_BYTE] & 0xe) >> 1;
    hdcp_tx_records[port].count_overflow |= (new_count_bits & 8) >> 3;
    hdcp_tx_records[port].level_overflow |= (new_count_bits & 4) >> 2;
    hdcp_tx_records[port].byte_0x7 = new_count_byte & 1;
    hdcp_tx_records[port].byte_0x8 = (new_count_bits & 2) >> 1;
    /* 6. The device's 16-byte value must equal the engine's. */
    if (hdcp_tx_records[port].step_result != STEP_OTHER) {
        hdcp_tx_records[port].step_result = STEP_NEXT;
        hdcp_tx_engine_start_command(port, ENGINE_CMD_0B, 0x4005);
        for (i = 0; i < CHECK_VALUE_LENGTH; i++) {
            buf[i] = hdcp_tx_reg_read(port, PROT_REG_DATA);
            if (buf[i] != hdcp_tx_work_block[i]) {
                hdcp_tx_records[port].step_result = STEP_BACK;
                return;
            }
        }
        hdcp_tx_reg_write(port, PROT_REG_2, 0);
    }
    /* 7. This output's receiver id; output 2's id is also kept in its entry of hdcp_tx_ksv_table. */
    hdcp_tx_engine_start_command(port, ENGINE_CMD_0B, list_count * ID_LENGTH + 0x4010);
    for (i = 0; i < ID_LENGTH; i++)
        hdcp_tx_reg_write(port, PROT_REG_DATA, hdcp_tx_receiver_ids[port][i]);
    for (i = 0; i < ID_LENGTH; i++)
        hdcp_tx_ksv_table[i + DP_OUTPUT * ID_LENGTH] = hdcp_tx_receiver_ids[0][i + DP_OUTPUT * ID_LENGTH];
}
