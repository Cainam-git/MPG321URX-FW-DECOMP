/* flash_identify  (FUN_CODE_111f)
 *
 * Look the flash chip up in the built-in table of known chips and set its bus mode.
 * Name basis: proven - JEDEC id against the 57 records at 0x4000; a 32 MiB chip with a non-zero extended
 *   address is reset to 0 and the loader halts
 *
 * Matching notes
 * --------------
 * Built with OPTIMIZE(8,SPEED).
 * Source form: void, as both callers declare it, so the result of flash_setup_bus_mode is dropped.  The size code
 * is widened and shifted in the 16-bit flash_size_code itself, and the maker byte is held in the local maker for
 * the first test only; the exact build depends on both.
 */
/* Fields of one 6-byte record of flash_chip_table (CODE 0x4000). */
#define CHIP_REC_INDEX      0   /* chip index; high nibble = chip group */
#define CHIP_REC_MAKER      1   /* JEDEC id byte 0 */
#define CHIP_REC_MEM_TYPE   2   /* JEDEC id byte 1 */
#define CHIP_REC_CAPACITY   3   /* JEDEC id byte 2 */
#define CHIP_REC_SIZE_CODE  4
#define CHIP_REC_FLAGS      5   /* bit 0 = quad capable, bit 1 see flash_setup_bus_mode */

#define CHIP_FLAG_QUAD      0x01
#define CHIP_GROUP_MASK     0xf0
#define CHIP_INDEX_MAKER_ONLY 0x0f  /* low nibble of the index when only the maker byte matched */

#define JEDEC_MAKER_7F      0x7f  /* maker byte that gets the erase opcode 0xD7 */
#define FLASH_ERASE_OP_7F   0xd7
#define FLASH_ERASE_OP      0x20

#define SIZE_CODE_SMALL_MAX 0x0f    /* table size codes below this are moved into the high byte */
#define SIZE_CODE_5         0x0500  /* table size code 5, after that move */

#define SHARE_KIND_FLASH_INFO 5     /* share block entry at XDATA 0x3066 */
#define FLASH_INFO_BYTES    4       /* flash_chip_index, flash_erase_opcode, flash_size_code (2 bytes) */
#define REG_F00A_VALUE      0x55    /* value written to register 0xF00A; its purpose is not shown */

extern unsigned char code flash_chip_table[][6];
extern unsigned char volatile xdata reg_flash_jedec_maker, reg_flash_jedec_mem_type, reg_flash_jedec_capacity, DAT_EXTMEM_f00a;
extern unsigned char data flash_quad_capable_flag, flash_chip_index, flash_erase_opcode, flash_chip_flags;
extern unsigned int data flash_size_code;
unsigned char flash_get_known_chip_count(void);
unsigned char flash_read_extended_address(void);
void SetExtendedAddr(unsigned char ear);
void startup_share_block_write(unsigned char kind, unsigned char len, unsigned char *src);
unsigned char flash_setup_bus_mode(unsigned char quad_capable, unsigned char chip_index);

/* flash_identify
 *
 * Looks the JEDEC id that flash_read_jedec_id left in 0xF064..0xF066 up in flash_chip_table and fills the chip
 * state the other flash routines use: flash_chip_index, flash_size_code, flash_chip_flags, flash_quad_capable_flag
 * and flash_erase_opcode.  A record must match all three id bytes.  When none does, a record whose maker byte
 * matches still sets flash_chip_index, to its chip group with low nibble 0xF (the last such record wins); with no
 * match at all flash_chip_index keeps its old value.
 *
 * For size code 5 the chip's extended address register is read; when it is not 0 the routine writes 0 to it,
 * writes 0x55 to 0xF00A and stays in an endless loop: the boot loader goes no further.
 *
 * Last, the four bytes from flash_chip_index on go into the share block (kind 5, XDATA 0x3066) and
 * flash_setup_bus_mode chooses the read mode; its result is not used here.
 * Called by startup_boot_main and, after a DUALFW register patch, by startup_load_partition_table.
 */
void flash_identify(void)
{
    unsigned char i, chip_count, maker;
    chip_count = flash_get_known_chip_count();
    flash_quad_capable_flag = 0;
    for (i = 0; i < chip_count; i++) {
        maker = flash_chip_table[i][CHIP_REC_MAKER];
        if (maker == reg_flash_jedec_maker && flash_chip_table[i][CHIP_REC_MEM_TYPE] == reg_flash_jedec_mem_type && flash_chip_table[i][CHIP_REC_CAPACITY] == reg_flash_jedec_capacity) {
            flash_chip_index = flash_chip_table[i][CHIP_REC_INDEX];
            flash_size_code = flash_chip_table[i][CHIP_REC_SIZE_CODE];
            if (flash_size_code < SIZE_CODE_SMALL_MAX) flash_size_code <<= 8;
            flash_chip_flags = flash_chip_table[i][CHIP_REC_FLAGS];
            flash_quad_capable_flag = flash_chip_flags & CHIP_FLAG_QUAD;
            break;
        }
        if (reg_flash_jedec_maker == maker) flash_chip_index = (flash_chip_table[i][CHIP_REC_INDEX] & CHIP_GROUP_MASK) | CHIP_INDEX_MAKER_ONLY;
    }
    if (reg_flash_jedec_maker == JEDEC_MAKER_7F) flash_erase_opcode = FLASH_ERASE_OP_7F; else flash_erase_opcode = FLASH_ERASE_OP;
    if (flash_size_code == SIZE_CODE_5) {
        if (flash_read_extended_address() > 0) {
            /* Extended address not 0: set it to 0 and stop the boot here. */
            SetExtendedAddr(0);
            DAT_EXTMEM_f00a = REG_F00A_VALUE;
            for (;;);
        }
    }
    startup_share_block_write(SHARE_KIND_FLASH_INFO, FLASH_INFO_BYTES, &flash_chip_index);
    flash_setup_bus_mode(flash_quad_capable_flag, flash_chip_index);
}
