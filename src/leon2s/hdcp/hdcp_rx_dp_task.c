/* hdcp_rx_dp_task  (FUN_a00c44e4)
 *
 * Run the copy-protection state machine of the DisplayPort inputs.
 * Name basis: derived - records at 0xA807D608, registers 0x400..0x40E; called from input_run_port_services
 *
 * Matching notes
 * --------------
 * FUN_a00c44e4 (leon2s 0xa00c44e4-0xa00c4e4c, 2408 bytes), flags -mcpu=v8 -Os -g.
 * The switch compiles to the jump table at 0xa00c44ac (linked at 0x9f1b44ac).
 * Source forms the exact build depends on: word 0 is a union of the word, a bit-field view and its bytes;
 * the record pointer is built in a block-local pointer (p = hdcp_rx_record_dp; p += rx; record = p;), which
 * keeps the first load of each pass as ld [record] instead of a register-plus-register address; pass_flags
 * and saved are zero-initialised arrays; bit21 is read twice from register 0x401.
 */

/* Word 0 of a protection record, as bit-fields (bit 31 first). */
struct hdcp_rx_record_bits {
    unsigned int keys_ready : 1;            /* bit 31: hdcp_rx_key_load_step has finished its sequence */
    unsigned int key_event_seen : 1;        /* bit 30: the event that follows the key sequence was seen */
    unsigned int bits_24_29 : 6;
    unsigned int bit23 : 1;                 /* copied to the output records by input_update_port_records */
    unsigned int downstream_reported : 1;   /* bit 22: set by input_update_port_records after the report */
    unsigned int bit21 : 1;                 /* copied to bit 20 of the output records, same routine */
    unsigned int bits_0_20 : 21;
};

/* Protection record of an input (16 bytes). hdcp_rx_record_dp[0] and [1] are records 4 and 5 of the six
   that start at hdcp_rx_record_hdmi20; the routines that take the input number 0..5 get input + 4. */
struct hdcp_rx_record {
    union {
        unsigned int word;
        struct hdcp_rx_record_bits bits;
        unsigned char bytes[4];             /* bytes[3] = byte_0x3 (bits 0..7) */
    } head;
    unsigned char bytes_4_11[0xc - 4];
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
    HDCP_RX_STATE_WAIT_START_AGAIN = 1,     /* entered from states 10 / 13 on bit 6 of 0x409 */
    HDCP_RX_STATE_STARTED          = 2,
    HDCP_RX_STATE_KEY_SEQUENCE     = 3,
    HDCP_RX_STATE_NO_KEY_SEQUENCE  = 4,
    HDCP_RX_STATE_5                = 5,
    HDCP_RX_STATE_6                = 6,
    HDCP_RX_STATE_7                = 7,
    HDCP_RX_STATE_WAIT_DONE        = 8,
    HDCP_RX_STATE_RESTART_OUTPUTS  = 9,
    HDCP_RX_STATE_RESTARTED        = 10,
    HDCP_RX_STATE_AUTHED           = 13     /* printed as "HDCP22 AUTHED" */
};

#define FIRST_DP_INPUT      4           /* input number of hdcp_rx_record_dp[0] */
#define KEY_STATE_FREE      0xff        /* hdcp_rx_dp_key_state: no DisplayPort input is in the key sequence */
#define HDCP2_BYTES_LENGTH  8
#define READ_BACK_PENDING   4           /* the one element of pass_flags in use */

extern struct hdcp_rx_record hdcp_rx_record_dp[];
extern unsigned char hdcp_rx_dp_key_state;
extern unsigned char hdcp_rx_restart_bits;
extern unsigned char hdcp_rx_dp_hdcp2_bytes[];
extern int dbg_printf(const char *, ...);
extern unsigned int dp_reg_read8(unsigned char, unsigned short);
extern void dp_reg_write8(unsigned char, unsigned short, unsigned char);
extern void dp_reg_update_bits(unsigned char, unsigned short, unsigned char, unsigned char);
extern void timer_delay_units(unsigned int);
extern void hdcp_rx_step_hdcp2_bytes(unsigned char *);
extern unsigned char hdcp_rx_key_load_step(unsigned char);
extern void hdcp_rx_update_port_status(unsigned char);

