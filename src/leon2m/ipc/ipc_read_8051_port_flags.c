/* ipc_read_8051_port_flags  (FUN_a002c204)
 *
 * Return the shared 8051 byte at XDATA 0xF224.
 * Returns: byte value
 * Note: Register 0xCF03C890; input_apply_8051_port_flags tests port-record bits against it.
 * Name basis: descriptive - 8051 window mapping; purpose not shown
 *
 * Matching notes
 * --------------
 * FUN_a002c204 (leon2m 0xa002c204, leaf), flags -mcpu=v8 -O3 -g.
 * Source form: the register is a volatile word read; the result is masked with 0xFF and returned as unsigned int.
 */
#define reg_ipc_shared_hdmi_status (*(volatile unsigned int *)0xcf03c890)

/*
 * Read the shared status register that has one bit per HDMI port (data name reg_ipc_shared_hdmi_status;
 * XDATA 0xF224 of the 8051).
 * Returns the low byte of the register. The caller input_apply_8051_port_flags tests it against the port mask
 * of each channel record.
 */
unsigned int ipc_read_8051_port_flags(void)
{
  return reg_ipc_shared_hdmi_status & 0xff;
}
