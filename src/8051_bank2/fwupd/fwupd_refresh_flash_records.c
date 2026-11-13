/* fwupd_refresh_flash_records  (FUN_CODE_8437)
 *
 * Rewrite and verify the flash header records of the new firmware.
 *   mode: update mode 0x10/0x11
 * Returns: 0 when all records verified
 * Name basis: derived - 32-byte records read, changed (bytes 0x0C/0x0D, DUALFW slot words), written back and
 *   compared
 *
 * Matching notes
 * --------------
 * 8051_bank2 module FUN_CODE_8437, compiled with OPTIMIZE(8,SPEED) LARGE.
 * ONE Keil C51 module, 5 functions, in this order: fwupd_refresh_flash_records (0x8437..0x872D), fwupd_record_verify
 * (block 0xD84C + function 0xD866..0xD8C3), fwupd_record_set_byte (block 0xDC78, 0xDC80..0xDCC8), fwupd_record_write
 * (block 0xDE04, 0xDE20..0xDE4F), fwupd_record_copy_field (block 0xDEE4, 0xDEFD..0xDF2C). The 11 "fragments"
 * d84c/d859/d85b, dc78/dc7c, de04/de13/de15, dee4/def0/def2 are Keil OPTIMIZE(8) common-entry code built from the
 * call sites in fwupd_refresh_flash_records; Keil puts each L? block into the callee's code segment in front of it,
 * so each callee segment = block + function (lengths 26/8/28/25 B = firmware). OPTIMIZE(7,SPEED) LARGE builds no
 * common-entry blocks (1061 B), so the module is level 8.
 * usb_port_read_blocks_buf / usb_port_write_blocks_buf are SMALL-model functions (parameter block at DATA 0x08).
 * LARGE locals: block 0x08EE (erase_kb, failed, i, word_offset, flash_bytes); the callees' blocks start at 0x08F6.
 * Declaration facts the bytes depend on (no aids, no volatile, no dummy objects):
 * - the record table must be declared with a known size below 256 bytes: Keil then indexes it with 8-bit math
 *   (CLR A / ADDC A,#HIGH, firmware); [] or 32+ records give MOV A,B / ADDC and a different block (765 B). [20] = the
 *   table ends exactly at the next known global, XDATA 0x06F2. 2..31 records all give the same code.
 * - fwupd_record_verify compares 'fwupd_record_buffer[k] != flash_copy[k]' (Keil loads the right operand first);
 *   fwupd_record_set_byte reuses its parameter as the index (gives the firmware registers R6 = offset >> 2,
 *   R4 = offset & 3, R7 = index).
 * - fwupd_dualfw_region_next is declared as its own byte here; it is the 'next' byte of fwupd_dualfw_region.
 * Check note: the exact check matches fwupd_refresh_flash_records (its LCALL L?nnnn resolve through the common
 * entries). The 4 callees score low in a per-function compare only because the listing puts the L? block in front of
 * the function; over the real range (block start..callee end) all 4 are exact.
 */

#define RECORD_BYTES         0x20        /* one header record = one 32-byte bus block */
#define REC_BYTE_ERASE_KB    0x0c        /* record byte set to the erase block size in KB (0 in record 0) */
#define REC_BYTE_0D          0x0d        /* record byte set to 1 while region 0 is the current DUALFW region */
#define ISP_MODE_PICK_REGION 0x11        /* update mode of port command 0x17 (DUALFW) */
#define REGION_SHIFT         12          /* region n starts at fwupd_record_base + (n << 12) */
#define FLASH_SIZE_UNIT      0x40000UL   /* flash size = fwupd_flash_size_code * 0x40000 bytes */
#define WORD_STEP            8           /* words 0, 8, 16 and 24 of a block are moved */
#define ERASED_WORD          0xffffffff  /* an erased word ends the list */
#define READ_ONE_BLOCK       1
#define WORDS_REVERSED       0           /* last argument of the block routines: each 4-byte group reversed */

/* One entry of the record table (filled by fwupd_build_record_table from the loaded image). */
struct rec {
    unsigned long block;    /* +0: the record's place, in 32-byte blocks from the start of the loaded image */
    unsigned long size;     /* +4: the size word of the record (its bytes 4..7); the next record starts
                               (size + 32) / 32 blocks further on */
};
extern struct rec xdata fwupd_record_table[20];
extern unsigned char xdata fwupd_record_buffer[32];
/* fwupd_last_record_size_low: low byte of the size word of the last record (fwupd_build_record_table);
 * fwupd_dualfw_region_next: the 'next' region index of fwupd_dualfw_region. */
