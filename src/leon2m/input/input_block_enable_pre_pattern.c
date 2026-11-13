/* input_block_enable_pre_pattern  (FUN_a00f913c)
 *
 * Switch the built-in test pattern of an input block on or off.
 * Name basis: proven - prints 'Enable PrePattern'
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00f913c @ 0xa00f913c (-mcpu=v8 -O3 -g)
 * Source form: the capture-block write routines are declared with a prototype of three arguments; the register
 * 0xCF011400 is read-modify-written through a volatile int pointer.
 */
extern int dbg_printf();
extern void input_capture_write8(unsigned char blk, unsigned char reg, unsigned char val);
extern void input_capture_update_bits(unsigned char blk, unsigned char reg, unsigned char mask, unsigned char set);
extern void input_capture_write16(unsigned char blk, unsigned char reg, unsigned short val);

#define reg_input_block_pre_pattern (*(volatile unsigned int *)0xcf011400)

#define CAPTURE_REG_PATTERN_ENABLE 0xa4     /* 1 while the pattern is on, 0 when off */
#define CAPTURE_REG_8C             0x8c     /* bit 7 set = pattern on: input_block_get_signal_code then returns 0xE8 */
#define CAPTURE_REG_55             0x55
#define PRE_PATTERN_ENABLE_BIT     0x10     /* bit 4 of register 0xCF011400 */

/*
 * Switch the built-in test pattern of an input block on or off.
 *
 *   block   input block (capture block registers)
 *   value   low bits written to register 0x8c when the pattern is switched on (bit 7 is added to it)
 *   enable  non-zero: switch on, 0: switch off
 *
 * Called by input_load_block_source_registers as the last step of loading a block's registers, with value 0x15
 * and enable set when the signal code of the block is 0xE8.
 *
 * On: prints "Enable PrePattern", writes a fixed list of values to registers 0xa4, 0x8d to 0x9e, 0xa0 to 0xa2 and
 * 0xac of the block (the meaning of the single values is not shown by the code), sets bit 4 of register 0x94,
 * sets register 0x8c to value | 0x80, writes registers 0x57 and 0x59, sets bit 4 of register 0xCF011400 and
 * finally writes 0xf0 to register 0x55.
 * Off: clears register 0xa4 and bit 4 of register 0x94, clears bit 4 of register 0xCF011400, writes 0xc0 to
 * register 0x55 and clears register 0x8c.
 */
void input_block_enable_pre_pattern(unsigned char block, unsigned char value, unsigned char enable)
{
  if (enable != 0) {
    dbg_printf("\033[1;35mEnable PrePattern\r\n\033[m");
    input_capture_write8(block, CAPTURE_REG_PATTERN_ENABLE, 1);
    input_capture_write16(block, 0x8d, 0xdc);
    input_capture_write16(block, 0x8f, 0x500);
    input_capture_write8(block, 0x91, 0x14);
    input_capture_write8(block, 0x93, 0);
    input_capture_write8(block, 0x9e, 0xd0);
    input_capture_write8(block, 0xac, 2);
    input_capture_write16(block, 0x95, 0x7bc);
    input_capture_write16(block, 0x97, 0x2ee);
    input_capture_write16(block, 0xa0, 0x2d0);
    input_capture_write16(block, 0xa2, 0x500);
    input_capture_update_bits(block, 0x94, 0x10, 1);
    input_capture_write8(block, CAPTURE_REG_8C, value | 0x80);
    input_capture_write16(block, 0x57, 0x13f);
    input_capture_write16(block, 0x59, 0x2ed);
    reg_input_block_pre_pattern = reg_input_block_pre_pattern | PRE_PATTERN_ENABLE_BIT;
    input_capture_write8(block, CAPTURE_REG_55, 0xf0);
    return;
  }
  input_capture_write8(block, CAPTURE_REG_PATTERN_ENABLE, 0);
  input_capture_update_bits(block, 0x94, 0x10, 0);
  reg_input_block_pre_pattern = reg_input_block_pre_pattern & 0xffffffef;
  input_capture_write8(block, CAPTURE_REG_55, 0xc0);
  input_capture_write8(block, CAPTURE_REG_8C, 0);
}
