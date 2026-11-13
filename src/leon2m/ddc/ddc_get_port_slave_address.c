/* ddc_get_port_slave_address  (FUN_a01243c8)
 *
 * Return the stored DDC/CI slave address of a port.
 *   port: port number 0..7 (low byte used)
 * Returns: the port's byte of ddc_port_slave_addresses
 * Name basis: derived - byte table ddc_port_slave_addresses; the callers pass the result as the address of
 *   ipc_8051_enable_ddc_slave
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01243c8 @ 0xa01243c8, flags -mcpu=v8 -O2 -g.
 */
extern unsigned char ddc_port_slave_addresses[];      /* one DDC/CI slave address per port */

/*
 * Return the DDC/CI slave address stored for a port (the byte table at 0xA802A428, 0x6E at power-on for ports
 * 0..6, set by ddc_set_port_slave_address).
 *
 *   port  index into the byte table
 */
unsigned char ddc_get_port_slave_address(unsigned int port)
{
    return ddc_port_slave_addresses[(port & 0xff)];
}
