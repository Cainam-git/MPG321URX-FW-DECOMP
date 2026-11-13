/* dp_tx_hpd_is_low  (FUN_a0083648)
 *
 * Return whether the hot-plug line of a link output is low.
 *   output
 * Returns: 1 when low, 2 for a bad index
 * Name basis: descriptive - bit of the HPD status byte by index (1..4 remapped); callers eDP/DPTX HPD action
 *   checks
 *
 * Matching notes
 * --------------
 * leon2s FUN_a0083648 (0xa0083648-0xa00836f4, 172 bytes, leaf), flags -mcpu=v8 -Os -g.
 * Source forms: the default case jumps past the result assignment, so the value 2 and the 0/1 result share
 * one register and one return; the selected bit goes through an unsigned int temporary.
 */
extern unsigned char dp_tx_output_map;
extern unsigned char dp_tx_hpd_status;

/*
 * Test one bit of dp_tx_hpd_status for a link output and return 1 when the bit is clear, 0 when it is set.
 * An output number that selects no bit returns 2.
 *   output: 1..4 is first replaced by (2-bit field output-1 of dp_tx_output_map) + 1; 0 is used as it is.
 * Output 0..6 test the status bits 0x04, 0x08, 0x10, 0x20, 0x40, 0x01, 0x02 in that order.
 */
int dp_tx_hpd_is_low(int output)
{
    int result = 2;
    unsigned int bit;

    if ((unsigned int)(output - 1) <= 3)
        output = ((dp_tx_output_map >> (output * 2 - 2)) & 3) + 1;
    switch (output) {
    case 0:
        bit = dp_tx_hpd_status & 4;
        break;
    case 1:
        bit = dp_tx_hpd_status & 8;
        break;
    case 2:
        bit = dp_tx_hpd_status & 0x10;
        break;
    case 3:
        bit = dp_tx_hpd_status & 0x20;
        break;
    case 4:
        bit = dp_tx_hpd_status & 0x40;
        break;
    case 5:
        bit = dp_tx_hpd_status & 1;
        break;
    case 6:
        bit = dp_tx_hpd_status & 2;
        break;
    default:
        goto out;
    }
    result = bit == 0;
out:
    return result;
}
