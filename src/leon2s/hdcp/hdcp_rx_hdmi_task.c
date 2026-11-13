/* hdcp_rx_hdmi_task  (FUN_a00c32f4)
 *
 * Run the copy-protection state machine of the two HDMI 2.0 inputs.
 * Name basis: derived - 16-byte records at 0xA807D5C8; called from input_run_port_services
 *
 * Matching notes
 * --------------
 * FUN_a00c32f4 (leon2s 0xa00c32f4-0xa00c3ab0, 1980 bytes), flags -mcpu=v8 -Os -g.
 * The switch compiles to the jump table at 0xa00c32bc (linked at 0x9f1b32bc).
 * Source forms the exact build depends on: word 0 is a union of the word and a bit-field view (mask tests on
 * the word, single bits written as fields); in state 2 the state byte is written before the two bit clears;
 * the register reads are declared with an unsigned char result (the callee returns the low byte); the extra
 * read of register 0x31A before the bit-5 test is in the firmware.
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

/* Protection record of an input (16 bytes; the six records lie one after the other, inputs 0, 1 here). */
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

/* States of the input protection state machine (record byte +0xD), shared by the HDMI 2.0, HDMI 2.1 and
   DisplayPort tasks. hdcp_rx_update_port_status sets the input's status bit in states 2..12 and clears it in
   state 13. */
enum hdcp_rx_state {
    HDCP_RX_STATE_WAIT_START       = 0,     /* wait for the start event */
    HDCP_RX_STATE_WAIT_START_AGAIN = 1,     /* the same; entered from state 10 / 13 by the DisplayPort task */
    HDCP_RX_STATE_STARTED          = 2,     /* wait for one of two events: to state 3 or state 4 */
    HDCP_RX_STATE_KEY_SEQUENCE     = 3,     /* run hdcp_rx_key_load_step, then wait for events */
    HDCP_RX_STATE_NO_KEY_SEQUENCE  = 4,     /* wait for the event that ends state 3, without the key steps */
    HDCP_RX_STATE_5                = 5,     /* HDMI: left to state 7 by hdcp_rx_hdmi_recheck_ports */
    HDCP_RX_STATE_6                = 6,
    HDCP_RX_STATE_7                = 7,
    HDCP_RX_STATE_WAIT_DONE        = 8,     /* wait for the event that leads to state 9 or 13 */
    HDCP_RX_STATE_RESTART_OUTPUTS  = 9,     /* input's bit in hdcp_rx_restart_bits was set */
    HDCP_RX_STATE_RESTARTED        = 10,
    HDCP_RX_STATE_AUTHED           = 13     /* printed as "HDCP22 AUTHED" */
};

#define OUTPUT_DP           2           /* outputs 0, 1 are HDMI, output 2 is DisplayPort */
#define KEY_STATE_FREE      0xff        /* hdcp_rx_hdmi_key_state: no HDMI 2.0 input is in the key sequence */
#define START_WAIT_READS    3000        /* reads of register 0x319 while waiting for bit 6 */
#define HDCP2_BYTES_LENGTH  8

extern struct hdcp_rx_record hdcp_rx_record_hdmi20[];
extern unsigned char hdcp_rx_hdmi_key_state;
extern unsigned char hdcp_rx_restart_bits;
extern unsigned char hdcp_rx_hdmi_task_byte;
extern unsigned char hdcp_rx_hdmi_hdcp2_bytes[];
/* reg_hdcp_tx_dp_control: control register of the DisplayPort output's protection block. */
#define REG_HDCP_TX_DP_CONTROL (*(volatile unsigned int *)0xcf018d00)
extern int dbg_printf(const char *, ...);
extern unsigned char hdmi_reg_read8(unsigned char, unsigned short);
extern void hdmi_reg_write8(unsigned char, unsigned short, unsigned char);
extern void hdmi_reg_update_bits(unsigned char, unsigned short, unsigned int, unsigned char);
extern void hdmi_tx_reg_update_bits(unsigned char, int, int, int, int);
extern void hdcp_tx_reg_update_bits(unsigned char, unsigned short, unsigned char, unsigned char);
extern void hdcp_rx_step_hdcp2_bytes(unsigned char *);
extern unsigned char hdcp_rx_key_load_step(unsigned char);
extern unsigned char hdcp_rx_hdmi_watch_counters(unsigned char);
extern void hdcp_rx_update_port_status(unsigned char);

