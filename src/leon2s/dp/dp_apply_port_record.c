/* dp_apply_port_record  (FUN_a0084d04)
 *
 * Write the fixed register set-up of a DP receiver block, then its stored settings record if valid.
 *   p1: port
 * Note: The stored record (first byte 0xA0) replaces only registers 0x30, 0x31, 0x32, 0x76 and 0x7E.
 * Name basis: descriptive - fixed register writes of the receiver block; stored records
 *   dp_stored_settings_port0 / _port1; caller DP port start routine when forced
 *
 * Matching notes
 * --------------
 * leon2s FUN_a0084d04 @ 0xa0084d04, flags -mcpu=v8 -Os -g (section default).
 * Source forms the exact build depends on:
 *  - the routine is declared with six parameters and the last register write passes the 4th..6th on as
 *    extra arguments (the callees are declared without prototypes);
 *  - the mapped block is kept twice: as an unsigned short (mapped) and as an unsigned char (block); the last
 *    group of writes uses mapped & 0xff;
 *  - each read-modify-write first assigns block to value and then the read result (dead store kept);
 *  - the 0x7E / 0x76 writes pass the value as unsigned int, the 0x31 / 0x32 writes cast it to unsigned char.
 */
extern unsigned int dp_stored_settings_port0;
extern unsigned int dp_stored_settings_port1;
extern unsigned char dp_input_records[][300];   /* DP input records, 300 bytes each */
extern int dp_map_port();
extern int sys_get_chip_revision();
extern int dp_paged_reg_read8();
extern void dp_paged_reg_write8();
extern int dp_paged_reg_update_bits();

/* The same register in each of the four register sets of a receiver block. Set A: 0x100, 0x180, 0x200,
   0x280; set B: 0x500, 0x600, 0x700, 0x800. */
#define SET_A(n, reg) (0x100 + 0x80 * (n) + (reg))
#define SET_B(n, reg) (0x500 + 0x100 * (n) + (reg))

#define DP_RECORD_BYTE_0x11F 0x11f  /* DP input record byte set by commands from the main processor */
#define CHIP_REV_81          0x81   /* revisions above this get bit 7 of register 0x306 */

/* Stored settings record (dp_stored_settings_port0 / _port1): byte offsets. */
#define STORED_MARKER   0       /* the record is used only when this byte is STORED_VALID */
#define STORED_VALID    0xa0
#define STORED_REG30    3       /* whole register 0x30 */
#define STORED_REG31    4       /* low nibble of register 0x31 */
#define STORED_REG32    5       /* low five bits of register 0x32 */
#define STORED_REG76    6       /* bits 5..7 of register 0x76 */
#define STORED_REG7E    7       /* bits 3..7 of register 0x7E */

/*
 * Write the fixed register set-up of a DisplayPort receiver block, then the values of its stored settings
 * record when that record is marked valid.
 *
 *   port           DP input 0 or 1; dp_map_port gives the receiver block (the port swap is applied there)
 *   extra2..extra6 not used, only passed on (see the matching notes)
 *
 * Called only by dp_start_port when its force argument is set, which dp_init_port does.
 *
 * Phases:
 *   1. Map the port to its receiver block.
 *   2. Fixed values for the block and for the four register sets (0x119.. is written 0xDF, later 0x5F;
 *      0x426 0xFF, later 0x4F).
 *   3. Chip revision above 0x81: set bit 7 of register 0x306.
 *   4. Register 4 = 0xFA; register 0x55 = 0x0F when byte 0x11F of the port's DP input record is 1.
 *   5. More fixed values for the four sets.
 *   6. The stored record of the block (record 0 for block 0, record 1 otherwise) replaces registers 0x30, 0x31,
 *      0x32, 0x76 and 0x7E, keeping the other bits of the last four.
 *   7. Closing writes, with registers 0x4B1 and 0x4B2 pulsed (2, then 0).
 */
