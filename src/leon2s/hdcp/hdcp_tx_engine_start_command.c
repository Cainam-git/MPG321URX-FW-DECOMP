/* hdcp_tx_engine_start_command  (FUN_a00c87e8)
 *
 * Give the protection engine a command code and a 16-bit length.
 * Name basis: derived - three register writes: code, low byte, high byte
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00c87e8 @ 0xa00c87e8, flags -mcpu=v8 -Os -g.
 * Source form: the Ghidra typedefs and parameter types are kept. The last register write is passed the extra
 * arguments param_4 to param_6 (hdcp_tx_reg_write is declared without a prototype); the build depends on that.
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
extern void hdcp_tx_reg_write();

/*
 * Start a command of the protection block of output `port`: the command code goes to register 0, the low
 * byte of length to register 3 and its high byte to register 2 (all through hdcp_tx_reg_write). Callers pass
 * lengths like 0x8000, 0x4005 or 0x4015 and the code 0 with length 0 to end a sequence.
 *
 *   param_4 to param_6  only handed on to the last register write
 */
void hdcp_tx_engine_start_command(undefined1 port,undefined1 code, unsigned short length,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  hdcp_tx_reg_write(port,0,code);
  hdcp_tx_reg_write(port,3,length & 0xff);
  hdcp_tx_reg_write(port,2,(length & 0xffff) >> 8,param_4,param_5,param_6);
  return;
}
