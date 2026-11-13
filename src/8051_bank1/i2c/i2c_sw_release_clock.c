/* i2c_sw_release_clock  (FUN_CODE_bd1b)
 *
 * Release the clock line of the software I2C bus and wait until it is high.
 * Name basis: proven - sets the clock pin (pointer 0xA701) and waits up to 65535 rounds for it to read high
 *   (clock stretching)
 *
 * Matching notes
 * --------------
 * One Keil module in this order: i2c_sw_bit_delay (0xD086, 15 B), i2c_sw_release_clock (0xBD1B, 102 B),
 *   i2c_sw_start (0x97C4, 217 B), i2c_sw_stop (0xC6EC, 82 B), i2c_sw_write_byte (0x6781, 406 B),
 *   i2c_sw_read_byte (0x8C5D, 259 B). Compiler flags: OPTIMIZE(8,SPEED) LARGE. The order decides which call sites
 *   Keil merges into the common-entry blocks.
 * In front of i2c_sw_bit_delay the firmware has the Keil OPTIMIZE(8) common-entry chain 0xD05B..0xD085, built from
 *   the call sites: 0xD05B 'LCALL 0xD086', 0xD05E 'clock line cleared', 0xD07E 'ORL A,R7; MOV R7,A', 0xD080
 *   'MOVX A,@DPTR; CPL A; ANL A,R7; LCALL ?C?CSTPTR', each falling into the next and into i2c_sw_bit_delay.
 *   There is no separate function at 0xD05E. In front of i2c_sw_release_clock: the block 0xBD18 'LCALL 0xD086'
 *   (entered from i2c_sw_write_byte).
 * Source forms:
 *  - The clock-line clear is one statement, I2C_SW_SCL_CLEAR() (written out in place, at every site); Keil factors
 *    the sites followed by i2c_sw_bit_delay() into the chain above.
 *  - The other line updates use a byte local per site ('v = *ctrl; v = *port | v; *port = v | mask;'): one local per
 *    site keeps each in R7 (a local reused across the calls is placed in XDATA). i2c_sw_start's second data-line
 *    clear is one statement ('v = *ctrl; *port = (*port | v) & ~mask;').
 *  - i2c_sw_write_byte: 'if (!(...)) no_ack = 0; else { ... }' gives the firmware's 'JNZ +2; SJMP' (the no_ack = 0
 *    store is shared with the inner one); i and no_ack are IDATA (0x62, 0x63).
 *  - i2c_sw_read_byte: 'if (!(...)) byte_in &= 0xFE; else byte_in |= 1;'. byte_in is not initialised, as in the
 *    firmware (no store before the loop); all eight starting bits are shifted out, so the result does not depend on
 *    it. LARGE locals last 0xA76A, i 0xA76B, byte_in 0xA76C.
 *  - i2c_sw_release_clock: the round counter is the 16-bit IDATA variable 0x60..0x61 (i2c_sw_clock_wait_count).
 */

/* The software (pin-driven) I2C bus. Each line has a port register (i2c_sw_sda_port_ptr / i2c_sw_scl_port_ptr), a
 * second register that is ORed into the port value on every update (i2c_sw_sda_ctrl_ptr / i2c_sw_scl_ctrl_ptr) and
 * a bit mask (i2c_sw_sda_mask / i2c_sw_scl_mask). Setting the line's bit releases the line, clearing it drives the
 * line to 0; reading the port register gives the level on the line. The pins are chosen by i2c_sw_select_pins. */
#define I2C_SW_BITS_PER_BYTE    8
#define I2C_SW_CLEAR_PULSES_MAX 9      /* i2c_sw_start: clock pulses while the data line stays at 0 */
#define I2C_SW_ACK_WAIT_DELAYS  7      /* i2c_sw_write_byte: delays to wait for the acknowledge */
#define I2C_SW_DELAY_LOOPS      100    /* i2c_sw_bit_delay: empty loop rounds */
#define I2C_SW_CLOCK_WAIT_LOOPS 10     /* i2c_sw_release_clock: empty loop rounds between two clock reads */
#define I2C_SW_ACK              0      /* i2c_sw_read_byte(last = 0): data line at 0 after the byte */
#define I2C_SW_NACK             1      /* i2c_sw_read_byte(last = 1): data line released after the byte */

/* Drive the clock line to 0. */
#define I2C_SW_SCL_CLEAR() \
    (*i2c_sw_scl_port_ptr = (*i2c_sw_scl_port_ptr | *i2c_sw_scl_ctrl_ptr) & ~i2c_sw_scl_mask)

extern unsigned char * xdata i2c_sw_sda_port_ptr;
extern unsigned char * xdata i2c_sw_scl_port_ptr;
extern unsigned char xdata i2c_sw_sda_mask;
extern unsigned char xdata i2c_sw_scl_mask;
extern unsigned char * xdata i2c_sw_sda_ctrl_ptr;
extern unsigned char * xdata i2c_sw_scl_ctrl_ptr;
extern unsigned char xdata i2c_sw_bus_clear_count;
extern unsigned int idata i2c_sw_clock_wait_count;
extern unsigned char code i2c_sw_bit_masks[];
extern unsigned char volatile xdata DAT_EXTMEM_f00a;
extern unsigned char xdata i2c_sw_id_match_flag;

