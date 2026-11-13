/* hdcp_tx_check_stored_keys  (FUN_a00c6968)
 *
 * Compare a stored 3-byte sum with the sum computed over the first key set or the HDCP 2 data.
 * Returns: 1 when the sums agree, else 0 (also 0 for another argument)
 * Note: Argument 1: sum at store 0x142 over key block and key-selection value; 2: sum at 0x58A over the HDCP 2
 *   blocks. Command 0xFD.
 * Name basis: derived - blocks read with sys_otp_read_bytes; called for command 0xFD of the main processor
 *   with a one-byte reply
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00c6968 @ 0xa00c6968, flags -mcpu=v8 -Os -g (the section default).
 * Source form: each summing loop reads the byte into the unsigned char value and tests the buffer byte
 * itself: 'value = block[i]; if ((signed char)block[i] >= 0) sum += value; else { sum += (unsigned char)~value;
 * count_inverted++; }'. The loops are written out one after the other, not shared.
 */
extern void sys_otp_read_bytes(unsigned short, unsigned short, void *);

/* Addresses and lengths in the one-time-programmable store (sys_otp_read_bytes). */
#define OTP_SUM_FIRST        0x142  /* 3-byte stored sum for check 1 */
#define OTP_KEYS_FIRST       0x20   /* check 1 sums these 0x118 bytes (the first key set's key block) */
#define KEYS_FIRST_LENGTH    0x118
#define OTP_KSV_FIRST        0x138  /* and these 5 bytes (its key-selection value) */
#define KSV_LENGTH           5
#define OTP_SUM_SECOND       0x58a  /* 3-byte stored sum for check 2 */
#define OTP_HDCP2_VALUE      0x270  /* check 2 sums these 0x10 bytes */
#define HDCP2_VALUE_LENGTH   0x10
#define OTP_HDCP2_TABLE      0x280  /* these 0x20A bytes */
#define HDCP2_TABLE_LENGTH   0x20a
#define OTP_TABLE_MODE4      0x48a  /* these 0x80 bytes */
#define OTP_TABLE_MODE5      0x50a  /* and these 0x80 bytes */
#define TABLE_LENGTH         0x80
#define CHECK_FIRST_KEY_SET  1
#define CHECK_HDCP2_DATA     2

/*
 * Check the stored key data against the sum stored with it.
 *
 *   sel  which block to check: 1 = the first key set, 2 = the HDCP 2 data
 *
 * Returns 1 when the stored sum equals the sum computed over the data, 0 when it differs or sel is neither 1 nor 2.
 * Called for command 0xFD of the main processor (ipc_check_hdcp_stored_keys), which passes the argument
 * through and returns the result as a one-byte reply.
 *
 * The stored sum is a 3-byte value, least significant byte first. The computed value is the sum over every
 * byte of the data blocks listed below, where a byte below 0x80 adds itself and a byte of 0x80 or more adds
 * its bit complement (~b, 8 bits), plus the number of bytes of 0x80 or more. The blocks are read one after
 * the other into one buffer; the sums are in the order given:
 *   sel 1: sum at OTP_SUM_FIRST; data OTP_KEYS_FIRST (0x118 bytes), OTP_KSV_FIRST (5 bytes);
 *   sel 2: sum at OTP_SUM_SECOND; data OTP_HDCP2_VALUE (0x10), OTP_HDCP2_TABLE (0x20A),
 *          OTP_TABLE_MODE4 (0x80), OTP_TABLE_MODE5 (0x80).
 */
int hdcp_tx_check_stored_keys(unsigned char sel)
{
    unsigned char block[0x20a];
    unsigned int sum = 0;
    unsigned short count_inverted = 0;
    unsigned short i;
    unsigned char value;
    unsigned int stored_sum;

    if (sel == CHECK_FIRST_KEY_SET) {
        sys_otp_read_bytes(OTP_SUM_FIRST, 3, block);
        stored_sum = ((block[2] << 8) + block[1] << 8) + block[0];
        sys_otp_read_bytes(OTP_KEYS_FIRST, KEYS_FIRST_LENGTH, block);
        for (i = 0; i < KEYS_FIRST_LENGTH; i++) {
            value = block[i];
            if ((signed char)block[i] >= 0)
                sum += value;
            else {
                sum += (unsigned char)~value;
                count_inverted++;
            }
        }
        sys_otp_read_bytes(OTP_KSV_FIRST, KSV_LENGTH, block);
        for (i = 0; i < KSV_LENGTH; i++) {
            value = block[i];
            if ((signed char)block[i] >= 0)
                sum += value;
            else {
                sum += (unsigned char)~value;
                count_inverted++;
            }
        }
    } else if (sel == CHECK_HDCP2_DATA) {
        sys_otp_read_bytes(OTP_SUM_SECOND, 3, block);
        stored_sum = ((block[2] << 8) + block[1] << 8) + block[0];
        sys_otp_read_bytes(OTP_HDCP2_VALUE, HDCP2_VALUE_LENGTH, block);
        for (i = 0; i < HDCP2_VALUE_LENGTH; i++) {
            value = block[i];
            if ((signed char)block[i] >= 0)
                sum += value;
            else {
                sum += (unsigned char)~value;
                count_inverted++;
            }
        }
        sys_otp_read_bytes(OTP_HDCP2_TABLE, HDCP2_TABLE_LENGTH, block);
        for (i = 0; i < HDCP2_TABLE_LENGTH; i++) {
            value = block[i];
            if ((signed char)block[i] >= 0)
                sum += value;
            else {
                sum += (unsigned char)~value;
                count_inverted++;
            }
        }
        sys_otp_read_bytes(OTP_TABLE_MODE4, TABLE_LENGTH, block);
        for (i = 0; i < TABLE_LENGTH; i++) {
            value = block[i];
            if ((signed char)block[i] >= 0)
                sum += value;
            else {
                sum += (unsigned char)~value;
                count_inverted++;
            }
        }
        sys_otp_read_bytes(OTP_TABLE_MODE5, TABLE_LENGTH, block);
        for (i = 0; i < TABLE_LENGTH; i++) {
            value = block[i];
            if ((signed char)block[i] >= 0)
                sum += value;
            else {
                sum += (unsigned char)~value;
                count_inverted++;
            }
        }
    } else
        return 0;
    return stored_sum == sum + count_inverted;
}
