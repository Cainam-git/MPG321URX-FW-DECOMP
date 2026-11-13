/* i2c_master_wait_tx_ready  (FUN_CODE_bae2)
 *
 * Wait until a hardware I2C channel is ready to send.
 *   ch: I2C channel
 * Returns: 1 when ready
 * Name basis: derived - polls bit 6 of the channel's events register 0xF03C/0xF044/.. up to 12000 times
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_bae2, OPTIMIZE(8,SPEED) LARGE. The register is read through a generic pointer (?C?CLDPTR).
 */
extern unsigned char xdata reg_i2c0_events, reg_i2c1_events, reg_i2c2_events, reg_i2c3_events, reg_i2c4_events, reg_i2c5_events;

/*
 * i2c_master_wait_tx_ready - poll the events register of I2C channel ch (0..5: XDATA 0xF03C, 0xF044, 0xF08C,
 * 0xF094, 0xF09E, 0xF0BB) up to 12000 times for bit 6 (0x40). Returns 1 as soon as it is set, 0 when the tries run
 * out. For any other ch the pointer stays 0 and XDATA address 0 is polled.
 * Callers: i2c_master_write and i2c_master_write_at.
 */
bit i2c_master_wait_tx_ready(unsigned char ch)
{
    unsigned int tries;
    unsigned char *events;

    tries = 12000;
    events = 0;
    switch (ch) {
    case 0: events = &reg_i2c0_events; break;
    case 1: events = &reg_i2c1_events; break;
    case 2: events = &reg_i2c2_events; break;
    case 3: events = &reg_i2c3_events; break;
    case 4: events = &reg_i2c4_events; break;
    case 5: events = &reg_i2c5_events; break;
    }
    while (tries != 0) {
        tries--;
        if (*events & 0x40) return 1;
    }
    return 0;
}
