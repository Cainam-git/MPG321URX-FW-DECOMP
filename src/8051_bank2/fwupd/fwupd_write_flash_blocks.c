/* fwupd_write_flash_blocks  (FUN_CODE_9f8f)
 *
 * Write the DRAM file copy to the flash in 512-byte blocks with progress.
 *   mode: bit 2 = upper half only, bit 1 = skip last 4 KB of each 64 KB
 * Note: Block count = flash size code << 8 from the chip record.
 * Name basis: derived - per block fwupd_svc_write_block over slave 0x6E; progress 0x47..0xFE to scaler reg
 *   0xBF04
 *
 * Matching notes
 * --------------
 * 8051_bank2 FUN_CODE_9f8f @ 0x9f8f, compiled with OPTIMIZE(8,SPEED) LARGE.
 * Real span 0x9f8f..0xa17e (495 bytes, includes the inline ?C?LSTKXDATA constant 00 00 00 B7 at 0xa01f).
 * mode (R7) and the locals live in the LARGE-model XDATA block 0x08EE (file_blocks 0x08EF, flash_blocks 0x08F1,
 * file_base 0x08F3, block 0x08F5, first_block 0x08F7, progress 0x08F9); j / byte_sum are register variables.
 * Keil idioms: flash_blocks goes through a register temporary size_blocks (Keil then reuses R6:R7 for
 * first_block = size_blocks >> 1; computing flash_blocks straight into memory reloads it); progress is first set to
 * the constant 0xFE - 0x47 and then used (gives the ?C?LSTKXDATA constant store and the reload);
 * (block & 0x7F) >= 0x78 compares as unsigned int (CLR A / SUBB A,#0). The byte sum is computed and never used;
 * its loop is in the firmware bytes and must stay.
 */

#define BLOCK_BYTES          0x200       /* one flash block = 512 bytes */
#define MODE_UPPER_HALF      0x04        /* start at the middle block */
#define MODE_SKIP_TAIL       0x02        /* skip the last 8 blocks of every 128 */
#define GROUP_MASK           0x7f        /* 128 blocks = 64 KB */
#define GROUP_TAIL_FIRST     0x78        /* blocks 0x78..0x7F of a group = its last 4 KB */
#define STATE_SHIFT          5           /* fwupd_svc_write_state_reg state changes every 32 blocks */
#define PROGRESS_FIRST       0x47        /* progress value at the first block */
#define PROGRESS_LAST        0xfe        /* value the progress approaches at the last block */
#define SVC_REG_F0DE         0xf0de      /* set to 0x23 around the progress write, 0x21 after it */
#define SVC_REG_PROGRESS     0xbf04
#define READY_WAIT_LIMIT     4000        /* time limit of fwupd_wait_ready_line */

extern unsigned char xdata fwupd_block_buffer[0x200];
extern unsigned char xdata fwupd_flash_size_code;
extern unsigned char xdata fwupd_last_percent;
extern unsigned long fwupd_get_value_0109(void);
extern unsigned char fwupd_svc_write_register(unsigned int reg, unsigned char val);
extern void fwupd_svc_write_state_reg(unsigned char a);
extern void fwupd_svc_send_cmd_0x0f(unsigned char a);
extern void fwupd_read_file_block16(unsigned int off, unsigned char *buf);
extern void fwupd_svc_write_block(unsigned char dev, unsigned char *buf);
extern void fwupd_wait_ready_line(unsigned int t);
extern void fwupd_svc_query_cmd_0x36(unsigned char a);

/* fwupd_write_flash_blocks: write the loaded file to the flash, one 512-byte block per round.
 *
 * mode: the update mode of fwupd_run_isp_write (its only caller, for modes 1, 2, 4 and 8); here only bit 2
 *       (MODE_UPPER_HALF) and bit 1 (MODE_SKIP_TAIL) count.
 *
 * The block count is fwupd_flash_size_code << 8; with MODE_UPPER_HALF the loop starts at half of it. The file
 * size (value at 0x0109, fwupd_get_value_0109) / 512 gives the file's block count. For each flash block:
 *   1. With MODE_SKIP_TAIL, blocks 0x78..0x7F of every 128 are left out.
 *   2. Progress 0x47 + (block - first) * 0xB7 / (count - first), sent to service register 0xBF04 (between
 *      0xF0DE = 0x23 and 0xF0DE = 0x21) only when it differs from the value sent last (fwupd_last_percent).
 *   3. fwupd_svc_write_state_reg with bit 5 of the block number.
 *   4. At every 128th block: service command 0x0F with block >> 8, and the file base is set to the block number
 *      rounded down to a multiple of the file's block count.
 *   5. Block (block - file base) of the loaded file is read into fwupd_block_buffer and written with
 *      fwupd_svc_write_block; that call takes a byte, so it gets the low 8 bits of the block number (the upper
 *      bits went out with command 0x0F). Its result is not tested.
 *   6. fwupd_wait_ready_line(4000), then service command 0x36 with the low byte of the block number; the answer
 *      is not used.
 * Nothing is read back.
 */
void fwupd_write_flash_blocks(unsigned char mode)
{
    unsigned int file_blocks;
    unsigned int flash_blocks;
    unsigned int size_blocks;
    unsigned int file_base;
    unsigned int block;
    unsigned int first_block;
    unsigned long progress;
    unsigned int j;
    unsigned int byte_sum;
    file_blocks = fwupd_get_value_0109() / BLOCK_BYTES;
    size_blocks = fwupd_flash_size_code << 8;
    flash_blocks = size_blocks;
    if (mode & MODE_UPPER_HALF) first_block = size_blocks >> 1; else first_block = 0;
    file_base = 0;
    for (block = first_block; block < flash_blocks; block++) {
        if ((mode & MODE_SKIP_TAIL) && (block & GROUP_MASK) >= GROUP_TAIL_FIRST) continue;
        progress = PROGRESS_LAST - PROGRESS_FIRST;
        progress = (unsigned long)(block - first_block) * progress / (flash_blocks - first_block) + PROGRESS_FIRST;
        if ((unsigned char)progress != fwupd_last_percent) {
            fwupd_svc_write_register(SVC_REG_F0DE, 0x23);
            fwupd_svc_write_register(SVC_REG_PROGRESS, (unsigned char)progress);
            fwupd_svc_write_register(SVC_REG_F0DE, 0x21);
            fwupd_last_percent = (unsigned char)progress;
        }
        fwupd_svc_write_state_reg((block >> STATE_SHIFT) & 1);
        if ((block & GROUP_MASK) == 0) {
            fwupd_svc_send_cmd_0x0f(block >> 8);
            /* File base: the block number rounded down to a multiple of the file's block count. */
            file_base = block / file_blocks * file_blocks;
        }
        fwupd_read_file_block16(block - file_base, fwupd_block_buffer);
        byte_sum = 0;
        for (j = 0; j < BLOCK_BYTES; j++) byte_sum += fwupd_block_buffer[j];   /* not used afterwards */
        fwupd_svc_write_block(block, fwupd_block_buffer);
        fwupd_wait_ready_line(READY_WAIT_LIMIT);
        fwupd_svc_query_cmd_0x36(block);
    }
}
