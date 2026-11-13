/* i2c_master_read  (FUN_CODE_3c4d)
 *
 * Read bytes from an I2C device through one hardware I2C channel.
 *   channel: I2C channel 0..5
 *   device_addr: device address byte
 *   count: byte count
 *   buf: destination
 * Returns: 1 when every byte arrived and the closing stop succeeded; 0 otherwise, also for a count of 0
 * Name basis: derived - channel blocks 0xF039.. ch 0..5; per-byte wait for the receive flag
 *   (i2c_master_receive_byte), stop at the end
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_3c4d @ 0x3c4d, built with OPTIMIZE(8,SPEED) LARGE REGFILE(R.ORC) (c51opts).
 * Source forms the exact build depends on:
 * - LARGE parameter / local block at XDATA 0xA4B7: channel 0xA4B7, device_addr (kept in R5, slot 0xA4B8 unused),
 *   count 0xA4B9..BA, buf (generic pointer, passed in its slot 0xA4BB..BD), i 0xA4BE..BF, the five register
 *   pointers (generic) 0xA4C0..CE in the order tx_data, event_ack, ctrl, mode, status; the bit local ok is
 *   BITS 0x20.1. The return value is a bit (carry).
 * - mode is set in every case but never used; the five '= 0' stores and the 'case 0' arm stay.
 * - Pointer accesses go through the Keil library ?C?CLDPTR (0x06A4) and ?C?CSTPTR (0x06EA). Keil shares the last
 *   i2c_master_receive_byte call of the count 1 and count 2 cases. No aids.
 */
#include <reg51.h>
#include <intrins.h>
extern unsigned char volatile xdata DAT_EXTMEM_f00a;
extern unsigned char xdata i2c_master_ctrl_bits;
bit i2c_master_receive_byte(unsigned char ch, unsigned char *p);
bit i2c_master_stop(unsigned char ch);

/* Register block of hardware I2C channel N (reg_i2c<N>_*): base 0xF039, 0xF041, 0xF089, 0xF091, 0xF09B, 0xF0B8 for
 * channels 0..5, then +0 ctrl, +1 status, +2 mode, +3 events, +4 event_ack, +5 tx_data, +6 rx_data. */
#define I2C_ACK_ALL_EVENTS   0xFF
#define I2C_ADDR_READ_BIT    0x01  /* ORed into the device address byte here; i2c_master_write sends the byte as given */
#define I2C_STATUS_BIT3      0x08
#define I2C_CTRL_BIT7        0x80  /* set before the last two bytes; the channel clears it */

/* i2c_master_read - read 'count' bytes from an I2C device on hardware channel 'channel' (0..5) into buf.
 *   device_addr: device address byte; it is sent with bit 0 set.
 * Returns 1 when the stop and every byte succeeded, 0 when count is 0 or any step failed or timed out.
 * Called by i2c_master_write_read, which first writes the register address with i2c_master_write; that is the
 * read of message type 2 from the main processor (docs/MAILBOX.md).
 *
 * Phases:
 *   1. Pick the register block of the channel (another channel number leaves the pointers 0).
 *   2. Write 0x55 to XDATA 0xF00A, disable the timer 0 interrupt (ET0) for the whole transfer and acknowledge all
 *      pending events of the channel.
 *   3. Start the transfer: the control register gets i2c_master_ctrl_bits plus a value that depends on the count
 *      (0x02 for one byte, 0xC2 for two, 0x42 for more), and the address byte goes to tx_data.
 *   4. Take the bytes with i2c_master_receive_byte. With three or more bytes, before the last-but-one byte the
 *      routine waits for status bit 3, sets control bit 7 and waits until the channel clears it again.
 *   5. i2c_master_stop ends the transfer; the timer 0 interrupt is enabled again.
 */
