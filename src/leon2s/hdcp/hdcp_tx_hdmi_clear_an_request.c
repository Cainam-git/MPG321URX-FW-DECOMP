/* hdcp_tx_hdmi_clear_an_request  (FUN_a00c85b8)
 *
 * Clear bit 3 of register 0x0F of an HDMI output.
 * Name basis: descriptive - the bit hdcp_tx_hdmi_generate_an sets
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00c85b8 @ 0xa00c85b8, flags -mcpu=v8 -Os -g.
 * Source form: the Ghidra typedefs and parameter type are kept; the register routines are declared without a
 * prototype.
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
extern int hdmi_tx_reg_read8();
extern int hdmi_tx_reg_write8();

/*
 * Clear bit 3 of register 0x0F of HDMI output `port`. Bit 3 is the one hdcp_tx_hdmi_generate_an sets.
 *
 * Called from hdcp_tx_hdmi_state_wait_clear_an_request.
 */
void hdcp_tx_hdmi_clear_an_request(uint port)

{
  uint value;
  
  port = port & 0xff;
  value = hdmi_tx_reg_read8(port,0,0xf);
  hdmi_tx_reg_write8(port,0,0xf,value & 0xf7);
  return;
}
