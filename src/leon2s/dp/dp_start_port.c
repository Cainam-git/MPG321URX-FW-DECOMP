/* dp_start_port  (FUN_a00b05e8)
 *
 * Start a DisplayPort input: reset it, set it up and switch its interrupts on.
 * Name basis: derived - skipped when it is already active and no restart is forced
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00b05e8 @ 0xa00b05e8-0xa00b06e0 (62 words incl. the unreachable ret/restore pair
 * FUN_a00b06d8), flags -mcpu=v8 -Os -g.
 * Source form: the '> 0x80' arm comes first.
 */
extern unsigned char ARR_a8079318[];
extern void dp_irq_disable_port(unsigned char);
extern void dp_apply_port_link_bytes(unsigned char);
extern void dp_set_port_enable_bits(unsigned char, unsigned char, unsigned char);
extern void dp_apply_port_record(unsigned char);
extern void dp_init_port_registers(unsigned char);
extern unsigned char sys_get_chip_revision(void);
extern void dp_reg_write8(unsigned char, unsigned short, unsigned char);
extern void dp_reg_update_bits(unsigned char, unsigned short, unsigned char, unsigned char);
extern void dp_write_phy_table(unsigned char);
extern void dp_clear_start_bits(unsigned char);
extern void dp_irq_enable_port(unsigned char);

/* Start DisplayPort input `port`: reset it, set it up and switch its interrupts on, then mark it
 * active (1) in ARR_a8079318. Nothing happens when it is already marked active and `force` is 0.
 * A non-zero `force` also applies the port record (dp_apply_port_record). */
void dp_start_port(unsigned char port, unsigned char force)
{
    if (ARR_a8079318[port] != 1 || force != 0) {
        dp_irq_disable_port(port);
        dp_apply_port_link_bytes(port);
        dp_set_port_enable_bits(port, 1, 1);
        if (force != 0)
            dp_apply_port_record(port);
        dp_init_port_registers(port);
        /* A chip revision above 0x80 gets three direct register writes; an older one gets the
         * PHY table instead. */
        if (sys_get_chip_revision() > 0x80) {
            dp_reg_write8(port, 0x21d, 0x84);
            dp_reg_update_bits(port, 0xc0, 0x80, 0);
            dp_reg_update_bits(port, 0xda, 0x10, 1);
        } else {
            dp_write_phy_table(port);
        }
        dp_clear_start_bits(port);
        ARR_a8079318[port] = 1;
        dp_irq_enable_port(port);
    }
}
