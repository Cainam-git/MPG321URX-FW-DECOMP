/* i2c_master_stop  (FUN_CODE_6db5)
 *
 * End a hardware I2C read with a stop and wait for the bus to finish.
 *   ch: I2C channel
 * Returns: 1 on success
 * Name basis: derived - sets bit 5 of the channel's register, waits up to 12000 passes for bit 0 of the next
 *   one
 *
 * Matching notes
 * --------------
 * Compiler flags: OPTIMIZE(8,SPEED) LARGE.
 * LARGE block: tries_left 0xA4CF..0xA4D0, then the three generic pointers ctrl, event_ack, status 0xA4D1..0xA4D9;
 *   the accesses go through ?C?CLDPTR / ?C?CSTPTR. event_ack is set and never used; it stays because it takes its
 *   place in the block and its stores are in the firmware.
 * Same shape as the wait in i2c_master_send_last_byte (src/8051_bank1/i2c/i2c_master_write.c).
 */

/* Register block of hardware I2C channel N: base 0xF039, 0xF041, 0xF089, 0xF091, 0xF09B, 0xF0B8 for channels
 * 0..5, then +0 ctrl, +1 status, +4 event_ack (as in i2c_master_write). */
#define I2C_CTRL_STOP        0x20  /* ctrl bit 5, also set by i2c_master_send_last_byte */
#define I2C_STATUS_BIT0      0x01  /* waited for after the stop */
#define STOP_TRIES           12000

/* Set the stop bit of hardware I2C channel 'ch' (0..5) and wait for bit 0 of its status register.
 * Called by i2c_master_read at the end of every read.
 * Returns 1 as soon as status bit 0 is set, 0 when it is still clear after 12000 passes.
 * A channel number above 5 leaves the register pointers 0 (the firmware then works on generic address 0).
 */
bit i2c_master_stop(unsigned char ch)
{
    unsigned int tries_left;
    unsigned char volatile *ctrl, *event_ack, *status;

    tries_left = STOP_TRIES;
    ctrl = 0;
    event_ack = 0;
    status = 0;
    switch (ch) {
    case 0:
        ctrl = (unsigned char xdata *)0xf039;
        event_ack = (unsigned char xdata *)0xf03d;
        status = (unsigned char xdata *)0xf03a;
        break;
    case 1:
        ctrl = (unsigned char xdata *)0xf041;
        event_ack = (unsigned char xdata *)0xf045;
        status = (unsigned char xdata *)0xf042;
        break;
    case 2:
        ctrl = (unsigned char xdata *)0xf089;
        event_ack = (unsigned char xdata *)0xf08d;
        status = (unsigned char xdata *)0xf08a;
        break;
    case 3:
        ctrl = (unsigned char xdata *)0xf091;
        event_ack = (unsigned char xdata *)0xf095;
        status = (unsigned char xdata *)0xf092;
        break;
    case 4:
        ctrl = (unsigned char xdata *)0xf09b;
        event_ack = (unsigned char xdata *)0xf09f;
        status = (unsigned char xdata *)0xf09c;
        break;
    case 5:
        ctrl = (unsigned char xdata *)0xf0b8;
        event_ack = (unsigned char xdata *)0xf0bc;
        status = (unsigned char xdata *)0xf0b9;
        break;
    }
    *ctrl |= I2C_CTRL_STOP;
    while (tries_left) {
        tries_left--;
        if (*status & I2C_STATUS_BIT0) return 1;
    }
    return 0;
}
