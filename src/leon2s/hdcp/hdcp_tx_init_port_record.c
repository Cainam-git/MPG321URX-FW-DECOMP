/* hdcp_tx_init_port_record  (FUN_a00c7a4c)
 *
 * Initialise the copy-protection record of an output.
 * Name basis: derived - 24-byte record at 0xA8078BB0
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00c7a4c @ 0xa00c7a4c, flags -mcpu=v8 -Os -g (the section default).
 * Source form: word 0 is a 16-bit group of bit-fields (big-endian, the first field is bit 31) followed by the
 * byte members, so byte +2 is the state byte; GCC merges each group of field stores into one load and store,
 * so the order of the statements below is the order that gives the firmware's stores.
 */
/* Protection record of an output (24 bytes), three records from hdcp_tx_records. Word 0 is a group of
   bit-fields, bit 31 first. Names that are not words follow the other files of the output state machine. */
struct hdcp_tx_record {
    unsigned int f31 : 1;               /* bit 31 */
    unsigned int f30 : 1;
    unsigned int f29 : 1;
    unsigned int f28 : 1;               /* tested by hdcp_tx_hdmi_state_start_engine and _check_v */
    unsigned int cnt : 4;               /* bits 24..27 */
    unsigned int b23 : 1;
    unsigned int b22 : 1;
    unsigned int b21 : 1;
    unsigned int b20 : 1;
    unsigned int b19 : 1;
    unsigned int b18 : 1;
    unsigned int st : 2;                /* bits 16..17: set by the state handlers (0, 1 or 3) */
    unsigned char state;                /* +2: state of the output's handshake (hdcp_tx_hdmi_run_state) */
    unsigned char device_count;         /* +3 */
    unsigned char level;                /* +4 */
    unsigned char count_overflow;       /* +5 */
    unsigned char level_overflow;       /* +6 */
    unsigned char byte_0x7;
    unsigned char byte_0x8;
    unsigned char engine_unit;          /* +9: engine unit given to the output; 0xFF = none */
    unsigned char bytes_0xa_0xb[2];
    unsigned int word_0xc;
    unsigned int word_0x10;
    unsigned char byte_0x14;
    unsigned char byte_0x15;
    unsigned short halfword_0x16;
};

#define CNT_START          5        /* value of cnt after the reset */
#define ST_START           1        /* value of st after the reset */
#define STATE_START        1        /* value of the state byte after the reset */
#define HALFWORD_0x16_START 100
#define ENGINE_UNIT_NONE   0xff
#define BYTE_0x14_START    0x1f

extern struct hdcp_tx_record hdcp_tx_records[];
extern unsigned char hdcp_owner_byte;

/*
 * Put the protection record of one output back to its start state.
 *
 *   port  the output, 0..2
 *   flag  nonzero for a full reset that also clears the device-list fields of the record (bytes +3..+8);
 *         0 keeps them (and bits 18, 19 and 23)
 *
 * Called by hdcp_tx_task with flag 1 and by hdcp_tx_service_port and others with flag 0.
 *
 * Always: bit 31 = 1; bits 30, 29, 28 = 0; cnt = 5; st = 1; state byte = 1; the halfword at +0x16 = 100; the
 * engine unit (+9) = 0xFF (none); bit 22 = 1; the byte at +0x14 = 0x1F; the words at +0xC and +0x10 = 0;
 * bits 20 and 21 = 0. hdcp_owner_byte is set to 0xFF when it holds this output.
 * Only with flag: bit 18 = 1; bits 23 and 19 = 0; the bytes +3..+8 = 0.
 */
void hdcp_tx_init_port_record(unsigned char port, unsigned char flag)
{
    hdcp_tx_records[port].f31 = 1;
    hdcp_tx_records[port].f30 = 0;
    hdcp_tx_records[port].f29 = 0;
    hdcp_tx_records[port].st = ST_START;
    hdcp_tx_records[port].f28 = 0;
    hdcp_tx_records[port].cnt = CNT_START;
    hdcp_tx_records[port].state = STATE_START;
    hdcp_tx_records[port].halfword_0x16 = HALFWORD_0x16_START;
    hdcp_tx_records[port].engine_unit = ENGINE_UNIT_NONE;
    if (hdcp_owner_byte == port)
        hdcp_owner_byte = 0xff;
    if (flag) {
        hdcp_tx_records[port].b18 = 1;
        hdcp_tx_records[port].b23 = 0;
        hdcp_tx_records[port].b19 = 0;
        hdcp_tx_records[port].device_count = 0;
        hdcp_tx_records[port].level = 0;
        hdcp_tx_records[port].count_overflow = 0;
        hdcp_tx_records[port].level_overflow = 0;
        hdcp_tx_records[port].byte_0x7 = 0;
        hdcp_tx_records[port].byte_0x8 = 0;
    }
    hdcp_tx_records[port].b22 = 1;
    hdcp_tx_records[port].byte_0x14 = BYTE_0x14_START;
    hdcp_tx_records[port].word_0xc = 0;
    hdcp_tx_records[port].word_0x10 = 0;
    hdcp_tx_records[port].b20 = 0;
    hdcp_tx_records[port].b21 = 0;
}
