/* dp_write_port_stop_sequence  (FUN_a008442c)
 *
 * Write the fixed register sequence used when a DP receiver is stopped.
 *   port
 * Name basis: descriptive - fixed register writes; caller DP port stop routine
 *
 * Matching notes
 * --------------
 * leon2s FUN_a008442c @ 0xa008442c (-mcpu=v8 -Os -g).
 * Source form: the result of the first call replaces the parameter (port = dp_map_port(port & 0xff) & 0xff).
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
extern unsigned char dp_map_port();
extern void dp_paged_reg_write8();
extern void dp_paged_reg_update_bits();

/*
 * Write the fixed register sequence that puts one DP receiver into its stopped state (59 paged register
 * writes). It is the counterpart of dp_init_port_registers.
 *
 *   port  DP port; after the first line the variable holds the receiver block (0 or 1) that dp_map_port
 *         returns for it
 *
 * Order: write 0xff to 0x4ae and 0x4af first (the start-up routine writes 0xfd to them last); set bits in the
 * control registers 0x433/0x434; set or clear single bits of 0x550, 0x11b, 0x551, 0x555, 0x554 in the four lane
 * copies (registers 0x550, 0x650, 0x750, 0x850 and 0x11b, 0x19b, 0x21b, 0x29b); write 0x55 to 0x4d1 (the start-up
 * routine writes 0xaa); then bits of register 1, 0x404 and 0x403, ending with bit 7 of 0x403 set.
 */
void dp_write_port_stop_sequence(unsigned char port)

{
  
  port = dp_map_port(port & 0xff) & 0xff;
  dp_paged_reg_write8(port,0x4ae,0xff);
  dp_paged_reg_write8(port,0x4af,0xff);
  /* Control bits. */
  dp_paged_reg_update_bits(port,0x433,0x10,1);
  dp_paged_reg_update_bits(port,0x434,1,1);
  dp_paged_reg_update_bits(port,0x433,0x80,1);
  /* One group per bit, the same bit in each of the four lane copies. */
  dp_paged_reg_update_bits(port,0x550,4,1);
  dp_paged_reg_update_bits(port,0x650,4,1);
  dp_paged_reg_update_bits(port,0x750,4,1);
  dp_paged_reg_update_bits(port,0x850,4,1);
  dp_paged_reg_update_bits(port,0x550,8,0);
  dp_paged_reg_update_bits(port,0x650,8,0);
  dp_paged_reg_update_bits(port,0x750,8,0);
  dp_paged_reg_update_bits(port,0x850,8,0);
  dp_paged_reg_update_bits(port,0x11b,0x80,1);
  dp_paged_reg_update_bits(port,0x19b,0x80,1);
  dp_paged_reg_update_bits(port,0x21b,0x80,1);
  dp_paged_reg_update_bits(port,0x29b,0x80,1);
  dp_paged_reg_update_bits(port,0x11b,0x40,0);
  dp_paged_reg_update_bits(port,0x19b,0x40,0);
  dp_paged_reg_update_bits(port,0x21b,0x40,0);
  dp_paged_reg_update_bits(port,0x29b,0x40,0);
  dp_paged_reg_update_bits(port,0x551,4,0);
  dp_paged_reg_update_bits(port,0x651,4,0);
  dp_paged_reg_update_bits(port,0x751,4,0);
  dp_paged_reg_update_bits(port,0x851,4,0);
  dp_paged_reg_update_bits(port,0x555,0x80,1);
  dp_paged_reg_update_bits(port,0x655,0x80,1);
  dp_paged_reg_update_bits(port,0x755,0x80,1);
  dp_paged_reg_update_bits(port,0x855,0x80,1);
  dp_paged_reg_update_bits(port,0x554,0x80,0);
  dp_paged_reg_update_bits(port,0x654,0x80,0);
  dp_paged_reg_update_bits(port,0x754,0x80,0);
  dp_paged_reg_update_bits(port,0x854,0x80,0);
  dp_paged_reg_update_bits(port,0x550,0x10,1);
  dp_paged_reg_update_bits(port,0x650,0x10,1);
  dp_paged_reg_update_bits(port,0x750,0x10,1);
  dp_paged_reg_update_bits(port,0x850,0x10,1);
  dp_paged_reg_update_bits(port,0x550,0x20,0);
  dp_paged_reg_update_bits(port,0x650,0x20,0);
  dp_paged_reg_update_bits(port,0x750,0x20,0);
  dp_paged_reg_update_bits(port,0x850,0x20,0);
  dp_paged_reg_write8(port,0x4d1,0x55);
  /* Register 1 bits 4 (set), 3..0 (cleared), then 0x404 and 0x403. */
  dp_paged_reg_update_bits(port,1,0x10,1);
  dp_paged_reg_update_bits(port,1,8,0);
  dp_paged_reg_update_bits(port,1,4,0);
  dp_paged_reg_update_bits(port,1,2,0);
  dp_paged_reg_update_bits(port,1,1,0);
  dp_paged_reg_update_bits(port,0x404,1,0);
  dp_paged_reg_update_bits(port,0x404,2,0);
  dp_paged_reg_update_bits(port,0x404,4,0);
  dp_paged_reg_update_bits(port,0x404,8,0);
  dp_paged_reg_update_bits(port,0x404,0x10,0);
  dp_paged_reg_update_bits(port,0x404,0x20,1);
  dp_paged_reg_update_bits(port,0x403,1,0);
  dp_paged_reg_update_bits(port,0x403,2,0);
  dp_paged_reg_update_bits(port,0x403,4,0);
  dp_paged_reg_update_bits(port,0x403,8,0);
  dp_paged_reg_update_bits(port,0x403,0x10,0);
  dp_paged_reg_update_bits(port,0x403,0x80,1);
  return;
}