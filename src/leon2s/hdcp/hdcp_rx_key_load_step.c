/* hdcp_rx_key_load_step  (FUN_a00c2758)
 *
 * Do one step of the three-step key sequence of an input and return 1 after the last step.
 * Name basis: descriptive - three-step state machine on the 16-byte records
 *
 * Matching notes
 * --------------
 * FUN_a00c2758 (leon2s 0xa00c2758-0xa00c2de4, 1676 bytes), flags -mcpu=v8 -Os -g.
 * Source forms the exact build depends on: unit is an unsigned short (an int is merged with port and changes
 * the register allocation); word 0 is a union of the plain word (bit 27 tests) and a bit-field view (bit 27
 * writes); in step 1 the bit is cleared before key_step is written; the result is returned as done & 1.
 */

/* Protection record of an input (16 bytes). The six records lie one after the other from
   hdcp_rx_record_hdmi20: inputs 0, 1 HDMI 2.0, 2, 3 HDMI 2.1, 4, 5 DisplayPort. Only what this routine uses
   is named here. */
struct hdcp_rx_record {
    union {
        unsigned int word;
        struct {
            unsigned int bits_28_31:4;
            unsigned int engine_result:1;   /* bit 27: hdcp_tx_engine_read_result has delivered */
            unsigned int bits_0_26:27;
        } bits;
    } head;
    unsigned char bytes_4_11[8];
    unsigned char key_step;                 /* +0xC: step of this sequence, KEY_STEP_* */
    unsigned char state;                    /* +0xD: state of the input's protection state machine */
    unsigned char byte_0xe[2];
};

#define RECORD_ENGINE_RESULT 0x8000000      /* head.word bit 27 = head.bits.engine_result */

/* The three steps, kept in key_step. */
enum {
    KEY_STEP_READ_TABLE    = 0,     /* read 128 bytes from the receiver and start the engine */
    KEY_STEP_WAIT_ENGINE   = 1,     /* wait for the engine's result */
    KEY_STEP_WRITE_RESULT  = 2      /* exchange the long tables, write 16 bytes to the receiver */
};

/* Which register set the input has; the codes are this routine's own. */
enum {
    KEY_PATH_DP     = 0,            /* inputs 4, 5: dp_reg_* */
    KEY_PATH_HDMI20 = 0x20,         /* inputs 0, 1: hdmi_reg_* */
    KEY_PATH_HDMI21 = 0x21          /* inputs 2, 3: hdmi_rx21_reg_* */
};

#define KEY_STATE_FREE   0xff       /* hdcp_rx_*_key_state: no input of the group is in the sequence */
#define TABLE_LENGTH     0x80       /* bytes read from the receiver in step 0 */
#define RESULT_LENGTH    0x10       /* bytes written to the receiver in step 2 */

extern struct hdcp_rx_record hdcp_rx_record_hdmi20[];
extern unsigned char hdcp_rx_hdmi_key_state;
extern unsigned char hdcp_rx_hdmi21_key_state;
extern unsigned char hdcp_rx_dp_key_state;
extern unsigned char hdcp_tx_engine_table_mode0[];
extern unsigned char hdcp_rx_key_buffer[];
extern unsigned char hdcp_rx_engine_result_buffer[];
extern unsigned char hdcp_tx_engine_read_result(unsigned char, unsigned char *);
extern void hdcp_tx_engine_exchange_long_tables(unsigned char);
extern void hdcp_tx_engine_load_three_tables(unsigned char);
extern void hdmi_reg_write8(unsigned char, unsigned short, unsigned char);
extern unsigned int hdmi_reg_read8(unsigned char, unsigned short);
extern void hdmi_rx21_reg_write8(unsigned char, unsigned short, unsigned char);
extern unsigned int hdmi_rx21_reg_read8(unsigned char, unsigned short);
extern void dp_reg_write8(unsigned char, unsigned short, unsigned char);
extern void dp_reg_update_bits(unsigned char, unsigned short, unsigned char, unsigned char);
extern unsigned char dp_reg_read8(unsigned char, unsigned short);
extern void timer_delay_units(unsigned int);
extern void timer_delay_long_units(unsigned int);

