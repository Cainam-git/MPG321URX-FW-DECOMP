/* hdcp_tx_dp_state_compare_reads  (FUN_a00cd31c)
 *
 * State handler: read the AUX status and value bytes, compare them with two registers, switch protection on.
 * Name basis: descriptive - one state handler of the per-output copy-protection state machine; called from
 *   hdcp_tx_dp_run_state
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00cd31c @ 0xa00cd31c-0xa00cd4fc, flags -mcpu=v8 -Os -g.
 * Source forms the exact build depends on: the block that calls hdcp_tx_dp_set_enable stands between the bit 1
 * test and the attempt loop and is reached by goto (its position in the source gives the firmware's block
 * order); the first loop ends on 'more & !(buf[0] & 2)' with more = i < 3 in its own variable (flag arithmetic,
 * no branch). The registers are volatile words.
 */

#define AUX_CMD_READ        0x90
#define AUX_STATUS_BYTE     0x68029     /* one byte: bit 0 -> STEP_OTHER, bit 1 must be set to go on */
#define AUX_VALUE_PAIR      0x68005     /* two bytes, compared with the two registers below */
#define READ_TRIES          3
#define WAIT_LIMIT          30          /* waits of one delay unit for the busy bit */

/* Registers of the DisplayPort protection block. */
#define DP_REG_CONTROL      (*(volatile unsigned int *)0xcf018d00)   /* bit 2 is set here and clears when done;
                                                                        bit 1 is the enable bit of
                                                                        hdcp_tx_dp_set_enable */
#define DP_REG_VALUE_0      (*(volatile unsigned int *)0xcf018d38)   /* compared with the first byte read */
#define DP_REG_VALUE_1      (*(volatile unsigned int *)0xcf018d3c)   /* compared with the second byte read */

/* Protection record of an output (24 bytes, docs/DATA.md; the fields used here). */
struct hdcp_tx_record {
    unsigned int bits_29_31 : 3;
    unsigned int repeater : 1;          /* bit 28 */
    unsigned int tries_left : 4;        /* bits 24..27 */
    unsigned int bit23 : 1;
    unsigned int bits_18_22 : 5;
    unsigned int step_result : 2;       /* bits 16..17: STEP_* below, read by hdcp_tx_select_next_state */
    unsigned int state : 8;             /* +2 */
    unsigned char device_count;         /* +3 */
    unsigned char level;                /* +4 */
    unsigned char count_overflow;       /* +5 */
    unsigned char level_overflow;       /* +6 */
    unsigned char pad[17];
};
enum {
    STEP_BACK  = 0,
    STEP_NEXT  = 1,
    STEP_OTHER = 2,
    STEP_AGAIN = 3
};
extern struct hdcp_tx_record hdcp_tx_records[];
extern int dp_tx_aux_request_copy(int, int, int, int, unsigned char *);
extern void timer_delay_long_units(unsigned int);
extern void hdcp_tx_dp_set_enable(unsigned int);

/*
 * State 0x13 of the DisplayPort output: read the receiver's status byte until it shows bit 1, then check the
 * two bytes it holds against two registers of the protection block, and switch the protection on when they
 * match.
 *
 *   port  the output, 2
 *
 * Called by hdcp_tx_dp_run_state in state 0x13. It reports through step_result (STEP_*); hdcp_tx_select_next_state
 * picks the next state from it.
 *
 * Order:
 *   1. step_result = STEP_NEXT.
 *   2. Read the status byte (AUX 0x68029, channel 0, a 2-unit delay after each read), at most 3 times, until
 *      bit 1 is set. Bit 0 set (checked after the loop) gives STEP_OTHER. Bit 1 still clear gives STEP_BACK
 *      and ends the routine.
 *   3. Up to 3 attempts: set bit 2 of the control register and wait (1-unit delays) until it clears; more than
 *      30 waits give STEP_BACK. Then read two bytes (AUX 0x68005); when they equal the two value registers,
 *      switch the protection on with hdcp_tx_dp_set_enable(1) and return (step_result as set in step 2).
 *   4. After the third attempt the same comparison is made once more on the bytes already read: equal returns
 *      without switching on, different gives STEP_BACK.
 */
void hdcp_tx_dp_state_compare_reads(unsigned char port)
{
    unsigned char buf[2];
    unsigned char i;
    unsigned char k;
    unsigned int more;

    hdcp_tx_records[port].step_result = STEP_NEXT;
    i = 0;
    do {
        dp_tx_aux_request_copy(0, AUX_CMD_READ, AUX_STATUS_BYTE, 0, buf);
        timer_delay_long_units(2);
        i++;
        more = i < READ_TRIES;
    } while (more & !(buf[0] & 2));
    if (buf[0] & 1)
        hdcp_tx_records[port].step_result = STEP_OTHER;
    if (!(buf[0] & 2))
        goto fail;
    goto loop;
ok:
    hdcp_tx_dp_set_enable(1);
    return;
loop:
    for (k = 0; k < READ_TRIES; k++) {
        DP_REG_CONTROL |= 4;
        for (i = 0; DP_REG_CONTROL & 4; ) {
            timer_delay_long_units(1);
            i++;
            if (i > WAIT_LIMIT)
                goto fail;
        }
        dp_tx_aux_request_copy(0, AUX_CMD_READ, AUX_VALUE_PAIR, 1, buf);
        if (buf[0] == DP_REG_VALUE_0 && buf[1] == DP_REG_VALUE_1)
            goto ok;
    }
    if (buf[0] == DP_REG_VALUE_0 && buf[1] == DP_REG_VALUE_1)
        return;
fail:
    hdcp_tx_records[port].step_result = STEP_BACK;
}
