/* dp_pulse_hpd_block  (FUN_a00acff4)
 *
 * Pulse bit 1 of register 0xCF0132C0 and apply a per-port follow-up.
 * Name basis: descriptive - one-unit wait in between
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00acff4 @ 0xa00acff4, flags -mcpu=v8 -Os -g.
 * Source form: the register is reached through a volatile pointer (read-modify-written twice).
 */
/* The byte 0x11F of a DP port record; the other bytes are not used here. */
struct dp_input_record {
    unsigned char before_0x11f[0x11f];
    unsigned char byte_0x11f;
    unsigned char after_0x11f[0x12c - 0x120];
};
extern struct dp_input_record dp_input_records[];   /* one 300-byte record per port */
extern unsigned char dp_hpd_pulse_flag;         /* tested by dp_is_port_ready_for_service */
extern void timer_delay_long_units(int);

/*
 * Set bit 1 of register 0xCF0132C0, wait one unit (timer_delay_long_units), clear the bit again. Then, if byte
 * 0x11F of the record of port 0 or of port 1 is 1, clear dp_hpd_pulse_flag.
 * Callers: dp_setup_service_block, dp_update_pending_bits, ipc_dispatch_command.
 */
void dp_pulse_hpd_block(void)
{
    volatile unsigned int *reg = (volatile unsigned int *)0xcf0132c0;

    *reg |= 2;
    timer_delay_long_units(1);
    *reg &= ~2;
    if (dp_input_records[0].byte_0x11f == 1 || dp_input_records[1].byte_0x11f == 1)
        dp_hpd_pulse_flag = 0;
}
