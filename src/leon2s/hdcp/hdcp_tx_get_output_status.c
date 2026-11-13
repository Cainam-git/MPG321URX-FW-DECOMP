/* hdcp_tx_get_output_status  (FUN_a00c9750)
 *
 * Return the protection status bit of an output.
 * Returns: 0 or 1
 * Name basis: descriptive - DisplayPort for output 2, the HDMI getter for outputs 0 and 1
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00c9750 @ 0xa00c9750, flags -mcpu=v8 -Os -g.
 * Source form: the Ghidra typedefs, parameter types and the 'return CONCAT44(...)' are kept; param_2 is not used.
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
extern int hdcp_tx_hdmi_get_status_bit6();
extern int hdcp_tx_dp_get_enable_bit();

/*
 * Return the status bit of video output `output`: for output 2 (DisplayPort) the enable bit
 * (hdcp_tx_dp_get_enable_bit), for outputs 0 and 1 (HDMI) bit 6 of register 0x0F
 * (hdcp_tx_hdmi_get_status_bit6), for any other value 0.
 *
 * Called from hdcp_tx_hdmi_state_refresh_status.
 */
int hdcp_tx_get_output_status(uint output,undefined4 param_2)

{
  uint status;
  uint port;
  
  port = output & 0xff;
  status = 0;
  if (port == 2) {
    status = hdcp_tx_dp_get_enable_bit();
  }
  else if (port < 2) {
    status = hdcp_tx_hdmi_get_status_bit6(port);
  }
  return CONCAT44(param_2,status) & 0xffffffff000000ff;
}
