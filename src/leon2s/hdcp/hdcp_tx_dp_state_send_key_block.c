/* hdcp_tx_dp_state_send_key_block  (FUN_a00cdde0)
 *
 * State handler: wait for the engine, then send a prepared data block in 16 groups over AUX.
 * Name basis: descriptive - one state handler of the per-port copy-protection state machine (24-byte records
 *   at 0xA8078BB0); called from hdcp_tx_dp_run_state; polls up to 30 times
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00cdde0 @ 0xa00cdde0-0xa00ce420, flags -mcpu=v8 -Os -g.
 * Source forms the exact build depends on: a while loop on the hdcp_tx_engine_read_result result with the
 * counter decremented first in the body; the AUX address is one variable advanced by 8 after each send (the
 * firmware adds 8 to a register); the buffer offsets are constants per group, so the 16 groups are 16 macro
 * expansions, not a loop.
 */
#define AUX_CMD_WRITE       0x80
#define AUX_KEY_BLOCK       0x69220     /* 128 bytes, written in 16 groups of 8; the next area is 0x692a0 */
#define POLL_LIMIT          30          /* tries for the engine result */
#define POLL_DELAY          10          /* delay units after each try without a result */

/* Protection record of an output (24 bytes, docs/DATA.md; the fields used here). Word 0 is split so that
   step_result is one field. */
struct hdcp_tx_record {
    unsigned int bits_18_31 : 14;
    unsigned int step_result : 2;       /* bits 16..17: STEP_* below, read by hdcp_tx_select_next_state */
    unsigned int low_half : 16;         /* +2 state, +3 device_count */
    unsigned char bytes_0x4_0x8[5];
    unsigned char engine_unit;          /* +9: engine unit of the output, passed to the engine routines */
    unsigned char pad[14];
};
enum {
    STEP_BACK  = 0,
    STEP_NEXT  = 1,
    STEP_OTHER = 2,
    STEP_AGAIN = 3
};
extern struct hdcp_tx_record hdcp_tx_records[];
extern unsigned char hdcp_tx_message_buffer[];
extern void hdcp_tx_engine_exchange_tables(unsigned char);
extern void hdcp_tx_engine_load_key_blocks(unsigned char);
extern unsigned char hdcp_tx_engine_read_result(unsigned char, unsigned char *);
extern void timer_delay_long_units(unsigned int);
extern int dp_tx_aux_request(unsigned int, unsigned int, unsigned int, unsigned int, unsigned char *);

/* Copy group k (8 bytes) of the message buffer to buf and write it over AUX at addr; addr moves on by 8. */
#define SEND_GROUP(k)                                                   \
    for (i = 0; i < 8; i++)                                        \
        buf[i] = hdcp_tx_message_buffer[(k) * 8 + i];                        \
    dp_tx_aux_request(0, AUX_CMD_WRITE, addr, 7, buf);                        \
    addr += 8

/*
 * State 0x43 of the DisplayPort output: have the engine produce its 128-byte result and write it to the receiver.
 *
 *   port  the output, 2
 *
 * Called by hdcp_tx_dp_run_state in state 0x43 (hdcp_tx_select_next_state enters it after the state 0x42
 * compare, unless the record's bit 29 sends it to 0x44). It reports through step_result (STEP_*).
 *
 *   1. step_result = STEP_NEXT.
 *   2. hdcp_tx_engine_exchange_tables and hdcp_tx_engine_load_key_blocks run for the output's engine unit.
 *   3. hdcp_tx_engine_read_result is tried up to 30 times into hdcp_tx_message_buffer, with 10 delay units after
 *      each try that gives no result. After 30 tries without a result step_result is STEP_BACK and the loop
 *      ends; the next step is done anyway.
 *   4. The 128 bytes of hdcp_tx_message_buffer are written over AUX (channel 0) to 0x69220..0x6929F, 8 bytes at
 *      a time.
 */
void hdcp_tx_dp_state_send_key_block(unsigned char port)
{
    unsigned char buf[8];
    unsigned short i;
    unsigned char n;
    unsigned int addr;

    hdcp_tx_records[port].step_result = STEP_NEXT;
    hdcp_tx_engine_exchange_tables(hdcp_tx_records[port].engine_unit);
    hdcp_tx_engine_load_key_blocks(hdcp_tx_records[port].engine_unit);
    n = POLL_LIMIT;
    while (hdcp_tx_engine_read_result(hdcp_tx_records[port].engine_unit, hdcp_tx_message_buffer) == 0) {
        n--;
        timer_delay_long_units(POLL_DELAY);
        if (n == 0) {
            hdcp_tx_records[port].step_result = STEP_BACK;
            break;
        }
    }
    addr = AUX_KEY_BLOCK;
    SEND_GROUP(0);
    SEND_GROUP(1);
    SEND_GROUP(2);
    SEND_GROUP(3);
    SEND_GROUP(4);
    SEND_GROUP(5);
    SEND_GROUP(6);
    SEND_GROUP(7);
    SEND_GROUP(8);
    SEND_GROUP(9);
    SEND_GROUP(10);
    SEND_GROUP(11);
    SEND_GROUP(12);
    SEND_GROUP(13);
    SEND_GROUP(14);
    SEND_GROUP(15);
}
