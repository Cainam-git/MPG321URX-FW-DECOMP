/* i2c_master_write  (FUN_CODE_482e)
 *
 * Write bytes to an I2C device through one hardware I2C channel.
 *   channel: I2C channel 0..5
 *   device_addr: device address byte
 *   count: byte count
 *   buf: source
 * Returns: 1 when all bytes were taken
 * Name basis: derived - channel blocks 0xF039.. ch 0..5; sends address then bytes with i2c_master_send_byte,
 *   last with stop
 *
 * Matching notes
 * --------------
 * 8051_bank1 module FUN_CODE_482e: i2c_master_write (0x482E), i2c_master_write_at (0x4CB9), i2c_master_send_byte
 * (0x62C6) and i2c_master_send_last_byte (0x6465), one compile with OPTIMIZE(8,SPEED) LARGE (c51opts; also exact
 * with REGFILE(R.ORC) added). Source forms the exact build depends on:
 * - The four routines stay in this one file: Keil builds the common-entry blocks only for callers in the same
 *   module. The calls 'i2c_master_send_byte(channel, buf[i])' in the loops of i2c_master_write and
 *   i2c_master_write_at share the block 0x62B5..0x62C6 (i2c_master_send_byte_entry) in front of i2c_master_send_byte (R7 =
 *   channel, R5 = buf[i] with i in R4:R5); the calls 'i2c_master_send_last_byte(channel, buf[i])' share the block
 *   0x644F..0x6465 (i2c_master_send_last_byte_entry) in front of i2c_master_send_last_byte (buf and i read from their adjacent LARGE
 *   slots through DPTR). Callers pass A = channel and DPTR = the slot of buf.
 * - Register pointers are generic pointers to volatile bytes (i2c_master_send_byte reads the events register again
 *   for every test), accessed through the Keil library ?C?CLDPTR (0x06A4) and ?C?CSTPTR (0x06EA). Every pointer is
 *   set to 0 first and the switch has no default. All four return a bit (carry).
 * - LARGE slots: i2c_master_write 0xA4B7..0xA4CB (count 0xA4B9, buf 0xA4BB, i 0xA4BE, the four pointers 0xA4C0..),
 *   bit local ok = BITS 0x20.1; i2c_master_write_at 0xA4BD..0xA4D0 (count and buf passed in their slots 0xA4C1 /
 *   0xA4C3).
 * - The two early exits of i2c_master_send_byte are 'break' (Keil jumps to the shared CLR C / RET).
 * No aids.
 */
#include <reg51.h>
extern unsigned char volatile xdata DAT_EXTMEM_f00a;
extern unsigned char xdata i2c_master_ctrl_bits;
bit i2c_master_wait_tx_ready(unsigned char channel);
bit i2c_master_send_byte(unsigned char channel, unsigned char value);
bit i2c_master_send_last_byte(unsigned char channel, unsigned char value);

/* Register block of hardware I2C channel N (reg_i2c<N>_*): base 0xF039, 0xF041, 0xF089, 0xF091, 0xF09B, 0xF0B8 for
 * channels 0..5, then +0 ctrl, +1 status, +2 mode, +3 events, +4 event_ack, +5 tx_data, +7 address. A channel
 * number above 5 leaves every register pointer 0. */
#define I2C_ACK_ALL_EVENTS   0xFF
#define I2C_EVENT_TX_READY   0x40  /* events bit 6: the channel takes the next byte (also its acknowledge value) */
#define I2C_EVENT_BIT4       0x10  /* events bits 4 and 3 end i2c_master_send_byte with failure */
#define I2C_EVENT_BIT3       0x08
#define I2C_CTRL_STOP        0x20  /* ctrl bit 5, also set by i2c_master_stop */
#define I2C_STATUS_BIT0      0x01  /* waited for after the stop */
#define SEND_TRIES           1000
#define STOP_TRIES           12000

/* i2c_master_write - send 'count' bytes from buf to an I2C device on hardware channel 'channel' (0..5).
 *   device_addr: device address byte, sent as given.
 * Returns 1 when every byte and the stop succeeded; 0 when count is 0 or any step failed or timed out.
 * Called by i2c_master_write_read (with one byte, the register address) right before i2c_master_read.
 *
 * Phases:
 *   1. Pick the register block of the channel.
 *   2. Disable the timer 0 interrupt (ET0), set the address register to 1, acknowledge all events, start with
 *      i2c_master_ctrl_bits | 0x02 and put the address byte into tx_data.
 *   3. Send all bytes but the last with i2c_master_send_byte.
 *   4. Wait until the channel takes a byte again, then send the last byte with the stop.
 * ET0 stays 0 on return; i2c_master_read, which follows in i2c_master_write_read, enables it again.
 */
