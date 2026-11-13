/* hdcp_tx_hdmi_state_start_engine  (FUN_a00c91f8)
 *
 * Count one more device and level in the record; for a plain receiver also load its id into the engine.
 * Name basis: descriptive - one state handler of the per-output copy-protection state machine; called from
 *   hdcp_tx_hdmi_run_state
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00c91f8 @ 0xa00c91f8-0xa00c9334 (316 bytes, 79 words), flags -mcpu=v8 -Os -g.
 * Word 0 of the record is a group of bit-fields (big-endian, first field = bit 31). Byte +3 is a plain
 * unsigned char member (as a bit-field it would be read with ld + and and compared signed). The stores to
 * bytes +3..+6 are written in source order 3, 4, 5, 6; GCC emits them as 6, 3, 4, 5. The 'set the overflow flag'
 * arms come first in the source (the firmware falls into them). No volatile.
 */

/* Copy-protection record of one video output (24 bytes, array hdcp_tx_records); only the parts used here are
   named. Word 0 is a group of bit-fields, bit 31 first. */
struct hdcp_tx_record {
    unsigned int bits_29_31:3;
    unsigned int repeater:1;            /* bit 28: the receiver is a repeater */
    unsigned int tries_left:4;          /* bits 24..27 */
    unsigned int bit23:1;
    unsigned int bits_18_22:5;
    unsigned int step_result:2;         /* bits 16..17: result of the state handler (STEP_*) */
    unsigned int state:8;               /* +2: state of the output's handshake (hdcp_tx_hdmi_run_state) */
    unsigned char device_count;         /* +3: counts up to 0x7f */
    unsigned char level;                /* +4: counts up to 7 */
    unsigned char count_overflow;       /* +5: set when device_count was already 0x7f */
    unsigned char level_overflow;       /* +6: set when level was already 7 */
    unsigned char rest[17];
};

/* Result of a state handler; hdcp_tx_select_next_state picks the next state from it. */
enum {
    STEP_BACK  = 0,
    STEP_NEXT  = 1,
    STEP_OTHER = 2,
    STEP_AGAIN = 3
};
extern struct hdcp_tx_record hdcp_tx_records[];
extern void hdcp_tx_reg_write(unsigned char, unsigned char, unsigned char);
extern void hdcp_tx_engine_start_command(unsigned char, unsigned char, unsigned short);
extern unsigned int hdmi_tx_reg_read8(unsigned char, int, unsigned short);

#define MAX_DEVICE_COUNT 0x7f           /* device_count stops here and sets count_overflow */
#define MAX_LEVEL        7              /* level stops here and sets level_overflow */
#define RECEIVER_ID_REG  0x10           /* first of the five HDMI transmitter registers read below */
#define RECEIVER_ID_SIZE 5

/*
 * State handler of an HDMI output (state 22 of hdcp_tx_hdmi_run_state). port = output 0 or 1.
 *
 * Always sets step_result = STEP_NEXT; hdcp_tx_select_next_state then moves the output to state 0x17 and sets
 * bit 23.
 *
 * When the repeater bit of the record is clear it first clears bit 23 and the four counters (device_count,
 * level and their two overflow flags), gives the engine command 0xb with length 0x4005, copies the five bytes of
 * the HDMI transmitter registers 0x10..0x14 into register 1 of the output's protection block, and gives the
 * engine command 0 with length 0. (Registers 0x10..0x14 hold the five-byte id of the receiver, written there by
 * hdcp_tx_hdmi_state_compare_results.)
 *
 * In every case it then counts one more device and one more level: device_count and level go up by one, and a
 * counter that is already at its maximum (0x7f, 7) sets its overflow flag instead. With the repeater bit set the
 * counts already in the record are the ones to which this is added.
 */
void hdcp_tx_hdmi_state_start_engine(unsigned char port)
{
    unsigned char i;

    hdcp_tx_records[port].step_result = STEP_NEXT;
    if (hdcp_tx_records[port].repeater == 0) {
        hdcp_tx_records[port].bit23 = 0;
        hdcp_tx_records[port].device_count = 0;
        hdcp_tx_records[port].level = 0;
        hdcp_tx_records[port].count_overflow = 0;
        hdcp_tx_records[port].level_overflow = 0;
        hdcp_tx_engine_start_command(port, 0xb, 0x4005);
        for (i = 0; i < RECEIVER_ID_SIZE; i++)
            hdcp_tx_reg_write(port, 1, hdmi_tx_reg_read8(port, 0, i + RECEIVER_ID_REG));
        hdcp_tx_engine_start_command(port, 0, 0);
    }
    if (hdcp_tx_records[port].device_count >= MAX_DEVICE_COUNT)
        hdcp_tx_records[port].count_overflow = 1;
    else
        hdcp_tx_records[port].device_count++;
    if (hdcp_tx_records[port].level >= MAX_LEVEL)
        hdcp_tx_records[port].level_overflow = 1;
    else
        hdcp_tx_records[port].level++;
}
