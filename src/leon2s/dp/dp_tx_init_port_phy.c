/* dp_tx_init_port_phy  (FUN_a0085dcc)
 *
 * Set up the PHY power and drive registers of a DP output.
 *   p1: output
 * Name basis: descriptive - 0xCF013280.. power bits and five fixed PHY writes; caller dp_tx_init_ports
 *
 * Matching notes
 * --------------
 * leon2s FUN_a0085dcc @ 0xa0085dcc (-mcpu=v8 -Os -g).
 * Source form: Ghidra's signature and its odd 'return CONCAT44(...)' are kept (a void routine in effect); the
 * five transmitter register writes are separate calls with the mapped output held in an unsigned int.
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
extern unsigned char DAT_a8078a0d;
#define _DAT_cf013280 (*(volatile unsigned int *)0xcf013280)
#define _DAT_cf013284 (*(volatile unsigned int *)0xcf013284)
#define _DAT_cf013288 (*(volatile unsigned int *)0xcf013288)
#define _DAT_cf01328c (*(volatile unsigned int *)0xcf01328c)
extern void dp_tx_reg_write8(uint port, unsigned short param_2,uint param_3);
extern void dp_tx_reg_update_bits();
extern int dp_tx_phy_power_up_output();
extern int dp_tx_phy_apply_output_options();

/*
 * Set up the PHY of one DP output: switch on the shared PHY power bits, write the three shared drive
 * registers, apply the stored option bytes, power the output up and write its fixed PHY registers.
 *
 *   port  DP output 0..4 (the second parameter and the returned value are not used by the callers)
 *
 * Called from dp_tx_init_ports.
 *
 * Order: set bits 0..4 of 0xcf013280, write 0x86, 0x95 and 0x55 to 0xcf013284, 0xcf013288 and 0xcf01328c
 * (these registers are shared by all outputs, so they are written again for every output); then
 * dp_tx_phy_apply_output_options, dp_tx_phy_power_up_output(port), and the output's transmitter registers
 * 0x32, 0x31, 0x35 (twice, 0x13 then 0x91) and 0x33. Output 0 alone also sets the masked bits (0x06) of
 * register 0x21 and writes 0x0b to register 0x31 again. The byte at 0xa8078a0d is cleared at the end.
 */
void dp_tx_init_port_phy(uint port,undefined4 param_2)

{
  uint output;
  
  _DAT_cf013280 = _DAT_cf013280 | 0x1f;
  _DAT_cf013284 = 0x86;
  _DAT_cf013288 = 0x95;
  _DAT_cf01328c = 0x55;
  output = port & 0xff;
  dp_tx_phy_apply_output_options();
  dp_tx_phy_power_up_output(output);
  dp_tx_reg_write8(output,0x32,0);
  dp_tx_reg_write8(output,0x31,0xd1);
  dp_tx_reg_write8(output,0x35,0x13);
  dp_tx_reg_write8(output,0x35,0x91);
  dp_tx_reg_write8(output,0x33,8);
  if (output == 0) {
    dp_tx_reg_update_bits(0,0x21,6,1);
    dp_tx_reg_write8(0,0x31,0xb);
  }
  DAT_a8078a0d = 0;
  return CONCAT44(param_2,port) & 0xffffffff000000ff;
}