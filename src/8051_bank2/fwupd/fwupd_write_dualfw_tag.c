/* fwupd_write_dualfw_tag  (FUN_CODE_ca42)
 *
 * Write the 512-byte DUALFW tag block for the update mode.
 *   mode: update mode
 * Name basis: derived - signature 'DUALFW' at block offset 0x1F0, block 0x77 via fwupd_svc_write_block
 *
 * Matching notes
 * --------------
 * Built with OPTIMIZE(8,SPEED) LARGE; mode (R7) is kept in the LARGE block at 0x08EE, sum at 0x08EF..0x08F0.
 * The sum of the block is computed and never used; it is in the firmware's bytes, so it stays.
 * The fill loop compiles to Keil's MOVX / INC DPTR / DJNZ R7 / DJNZ R6 form from a plain index loop (memset gives
 * ?C?MEMSET instead).
 */
extern unsigned char xdata fwupd_block_buffer[0x200];
extern unsigned char xdata fwupd_flash_size_code;
extern unsigned char xdata fwupd_mailbox_work_bytes[8];  /* the eight work bytes set by mailbox commands 0x41 / 0x42 */
extern unsigned char usb_get_port_error_count(void);
extern unsigned char fwupd_svc_write_register(unsigned int reg, unsigned char val);
extern void fwupd_svc_send_cmd_0x0f(unsigned char a);
extern void fwupd_svc_write_block(unsigned char block, unsigned char *buf);
extern void fwupd_wait_ready_line(unsigned int t);

#define ISP_MODE_BIT2       0x04
#define SVC_REG_F0DE        0xf0de
#define BLOCK_BYTES         0x200
#define FILL_BYTE           0xff
#define TAG_MARK_AT         0x1f0   /* "DUALFW" */
#define TAG_BYTE_AT         0x1f6
#define TAG_BIT2_CLEAR      0x78    /* tag byte without ISP_MODE_BIT2 */
#define TAG_WORK_BYTES_AT   0x1f7   /* eight bytes, only without ISP_MODE_BIT2 */
#define TAG_BLOCK           0x77    /* block number given to fwupd_svc_write_block */

/* fwupd_write_dualfw_tag: build the 512-byte DUALFW tag block in fwupd_block_buffer and write it.
 *
 * mode: the update mode of fwupd_run_isp_write (its only caller, for modes with bit 2 or bit 3).
 *
 * Nothing happens when usb_get_port_error_count() is set. Otherwise: service register 0xF0DE = 0x23, then 0x21; the
 * block is all FILL_BYTE with "DUALFW" at TAG_MARK_AT and one tag byte after it: with ISP_MODE_BIT2,
 * fwupd_flash_size_code * 2; without it, TAG_BIT2_CLEAR followed by the eight work bytes. Then service command
 * 0x0F with 0, the block goes out as block TAG_BLOCK, and the routine waits for the ready line (200). */
void fwupd_write_dualfw_tag(unsigned char mode)
{
    unsigned int sum;
    unsigned int i;
    sum = 0;
    if (usb_get_port_error_count()) return;
    fwupd_svc_write_register(SVC_REG_F0DE, 0x23);
    fwupd_svc_write_register(SVC_REG_F0DE, 0x21);
    for (i = 0; i < BLOCK_BYTES; i++) fwupd_block_buffer[i] = FILL_BYTE;
    fwupd_block_buffer[TAG_MARK_AT + 0] = 'D';
    fwupd_block_buffer[TAG_MARK_AT + 1] = 'U';
    fwupd_block_buffer[TAG_MARK_AT + 2] = 'A';
    fwupd_block_buffer[TAG_MARK_AT + 3] = 'L';
    fwupd_block_buffer[TAG_MARK_AT + 4] = 'F';
    fwupd_block_buffer[TAG_MARK_AT + 5] = 'W';
    if (mode & ISP_MODE_BIT2) {
        fwupd_block_buffer[TAG_BYTE_AT] = fwupd_flash_size_code * 2;
    } else {
        fwupd_block_buffer[TAG_BYTE_AT] = TAG_BIT2_CLEAR;
        for (i = 0; i < 8; i++) fwupd_block_buffer[TAG_WORK_BYTES_AT + i] = fwupd_mailbox_work_bytes[i];
    }
    for (i = 0; i < BLOCK_BYTES; i++) sum += fwupd_block_buffer[i];
    fwupd_svc_send_cmd_0x0f(0);
    fwupd_svc_write_block(TAG_BLOCK, fwupd_block_buffer);
    fwupd_wait_ready_line(200);
}
