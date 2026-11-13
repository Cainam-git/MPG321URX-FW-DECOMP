/* hdcp_tx_dp_state_read_message  (FUN_a00cd5e4)
 *
 * State handler: read a two-byte header and a data block over AUX and pass them to the hardware.
 * Name basis: descriptive - one state handler of the per-output copy-protection state machine; called from
 *   hdcp_tx_dp_run_state
 *
 * Matching notes
 * --------------
 * FUN_a00cd5e4 (leon2s, 0xa00cd5e4-0xa00cdb0c, 1320 bytes), flags -mcpu=v8 -Os -g.
 * Source forms the exact build depends on: the count argument of the AUX read is a signed char (sign-extended
 * left - 1), with the 'left <= 14' call first; the block position is advanced as 'k++; k = k % 15;' (unsigned
 * char); the two length byte writes use (unsigned char) casts. All hash block registers are volatile 32-bit words.
 */

/* Protection record of an output (24 bytes, docs/DATA.md; the fields used here). */
struct hdcp_tx_record {
    unsigned int bits_29_31 : 3;
    unsigned int repeater : 1;          /* word 0 bit 28: set by hdcp_tx_dp_state_read_bksv from AUX 0x68028 bit 1 */
    unsigned int tries_left : 4;        /* bits 24..27: 3 on entry to this state */
    unsigned int bit23 : 1;
    unsigned int bits_18_22 : 5;
    unsigned int step_result : 2;       /* bits 16..17: STEP_* below, read by hdcp_tx_select_next_state */
    unsigned int state : 8;             /* +2: the state hdcp_tx_dp_run_state dispatches on */
    unsigned char device_count;         /* +3: status byte 0 & 0x7F */
    unsigned char level;                /* +4: status byte 1 & 7 */
    unsigned char count_overflow;       /* +5: status byte 0 bit 7 */
    unsigned char level_overflow;       /* +6: status byte 1 bit 3 */
    unsigned char pad[17];
};

/* Result of a state handler. hdcp_tx_select_next_state picks the next state from it; for this state (0x15):
   STEP_NEXT -> 0x16, STEP_BACK and STEP_OTHER -> 1, STEP_AGAIN -> state kept (hdcp_tx_service_port turns it
   into STEP_BACK when tries_left has reached 0). */
enum {
    STEP_BACK  = 0,
    STEP_NEXT  = 1,
    STEP_OTHER = 2,
    STEP_AGAIN = 3
};

#define AUX_CMD_READ        0x90
#define AUX_STATUS          0x6802a     /* the two status bytes */
#define AUX_LIST            0x6802c     /* the device list, read 15 bytes at a time */
#define AUX_VALUE           0x68014     /* 16 + 4 bytes compared with the hash block's output */
#define AUX_VALUE_TAIL      0x68024
#define LIST_READ_MAX       15

#define STATUS0_COUNT       0x7f        /* status byte 0: number of downstream devices */
#define STATUS0_OVERFLOW    0x80
#define STATUS1_LEVEL       7           /* status byte 1: level */
#define STATUS1_OVERFLOW    8
#define ENTRY_LENGTH        5           /* bytes per downstream device entry */

/* Registers of the hash block (also driven by hdcp_hash_feed_byte). */
#define XFER_REG_E00        0xcf018e00  /* 0x11 before the bytes, 0x22 after */
#define XFER_DATA           0xcf018e04  /* every byte passes through it; the result bytes are read from it */
#define XFER_REG_E08        0xcf018e08
#define XFER_COUNT          0xcf018e0c  /* counted down per byte by hdcp_hash_feed_byte, 0x3F after 0 */
#define XFER_REG_E10        0xcf018e10  /* 0x1F before each bit-7 start */
#define XFER_CONTROL        0xcf018e14  /* bits 0, 1, 2, 7 are set and read back clear when done */
#define XFER_REG_E18        0xcf018e18
#define XFER_LENGTH_HI      0xcf018e24
#define XFER_LENGTH_LO      0xcf018e28
#define XFER_STEP_DATA      0xaa        /* hdcp_hash_feed_byte: start with control bit 0 (else bit 2) */

