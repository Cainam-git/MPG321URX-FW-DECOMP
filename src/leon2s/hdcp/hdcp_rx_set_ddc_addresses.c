/* hdcp_rx_set_ddc_addresses  (FUN_a00c18fc)
 *
 * Write the fixed device address values of the inputs' protection ports.
 * Name basis: descriptive - values 0x10 and 0x74 to registers 0x41 / 0x3F of block 2
 *
 * Matching notes
 * --------------
 * FUN_a00c18fc (leon2s 0xa00c18fc-0xa00c19b8), flags -mcpu=v8 -Os -g.
 * Source form: the Ghidra typedefs are kept; the register routines are declared without a prototype.
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
extern void hdmi_reg_write8();
extern void hdmi_rx21_reg_write8();
extern void hdmi_rx21_reg_update_bits();

/*
 * Write fixed values into the registers of both receivers of the HDMI 2.0 and the HDMI 2.1 inputs (port 2 of
 * the register helpers means both receivers): 0x10 to register 0x41 and 0x74 to register 0x3F of the HDMI 2.0
 * receivers, 0x74 to register 0x3F and bit 0 of register 0x43 on the HDMI 2.1 receivers, then 4 to 0x301 and
 * 0x0D to 0x30E of the HDMI 2.0 receivers. The last five writes on the HDMI 2.1 receivers go through the index
 * registers: select 0x41, index 1, value 0x0D, finally 0x20 to register 0xA4.
 *
 * Called from InitHDCP, after the input records are reset.
 */
void hdcp_rx_set_ddc_addresses(void)

{
  
  hdmi_reg_write8(2,0x41,0x10);
  hdmi_reg_write8(2,0x3f,0x74);
  hdmi_rx21_reg_write8(2,0x3f,0x74);
  hdmi_rx21_reg_update_bits(2,0x43,1,1);
  hdmi_reg_write8(2,0x301,4);
  hdmi_reg_write8(2,0x30e,0xd);
  hdmi_rx21_reg_write8(2,0xa6,0x41);
  hdmi_rx21_reg_write8(2,0xa4,0);
  hdmi_rx21_reg_write8(2,0xa5,1);
  hdmi_rx21_reg_write8(2,0xa7,0xd);
  hdmi_rx21_reg_write8(2,0xa4,0x20);
  return;
}
