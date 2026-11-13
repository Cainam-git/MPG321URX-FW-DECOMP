/* hdcp_tx_hdmi_state_send_session_key  (FUN_a00cb7a0)
 *
 * State handler: send message 0xB (16 engine bytes and 8 fixed bytes) to the receiver.
 * Note: Message 0xB of HDCP 2.x is SKE_Send_Eks; for a plain receiver it also loads the receiver id and sets
 *   device count and level to 1.
 * Name basis: derived - one state handler of the per-output copy-protection state machine, called from
 *   hdcp_tx_hdmi_run_state; writes 25 bytes starting with 0xB to DDC device 0x74 offset 0x60
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00cb7a0 @ 0xa00cb7a0-0xa00cbb50, flags -mcpu=v8 -Os -g.
 * Source forms the exact build depends on:
 *  - the pattern is filled in one loop that stores bytes i, i + 8 and i + 0x10 in that order;
 *  - the poll is 'i = 0xff; while (read & 8) { i--; if (i == 0) goto fail; }' with the loop counter i reused;
 *  - the STEP_AGAIN and STEP_OTHER exits are labels after the success path (the firmware's block order);
 *  - the output's channel record is a struct whose first member is the word 0 that is tested.
 */

/* Protection record of an output (24 bytes, docs/DATA.md; the fields used here). */
struct hdcp_tx_record {
    unsigned int bits_29_31 : 3;
    unsigned int repeater : 1;          /* bit 28 */
    unsigned int tries_left : 4;        /* bits 24..27 */
    unsigned int bit23 : 1;
    unsigned int bits_18_22 : 5;
    unsigned int step_result : 2;       /* bits 16..17: STEP_* below, read by hdcp_tx_select_next_state */
    unsigned int state : 8;             /* +2 */
    unsigned char device_count;         /* +3 */
    unsigned char level;                /* +4 */
    unsigned char count_overflow;       /* +5 */
    unsigned char level_overflow;       /* +6 */
    unsigned char byte_0x7;
    unsigned char byte_0x8;
    unsigned char rest[15];
};

/* Channel record of an HDMI output (28 bytes each, array hdmi_tx_output_records); only word 0 is used here. */
struct hdmi_tx_channel_record { unsigned int word_0; unsigned char rest[24]; };

/* Result of a state handler. hdcp_tx_select_next_state picks the next state from it; for this state (0x49):
   STEP_NEXT -> 0x4E (with bit23 set), STEP_OTHER -> 0x4A, STEP_BACK -> 0x40, STEP_AGAIN -> state kept. */
enum {
    STEP_BACK  = 0,
    STEP_NEXT  = 1,
    STEP_OTHER = 2,
    STEP_AGAIN = 3
};

#define HDCP_DDC_DEVICE     0x74        /* device address used for all handshake reads and writes */
#define DDC_WRITE_MESSAGE   0x60        /* offset a message is written to */
#define MESSAGE_LENGTH      0x19        /* byte 0, the 16 engine bytes and 8 pattern bytes */

#define CHANNEL_WORD0_BIT2  4           /* word 0 of the output's channel record: selects the value of register 0xD */

#define PROT_REG_DATA       1           /* bytes to and from the engine */
#define PROT_REG_5          5
#define PROT_REG_6          6           /* polled until bit 3 reads 0 */
#define PROT_REG_DATA_2     0x12        /* second data register: takes the first 16 pattern bytes */
#define PROT_REG_D          0xd
#define PROT_REG_E          0xe
#define POLL_TRIES          0xff

#define ENGINE_CMD_15       0x15        /* hdcp_tx_engine_start_command codes, in the order they are given */
#define ENGINE_CMD_11       0x11
#define ENGINE_CMD_0A       0xa
#define ENGINE_CMD_0B       0xb

extern struct hdcp_tx_record hdcp_tx_records[];
extern struct hdmi_tx_channel_record hdmi_tx_output_records[];
extern unsigned char hdcp_tx_message_buffer[];
extern unsigned char hdcp_tx_receiver_ids[][5];
extern void hdcp_tx_engine_start_command(unsigned char, unsigned char, unsigned short);
extern void hdcp_tx_reg_write(unsigned char, unsigned short, unsigned char);
extern unsigned char hdcp_tx_reg_read(unsigned char, unsigned short);
extern void hdcp_tx_reg_update_bits(unsigned char, unsigned short, unsigned char, unsigned char);
extern int hdmi_tx_ddc_write(unsigned char, unsigned char *, unsigned char, unsigned char, unsigned short);

