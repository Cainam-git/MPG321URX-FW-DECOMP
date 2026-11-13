/* dp_is_high_rate_mode  (FUN_a00aea64)
 *
 * Test chip revision above 0x83, high nibble of register 0x481 equal 4 and active width 3440.
 * Returns: 0 or 1
 * Name basis: descriptive - revision above 0x83, field == 4
 *
 * Matching notes
 * --------------
 * FUN_a00aea64 (leon2s 0xa00aea64-0xa00aeadc, 120 bytes), flags -mcpu=v8 -Os -g.
 * Source form: the revision test is a separate outer if.
 */
extern unsigned short dp_get_hactive(unsigned char);
extern unsigned int dp_reg_read8(unsigned char, unsigned short);
extern unsigned char sys_get_chip_revision(void);

#define CHIP_REVISION_LIMIT 0x83        /* the test needs a revision above this */
#define HACTIVE_3440        0xd70       /* 3440 pixels */

/*
 * Return 1 when the chip revision is above 0x83, the high nibble of register 0x481 of the port is 4 and the
 * horizontal active width of the port is 3440; otherwise 0.
 *   port: DP receiver (0 or 1)
 */
unsigned char dp_is_high_rate_mode(unsigned char port)
{
    unsigned short hactive = dp_get_hactive(port);
    unsigned char field = (unsigned char)dp_reg_read8(port, 0x481) >> 4;
    unsigned char revision = sys_get_chip_revision();

    if (revision > CHIP_REVISION_LIMIT) {
        if (field == 4 && hactive == HACTIVE_3440)
            return 1;
    }
    return 0;
}
