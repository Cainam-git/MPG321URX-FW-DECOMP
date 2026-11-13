/* dp_write_phy_table  (FUN_a00848cc)
 *
 * Write the two fixed PHY register tables of a DP receiver with a reset pulse between.
 *   p1: port
 * Name basis: descriptive - 24 register/value pairs twice, around two pulses; caller DP port start routine
 *
 * Matching notes
 * --------------
 * leon2s FUN_a00848cc @ 0xa00848cc (-mcpu=v8 -Os -g).
 * Source form: Ghidra's signature is kept (five unused further parameters; the last write passes three of
 * them on). The port is port & 0xff; the mapped receiver block is held in an unsigned int.
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
extern int dp_map_port();
extern void dp_reg_write8();
extern void dp_reg_update_bits();
extern void dp_paged_reg_write8();
extern int timer_delay_long_units();

/*
 * Load the two PHY value tables of one DP receiver, with two reset pulses between them.
 *
 *   port  DP port 0..4; the paged registers use the receiver block (0 or 1) that dp_map_port returns for it,
 *         the plain registers (0x21d, 0xc0) use the port number
 *
 * Order: write 0x84 to register 0x21d; load table 1; pulse the reset twice; load table 2.
 * Each table holds six registers, written in the four lane copies (stride 0x80 for the first four, 0x100 for
 * the last two), 24 writes each:
 *
 *     registers (lane 0)   table 1   table 2
 *     0x10c                0xc0      0x00
 *     0x10b                0xc0      0x00
 *     0x126                0x70      0x30
 *     0x114                0x5b      0x1b
 *     0x558                0xa0      0x20
 *     0x559                0x10      0x10
 *
 * A reset pulse is: clear bit 7 of register 0xc0, write 0x80 to paged register 0x403, set bit 7 of 0xc0, and
 * wait 5 units of timer_delay_long_units.
 */
void dp_write_phy_table(uint port,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  uint block;
  
  port = port & 0xff;
  block = dp_map_port(port);
  dp_reg_write8(port,0x21d,0x84);
  block = block & 0xff;
  /* Table 1: six registers, each in four lane copies. */
  dp_paged_reg_write8(block,0x10c,0xc0);
  dp_paged_reg_write8(block,0x18c,0xc0);
  dp_paged_reg_write8(block,0x20c,0xc0);
  dp_paged_reg_write8(block,0x28c,0xc0);
  dp_paged_reg_write8(block,0x10b,0xc0);
  dp_paged_reg_write8(block,0x18b,0xc0);
  dp_paged_reg_write8(block,0x20b,0xc0);
  dp_paged_reg_write8(block,0x28b,0xc0);
  dp_paged_reg_write8(block,0x126,0x70);
  dp_paged_reg_write8(block,0x1a6,0x70);
  dp_paged_reg_write8(block,0x226,0x70);
  dp_paged_reg_write8(block,0x2a6,0x70);
  dp_paged_reg_write8(block,0x114,0x5b);
  dp_paged_reg_write8(block,0x194,0x5b);
  dp_paged_reg_write8(block,0x214,0x5b);
  dp_paged_reg_write8(block,0x294,0x5b);
  dp_paged_reg_write8(block,0x558,0xa0);
  dp_paged_reg_write8(block,0x658,0xa0);
  dp_paged_reg_write8(block,0x758,0xa0);
  dp_paged_reg_write8(block,0x858,0xa0);
  dp_paged_reg_write8(block,0x559,0x10);
  dp_paged_reg_write8(block,0x659,0x10);
  dp_paged_reg_write8(block,0x759,0x10);
  dp_paged_reg_write8(block,0x859,0x10);
  /* Reset pulse, twice. */
  dp_reg_update_bits(port,0xc0,0x80,0);
  dp_paged_reg_write8(block,0x403,0x80);
  dp_reg_update_bits(port,0xc0,0x80,1);
  timer_delay_long_units(5);
  dp_reg_update_bits(port,0xc0,0x80,0);
  dp_paged_reg_write8(block,0x403,0x80);
  dp_reg_update_bits(port,0xc0,0x80,1);
  timer_delay_long_units(5);
  /* Table 2: the same registers. */
  dp_paged_reg_write8(block,0x10c,0);
  dp_paged_reg_write8(block,0x18c,0);
  dp_paged_reg_write8(block,0x20c,0);
  dp_paged_reg_write8(block,0x28c,0);
  dp_paged_reg_write8(block,0x10b,0);
  dp_paged_reg_write8(block,0x18b,0);
  dp_paged_reg_write8(block,0x20b,0);
  dp_paged_reg_write8(block,0x28b,0);
  dp_paged_reg_write8(block,0x126,0x30);
  dp_paged_reg_write8(block,0x1a6,0x30);
  dp_paged_reg_write8(block,0x226,0x30);
  dp_paged_reg_write8(block,0x2a6,0x30);
  dp_paged_reg_write8(block,0x114,0x1b);
  dp_paged_reg_write8(block,0x194,0x1b);
  dp_paged_reg_write8(block,0x214,0x1b);
  dp_paged_reg_write8(block,0x294,0x1b);
  dp_paged_reg_write8(block,0x558,0x20);
  dp_paged_reg_write8(block,0x658,0x20);
  dp_paged_reg_write8(block,0x758,0x20);
  dp_paged_reg_write8(block,0x858,0x20);
  dp_paged_reg_write8(block,0x559,0x10);
  dp_paged_reg_write8(block,0x659,0x10);
  dp_paged_reg_write8(block,0x759,0x10);
  dp_paged_reg_write8(block,0x859,0x10,param_4,param_5,param_6);
  return;
}