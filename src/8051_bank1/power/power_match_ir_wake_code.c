/* power_match_ir_wake_code  (FUN_CODE_82d2)
 *
 * Decode infrared pulses and compare them with the wake-up remote code.
 * Returns: 1 when the code matched
 * Name basis: derived - samples from sys_ir_ring_read_byte (IR pulse ring of irq_record_ir_pulse); pattern
 *   table 0xA5F9 in the standby table
 *
 * Matching notes
 * --------------
 * Compiler flags: OPTIMIZE(8,SPEED) LARGE.
 * LARGE locals: sample at XDATA 0xA474, unused_zeros[16] at 0xA475 (initialised from 16 zero bytes at CODE 0x9955
 *   with ?C?COPY and not used further; it stays because the copy is in the firmware).
 * volatile on the code table: the firmware reads byte 1 again after the store to bits and code[step] again for
 *   the 0xFF test. step, bits and bit_count are one 3-byte object (INC DPTR between them).
 * Source forms: the 16-bit compare is '(unsigned int)(code[1] & 0x7f) < sample'; the loop is 'for (;;)' with
 *   'break' to the shared 'return 0' at the end.
 */

/* Layout of the 6-byte infrared wake-up code (part of the standby key table that the main processor sends with
 * message 8). */
#define IR_CODE_LEAD             0     /* pulse length that starts a code */
#define IR_CODE_FORMAT           1     /* bit 7: bit order; bits 6..0: pulse length above which a bit is 1 */
#define IR_CODE_FIRST_BYTE       2     /* bytes 2..5: expected code bytes */
#define IR_CODE_END              6
#define IR_FORMAT_FIRST_IN_BIT0  0x80  /* set: the first pulse ends up in bit 0 of the byte, else in bit 7 */
#define IR_FORMAT_THRESHOLD      0x7f
#define IR_BYTE_ANY              0xff  /* an expected byte of 0xFF accepts every byte */
#define IR_BYTE_NONE             0     /* an expected byte of 0 ends the code early */
#define IR_LEAD_TOLERANCE        8     /* lib_is_within_distance limit for the lead pulse */
#define IR_STEP_IDLE             0
#define BITS_PER_BYTE            8

struct ir_match_state {
    unsigned char step;       /* 0 = waiting for the lead pulse, else index of the code byte being collected */
    unsigned char bits;       /* bits of the current byte so far */
    unsigned char bit_count;  /* pulses taken into the current byte */
};
extern struct ir_match_state xdata power_ir_match_state;
extern unsigned char volatile xdata power_key_table_ir_code[6];
unsigned char sys_ir_ring_is_empty(void);
unsigned char sys_ir_ring_read_byte(void);
unsigned char lib_is_within_distance(unsigned char a, unsigned char b, unsigned char limit);
void ipc_write_shared_byte(unsigned char value, unsigned char index);

/* Feed every pulse length waiting in the IR ring through the wake-code matcher.
 * Only caller: sys_scan_keys_and_ir, during the standby scan.
 * Returns 1 as soon as a whole code has matched, 0 when the ring is empty without a match. The state survives
 * between calls, so a code can arrive over several calls.
 *
 * Per pulse:
 *   - waiting (step 0): a pulse within 8 of the lead length starts a code: step 2, bits cleared, and 2 is written
 *     to shared byte 0 (ipc_write_shared_byte);
 *   - collecting: the pulse becomes one bit (1 when longer than the threshold), shifted in from the side the
 *     format byte selects. After 8 pulses the byte is compared with code[step]: when it matches (or code[step] is
 *     0xFF) it is written to shared byte step - 1 and the next code byte follows; otherwise the matcher starts
 *     over at step 0.
 * The code is complete when step reaches 6, or earlier when code[step] is 0 (with code[2] = 0 the lead pulse alone
 * is a match); the matcher then goes back to step 0 and returns 1.
 */
unsigned char power_match_ir_wake_code(void)
{
    unsigned char sample;
    unsigned char unused_zeros[16] = {0};

    for (;;) {
        if (sys_ir_ring_is_empty())
            break;
        sample = sys_ir_ring_read_byte();
        if (power_ir_match_state.step == IR_STEP_IDLE) {
            /* Wait for the lead pulse. */
            if (lib_is_within_distance(power_key_table_ir_code[IR_CODE_LEAD], sample, IR_LEAD_TOLERANCE)) {
                power_ir_match_state.step = IR_CODE_FIRST_BYTE;
                power_ir_match_state.bits = 0;
                power_ir_match_state.bit_count = 0;
                ipc_write_shared_byte(2, 0);
            }
        } else {
            /* One more bit of the current byte. */
            power_ir_match_state.bit_count++;
            if (power_key_table_ir_code[IR_CODE_FORMAT] & IR_FORMAT_FIRST_IN_BIT0) {
                power_ir_match_state.bits >>= 1;
                if ((unsigned int)(power_key_table_ir_code[IR_CODE_FORMAT] & IR_FORMAT_THRESHOLD) < sample)
                    power_ir_match_state.bits |= 0x80;
            } else {
                power_ir_match_state.bits <<= 1;
                if ((unsigned int)(power_key_table_ir_code[IR_CODE_FORMAT] & IR_FORMAT_THRESHOLD) < sample)
                    power_ir_match_state.bits |= 0x01;
            }
            if (power_ir_match_state.bit_count == BITS_PER_BYTE) {
                /* Byte complete: compare it with the expected one. */
                if (power_ir_match_state.bits == power_key_table_ir_code[power_ir_match_state.step] || power_key_table_ir_code[power_ir_match_state.step] == IR_BYTE_ANY) {
                    ipc_write_shared_byte(power_ir_match_state.bits, power_ir_match_state.step - 1);
                    power_ir_match_state.step++;
                    power_ir_match_state.bit_count = 0;
                    power_ir_match_state.bits = 0;
                } else {
                    power_ir_match_state.step = IR_STEP_IDLE;
                }
            }
        }
        /* Whole code seen? */
        if (power_ir_match_state.step >= IR_CODE_END || (power_ir_match_state.step >= IR_CODE_FIRST_BYTE && power_key_table_ir_code[power_ir_match_state.step] == IR_BYTE_NONE)) {
            power_ir_match_state.step = IR_STEP_IDLE;
            return 1;
        }
    }
    return 0;
}
