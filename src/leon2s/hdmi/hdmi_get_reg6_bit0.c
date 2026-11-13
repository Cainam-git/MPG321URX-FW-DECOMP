/* hdmi_get_reg6_bit0  (FUN_a00910d0)
 *
 * Return bit 0 of HDMI receiver register 6.
 *   port: HDMI 2.0 receiver 0/1
 * Name basis: descriptive - mailbox command 0x83 sub 0 for ports 0/1
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00910d0 @ 0xa00910d0 (-mcpu=v8 -Os -g)
 * Source form: the callee is declared without a prototype and returns int.
 */

#define RX_REG_6    6

extern int hdmi_reg_read8();

/* Returns bit 0 of register 6 of HDMI 2.0 receiver "port". Called by ipc_dispatch_command for the main
   program's port status request (the HDMI 2.1 receivers answer with hdmi_rx21_status04_bit17). */
unsigned char hdmi_get_reg6_bit0(unsigned int port)

{
  port = port & 0xff;
  return hdmi_reg_read8(port,RX_REG_6) & 1;
}
