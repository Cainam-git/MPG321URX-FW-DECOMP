/* hdcp_tx_hdmi_update_record  (FUN_a00cbb50)
 *
 * Update an HDMI output's record from the received status and message bytes.
 * Name basis: derived - reads the RXSTATUS bytes and the message at DDC offset 0x80, passes message bytes to
 *   the engine and takes the device counts into the record; called by hdcp_tx_hdmi_run_state and
 *   hdcp_tx_service_port
 *
 * Matching notes
 * --------------
 * FUN_a00cbb50 (leon2s 0xa00cbb50-0xa00cc1d4, 1668 bytes), flags -mcpu=v8 -Os -g.
 * Source forms the exact build depends on:
 *  - the first test of count_byte reads it into an unsigned char with an unsigned int copy for the tests (the
 *    stored count_byte | 8 uses the unsigned char);
 *  - for the record bytes level_byte is read into an int before count_byte, and count_byte into an unsigned
 *    char with an int copy for the shifted bits (count_byte >> 4 and bit 0 use the unsigned char);
 *  - the inner else arm clears the count bits before it sets bit 0 of the level byte.
 */

/* Protection record of an output (24 bytes, docs/DATA.md; the fields used here). */
struct hdcp_tx_record {
    unsigned int bits_28_31 : 4;
    unsigned int tries_left : 4;        /* word 0 bits 24..27 */
    unsigned int bit23 : 1;
    unsigned int bits_18_22 : 5;
    unsigned int step_result : 2;       /* bits 16..17: STEP_* below, read by hdcp_tx_select_next_state */
    unsigned int state : 8;             /* +2: the state hdcp_tx_hdmi_run_state dispatches on */
    unsigned char device_count;         /* +3 */
    unsigned char level;                /* +4 */
    unsigned char count_overflow;       /* +5 */
    unsigned char level_overflow;       /* +6 */
    unsigned char byte_0x7;             /* +7: bit 0 of the message's count byte */
    unsigned char byte_0x8;             /* +8: bit 1 of the message's count byte */
    unsigned char pad9[3];
    unsigned int message_counter;       /* +0xC: bytes 3..5 of the last message; 0 after hdcp_tx_init_port_record */
    unsigned char pad10[8];
};

/* The two RXSTATUS bytes (hdcp_tx_hdmi_read_rx_status prints 'Read RXSTATUS Error' when they cannot be read). */
struct rx_status {
    unsigned char length_lo;            /* message length, bits 0..7 */
    unsigned char hi;                   /* bits 0..1: message length bits 8..9; RXSTATUS_BIT2 / _BIT3 */
};

/* Result of a state handler. hdcp_tx_select_next_state picks the next state from it; for this state (0x4A):
   STEP_NEXT -> 0x4B, STEP_OTHER -> 0 with bit23 set, STEP_BACK -> 0x40, STEP_AGAIN -> state kept. */
enum {
    STEP_BACK  = 0,
    STEP_NEXT  = 1,
    STEP_OTHER = 2,
    STEP_AGAIN = 3
};

#define RXSTATUS_BIT3       8           /* set: STEP_BACK */
#define RXSTATUS_BIT2       4           /* clear: STEP_AGAIN */
#define RXSTATUS_LENGTH_HI  3

#define DDC_DEVICE          0x74        /* the receiver's address on the output's DDC channel */
#define DDC_MESSAGE         0x80        /* offset the message is read from */

/* Byte offsets in the message. */
#define MSG_LEVEL_BYTE      1           /* bits 1..3 level, bit 0 = bit 4 of the device count */
#define MSG_COUNT_BYTE      2           /* bits 4..7 device count bits 0..3, bit 3 count overflow, bit 2 level
                                           overflow, bit 1 -> byte_0x8, bit 0 -> byte_0x7 */
#define MSG_COUNTER         3           /* 3 bytes, high byte first */
#define MSG_CHECK_VALUE     6           /* 16 bytes, compared with the engine's result */
#define CHECK_VALUE_LENGTH  16
#define ID_LENGTH           5           /* bytes of a receiver id; also of each device list entry */

