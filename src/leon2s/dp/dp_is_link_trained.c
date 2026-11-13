/* dp_is_link_trained  (FUN_a00ad27c)
 *
 * Return whether at least one lane of a port's link has both of its status bits set.
 * Returns: 1 when trained, else 0
 * Note: Returns 0 without reading the lane status when dp_get_link_flag is 1.
 * Name basis: proven - lane status bit pairs 0x11 / 0x22 / 0x44 / 0x88; the callers print 'Lost Training' when
 *   it does not return 1
 *
 * Matching notes
 * --------------
 * FUN_a00ad27c (leon2s), flags -mcpu=v8 -Os -g.
 * Source form: the count is a byte incremented by four separate ifs (the compiler turns the last three into
 * subx/add sequences and keeps a branch for the first one).
 */
extern int dp_get_link_flag(unsigned char);
extern unsigned char dp_read_lane_status(unsigned char);

/*
 * Return 0 when dp_get_link_flag(port) is 1. Otherwise read the lane status byte (dp_read_lane_status) and
 * return 1 when at least one of the bit pairs 0x11, 0x22, 0x44, 0x88 has both bits set, else 0.
 *   port: DP port
 */
unsigned char dp_is_link_trained(unsigned char port)
{
    unsigned char result = 0;
    unsigned char status, pairs_set;

    if ((unsigned char)dp_get_link_flag(port) == 1)
        return 0;
    status = dp_read_lane_status(port);
    pairs_set = 0;
    if ((status & 0x11) == 0x11)
        pairs_set++;
    if ((status & 0x22) == 0x22)
        pairs_set++;
    if ((status & 0x44) == 0x44)
        pairs_set++;
    if ((status & 0x88) == 0x88)
        pairs_set++;
    if (pairs_set)
        result = 1;
    return result;
}