#define R(a) (*(volatile unsigned int *)(a))
#define REG_WORD(index) (0xcf000000 | ((index) << 2))
#define DP_REG_BKSV         0x6350      /* register words 0x6350..0x6354: the receiver's BKSV, stored by
                                           hdcp_tx_dp_state_read_bksv */
#define DP_REG_637F         0x637f      /* register words 0x637F down to 0x6378 */

#define ENGINE_CMD_0B       0xb         /* hdcp_tx_engine_start_command code */
#define PROT_REG_DATA       1           /* protection block register: bytes to the engine */

extern struct hdcp_tx_record hdcp_tx_records[];
extern void hdcp_tx_reg_write(unsigned char, unsigned short, unsigned char);
extern void hdcp_tx_engine_start_command(unsigned char, unsigned char, unsigned short);
extern void hdcp_hash_feed_byte(unsigned char, unsigned char);
extern int dp_tx_aux_request_copy(int, int, int, signed char, unsigned char *);

/*
 * State 0x15 of the DisplayPort output: read the downstream device's two status bytes and its device list,
 * feed them to the engine and to the hash block, and compare the block's 20 result bytes with the 20
 * bytes the device holds.
 *
 *   port  the output, 2
 *
 * Called by hdcp_tx_dp_run_state in state 0x15 (hdcp_tx_select_next_state enters it from 0x14). The AUX
 * reads use channel 0. It reports through step_result (STEP_*).
 *
 * Phases, in order:
 *   1. step_result = STEP_NEXT; without the repeater bit STEP_BACK.
 *   2. Status bytes (AUX 0x6802A): bit 7 of byte 0 or bit 3 of byte 1 set the matching overflow byte and give
 *      STEP_OTHER; else device_count, level and the overflow bits (both 0) go into the record.
 *   3. Prepare the hash block: 0x1F to E10 and a bit-7 start, clear bit 0 of E18, E00 = 0x11, E08 = 0x10,
 *      count 0x3F, and a bit-1 start.
 *   4. Engine command 0x0B with 0x4015. The list (device_count * 5 bytes, AUX 0x6802C in reads of up to 15
 *      bytes) goes byte by byte to the hash block and to the engine.
 *   5. The BKSV (register words 0x6350..0x6354) to the engine; the two status bytes, register words 0x637F down
 *      to 0x6378 and 0x80 to the hash block.
 *   6. The byte count (list + 10) to E28 / E24. When the count register reads 6 or less, a bit-0 and a bit-7
 *      start first. The count times 8 to E04 (low byte with E0C = 0, high byte with E0C = 1), a bit-0 and a
 *      bit-7 start, E08 = 0, E00 = 0x22.
 *   7. Read 20 bytes (AUX 0x68014, 16 bytes, and 0x68024, 4 bytes), set bit 7 of E08 and compare them, each
 *      group of four in reverse order, with successive reads of E04. The first difference gives STEP_AGAIN and
 *      takes one off tries_left.
 */
