/* dp_check_mrx0_wake  (FUN_CODE_da3a)
 *
 * Report and log a wake request from DisplayPort receiver 0.
 * Returns: 1 when woken
 * Name basis: proven - prints 'mrx wake up'; flag bit 0 of the DP sink state 0xA6FD
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_da3a @ 0xda3a  OPTIMIZE(8,SPEED) LARGE (SMALL gives other code).
 * The local bit is BIT 0x01.
 */
#define DP_RX0_FLAG 0x01  /* bit 0 of dp_aux_port_state_flags (receiver 0) */

extern unsigned char xdata dp_aux_port_state_flags;
extern void lib_printf517(void *fmt, ...) large;

/*
 * Return 1 when bit 0 of dp_aux_port_state_flags is set, and print "mrx wake up" in that case. Twin of
 * dp_check_mrx1_wake for the other receiver.
 */
bit dp_check_mrx0_wake(void)
{
    bit set;
    unsigned char flag_bits;

    set = 0;
    flag_bits = dp_aux_port_state_flags & DP_RX0_FLAG;
    if (flag_bits == 1) set = 1;
    if (set) lib_printf517((void code *)0x6aa6);
    return set;
}