extern unsigned char xdata fwupd_record_count, fwupd_last_record_size_low, fwupd_dualfw_region, fwupd_dualfw_region_next, fwupd_flash_size_code;
extern unsigned long xdata fwupd_record_base;
extern unsigned long fwupd_get_value_0717(void);
extern unsigned long fwupd_record_get_word(unsigned char j);
extern unsigned char fwupd_get_erase_size_kb(unsigned long v);
extern void fwupd_record_set_word(unsigned char j, unsigned long v);
extern void usb_port_read_blocks_buf(unsigned char *buf, unsigned long addr, unsigned char n, unsigned char f) small;
extern void usb_port_write_blocks_buf(unsigned char *buf, unsigned long addr, unsigned char n, unsigned char f) small;
bit fwupd_record_verify(unsigned long block);
void fwupd_record_set_byte(unsigned char offset, unsigned char value);
void fwupd_record_write(unsigned long block);
void fwupd_record_copy_field(unsigned long block);

/* fwupd_refresh_flash_records: change the header records of the loaded image in memory and check each one.
 *
 * mode: the update mode; ISP_MODE_PICK_REGION (0x11) also does the last record and the blocks behind it, any other
 *       value only records 0 .. count-2. The only caller, fwupd_run_isp_write, passes 0x11 after
 *       fwupd_pick_valid_region, or 0x10 after setting the region to cur = 2, next = 0.
 * Returns 0 when every record written read back equal, 1 when at least one did not (the OR of all checks).
 *
 * Each record is handled the same way: read its 32-byte block into fwupd_record_buffer, change bytes or words
 * there, write the block back and read it again to compare. All addresses are the record's block number plus the
 * value at 0x0717 (fwupd_get_value_0717, the memory address of the loaded file).
 *   record 0:          byte 0x0C = 0;
 *   records 1..n-2:    byte 0x0C = erase size in KB that fits word 0 (64, 32 or 4, fwupd_get_erase_size_kb);
 *                      byte 0x0D = 1 when the current DUALFW region is 0;
 *   last record (0x11 only): word 0 = fwupd_record_base + (next region << 12), then byte 0x0C from that word;
 *   blocks behind the last record (0x11 only, (fwupd_last_record_size_low >> 5) blocks): words 0, 8, 16 and 24 of each block
 *                      get next region * half the flash size added, until a word reads 0xFFFFFFFF; the block is read
 *                      again before each word.
 * The byte numbers are those of fwupd_record_set_byte (see there).
 */
