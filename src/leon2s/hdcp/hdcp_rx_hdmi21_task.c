/* hdcp_rx_hdmi21_task  (FUN_a00c3ae8)
 *
 * Run the copy-protection state machine of the two HDMI 2.1 inputs.
 * Name basis: derived - 16-byte records at 0xA807D5E8; called from input_run_port_services
 *
 * Matching notes
 * --------------
 * FUN_a00c3ae8 (leon2s 0xa00c3ae8-0xa00c44ac, 2500 bytes), flags -mcpu=v8 -Os -g.
 * The switch compiles to the jump table at 0xa00c3ab0 (linked at 0x9f1b3ab0).
 * Source forms the exact build depends on: as hdcp_rx_hdmi_task (union of the word and a bit-field view, the
 * state byte written before the two bit clears in state 2, unsigned char result of the register read); n is
 * an unsigned char and reads an unsigned short; the extra read of register 0xAA before the bit-5 test is in
 * the firmware.
 */

/* Word 0 of a protection record, as bit-fields (bit 31 first). */
struct hdcp_rx_record_bits {
    unsigned int keys_ready : 1;            /* bit 31: hdcp_rx_key_load_step has finished its sequence */
    unsigned int key_event_seen : 1;        /* bit 30: the event that follows the key sequence was seen */
    unsigned int bits_25_29 : 5;
    unsigned int bit24 : 1;
    unsigned int bit23 : 1;                 /* copied to the output records by input_update_port_records */
    unsigned int downstream_reported : 1;   /* bit 22: set by input_update_port_records after the report */
    unsigned int bit21 : 1;
    unsigned int watch_hold : 5;            /* bits 16..20: nonzero makes the next counter check count as good */
    unsigned int bits_0_15 : 16;
};

/* Protection record of an input (16 bytes). hdcp_rx_record_hdmi21[0] and [1] are records 2 and 3 of the six
   that start at hdcp_rx_record_hdmi20; the routines that take the input number 0..5 get input + 2. */
struct hdcp_rx_record {
    union { unsigned int word; struct hdcp_rx_record_bits bits; } head;
    unsigned char output_bits;              /* +4: bit n = output n shows this input */
    unsigned char bytes_5_11[7];
    unsigned char key_step;                 /* +0xC: step of hdcp_rx_key_load_step */
    unsigned char state;                    /* +0xD: HDCP_RX_STATE_* */
    unsigned char byte_0xe[2];
};

/* head.word masks */
#define RECORD_BITS_24_26           0x7000000
#define RECORD_BITS_24_26_READY     0x5000000   /* value 5, the one hdcp_rx_reset_port stores */
#define RECORD_KEY_EVENT_SEEN       0x40000000  /* bit 30 */
#define RECORD_DOWNSTREAM_REPORTED  0x400000    /* bit 22 */

/* States of the input protection state machine (record byte +0xD); see hdcp_rx_hdmi_task. */
enum hdcp_rx_state {
    HDCP_RX_STATE_WAIT_START       = 0,
    HDCP_RX_STATE_WAIT_START_AGAIN = 1,
    HDCP_RX_STATE_STARTED          = 2,
    HDCP_RX_STATE_KEY_SEQUENCE     = 3,
    HDCP_RX_STATE_NO_KEY_SEQUENCE  = 4,
    HDCP_RX_STATE_5                = 5,     /* left to state 7 by hdcp_rx_hdmi_recheck_ports */
    HDCP_RX_STATE_6                = 6,
    HDCP_RX_STATE_7                = 7,
    HDCP_RX_STATE_WAIT_DONE        = 8,
    HDCP_RX_STATE_RESTART_OUTPUTS  = 9,
    HDCP_RX_STATE_RESTARTED        = 10,
    HDCP_RX_STATE_AUTHED           = 13     /* printed as "FSM_HDCP22_AUTHED" */
};

#define FIRST_HDMI21_INPUT  2           /* input number of hdcp_rx_record_hdmi21[0] */
#define OUTPUT_DP           2           /* outputs 0, 1 are HDMI, output 2 is DisplayPort */
#define KEY_STATE_FREE      0xff        /* hdcp_rx_hdmi21_key_state: no HDMI 2.1 input is in the key sequence */
#define START_WAIT_READS    3000        /* reads of register 0xA9 while waiting for bit 6 */
#define HDCP2_BYTES_LENGTH  8

