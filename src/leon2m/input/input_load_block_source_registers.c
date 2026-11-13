/* input_load_block_source_registers  (FUN_a00fd9a0)
 *
 * Load the block registers for an input class from the ROM register table.
 * Name basis: derived - source selection part 2; called from GlobalModeHandler
 *
 * Matching notes
 * --------------
 * leon2m FUN_a00fd9a0 @ 0xa00fd9a0-0xa00fde94 (317 words), flags -mcpu=v8 -O3 -g.
 * Source forms the exact build depends on:
 *  - the switch needs an explicit 'case 0x11: row = 0;' (with 16 case values plus the 0xe1..0xe2 range the
 *    compiler then builds the firmware's case tree: root 0x71, then 0x21 / 0xb1);
 *  - the 0x91 arm and the 0xe1/0xe2 arm of the register 0x40 chain are TWO else-if arms with identical bodies
 *    (the compiler merges them; one '||' arm keeps the body inline);
 *  - a table row is a struct of 16 'unsigned char name : 8' bit-fields. The loads are the same byte loads, but a
 *    bit-field access carries the row struct's alias set instead of the char alias set, so the scheduler no
 *    longer makes the row loads depend on the volatile register stores. With plain bytes the 0xCC store and the
 *    'signal_code == 0x13' test tie and the store goes first; with the bit-field rows the test goes first as in
 *    the firmware (0xa00fda90..0xa00fdb00). No aids.
 */

/* Registers at 0xCF020xxx, the block that also holds the level and offset registers of the analogue input stage
   (0xCF020000..0xCF020014). Written here only for signal codes 0x11, 0x12, 0x13 and 0x21. */
#define ANALOG_REG_88  (*(volatile unsigned int *)(0xcf020088))
#define ANALOG_REG_CC  (*(volatile unsigned int *)(0xcf0200cc))
#define ANALOG_REG_D0  (*(volatile unsigned int *)(0xcf0200d0))
#define ANALOG_REG_114 (*(volatile unsigned int *)(0xcf020114))     /* low 3 bits read back: 5 selects 0xA0 for 0x88 */
#define ANALOG_REG_134 (*(volatile unsigned int *)(0xcf020134))
#define ANALOG_REG_138 (*(volatile unsigned int *)(0xcf020138))
#define ANALOG_REG_13C (*(volatile unsigned int *)(0xcf02013c))
#define ANALOG_REG_140 (*(volatile unsigned int *)(0xcf020140))
#define ANALOG_REG_144 (*(volatile unsigned int *)(0xcf020144))

#define SOURCE_TABLE_ROWS 12

/*
 * One row of input_block_source_reg_table (16 bytes): the register values for one group of signal codes.
 * Each field is named after the register it is written to; bytes 12, 14 and 15 are not used here.
 */
struct source_reg_row {
  unsigned char measure_reg_0 : 8;      /* measure block register 0 */
  unsigned char analog_reg_114 : 8;
  unsigned char analog_reg_cc : 8;      /* bit 0 is set after the write */
  unsigned char analog_reg_d0 : 8;
  unsigned char capture_reg_0 : 8;
  unsigned char capture_reg_1 : 8;
  unsigned char capture_reg_3 : 8;      /* combined with the register's own bit 0 */
  unsigned char capture_reg_5 : 8;
  unsigned char capture_reg_6 : 8;
  unsigned char capture_reg_16 : 8;
  unsigned char capture_reg_54 : 8;
  unsigned char picture_reg_32 : 8;     /* picture block register 0x32 */
  unsigned char byte_12 : 8;
  unsigned char capture_reg_56 : 8;
  unsigned char byte_14 : 8;
  unsigned char byte_15 : 8;
};
extern const unsigned char input_block_source_reg_table[];
extern void *memcpy(void *dst, const void *src, int n);
extern void input_measure_write8(unsigned char block, unsigned char reg, unsigned char value);
extern void input_capture_write8(unsigned char block, unsigned char reg, unsigned char value);
extern void input_capture_update_bits(unsigned char block, unsigned char reg, unsigned char mask, unsigned char set);
extern unsigned char input_capture_read8(unsigned char block, unsigned char reg);
extern void pq_block_write8(unsigned char block, unsigned char reg, unsigned char value);
extern void input_block_set_sync_thresholds(unsigned char block, unsigned char high, unsigned char low);
extern void input_block_set_reg40_field(unsigned char block, unsigned char value);
extern void input_block_set_reg40_bit0(unsigned char block, unsigned char on);
extern void input_block_enable_pre_pattern(unsigned char block, unsigned char value, unsigned char enable);
extern void timer_sleep_ticks(int ms);

/*
 * Load the registers of an input block for one signal code from the ROM table input_block_source_reg_table.
 * This is the second half of switching a block to a source: GlobalModeHandler calls
 * input_select_block_source and then this routine, with the same block and signal code.
 *
 *   block        input block
 *   signal_code  the kind of source, as in input_select_block_source
 *
 * Phases:
 *   1. copy the table (12 rows of 16 bytes) to the stack and pick the row of the signal code
 *      (0x21 also pulses bit 6 of capture register 1 for 2 ticks);
 *   2. measure register 0 from the row; for codes 0x11..0x13 and 0x21 also the registers at 0xCF020xxx;
 *   3. the capture block registers 0, 1, 3, 5, 6, 0x16, 0x54, 0x56 and picture register 0x32 from the row,
 *      with extra bits for blocks 6 and 7;
 *   4. the settings that depend on the code itself: the sync thresholds, register 0x40 of the measure block and
 *      the built-in test pattern (on only for code 0xE8).
 */
