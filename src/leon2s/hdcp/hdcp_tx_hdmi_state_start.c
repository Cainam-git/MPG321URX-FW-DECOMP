/* hdcp_tx_hdmi_state_start  (FUN_a00ccb04)
 *
 * State handler: once the retry time is reached and the engine is free, reset and send message 2.
 * Note: Message 2 of HDCP 2.x is AKE_Init; its 8 value bytes are fixed (1..8). Before the retry time or with
 *   the engine taken it gives 'again'.
 * Name basis: descriptive - one state handler of the per-output copy-protection state machine (24-byte records
 *   at 0xA8078BB0); called from hdcp_tx_hdmi_run_state; compares the tick count with hdcp_tx_retry_ticks and
 *   tests hdcp_owner_byte
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00ccb04 @ 0xa00ccb04-0xa00ccd20, flags -mcpu=v8 -Os -g.
 * Source forms the exact build depends on:
 *  - the parameter is defined K&R style ('void f(port) unsigned char port;');
 *  - the two start conditions are nested ifs, each with its own 'step_result = STEP_AGAIN; return;' else arm;
 *  - hdcp_tx_message_buffer is stored in the order bytes 1, 3..7, 0, 8, 2, 0xa, 9, 0xb;
 *  - word 0 of the record is a 14 + 2 bit group followed by a 16-bit member.
 */

/* Protection record of an output (24 bytes, docs/DATA.md; the fields used here). */
struct hdcp_tx_record {
    unsigned int bits_18_31 : 14;
    unsigned int step_result : 2;       /* bits 16..17: STEP_* below, read by hdcp_tx_select_next_state */
    unsigned int state_and_count : 16;  /* +2 state, +3 device_count */
    unsigned char bytes_0x4_0x8[5];
    unsigned char engine_unit;          /* +9: engine unit given to the output; 0xFF = none */
    unsigned char pad_0xa[2];
    unsigned int word_0xc;              /* 0 after hdcp_tx_init_port_record */
    unsigned int word_0x10;             /* 24-bit counter, see hdcp_tx_hdmi_state_send_stream_manage */
    unsigned int word_0x14;
};

/* Result of a state handler. hdcp_tx_select_next_state picks the next state from it; for this state (0x40):
   STEP_NEXT -> 0x41 (tries_left 10), STEP_BACK -> 0, STEP_AGAIN -> state kept. */
enum {
    STEP_BACK  = 0,
    STEP_NEXT  = 1,
    STEP_AGAIN = 3
};

#define OWNER_NONE          0xff        /* hdcp_owner_byte when no output has the engine */
#define ENGINE_UNIT_OUTPUT  3           /* engine unit this state gives the output */
#define DISABLE_WAIT        0x14        /* delay units after register 4 is set to 7 */

#define HDCP_DDC_DEVICE     0x74        /* device address used for all handshake reads and writes */
#define DDC_WRITE_MESSAGE   0x60        /* offset a message is written to */
#define MESSAGE_LENGTH      0xc         /* bytes written to the device */
#define STORED_KEY_LENGTH   16          /* bytes of hdcp_stored_key_header given to the engine */

#define PROT_REG_DATA       1           /* bytes to and from the engine */
#define PROT_REG_4          4
#define PROT_REG_5          5
#define ENGINE_CMD_13       0x13        /* hdcp_tx_engine_start_command codes, in the order they are given */
#define ENGINE_CMD_01       1

extern struct hdcp_tx_record hdcp_tx_records[];
extern unsigned int hdcp_tx_retry_ticks[];
extern unsigned char hdcp_owner_byte;
extern unsigned char hdcp_stored_key_header[];
extern unsigned char hdcp_tx_message_buffer[];
extern unsigned int timer_get_ticks(void);
extern void timer_delay_long_units(unsigned int);
extern unsigned char hdmi_tx_reg_read8(unsigned char, int, unsigned short);
extern void hdcp_tx_disable_output(unsigned char);
extern void hdcp_tx_hdmi_pulse_reg0f_bit2(unsigned char, unsigned char);
extern void hdcp_tx_reg_write(unsigned char, unsigned short, unsigned char);
extern void hdcp_tx_engine_start_command(unsigned char, unsigned char, unsigned short);
extern int hdmi_tx_ddc_write(unsigned char, unsigned char *, unsigned char, unsigned char, unsigned short);

