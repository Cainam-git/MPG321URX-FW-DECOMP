/* input_port_fix_reg2e  (FUN_a00c5c30)
 *
 * Correct register 0x2E of an input when its status requires it.
 * Name basis: descriptive - several register reads; ports 0..1 write registers 0x30 (twice) and 0x2E, ports
 *   2..3 write registers 0x42 and 0x2E
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00c5c30 @ 0xa00c5c30, flags -mcpu=v8 -Os -g.
 * Source form: Ghidra's declarations are kept (the register routines are declared without parameter lists,
 * the routine returns a register routine's result in two paths, parameters 2 to 6 are never read).
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
#define CONCAT11(a, b) ((unsigned short)(((unsigned)(a) << 8) | (unsigned char)(b)))
#define CONCAT12(a, b) (((unsigned)(a) << 16) | (unsigned short)(b))
#define CONCAT13(a, b) (((unsigned)(a) << 24) | ((unsigned)(b) & 0xffffff))
#define CONCAT21(a, b) (((unsigned)(a) << 8) | (unsigned char)(b))
#define CONCAT22(a, b) (((unsigned)(a) << 16) | (unsigned short)(b))
#define CONCAT31(a, b) (((unsigned)(a) << 8) | (unsigned char)(b))
#define SUB41(x, c) ((unsigned char)((unsigned)(x) >> ((c) * 8)))
#define SUB42(x, c) ((unsigned short)((unsigned)(x) >> ((c) * 8)))
#define SUB43(x, c) (((unsigned)(x) >> ((c) * 8)) & 0xffffff)
#define SUB21(x, c) ((unsigned char)((unsigned)(x) >> ((c) * 8)))
#define ZEXT14(x) ((unsigned)(unsigned char)(x))
#define ZEXT24(x) ((unsigned)(unsigned short)(x))
#define ZEXT12(x) ((unsigned short)(unsigned char)(x))
#define SEXT14(x) ((int)(signed char)(x))
#define SEXT24(x) ((int)(short)(x))
#define SEXT12(x) ((short)(signed char)(x))
extern int hdmi_port_reg_write8();
extern void hdmi_port_reg_update_bits();
extern int hdmi_port_reg_read8();

/*
 * Per-pass fix-up of one HDMI input (port 0..3), called by input_update_port_records. It acts only when bit 5
 * of register 0x2E is set, and then only when a second condition holds:
 *   - port 0 or 1: bit 1 of register 0x21F is set, or bit 1 of register 6 is clear. Action: set and then
 *     clear bit 1 of register 0x30, and clear bit 5 of register 0x2E.
 *   - port 2 or 3: bit 1 of register 0x42 is set, or bit 1 of register 6 is clear. Action: clear bit 1 of
 *     register 0x42, then rewrite register 0x2E with bit 3 set and bit 5 cleared.
 * The meaning of these registers is not shown in the firmware.
 * Parameter port_arg: the port; only the low byte is used. The return value is not used by the caller.
 */
void input_port_fix_reg2e(uint port_arg,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6)

{
  unsigned char value;
  undefined4 uVar2;
  uint port;
  
  port = port_arg & 0xff;
  value = hdmi_port_reg_read8(port,0x2e);
  if ((value & 0x20) != 0) {
    if (port < 2) {
      param_2 = 0x2e;
      value = hdmi_port_reg_read8(port,0x21f);
      if (((value & 2) != 0) || (value = hdmi_port_reg_read8(port,6), (value & 2) == 0)) {
        hdmi_port_reg_update_bits(port,0x30,2,1);
        hdmi_port_reg_update_bits(port,0x30,2,0);
        uVar2 = 0x2e;
        return hdmi_port_reg_update_bits(port,0x2e,0x20,0,param_5,param_6);
      }
    }
    else {
      value = hdmi_port_reg_read8(port,0x42);
      param_2 = 0x2e;
      if (((value & 2) != 0) ||
         (value = hdmi_port_reg_read8(port,6), (value & 2) == 0)) {
        hdmi_port_reg_update_bits(port,0x42,2,0);
        value = hdmi_port_reg_read8(port,0x2e);
        uVar2 = 0x2e;
        return hdmi_port_reg_write8(port,0x2e,(value | 8) & 0xdf,param_4,param_5,param_6);
      }
    }
  }
  return CONCAT44(param_2,port_arg);
}