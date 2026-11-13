/* hdcp_rx_reset_port  (FUN_a00c1778)
 *
 * Reset the copy-protection record of an input and its hardware bits.
 * Name basis: descriptive - 16-byte record at 0xA807D5C8 and four bytes set to 0xFF
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00c1778 @ 0xa00c1778, flags -mcpu=v8 -Os -g (the section default).
 * Source form: the stores to the record are separate statements in the firmware's store order (it differs from
 * the order of the fields); word 0 is a 16-bit bit-field group followed by the byte members.
 */
/* Protection record of one input (16 bytes), the six records from hdcp_rx_record_hdmi20 on: inputs 0, 1
   HDMI 2.0, 2, 3 HDMI 2.1, 4, 5 DisplayPort. Word 0 is a group of bit-fields, bit 31 first. */
struct hdcp_rx_record {
    unsigned int keys_ready : 1;            /* bit 31: the key sequence has finished */
    unsigned int key_event_seen : 1;        /* bit 30 */
    unsigned int bit29 : 1;
    unsigned int bit28 : 1;
    unsigned int engine_result : 1;         /* bit 27: the engine has delivered its result */
    unsigned int bits_24_26 : 3;            /* 5 = RECORD_BITS_24_26_READY; the state machines return otherwise */
    unsigned int bit23 : 1;
    unsigned int downstream_reported : 1;   /* bit 22 */
    unsigned int bit21 : 1;
    unsigned int watch_hold : 5;            /* bits 16..20 */
    unsigned char previous_output_bits;     /* +2 */
    unsigned char byte_0x3;
    unsigned char output_bits;              /* +4: bit n = output n shows this input */
    unsigned char byte_0x5;
    unsigned char byte_0x6;
    unsigned char byte_0x7;
    unsigned int watch_time_stamp;          /* +8 */
    unsigned char key_step;                 /* +0xC */
    unsigned char state;                    /* +0xD */
    unsigned char byte_0xe;
    unsigned char byte_0xf;
};

#define RECORD_BITS_24_26_READY 5           /* value of bits_24_26 (as a word mask: 0x5000000) */
#define WATCH_HOLD_START        1           /* value of watch_hold after the reset */
#define BYTE_0x5_START          0x22
#define KEY_STATE_FREE          0xff        /* hdcp_rx_*_key_state, hdcp_owner_byte: nobody holds it */
#define LAST_HDMI20_PORT        1
#define FIRST_HDMI21_INPUT      2
#define FIRST_DP_INPUT          4

extern struct hdcp_rx_record hdcp_rx_record_hdmi20[];
extern unsigned char hdcp_owner_byte;
extern unsigned char hdcp_rx_port_flags[];
extern unsigned char hdcp_rx_port_bytes[];
extern unsigned char hdcp_rx_hdmi_key_state;
extern unsigned char hdcp_rx_hdmi21_key_state;
extern unsigned char hdcp_rx_dp_key_state;
extern void dp_reg_update_bits(unsigned char, unsigned short, unsigned char, unsigned char);
extern void hdmi_rx21_reg_update_bits(unsigned char, unsigned short, unsigned char, unsigned char);
extern void hdmi_reg_update_bits(unsigned char, unsigned short, unsigned char, unsigned char);

/*
 * Put the copy-protection record of one input back to its start state and set bits in its receiver.
 *
 *   port  the input, 0..5
 *   flag  nonzero for an HDMI input (0..3), 0 for a DisplayPort input (4, 5); picks the register writes at
 *         the end
 *
 * Called by InitHDCP for all six inputs (flag 1 for 0..3, 0 for 4, 5).
 *
 * The record: keys_ready, key_event_seen, bit 29, bit 28, engine_result, the byte at +0xD (state), the byte
 * at +0xC (key_step), the word at +8, the byte at +4 (output_bits), the byte at +2 and bits 21..23 are
 * cleared; bits 24..26 become 5, the byte at +5 becomes 0x22 and watch_hold becomes 1. The input's entries in
 * hdcp_rx_port_flags and hdcp_rx_port_bytes are cleared. The three key-state variables of the input groups
 * (HDMI 2.0, HDMI 2.1, DisplayPort) and hdcp_owner_byte are set to 0xFF for every port, not only the one
 * reset.
 *
 * Register writes (each sets the named bits): HDMI 2.0 inputs 0, 1: bit 7 of registers 0x31F and 0x309 and
 * bits 1..3 of 0x321. HDMI 2.1 inputs 2, 3 (receiver port - 2): bit 0 of 0xC00 and bit 6 of 9. DisplayPort
 * inputs (receiver port - 4): bit 7 of 0x407.
 */
void hdcp_rx_reset_port(unsigned char port, unsigned char flag)
{
    hdcp_rx_record_hdmi20[port].keys_ready = 0;
    hdcp_rx_record_hdmi20[port].key_event_seen = 0;
    hdcp_rx_record_hdmi20[port].bit29 = 0;
    hdcp_rx_record_hdmi20[port].bit28 = 0;
    hdcp_rx_record_hdmi20[port].engine_result = 0;
    hdcp_rx_record_hdmi20[port].state = 0;
    hdcp_rx_record_hdmi20[port].key_step = 0;
    hdcp_rx_record_hdmi20[port].watch_time_stamp = 0;
    hdcp_rx_record_hdmi20[port].bits_24_26 = RECORD_BITS_24_26_READY;
    hdcp_rx_record_hdmi20[port].byte_0x5 = BYTE_0x5_START;
    hdcp_rx_record_hdmi20[port].output_bits = 0;
    hdcp_rx_record_hdmi20[port].previous_output_bits = 0;
    hdcp_rx_record_hdmi20[port].bit23 = 0;
    hdcp_rx_record_hdmi20[port].downstream_reported = 0;
    hdcp_rx_record_hdmi20[port].bit21 = 0;
    hdcp_rx_record_hdmi20[port].watch_hold = WATCH_HOLD_START;
    hdcp_rx_port_flags[port] = 0;
    hdcp_rx_port_bytes[port] = 0;
    hdcp_rx_hdmi_key_state = KEY_STATE_FREE;
    hdcp_rx_hdmi21_key_state = KEY_STATE_FREE;
    hdcp_rx_dp_key_state = KEY_STATE_FREE;
    hdcp_owner_byte = KEY_STATE_FREE;
    if (flag != 0) {
        if (port <= LAST_HDMI20_PORT) {
            hdmi_reg_update_bits(port, 0x31f, 0x80, 1);
            hdmi_reg_update_bits(port, 0x309, 0x80, 1);
            hdmi_reg_update_bits(port, 0x321, 0xe, 1);
        } else {
            hdmi_rx21_reg_update_bits(port - FIRST_HDMI21_INPUT, 0xc00, 1, 1);
            hdmi_rx21_reg_update_bits(port - FIRST_HDMI21_INPUT, 9, 0x40, 1);
        }
    } else {
        dp_reg_update_bits(port - FIRST_DP_INPUT, 0x407, 0x80, 1);
    }
}
