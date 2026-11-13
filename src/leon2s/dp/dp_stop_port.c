/* dp_stop_port  (FUN_a00b0568)
 *
 * Stop a DisplayPort input that is active: interrupts off and its blocks reset.
 * Name basis: derived - only when the port's active byte at 0xA8079318 is set
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00b0568 @ 0xa00b0568 (-mcpu=v8 -Os -g)
 * Source form: the routine is declared void but ends in `return port_index;` (a value the caller never
 * uses); the do/while over the two array entries is kept as is.
 */
extern void dp_write_port_stop_sequence(unsigned char port);
extern void dp_set_reg1143c_bits(void);
extern int dp_apply_port_link_bytes(unsigned char port);
extern void dp_irq_disable_port(unsigned char port);
extern unsigned char ARR_a8079318[];

/* Stop DisplayPort input `port` when it is marked active in ARR_a8079318 (one byte per input, 0 or 1):
 * interrupts off, link bytes applied, the fixed stop register sequence written, mark cleared. When no
 * input is active any more (both bytes 0), also sets the bits of register 0xCF01143C
 * (dp_set_reg1143c_bits). Does nothing for an input that is not active. */
void dp_stop_port(unsigned char port)
{
    unsigned char any_active;
    unsigned int next_index;
    unsigned char i;
    unsigned char port_index;
    
    port_index = port;
    any_active = 0;
    if (ARR_a8079318[port_index] != 0) {
        dp_irq_disable_port(port);
        dp_apply_port_link_bytes(port_index);
        dp_write_port_stop_sequence(port);
        ARR_a8079318[port_index] = 0;
        i = 0;
        next_index = 0;
        do {
            any_active = any_active | ARR_a8079318[i];
            i = (i + 1) & 0xff;
            next_index = i;
        } while (next_index <= 1);
        if (any_active == 0) {
            dp_set_reg1143c_bits();
            return port_index;
        }
    }
    return port_index;
}