extern struct hdcp_rx_record hdcp_rx_record_hdmi21[];
extern unsigned char hdcp_rx_hdmi21_key_state;
extern unsigned char hdcp_rx_restart_bits;
extern unsigned char hdcp_rx_hdmi_task_byte;
extern unsigned char hdcp_rx_hdmi_hdcp2_bytes[];
extern int dbg_printf(const char *, ...);
extern unsigned char hdmi_rx21_reg_read8(unsigned char, unsigned short);
extern void hdmi_rx21_reg_write8(unsigned char, unsigned short, unsigned char);
extern void hdmi_rx21_reg_update_bits(unsigned char, unsigned short, unsigned char, unsigned char);
extern void hdmi_tx_reg_update_bits(unsigned char, int, int, int, int);
extern void hdcp_tx_reg_update_bits(unsigned char, unsigned short, unsigned char, unsigned char);
extern void hdcp_rx_step_hdcp2_bytes(unsigned char *);
extern unsigned char hdcp_rx_key_load_step(unsigned char);
extern unsigned char hdcp_rx_hdmi21_watch_counters(unsigned char);
extern void hdcp_rx_update_port_status(unsigned char);

/*
 * One pass of the copy-protection state machine of HDMI 2.1 inputs 2 and 3 (receivers 0 and 1).
 * Called by input_run_port_services after hdcp_rx_hdmi_task; the same state machine as that one, on other
 * registers.
 *
 * Registers 0xA8, 0xA9 and 0xAA of the receiver hold event bits: the task tests a bit and writes the same bit
 * back once it has acted on it. Most other writes go through four registers: a value to 0xA6, 0 (or 2 / 0x20)
 * to 0xA4, an index to 0xA5, the data to 0xA7, and 0x20 to 0xA4 at the end. Below "(a6, a5) = v" stands for
 * such a write.
 *
 * Per input, in order:
 *   1. Stop the whole pass, receiver 1 included, unless record bits 24..26 hold 5.
 *   2. Start event (bit 0 of 0xA8): back to state 0 and key step 0.
 *   3. output = the lowest output whose bit is set in output_bits (unchanged when none is set: then the
 *      value of receiver 0, or 0).
 *   4. The state machine below.
 *   5. hdcp_rx_update_port_status updates the input's status bit from the new state.
 *
 * Differences from hdcp_rx_hdmi_task: no events of every state other than the start event; in states 0/1
 * and 9 the output writes are made without looking at output_bits and nothing is written for the
 * DisplayPort output; state 9 waits for downstream_reported before it moves on; a failed counter check
 * prints "Re-auth".
 */