void dp_apply_port_record(unsigned int port, unsigned int extra2, unsigned int extra3, unsigned int extra4,
                          unsigned int extra5, unsigned int extra6)
{
  unsigned int value;
  unsigned short mapped;
  unsigned char *stored;
  unsigned char block;

  /* 1. Receiver block of the port. */
  mapped = dp_map_port(port & 0xff);
  block = mapped & 0xff;

  /* 2. Fixed values. */
  dp_paged_reg_write8(block,0,0xc0);
  dp_paged_reg_write8(block,0x5e,0xd1);
  dp_paged_reg_write8(block,0x5f,0x95);
  dp_paged_reg_write8(block,0x75,0xd);
  dp_paged_reg_write8(block,0xaf,0x84);
  dp_paged_reg_write8(block,0x48f,0x48);
  dp_paged_reg_write8(block,0x490,0x81);
  dp_paged_reg_write8(block,0x469,0x2d);
  dp_paged_reg_write8(block,0x423,0x62);
  dp_paged_reg_write8(block,SET_A(0, 0x18),0xf);
  dp_paged_reg_write8(block,SET_A(1, 0x18),0xf);
  dp_paged_reg_write8(block,SET_A(2, 0x18),0xf);
  dp_paged_reg_write8(block,SET_A(3, 0x18),0xf);
  dp_paged_reg_write8(block,SET_A(0, 0x19),0xdf);
  dp_paged_reg_write8(block,SET_A(1, 0x19),0xdf);
  dp_paged_reg_write8(block,SET_A(2, 0x19),0xdf);
  dp_paged_reg_write8(block,SET_A(3, 0x19),0xdf);
  dp_paged_reg_write8(block,0x9e,0xc5);
  dp_paged_reg_write8(block,0x465,0x77);
  dp_paged_reg_write8(block,0x466,0x37);
  dp_paged_reg_write8(block,0x30,0x77);
  dp_paged_reg_write8(block,0x31,0x89);
  dp_paged_reg_write8(block,0x32,0x2f);
  dp_paged_reg_write8(block,0x37,0xa8);
  dp_paged_reg_write8(block,0x7e,0xb9);
  dp_paged_reg_write8(block,0x76,0x90);
  dp_paged_reg_write8(block,0xaa,0xeb);
  dp_paged_reg_write8(block,0xa4,0x61);
  dp_paged_reg_write8(block,0xa5,0xc4);
  dp_paged_reg_write8(block,0xa6,0x9c);
  dp_paged_reg_write8(block,0xa7,0x2a);
  dp_paged_reg_write8(block,SET_B(0, 0x10),1);
  dp_paged_reg_write8(block,SET_B(1, 0x10),1);
  dp_paged_reg_write8(block,SET_B(2, 0x10),1);
  dp_paged_reg_write8(block,SET_B(3, 0x10),1);
  dp_paged_reg_write8(block,0x464,0xd4);
  dp_paged_reg_write8(block,SET_A(0, 0x19),0x5f);
  dp_paged_reg_write8(block,SET_A(1, 0x19),0x5f);
  dp_paged_reg_write8(block,SET_A(2, 0x19),0x5f);
  dp_paged_reg_write8(block,SET_A(3, 0x19),0x5f);
  dp_paged_reg_write8(block,0x426,0xff);
  dp_paged_reg_write8(block,0x462,0xf4);
  dp_paged_reg_write8(block,0x5d,0xff);
  dp_paged_reg_write8(block,0x68,4);
  dp_paged_reg_write8(block,0x6f,0xff);
  dp_paged_reg_write8(block,0x70,0xff);
  dp_paged_reg_write8(block,0x426,0x4f);

  /* 3. Chip revision. */
  value = sys_get_chip_revision();
  if (CHIP_REV_81 < (value & 0xff)) {
    dp_paged_reg_update_bits(block,0x306,0x80,1);
  }

  /* 4. Register 4, and register 0x55 by the main processor's setting. */
  dp_paged_reg_write8(block,4,0xfa);
  if (dp_input_records[port & 0xff][DP_RECORD_BYTE_0x11F] == 1) {
    dp_paged_reg_write8(block,0x55,0xf);
  }

  /* 5. More fixed values, four sets each. */
  dp_paged_reg_write8(block,SET_A(0, 0x0b),0);
  dp_paged_reg_write8(block,SET_A(1, 0x0b),0);
  dp_paged_reg_write8(block,SET_A(2, 0x0b),0);
  dp_paged_reg_write8(block,SET_A(3, 0x0b),0);
  dp_paged_reg_write8(block,SET_A(0, 0x0c),0);
  dp_paged_reg_write8(block,SET_A(1, 0x0c),0);
  dp_paged_reg_write8(block,SET_A(2, 0x0c),0);
  dp_paged_reg_write8(block,SET_A(3, 0x0c),0);
  dp_paged_reg_write8(block,SET_A(0, 0x1b),8);
  dp_paged_reg_write8(block,SET_A(1, 0x1b),8);
  dp_paged_reg_write8(block,SET_A(2, 0x1b),8);
  dp_paged_reg_write8(block,SET_A(3, 0x1b),8);
  dp_paged_reg_write8(block,SET_A(0, 0x1c),0xe);
  dp_paged_reg_write8(block,SET_A(1, 0x1c),0xe);
  dp_paged_reg_write8(block,SET_A(2, 0x1c),0xe);
  dp_paged_reg_write8(block,SET_A(3, 0x1c),0xe);
  dp_paged_reg_write8(block,SET_A(0, 0x1e),0x40);
  dp_paged_reg_write8(block,SET_A(1, 0x1e),0x40);
  dp_paged_reg_write8(block,SET_A(2, 0x1e),0x40);
  dp_paged_reg_write8(block,SET_A(3, 0x1e),0x40);
  dp_paged_reg_write8(block,SET_A(0, 0x27),0x10);
  dp_paged_reg_write8(block,SET_A(1, 0x27),0x10);
  dp_paged_reg_write8(block,SET_A(2, 0x27),0x10);
  dp_paged_reg_write8(block,SET_A(3, 0x27),0x10);
  dp_paged_reg_write8(block,SET_A(0, 0x50),8);
  dp_paged_reg_write8(block,SET_A(1, 0x50),8);
  dp_paged_reg_write8(block,SET_A(2, 0x50),8);
  dp_paged_reg_write8(block,SET_A(3, 0x50),8);
  dp_paged_reg_write8(block,0x46d,5);
  dp_paged_reg_write8(block,0x4e9,0);
  dp_paged_reg_write8(block,0x4b1,0);
  dp_paged_reg_write8(block,0x4b2,0);
  dp_paged_reg_write8(block,0x4d1,0);
  dp_paged_reg_write8(block,SET_B(0, 0x50),0x2a);
  dp_paged_reg_write8(block,SET_B(1, 0x50),0x2a);
  dp_paged_reg_write8(block,SET_B(2, 0x50),0x2a);
  dp_paged_reg_write8(block,SET_B(3, 0x50),0x2a);
  dp_paged_reg_write8(block,SET_B(0, 0x53),0xb);
  dp_paged_reg_write8(block,SET_B(1, 0x53),0xb);
  dp_paged_reg_write8(block,SET_B(2, 0x53),0xb);
  dp_paged_reg_write8(block,SET_B(3, 0x53),0xb);
  dp_paged_reg_write8(block,SET_B(0, 0x54),0x80);
  dp_paged_reg_write8(block,SET_B(1, 0x54),0x80);
  dp_paged_reg_write8(block,SET_B(2, 0x54),0x80);
  dp_paged_reg_write8(block,SET_B(3, 0x54),0x80);
  dp_paged_reg_write8(block,SET_B(0, 0x59),0x10);
  dp_paged_reg_write8(block,SET_B(1, 0x59),0x10);
  dp_paged_reg_write8(block,SET_B(2, 0x59),0x10);
  dp_paged_reg_write8(block,SET_B(3, 0x59),0x10);
  dp_paged_reg_write8(block,SET_B(0, 0x62),0);
  dp_paged_reg_write8(block,SET_B(1, 0x62),0);
  dp_paged_reg_write8(block,SET_B(2, 0x62),0);
  dp_paged_reg_write8(block,SET_B(3, 0x62),0);
  dp_paged_reg_write8(block,SET_B(0, 0x69),0);
  dp_paged_reg_write8(block,SET_B(1, 0x69),0);
  dp_paged_reg_write8(block,SET_B(2, 0x69),0);
  dp_paged_reg_write8(block,SET_B(3, 0x69),0);
  dp_paged_reg_write8(block,SET_B(0, 0x6a),0);
  dp_paged_reg_write8(block,SET_B(1, 0x6a),0);
  dp_paged_reg_write8(block,SET_B(2, 0x6a),0);
  dp_paged_reg_write8(block,SET_B(3, 0x6a),0);
  dp_paged_reg_write8(block,SET_B(0, 0x6b),0);
  dp_paged_reg_write8(block,SET_B(1, 0x6b),0);
  dp_paged_reg_write8(block,SET_B(2, 0x6b),0);
  dp_paged_reg_write8(block,SET_B(3, 0x6b),0);
  dp_paged_reg_write8(block,SET_B(0, 0x6c),0);
  dp_paged_reg_write8(block,SET_B(1, 0x6c),0);
  dp_paged_reg_write8(block,SET_B(2, 0x6c),0);
  dp_paged_reg_write8(block,SET_B(3, 0x6c),0);
  dp_paged_reg_write8(block,SET_B(0, 0xd3),8);
  dp_paged_reg_write8(block,SET_B(1, 0xd3),8);
  dp_paged_reg_write8(block,SET_B(2, 0xd3),8);
  dp_paged_reg_write8(block,SET_B(3, 0xd3),8);

  /* 6. The block's stored settings record, when it is marked valid. */
  stored = &dp_stored_settings_port0;
  if (block != 0) {
    stored = &dp_stored_settings_port1;
  }
  if (*stored == STORED_VALID) {
    dp_paged_reg_write8(block,0x30,stored[STORED_REG30]);
    value = block;
    value = dp_paged_reg_read8(block,0x31);
    dp_paged_reg_write8(block,0x31,(unsigned char)(value & 0xf0 | stored[STORED_REG31]));
    value = block;
    value = dp_paged_reg_read8(block,0x32);
    dp_paged_reg_write8(block,0x32,(unsigned char)(value & 0xe0 | stored[STORED_REG32]));
    value = dp_paged_reg_read8(block,0x7e);
    dp_paged_reg_write8(block,0x7e,value & 7 | (unsigned int)(unsigned char)stored[STORED_REG7E]);
    value = dp_paged_reg_read8(block,0x76);
    dp_paged_reg_write8(block,0x76,value & 0x1f | (unsigned int)(unsigned char)stored[STORED_REG76]);
  }

  /* 7. Closing writes. */
  mapped = mapped & 0xff;
  dp_paged_reg_write8(mapped,0xaf,0x94);
  dp_paged_reg_write8(mapped,0x4a8,0xff);
  dp_paged_reg_write8(mapped,0x4a9,0xfd);
  dp_paged_reg_write8(mapped,0x4ab,2);
  dp_paged_reg_write8(mapped,0x4ac,2);
  dp_paged_reg_write8(mapped,0x4b1,2);
  dp_paged_reg_write8(mapped,0x4b1,0);
  dp_paged_reg_write8(mapped,0x4b2,2);
  dp_paged_reg_write8(mapped,0x4b2,0);
  dp_paged_reg_write8(mapped,0x4ae,0xfd);
  dp_paged_reg_write8(mapped,0x4af,0xfd,extra4,extra5,extra6);
  return;
}
