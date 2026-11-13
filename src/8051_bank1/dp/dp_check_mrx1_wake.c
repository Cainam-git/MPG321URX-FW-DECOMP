/* dp_check_mrx1_wake  (FUN_CODE_da57)
 *
 * Report and log a wake request from DisplayPort receiver 1.
 * Returns: 1 when woken
 * Name basis: proven - prints 'mrx1 wake up'; flag bit 4 of the DP sink state 0xA6FD
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_da57 @ 0xda57  Options: OPTIMIZE(8,SPEED) LARGE.
 * The local bit is BIT 0x01.
 */
#define DP_RX1_FLAG 0x10  /* bit 4 of dp_aux_port_state_flags (receiver 1) */

extern unsigned char xdata dp_aux_port_state_flags;
extern void lib_printf517(void *fmt, ...) large;

/*
 * Return 1 when bit 4 of dp_aux_port_state_flags is set, and print "mrx1 wake up" in that case. Twin of
 * dp_check_mrx0_wake for the other receiver.
 */
bit dp_check_mrx1_wake(void)
{
    bit set;
    unsigned char flag_bits;

    set = 0;
    flag_bits = dp_aux_port_state_flags & DP_RX1_FLAG;
    if (flag_bits == 0x10) set = 1;
    if (set) lib_printf517((void code *)0x6ab4);
    return set;
}