bit i2c_master_read(unsigned char channel, unsigned char device_addr, unsigned int count, unsigned char *buf)
{
    unsigned int i;
    unsigned char *tx_data, *event_ack, *ctrl, *mode, *status;
    bit ok;

    i = 0;
    ok = 1;
    tx_data = 0;
    event_ack = 0;
    ctrl = 0;
    mode = 0;
    status = 0;
    if (count < 1) return 0;
    /* 1. Register block of the channel. */
    switch (channel) {
    case 0:
        tx_data = (unsigned char xdata *)0xf03e;
        event_ack = (unsigned char xdata *)0xf03d;
        ctrl = (unsigned char xdata *)0xf039;
        mode = (unsigned char xdata *)0xf03b;
        status = (unsigned char xdata *)0xf03a;
        break;
    case 1:
        tx_data = (unsigned char xdata *)0xf046;
        event_ack = (unsigned char xdata *)0xf045;
        ctrl = (unsigned char xdata *)0xf041;
        mode = (unsigned char xdata *)0xf043;
        status = (unsigned char xdata *)0xf042;
        break;
    case 2:
        tx_data = (unsigned char xdata *)0xf08e;
        event_ack = (unsigned char xdata *)0xf08d;
        ctrl = (unsigned char xdata *)0xf089;
        mode = (unsigned char xdata *)0xf08b;
        status = (unsigned char xdata *)0xf08a;
        break;
    case 3:
        tx_data = (unsigned char xdata *)0xf096;
        event_ack = (unsigned char xdata *)0xf095;
        ctrl = (unsigned char xdata *)0xf091;
        mode = (unsigned char xdata *)0xf093;
        status = (unsigned char xdata *)0xf092;
        break;
    case 4:
        tx_data = (unsigned char xdata *)0xf0a0;
        event_ack = (unsigned char xdata *)0xf09f;
        ctrl = (unsigned char xdata *)0xf09b;
        mode = (unsigned char xdata *)0xf09d;
        status = (unsigned char xdata *)0xf09c;
        break;
    case 5:
        tx_data = (unsigned char xdata *)0xf0bd;
        event_ack = (unsigned char xdata *)0xf0bc;
        ctrl = (unsigned char xdata *)0xf0b8;
        mode = (unsigned char xdata *)0xf0ba;
        status = (unsigned char xdata *)0xf0b9;
        break;
    }
    /* 2. Prepare: no timer 0 interrupt during the transfer, clear old events. */
    DAT_EXTMEM_f00a = 0x55;
    ET0 = 0;
    *event_ack = I2C_ACK_ALL_EVENTS;
    /* 3 + 4. Start with the address byte, then receive. */
    switch (count) {
    case 0:
        break;
    case 1:
        *ctrl = i2c_master_ctrl_bits | 0x02;
        *tx_data = device_addr | I2C_ADDR_READ_BIT;
        ok &= i2c_master_receive_byte(channel, buf);
        break;
    case 2:
        *ctrl = i2c_master_ctrl_bits | 0xc2;
        *tx_data = device_addr | I2C_ADDR_READ_BIT;
        ok &= i2c_master_receive_byte(channel, buf);
        ok &= i2c_master_receive_byte(channel, buf + 1);
        break;
    default:
        *ctrl = i2c_master_ctrl_bits | 0x42;
        *tx_data = device_addr | I2C_ADDR_READ_BIT;
        for (i = 0; i < count; i++) {
            if (i == count - 2) {
                /* Before the last two bytes: wait for status bit 3, then hand control bit 7 to the channel. */
                while (!(*status & I2C_STATUS_BIT3)) {
                    _nop_();
                    _nop_();
                }
                *ctrl |= I2C_CTRL_BIT7;
                while (*ctrl & I2C_CTRL_BIT7) ;
            }
            ok &= i2c_master_receive_byte(channel, buf + i);
        }
        break;
    }
    /* 5. Stop and give the timer interrupt back. */
    ok &= i2c_master_stop(channel);
    ET0 = 1;
    return ok;
}
