/* dp_mst_wait_downstream_ready  (FUN_a00d64ec)
 *
 * Wait, in up to ten tries, until the output reports that it has taken the message.
 * Name basis: derived - sets bit 0 of 0xCF013204, waits, reads DPCD 0x2C0 and tests bit 1
 *
 * Matching notes
 * --------------
 * FUN_a00d64ec (leon2s, 0xa00d64ec-0xa00d6560, 29 words). Flags -mcpu=v8 -Os -g.
 * dp_tx_aux_read_byte returns u8 and the result is unsigned char (firmware btst 0xff; a signed char result
 * gives sll 24). Source form: the decrement sits in the loop condition ('while (counter-- != 0)'; the
 * firmware keeps the old value live and moves the new one into %l0; '--counter != 0xff' gives the same code).
 */
#define REG_CF013204 (*(volatile unsigned int *)0xcf013204)

extern unsigned char dp_tx_aux_read_byte(int, int, int, void *);
extern int timer_delay_long_units(int);

/* Poll the sink: up to 10 tries, each sets bit 0 of register 0xcf013204, waits 5 delay units and reads the
 * sink's DPCD byte 0x2C0 over AUX (output 0, command 0x90). A failed read counts as 0. Stops as soon as
 * bit 1 of the byte is set; gives up silently after the tenth try. */
void dp_mst_wait_downstream_ready(void)
{
    unsigned char dpcd_byte;
    unsigned char counter = 9;
    unsigned char result;
    
    do {
        REG_CF013204 |= 1;
        timer_delay_long_units(5);
        dpcd_byte = 0;
        result = dp_tx_aux_read_byte(0, 0x90, 0x2c0, &dpcd_byte);
        if ((result) != 0) {
            dpcd_byte = 0;
        }
        if ((dpcd_byte & 2) != 0) {
            break;
        }
    } while (counter-- != 0);

}