void hdcp_tx_dp_state_read_message(unsigned char port)
{
    unsigned char status[2];
    unsigned char buf[20];
    unsigned short byte_count;
    unsigned short left;
    unsigned char k;
    unsigned char j;

    /* 1. */
    hdcp_tx_records[port].step_result = STEP_NEXT;
    if (hdcp_tx_records[port].repeater == 0) {
        hdcp_tx_records[port].step_result = STEP_BACK;
        return;
    }
    /* 2. Status bytes; an overflow bit set by the device takes the other way out. */
    dp_tx_aux_request_copy(0, AUX_CMD_READ, AUX_STATUS, 1, status);
    if (status[0] & STATUS0_OVERFLOW) {
        hdcp_tx_records[port].count_overflow = 1;
        hdcp_tx_records[port].step_result = STEP_OTHER;
        return;
    }
    if (status[1] & STATUS1_OVERFLOW) {
        hdcp_tx_records[port].level_overflow = 1;
        hdcp_tx_records[port].step_result = STEP_OTHER;
        return;
    }
    hdcp_tx_records[port].device_count = status[0] & STATUS0_COUNT;
    hdcp_tx_records[port].level = status[1] & STATUS1_LEVEL;
    hdcp_tx_records[port].count_overflow = status[0] >> 7;
    hdcp_tx_records[port].level_overflow = (status[1] >> 3) & 1;
    /* 3. Hash block set-up. */
    R(XFER_REG_E10) = 0x1f;
    R(XFER_CONTROL) |= 0x80;
    while (R(XFER_CONTROL) & 0x80)
        ;
    R(XFER_REG_E18) &= ~1;
    R(XFER_REG_E00) = 0x11;
    R(XFER_REG_E08) = 0x10;
    R(XFER_COUNT) = 0x3f;
    R(XFER_CONTROL) |= 2;
    while (R(XFER_CONTROL) & 2)
        ;
    /* 4. The device list, fetched 15 bytes at a time. */
    byte_count = (status[0] & STATUS0_COUNT) * ENTRY_LENGTH;
    hdcp_tx_engine_start_command(port, ENGINE_CMD_0B, 0x4015);
    k = 0;
    left = byte_count;
    while (left != 0) {
        if (k == 0) {
            if (left <= LIST_READ_MAX - 1)
                dp_tx_aux_request_copy(0, AUX_CMD_READ, AUX_LIST, left - 1, buf);
            else
                dp_tx_aux_request_copy(0, AUX_CMD_READ, AUX_LIST, LIST_READ_MAX - 1, buf);
        }
        hdcp_hash_feed_byte(XFER_STEP_DATA, buf[k]);
        hdcp_tx_reg_write(port, PROT_REG_DATA, buf[k]);
        k++;
        k = k % LIST_READ_MAX;
        left--;
    }
    /* 5. */
    for (k = 0; k < 5; k++)
        hdcp_tx_reg_write(port, PROT_REG_DATA, R(REG_WORD(k + DP_REG_BKSV)) & 0xff);
    hdcp_hash_feed_byte(XFER_STEP_DATA, status[0]);
    hdcp_hash_feed_byte(XFER_STEP_DATA, status[1]);
    for (k = 0; k < 8; k++)
        hdcp_hash_feed_byte(XFER_STEP_DATA, R(REG_WORD(DP_REG_637F - k)) & 0xff);
    hdcp_hash_feed_byte(XFER_STEP_DATA, 0x80);
    /* 6. The byte count and the count times 8, then start. */
    byte_count = byte_count + 10;
    R(XFER_LENGTH_LO) = (unsigned char)byte_count;
    R(XFER_LENGTH_HI) = (unsigned char)(byte_count >> 8);
    if (R(XFER_COUNT) <= 6) {
        R(XFER_CONTROL) |= 1;
        while (R(XFER_CONTROL) & 1)
            ;
        R(XFER_REG_E10) = 0x1f;
        R(XFER_CONTROL) |= 0x80;
        while (R(XFER_CONTROL) & 0x80)
            ;
    }
    R(XFER_COUNT) = 0;
    R(XFER_DATA) = (byte_count << 3) & 0xff;
    R(XFER_COUNT) = 1;
    R(XFER_DATA) = ((byte_count << 3) >> 8) & 0xff;
    R(XFER_CONTROL) |= 1;
    while (R(XFER_CONTROL) & 1)
        ;
    R(XFER_REG_E10) = 0x1f;
    R(XFER_CONTROL) |= 0x80;
    while (R(XFER_CONTROL) & 0x80)
        ;
    R(XFER_REG_E08) = 0;
    R(XFER_REG_E00) = 0x22;
    /* 7. The device's 20 bytes against the block's output. */
    dp_tx_aux_request_copy(0, AUX_CMD_READ, AUX_VALUE, 0xf, buf);
    dp_tx_aux_request_copy(0, AUX_CMD_READ, AUX_VALUE_TAIL, 3, buf + 16);
    R(XFER_REG_E08) |= 0x80;
    for (k = 0; k < 5; k++)
        for (j = 0; j < 4; j++)
            if (buf[k * 4 + 3 - j] != (R(XFER_DATA) & 0xff)) {
                hdcp_tx_records[port].step_result = STEP_AGAIN;
                hdcp_tx_records[port].tries_left--;
                return;
            }
}
