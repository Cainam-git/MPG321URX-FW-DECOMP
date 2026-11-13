/* power_test_port_wake_status  (FUN_CODE_d92a)
 *
 * Report bit 6 of the paged status register of input port page.
 *   page: port page
 * Returns: 1 when set
 * Note: Only on chip id 0x20.
 * Name basis: descriptive - reg_read_paged_byte(page, 0x041A) bit 6; part of the standby wake check of each
 *   port
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_d92a @ 0xd92a  Options: OPTIMIZE(8,SPEED).
 * Source form: the parameter stays in R7 for reg_read_paged_byte (nothing writes R7 before the call). The
 * nested ?: gives the firmware's three MOV R7,#k and MOV A,R7 / ADD A,#0FFH; the if/else form puts the result in
 * DATA. reg_chip_id is volatile (startup_init_chip_regs re-reads it four times).
 */
#define CHIP_ID_20            0x20
#define PORT_STATUS_SELECT_OFF 0x041a  /* select byte 0x04, offset 0x1A in the port page */
#define PORT_STATUS_BIT6       0x40

extern unsigned char volatile xdata reg_chip_id;
unsigned char reg_read_paged_byte(unsigned char page, unsigned int select_offset);

/*
 * Return 1 when bit 6 of the status register (select 0x04, offset 0x1A) in window page 'page' of the input
 * ports is set. Always 0 unless the chip id is 0x20. Part of the standby wake check of each port.
 */
bit power_test_port_wake_status(unsigned char page)
{
    return (reg_chip_id == CHIP_ID_20) ? ((reg_read_paged_byte(page, PORT_STATUS_SELECT_OFF) & PORT_STATUS_BIT6) ? 1 : 0) : 0;
}