unsigned char fwupd_refresh_flash_records(unsigned char mode)
{
    unsigned char erase_kb;
    unsigned char failed;
    unsigned char i;
    unsigned char word_offset;
    unsigned long flash_bytes;

    if (mode == ISP_MODE_PICK_REGION) {
        fwupd_record_copy_field(fwupd_record_table[0].block);
        erase_kb = 0;
        fwupd_record_set_byte(REC_BYTE_ERASE_KB, erase_kb);
        fwupd_record_write(fwupd_record_table[0].block);
        failed = fwupd_record_verify(fwupd_record_table[0].block);
        for (i = 1; i < fwupd_record_count - 1; i++) {
            fwupd_record_copy_field(fwupd_record_table[i].block);
            erase_kb = fwupd_get_erase_size_kb(fwupd_record_get_word(0));
            fwupd_record_set_byte(REC_BYTE_ERASE_KB, erase_kb);
            if (fwupd_dualfw_region == 0) fwupd_record_set_byte(REC_BYTE_0D, 1);
            fwupd_record_write(fwupd_record_table[i].block);
            failed |= fwupd_record_verify(fwupd_record_table[i].block);
        }
        /* Last record: word 0 = start of the next DUALFW region. */
        flash_bytes = fwupd_flash_size_code * FLASH_SIZE_UNIT;
        fwupd_record_copy_field(fwupd_record_table[fwupd_record_count - 1].block);
        fwupd_record_set_word(0, fwupd_record_base + ((unsigned int)fwupd_dualfw_region_next << REGION_SHIFT));
        erase_kb = fwupd_get_erase_size_kb(fwupd_record_get_word(0));
        fwupd_record_set_byte(REC_BYTE_ERASE_KB, erase_kb);
        fwupd_record_write(fwupd_record_table[fwupd_record_count - 1].block);
        failed |= fwupd_record_verify(fwupd_record_table[fwupd_record_count - 1].block);
        /* Blocks behind the last record: add next region * half the flash size to each listed word. */
        for (i = 0; i < (fwupd_last_record_size_low >> 5); i++) {
            for (word_offset = 0; word_offset < RECORD_BYTES; word_offset += WORD_STEP) {
                fwupd_record_copy_field(fwupd_record_table[fwupd_record_count - 1].block + 1 + i);
                if (fwupd_record_get_word(word_offset) == ERASED_WORD) break;
                fwupd_record_set_word(word_offset, fwupd_record_get_word(word_offset) + fwupd_dualfw_region_next * (flash_bytes / 2));
                fwupd_record_write(fwupd_record_table[fwupd_record_count - 1].block + 1 + i);
                failed |= fwupd_record_verify(fwupd_record_table[fwupd_record_count - 1].block + 1 + i);
            }
        }
    } else {
        fwupd_record_copy_field(fwupd_record_table[0].block);
        erase_kb = 0;
        fwupd_record_set_byte(REC_BYTE_ERASE_KB, erase_kb);
        fwupd_record_write(fwupd_record_table[0].block);
        failed = fwupd_record_verify(fwupd_record_table[0].block);
        for (i = 1; i < fwupd_record_count - 1; i++) {
            fwupd_record_copy_field(fwupd_record_table[i].block);
            erase_kb = fwupd_get_erase_size_kb(fwupd_record_get_word(0));
            fwupd_record_set_byte(REC_BYTE_ERASE_KB, erase_kb);
            if (fwupd_dualfw_region == 0) fwupd_record_set_byte(REC_BYTE_0D, 1);
            fwupd_record_write(fwupd_record_table[i].block);
            failed |= fwupd_record_verify(fwupd_record_table[i].block);
        }
    }
    return failed;
}

/* fwupd_record_verify: read the record at block (plus the file address) into a buffer of its own and compare it
 * with fwupd_record_buffer. Returns 1 at the first byte that differs, 0 when all 32 agree. */
bit fwupd_record_verify(unsigned long block)
{
    unsigned char flash_copy[32];
    unsigned char k;
    bit differs;
    usb_port_read_blocks_buf(flash_copy, block + fwupd_get_value_0717(), READ_ONE_BLOCK, WORDS_REVERSED);
    for (k = 0; k < RECORD_BYTES; k++) {
        if (fwupd_record_buffer[k] != flash_copy[k]) { differs = 1; break; }
        if (k == 0x1f) differs = 0;
    }
    return differs;
}

/* fwupd_record_set_byte: store value as byte 'offset' of the record. The record is read with each 4-byte group
 * reversed (WORDS_REVERSED), so offset 4w + 0/1/2/3 lands at buffer index 4w + 3/2/1/0; byte 0x0C is the top byte
 * of the word fwupd_record_get_word(0x0C) returns. */
void fwupd_record_set_byte(unsigned char offset, unsigned char value)
{
    unsigned char word_index;
    word_index = offset >> 2;
    if ((offset & 3) == 0) offset = word_index * 4 + 3;
    else if ((offset & 3) == 1) offset = word_index * 4 + 2;
    else if ((offset & 3) == 2) offset = word_index * 4 + 1;
    else if ((offset & 3) == 3) offset = word_index * 4;
    fwupd_record_buffer[offset] = value;
}

/* fwupd_record_write: write fwupd_record_buffer back to the record at block (plus the file address). */
void fwupd_record_write(unsigned long block)
{
    usb_port_write_blocks_buf(fwupd_record_buffer, block + fwupd_get_value_0717(), READ_ONE_BLOCK, WORDS_REVERSED);
}

/* fwupd_record_copy_field: read the record at block (plus the file address) into fwupd_record_buffer. */
void fwupd_record_copy_field(unsigned long block)
{
    usb_port_read_blocks_buf(fwupd_record_buffer, block + fwupd_get_value_0717(), READ_ONE_BLOCK, WORDS_REVERSED);
}
