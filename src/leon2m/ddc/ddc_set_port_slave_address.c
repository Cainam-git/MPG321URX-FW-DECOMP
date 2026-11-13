/* ddc_set_port_slave_address  (FUN_a01255dc)
 *
 * Store the DDC/CI slave address of a port.
 *   port: port number 0..7 (low byte used)
 *   value: the slave address
 * Name basis: derived - byte table ddc_port_slave_addresses; the one caller sends the same byte with
 *   ipc_8051_enable_ddc_slave
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01255dc @ 0xa01255dc, flags -mcpu=v8 -O2 -g.
 */
extern unsigned char ddc_port_slave_addresses[];      /* one DDC/CI slave address per port */

/*
 * Store the DDC/CI slave address of a port in the byte table at 0xA802A428 (read back by
 * ddc_get_port_slave_address).
 *
 *   port   index into the byte table
 *   value  the slave address
 */
void ddc_set_port_slave_address(unsigned int port, unsigned char value)
{
    ddc_port_slave_addresses[(port & 0xff)] = value;
    return;
}