/*
 * State 0x49 of an HDMI output: give the engine a 24-byte pattern, take 16 bytes back from the engine and send
 * them to the downstream device; for a receiver that is not a repeater also set up the record for the next
 * step.
 *
 *   port  the HDMI output, 0 or 1
 *
 * Called by hdcp_tx_hdmi_run_state in state 0x49. The result is step_result: STEP_AGAIN when register 6
 * still has bit 3 set after 255 reads; STEP_OTHER when the receiver is a repeater (repeater bit set); else
 * STEP_NEXT.
 *
 * In order:
 *   1. Fill hdcp_tx_message_buffer: bytes 1..8 = 1..8, bytes 9..16 = 9..16, bytes 0x11..0x18 = 0x21..0x28.
 *   2. Engine command 0x15: write bytes 1..16 to register 0x12. Engine command 0x11: write bytes 0x11..0x18 to
 *      register 1. Write 10 to register 6 and wait for its bit 3 to clear (STEP_AGAIN if it does not).
 *   3. Register 0xD gets 0x3A when bit 2 of word 0 of the output's channel record is set, else 0x76; register
 *      0xE gets 0.
 *   4. Message byte 0 = 0xB. Engine command 10: read 16 bytes into message bytes 1..16. Write the 0x19 bytes
 *      (message bytes 0..0x18) to the device (DDC offset 0x60).
 *   5. Repeater: stop with STEP_OTHER. Otherwise clear bit23, pulse bit 2 of protection register 5, engine
 *      command 0x0B with: 2, 0x10, 0, 0, 0, the output's receiver id (5 bytes), 2, 0x10, 0, 0, 0, 0x80
 *      written to register 1; the record gets device_count 1, level 1 and its two overflow counts, byte_0x7 and
 *      byte_0x8 cleared; STEP_NEXT.
 */
void hdcp_tx_hdmi_state_send_session_key(unsigned char port)
{
    unsigned char i;

    hdcp_tx_records[port].step_result = STEP_NEXT;
    for (i = 1; i < 9; i++) {
        hdcp_tx_message_buffer[i] = i;
        hdcp_tx_message_buffer[i + 8] = i + 8;
        hdcp_tx_message_buffer[i + 0x10] = i + 0x20;
    }
    hdcp_tx_engine_start_command(port, ENGINE_CMD_15, 0x8000);
    for (i = 0; i < 16; i++)
        hdcp_tx_reg_write(port, PROT_REG_DATA_2, hdcp_tx_message_buffer[i + 1]);
    hdcp_tx_engine_start_command(port, ENGINE_CMD_11, 0x8000);
    for (i = 0; i < 8; i++)
        hdcp_tx_reg_write(port, PROT_REG_DATA, hdcp_tx_message_buffer[i + 0x11]);
    hdcp_tx_reg_write(port, PROT_REG_6, 10);
    i = POLL_TRIES;
    while (hdcp_tx_reg_read(port, PROT_REG_6) & 8) {
        i--;
        if (i == 0)
            goto again;
    }
    if (hdmi_tx_output_records[port].word_0 & CHANNEL_WORD0_BIT2)
        hdcp_tx_reg_write(port, PROT_REG_D, 0x3a);
    else
        hdcp_tx_reg_write(port, PROT_REG_D, 0x76);
    hdcp_tx_reg_write(port, PROT_REG_E, 0);
    hdcp_tx_message_buffer[0] = 0xb;
    hdcp_tx_engine_start_command(port, ENGINE_CMD_0A, 0x8000);
    for (i = 0; i < 16; i++)
        hdcp_tx_message_buffer[i + 1] = hdcp_tx_reg_read(port, PROT_REG_DATA);
    hdmi_tx_ddc_write(port, hdcp_tx_message_buffer, HDCP_DDC_DEVICE, DDC_WRITE_MESSAGE, MESSAGE_LENGTH);
    if (hdcp_tx_records[port].repeater == 0) {
        hdcp_tx_records[port].bit23 = 0;
        hdcp_tx_reg_update_bits(port, PROT_REG_5, 4, 1);
        hdcp_tx_reg_update_bits(port, PROT_REG_5, 4, 0);
        hdcp_tx_engine_start_command(port, ENGINE_CMD_0B, 0x8000);
        hdcp_tx_reg_write(port, PROT_REG_DATA, 2);
        hdcp_tx_reg_write(port, PROT_REG_DATA, 0x10);
        hdcp_tx_reg_write(port, PROT_REG_DATA, 0);
        hdcp_tx_reg_write(port, PROT_REG_DATA, 0);
        hdcp_tx_reg_write(port, PROT_REG_DATA, 0);
        for (i = 0; i < 5; i++)
            hdcp_tx_reg_write(port, PROT_REG_DATA, hdcp_tx_receiver_ids[port][i]);
        hdcp_tx_reg_write(port, PROT_REG_DATA, 2);
        hdcp_tx_reg_write(port, PROT_REG_DATA, 0x10);
        hdcp_tx_reg_write(port, PROT_REG_DATA, 0);
        hdcp_tx_reg_write(port, PROT_REG_DATA, 0);
        hdcp_tx_reg_write(port, PROT_REG_DATA, 0);
        hdcp_tx_reg_write(port, PROT_REG_DATA, 0x80);
        hdcp_tx_records[port].device_count = 1;
        hdcp_tx_records[port].level = 1;
        hdcp_tx_records[port].count_overflow = 0;
        hdcp_tx_records[port].level_overflow = 0;
        hdcp_tx_records[port].byte_0x7 = 0;
        hdcp_tx_records[port].byte_0x8 = 0;
        hdcp_tx_records[port].step_result = STEP_NEXT;
        return;
    }
    goto other;
again:
    hdcp_tx_records[port].step_result = STEP_AGAIN;
    return;
other:
    hdcp_tx_records[port].step_result = STEP_OTHER;
}
