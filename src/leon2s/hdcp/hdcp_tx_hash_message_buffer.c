/* hdcp_tx_hash_message_buffer  (FUN_a00ca4e8)
 *
 * Hash bytes 1..138 of the message buffer in the block at 0xCF018E00 and store the 32 result bytes.
 * Note: Takes no parameter; used by the HDMI and the DisplayPort output state machines.
 * Name basis: derived - block at 0xCF018E00: 64-byte data blocks, end mark 0x80, bit length 0x450 (138 bytes),
 *   32 result bytes into hdcp_tx_result_block; called by hdcp_tx_hdmi_state_read_message and
 *   hdcp_tx_dp_state_read_hdcp2_messages
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00ca4e8 @ 0xa00ca4e8-0xa00ca6d4, -mcpu=v8 -Os -g.
 * Declared void with no parameter: the callers pass &hdcp_tx_message_buffer[1], which is not used (the routine
 * reads the buffer by its name). The last loop has its own counter variable. The block registers are accessed
 * through macros of volatile 32-bit words.
 */
extern unsigned char hdcp_tx_message_buffer[];
extern unsigned char hdcp_tx_result_block[];

/* Registers of the hash block at 0xCF018E00 (also driven by hdcp_rx_dp_calculate_v and
   hdcp_hash_feed_byte), 32 bits each. Data goes in and out through R04; R0C counts down from 0x3f as
   bytes are written; R14 holds start bits that clear themselves. */
#define R00 (*(volatile unsigned int *)0xcf018e00)
#define R04 (*(volatile unsigned int *)0xcf018e04)
#define R08 (*(volatile unsigned int *)0xcf018e08)
#define R0C (*(volatile unsigned int *)0xcf018e0c)
#define R10 (*(volatile unsigned int *)0xcf018e10)
#define R14 (*(volatile unsigned int *)0xcf018e14)
#define R18 (*(volatile unsigned int *)0xcf018e18)

#define MESSAGE_LAST_INDEX 0x8a         /* bytes 1..0x8a of the message buffer are written: 138 bytes */
#define RESULT_LAST_INDEX  0x1f         /* 32 result bytes */

/*
 * Write the 138 bytes hdcp_tx_message_buffer[1..0x8a] and four more bytes (0x80, then 0x50, 4, 0, 0) into the
 * hash block, start it, and read 32 bytes of its result into hdcp_tx_result_block.
 *
 * Called by hdcp_tx_hdmi_state_read_message (when bit 19 of the output's record is clear) and by hdcp_tx_dp_state_read_hdcp2_messages; it takes no parameter.
 *
 * Order:
 *  1. R10 = 0x1b, R14 = 0x80, bit 0 of R18 cleared, R00 = 0x11, R14 = 8 (waited for until bit 3 clears),
 *     R08 = 0x10, R0C = 0x3f.
 *  2. Each message byte goes to R04. When R0C reads 0 at that moment, the byte is followed by a start through
 *     bit 2 of R14 (waited for), R10 = 0x1b and R0C = 0x3f; otherwise R0C is decremented.
 *  3. R04 = 0x80, then the four bytes 0x50, 4, 0, 0 go to R04 with R0C = 0, 1, 2, 3 in turn; R08 = 0; a start
 *     through bit 2 of R14 (waited for); R00 = 0x33; a start through bit 4 of R10 (waited for).
 *  4. 32 reads of R04 fill hdcp_tx_result_block.
 * Every wait is a loop on the bit with no time-out.
 */
void hdcp_tx_hash_message_buffer(void)
{
    unsigned char tail[4];
    unsigned char i, j;

    R10 = 0x1b;
    R14 = 0x80;
    R18 &= ~1;
    R00 = 0x11;
    R14 = 8;
    while (R14 & 8)
        ;
    R08 = 0x10;
    R0C = 0x3f;
    for (i = 1; i <= MESSAGE_LAST_INDEX; i++) {
        if (R0C == 0) {
            R04 = hdcp_tx_message_buffer[i];
            R14 |= 4;
            while (R14 & 4)
                ;
            R10 = 0x1b;
            R0C = 0x3f;
        } else {
            R04 = hdcp_tx_message_buffer[i];
            R0C = R0C - 1;
        }
    }
    R04 = 0x80;
    tail[0] = 0x50;
    tail[1] = 4;
    tail[2] = 0;
    tail[3] = 0;
    R0C = 0;
    R04 = tail[0];
    R0C = 1;
    R04 = tail[1];
    R0C = 2;
    R04 = tail[2];
    R0C = 3;
    R04 = tail[3];
    R08 = 0;
    R14 |= 4;
    while (R14 & 4)
        ;
    R00 = 0x33;
    R10 |= 0x10;
    while (R10 & 0x10)
        ;
    for (j = 0; j <= RESULT_LAST_INDEX; j++)
        hdcp_tx_result_block[j] = R04;
}
