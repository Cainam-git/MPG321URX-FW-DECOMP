/* hdmi_tx_get_ctrl_bit31  (FUN_a0091a10)
 *
 * Return bit 31 of word 0 of an HDMI TX channel record.
 *   port: HDMI TX port 0/1
 * Name basis: descriptive - copied from request bit 14; callers TX set-up and the FRL task
 *
 * Matching notes
 * --------------
 * leon2s FUN_a0091a10 @ 0xa0091a10-0xa0091a4c (15 words), flags -mcpu=v8 -Os -g.
 * Leaf. For port <= 1 the result is (word 0 >> 31) != 0 (srl 31; cmp %g0; addx), else 0. u8 result from an int
 * local.
 * Source form: the '!= 0' test of the top bit in an int local (a u8/_Bool local gives 'and 1' and another
 * schedule); a 0x1c-byte record struct.
 */
/* One HDMI TX channel record (0x1c bytes); only word 0 is used here. */
struct hdmi_tx_channel_record { unsigned int ctrl; unsigned int word[6]; };
extern struct hdmi_tx_channel_record hdmi_tx_output_records[];

#define CTRL_BIT31_SHIFT 31             /* ctrl_bit31 is bit 31 of word 0 */

/* Return ctrl_bit31 of the record of HDMI TX channel 'port'; 0 for ports above 1. */
unsigned char hdmi_tx_get_ctrl_bit31(unsigned char port)
{
    int result = 0;

    if (port <= 1)
        result = (hdmi_tx_output_records[port].ctrl >> CTRL_BIT31_SHIFT) != 0;
    return result;
}