/*
 * One pass of the copy-protection state machine of DisplayPort inputs 4 and 5 (receivers 0 and 1).
 * Called by input_run_port_services after hdcp_rx_hdmi_task and hdcp_rx_hdmi21_task; the same states as
 * those, on the DisplayPort receiver's registers.
 *
 * Registers 0x408 and 0x409 hold event bits: the task tests a bit and writes it back once it has acted on
 * it. Blocks of bytes go through register 0x401 (with 0x400, 0x402 and 0x403 set first; in the long
 * sequence of states 10 / 13 each byte's position is written to 0x403 before its value).
 *
 * Per receiver, in order:
 *   1. Stop the whole pass, receiver 1 included, unless record bits 24..26 hold 5.
 *   2. Start event (bit 0 of 0x408): back to state 0 and key step 0.
 *   3. The state machine below.
 *   4. hdcp_rx_update_port_status updates the input's status bit from the new state.
 *
 * Differences from the HDMI tasks: no output writes; state 3 and 4 lead to state 6, and states 5 / 6 are
 * handled here; state 0 clears downstream_reported, which input_update_port_records sets again after its next
 * report (hdcp_repeater_collect_status for these inputs); bit23 is set on reaching state 13; there is no counter check, and in states 10 / 13 an event
 * (bit 3 of 0x409) starts a read-back sequence, after which state 9 waits until bit 4 of 0x409 has been seen.
 *
 * pass_flags[READ_BACK_PENDING] marks that sequence; it is a local array, zero at the start of every call.
 */
