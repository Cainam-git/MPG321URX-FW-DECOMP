/* startup_init_8051_i2c_ports  (FUN_a01243dc)
 *
 * Have the 8051 switch the DDC/CI slave on for ports 0, 2, 4, 6 and off for ports 1, 3, 5, 7.
 * Note: On: 8051 command 0x07 with the port mask 1 << port and the port's byte of ddc_port_slave_addresses;
 *   off: command 0x08.
 * Name basis: derived - ipc_8051_enable_ddc_slave for the ports of mask 0x55, ipc_8051_disable_ddc_slave for
 *   the others; called by startup_bring_up_system
 *
 * Matching notes
 * --------------
 * leon2m FUN_a01243dc, flags -mcpu=v8 -O3 -g.
 * Source form: the shifted mask is a local 'int bit = 1;' declared at the top of the loop body. gcc 3.4's loop
 * pass hoists loop-invariant sets in the order it meets them in the body; with '1 << i' the constant 1 is first met
 * inside the arms, after the test's 0x55, so 'mov 0x55' is hoisted first (2 words swapped). With 'bit' set at the
 * top of the body, 'bit = 1' is met first and hoisted first, as in the firmware. The variable is real code (its
 * value is the shifted mask), no volatile, no asm, no dummy data. A similar 'int one = 1' before the loop also
 * moves the constant ahead of 'i = 0' and does not match.
 */

/* The ports that get a DDC/CI slave address: ports 0, 2, 4 and 6. */
#define DDC_SLAVE_PORTS 0x55

extern unsigned char ddc_port_slave_addresses[];    /* the slave address byte of each port 0..7 */
extern void ipc_8051_enable_ddc_slave(unsigned char, unsigned char);
extern void ipc_8051_disable_ddc_slave(unsigned char);

/*
 * For each port i = 0..7 send one command to the 8051: ports 0, 2, 4 and 6 (the bits of DDC_SLAVE_PORTS) get
 * ipc_8051_enable_ddc_slave with the port mask 1 << i and the slave address ddc_port_slave_addresses[i]; ports 1, 3, 5 and 7
 * get ipc_8051_disable_ddc_slave with the mask. Each command is sent with a wait for the 8051 to take it (see
 * those two routines). Called by startup_bring_up_system after startup_init_display_output.
 */
void startup_init_8051_i2c_ports(void)
{
    unsigned char i;
    for (i = 0; i < 8; i++) {
        int bit = 1;
        if ((DDC_SLAVE_PORTS >> i) & 1)
            ipc_8051_enable_ddc_slave(bit << i, ddc_port_slave_addresses[i]);
        else
            ipc_8051_disable_ddc_slave(bit << i);
    }
}
