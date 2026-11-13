/* dp_update_fec_ready  (FUN_a00ac41c)
 *
 * Report and apply a change of the FEC-ready state of a DP receiver.
 *   port: DP receiver
 *   en: enable
 * Name basis: proven - prints 'source set DP%d FEC ready !!'; register 0x460 bit 0, rewrites 0x30 / 0x460
 *
 * Matching notes
 * --------------
 * FUN_a00ac41c (leon2s), flags -mcpu=v8 -Os -g.
 * Source form: en is copied into an int local "enable_now" before the test (keeps en in its own register).
 */
extern unsigned char dp_fec_ready_state;        /* last value stored by this routine */
extern unsigned char dp_reg_read8(unsigned char, unsigned short);
extern void dp_reg_update_bits(unsigned int, unsigned short, unsigned int, unsigned int);
extern int dbg_printf(const char *, ...);

/*
 * Set bit 0 of receiver register 0x460 ("FEC ready") to the wanted value.
 *
 * First, if the stored value dp_fec_ready_state differs from bit 0 of register 0x460, it prints
 * "source set DP%d FEC ready !!". Then it returns without a write when "enable" equals the register bit and
 * force is 0. Otherwise it sets bit 7 of register 0x30, writes bit 0 of register 0x460 (1 when enable is 1, else
 * 0), stores that value in dp_fec_ready_state, and clears bit 7 of register 0x30 again.
 * dp_run_link_state calls it.
 *   port: DP receiver
 *   enable: 1 sets the bit, any other value clears it
 *   force: non-zero writes even when the bit already has the wanted value
 */
void dp_update_fec_ready(unsigned char port, unsigned char enable, unsigned char force)
{
    int enable_now;

    if (dp_fec_ready_state != (dp_reg_read8(port, 0x460) & 1))
        dbg_printf("source set DP%d FEC ready !!\r\n", port);
    if (enable == (dp_reg_read8(port, 0x460) & 1) && !force)
        return;
    dp_reg_update_bits(port, 0x30, 0x80, 1);
    enable_now = enable;
    if (enable_now == 1) {
        dp_fec_ready_state = enable_now;
        dp_reg_update_bits(port, 0x460, 1, 1);
    } else {
        dp_fec_ready_state = 0;
        dp_reg_update_bits(port, 0x460, 1, 0);
    }
    dp_reg_update_bits(port, 0x30, 0x80, 0);
}
