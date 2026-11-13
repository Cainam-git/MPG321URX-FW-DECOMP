/* fwupd_build_record_table  (FUN_CODE_a547)
 *
 * Read the record count and sizes from a signed update image in DRAM.
 * Name basis: derived - only after fwupd_check_image_signature ('NVTSC_IMG'); records 0x0652 (offset, size),
 *   totals 0x0113
 *
 * Matching notes
 * --------------
 * Built with OPTIMIZE(8,SPEED) LARGE; local i at XDATA 0x08F1. The i == 0 arm still indexes the table (MUL by 8)
 * and cross-jumps into the shared tail that calls fwupd_get_value_0717.
 * The three read windows are named by address (DAT_EXTMEM_08f2[4], 08f6[4], 08fb[1], as for e384 / df7f). They lie in
 * this routine's LARGE block (after i), and true local arrays give the same bytes ('i; a[4]; b[5]; c[1]' and
 * 'i; a[4]; b[4]; x; c[1]' both match), but the byte 0x08FA between them is never used, so the declaration that
 * covers it cannot be read from the firmware; the extern form invents nothing.
 * struct rec at 0x0652 is the one in src/8051_bank2/fwupd/fwupd_refresh_flash_records.c.
 */
/* One entry of the record table; same layout as in fwupd_refresh_flash_records' file. */
struct rec {
    unsigned long block;    /* the record's place, in 32-byte blocks from the start of the loaded image */
    unsigned long size;     /* the record's size word (bytes 4..7 of its first block) */
};
extern struct rec xdata fwupd_record_table[20];
extern unsigned char xdata fwupd_record_count;
extern unsigned long xdata fwupd_record_base;
extern unsigned char xdata fwupd_last_record_size_low;     /* low byte of the last record's size word */
extern unsigned long xdata fwupd_record_total;     /* sizes of records 1 and up, in 256-byte units */
/* A block read to 0x08F2 fills 32 bytes from there; these are the parts the routine uses. */
extern unsigned char xdata DAT_EXTMEM_08f2[4];  /* block bytes 0..3 */
extern unsigned char xdata DAT_EXTMEM_08f6[4];  /* block bytes 4..7 */
extern unsigned char xdata DAT_EXTMEM_08fb[1];  /* block byte 9 */
bit fwupd_check_image_signature(void);
extern unsigned long fwupd_get_value_0717(void);
extern void usb_port_read_blocks_buf(unsigned char *buf, unsigned long addr, unsigned char n, unsigned char in_order) small;
unsigned long lib_get_le_value(unsigned char *p, unsigned char n);
unsigned long lib_div256_round_up(unsigned long n);

/* fwupd_build_record_table: read the record table of the update image loaded in DRAM.
 *
 * Only when fwupd_check_image_signature finds the image mark ('NVTSC_IMG'). The image starts at block
 * fwupd_get_value_0717() (fwupd_dram_address); all block numbers below count from there.
 * - fwupd_record_count = byte 9 of the image's first block.
 * - Record 0 starts at block 1; each further record starts (size + 32) / 32 blocks after the one before.
 * - size = bytes 4..7 of the record's first block (little-endian).
 * - fwupd_record_total = the sizes of records 1 and up, each rounded up to 256-byte units; the mailbox command
 *   GET_RECORD_TOTAL (0x60) of fwupd_run_mailbox_command reports it.
 * - From the last record's first block: fwupd_record_base = bytes 0..3, fwupd_last_record_size_low = low byte of bytes 4..7.
 * Caller: fwupd_load_file_to_dram (port command 0x46), after the file copy. */
void fwupd_build_record_table(void)
{
    unsigned char i;
    if (fwupd_check_image_signature()) {
        usb_port_read_blocks_buf(DAT_EXTMEM_08f2, fwupd_get_value_0717(), 1, 0);
        fwupd_record_count = lib_get_le_value(DAT_EXTMEM_08fb, 1);
        fwupd_record_total = 0;
        for (i = 0; i < fwupd_record_count; i++) {
            if (i == 0) fwupd_record_table[i].block = 1;
            else fwupd_record_table[i].block = fwupd_record_table[i - 1].block + (fwupd_record_table[i - 1].size + 32) / 32;
            usb_port_read_blocks_buf(DAT_EXTMEM_08f2, fwupd_record_table[i].block + fwupd_get_value_0717(), 1, 0);
            fwupd_record_table[i].size = lib_get_le_value(DAT_EXTMEM_08f6, 4);
            if (i > 0) fwupd_record_total += lib_div256_round_up(fwupd_record_table[i].size);
            if (i == fwupd_record_count - 1) {
                fwupd_record_base = lib_get_le_value(DAT_EXTMEM_08f2, 4);
                fwupd_last_record_size_low = lib_get_le_value(DAT_EXTMEM_08f6, 4);
            }
        }
    }
}