/*
 * Do one step of the key sequence of an input and say when the whole sequence is finished.
 *
 *   port  the input, 0..5 (index into the six protection records)
 *
 * Returns 1 after step 2 (the sequence is complete and starts again at step 0 next time), else 0.
 * Called in state 3 of hdcp_rx_hdmi_task, hdcp_rx_hdmi21_task and hdcp_rx_dp_task, which store the result in
 * bit 31 of the record and call again while it is 0.
 *
 * The input group's hdcp_rx_*_key_state holds the input that is in the sequence; the tasks call this routine
 * only while it is KEY_STATE_FREE or that input, so one input per group goes through it at a time. Each group
 * uses its own protection engine unit (0 HDMI 2.0, 1 HDMI 2.1, 2 DisplayPort).
 *
 * Phases:
 *   step 0  read 128 bytes from the receiver into hdcp_tx_engine_table_mode0 (the HDMI receivers deliver them
 *           last byte first) and send the tables to the engine (hdcp_tx_engine_load_three_tables);
 *   step 1  ask the engine for its result until it has one (record bit 27);
 *   step 2  exchange the long tables with the engine (hdcp_tx_engine_exchange_long_tables, which fills
 *           hdcp_rx_key_buffer), write bytes 1..16 of hdcp_rx_key_buffer to the
 *           receiver (to the HDMI receivers byte 16 first), run the DisplayPort receiver's command sequence,
 *           free the group and return 1.
 */
