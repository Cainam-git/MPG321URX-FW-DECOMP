/* dp_update_range_flag  (FUN_a00af690)
 *
 * Update a port's range flag from a measurement, at most once per 40 ticks.
 * Name basis: descriptive - byte at 0xA8079338
 *
 * Matching notes
 * --------------
 * FUN_a00af690 (leon2s 0xa00af690-0xa00af764, 212 bytes), flags -mcpu=v8 -Os -g.
 * Source forms: port is a raw unsigned int parameter (masked at each use); the reset arm is written first with a
 * negated || condition; the range test is an unsigned short compare of (value - 301) with 0x65c.
 */
extern unsigned char dp_range_flags[];                  /* per port: range flag */
extern unsigned int dp_range_check_ticks[];             /* per port: tick count of the last measurement */
extern unsigned int dp_reg_read8(unsigned char, unsigned short);
extern unsigned int timer_get_ticks(void);
extern unsigned short dp_calc_rate_value(unsigned char);

#define LINK_STATE_READY     5          /* port_record state */
#define MEASURE_INTERVAL     0x28       /* ticks between two measurements */
#define RATE_VALUE_MIN       301        /* the flag is set for rate values from 301 ... */
#define RATE_VALUE_SPAN      0x65c      /* ... up to 301 + 0x65c = 1929 */

/*
 * Keep the range flag of a port. Unless the port record is in state LINK_STATE_READY and bit 0 of register
 * 0x229 is set, the flag is cleared and the time stamp is set to now. Otherwise, when more than 40 ticks have
 * passed since the time stamp, take a new time stamp and set the flag to 1 if dp_calc_rate_value is from 301 to
 * 1929, else to 0. Returns the flag.
 *   state: first byte (state) of the port_record of the port
 *   port: DP receiver (0 or 1)
 * Called by dp_update_port_status_flags, which sets bit 6 of the record's flags_0x12 from the result.
 */
unsigned char dp_update_range_flag(unsigned char *state, unsigned int port)
{
    if (*state != LINK_STATE_READY || !(dp_reg_read8(port, 0x229) & 1)) {
        dp_range_flags[(unsigned char)port] = 0;
        dp_range_check_ticks[(unsigned char)port] = timer_get_ticks();
    } else if (timer_get_ticks() - dp_range_check_ticks[(unsigned char)port] > MEASURE_INTERVAL) {
        dp_range_check_ticks[(unsigned char)port] = timer_get_ticks();
        if ((unsigned short)(dp_calc_rate_value(port) - RATE_VALUE_MIN) <= RATE_VALUE_SPAN)
            dp_range_flags[(unsigned char)port] = 1;
        else
            dp_range_flags[(unsigned char)port] = 0;
    }
    return dp_range_flags[(unsigned char)port];
}
