/* hdcp_tx_dp_state_read_bksv  (FUN_a00ccfa8)
 *
 * State handler: read the receiver's five key-selection bytes over AUX and check them.
 * Name basis: descriptive - one state handler of the per-output copy-protection state machine; called from
 *   hdcp_tx_dp_run_state; DPCD 0x68000, five bytes with a bit-count check (20 ones)
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00ccfa8 @ 0xa00ccfa8-0xa00cd2f0, flags -mcpu=v8 -Os -g.
 * Source forms the exact build depends on:
 *  - the retry loop is 'do { v = read; if (v) break; } while (--tries != 0xff);';
 *  - two unsigned char counters (i, tries) are shared by all the loops;
 *  - the wait loop leaves through 'goto fail' to the STEP_BACK block of the bit-count test (firmware block
 *    order);
 *  - register words are accessed through a volatile unsigned int macro.
 */

/* Protection record of an output (24 bytes, docs/DATA.md; the fields used here). */
struct hdcp_tx_record {
    unsigned int bits_29_31 : 3;
    unsigned int repeater : 1;          /* bit 28: set here from AUX 0x68028 bit 1 */
    unsigned int tries_left : 4;        /* bits 24..27 */
    unsigned int bit23 : 1;
    unsigned int bits_18_22 : 5;
    unsigned int step_result : 2;       /* bits 16..17: STEP_* below, read by hdcp_tx_select_next_state */
    unsigned int state : 8;             /* +2 */
    unsigned char rest[20];
};

/* Result of a state handler. hdcp_tx_select_next_state picks the next state from it; for this state (0x11):
   STEP_NEXT -> 0x12, STEP_BACK -> 1, STEP_AGAIN -> state kept. */
enum {
    STEP_BACK  = 0,
    STEP_NEXT  = 1,
    STEP_AGAIN = 3
};

#define AUX_CMD_READ        0x90
#define AUX_CMD_WRITE       0x80
#define AUX_BKSV            0x68000     /* the receiver's five key-selection bytes */
#define AUX_STATUS          0x68028     /* bit 0 must be set; bit 1 = repeater */
#define AUX_REPEATER        0x6803b     /* receives the repeater bit as one byte */
#define AUX_WRITE_A         0x6800c     /* receives 8 bytes (length argument 7) */
#define AUX_WRITE_B         0x68007     /* receives 5 bytes (length argument 4) */
#define AUX_TRIES           4           /* reads of each BKSV byte before the last result is kept */

#define BKSV_LENGTH         5
#define BKSV_ONES           20          /* a valid key-selection value has 20 bits set */
#define WAIT_LIMIT          100         /* checks (one delay unit each) the wait for the control bit may take */

#define REG_WORD(index) (0xcf000000 | ((index) << 2))
#define REG(address) (*(volatile unsigned int *)(address))
#define REG_HDCP_TX_DP_CONTROL  0xcf018d00      /* bit 5: set here, read back clear when done */
#define CONTROL_BIT5            0x20
#define REG_DP_CONTROL_54       0xcf018d54      /* bit 0 follows the repeater bit */
#define DP_REG_BKSV         0x6350      /* register words 0x6350..0x6354: the receiver's BKSV, stored here */
#define DP_REG_6341         0x6341      /* register words 0x6341..0x6348, sent to AUX_WRITE_A */
#define DP_REG_6349         0x6349      /* register words 0x6349..0x634D, sent to AUX_WRITE_B */

extern struct hdcp_tx_record hdcp_tx_records[];
extern unsigned char dp_tx_aux_request_copy(int, int, int, int, unsigned char *);
extern int dp_tx_aux_request(unsigned int, unsigned int, unsigned int, unsigned int, unsigned char *);
extern int dbg_printf(const char *, ...);
extern void timer_delay_long_units(unsigned int);