void hdcp_rx_dp_task(void)
{
    unsigned char pass_flags[5] = { 0 };
    unsigned char saved[3] = { 0 };     /* bytes 0..2 read back in the sequence of states 10 / 13 */
    unsigned char rx;
    unsigned int value, offset;
    unsigned short n;
    struct hdcp_rx_record *record;

    for (rx = 0; rx < 2; rx++) {
        {
            struct hdcp_rx_record *p = hdcp_rx_record_dp;

            p += rx;
            record = p;
        }
        /* 1. */
        if ((record->head.word & RECORD_BITS_24_26) != RECORD_BITS_24_26_READY)
            return;
        /* 2. Start event: begin again. The bit stays set for state 0 below. */
        if (dp_reg_read8(rx, 0x408) & 1) {
            record->state = HDCP_RX_STATE_WAIT_START;
            record->key_step = 0;
        }
        /* 3. The state machine. */
        switch (record->state) {
        case HDCP_RX_STATE_WAIT_START:
        case HDCP_RX_STATE_WAIT_START_AGAIN:
            if (dp_reg_read8(rx, 0x408) & 1) {
                record->head.bits.downstream_reported = 0;
                pass_flags[READ_BACK_PENDING] = 0;
                /* Step the 8 bytes on and write them through 0x401 (0x400 = 3, 0x403 = 0). */
                hdcp_rx_step_hdcp2_bytes(hdcp_rx_dp_hdcp2_bytes);
                dp_reg_update_bits(rx, 0, 0x20, 0);
                dp_reg_write8(rx, 0x400, 3);
                dp_reg_update_bits(rx, 0x402, 0x80, 1);
                dp_reg_write8(rx, 0x403, 0);
                for (n = 0; n < HDCP2_BYTES_LENGTH; n++)
                    dp_reg_write8(rx, 0x401, hdcp_rx_dp_hdcp2_bytes[n]);
                dp_reg_write8(rx, 0x408, 1);
                /* 7 to register 0x404, one delay unit, then 1. */
                dp_reg_write8(rx, 0x404, 7);
                timer_delay_units(1);
                dp_reg_write8(rx, 0x404, 1);
                record->state = HDCP_RX_STATE_STARTED;
                dp_reg_update_bits(rx, 0, 0x20, 0);
                record->head.bits.bit23 = 0;
            }
            break;
        case HDCP_RX_STATE_STARTED:
            /* Bit 2 or bit 3 of 0x408; each is acknowledged together with bit 1. */
            if (dp_reg_read8(rx, 0x408) & 4) {
                dp_reg_write8(rx, 0x408, 6);
                record->state = HDCP_RX_STATE_KEY_SEQUENCE;
                record->head.bits.keys_ready = 0;
                record->head.bits.key_event_seen = 0;
            } else if (dp_reg_read8(rx, 0x408) & 8) {
                dp_reg_write8(rx, 0x408, 0xa);
                record->state = HDCP_RX_STATE_NO_KEY_SEQUENCE;
            }
            break;
        case HDCP_RX_STATE_KEY_SEQUENCE:
            /* a. One key step per pass, while no other DisplayPort input is in the sequence. */
            if (!record->head.bits.keys_ready) {
                if (hdcp_rx_dp_key_state == KEY_STATE_FREE || hdcp_rx_dp_key_state == rx + FIRST_DP_INPUT)
                    record->head.bits.keys_ready = hdcp_rx_key_load_step(rx + FIRST_DP_INPUT);
                record->head.bits.key_event_seen = 0;
            }
            /* b. Keys ready: event bit 4 of 0x408 leads to state 6. */
            if (record->head.bits.keys_ready && !record->head.bits.key_event_seen) {
                if (dp_reg_read8(rx, 0x408) & 0x10) {
                    dp_reg_write8(rx, 0x408, 0x10);
                    record->head.bits.key_event_seen = 1;
                    record->state = HDCP_RX_STATE_6;
                }
            }
            /* c. After it, event bit 5 of 0x408 also leads to state 6 and clears bit 5 of register 0. */
            if (record->head.word & RECORD_KEY_EVENT_SEEN) {
                if (dp_reg_read8(rx, 0x408) & 0x20) {
                    dp_reg_write8(rx, 0x408, 0x20);
                    record->state = HDCP_RX_STATE_6;
                    dp_reg_update_bits(rx, 0, 0x20, 0);
                }
            }
            break;
        case HDCP_RX_STATE_NO_KEY_SEQUENCE:
            if (dp_reg_read8(rx, 0x408) & 0x10) {
                dp_reg_write8(rx, 0x408, 0x10);
                record->state = HDCP_RX_STATE_6;
                dp_reg_update_bits(rx, 0, 0x20, 0);
            }
            break;
        case HDCP_RX_STATE_5:
        case HDCP_RX_STATE_6:
            if (dp_reg_read8(rx, 0x408) & 0x40) {
                dp_reg_update_bits(rx, 0, 0x20, 0);
                dp_reg_write8(rx, 0x408, 0x40);
                record->state = HDCP_RX_STATE_7;
            }
            break;
        case HDCP_RX_STATE_7:
            if (dp_reg_read8(rx, 0x408) & 0x80) {
                dp_reg_write8(rx, 0x408, 0x80);
                record->state = HDCP_RX_STATE_WAIT_DONE;
            }
            break;
        case HDCP_RX_STATE_WAIT_DONE:
            if (dp_reg_read8(rx, 0x409) & 1) {
                dp_reg_write8(rx, 0x409, 1);
                if ((hdcp_rx_restart_bits >> (rx + FIRST_DP_INPUT)) & 1) {
                    record->state = HDCP_RX_STATE_RESTART_OUTPUTS;
                } else {
                    record->head.bits.bit23 = 1;
                    record->state = HDCP_RX_STATE_AUTHED;
                    dbg_printf("DP%2x HDCP22 AUTHED\r\n", rx);
                }
            }
            break;
        case HDCP_RX_STATE_RESTART_OUTPUTS:
            /* Once the downstream report is written and no read-back is pending in this call: bit 5 of
               register 0 cleared, bit 4 of 0x405 pulsed, on to state 10. */
            if ((record->head.word & RECORD_DOWNSTREAM_REPORTED) && pass_flags[READ_BACK_PENDING] == 0) {
                dp_reg_update_bits(rx, 0, 0x20, 0);
                dp_reg_update_bits(rx, 0x405, 0x10, 0);
                dp_reg_update_bits(rx, 0x405, 0x10, 1);
                dp_reg_update_bits(rx, 0x405, 0x10, 0);
                record->state = HDCP_RX_STATE_RESTARTED;
            }
            break;
        case HDCP_RX_STATE_RESTARTED:
        case HDCP_RX_STATE_AUTHED:
            if (dp_reg_read8(rx, 0x409) & 2)
                dp_reg_write8(rx, 0x409, 2);
            if (dp_reg_read8(rx, 0x409) & 4)
                dp_reg_write8(rx, 0x409, 4);
            /* Bit 6: set bit 7 of 0x40E and go back to waiting for the start event. */
            if (dp_reg_read8(rx, 0x409) & 0x40) {
                dp_reg_write8(rx, 0x409, 0x40);
                dp_reg_update_bits(rx, 0x40e, 0x80, 1);
                record->state = HDCP_RX_STATE_WAIT_START_AGAIN;
            }
            /* Bit 3: the read-back sequence. */
            if (dp_reg_read8(rx, 0x409) & 8) {
                dp_reg_write8(rx, 0x409, 8);
                pass_flags[READ_BACK_PENDING] = 1;
                /* a. 0x90 to 0x406 and wait (no limit) until bit 7 reads clear. */
                dp_reg_write8(rx, 0x406, 0x90);
                while (dp_reg_read8(rx, 0x406) & 0x80)
                    ;
                /* b. Read 8 bytes through 0x401 (0x400 = 0xD, 0x402 = 0x80, 0x403 = 0): bytes 0..2 kept,
                      byte 3 dropped, byte 4 into byte_0x3 (twice it is the offset used below), bytes 5 and 6
                      into bit21 (bit 0 of each; the second read wins). */
                dp_reg_write8(rx, 0x400, 0xd);
                dp_reg_write8(rx, 0x402, 0x80);
                dp_reg_write8(rx, 0x403, 0);
                saved[0] = dp_reg_read8(rx, 0x401);
                saved[1] = dp_reg_read8(rx, 0x401);
                saved[2] = dp_reg_read8(rx, 0x401);
                dp_reg_read8(rx, 0x401);
                value = dp_reg_read8(rx, 0x401);
                record->head.bytes[3] = value;
                offset = value * 2;
                record->head.bits.bit21 = dp_reg_read8(rx, 0x401);
                record->head.bits.bit21 = dp_reg_read8(rx, 0x401);
                /* c. Set bit 5 of 0x40E and wait (no limit) until it reads clear. */
                dp_reg_update_bits(rx, 0x40e, 0x20, 1);
                while (dp_reg_read8(rx, 0x40e) & 0x20)
                    ;
                /* d. Write back with 0x402 = 0x90, position to 0x403 and value to 0x401: positions 0..2 the
                      kept bytes, 4 byte_0x3, 6 bit21, offset + 5..7 the kept bytes again, offset + 8 0x80. */
                dp_reg_write8(rx, 0x402, 0x90);
                dp_reg_write8(rx, 0x403, 0);
                dp_reg_write8(rx, 0x401, saved[0]);
                dp_reg_write8(rx, 0x403, 1);
                dp_reg_write8(rx, 0x401, saved[1]);
                dp_reg_write8(rx, 0x403, 2);
                dp_reg_write8(rx, 0x401, saved[2]);
                dp_reg_write8(rx, 0x403, 4);
                dp_reg_write8(rx, 0x401, record->head.bytes[3]);
                dp_reg_write8(rx, 0x403, 6);
                dp_reg_write8(rx, 0x401, record->head.bits.bit21);
                dp_reg_write8(rx, 0x403, offset + 5);
                dp_reg_write8(rx, 0x401, saved[0]);
                dp_reg_write8(rx, 0x403, offset + 6);
                dp_reg_write8(rx, 0x401, saved[1]);
                dp_reg_write8(rx, 0x403, offset + 7);
                dp_reg_write8(rx, 0x401, saved[2]);
                dp_reg_write8(rx, 0x403, offset + 8);
                dp_reg_write8(rx, 0x401, 0x80);
                /* e. 0x402 = 0, bit 0 of 0x405 set, 1 to 0x40A, bit 5 of 0x405 pulsed; bit23 set. */
                dp_reg_write8(rx, 0x402, 0);
                dp_reg_update_bits(rx, 0x405, 1, 1);
                dp_reg_write8(rx, 0x40a, 1);
                dp_reg_update_bits(rx, 0x405, 0x20, 1);
                dp_reg_update_bits(rx, 0x405, 0x20, 0);
                record->head.bits.bit23 = 1;
                /* f. With 0x400 = 0x12 and 0x402 = 0x90: bit21 to positions 8, 9 and 10; then 0x400 = 0. */
                dp_reg_write8(rx, 0x400, 0x12);
                dp_reg_write8(rx, 0x402, 0x90);
                dp_reg_write8(rx, 0x403, 8);
                dp_reg_write8(rx, 0x401, record->head.bits.bit21);
                dp_reg_write8(rx, 0x403, 9);
                dp_reg_write8(rx, 0x401, record->head.bits.bit21);
                dp_reg_write8(rx, 0x403, 0xa);
                dp_reg_write8(rx, 0x401, record->head.bits.bit21);
                dp_reg_write8(rx, 0x400, 0);
            }
            /* Bit 4: the read-back is no longer pending. */
            if (dp_reg_read8(rx, 0x409) & 0x10) {
                dp_reg_write8(rx, 0x409, 0x10);
                pass_flags[READ_BACK_PENDING] = 0;
            }
            break;
        }
        /* 4. */
        hdcp_rx_update_port_status(rx + FIRST_DP_INPUT);
    }
}
