/* input_block_compare_two_measurements  (FUN_a00f8f78)
 *
 * Take two measurements on the capture block of a port and return whether they agree.
 * Returns: 1 when the two 16-bit values are equal, else 0
 * Note: Port 0 uses block 6, port 1 block 7, any other port block 0. Nothing calls it.
 * Name basis: descriptive - two command / read-back cycles (commands 0x11 and 0x41) on registers 0x41:0x40,
 *   results compared
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00f8f78 @ 0xa00f8f78-0xa00f90fc (97 words), flags -mcpu=v8 -O3 -g.
 * Source form: the reading is a static helper inlined twice. measure_block_of_port takes the port as an int and
 * returns 0xFF for a negative port, else 6, 7 or 0. The caller passes an unsigned char, so GCC removes the
 * negative case after inlining; the 0xFF value is why the block number is still masked with 'and 0xff' after
 * the selection, as in the firmware (with only 6, 7 and 0 possible GCC narrows the mask to 'and 7').
 */
extern void input_block_wait_measure_cycle(unsigned char);
extern void timer_sleep_ticks(int ms);
extern unsigned short timer_get_ticks16(void);
extern void input_capture_write8(unsigned char blk, unsigned char reg, unsigned char val);
extern int input_capture_read8(unsigned char blk, unsigned char reg);

#define CAPTURE_REG_COMMAND     0x36        /* bit 0 stays set while the command runs */
#define CAPTURE_REG_VALUE_LOW   0x40
#define CAPTURE_REG_VALUE_HIGH  0x41
#define CAPTURE_REG_8C          0x8c
#define COMMAND_FIRST           0x11
#define COMMAND_SECOND          0x41
#define COMMAND_TIMEOUT_TICKS   100         /* the wait for the command to finish ends after this many ticks */
#define HELPER_BLOCK            3           /* the block that gets register 0x8c = 0x80 around the readings */

/* Send one command to the capture block, wait until bit 0 of the command register clears (at most 100 ticks) and
 * return the 16-bit value in registers 0x41 (high) and 0x40 (low). */
static unsigned short read_measured_value(unsigned char blk, unsigned char cmd)
{
    unsigned short start_ticks;

    input_capture_write8(blk, CAPTURE_REG_COMMAND, cmd);
    start_ticks = timer_get_ticks16();
    while (input_capture_read8(blk, CAPTURE_REG_COMMAND) & 1) {
        if ((unsigned short)(timer_get_ticks16() - start_ticks) > COMMAND_TIMEOUT_TICKS - 1)
            break;
    }
    return (input_capture_read8(blk, CAPTURE_REG_VALUE_HIGH) & 0xff) << 8 | (input_capture_read8(blk, CAPTURE_REG_VALUE_LOW) & 0xff);
}

/* The capture block that belongs to a port: 6 for port 0, 7 for port 1, 0 for any other port, 0xFF for a negative one. */
static unsigned char measure_block_of_port(int port)
{
    unsigned char blk = 0xff;

    if (port >= 0) {
        blk = 0;
        if (port == 0)
            blk = 6;
        else if (port == 1)
            blk = 7;
    }
    return blk;
}

/*
 * Take two measurements on the capture block of a port and tell whether they agree.
 *
 *   port  0 uses block 6, 1 uses block 7, anything else block 0
 *
 * Returns 1 when the two 16-bit values are equal, else 0. Nothing calls this routine.
 *
 * Order: wait for one measure cycle of block 3 (input_block_wait_measure_cycle), wait 5 ticks and set register
 * 0x8c of block 3 to 0x80; read the value with command 0x11, then with command 0x41; wait for another measure
 * cycle of block 3, wait 5 ticks and clear register 0x8c of block 3 again. What the commands measure is not
 * shown by the code.
 */
unsigned char input_block_compare_two_measurements(unsigned char port)
{
    unsigned char blk;
    unsigned short first_value, second_value;

    input_block_wait_measure_cycle(HELPER_BLOCK);
    timer_sleep_ticks(5);
    input_capture_write8(HELPER_BLOCK, CAPTURE_REG_8C, 0x80);
    blk = measure_block_of_port(port);
    first_value = read_measured_value(blk, COMMAND_FIRST);
    second_value = read_measured_value(blk, COMMAND_SECOND);
    input_block_wait_measure_cycle(HELPER_BLOCK);
    timer_sleep_ticks(5);
    input_capture_write8(HELPER_BLOCK, CAPTURE_REG_8C, 0);
    return (unsigned short)(first_value ^ second_value) == 0;
}