/*
 * State 0x11 of the DisplayPort output: read the receiver's five key-selection bytes over AUX, check that
 * 20 of their 40 bits are set, then let the transmitter take them and pass two blocks of register words
 * back to the receiver.
 *
 *   port  the output, 2
 *
 * Called by hdcp_tx_dp_run_state in state 0x11. AUX channel 0 is used throughout. The result is step_result:
 * STEP_NEXT when everything went through; STEP_AGAIN when the first AUX read fails; STEP_BACK when bit 0 of
 * the status byte is clear, the key-selection bits are not 20, or control bit 5 is still set after 101 waits.
 *
 * In order:
 *   1. Read the status byte (AUX 0x68028). Bit 1 sets the record's repeater bit and bit 0 of register
 *      0xCF018D54; otherwise both are cleared. Write that bit as one byte to AUX 0x6803B. Print 'BKSV = '.
 *   2. For each of the five bytes at AUX 0x68000..0x68004: up to four reads until one succeeds; store the
 *      byte in register word 0x6350 + i (DP_REG_BKSV) and print the value read back.
 *   3. Count the set bits of the five bytes; not 20 gives STEP_BACK.
 *   4. Set bit 5 of the DP protection control register (0xCF018D00) and wait for it to read 0, one delay
 *      unit per check; after 101 checks give STEP_BACK.
 *   5. Take the low bytes of register words 0x6341..0x6348 and write them to AUX 0x6800C (length argument 7);
 *      take register words 0x6349..0x634D and write them to AUX 0x68007 (length argument 4).
 */
void hdcp_tx_dp_state_read_bksv(unsigned char port)
{
    unsigned char bytes[8];
    unsigned char status;
    unsigned char i;
    unsigned char j;                    /* retry and loop counter, shared by all the loops */
    unsigned char value;
    unsigned char ones;

    hdcp_tx_records[port].step_result = STEP_NEXT;
    if (dp_tx_aux_request_copy(0, AUX_CMD_READ, AUX_STATUS, 0, &status) == 0) {
        hdcp_tx_records[port].step_result = STEP_AGAIN;
        return;
    }
    if ((status & 1) == 0) {
        hdcp_tx_records[port].step_result = STEP_BACK;
        return;
    }
    if (status & 2) {
        hdcp_tx_records[port].repeater = 1;
        REG(REG_DP_CONTROL_54) |= 1;
        bytes[0] = 1;
        dp_tx_aux_request(0, AUX_CMD_WRITE, AUX_REPEATER, 0, bytes);
    } else {
        hdcp_tx_records[port].repeater = 0;
        REG(REG_DP_CONTROL_54) &= ~1;
        bytes[0] = 0;
        dp_tx_aux_request(0, AUX_CMD_WRITE, AUX_REPEATER, 0, bytes);
    }
    dbg_printf("\nBKSV = ");
    for (i = 0; i < BKSV_LENGTH; i++) {
        j = AUX_TRIES - 1;
        do {
            value = dp_tx_aux_request_copy(0, AUX_CMD_READ, AUX_BKSV + i, 0, &bytes[i]);
            if (value)
                break;
        } while (--j != 0xff);
        REG(REG_WORD(i + DP_REG_BKSV)) = bytes[i];
        dbg_printf("%02X ", (unsigned short)REG(REG_WORD(i + DP_REG_BKSV)));
    }
    ones = 0;
    for (j = 0; j < BKSV_LENGTH; j++) {
        value = bytes[j];
        for (i = 0; i < 8; i++) {
            if (value & 1)
                ones++;
            value >>= 1;
        }
    }
    if (ones != BKSV_ONES) {
fail:
        hdcp_tx_records[port].step_result = STEP_BACK;
        return;
    }
    REG(REG_HDCP_TX_DP_CONTROL) |= CONTROL_BIT5;
    j = 0;
    while (REG(REG_HDCP_TX_DP_CONTROL) & CONTROL_BIT5) {
        timer_delay_long_units(1);
        j++;
        if (j > WAIT_LIMIT)
            goto fail;
    }
    for (j = 0; j < 8; j++)
        bytes[j] = REG(REG_WORD(j + DP_REG_6341));
    dp_tx_aux_request(0, AUX_CMD_WRITE, AUX_WRITE_A, 7, bytes);
    for (j = 0; j < 5; j++)
        bytes[j] = REG(REG_WORD(j + DP_REG_6349));
    dp_tx_aux_request(0, AUX_CMD_WRITE, AUX_WRITE_B, 4, bytes);
}
