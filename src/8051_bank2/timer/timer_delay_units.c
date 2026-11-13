/* timer_delay_units  (FUN_CODE_e44b)
 *
 * Wait for n times four base delays.
 * Name basis: proven - loop over timer_delay_base
 *
 * Matching notes
 * --------------
 * 8051_bank2 FUN_CODE_e44b @ 0xe44b, OPTIMIZE(8,SPEED) REGFILE(R.ORC).
 */
extern unsigned char xdata fwupd_svc_packet[];
unsigned char i2c_write_packet(unsigned char addr, unsigned char len, unsigned char *buf);
unsigned char i2c_read_packet(unsigned char addr, unsigned char *buf);
void fwupd_wait_ready_line(unsigned int t);
void fwupd_svc_read_reply(unsigned char *buf);
void timer_delay_units(unsigned char n);
void timer_delay_base(void);

/* The update agent's general wait: `units` delay units, each four calls of timer_delay_base. Its length follows
 * timer_delay_loop_count, which uart_set_baud_rate sets. Used all over the update agent (after service packets,
 * between USB controller steps, inside fwupd_wait_ready_line). */
void timer_delay_units(unsigned char units)
{
    while (units--) {
        timer_delay_base();
        timer_delay_base();
        timer_delay_base();
        timer_delay_base();
    }
}
