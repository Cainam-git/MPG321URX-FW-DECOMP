/* hdcp_tx_hdmi_state_send_lc_init  (FUN_a00cb3e8)
 *
 * State handler: send message 9 (fixed bytes 1..8) to the engine and the receiver, wait for the engine.
 * Note: Message 9 of HDCP 2.x is LC_Init (locality check); the 8 bytes are fixed, not random.
 * Name basis: derived - one state handler of the per-output copy-protection state machine, called from
 *   hdcp_tx_hdmi_run_state; writes the 9 bytes 9, 1..8 to DDC device 0x74 offset 0x60 (the HDCP 2.x message
 *   write offset)
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00cb3e8 @ 0xa00cb3e8-0xa00cb56c, flags -mcpu=v8 -Os -g.
 * Source forms the exact build depends on:
 *  - the nine message bytes are nine separate stores (9, 1, 2 .. 8), not a loop;
 *  - the poll counter t is an unsigned char that starts at 0xff and is tested after its decrement;
 *  - the debug print takes its text as the program-memory address 0x9f1c2158.
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
    unsigned char bytes_0x3_0x8[6];
    unsigned char engine_unit;          /* +9: engine unit given to the output; 0xFF = none */
    unsigned char rest[14];
};

/* Result of a state handler. hdcp_tx_select_next_state picks the next state from it; for this state (0x47):
   STEP_NEXT -> 0x48, STEP_BACK and STEP_OTHER -> 0x40. */
enum {
    STEP_BACK  = 0,
    STEP_NEXT  = 1
};

#define ENGINE_UNIT_NONE    0xff
#define HDCP_DDC_DEVICE     0x74        /* device address used for all handshake reads and writes */
#define DDC_WRITE_MESSAGE   0x60        /* offset a message is written to */
#define MESSAGE_LENGTH      9           /* bytes written to the device: byte 0 and bytes 1..8 */

#define PROT_REG_DATA       1           /* bytes to and from the engine */
#define PROT_REG_5          5
#define PROT_REG_6          6           /* bit 7 reads 1 while busy */
#define ENGINE_CMD_WRITE_8  8           /* hdcp_tx_engine_start_command code */
#define POLL_TRIES          0xff

extern struct hdcp_tx_record hdcp_tx_records[];
extern unsigned char hdcp_owner_byte;
extern unsigned char hdcp_tx_message_buffer[];
extern int dbg_printf(const char *, ...);
extern void hdcp_tx_engine_start_command(unsigned char, unsigned char, unsigned short);
extern void hdcp_tx_reg_write(unsigned char, unsigned short, unsigned char);
extern unsigned char hdcp_tx_reg_read(unsigned char, unsigned short);
extern int hdmi_tx_ddc_write(unsigned char, unsigned char *, unsigned char, unsigned char, unsigned short);

/*
 * State 0x47 of an HDMI output: give the engine 8 bytes, send the 9-byte message 9, 1, 2 .. 8 to the
 * downstream device and wait until the engine's busy bit clears.
 *
 *   port  the HDMI output, 0 or 1
 *
 * Called by hdcp_tx_hdmi_run_state in state 0x47. step_result is STEP_NEXT, or STEP_BACK when the busy bit of
 * protection register 6 is still set after 255 reads.
 *
 * In order:
 *   1. When this output owns the engine (hdcp_owner_byte == port) the record's engine_unit
 *      and the owner byte become 0xFF (no unit, no owner), and a debug text is printed.
 *   2. Fill hdcp_tx_message_buffer with 9, 1, 2 .. 8. Engine command 8; write message bytes 1..8 to the
 *      engine; write the 9 bytes to the device (DDC offset 0x60).
 *   3. Write 3 to protection register 5 and 0xD0 to register 6, then read register 6 until bit 7 is clear.
 */
void hdcp_tx_hdmi_state_send_lc_init(unsigned char port)
{
    unsigned char i, tries;

    hdcp_tx_records[port].step_result = STEP_NEXT;
    /* Release the engine when this output holds it. */
    if (hdcp_owner_byte == port) {
        hdcp_tx_records[port].engine_unit = ENGINE_UNIT_NONE;
        hdcp_owner_byte = 0xff;
        dbg_printf((const char *)0x9f1c2158);
    }
    hdcp_tx_message_buffer[0] = 9;
    hdcp_tx_message_buffer[1] = 1;
    hdcp_tx_message_buffer[2] = 2;
    hdcp_tx_message_buffer[3] = 3;
    hdcp_tx_message_buffer[4] = 4;
    hdcp_tx_message_buffer[5] = 5;
    hdcp_tx_message_buffer[6] = 6;
    hdcp_tx_message_buffer[7] = 7;
    hdcp_tx_message_buffer[8] = 8;
    hdcp_tx_engine_start_command(port, ENGINE_CMD_WRITE_8, 0x8000);
    for (i = 0; i <= 7; i++)
        hdcp_tx_reg_write(port, PROT_REG_DATA, hdcp_tx_message_buffer[1 + i]);
    hdmi_tx_ddc_write(port, hdcp_tx_message_buffer, HDCP_DDC_DEVICE, DDC_WRITE_MESSAGE, MESSAGE_LENGTH);
    hdcp_tx_reg_write(port, PROT_REG_5, 3);
    hdcp_tx_reg_write(port, PROT_REG_6, 0xd0);
    tries = POLL_TRIES;
    while (hdcp_tx_reg_read(port, PROT_REG_6) & 0x80) {
        tries--;
        if (tries == 0) {
            hdcp_tx_records[port].step_result = STEP_BACK;
            break;
        }
    }
}