/*
 * State 0x40 of an HDMI output, the first state of a handshake: take the engine, reset the output's
 * protection block, give the engine the stored key block and send a 12-byte message to the downstream device.
 *
 *   port  the HDMI output, 0 or 1
 *
 * Called by hdcp_tx_hdmi_run_state in state 0x40. The result is step_result: STEP_NEXT after the message is
 * sent; STEP_AGAIN when the tick count is still below this output's hdcp_tx_retry_ticks entry or another
 * output owns the engine (hdcp_owner_byte is neither 0xFF nor port); STEP_BACK when bit 1 of byte register 9
 * of the HDMI transmitter (bank 0) is clear.
 *
 * In order:
 *   1. The two STEP_AGAIN checks, time first.
 *   2. hdcp_owner_byte = port, the record's engine_unit = 3, word_0xc = 0, hdcp_tx_disable_output, word_0x10 = 0,
 *      bit 2 of register 0x0F of the output pulsed (cleared, then set again after a wait, by
 *      hdcp_tx_hdmi_pulse_reg0f_bit2 with 1).
 *   3. Protection register 4 = 7, a wait of 0x14 delay units, register 4 = 1, register 5 = 1.
 *   4. Engine command 0x13: write the 16 bytes of hdcp_stored_key_header to register 1.
 *   5. hdcp_tx_message_buffer = 2, 1, 2, 3, 4, 5, 6, 7, 8, 2, 0, 0. Engine command 1: write bytes 1..11 to
 *      register 1.
 *   6. Send the 12 bytes to the device (DDC offset 0x60), after the bit 1 check above.
 */
void hdcp_tx_hdmi_state_start(port)
    unsigned char port;
{
    unsigned char i;

    hdcp_tx_records[port].step_result = STEP_NEXT;
    if (timer_get_ticks() >= hdcp_tx_retry_ticks[port]) {
        if (hdcp_owner_byte == OWNER_NONE || hdcp_owner_byte == port) {
            /* Take the engine and reset this output's protection block. */
            hdcp_owner_byte = port;
            hdcp_tx_records[port].engine_unit = ENGINE_UNIT_OUTPUT;
            hdcp_tx_records[port].word_0xc = 0;
            hdcp_tx_disable_output(port);
            hdcp_tx_records[port].word_0x10 = 0;
            hdcp_tx_hdmi_pulse_reg0f_bit2(port, 1);
            hdcp_tx_reg_write(port, PROT_REG_4, 7);
            timer_delay_long_units(DISABLE_WAIT);
            hdcp_tx_reg_write(port, PROT_REG_4, 1);
            hdcp_tx_reg_write(port, PROT_REG_5, 1);
            hdcp_tx_engine_start_command(port, ENGINE_CMD_13, 0x8000);
        } else {
            hdcp_tx_records[port].step_result = STEP_AGAIN;
            return;
        }
    } else {
        hdcp_tx_records[port].step_result = STEP_AGAIN;
        return;
    }
    for (i = 0; i < STORED_KEY_LENGTH; i++)
        hdcp_tx_reg_write(port, PROT_REG_DATA, hdcp_stored_key_header[i]);
    hdcp_tx_message_buffer[1] = 1;
    hdcp_tx_message_buffer[3] = 3;
    hdcp_tx_message_buffer[4] = 4;
    hdcp_tx_message_buffer[5] = 5;
    hdcp_tx_message_buffer[6] = 6;
    hdcp_tx_message_buffer[7] = 7;
    hdcp_tx_message_buffer[0] = 2;
    hdcp_tx_message_buffer[8] = 8;
    hdcp_tx_message_buffer[2] = 2;
    hdcp_tx_message_buffer[0xa] = 0;
    hdcp_tx_message_buffer[9] = 2;
    hdcp_tx_message_buffer[0xb] = 0;
    hdcp_tx_engine_start_command(port, ENGINE_CMD_01, 0x8000);
    for (i = 0; i <= 0xa; i++)
        hdcp_tx_reg_write(port, PROT_REG_DATA, hdcp_tx_message_buffer[1 + i]);
    if ((hdmi_tx_reg_read8(port, 0, 9) & 2) == 0)
        hdcp_tx_records[port].step_result = STEP_BACK;
    else
        hdmi_tx_ddc_write(port, hdcp_tx_message_buffer, HDCP_DDC_DEVICE, DDC_WRITE_MESSAGE, MESSAGE_LENGTH);
}