bit i2c_master_write(unsigned char channel, unsigned char device_addr, unsigned int count, unsigned char *buf)
{
    unsigned int i;
    unsigned char volatile *address, *tx_data, *event_ack, *ctrl;
    bit ok;

    i = 0;
    ok = 1;
    address = 0;
    tx_data = 0;
    event_ack = 0;
    ctrl = 0;
    DAT_EXTMEM_f00a = 0x55;
    if (count < 1) return 0;
    /* 1. Register block of the channel. */
    switch (channel) {
    case 0:
        address = (unsigned char xdata *)0xf040;
        tx_data = (unsigned char xdata *)0xf03e;
        event_ack = (unsigned char xdata *)0xf03d;
        ctrl = (unsigned char xdata *)0xf039;
        break;
    case 1:
        address = (unsigned char xdata *)0xf048;
        tx_data = (unsigned char xdata *)0xf046;
        event_ack = (unsigned char xdata *)0xf045;
        ctrl = (unsigned char xdata *)0xf041;
        break;
    case 2:
        address = (unsigned char xdata *)0xf090;
        tx_data = (unsigned char xdata *)0xf08e;
        event_ack = (unsigned char xdata *)0xf08d;
        ctrl = (unsigned char xdata *)0xf089;
        break;
    case 3:
        address = (unsigned char xdata *)0xf098;
        tx_data = (unsigned char xdata *)0xf096;
        event_ack = (unsigned char xdata *)0xf095;
        ctrl = (unsigned char xdata *)0xf091;
        break;
    case 4:
        address = (unsigned char xdata *)0xf0a2;
        tx_data = (unsigned char xdata *)0xf0a0;
        event_ack = (unsigned char xdata *)0xf09f;
        ctrl = (unsigned char xdata *)0xf09b;
        break;
    case 5:
        address = (unsigned char xdata *)0xf0bf;
        tx_data = (unsigned char xdata *)0xf0bd;
        event_ack = (unsigned char xdata *)0xf0bc;
        ctrl = (unsigned char xdata *)0xf0b8;
        break;
    }
    /* 2. Start with the device address byte. */
    ET0 = 0;
    *address = 0x01;
    *event_ack = I2C_ACK_ALL_EVENTS;
    *ctrl = i2c_master_ctrl_bits | 0x02;
    *tx_data = device_addr;
    /* 3. All bytes but the last. */
    for (i = 0; i < count - 1; i++) {
        DAT_EXTMEM_f00a = 0x55;
        ok &= i2c_master_send_byte(channel, buf[i]);
    }
    /* 4. Last byte with the stop. */
    ok &= i2c_master_wait_tx_ready(channel);
    ok &= i2c_master_send_last_byte(channel, buf[i]);
    return ok;
}

/* i2c_master_write_at - send the byte mem_addr and then 'count' bytes from buf to an I2C device on hardware
 * channel 'channel' (0..5).
 *   device_addr: device address byte, sent as given; mem_addr: only its bits 0..7 are sent.
 * Returns 1 when every byte and the stop succeeded; 0 when count is 0 or any step failed or timed out.
 * Called by i2c_write_eeprom_pages for each piece of up to 8 bytes.
 * Same phases as i2c_master_write, without the address register write and with mem_addr sent first; ET0 is
 * enabled again at the end.
 */
bit i2c_master_write_at(unsigned char channel, unsigned char device_addr, unsigned int mem_addr, unsigned int count, unsigned char *buf)
{
    unsigned int i;
    unsigned char volatile *tx_data, *event_ack, *ctrl;
    bit ok;

    i = 0;
    ok = 1;
    tx_data = 0;
    event_ack = 0;
    ctrl = 0;
    if (count < 1) return 0;
    switch (channel) {
    case 0:
        tx_data = (unsigned char xdata *)0xf03e;
        event_ack = (unsigned char xdata *)0xf03d;
        ctrl = (unsigned char xdata *)0xf039;
        break;
    case 1:
        tx_data = (unsigned char xdata *)0xf046;
        event_ack = (unsigned char xdata *)0xf045;
        ctrl = (unsigned char xdata *)0xf041;
        break;
    case 2:
        tx_data = (unsigned char xdata *)0xf08e;
        event_ack = (unsigned char xdata *)0xf08d;
        ctrl = (unsigned char xdata *)0xf089;
        break;
    case 3:
        tx_data = (unsigned char xdata *)0xf096;
        event_ack = (unsigned char xdata *)0xf095;
        ctrl = (unsigned char xdata *)0xf091;
        break;
    case 4:
        tx_data = (unsigned char xdata *)0xf0a0;
        event_ack = (unsigned char xdata *)0xf09f;
        ctrl = (unsigned char xdata *)0xf09b;
        break;
    case 5:
        tx_data = (unsigned char xdata *)0xf0bd;
        event_ack = (unsigned char xdata *)0xf0bc;
        ctrl = (unsigned char xdata *)0xf0b8;
        break;
    }
    DAT_EXTMEM_f00a = 0x55;
    ET0 = 0;
    *event_ack = I2C_ACK_ALL_EVENTS;
    *ctrl = i2c_master_ctrl_bits | 0x02;
    *tx_data = device_addr;
    ok &= i2c_master_send_byte(channel, mem_addr);
    for (i = 0; i < count - 1; i++) {
        DAT_EXTMEM_f00a = 0x55;
        ok &= i2c_master_send_byte(channel, buf[i]);
    }
    ok &= i2c_master_wait_tx_ready(channel);
    ok &= i2c_master_send_last_byte(channel, buf[i]);
    ET0 = 1;
    return ok;
}