/* Registers of the output's protection block (hdcp_tx_reg_*). */
#define PROT_REG_DATA       1           /* bytes to and from the engine */
#define PROT_REG_5          5
#define PROT_REG_6          6           /* 0xE0 starts; bit 7 reads 1 while busy */

#define ENGINE_CMD_0B       0xb         /* hdcp_tx_engine_start_command codes */
#define ENGINE_CMD_14       0x14

extern struct hdcp_tx_record hdcp_tx_records[];
extern struct rx_status hdcp_tx_status_bytes;
extern unsigned char hdcp_tx_message_buffer[];
extern unsigned char hdcp_tx_work_block[];
extern unsigned char hdcp_tx_result_block[];
extern unsigned char hdcp_tx_receiver_ids[][5];
extern unsigned char hdcp_rx_get_port_status_bit(int);
extern unsigned int hdcp_tx_hdmi_read_rx_status(unsigned char, struct rx_status *);
extern unsigned int hdmi_tx_ddc_start(unsigned char, unsigned char, unsigned char, unsigned short);
extern unsigned int hdmi_tx_ddc_read(unsigned char, unsigned char *, unsigned short);
extern void hdcp_tx_engine_start_command(unsigned char, unsigned char, unsigned short);
extern void hdcp_tx_reg_update_bits(unsigned char, unsigned short, unsigned char, unsigned char);
extern void hdcp_tx_reg_write(unsigned char, unsigned short, unsigned char);
extern unsigned char hdcp_tx_reg_read(unsigned char, unsigned short);
extern void timer_delay_long_units(unsigned int);

/*
 * State 0x4A of an HDMI output: read the message the downstream device has waiting, check its 16-byte value
 * with the output's engine, and take the device's counts into the record.
 *
 *   port  the HDMI output, 0 or 1
 *
 * Called by hdcp_tx_hdmi_run_state in state 0x4A, and by hdcp_tx_service_port for an HDMI output in state
 * 0x4F whose repeater bit is set and bit 30 clear; there STEP_NEXT sets state 0x4A, STEP_BACK restarts the
 * record (hdcp_tx_init_port_record) and STEP_AGAIN becomes STEP_NEXT.
 *
 * Phases, in order:
 *   1. step_result = STEP_NEXT. STEP_AGAIN when hdcp_rx_get_port_status_bit(port) is set or the RXSTATUS bytes
 *      cannot be read; STEP_BACK when bit 3 of the high byte is set; STEP_AGAIN when its bit 2 is clear or
 *      the message length (10 bits) is 0 (then also a wait of 10 delay units).
 *   2. Clear bit23 and read the message (DDC offset 0x80) into hdcp_tx_message_buffer. Only the low byte of the
 *      length is used as the byte count. A failed read gives STEP_BACK.
 *   3. Message counter (bytes 3..5), checked when the message is longer than 5 bytes: a record value of
 *      0xFFFFFF followed by 0, or a record value of 0 followed by anything else, gives STEP_BACK. The value is
 *      then kept in message_counter (0 is kept as 1).
 *   4. Pulse bit 2 of protection register 5. Engine command 0x0B with 0x8000; pass message bytes 1..5, then bytes
 *      0x16 up to the last; keep bytes 6..21 in hdcp_tx_work_block; pass bytes 1..5 again and 0x80; write 0xE0 to
 *      register 6 and wait, with no limit, until its bit 7 reads 0. Engine command 0x14 with 0x8000 and read 16
 *      bytes into hdcp_tx_result_block.
 *   5. Counts: an overflow bit already set in the count byte (bits 2, 3) gives STEP_OTHER. The device count
 *      (5 bits) goes up by one, or at 31 its overflow bit and count_overflow are set; the level goes up by
 *      one while it is below 4, else its overflow bit and level_overflow are set. The record gets the new
 *      device_count and level, the two overflow bits ORed in, and bits 0 and 1 as byte_0x7 and byte_0x8.
 *      hdcp_repeater_report_downstream later builds its summary bytes 0 and 1 in the same layout.
 *   6. Without STEP_OTHER: STEP_NEXT when hdcp_tx_result_block equals hdcp_tx_work_block, else STEP_BACK.
 *   7. Engine command 0x0B with 0x4000 | device_count * 5, then the output's own receiver id
 *      (hdcp_tx_receiver_ids[port]).
 */