void hdcp_rx_hdmi21_task(void)
{
    unsigned char output = 0;
    unsigned char rx;
    unsigned char n;
    unsigned short reads;
    struct hdcp_rx_record *record;

    for (rx = 0; rx < 2; rx++) {
        record = &hdcp_rx_record_hdmi21[rx];
        /* 1. */
        if ((record->head.word & RECORD_BITS_24_26) != RECORD_BITS_24_26_READY)
            return;
        /* 2. Start event: begin again. The bit stays set for state 0 below. */
        if (hdmi_rx21_reg_read8(rx, 0xa8) & 1) {
            record->state = HDCP_RX_STATE_WAIT_START;
            record->key_step = 0;
        }
        /* 3. The output this input is shown on. */
        if (record->output_bits & 1)
            output = 0;
        else if (record->output_bits & 2)
            output = 1;
        else if (record->output_bits & 4)
            output = 2;
        /* 4. The state machine. */
        switch (record->state) {
        case HDCP_RX_STATE_WAIT_START:
        case HDCP_RX_STATE_WAIT_START_AGAIN:
            if (hdmi_rx21_reg_read8(rx, 0xa8) & 1) {
                /* Step the 8 bytes on and write them to indices 0xA..0x11 at 0xA6 = 0xA (0xA4 = 2). */
                hdcp_rx_step_hdcp2_bytes(hdcp_rx_hdmi_hdcp2_bytes);
                hdmi_rx21_reg_write8(rx, 0xa6, 0xa);
                hdmi_rx21_reg_write8(rx, 0xa4, 2);
                reads = 0;
                for (n = 0; n < HDCP2_BYTES_LENGTH; n++) {
                    hdmi_rx21_reg_write8(rx, 0xa5, n + 0xa);
                    hdmi_rx21_reg_write8(rx, 0xa7, hdcp_rx_hdmi_hdcp2_bytes[n]);
                }
                /* (8, 0) = 0 and (8, 1) = 0. */
                hdmi_rx21_reg_write8(rx, 0xa6, 8);
                hdmi_rx21_reg_write8(rx, 0xa4, 0);
                for (n = 0; n < 2; n++) {
                    hdmi_rx21_reg_write8(rx, 0xa5, n);
                    hdmi_rx21_reg_write8(rx, 0xa7, 0);
                }
                hdmi_rx21_reg_write8(rx, 0xa9, 0x60);
                /* Wait for bit 6 of 0xA9, at most 3000 reads; the task goes on either way. */
                while (!(hdmi_rx21_reg_read8(rx, 0xa9) & 0x40) && reads < START_WAIT_READS)
                    reads++;
                /* Bits 0 and 2 set at (1, 1); (9, 0) = 2. */
                hdmi_rx21_reg_write8(rx, 0xa6, 1);
                hdmi_rx21_reg_write8(rx, 0xa4, 0);
                hdmi_rx21_reg_write8(rx, 0xa5, 1);
                hdmi_rx21_reg_update_bits(rx, 0xa7, 5, 1);
                hdmi_rx21_reg_write8(rx, 0xa6, 9);
                hdmi_rx21_reg_write8(rx, 0xa4, 0);
                hdmi_rx21_reg_write8(rx, 0xa5, 0);
                hdmi_rx21_reg_write8(rx, 0xa7, 2);
                hdmi_rx21_reg_write8(rx, 0xa8, 0xff);   /* acknowledge every event of 0xA8 */
                hdmi_rx21_reg_write8(rx, 0xa9, 0x10);
                record->state = HDCP_RX_STATE_STARTED;
                /* The same writes as hdcp_tx_set_encryption_bit(output, 0) for an HDMI output, and bit 0 of
                   register 0x0F in bank 0 of its transmitter cleared. */
                if (output != OUTPUT_DP) {
                    hdcp_tx_reg_update_bits(output, 4, 0x10, 0);
                    hdmi_tx_reg_update_bits(output, 0, 0xf, 1, 0);
                }
                record->head.bits.bit23 = 0;
            }
            break;
        case HDCP_RX_STATE_STARTED:
            if (hdmi_rx21_reg_read8(rx, 0xa8) & 2) {
                hdmi_rx21_reg_write8(rx, 0xa8, 2);
                record->state = HDCP_RX_STATE_KEY_SEQUENCE;
                record->head.bits.keys_ready = 0;
                record->head.bits.key_event_seen = 0;
            } else if (hdmi_rx21_reg_read8(rx, 0xa8) & 4) {
                hdmi_rx21_reg_write8(rx, 0xa8, 4);
                record->state = HDCP_RX_STATE_NO_KEY_SEQUENCE;
            }
            break;
        case HDCP_RX_STATE_KEY_SEQUENCE:
            /* a. One key step per pass, while no other HDMI 2.1 input is in the sequence. */
            if (!record->head.bits.keys_ready) {
                if (hdcp_rx_hdmi21_key_state == KEY_STATE_FREE || hdcp_rx_hdmi21_key_state == rx + FIRST_HDMI21_INPUT)
                    record->head.bits.keys_ready = hdcp_rx_key_load_step(rx + FIRST_HDMI21_INPUT);
                record->head.bits.key_event_seen = 0;
            }
            /* b. Keys ready: wait for event bit 3 of 0xA8, then (9, 0) = 4. */
            if (record->head.bits.keys_ready && !record->head.bits.key_event_seen) {
                if (hdmi_rx21_reg_read8(rx, 0xa8) & 8) {
                    hdmi_rx21_reg_write8(rx, 0xa8, 8);
                    hdmi_rx21_reg_write8(rx, 0xa6, 9);
                    hdmi_rx21_reg_write8(rx, 0xa4, 0);
                    hdmi_rx21_reg_write8(rx, 0xa5, 0);
                    hdmi_rx21_reg_write8(rx, 0xa7, 4);
                    hdmi_rx21_reg_write8(rx, 0xa4, 0x20);
                    record->head.bits.key_event_seen = 1;
                }
            }
            /* c. Then wait until bits 2..4 of (9, 2) are clear: acknowledge bit 4 of 0xA8, (9, 0) = 8. */
            if (record->head.word & RECORD_KEY_EVENT_SEEN) {
                hdmi_rx21_reg_write8(rx, 0xa6, 9);
                hdmi_rx21_reg_write8(rx, 0xa4, 0x20);
                hdmi_rx21_reg_write8(rx, 0xa5, 2);
                if (!(hdmi_rx21_reg_read8(rx, 0xa7) & 0x1c)) {
                    hdmi_rx21_reg_write8(rx, 0xa8, 0x10);
                    hdmi_rx21_reg_write8(rx, 0xa4, 0);
                    hdmi_rx21_reg_write8(rx, 0xa5, 0);
                    hdmi_rx21_reg_write8(rx, 0xa7, 8);
                    hdmi_rx21_reg_write8(rx, 0xa4, 0x20);
                    record->state = HDCP_RX_STATE_5;
                }
            }
            break;
        case HDCP_RX_STATE_NO_KEY_SEQUENCE:
            if (hdmi_rx21_reg_read8(rx, 0xa8) & 8) {
                hdmi_rx21_reg_write8(rx, 0xa8, 8);
                hdmi_rx21_reg_write8(rx, 0xa6, 9);
                hdmi_rx21_reg_write8(rx, 0xa4, 0);
                hdmi_rx21_reg_write8(rx, 0xa5, 0);
                hdmi_rx21_reg_write8(rx, 0xa7, 4);
                hdmi_rx21_reg_write8(rx, 0xa4, 0x20);
                record->state = HDCP_RX_STATE_5;
            }
            break;
        case HDCP_RX_STATE_7:
            if (hdmi_rx21_reg_read8(rx, 0xa8) & 0x80) {
                hdmi_rx21_reg_write8(rx, 0xa8, 0x80);
                record->state = HDCP_RX_STATE_WAIT_DONE;
            }
            break;
        case HDCP_RX_STATE_WAIT_DONE:
            if (hdmi_rx21_reg_read8(rx, 0xa9) & 1) {
                hdmi_rx21_reg_write8(rx, 0xa9, 1);
                record->head.bits.watch_hold = 1;
                if ((hdcp_rx_restart_bits >> (rx + FIRST_HDMI21_INPUT)) & 1) {
                    record->state = HDCP_RX_STATE_RESTART_OUTPUTS;
                    hdcp_rx_hdmi_task_byte = 0;
                } else {
                    record->state = HDCP_RX_STATE_AUTHED;
                    dbg_printf("HDMI21 %2x FSM_HDCP22_AUTHED\r\n", rx);
                }
            }
            break;
        case HDCP_RX_STATE_RESTART_OUTPUTS:
            /* The output writes of state 0/1 on every pass; once the downstream report is written, pulse
               (9, 0) = 0, 0x20, 0 and go on to state 10. */
            if (output != OUTPUT_DP) {
                hdcp_tx_reg_update_bits(output, 4, 0x10, 0);
                hdmi_tx_reg_update_bits(output, 0, 0xf, 1, 0);
            }
            if (record->head.word & RECORD_DOWNSTREAM_REPORTED) {
                hdmi_rx21_reg_write8(rx, 0xa6, 9);
                hdmi_rx21_reg_write8(rx, 0xa4, 0);
                hdmi_rx21_reg_write8(rx, 0xa5, 0);
                hdmi_rx21_reg_write8(rx, 0xa7, 0);
                hdmi_rx21_reg_write8(rx, 0xa7, 0x20);
                hdmi_rx21_reg_write8(rx, 0xa7, 0);
                hdmi_rx21_reg_write8(rx, 0xa4, 0x20);
                record->state = HDCP_RX_STATE_RESTARTED;
            }
            break;
        case HDCP_RX_STATE_RESTARTED:
        case HDCP_RX_STATE_AUTHED:
            /* Counter check failed: (8, 1) = 8 and no events in this pass. */
            if (hdcp_rx_hdmi21_watch_counters(rx)) {
                dbg_printf("HDMI21 %02x Re-auth\r\n", rx);
                hdmi_rx21_reg_write8(rx, 0xa4, 0);
                hdmi_rx21_reg_write8(rx, 0xa5, 1);
                hdmi_rx21_reg_write8(rx, 0xa6, 8);
                hdmi_rx21_reg_write8(rx, 0xa7, 8);
                break;
            }
            /* Events of register 0xAA. Bit 0 waits while hdcp_rx_hdmi_task_byte is 1 (set by bit 6, cleared
               by bit 7). */
            if ((hdmi_rx21_reg_read8(rx, 0xaa) & 1) && hdcp_rx_hdmi_task_byte == 0) {
                /* (8, 1) = 4 and (9, 0) = 0x40. */
                hdmi_rx21_reg_write8(rx, 0xaa, 1);
                hdmi_rx21_reg_write8(rx, 0xa6, 8);
                hdmi_rx21_reg_write8(rx, 0xa4, 0);
                hdmi_rx21_reg_write8(rx, 0xa5, 1);
                hdmi_rx21_reg_write8(rx, 0xa7, 4);
                hdmi_rx21_reg_write8(rx, 0xa4, 0x20);
                hdmi_rx21_reg_write8(rx, 0xa6, 9);
                hdmi_rx21_reg_write8(rx, 0xa4, 0);
                hdmi_rx21_reg_write8(rx, 0xa5, 0);
                hdmi_rx21_reg_write8(rx, 0xa7, 0x40);
                hdmi_rx21_reg_write8(rx, 0xa4, 0x20);
            }
            if (hdmi_rx21_reg_read8(rx, 0xaa) & 2) {
                /* (8, 1) = 0. */
                hdmi_rx21_reg_write8(rx, 0xaa, 2);
                hdmi_rx21_reg_write8(rx, 0xa6, 8);
                hdmi_rx21_reg_write8(rx, 0xa4, 0);
                hdmi_rx21_reg_write8(rx, 0xa5, 1);
                hdmi_rx21_reg_write8(rx, 0xa7, 0);
                hdmi_rx21_reg_write8(rx, 0xa4, 0x20);
            }
            if (hdmi_rx21_reg_read8(rx, 0xaa) & 4)
                hdmi_rx21_reg_write8(rx, 0xaa, 4);
            if (hdmi_rx21_reg_read8(rx, 0xaa) & 0x40) {
                hdmi_rx21_reg_write8(rx, 0xaa, 0x40);
                hdcp_rx_hdmi_task_byte = 1;
            }
            hdmi_rx21_reg_read8(rx, 0xaa);
            if (hdmi_rx21_reg_read8(rx, 0xaa) & 0x20) {
                /* Bit 5: acknowledged together with bits 3 and 4; (9, 0) = 0x80. */
                hdmi_rx21_reg_write8(rx, 0xaa, 0x38);
                hdmi_rx21_reg_write8(rx, 0xa6, 9);
                hdmi_rx21_reg_write8(rx, 0xa4, 0);
                hdmi_rx21_reg_write8(rx, 0xa5, 0);
                hdmi_rx21_reg_write8(rx, 0xa7, 0x80);
                hdmi_rx21_reg_write8(rx, 0xa4, 0x20);
            }
            if (hdmi_rx21_reg_read8(rx, 0xaa) & 0x80) {
                hdmi_rx21_reg_write8(rx, 0xaa, 0x80);
                hdcp_rx_hdmi_task_byte = 0;
            }
            break;
        }
        /* 5. */
        hdcp_rx_update_port_status(rx + FIRST_HDMI21_INPUT);
    }
}
