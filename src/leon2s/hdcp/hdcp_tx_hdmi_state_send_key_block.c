/* hdcp_tx_hdmi_state_send_key_block  (FUN_a00cad8c)
 *
 * State handler: wait for the engine and send the prepared block to the receiver.
 * Name basis: descriptive - one state handler of the per-output copy-protection state machine (24-byte records
 *   at 0xA8078BB0); called from hdcp_tx_hdmi_run_state; retries up to 30 times
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00cad8c @ 0xa00cad8c-0xa00caee4, -mcpu=v8 -Os -g.
 * Word 0 of the record is a group of bit-fields (big-endian, first field = bit 31); bytes +4..+8 are an array
 * member and byte +9 a plain unsigned char. The status bytes are one struct (low, high) passed by address. The
 * last call is a tail call; the empty counting loop to 0x80 is part of the build.
 */
/* Copy-protection record of one video output (24 bytes, array hdcp_tx_records); only the parts used here are
   named. Word 0 is a group of bit-fields, bit 31 first. */
struct hdcp_tx_record {
    unsigned int bits_28_31 : 4;        /* includes the repeater bit 28 */
    unsigned int tries_left : 4;        /* bits 24..27 */
    unsigned int bits_18_23 : 6;
    unsigned int step_result : 2;       /* bits 16..17: result of the state handler (STEP_*) */
    unsigned int bytes_2_3 : 16;        /* +2 state, +3 device_count */
    unsigned char bytes_4_8[5];
    unsigned char engine_unit;          /* +9: engine unit given to the output */
    unsigned char rest[14];
};
/* The two status bytes of the receiver (hdcp_tx_hdmi_read_rx_status). */
struct hdcp_tx_status {
    unsigned char low;                  /* low 8 bits of the length */
    unsigned char high;                 /* bits 0..1: high bits of the length; bits 2..3: tested */
};

/* Result of a state handler; hdcp_tx_select_next_state picks the next state from it. */
enum {
    STEP_BACK  = 0,
    STEP_NEXT  = 1,
    STEP_OTHER = 2,
    STEP_AGAIN = 3
};

extern struct hdcp_tx_record hdcp_tx_records[];
extern struct hdcp_tx_status hdcp_tx_status_bytes;
extern unsigned char hdcp_tx_message_buffer[];
extern unsigned int hdcp_tx_hdmi_read_rx_status(unsigned char, struct hdcp_tx_status *);
extern void hdcp_tx_engine_exchange_tables(unsigned char);
extern void hdcp_tx_engine_load_key_blocks(unsigned char);
extern unsigned char hdcp_tx_engine_read_result(unsigned char, unsigned char *);
extern void timer_delay_long_units(unsigned int);
extern int hdmi_tx_ddc_write(unsigned char, unsigned char *, unsigned char, unsigned char, unsigned short);

#define LENGTH_HIGH_MASK     3          /* the length is ((high & 3) << 8) + low */
#define STATUS_HIGH_BITS_2_3 0xc        /* any of these bits in high ends the state with STEP_BACK */
#define RESULT_TRIES         30         /* tries of hdcp_tx_engine_read_result */
#define RESULT_WAIT_UNITS    10         /* timer_delay_long_units argument between two tries */
#define MESSAGE_FIRST_BYTE   4          /* value put in hdcp_tx_message_buffer[0] */
#define HDCP_DDC_DEVICE      0x74       /* device address of the receiver on the output's DDC channel */
#define DDC_WRITE_OFFSET     0x60       /* offset written to */
#define DDC_WRITE_LENGTH     0x81       /* buffer[0] and the 128 result bytes at [1..0x80] */

/*
 * State handler of an HDMI output (state 67 = 0x43 of hdcp_tx_hdmi_run_state). port = output 0 or 1.
 *
 * Prepares the engine and writes its 128-byte result, with a first byte of 4, to the receiver. The result is
 * left in step_result: STEP_NEXT moves the output to state 0x45; STEP_AGAIN keeps the state so that the handler
 * runs again; STEP_BACK sends the output to state 0x40.
 *
 * Decisions in order:
 *  1. The receiver's two status bytes are read into hdcp_tx_status_bytes; a read error, or any of bits 2..3 of
 *     the high byte, gives STEP_BACK. When the length ((high & 3) << 8) + low is not 0, the result is
 *     STEP_AGAIN (this handler goes on only when the length is 0).
 *  2. The engine of the output (engine_unit) runs hdcp_tx_engine_exchange_tables and
 *     hdcp_tx_engine_load_key_blocks.
 *  3. hdcp_tx_engine_read_result is tried up to 30 times, with timer_delay_long_units(10) between the tries,
 *     to fetch the engine's result into hdcp_tx_message_buffer[1..0x80]. If every try fails the result is
 *     STEP_BACK, but the write below still happens.
 *  4. hdcp_tx_message_buffer[0] = 4 and 0x81 bytes of the buffer are written to the receiver (device 0x74,
 *     offset 0x60) with hdmi_tx_ddc_write.
 */
void hdcp_tx_hdmi_state_send_key_block(unsigned char port)
{
    unsigned char tries, i;
    unsigned short message_length;

    hdcp_tx_records[port].step_result = STEP_NEXT;
    if ((unsigned char)hdcp_tx_hdmi_read_rx_status(port, &hdcp_tx_status_bytes) != 0) {
        hdcp_tx_records[port].step_result = STEP_BACK;
        return;
    }
    message_length = ((hdcp_tx_status_bytes.high & LENGTH_HIGH_MASK) << 8) + hdcp_tx_status_bytes.low;
    if ((hdcp_tx_status_bytes.high & STATUS_HIGH_BITS_2_3) != 0) {
        hdcp_tx_records[port].step_result = STEP_BACK;
        return;
    }
    if (message_length != 0) {
        hdcp_tx_records[port].step_result = STEP_AGAIN;
        return;
    }
    hdcp_tx_engine_exchange_tables(hdcp_tx_records[port].engine_unit);
    hdcp_tx_engine_load_key_blocks(hdcp_tx_records[port].engine_unit);
    tries = RESULT_TRIES;
    while (hdcp_tx_engine_read_result(hdcp_tx_records[port].engine_unit, &hdcp_tx_message_buffer[1]) == 0) {
        tries--;
        timer_delay_long_units(RESULT_WAIT_UNITS);
        if (tries == 0) {
            hdcp_tx_records[port].step_result = STEP_BACK;
            break;
        }
    }
    hdcp_tx_message_buffer[0] = MESSAGE_FIRST_BYTE;
    for (i = 0; i <= 0x80; i++)
        ;
    hdmi_tx_ddc_write(port, hdcp_tx_message_buffer, HDCP_DDC_DEVICE, DDC_WRITE_OFFSET, DDC_WRITE_LENGTH);
}
