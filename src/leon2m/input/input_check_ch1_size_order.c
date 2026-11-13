/* input_check_ch1_size_order  (FUN_a00844f8)
 *
 * Return 1 when channel 1's port code is 0x0D and its first measured size is not above the second.
 * Returns: 0 or 1
 * Note: The sizes are the two results of input_measure_picture_size. Called by APP_ConfigDispSize.
 * Name basis: descriptive - input_api_get_channel_port_code(1) == 0x0D; compares the halfwords 0xA8024006 and
 *   0xA8024004
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00844f8 @ 0xa00844f8, flags -mcpu=v8 -O3 -g.
 * Source form: an unsigned char result returned as 'result & 1' (the firmware ends with 'and %i0, 1, %i0'). The
 * second size keeps its decompiler label pq_ch1_measured_height.
 */

extern unsigned short pq_ch1_measured_height;
extern unsigned short pq_ch1_measured_width;
extern int input_api_get_channel_port_code();

/*
 * Return 1 when the port code of channel 1 is 0x0D and the first picture size measured on channel 1
 * (pq_ch1_measured_width) is not larger than the second one (pq_ch1_measured_height). Both come from
 * input_measure_picture_size; the first one is checked there to be at least 300, the second at least 200.
 * Called by APP_ConfigDispSize.
 */
int input_check_ch1_size_order()
{
    unsigned int port_code;
    unsigned char result;

    port_code = input_api_get_channel_port_code(1);
    result = 0;
    if (((port_code & 0xff) == 0xd) && (pq_ch1_measured_width <= pq_ch1_measured_height)) {
        result = 1;
    }
    return result & 1;
}