void input_load_block_source_registers(unsigned char block, unsigned char signal_code)
{
  struct source_reg_row table[SOURCE_TABLE_ROWS];
  unsigned char row;

  /* 1. The row of the table for this signal code; codes not listed use row 0. */
  memcpy(table, input_block_source_reg_table, 0xc0);
  row = 0;
  switch (signal_code) {
  case 0x11: row = 0; break;
  case 0x12: row = 1; break;
  case 0x13: row = 2; break;
  case 0x21:
    input_capture_update_bits(block, 1, 0x40, 1);
    timer_sleep_ticks(2);
    input_capture_update_bits(block, 1, 0x40, 0);
    row = 3;
    break;
  case 0x31: case 0x41: row = 4; break;
  case 0x51: case 0x61: row = 5; break;
  case 0x71: case 0x81: row = 6; break;
  case 0xc1: row = 7; break;
  case 0x91: case 0xa1: row = 8; break;
  case 0xb1: row = 9; break;
  case 0xe1: case 0xe2: row = 10; break;
  case 0xe8: row = 11; break;
  }

  /* 2. Measure register 0, and for codes 0x11..0x13 and 0x21 the registers at 0xCF020xxx. */
  input_measure_write8(block, 0, table[row].measure_reg_0);
  if ((unsigned char)(signal_code - 0x11) < 3 || signal_code == 0x21) {
    ANALOG_REG_114 = table[row].analog_reg_114;
    if ((ANALOG_REG_114 & 7) == 5)
      ANALOG_REG_88 = 0xa0;
    else
      ANALOG_REG_88 = 0;
    ANALOG_REG_CC = table[row].analog_reg_cc;
    ANALOG_REG_CC |= 1;
    ANALOG_REG_D0 = table[row].analog_reg_d0;
    if (signal_code == 0x13 || signal_code == 0x21) {
      ANALOG_REG_134 = 0xd0;
      ANALOG_REG_138 = 2;
      ANALOG_REG_13C = 0x80;
      ANALOG_REG_140 = 0x80;
      ANALOG_REG_144 = 0x40;
    } else {
      ANALOG_REG_134 = 0x50;
      ANALOG_REG_138 = 0x22;
      ANALOG_REG_13C = 0;
    }
  }

  /* 3. The capture block registers. Blocks 6 and 7 also get bit 7 of register 0 (set for rows 0..3, the
     codes 0x11..0x21) and bit 0 of register 5. */
  input_capture_write8(block, 0, table[row].capture_reg_0);
  if ((unsigned char)(block - 6) <= 1) {
    if (row <= 3)
      input_capture_update_bits(block, 0, 0x80, 1);
    else
      input_capture_update_bits(block, 0, 0x80, 0);
  }
  input_capture_write8(block, 1, table[row].capture_reg_1);
  input_capture_write8(block, 3, (input_capture_read8(block, 3) & 1) | table[row].capture_reg_3);
  input_capture_write8(block, 5, table[row].capture_reg_5);
  if ((unsigned char)(block - 6) <= 1)
    input_capture_update_bits(block, 5, 1, 1);
  input_capture_write8(block, 6, table[row].capture_reg_6);
  input_capture_write8(block, 0x16, table[row].capture_reg_16);
  input_capture_write8(block, 0x54, table[row].capture_reg_54);
  pq_block_write8(block, 0x32, table[row].picture_reg_32);
  input_capture_write8(block, 0x56, table[row].capture_reg_56);

  /* 4. Settings by code. The sync threshold low value is 8 for 0x71/0x81, else 4. Register 0x40 of the
     measure block ends as 7 for 0x71, 0x81 and 0xb1, 5 for 0x91, 0xe1 and 0xe2, and 0 for the others
     (input_block_set_reg40_field writes value << 1 over bits 1..7, input_block_set_reg40_bit0 bit 0). */
  if (signal_code == 0x71 || signal_code == 0x81)
    input_block_set_sync_thresholds(block, 1, 8);
  else
    input_block_set_sync_thresholds(block, 1, 4);
  if (signal_code == 0x31 || signal_code == 0x41 || signal_code == 0x51 || signal_code == 0x61) {
    input_block_set_reg40_field(block, 0);
    input_block_set_reg40_bit0(block, 0);
  } else if (signal_code == 0x71 || signal_code == 0x81) {
    input_block_set_reg40_field(block, 3);
    input_block_set_reg40_bit0(block, 1);
  } else if (signal_code == 0x91) {
    input_block_set_reg40_field(block, 2);
    input_block_set_reg40_bit0(block, 1);
  } else if ((unsigned char)(signal_code + 0x1f) <= 1) {        /* 0xe1 or 0xe2 */
    input_block_set_reg40_field(block, 2);
    input_block_set_reg40_bit0(block, 1);
  } else if (signal_code == 0xb1) {
    input_block_set_reg40_field(block, 3);
    input_block_set_reg40_bit0(block, 1);
  } else {
    input_block_set_reg40_field(block, 0);
    input_block_set_reg40_bit0(block, 0);
  }
  /* The built-in test pattern is on only for code 0xE8, the code input_block_get_signal_code reports while
     the pattern is on. */
  input_block_enable_pre_pattern(block, 0x15, signal_code == 0xe8);
}
