/* i2c_master_receive_byte  (FUN_CODE_611a)
 *
 * Wait for and take one received byte on a hardware I2C channel.
 *   channel: I2C channel
 *   buf: destination
 * Returns: 1 on success, 0 on error or time-out
 * Name basis: derived - polls bit 5 of the channel's events register up to 1000 times (gives up on events bit
 *   3), reads rx_data, acknowledges with 0x20 in event_ack
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_611a @ 0x611a  (OPTIMIZE(8,SPEED) LARGE).
 * LARGE slots: buf 0xA4CF..D1 (generic pointer), tries 0xA4D2..D3, events, rx_data, event_ack (generic pointers to
 * volatile bytes) 0xA4D4..DC.
 * The early exit is 'break' (Keil jumps to the shared CLR C / RET). Pointer accesses go through ?C?CLDPTR (0x06A4) /
 * ?C?CSTPTR (0x06EA). Same shape as i2c_master_send_byte in src/8051_bank1/i2c/i2c_master_write.c. No aids.
 */
#define RECEIVE_TRIES        1000
#define I2C_EVENT_BIT3       0x08  /* events bit 3: ends the wait with failure (as in i2c_master_send_byte) */
#define I2C_EVENT_RX_READY   0x20  /* events bit 5: a byte is waiting in rx_data; also its acknowledge value */

/*
 * i2c_master_receive_byte - wait for the next byte that a hardware I2C channel has read and take it.
 *   channel  hardware I2C channel 0..5 (registers reg_i2c<N>_events +3, _event_ack +4, _rx_data +6)
 *   buf      where the byte goes
 * Returns 1 with the byte stored and the event acknowledged; 0 when events bit 3 comes first or after 1000 tests
 * without a byte. Any other channel number leaves the register pointers at 0.
 * Called by i2c_master_read once per byte.
 */
bit i2c_master_receive_byte(unsigned char channel, unsigned char *buf)
{
    unsigned int tries;
    unsigned char volatile *events, *rx_data, *event_ack;

    tries = RECEIVE_TRIES;
    events = 0;
    rx_data = 0;
    event_ack = 0;
    switch (channel) {
    case 0:
        events = (unsigned char xdata *)0xf03c;
        rx_data = (unsigned char xdata *)0xf03f;
        event_ack = (unsigned char xdata *)0xf03d;
        break;
    case 1:
        events = (unsigned char xdata *)0xf044;
        rx_data = (unsigned char xdata *)0xf047;
        event_ack = (unsigned char xdata *)0xf045;
        break;
    case 2:
        events = (unsigned char xdata *)0xf08c;
        rx_data = (unsigned char xdata *)0xf08f;
        event_ack = (unsigned char xdata *)0xf08d;
        break;
    case 3:
        events = (unsigned char xdata *)0xf094;
        rx_data = (unsigned char xdata *)0xf097;
        event_ack = (unsigned char xdata *)0xf095;
        break;
    case 4:
        events = (unsigned char xdata *)0xf09e;
        rx_data = (unsigned char xdata *)0xf0a1;
        event_ack = (unsigned char xdata *)0xf09f;
        break;
    case 5:
        events = (unsigned char xdata *)0xf0bb;
        rx_data = (unsigned char xdata *)0xf0be;
        event_ack = (unsigned char xdata *)0xf0bc;
        break;
    }
    while (tries) {
        tries--;
        if (*events & I2C_EVENT_BIT3) break;
        if (*events & I2C_EVENT_RX_READY) {
            *buf = *rx_data;
            *event_ack = 0x20;
            return 1;
        }
    }
    return 0;
}
