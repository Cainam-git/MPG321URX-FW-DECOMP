/* dp_tx_check_channel_eq  (FUN_a0087364)
 *
 * Return the training result code from the lane status bytes.
 * Returns: code 5/6/8/9
 * Name basis: derived - tests the bit masks 0x77, 0x11, 7 and 1 of status bytes 4 and 5, chosen by the lane
 *   count; dp_tx_train_links acts on the code
 *
 * Matching notes
 * --------------
 * FUN_a0087364 (leon2s 0xa0087364-0xa008743c, 216 bytes, leaf), flags -mcpu=v8 -Os -g.
 * Source form: one exit returning result & 0xf; byte 4 is read into an unsigned int inside each arm of the
 * lanes == 2 test (GCC hoists the load above that test only).
 */
/*
 * Rate the lane status bytes of a link status record and return a code for the training loop.
 *   lanes:  lane count (low 4 bits used): 4, 2, or anything else for one lane
 *   status: link status record; bytes 4 and 5 are the lane status bytes
 * Returns:
 *   4 lanes: 5 when both bytes have all of the bits 0x77 set. If neither byte has both bits 0x11 set: 9 when
 *            each byte has one of them set, else 8. Otherwise 6.
 *   2 lanes: only byte 4: 5 for 0x77 set; when the bits 0x11 are not both set, 9 if one of them is, else 8.
 *            Otherwise 6.
 *   1 lane:  byte 4 only: 5 when bits 0..2 are set; 8 when bit 0 is clear. Otherwise 6.
 * dp_tx_train_links acts on the code: 5 ends the training, 9 halves the lane count, 8 steps the link rate
 * down. Called by dp_tx_train_channel_eq and dp_tx_check_training_lost.
 */
unsigned char dp_tx_check_channel_eq(unsigned int lanes, unsigned char *status)
{
    unsigned char result = 6;
    unsigned char bits_a;
    unsigned char bits_b;
    unsigned int lane_byte;

    lanes &= 0xf;
    if (lanes == 4) {
        bits_a = status[4];
        if ((bits_a & 0x77) == 0x77 && (status[5] & 0x77) == 0x77)
            result = 5;
        bits_a &= 0x11;
        if (bits_a != 0x11) {
            bits_b = status[5] & 0x11;
            if (bits_b != 0x11) {
                result = 8;
                if (bits_a != 0)
                    if (bits_b != 0)
                        result = 9;
            }
        }
    } else {
        if (lanes == 2) {
            lane_byte = status[4];
            if ((lane_byte & 0x77) == 0x77)
                result = 5;
            bits_b = lane_byte & 0x11;
            if (bits_b != 0x11) {
                result = 8;
                if (bits_b != 0)
                    result = 9;
            }
        } else {
            lane_byte = status[4];
            if ((lane_byte & 7) == 7)
                result = 5;
            if (!(lane_byte & 1))
                result = 8;
        }
    }
    return result & 0xf;
}
