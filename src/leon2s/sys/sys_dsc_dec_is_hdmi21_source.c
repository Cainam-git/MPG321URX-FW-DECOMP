/* sys_dsc_dec_is_hdmi21_source  (FUN_a00a6190)
 *
 * Return whether byte +0x2D of the record of the decoder's HDMI 2.1 input equals 1.
 *   input_code: input code 0x51/0x61/0x71/0x81
 * Returns: 0 or 1
 * Name basis: descriptive - input code 0x51 / 0x61 -> the byte at +0x2D of the HDMI 2.1 input record 0 / 1
 *   (0xA807D80D / 0xA807D99D) compared with 1
 *
 * Matching notes
 * --------------
 * FUN_a00a6190 (leon2s 0xa00a6190-0xa00a61d4, 68 bytes, leaf), flags -mcpu=v8 -Os -g.
 * The two flags are the bytes at 0xa807d80d and 0xa807d99d, 0x190 bytes apart (both loads crossjump into one
 * compare).
 * Source form: a nested 'if (flag == 1) r = 1' in each input arm.
 */
extern unsigned char hdmi_rx21_input_record0_dsc;
extern unsigned char hdmi_rx21_input_record1_dsc;

/* Return 1 when the HDMI 2.1 input named by the input code has its DSC flag equal to 1: flag of record 0 for
 * code 0x51 ('Q'), of record 1 for code 0x61 ('a'). Any other code gives 0.
 *   input_code: 0x51 or 0x61 for the HDMI 2.1 inputs
 */
unsigned char sys_dsc_dec_is_hdmi21_source(unsigned char input_code)
{
    unsigned char result = 0;

    if (input_code == 'Q') {
        if (hdmi_rx21_input_record0_dsc == 1)
            result = 1;
    } else if (input_code == 'a') {
        if (hdmi_rx21_input_record1_dsc == 1)
            result = 1;
    }
    return result & 1;
}
