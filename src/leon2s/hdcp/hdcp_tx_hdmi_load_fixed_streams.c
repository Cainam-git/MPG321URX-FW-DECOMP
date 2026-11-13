/* hdcp_tx_hdmi_load_fixed_streams  (FUN_a00c0b48)
 *
 * Write the fixed byte stream to both HDMI outputs and adjust one register on each.
 * Name basis: descriptive - hdcp_tx_hdmi_write_fixed_stream for outputs 0 and 1
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00c0b48 @ 0xa00c0b48, flags -mcpu=v8 -Os -g.
 * Source form: the Ghidra typedefs and the six-parameter signature are kept. The last register write is passed
 * the two extra arguments param_5 and param_6 (the register routine is declared without a prototype); the build
 * depends on that.
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
extern int hdcp_tx_hdmi_write_fixed_stream();
extern int hdmi_tx_reg_read8();
extern void hdmi_tx_reg_write8();

/*
 * Load a key set into both HDMI outputs: write the fixed stream (key-selection value and key block, see
 * hdcp_tx_hdmi_write_fixed_stream) to output 0 and output 1, then for each output clear bit 5 of register
 * 0xFA and set it again.
 *
 * Called from InitHDCP for the second key set.
 *
 *   ksv        5-byte key-selection value
 *   key_block  key block (the first 0x118 bytes are used)
 *   param_3, param_4  not used
 *   param_5, param_6  only handed on to the last register write
 */
void hdcp_tx_hdmi_load_fixed_streams(undefined4 ksv,undefined4 key_block,undefined4 param_3,undefined4 param_4, int param_5,undefined4 param_6)

{
  unsigned char reg_value;
  
  hdcp_tx_hdmi_write_fixed_stream(0,ksv,key_block);
  hdcp_tx_hdmi_write_fixed_stream(1,ksv,key_block);
  reg_value = hdmi_tx_reg_read8(0,0,0xfa);
  hdmi_tx_reg_write8(0,0,0xfa,reg_value & 0xdf);
  reg_value = hdmi_tx_reg_read8(0,0,0xfa);
  hdmi_tx_reg_write8(0,0,0xfa,reg_value & 0xff | 0x20);
  reg_value = hdmi_tx_reg_read8(1,0,0xfa);
  hdmi_tx_reg_write8(1,0,0xfa,reg_value & 0xdf);
  reg_value = hdmi_tx_reg_read8(1,0,0xfa);
  hdmi_tx_reg_write8(1,0,0xfa,reg_value & 0xff | 0x20,param_5,param_6);
  return;
}
