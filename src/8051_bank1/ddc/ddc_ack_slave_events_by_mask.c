/* ddc_ack_slave_events_by_mask  (FUN_CODE_cb65)
 *
 * Write 0x10 to the event acknowledge registers of the slave ports chosen by a bit mask.
 *   port_mask: bits 0..6 pick the slave ports 0..6
 * Note: No caller in the bank-1 image.
 * Name basis: descriptive - 0x10 to reg_i2c0_event_ack .. reg_i2c6_event_ack (0xF03D, F045, F08D, F095, F09F,
 *   F0BC, F144), one per mask bit; the same write as in ddc_rearm_idle_slaves
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_cb65 @ 0xCB65..0xCBAC (71 bytes)  Byte-exact with OPTIMIZE(8,SPEED) (no register file).
 * Source form: the mask bits are tested with 'JNB ACC.n'.
 */
extern unsigned char xdata reg_i2c0_event_ack, reg_i2c1_event_ack, reg_i2c2_event_ack, reg_i2c3_event_ack, reg_i2c4_event_ack;
extern unsigned char xdata reg_i2c5_event_ack, reg_i2c6_event_ack;

/*
 * Bit i of port_mask (i = 0..6) selects slave port i; for each selected port
 * 0x10 is written to its event acknowledge register (0xF03D, 0xF045, 0xF08D,
 * 0xF095, 0xF09F, 0xF0BC, 0xF144). No caller in the bank-1 image.
 */
void ddc_ack_slave_events_by_mask(unsigned char port_mask)
{
    if (port_mask & 0x01) reg_i2c0_event_ack = 0x10;
    if (port_mask & 0x02) reg_i2c1_event_ack = 0x10;
    if (port_mask & 0x04) reg_i2c2_event_ack = 0x10;
    if (port_mask & 0x08) reg_i2c3_event_ack = 0x10;
    if (port_mask & 0x10) reg_i2c4_event_ack = 0x10;
    if (port_mask & 0x20) reg_i2c5_event_ack = 0x10;
    if (port_mask & 0x40) reg_i2c6_event_ack = 0x10;
}
