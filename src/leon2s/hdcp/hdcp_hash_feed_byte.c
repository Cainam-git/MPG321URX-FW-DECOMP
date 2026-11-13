/* hdcp_hash_feed_byte  (FUN_a00ca074)
 *
 * Feed one byte to the hash block at 0xCF018E00; at counter 0 run the start sequence after it.
 * Name basis: derived - registers 0xCF018E04..0xCF018E14 of the hash block (64-byte blocks, counter reloaded
 *   with 0x3F); callers hdcp_rx_dp_calculate_v and hdcp_tx_hash_message_buffer
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00ca074 @ 0xa00ca074-0xa00ca130 (47 words), flags -mcpu=v8 -Os -g.
 * Source form: the '== 0' arm comes first and stores the data byte in both arms; all registers are 32-bit
 * volatile words.
 */
#define R(a) (*(volatile unsigned int *)(a))

#define HASH_REG_E04            0xcf018e04      /* receives the data byte */
#define HASH_REG_E0C            0xcf018e0c      /* counter, see below */
#define HASH_REG_E10            0xcf018e10
#define HASH_REG_E14            0xcf018e14      /* control: bits 0, 2 and 7 are set, then polled until they read 0 */
#define MODE_BIT0_STEP          0xaa            /* mode value that starts the step with bit 0 instead of bit 2 */
#define E0C_RELOAD              0x3f            /* value written to the counter after a full start-up sequence */

/*
 * Give one data byte to the hash block at 0xcf018e00 (64-byte blocks; also used by hdcp_rx_dp_calculate_v and
 * hdcp_tx_hash_message_buffer).
 *
 * Register 0xcf018e0c is used as a counter. While it is 0 the byte is written to register 0xcf018e04 and a full
 * start-up sequence runs: bit 0 of register 0xcf018e14 is set when mode is 0xaa (bit 2 for any other mode) and
 * waited on until it reads 0, register 0xcf018e10 is set to 0x1f, bit 7 of 0xcf018e14 is set and
 * waited on in the same way, and the counter is set to 0x3f. While the counter is not 0 only the byte is written and the
 * counter is decremented.
 */
void hdcp_hash_feed_byte(unsigned char mode, unsigned char data)
{
    if (R(HASH_REG_E0C) == 0) {
        R(HASH_REG_E04) = data;
        if (mode == MODE_BIT0_STEP) {
            R(HASH_REG_E14) |= 1;
            while (R(HASH_REG_E14) & 1)
                ;
        } else {
            R(HASH_REG_E14) |= 4;
            while (R(HASH_REG_E14) & 4)
                ;
        }
        R(HASH_REG_E10) = 0x1f;
        R(HASH_REG_E14) |= 0x80;
        while (R(HASH_REG_E14) & 0x80)
            ;
        R(HASH_REG_E0C) = E0C_RELOAD;
    } else {
        R(HASH_REG_E04) = data;
        R(HASH_REG_E0C) = R(HASH_REG_E0C) - 1;
    }
}
