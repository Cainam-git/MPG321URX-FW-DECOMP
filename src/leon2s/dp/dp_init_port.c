/* dp_init_port  (FUN_a00b1028)
 *
 * Run the full set-up sequence of a DisplayPort input.
 * Name basis: derived - fixed sequence of set-up calls and register writes with dp_start_port(port, 1) in the
 *   middle; called by input_init_receivers and by a command from the main processor
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00b1028 @ 0xa00b1028-0xa00b115c, -mcpu=v8 -Os -g.
 * Source form: the byte stores into dp_port_lane_units are written in the order 1, 2, 0, 3, 4.
 */
/* The 300-byte record of one DP input (array dp_input_records); only the used field is named. */
struct dp_input_record { unsigned char pad[0x119]; unsigned char byte_0x119; unsigned char rest[0x12c - 0x11a]; };
extern struct dp_input_record dp_input_records[];
extern unsigned char dp_port_lane_units[];
extern unsigned char dp_init_byte;
extern void dp_irq_disable_port(unsigned char);
extern unsigned char sys_get_chip_revision(void);
extern unsigned int dp_read_reg34400_bit0(void);
extern void dp_set_port_swap(unsigned char);
extern void dp_write_lane_tables(void);
extern void dp_status_reg_update_bits(unsigned char, unsigned short, unsigned char, unsigned char);
extern void dp_start_port(unsigned char, unsigned char);
extern void dp_setup_service_block(unsigned char);
extern void dp_reset_port(unsigned char);
extern void dp_reg_update_bits(unsigned char, unsigned short, unsigned char, unsigned char);
extern void dp_irq_enable_port(unsigned char);

#define REG_CF0147F0 (*(volatile unsigned int *)0xcf0147f0)
#define REG_CF00F21C (*(volatile unsigned int *)0xcf00f21c)

/* Runs the full set-up sequence of a DP input.
 *
 * Order: interrupts of the port off (dp_irq_disable_port); on chip revision above 0x81 bit 7 of 0xcf0147f0 is
 * set and dp_port_lane_units becomes {0, 2, 4, 6, 5}; the port swap is set from dp_read_reg34400_bit0() when
 * flag is non-zero, else from byte 0x119 of the port's record; dp_write_lane_tables; mask 1 of status register
 * 0x3e switched off; dp_start_port(port, 1); dp_setup_service_block(0); bits 3, 4 and 6 of 0xcf00f21c cleared;
 * dp_reset_port; bit 1 of register 0x20 set and cleared again; mask 1 of status register 0x3e switched on;
 * interrupts of the port on (dp_irq_enable_port); dp_init_byte = 0.
 *
 * port: DP input (0 or 1). flag: non-zero = take the port swap from the hardware bit instead of the record.
 * Called by input_init_receivers and by the main-processor command handler ipc_dispatch_command.
 */
void dp_init_port(unsigned char port, unsigned char flag)
{
    dp_irq_disable_port(port);
    if (sys_get_chip_revision() > 0x81) {
        REG_CF0147F0 |= 0x80;
        dp_port_lane_units[1] = 2;
        dp_port_lane_units[2] = 4;
        dp_port_lane_units[0] = 0;
        dp_port_lane_units[3] = 6;
        dp_port_lane_units[4] = 5;
    }
    if (flag)
        dp_set_port_swap(dp_read_reg34400_bit0());
    else
        dp_set_port_swap(dp_input_records[port].byte_0x119);
    dp_write_lane_tables();
    dp_status_reg_update_bits(port, 0x3e, 1, 0);
    dp_start_port(port, 1);
    dp_setup_service_block(0);
    REG_CF00F21C &= ~0x58;
    dp_reset_port(port);
    dp_reg_update_bits(port, 0x20, 2, 1);
    dp_reg_update_bits(port, 0x20, 2, 0);
    dp_status_reg_update_bits(port, 0x3e, 1, 1);
    dp_irq_enable_port(port);
    dp_init_byte = 0;
}