/*
 * One pass of the copy-protection state machine of HDMI 2.0 inputs 0 and 1.
 * Called by input_run_port_services, which then calls hdcp_rx_hdmi21_task and hdcp_rx_dp_task.
 *
 * The registers 0x318, 0x319 and 0x31A of the receiver hold event bits: the task tests a bit and writes the
 * same bit back once it has acted on it.
 *
 * Per input, in order:
 *   1. output = the lowest output whose bit is set in output_bits (unchanged when none is set: then the value
 *      of input 0, or 0).
 *   2. Stop the whole pass, input 1 included, unless record bits 24..26 hold 5.
 *   3. Events handled in every state: 0x319 bit 4 (clears bit 7 of 0x31F; sets bit 2 of 0x305 when bit 1 of
 *      0x71 is set), 0x319 bit 1 (sets bit 7 of 0x31F), 0x318 bit 0 (start event: back to state 0, key step 0,
 *      3 to register 0x305).
 *   4. The state machine below.
 *   5. hdcp_rx_update_port_status updates the input's status bit from the new state.
 * States 5 and 6 are not handled here: hdcp_rx_hdmi_recheck_ports, the tick hook installed by InitHDCP,
 * moves them on to state 7.
 */
void hdcp_rx_hdmi_task(void)
{
    unsigned char output = 0;
    unsigned char input;
    unsigned short n, reads;
    struct hdcp_rx_record *record;

    for (input = 0; input < 2; input++) {
        record = &hdcp_rx_record_hdmi20[input];
        /* 1. The output this input is shown on. */
        if (record->output_bits & 1)
            output = 0;
        else if (record->output_bits & 2)
            output = 1;
        else if (record->output_bits & 4)
            output = 2;
        /* 2. */
        if ((record->head.word & RECORD_BITS_24_26) != RECORD_BITS_24_26_READY)
            return;
        /* 3. Events of every state. */
        if (hdmi_reg_read8(input, 0x319) & 0x10) {
            if (hdmi_reg_read8(input, 0x31f) & 0x80)
                hdmi_reg_update_bits(input, 0x31f, 0x80, 0);
            if (hdmi_reg_read8(input, 0x71) & 2)
                hdmi_reg_update_bits(input, 0x305, 4, 1);
            hdmi_reg_write8(input, 0x319, 0x10);
        }
        if (hdmi_reg_read8(input, 0x319) & 2) {
            if (!(hdmi_reg_read8(input, 0x31f) & 0x80))
                hdmi_reg_update_bits(input, 0x31f, 0x80, 1);
            hdmi_reg_write8(input, 0x319, 2);
        }
        if (hdmi_reg_read8(input, 0x318) & 1) {
            /* Start event: begin again. The bit stays set for state 0 below. */
            record->state = HDCP_RX_STATE_WAIT_START;
            record->key_step = 0;
            hdmi_reg_write8(input, 0x305, 3);
        }
        /* 4. The state machine. */
        switch (record->state) {
        case HDCP_RX_STATE_WAIT_START:
        case HDCP_RX_STATE_WAIT_START_AGAIN:
            if (hdmi_reg_read8(input, 0x318) & 1) {
                /* Step the 8 bytes on and write them to the receiver: 0x2D to register 0x310, then the bytes
                   to register 0x312. */
                hdcp_rx_step_hdcp2_bytes(hdcp_rx_hdmi_hdcp2_bytes);
                hdmi_reg_write8(input, 0x310, 0x2d);
                reads = 0;
                for (n = 0; n < HDCP2_BYTES_LENGTH; n++)
                    hdmi_reg_write8(input, 0x312, hdcp_rx_hdmi_hdcp2_bytes[n]);
                hdmi_reg_write8(input, 0x303, 0);
                hdmi_reg_write8(input, 0x304, 0);
                hdmi_reg_write8(input, 0x319, 0x60);
                /* Wait for bit 6 of 0x319, at most 3000 reads; the task goes on either way. */
                while (!(hdmi_reg_read8(input, 0x319) & 0x40) && reads < START_WAIT_READS)
                    reads++;
                hdmi_reg_update_bits(input, 0x31f, 0x80, 1);
                hdmi_reg_update_bits(input, 0x308, 2, 1);
                hdmi_reg_write8(input, 0x318, 0xff);    /* acknowledge every event of 0x318 */
                record->state = HDCP_RX_STATE_STARTED;
                if (record->output_bits != 0) {
                    /* Shown on an output: the same writes as hdcp_tx_set_encryption_bit(output, 0), and on an
                       HDMI output bit 0 of register 0x0F in bank 0 of its transmitter cleared. */
                    if (output != OUTPUT_DP) {
                        hdcp_tx_reg_update_bits(output, 4, 0x10, 0);
                        hdmi_tx_reg_update_bits(output, 0, 0xf, 1, 0);
                    } else {
                        REG_HDCP_TX_DP_CONTROL &= ~2;
                    }
                }
                record->head.bits.bit23 = 0;
            }
            break;
        case HDCP_RX_STATE_STARTED:
            if (hdmi_reg_read8(input, 0x318) & 2) {
                hdmi_reg_write8(input, 0x318, 2);
                record->state = HDCP_RX_STATE_KEY_SEQUENCE;
                record->head.bits.keys_ready = 0;
                record->head.bits.key_event_seen = 0;
            } else if (hdmi_reg_read8(input, 0x318) & 4) {
                hdmi_reg_write8(input, 0x318, 4);
                record->state = HDCP_RX_STATE_NO_KEY_SEQUENCE;
            }
            break;
        case HDCP_RX_STATE_KEY_SEQUENCE:
            /* a. One key step per pass, while no other HDMI 2.0 input is in the sequence. */
            if (!record->head.bits.keys_ready) {
                if (hdcp_rx_hdmi_key_state == KEY_STATE_FREE || hdcp_rx_hdmi_key_state == input)
                    record->head.bits.keys_ready = hdcp_rx_key_load_step(input);
                record->head.bits.key_event_seen = 0;
            }
            /* b. Keys ready: wait for event bit 3 of 0x318, then set bit 2 of 0x308. */
            if (record->head.bits.keys_ready && !record->head.bits.key_event_seen) {
                if (hdmi_reg_read8(input, 0x318) & 8) {
                    hdmi_reg_write8(input, 0x318, 8);
                    hdmi_reg_update_bits(input, 0x308, 4, 1);
                    record->head.bits.key_event_seen = 1;
                }
            }
            /* c. Then wait until bits 4..6 of 0x30A are clear: acknowledge bit 4 of 0x318, set bit 3 of 0x308. */
            if (record->head.word & RECORD_KEY_EVENT_SEEN) {
                if (!(hdmi_reg_read8(input, 0x30a) & 0x70)) {
                    hdmi_reg_write8(input, 0x318, 0x10);
                    hdmi_reg_update_bits(input, 0x308, 8, 1);
                    record->state = HDCP_RX_STATE_5;
                }
            }
            break;
        case HDCP_RX_STATE_NO_KEY_SEQUENCE:
            if (hdmi_reg_read8(input, 0x318) & 8) {
                hdmi_reg_write8(input, 0x318, 8);
                hdmi_reg_update_bits(input, 0x308, 4, 1);
                record->state = HDCP_RX_STATE_5;
            }
            break;
        case HDCP_RX_STATE_7:
            if (hdmi_reg_read8(input, 0x318) & 0x80) {
                hdmi_reg_write8(input, 0x318, 0x80);
                record->state = HDCP_RX_STATE_WAIT_DONE;
            }
            break;
        case HDCP_RX_STATE_WAIT_DONE:
            if (hdmi_reg_read8(input, 0x319) & 1) {
                hdmi_reg_write8(input, 0x319, 1);
                record->head.bits.watch_hold = 1;
                if ((hdcp_rx_restart_bits >> input) & 1) {
                    record->state = HDCP_RX_STATE_RESTART_OUTPUTS;
                    hdcp_rx_hdmi_task_byte = 0;
                } else {
                    record->state = HDCP_RX_STATE_AUTHED;
                    dbg_printf("HDMI %2x HDCP22 AUTHED\r\n", input);
                }
            }
            break;
        case HDCP_RX_STATE_RESTART_OUTPUTS:
            /* The same writes as hdcp_tx_set_encryption_bit(output, 0); on an HDMI output also bit 0 of
               protection register 0x0F cleared. Done whether or not output_bits has a bit set. */
            if (output != OUTPUT_DP) {
                hdcp_tx_reg_update_bits(output, 4, 0x10, 0);
                hdcp_tx_reg_update_bits(output, 0xf, 1, 0);
            } else {
                REG_HDCP_TX_DP_CONTROL &= ~2;
            }
            /* After the downstream report: pulse bit 5 of 0x308. */
            if (record->head.word & RECORD_DOWNSTREAM_REPORTED) {
                hdmi_reg_update_bits(input, 0x308, 0x20, 0);
                hdmi_reg_update_bits(input, 0x308, 0x20, 1);
                hdmi_reg_update_bits(input, 0x308, 0x20, 0);
            }
            record->state = HDCP_RX_STATE_RESTARTED;
            break;
        case HDCP_RX_STATE_RESTARTED:
        case HDCP_RX_STATE_AUTHED:
            /* Counter check failed, or bit 3 of 0x303 already set: keep bit 3 of 0x303 set and handle no
               events in this pass. (The HDMI 2.1 task prints "Re-auth" at this point.) */
            if (hdcp_rx_hdmi_watch_counters(input) || (hdmi_reg_read8(input, 0x303) & 8)) {
                hdmi_reg_update_bits(input, 0x303, 8, 1);
                break;
            }
            /* Events of register 0x31A, and bit 7 of 0x319. Bit 0 waits while hdcp_rx_hdmi_task_byte is 1
               (set by bit 6, cleared by bit 7 of 0x319). */
            if ((hdmi_reg_read8(input, 0x31a) & 1) && hdcp_rx_hdmi_task_byte == 0) {
                hdmi_reg_write8(input, 0x31a, 1);
                hdmi_reg_update_bits(input, 0x303, 4, 1);
                hdmi_reg_update_bits(input, 0x308, 0x40, 1);
            }
            if (hdmi_reg_read8(input, 0x31a) & 2) {
                hdmi_reg_write8(input, 0x31a, 2);
                hdmi_reg_update_bits(input, 0x303, 4, 0);
            }
            if (hdmi_reg_read8(input, 0x31a) & 4)
                hdmi_reg_write8(input, 0x31a, 4);
            if (hdmi_reg_read8(input, 0x31a) & 0x40) {
                hdmi_reg_write8(input, 0x31a, 0x40);
                hdcp_rx_hdmi_task_byte = 1;
            }
            hdmi_reg_read8(input, 0x31a);
            if (hdmi_reg_read8(input, 0x31a) & 0x20) {
                /* Bit 5: acknowledged together with bits 3 and 4; bit 7 of 0x308 set. */
                hdmi_reg_write8(input, 0x31a, 0x38);
                hdmi_reg_update_bits(input, 0x308, 0x80, 1);
            }
            if (hdmi_reg_read8(input, 0x319) & 0x80) {
                hdmi_reg_write8(input, 0x319, 0x80);
                hdcp_rx_hdmi_task_byte = 0;
            }
            break;
        }
        /* 5. */
        hdcp_rx_update_port_status(input);
    }
}
