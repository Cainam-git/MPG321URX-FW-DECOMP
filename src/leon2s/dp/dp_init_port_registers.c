/* dp_init_port_registers  (FUN_a0083fb8)
 *
 * Write the fixed start-up register sequence of a DP receiver.
 *   p1: port
 * Name basis: descriptive - 59 fixed register writes and bit updates after dp_map_port; caller DP port start
 *   routine
 *
 * Matching notes
 * --------------
 * leon2s FUN_a0083fb8 @ 0xa0083fb8 (-mcpu=v8 -Os -g).
 * Source form: Ghidra's signature is kept (five unused further parameters; the last register write passes
 * three of them on); the parameter is reassigned with the mapped receiver number.
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
extern void dp_paged_reg_write8();
extern void dp_paged_reg_update_bits();

/*
 * Write the fixed start-up register sequence of one DP receiver (59 writes through the paged register
 * access).
 *
 *   port  DP port; after the first line the variable holds the receiver block (0 or 1) that dp_map_port returns for it
 *
 * Order of the sequence: clear the control bits 0x433/0x434; clear bits 2, 3, 4 and 5 of 0x550 and clear 0x80
 * and 0x40 of 0x11b, set bit 2 of 0x551 and clear 0x80 of 0x555/0x554, each in the four lane copies
 * (registers 0x550, 0x650, 0x750, 0x850 and 0x11b, 0x19b, 0x21b, 0x29b); write 0xaa to 0x4d1, 0xef to 1 and
 * 0 to 0x404; set bits 0..4 of 0x403 after clearing its bit 7; write registers 0xaf and 0x4a8..0x4af, the
 * last two (0x4ae, 0x4af) with 0xfd. dp_write_port_stop_sequence touches the same registers and sets
 * most of the bits this routine clears (it writes 0xff to 0x4ae and 0x4af and 0x55 to 0x4d1).
 */
void dp_init_port_registers(unsigned char port,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  port = port & 0xff;
  port = dp_map_port(port) & 0xff;
  /* Control bits. */
  dp_paged_reg_update_bits(port,0x433,0x10,0);
  dp_paged_reg_update_bits(port,0x434,1,0);
  dp_paged_reg_update_bits(port,0x433,0x80,0);
  /* The same bit in each of the four lane copies, one group per bit. */
  dp_paged_reg_update_bits(port,0x550,4,0);
  dp_paged_reg_update_bits(port,0x650,4,0);
  dp_paged_reg_update_bits(port,0x750,4,0);
  dp_paged_reg_update_bits(port,0x850,4,0);
  dp_paged_reg_update_bits(port,0x550,8,0);
  dp_paged_reg_update_bits(port,0x650,8,0);
  dp_paged_reg_update_bits(port,0x750,8,0);
  dp_paged_reg_update_bits(port,0x850,8,0);
  dp_paged_reg_update_bits(port,0x11b,0x80,0);
  dp_paged_reg_update_bits(port,0x19b,0x80,0);
  dp_paged_reg_update_bits(port,0x21b,0x80,0);
  dp_paged_reg_update_bits(port,0x29b,0x80,0);
  dp_paged_reg_update_bits(port,0x11b,0x40,0);
  dp_paged_reg_update_bits(port,0x19b,0x40,0);
  dp_paged_reg_update_bits(port,0x21b,0x40,0);
  dp_paged_reg_update_bits(port,0x29b,0x40,0);
  dp_paged_reg_update_bits(port,0x551,4,1);
  dp_paged_reg_update_bits(port,0x651,4,1);
  dp_paged_reg_update_bits(port,0x751,4,1);
  dp_paged_reg_update_bits(port,0x851,4,1);
  dp_paged_reg_update_bits(port,0x555,0x80,0);
  dp_paged_reg_update_bits(port,0x655,0x80,0);
  dp_paged_reg_update_bits(port,0x755,0x80,0);
  dp_paged_reg_update_bits(port,0x855,0x80,0);
  dp_paged_reg_update_bits(port,0x554,0x80,0);
  dp_paged_reg_update_bits(port,0x654,0x80,0);
  dp_paged_reg_update_bits(port,0x754,0x80,0);
  dp_paged_reg_update_bits(port,0x854,0x80,0);
  dp_paged_reg_update_bits(port,0x550,0x10,0);
  dp_paged_reg_update_bits(port,0x650,0x10,0);
  dp_paged_reg_update_bits(port,0x750,0x10,0);
  dp_paged_reg_update_bits(port,0x850,0x10,0);
  dp_paged_reg_update_bits(port,0x550,0x20,0);
  dp_paged_reg_update_bits(port,0x650,0x20,0);
  dp_paged_reg_update_bits(port,0x750,0x20,0);
  dp_paged_reg_update_bits(port,0x850,0x20,0);
  /* Fixed values. */
  dp_paged_reg_write8(port,0x4d1,0xaa);
  dp_paged_reg_write8(port,1,0xef);
  dp_paged_reg_write8(port,0x404,0);
  dp_paged_reg_update_bits(port,0x403,0x80,0);
  dp_paged_reg_update_bits(port,0x403,1,1);
  dp_paged_reg_update_bits(port,0x403,2,1);
  dp_paged_reg_update_bits(port,0x403,4,1);
  dp_paged_reg_update_bits(port,0x403,8,1);
  dp_paged_reg_update_bits(port,0x403,0x10,1);
  dp_paged_reg_write8(port,0xaf,0x94);
  /* Registers 0x4a8..0x4af; 0x4b1 and 0x4b2 are set to 2, then to 0. */
  dp_paged_reg_write8(port,0x4a8,0xff);
  dp_paged_reg_write8(port,0x4a9,0xfd);
  dp_paged_reg_write8(port,0x4ab,2);
  dp_paged_reg_write8(port,0x4ac,2);
  dp_paged_reg_write8(port,0x4b1,2);
  dp_paged_reg_write8(port,0x4b1,0);
  dp_paged_reg_write8(port,0x4b2,2);
  dp_paged_reg_write8(port,0x4b2,0);
  dp_paged_reg_write8(port,0x4ae,0xfd);
  dp_paged_reg_write8(port,0x4af,0xfd,param_4,param_5,param_6);
  return;
}