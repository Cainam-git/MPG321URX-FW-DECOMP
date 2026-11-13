/* hdcp_tx_engine_write_bank3_block  (FUN_a00c9c98)
 *
 * Write 0 to engine register 0, then write a data block of size/16 words to bank 3.
 * Name basis: descriptive - mechanics only
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00c9c98 @ 0xa00c9c98, flags -mcpu=v8 -Os -g.
 * Source form: the Ghidra typedefs and parameter types are kept; param_6 is passed on to the block write
 * (the routines are declared without a prototype).
 */
typedef unsigned char undefined, undefined1, byte, uchar, bool;
typedef unsigned short undefined2, ushort, word;
typedef unsigned int undefined4, uint, ulong, dword, undefined3;
typedef unsigned long long undefined8, ulonglong;
typedef long long longlong;
typedef signed char sbyte;
typedef int code();
extern int hdcp_tx_engine_write_block();
extern int hdcp_tx_engine_reg_write8();

/*
 * Write 0 to register 0 of copy-protection engine unit `port`, then hdcp_tx_engine_write_block(port, block, 3,
 * 0, size): bank 3, with data. The callers (hdcp_tx_hdmi_state_compare_results, hdcp_tx_dp_state_compare_results) pass size 0x400.
 *
 *   param_4, param_5  not used
 *   param_6           handed on to the block write
 */
void hdcp_tx_engine_write_bank3_block(undefined1 port,undefined4 block,undefined2 size,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  hdcp_tx_engine_reg_write8(port,0,0);
  hdcp_tx_engine_write_block(port,block,3,0,size,param_6);
  return;
}
