/* input_port_handle_reg71_bits  (FUN_a00c59e0)
 *
 * Act on two status bits of register 0x71 of an input.
 * Name basis: descriptive - only when bits 0-1 are both set
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00c59e0 @ 0xa00c59e0, flags -mcpu=v8 -Os -g.
 * Source form: Ghidra's declarations are kept (the register routines are declared without parameter lists,
 * the routine returns the write routine's result in one path, and parameters 2 to 6 are never read).
 */
typedef unsigned char undefined, undefined1, byte, uchar, bool;
typedef unsigned short undefined2, ushort, word;
typedef unsigned int undefined4, uint, ulong, dword, undefined3;
typedef unsigned long long undefined8, ulonglong;
typedef long long longlong;
typedef signed char sbyte;
typedef int code();
#define true 1
#define false 0
#define CONCAT44(a, b) (((unsigned long long)(a) << 32) | (unsigned int)(b))
extern void hdmi_port_reg_write8();
extern void hdmi_port_reg_update_bits();
extern int hdmi_port_reg_read8();
extern byte hdcp_rx_record_hdmi20[];

/*
 * Per-pass service of one HDMI input (port 0..3), called by input_update_port_records for a port whose
 * record has bit 22 set. It does nothing unless bits 0 and 1 of register 0x71 are both set. Then it writes 3
 * to register 0x71, and
 *   - if bit 6 of register 0x2E is clear, stops there;
 *   - otherwise runs a fixed sequence: bit 2 of register 0x37 cleared, bit 6 of 0x88 set, bit 0 of 0x37 set,
 *     waits until bit 0 of 0x37 reads 1, clears bit 6 of 0x88; if bits 0 and 1 of 0x71 are not both set
 *     afterwards it sets the bits 0x28 of register 0x2E and sets bit 23 of word 0 of the port's 16-byte
 *     copy-protection input record (hdcp_rx_record_hdmi20).
 * The meaning of these registers is not shown in the firmware.
 * Parameter port_arg: the port; only the low byte is used. The return value is not used by the caller.
 */
void input_port_handle_reg71_bits(uint port_arg,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                      undefined4 param_5,undefined4 param_6)

{
  uint value;
  undefined4 uVar2;
  uint port;
  
  port = port_arg & 0xff;
  value = hdmi_port_reg_read8(port,0x71);
  if ((value & 3) == 3) {
    value = hdmi_port_reg_read8(port,0x2e);
    param_2 = 0x71;
    /* Bit 6 of register 0x2E clear: only the write of 3 to register 0x71 is done. */
    if ((value & 0x40) == 0) {
      uVar2 = 0x71;
      return hdmi_port_reg_write8(port,0x71,3,param_4,param_5,param_6);
    }
    hdmi_port_reg_write8(port,0x71,3);
    hdmi_port_reg_update_bits(port,0x37,4,0);
    hdmi_port_reg_update_bits(port,0x88,0x40,1);
    hdmi_port_reg_update_bits(port,0x37,1,1);
    /* Busy wait on bit 0 of register 0x37; there is no time limit. */
    do {
      value = hdmi_port_reg_read8(port,0x37);
    } while ((value & 1) == 0);
    hdmi_port_reg_update_bits(port,0x88,0x40,0);
    value = hdmi_port_reg_read8(port,0x71);
    if ((value & 3) != 3) {
      hdmi_port_reg_update_bits(port,0x2e,0x28,1);
      *(uint *)(port * 0x10 + (int)hdcp_rx_record_hdmi20) = *(uint *)(port * 0x10 + (int)hdcp_rx_record_hdmi20) | 0x800000;
    }
  }
  return CONCAT44(param_2,port_arg) & 0xffffffff000000ff;
}