/* The fixed wait between two line changes: an empty loop of 100 rounds. */
void i2c_sw_bit_delay(void)
{
    unsigned int i;
    for (i = 0; i != I2C_SW_DELAY_LOOPS; i++) ;
}

/* Release the clock line, then wait until it reads 1: up to 65535 rounds (the counter starts at 0 and counts down
 * through 0xFFFF), with a 10-round empty loop between two reads. Returns after the last round also when the line
 * still reads 0. */
void i2c_sw_release_clock(void)
{
    unsigned char scl_value;
    unsigned int j;

    scl_value = *i2c_sw_scl_ctrl_ptr; scl_value = *i2c_sw_scl_port_ptr | scl_value; *i2c_sw_scl_port_ptr = scl_value | i2c_sw_scl_mask;
    i2c_sw_clock_wait_count = 0;
    while (!(*i2c_sw_scl_port_ptr & i2c_sw_scl_mask)) {
        if (--i2c_sw_clock_wait_count == 0) break;
        for (j = 0; j < I2C_SW_CLOCK_WAIT_LOOPS; j++) ;
    }
}

/* Send a start condition, freeing the bus first when the data line is held at 0.
 *   1. Release the data line and the clock line; set the data bit in the data line's second register.
 *   2. While the data line still reads 0, give up to 9 clock pulses (clock to 0, delay, release the clock);
 *      i2c_sw_bus_clear_count counts them.
 *   3. Clear the data bit in the second register again, drive the data line to 0 while the clock is released,
 *      delay, then drive the clock line to 0.
 */
void i2c_sw_start(void)
{
    unsigned char sda_value1, sda_value2;

    /* 1. Both lines released. */
    sda_value1 = *i2c_sw_sda_ctrl_ptr; sda_value1 = *i2c_sw_sda_port_ptr | sda_value1; *i2c_sw_sda_port_ptr = sda_value1 | i2c_sw_sda_mask;
    i2c_sw_release_clock();
    *i2c_sw_sda_ctrl_ptr |= i2c_sw_sda_mask;
    i2c_sw_bit_delay();

    /* 2. Clock pulses while the data line is held at 0. */
    i2c_sw_bus_clear_count = 0;
    while (!(*i2c_sw_sda_port_ptr & i2c_sw_sda_mask) && i2c_sw_bus_clear_count < I2C_SW_CLEAR_PULSES_MAX) {
        I2C_SW_SCL_CLEAR();
        i2c_sw_bit_delay();
        i2c_sw_release_clock();
        i2c_sw_bus_clear_count++;
    }

    /* 3. Data line to 0 with the clock released, then the clock to 0. */
    *i2c_sw_sda_ctrl_ptr &= ~i2c_sw_sda_mask;
    sda_value2 = *i2c_sw_sda_ctrl_ptr; *i2c_sw_sda_port_ptr = (*i2c_sw_sda_port_ptr | sda_value2) & ~i2c_sw_sda_mask;
    i2c_sw_bit_delay();
    I2C_SW_SCL_CLEAR();
}

/* Send a stop condition: data line to 0, delay, release the clock line, delay, release the data line. */
void i2c_sw_stop(void)
{
    unsigned char sda_value1, sda_value2;
    sda_value1 = *i2c_sw_sda_ctrl_ptr; sda_value1 = *i2c_sw_sda_port_ptr | sda_value1; *i2c_sw_sda_port_ptr = sda_value1 & ~i2c_sw_sda_mask;
    i2c_sw_bit_delay();
    i2c_sw_release_clock();
    i2c_sw_bit_delay();
    sda_value2 = *i2c_sw_sda_ctrl_ptr; sda_value2 = *i2c_sw_sda_port_ptr | sda_value2; *i2c_sw_sda_port_ptr = sda_value2 | i2c_sw_sda_mask;
}

/* Send one byte and read the acknowledge.
 *   1. Eight data bits, first bit 7 (masks from i2c_sw_bit_masks): clock to 0, set the data line to the bit,
 *      release the clock.
 *   2. Clock to 0, data line to 0, then the data bit set in the second register and the data line released;
 *      release the clock and read the data line.
 *   3. When the data line reads 0 the byte was acknowledged. Otherwise wait up to 7 delays for it to go to 0;
 *      when the 7 delays run out the result is "no acknowledge".
 *   4. Clock to 0, data bit cleared in the second register, data line to 0.
 * Returns 0 when the byte was acknowledged, 1 when not. i2c_sw_read_regs sends the device address again (up to
 * 10 times) while the result is 1.
 */