/* i2c_master_send_byte - wait until the channel takes a byte (events bit 6), then hand it 'value' and
 * acknowledge the event. Returns 1 when sent; 0 when events bit 3 or 4 shows up first or after 1000 tests.
 */
bit i2c_master_send_byte(unsigned char channel, unsigned char value)
{
    unsigned int tries;
    unsigned char volatile *events, *tx_data, *event_ack;

    tries = SEND_TRIES;
    events = 0;
    tx_data = 0;
    event_ack = 0;
    switch (channel) {
    case 0:
        events = (unsigned char xdata *)0xf03c;
        tx_data = (unsigned char xdata *)0xf03e;
        event_ack = (unsigned char xdata *)0xf03d;
        break;
    case 1:
        events = (unsigned char xdata *)0xf044;
        tx_data = (unsigned char xdata *)0xf046;
        event_ack = (unsigned char xdata *)0xf045;
        break;
    case 2:
        events = (unsigned char xdata *)0xf08c;
        tx_data = (unsigned char xdata *)0xf08e;
        event_ack = (unsigned char xdata *)0xf08d;
        break;
    case 3:
        events = (unsigned char xdata *)0xf094;
        tx_data = (unsigned char xdata *)0xf096;
        event_ack = (unsigned char xdata *)0xf095;
        break;
    case 4:
        events = (unsigned char xdata *)0xf09e;
        tx_data = (unsigned char xdata *)0xf0a0;
        event_ack = (unsigned char xdata *)0xf09f;
        break;
    case 5:
        events = (unsigned char xdata *)0xf0bb;
        tx_data = (unsigned char xdata *)0xf0bd;
        event_ack = (unsigned char xdata *)0xf0bc;
        break;
    }
    while (tries) {
        tries--;
        if (*events & I2C_EVENT_BIT3) break;
        if (*events & I2C_EVENT_BIT4) break;
        if (*events & I2C_EVENT_TX_READY) {
            *tx_data = value;
            *event_ack = I2C_EVENT_TX_READY;
            return 1;
        }
    }
    return 0;
}

/* i2c_master_send_last_byte - hand the channel 'value' together with the stop (ctrl bit 5), with the timer 0
 * interrupt off for these two writes, then wait for status bit 0. Returns 1 when it came within 12000 tests.
 */
bit i2c_master_send_last_byte(unsigned char channel, unsigned char value)
{
    unsigned int tries;
    unsigned char volatile *tx_data, *ctrl, *status;

    tries = STOP_TRIES;
    tx_data = 0;
    ctrl = 0;
    status = 0;
    switch (channel) {
    case 0:
        tx_data = (unsigned char xdata *)0xf03e;
        ctrl = (unsigned char xdata *)0xf039;
        status = (unsigned char xdata *)0xf03a;
        break;
    case 1:
        tx_data = (unsigned char xdata *)0xf046;
        ctrl = (unsigned char xdata *)0xf041;
        status = (unsigned char xdata *)0xf042;
        break;
    case 2:
        tx_data = (unsigned char xdata *)0xf08e;
        ctrl = (unsigned char xdata *)0xf089;
        status = (unsigned char xdata *)0xf08a;
        break;
    case 3:
        tx_data = (unsigned char xdata *)0xf096;
        ctrl = (unsigned char xdata *)0xf091;
        status = (unsigned char xdata *)0xf092;
        break;
    case 4:
        tx_data = (unsigned char xdata *)0xf0a0;
        ctrl = (unsigned char xdata *)0xf09b;
        status = (unsigned char xdata *)0xf09c;
        break;
    case 5:
        tx_data = (unsigned char xdata *)0xf0bd;
        ctrl = (unsigned char xdata *)0xf0b8;
        status = (unsigned char xdata *)0xf0b9;
        break;
    }
    ET0 = 0;
    *tx_data = value;
    *ctrl |= I2C_CTRL_STOP;
    ET0 = 1;
    while (tries) {
        tries--;
        if (*status & I2C_STATUS_BIT0) return 1;
    }
    return 0;
}
