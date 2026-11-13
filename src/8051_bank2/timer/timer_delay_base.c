/* timer_delay_base  (FUN_CODE_e478)
 *
 * Wait for one base delay.
 * Name basis: proven - idle loop set by the XDATA value at 0x09D0
 *
 * Matching notes
 * --------------
 * 8051_bank2 FUN_CODE_e478 @ 0xe478, no options recorded: the default OPTIMIZE(7,SPEED).
 */
extern unsigned char xdata fwupd_svc_packet[];
unsigned char i2c_write_packet(unsigned char addr, unsigned char len, unsigned char *buf);
unsigned char i2c_read_packet(unsigned char addr, unsigned char *buf);
void fwupd_wait_ready_line(unsigned int t);
void fwupd_svc_read_reply(unsigned char *buf);
void timer_delay_units(unsigned char n);
void timer_delay_base(void);
#include <intrins.h>
extern unsigned int xdata timer_delay_loop_count;

/* One NOP per count of timer_delay_loop_count (16 bits). uart_set_baud_rate sets the count from the same clock
 * factor as the serial port rate (factor * 12.5). timer_delay_units calls this four times per unit. */
void timer_delay_base(void)
{
    unsigned int rounds;
    rounds = timer_delay_loop_count;
    while (rounds--) _nop_();
}