unsigned char i2c_sw_write_byte(unsigned char byte_out)
{
    unsigned char sda_value1, sda_value2, sda_value3, sda_value4, sda_value5;
    unsigned char idata i;
    unsigned char idata no_ack;

    /* 1. The eight data bits. */
    for (i = 0; i < I2C_SW_BITS_PER_BYTE; i++) {
        i2c_sw_bit_delay();
        I2C_SW_SCL_CLEAR();
        i2c_sw_bit_delay();
        if (byte_out & i2c_sw_bit_masks[i]) {
            sda_value1 = *i2c_sw_sda_ctrl_ptr; sda_value1 = *i2c_sw_sda_port_ptr | sda_value1; *i2c_sw_sda_port_ptr = sda_value1 | i2c_sw_sda_mask;
        } else {
            sda_value2 = *i2c_sw_sda_ctrl_ptr; sda_value2 = *i2c_sw_sda_port_ptr | sda_value2; *i2c_sw_sda_port_ptr = sda_value2 & ~i2c_sw_sda_mask;
        }
        i2c_sw_bit_delay();
        i2c_sw_release_clock();
    }

    /* 2. Hand the data line over and clock the acknowledge bit. */
    i2c_sw_bit_delay();
    I2C_SW_SCL_CLEAR();
    i2c_sw_bit_delay();
    sda_value3 = *i2c_sw_sda_ctrl_ptr; sda_value3 = *i2c_sw_sda_port_ptr | sda_value3; *i2c_sw_sda_port_ptr = sda_value3 & ~i2c_sw_sda_mask;
    *i2c_sw_sda_ctrl_ptr |= i2c_sw_sda_mask;
    sda_value4 = *i2c_sw_sda_ctrl_ptr; sda_value4 = *i2c_sw_sda_port_ptr | sda_value4; *i2c_sw_sda_port_ptr = sda_value4 | i2c_sw_sda_mask;
    i2c_sw_bit_delay();
    i2c_sw_release_clock();
    i2c_sw_bit_delay();

    /* 3. Acknowledge: data line at 0, at once or within 7 delays. */
    if (!(*i2c_sw_sda_port_ptr & i2c_sw_sda_mask)) no_ack = 0;
    else {
        i = I2C_SW_ACK_WAIT_DELAYS;
        while ((*i2c_sw_sda_port_ptr & i2c_sw_sda_mask) && i) {
            i2c_sw_bit_delay();
            i--;
        }
        if (i == 0) no_ack = 1;
        else no_ack = 0;
    }

    /* 4. Clock to 0, data line back to 0. */
    I2C_SW_SCL_CLEAR();
    *i2c_sw_sda_ctrl_ptr &= ~i2c_sw_sda_mask;
    sda_value5 = *i2c_sw_sda_ctrl_ptr; sda_value5 = *i2c_sw_sda_port_ptr | sda_value5; *i2c_sw_sda_port_ptr = sda_value5 & ~i2c_sw_sda_mask;
    i2c_sw_bit_delay();
    return no_ack;
}

/* Read one byte, then answer with I2C_SW_ACK (last = 0) or I2C_SW_NACK (last = 1); i2c_sw_read_regs passes 1 for
 * the last byte it reads.
 *   1. Set the data bit in the second register and release the data line.
 *   2. Eight bits, first bit 7: release the clock, delay, shift the data line level into bit 0, clock to 0, delay.
 *   3. Clear the data bit in the second register; data line to 0 (last = 0) or released (last = 1); one clock
 *      pulse.
 * Returns the byte read.
 */
unsigned char i2c_sw_read_byte(unsigned char last)
{
    unsigned char i;
    unsigned char byte_in;
    unsigned char sda_value1, sda_value2, sda_value3;
    last &= 1;

    /* 1. Data line released for reading. */
    *i2c_sw_sda_ctrl_ptr |= i2c_sw_sda_mask;
    sda_value1 = *i2c_sw_sda_ctrl_ptr; sda_value1 = *i2c_sw_sda_port_ptr | sda_value1; *i2c_sw_sda_port_ptr = sda_value1 | i2c_sw_sda_mask;

    /* 2. The eight data bits. */
    for (i = 0; i < I2C_SW_BITS_PER_BYTE; i++) {
        byte_in <<= 1;
        i2c_sw_release_clock();
        i2c_sw_bit_delay();
        if (!(*i2c_sw_sda_port_ptr & i2c_sw_sda_mask)) byte_in &= 0xfe;
        else byte_in |= 1;
        I2C_SW_SCL_CLEAR();
        i2c_sw_bit_delay();
    }

    /* 3. The answer bit. */
    *i2c_sw_sda_ctrl_ptr &= ~i2c_sw_sda_mask;
    if (last == I2C_SW_ACK) {
        sda_value2 = *i2c_sw_sda_ctrl_ptr; sda_value2 = *i2c_sw_sda_port_ptr | sda_value2; *i2c_sw_sda_port_ptr = sda_value2 & ~i2c_sw_sda_mask;
    } else {
        sda_value3 = *i2c_sw_sda_ctrl_ptr; sda_value3 = *i2c_sw_sda_port_ptr | sda_value3; *i2c_sw_sda_port_ptr = sda_value3 | i2c_sw_sda_mask;
    }
    i2c_sw_bit_delay();
    i2c_sw_release_clock();
    i2c_sw_bit_delay();
    I2C_SW_SCL_CLEAR();
    i2c_sw_bit_delay();
    return byte_in;
}