unsigned char hdcp_rx_key_load_step(unsigned char port)
{
    struct hdcp_rx_record *record = &hdcp_rx_record_hdmi20[port];
    unsigned char done = 0;
    unsigned short unit;            /* receiver number within the group (0 or 1) */
    unsigned char path;
    unsigned char engine_unit;
    unsigned short i;
    unsigned short tries;

    /* Claim the group and pick the receiver's register set. */
    if (port < 2) {
        hdcp_rx_hdmi_key_state = port;
        unit = port;
        path = KEY_PATH_HDMI20;
        engine_unit = 0;
    } else if (port < 4) {
        hdcp_rx_hdmi21_key_state = port;
        unit = port - 2;
        path = KEY_PATH_HDMI21;
        engine_unit = 1;
    } else {
        hdcp_rx_dp_key_state = port;
        unit = port - 4;
        path = KEY_PATH_DP;
        engine_unit = 2;
    }
    switch (record->key_step) {
    case KEY_STEP_READ_TABLE:
        if (path == KEY_PATH_HDMI20) {
            /* 0x24 to register 0x310, then 128 reads of register 0x312. */
            hdmi_reg_write8(unit, 0x310, 0x24);
            for (i = 0; i < TABLE_LENGTH; i++)
                hdcp_tx_engine_table_mode0[0x7f - i] = hdmi_reg_read8(unit, 0x312);
        } else if (path == KEY_PATH_HDMI21) {
            /* 3 to register 0xA6 and 0x20 to 0xA4; then for each byte its index to 0xA5 and a read of 0xA7. */
            hdmi_rx21_reg_write8(unit, 0xa6, 3);
            hdmi_rx21_reg_write8(unit, 0xa4, 0x20);
            for (i = 0; i < TABLE_LENGTH; i++) {
                hdmi_rx21_reg_write8(unit, 0xa5, i);
                hdcp_tx_engine_table_mode0[0x7f - i] = hdmi_rx21_reg_read8(unit, 0xa7);
            }
        } else {
            /* 0 to register 0x403, bit 7 of 0x402 set, 4 to 0x400; then 128 reads of register 0x401. */
            dp_reg_write8(unit, 0x403, 0);
            dp_reg_update_bits(unit, 0x402, 0x80, 1);
            dp_reg_write8(unit, 0x400, 4);
            for (i = 0; i < TABLE_LENGTH; i++)
                hdcp_tx_engine_table_mode0[i] = dp_reg_read8(unit, 0x401);
        }
        hdcp_tx_engine_load_three_tables(engine_unit);
        record->key_step = KEY_STEP_WAIT_ENGINE;
        break;
    case KEY_STEP_WAIT_ENGINE:
        if ((record->head.word & RECORD_ENGINE_RESULT) == 0)
            record->head.bits.engine_result = hdcp_tx_engine_read_result(engine_unit, hdcp_rx_engine_result_buffer);
        if (record->head.word & RECORD_ENGINE_RESULT) {
            record->head.bits.engine_result = 0;
            record->key_step = KEY_STEP_WRITE_RESULT;
        }
        break;
    case KEY_STEP_WRITE_RESULT:
        hdcp_tx_engine_exchange_long_tables(engine_unit);
        if (path == KEY_PATH_HDMI20) {
            hdmi_reg_write8(unit, 0x310, 0x34);
            for (i = RESULT_LENGTH; i != 0; i--)
                hdmi_reg_write8(unit, 0x312, hdcp_rx_key_buffer[i]);
            hdmi_reg_write8(unit, 0x312, 1);
        } else if (path == KEY_PATH_HDMI21) {
            hdmi_rx21_reg_write8(unit, 0xa6, 0x21);
            hdmi_rx21_reg_write8(unit, 0xa4, 0);
            for (i = RESULT_LENGTH; i != 0; i--) {
                hdmi_rx21_reg_write8(unit, 0xa5, 0x10 - i);
                hdmi_rx21_reg_write8(unit, 0xa7, hdcp_rx_key_buffer[i]);
            }
            /* One more byte, value 1, at index 16. */
            hdmi_rx21_reg_write8(unit, 0xa5, 0x10);
            hdmi_rx21_reg_write8(unit, 0xa7, 1);
        } else {
            dp_reg_write8(unit, 0x400, 0xf);
            dp_reg_update_bits(unit, 0x402, 0x80, 1);
            dp_reg_write8(unit, 0x403, 0);
            for (i = 0; i < RESULT_LENGTH; i++)
                dp_reg_write8(unit, 0x401, hdcp_rx_key_buffer[i + 1]);
            dp_reg_update_bits(unit, 0, 0x20, 0);
            dp_reg_update_bits(unit, 0x405, 1, 0);
            /* Commands 8, 9 and 0xC0 to register 0x406; after each, wait (at most 256 delay units) until the
               receiver clears bit 3 (bit 7 after 0xC0). */
            dp_reg_write8(unit, 0x406, 8);
            tries = 0xff;
            while ((dp_reg_read8(unit, 0x406) & 8) && tries--)
                timer_delay_units(1);
            dp_reg_write8(unit, 0x406, 9);
            tries = 0xff;
            while ((dp_reg_read8(unit, 0x406) & 8) && tries--)
                timer_delay_units(1);
            dp_reg_write8(unit, 0x406, 0xc0);
            tries = 0xff;
            while ((dp_reg_read8(unit, 0x406) & 0x80) && tries--)
                timer_delay_units(1);
            dp_reg_update_bits(unit, 0x30, 0x40, 1);
            /* Wait for bit 4 of register 0x408, at most 1000 long delays. */
            tries = 1000;
            while (!(dp_reg_read8(unit, 0x408) & 0x10) && tries--)
                timer_delay_long_units(1);
            /* tries is 0 only when bit 4 came up on the last read: after a time-out the counter has wrapped
               to 0xFFFF, so this block runs then too. */
            if (tries != 0) {
                dp_reg_write8(unit, 0x406, 0xb);
                tries = 0xff;
                while ((dp_reg_read8(unit, 0x406) & 8) && tries--)
                    ;
                dp_reg_update_bits(unit, 0x30, 0x40, 1);
            }
            dp_reg_update_bits(unit, 0x405, 1, 1);
        }
        /* Sequence complete: start at step 0 next time and free the group of this input. */
        record->key_step = KEY_STEP_READ_TABLE;
        done = 1;
        if (hdcp_rx_hdmi_key_state == port)
            hdcp_rx_hdmi_key_state = KEY_STATE_FREE;
        else if (hdcp_rx_hdmi21_key_state == port)
            hdcp_rx_hdmi21_key_state = KEY_STATE_FREE;
        else if (hdcp_rx_dp_key_state == port)
            hdcp_rx_dp_key_state = KEY_STATE_FREE;
        break;
    }
    return done & 1;
}
