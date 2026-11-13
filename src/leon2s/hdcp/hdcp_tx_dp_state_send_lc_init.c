/* hdcp_tx_dp_state_send_lc_init  (FUN_a00ce864)
 *
 * State handler: check the receiver status byte, then send the bytes 0xB0..0xB7 over AUX to 0x692F0.
 * Note: DPCD 0x692F0 is the locality-check value (LC_Init) of HDCP 2.x; the same 8 bytes go to the engine.
 * Name basis: derived - one state handler of the per-port copy-protection state machine, called from
 *   hdcp_tx_dp_run_state; AUX read of 0x69493, AUX write of 8 bytes to 0x692F0
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00ce864 @ 0xa00ce864-0xa00cea60, flags -mcpu=v8 -Os -g.
 * Source forms the exact build depends on: the record fields are bit-fields (the firmware reads step_result back
 * with a halfword load and & 3); in the engine_unit / owner release the record byte is stored first; in the
 * tries_left test the '== 0' arm comes first. No volatile.
 */
#define AUX_CMD_READ        0x90
#define AUX_CMD_WRITE       0x80
#define AUX_RXSTATUS        0x69493     /* one byte, tested below */
#define AUX_SEND_BLOCK      0x692f0     /* 8 bytes written here */
#define RXSTATUS_RETRY      0x06        /* any of these bits: one try less, STEP_AGAIN */
#define RXSTATUS_FAIL       0x18        /* any of these bits: STEP_BACK */
#define SEND_BYTES          8
#define SEND_FIRST_VALUE    0xb0        /* the bytes sent are 0xb0, 0xb1 .. 0xb7 */
#define ENGINE_CMD_8        8           /* hdcp_tx_engine_start_command code */
#define PROT_REG_DATA       1           /* protection block register: bytes to the engine */
#define PROT_REG_6          6           /* protection block register: written 0xd0 to start, bit 7 = busy */
#define PROT_REG_6_START    0xd0
#define PROT_REG_6_BUSY     0x80
#define ENGINE_UNIT_NONE    0xff        /* record byte +9: no engine unit */
#define KEY_STATE_FREE      0xff        /* hdcp_owner_byte: nobody holds the engine */

/* Protection record of an output (24 bytes, docs/DATA.md; the fields used here). */
struct hdcp_tx_record {
    unsigned int bits_28_31 : 4;
    unsigned int tries_left : 4;        /* bits 24..27 */
    unsigned int bits_18_23 : 6;
    unsigned int step_result : 2;       /* bits 16..17: STEP_* below, read by hdcp_tx_select_next_state */
    unsigned int low_half : 16;         /* +2 state, +3 device_count */
    unsigned char bytes_0x4_0x8[5];
    unsigned char engine_unit;          /* +9 */
    unsigned char pad[14];
};
enum {
    STEP_BACK  = 0,
    STEP_NEXT  = 1,
    STEP_OTHER = 2,
    STEP_AGAIN = 3
};
extern struct hdcp_tx_record hdcp_tx_records[];
extern unsigned char hdcp_owner_byte;
extern unsigned char DAT_9f1c2158[];
extern void hdcp_tx_reg_write(unsigned char, unsigned char, unsigned char);
extern unsigned char hdcp_tx_reg_read(unsigned char, unsigned char);
extern void hdcp_tx_engine_start_command(unsigned char, unsigned char, unsigned short);
extern int dbg_printf(void *);
extern int dp_tx_aux_request(int, int, int, int, unsigned char *);
extern int dp_tx_aux_request_copy(int, int, int, int, unsigned char *);

/*
 * State 0x47 of the DisplayPort output: look at the receiver's status byte and, when it shows no problem, send
 * it 8 fixed bytes through the engine.
 *
 *   port  the output, 2
 *
 * Called by hdcp_tx_dp_run_state in state 0x47. It reports through step_result (STEP_*).
 *
 *   1. step_result = STEP_NEXT. When hdcp_owner_byte names this output, the output lets go of the engine:
 *      engine_unit = ENGINE_UNIT_NONE, hdcp_owner_byte = 0xFF, and a debug text is printed.
 *   2. Read the status byte (AUX 0x69493, channel 0).
 *   3. Bits 1 or 2 set: tries_left goes down by one; step_result is STEP_BACK when it reaches 0, else
 *      STEP_AGAIN; either way the routine ends.
 *   4. Bits 3 or 4 set: STEP_BACK.
 *   5. Otherwise: engine command 8 (length 0x8000); the bytes 0xB0..0xB7 go to register 1 of the output's
 *      protection block and are written over AUX to 0x692F0; register 6 gets 0xD0 and is read until its
 *      bit 7 has cleared.
 */
void hdcp_tx_dp_state_send_lc_init(unsigned char port)
{
    unsigned char buf[16];
    unsigned short j;
    unsigned char rx_status;

    hdcp_tx_records[port].step_result = STEP_NEXT;
    if (hdcp_owner_byte == port) {
        hdcp_tx_records[port].engine_unit = ENGINE_UNIT_NONE;
        hdcp_owner_byte = KEY_STATE_FREE;
        dbg_printf(DAT_9f1c2158);
    }
    dp_tx_aux_request_copy(0, AUX_CMD_READ, AUX_RXSTATUS, 0, buf);
    rx_status = buf[0];
    if ((rx_status & RXSTATUS_RETRY) != 0) {
        hdcp_tx_records[port].tries_left = hdcp_tx_records[port].tries_left - 1;
        if (hdcp_tx_records[port].tries_left == 0)
            hdcp_tx_records[port].step_result = STEP_BACK;
        else
            hdcp_tx_records[port].step_result = STEP_AGAIN;
        if (hdcp_tx_records[port].step_result != STEP_NEXT)
            return;
    }
    if ((rx_status & RXSTATUS_FAIL) != 0) {
        hdcp_tx_records[port].step_result = STEP_BACK;
    } else {
        for (j = 0; j < SEND_BYTES; j++)
            buf[j] = j + SEND_FIRST_VALUE;
        hdcp_tx_engine_start_command(port, ENGINE_CMD_8, 0x8000);
        for (j = 0; j < SEND_BYTES; j++)
            hdcp_tx_reg_write(port, PROT_REG_DATA, buf[j]);
        dp_tx_aux_request(0, AUX_CMD_WRITE, AUX_SEND_BLOCK, SEND_BYTES - 1, buf);
        hdcp_tx_reg_write(port, PROT_REG_6, PROT_REG_6_START);
        while (hdcp_tx_reg_read(port, PROT_REG_6) & PROT_REG_6_BUSY)
            ;
    }
}
