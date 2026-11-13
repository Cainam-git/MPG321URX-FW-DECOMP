/* dp_calc_pixel_clock  (FUN_a00acc54)
 *
 * Compute a port's pixel clock value from two 24-bit measurements and the link mode.
 * Returns: 16-bit value
 * Name basis: derived - mode factor and three scale steps
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00acc54 @ 0xa00acc54-0xa00aceec (664 bytes), flags -mcpu=v8 -Os -g.
 * Source form: the bytes are accumulated with '<<= 8; |= byte' statements; one complete formula 'second =
 * first * k / second' per case, as in dp_calc_rate_value; case 0 and the default both use 0xa2: the compare tree
 * at 0xa00ace48 has root 1 (a case 0 node, 'ble' to the 0xa2 block at 0xa00ace74) and the case 3 test at
 * 0xa00ace68 falls into the same default block; the explicit case equal to the default is also written in
 * dp_get_color_depth.
 */
extern unsigned int dp_pixel_clocks[];
extern unsigned char dp_reg_read8(unsigned int, unsigned short);

/*
 * Compute the pixel clock value of a DP receiver port from two 24-bit counts in its registers.
 *
 * first (registers 0x82..0x84) times a factor, divided by second (registers 0x85..0x87); the factor is 0xA2,
 * 0x10E, 0x21C or 0x32A for bits 0..1 of register 0x80 = 0, 1, 2 or 3. The quotient is then multiplied by 8
 * when bit 4 of register 0xD7 is set, else by 4 when bit 2 of 0xD7 is set, else by 2 when bit 5 of register
 * 0xD5 is set. A second of 0 is taken as 1.
 *
 * dp_pixel_clocks[port] keeps the last value of first. It is replaced by the new first, except when bit 5 of
 * register 3 is clear and the new first differs from the kept one by 0xF9..0x103 with its bits 2..7 all set
 * (new above kept) or all clear (new below kept), or by 0xF801..0x13FF with its bits 10..15 all set or all
 * clear in the same way; then the kept value is used instead.
 * Called by the link state machine (DP_GetClrSpace), by the mailbox command 0x03 (reply of the clock value of
 * an input) and by dp_reprogram_clock_registers.
 *   port: DP receiver
 *   returns: the value as 16 bits
 */
unsigned short dp_calc_pixel_clock(unsigned char port)
{
    unsigned int first;
    unsigned int second;                        /* after the division it holds the quotient */

    first = dp_reg_read8(port, 0x82);
    first <<= 8;
    first |= dp_reg_read8(port, 0x83);
    first <<= 8;
    first |= dp_reg_read8(port, 0x84);
    second = dp_reg_read8(port, 0x85);
    second <<= 8;
    second |= dp_reg_read8(port, 0x86);
    second <<= 8;
    second |= dp_reg_read8(port, 0x87);
    if (dp_reg_read8(port, 3) & 0x20)
        dp_pixel_clocks[port] = first;
    else if ((first > dp_pixel_clocks[port] && (first & 0xfc) == 0xfc && first - dp_pixel_clocks[port] - 0xf9 < 0xb)
             || (first < dp_pixel_clocks[port] && (first & 0xfc) == 0 && dp_pixel_clocks[port] - first - 0xf9 < 0xb)
             || (first > dp_pixel_clocks[port] && (first & 0xfc00) == 0xfc00 && first - dp_pixel_clocks[port] - 0xf801 < 0xbff)
             || (first < dp_pixel_clocks[port] && (first & 0xfc00) == 0 && dp_pixel_clocks[port] - first - 0xf801 < 0xbff))
        first = dp_pixel_clocks[port];
    else
        dp_pixel_clocks[port] = first;
    if (second == 0)
        second = 1;
    switch (dp_reg_read8(port, 0x80) & 3) {
    case 0:
        second = first * 0xa2 / second;
        break;
    case 1:
        second = first * 0x10e / second;
        break;
    case 2:
        second = first * 0x21c / second;
        break;
    case 3:
        second = first * 0x32a / second;
        break;
    default:
        second = first * 0xa2 / second;
        break;
    }
    if (dp_reg_read8(port, 0xd7) & 0x10)
        second <<= 3;
    else if (dp_reg_read8(port, 0xd7) & 4)
        second <<= 2;
    else if (dp_reg_read8(port, 0xd5) & 0x20)
        second *= 2;
    return second;
}