void hdcp_tx_hdmi_update_record(unsigned char port)
{
    unsigned short message_length;
    unsigned char length_lo;
    unsigned char i;
    unsigned char count_byte;
    unsigned int count_bits;
    unsigned char new_count_byte;
    int new_count_bits;
    int level_byte;

    /* 1. Status checks. */
    hdcp_tx_records[port].step_result = STEP_NEXT;
    if ((unsigned char)hdcp_rx_get_port_status_bit(port) != 0) {
        hdcp_tx_records[port].step_result = STEP_AGAIN;
        return;
    }
    if ((unsigned char)hdcp_tx_hdmi_read_rx_status(port, &hdcp_tx_status_bytes) != 0) {
        hdcp_tx_records[port].step_result = STEP_AGAIN;
        return;
    }
    if (hdcp_tx_status_bytes.hi & RXSTATUS_BIT3) {
        hdcp_tx_records[port].step_result = STEP_BACK;
        return;
    }
    if ((hdcp_tx_status_bytes.hi & RXSTATUS_BIT2) == 0) {
        hdcp_tx_records[port].step_result = STEP_AGAIN;
        return;
    }
    length_lo = hdcp_tx_status_bytes.length_lo;
    message_length = ((hdcp_tx_status_bytes.hi & RXSTATUS_LENGTH_HI) << 8) + length_lo;
    if (message_length == 0) {
        hdcp_tx_records[port].step_result = STEP_AGAIN;
        timer_delay_long_units(10);
        return;
    }
    /* 2. The message. */
    hdcp_tx_records[port].bit23 = 0;
    if ((unsigned char)hdmi_tx_ddc_start(port, DDC_DEVICE, DDC_MESSAGE, length_lo) != 0) {
        hdcp_tx_records[port].step_result = STEP_BACK;
        return;
    }
    if ((unsigned char)hdmi_tx_ddc_read(port, hdcp_tx_message_buffer, hdcp_tx_status_bytes.length_lo) != 0) {
        hdcp_tx_records[port].step_result = STEP_BACK;
        return;
    }
    /* 3. The counter may not go from 0xFFFFFF to 0, and must read 0 while the record holds 0. */
    if (message_length > 5) {
        if (hdcp_tx_records[port].message_counter == 0xffffff && hdcp_tx_message_buffer[MSG_COUNTER] == 0
            && hdcp_tx_message_buffer[MSG_COUNTER + 1] == 0 && hdcp_tx_message_buffer[MSG_COUNTER + 2] == 0) {
            hdcp_tx_records[port].step_result = STEP_BACK;
            return;
        }
        if (hdcp_tx_records[port].message_counter == 0
            && (hdcp_tx_message_buffer[MSG_COUNTER] != 0 || hdcp_tx_message_buffer[MSG_COUNTER + 1] != 0
                || hdcp_tx_message_buffer[MSG_COUNTER + 2] != 0)) {
            hdcp_tx_records[port].step_result = STEP_BACK;
            return;
        }
    }
    hdcp_tx_records[port].message_counter = (hdcp_tx_message_buffer[MSG_COUNTER] << 16)
        | (hdcp_tx_message_buffer[MSG_COUNTER + 1] << 8) | hdcp_tx_message_buffer[MSG_COUNTER + 2];
    if (hdcp_tx_records[port].message_counter == 0)
        hdcp_tx_records[port].message_counter = 1;
    /* 4. Let the engine compute its value over the message. */
    hdcp_tx_reg_update_bits(port, PROT_REG_5, 4, 1);
    hdcp_tx_reg_update_bits(port, PROT_REG_5, 4, 0);
    hdcp_tx_engine_start_command(port, ENGINE_CMD_0B, 0x8000);
    for (i = 0; i < 5; i++)
        hdcp_tx_reg_write(port, PROT_REG_DATA, hdcp_tx_message_buffer[i + 1]);
    for (i = 0x15; i < hdcp_tx_status_bytes.length_lo - 1; i++)
        hdcp_tx_reg_write(port, PROT_REG_DATA, hdcp_tx_message_buffer[i + 1]);
    for (i = 0; i < CHECK_VALUE_LENGTH; i++)
        hdcp_tx_work_block[i] = hdcp_tx_message_buffer[i + MSG_CHECK_VALUE];
    for (i = 0; i < 5; i++)
        hdcp_tx_reg_write(port, PROT_REG_DATA, hdcp_tx_message_buffer[i + 1]);
    hdcp_tx_reg_write(port, PROT_REG_DATA, 0x80);
    hdcp_tx_reg_write(port, PROT_REG_6, 0xe0);
    while (hdcp_tx_reg_read(port, PROT_REG_6) & 0x80)
        ;
    hdcp_tx_engine_start_command(port, ENGINE_CMD_14, 0x8000);
    for (i = 0; i < CHECK_VALUE_LENGTH; i++)
        hdcp_tx_result_block[i] = hdcp_tx_reg_read(port, PROT_REG_DATA);
    /* 5. Counts: an overflow reported by the device takes the other way out. */
    count_byte = hdcp_tx_message_buffer[MSG_COUNT_BYTE];
    count_bits = count_byte;
    if (count_bits & 0xc)
        hdcp_tx_records[port].step_result = STEP_OTHER;
    /* Device count + 1, with bit 0 of the level byte as its bit 4. */
    if ((hdcp_tx_message_buffer[MSG_LEVEL_BYTE] & 1) && (count_bits & 0xf0) == 0xf0) {
        hdcp_tx_message_buffer[MSG_COUNT_BYTE] = count_byte | 8;
        hdcp_tx_records[port].count_overflow = 1;
    } else if ((hdcp_tx_message_buffer[MSG_COUNT_BYTE] & 0xf0) == 0xf0) {
        hdcp_tx_message_buffer[MSG_COUNT_BYTE] &= 0xf;
        hdcp_tx_message_buffer[MSG_LEVEL_BYTE] |= 1;
    } else {
        hdcp_tx_message_buffer[MSG_COUNT_BYTE] += 0x10;
    }
    /* Level + 1 while below 4. */
    if ((hdcp_tx_message_buffer[MSG_LEVEL_BYTE] & 0xe) < 8) {
        hdcp_tx_message_buffer[MSG_LEVEL_BYTE] += 2;
    } else {
        hdcp_tx_message_buffer[MSG_COUNT_BYTE] |= 4;
        hdcp_tx_records[port].level_overflow = 1;
    }
    level_byte = hdcp_tx_message_buffer[MSG_LEVEL_BYTE];
    new_count_byte = hdcp_tx_message_buffer[MSG_COUNT_BYTE];
    new_count_bits = new_count_byte;
    hdcp_tx_records[port].device_count = ((level_byte & 1) << 4) | (new_count_byte >> 4);
    hdcp_tx_records[port].level = (level_byte & 0xe) >> 1;
    hdcp_tx_records[port].count_overflow |= (new_count_bits & 8) >> 3;
    hdcp_tx_records[port].level_overflow |= (new_count_bits & 4) >> 2;
    hdcp_tx_records[port].byte_0x7 = new_count_byte & 1;
    hdcp_tx_records[port].byte_0x8 = (new_count_bits & 2) >> 1;
    /* 6. The device's 16-byte value must equal the engine's. */
    if (hdcp_tx_records[port].step_result != STEP_OTHER) {
        hdcp_tx_records[port].step_result = STEP_NEXT;
        for (i = 0; i < CHECK_VALUE_LENGTH; i++)
            if (hdcp_tx_result_block[i] != hdcp_tx_work_block[i])
                hdcp_tx_records[port].step_result = STEP_BACK;
    }
    /* 7. Then this output's receiver id. */
    hdcp_tx_engine_start_command(port, ENGINE_CMD_0B, ((((hdcp_tx_message_buffer[MSG_LEVEL_BYTE] & 1) << 4) + (hdcp_tx_message_buffer[MSG_COUNT_BYTE] >> 4)) * ID_LENGTH) | 0x4000);
    for (i = 0; i < ID_LENGTH; i++)
        hdcp_tx_reg_write(port, PROT_REG_DATA, hdcp_tx_receiver_ids[port][i]);
}
