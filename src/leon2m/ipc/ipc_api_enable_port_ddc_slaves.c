/* ipc_api_enable_port_ddc_slaves  (FUN_a01486c4)
 *
 * Switch the 8051's DDC/CI slaves of the ports in mask 0x55 on or off (8051 commands 0x07 and 0x08).
 * Note: On: masked ports enabled with the port's stored slave address, the other four disabled; off: only the
 *   masked ports disabled.
 * Name basis: derived - ipc_8051_enable_ddc_slave (command 0x07) and ipc_8051_disable_ddc_slave (command 0x08)
 *   per port bit; no routine calls it
 *
 * Matching notes
 * --------------
 * FUN_a01486c4, flags -mcpu=v8 -O3 -g -msoft-float (the register choice of the loop set-up depends on it).
 * No direct callers were found (the address may be reached through a pointer).
 */
#define DDC_PORT_MASK 0x55              /* bits 0, 2, 4 and 6 of the port mask */

extern unsigned char ddc_get_port_slave_address(unsigned int port);
extern void ipc_8051_disable_ddc_slave(unsigned char port_mask);
extern void ipc_8051_enable_ddc_slave(unsigned char port_mask, unsigned char address);

/*
 * Switch the DDC/CI slave of the ports in the mask 0x55 (bits 0, 2, 4 and 6) on or off through the 8051.
 *   enable  non-zero: for each of the eight ports one command, port by port: ports in the mask are enabled
 *           (ipc_8051_enable_ddc_slave, command 0x07) with the port's stored slave address, the others
 *           are disabled (ipc_8051_disable_ddc_slave, command 0x08);
 *           0: the ports in the mask are disabled
 * No direct caller was found (the address may be reached through a pointer).
 */
void ipc_api_enable_port_ddc_slaves(unsigned char enable)
{
    unsigned char i;

    if (enable) {
        for (i = 0; i < 8; i++) {
            if ((DDC_PORT_MASK >> i) & 1)
                ipc_8051_enable_ddc_slave(1 << i, ddc_get_port_slave_address(i));
            else
                ipc_8051_disable_ddc_slave(1 << i);
        }
    } else {
        for (i = 0; i < 8; i++) {
            if ((DDC_PORT_MASK >> i) & 1)
                ipc_8051_disable_ddc_slave(1 << i);
        }
    }
}
