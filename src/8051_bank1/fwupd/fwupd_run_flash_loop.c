/* fwupd_run_flash_loop  (FUN_CODE_6c34)
 *
 * Serve flash erase, write and read commands from the update mailbox forever.
 * Note: Never returns; command 8 stops in an endless loop.
 * Name basis: proven - prints 'STBC FW updating......', 'checksum error'; mailbox 0xF250, ack 0xF260;
 *   docs/MAP.md update path (command 0x29)
 *
 * Matching notes
 * --------------
 * Compiler flags: OPTIMIZE(8,SPEED) REGFILE(R.ORC) (not LARGE).
 * Real size 0x181 bytes (the case bodies sit after the switch table).
 * Source forms: the mailbox is one array (Keil steps through it with INC DPTR); 0xA4B3 is a 32-bit / byte union
 *   (the address bytes are stored one by one, high byte first); the command copy at 0xA4B7 and the expected sum
 *   at 0xA4B8 are globals (both stored to XDATA, not kept in registers).
 */

/* Byte positions in the update mailbox (XDATA 0xF250..0xF261), written by the other side of the update. */
#define MBOX_COMMAND        0x00  /* command number; 0 = nothing to do. Cleared here when a command is done. */
#define MBOX_ARG0           0x01  /* first argument byte (count, address bits 23..16 or extended address) */
#define MBOX_ARG1           0x02
#define MBOX_ARG2           0x03
#define MBOX_ARG3           0x04
#define MBOX_ARG4           0x05
#define MBOX_ACK            0x10  /* inverted command number, written after each command */
#define MBOX_SUM_ERROR      0x11  /* set to SUM_ERROR_MARK by command 2 on a checksum mismatch */
#define SUM_ERROR_MARK      0x55

/* Commands of the update mailbox. */
#define FWUPD_CMD_ERASE           1  /* erase 4 KB sectors: count in ARG0, 32-bit address in ARG1..ARG4 */
#define FWUPD_CMD_PROGRAM_CHECKED 2  /* program a page, read it back and compare its sum */
#define FWUPD_CMD_SET_EXT_ADDR    3  /* flash extended address register = ARG0 */
#define FWUPD_CMD_READ_PAGE       4  /* read one page into the transfer buffer */
#define FWUPD_CMD_PROGRAM_PAGE    5  /* program one page from the transfer buffer */
#define FWUPD_CMD_UNPROTECT       6  /* save the status registers, clear the protect bits */
#define FWUPD_CMD_PROTECT         7  /* write the saved status registers back */
#define FWUPD_CMD_HALT            8  /* stop here for good */

#define SECTOR_SHIFT        12    /* 4 KB sectors */
#define PASS_MARK           0x55  /* written to 0xF00A and 0xF0E0 on every pass; ipc_run_command
                                     writes 0xAA there while it holds its handshake */
#define FWUPD_STATUS_SAVE   ((void xdata *)0xa776)  /* where commands 6 and 7 keep the flash status bytes */

extern unsigned char volatile xdata reg_fwupd_mailbox[0x12];
extern unsigned char volatile xdata DAT_EXTMEM_f00a, DAT_EXTMEM_f0e0;
extern unsigned char xdata DAT_EXTMEM_a4b7;   /* command being served */
extern unsigned int xdata DAT_EXTMEM_a4b8;    /* expected page sum of command 2 */
extern union { unsigned long l; unsigned char b[4]; } xdata DAT_EXTMEM_a4b3;   /* flash address, high byte first */
extern void lib_printf517(void *fmt, ...) large;
extern void flash_erase_sector(unsigned int sector, unsigned char count);
extern void flash_program_page(unsigned char addr_23_16, unsigned char addr_15_8, unsigned char addr_7_0);
extern unsigned int flash_sum_page(unsigned char addr_23_16, unsigned char addr_15_8, unsigned char addr_7_0);
extern void flash_read_page(unsigned char addr_23_16, unsigned char addr_15_8, unsigned char addr_7_0);
extern void flash_write_extended_addr(unsigned char ext);
extern void flash_unprotect(void *save);
extern void flash_restore_status(void *save);
extern void flash_begin_access(void);
extern void flash_end_access(void);

/* The 8051's firmware-update loop, entered through mailbox command 0x29 (ipc_run_command) and never left.
 * It prints "STBC FW updating......" once, then on every pass:
 *   - reads the command byte of the update mailbox at XDATA 0xF250; 0 means no command and nothing else happens;
 *   - otherwise carries the command out (see the FWUPD_CMD_* list), then clears the command byte and writes the
 *     inverted command number to the acknowledge byte (0xF260), which tells the sender that the command is done.
 *     Numbers above 8 are acknowledged without any action; command 8 never comes back to the acknowledgement;
 *   - writes 0x55 to XDATA 0xF00A and 0xF0E0 (what reads them is not shown here).
 * The page commands (2, 4, 5) take a 24-bit flash address as three bytes, high byte first; the page data moves
 * through the transfer buffer of flash_read_page / flash_program_page. Command 2 also takes the expected 16-bit
 * sum of the page (ARG3 high, ARG4 low) and, when the sum read back differs, sets the error byte (0xF261) to 0x55
 * and prints "checksum error %04X, %04X" with the expected and the read sum.
 */
void fwupd_run_flash_loop(void)
{
    unsigned int sum;
    lib_printf517((void code *)0xc930);    /* "STBC FW updating......" */
    for (;;) {
        DAT_EXTMEM_a4b7 = reg_fwupd_mailbox[MBOX_COMMAND];
        if (DAT_EXTMEM_a4b7 != 0) {
            switch (DAT_EXTMEM_a4b7) {
            case FWUPD_CMD_ERASE:
                DAT_EXTMEM_a4b3.b[0] = reg_fwupd_mailbox[MBOX_ARG1];
                DAT_EXTMEM_a4b3.b[1] = reg_fwupd_mailbox[MBOX_ARG2];
                DAT_EXTMEM_a4b3.b[2] = reg_fwupd_mailbox[MBOX_ARG3];
                DAT_EXTMEM_a4b3.b[3] = reg_fwupd_mailbox[MBOX_ARG4];
                flash_erase_sector(DAT_EXTMEM_a4b3.l >> SECTOR_SHIFT, reg_fwupd_mailbox[MBOX_ARG0]);
                break;
            case FWUPD_CMD_PROGRAM_CHECKED:
                DAT_EXTMEM_a4b8 = reg_fwupd_mailbox[MBOX_ARG3] << 8 | reg_fwupd_mailbox[MBOX_ARG4];
                flash_program_page(reg_fwupd_mailbox[MBOX_ARG0], reg_fwupd_mailbox[MBOX_ARG1], reg_fwupd_mailbox[MBOX_ARG2]);
                sum = flash_sum_page(reg_fwupd_mailbox[MBOX_ARG0], reg_fwupd_mailbox[MBOX_ARG1], reg_fwupd_mailbox[MBOX_ARG2]);
                if (DAT_EXTMEM_a4b8 != sum) {
                    reg_fwupd_mailbox[MBOX_SUM_ERROR] = SUM_ERROR_MARK;
                    lib_printf517((void code *)0xc949, DAT_EXTMEM_a4b8, sum);   /* "checksum error %04X, %04X" */
                }
                break;
            case FWUPD_CMD_SET_EXT_ADDR:
                flash_write_extended_addr(reg_fwupd_mailbox[MBOX_ARG0]);
                break;
            case FWUPD_CMD_READ_PAGE:
                DAT_EXTMEM_a4b3.b[0] = reg_fwupd_mailbox[MBOX_ARG0];
                DAT_EXTMEM_a4b3.b[1] = reg_fwupd_mailbox[MBOX_ARG1];
                DAT_EXTMEM_a4b3.b[2] = reg_fwupd_mailbox[MBOX_ARG2];
                DAT_EXTMEM_a4b3.b[3] = 0;
                flash_read_page(DAT_EXTMEM_a4b3.b[0], DAT_EXTMEM_a4b3.b[1], DAT_EXTMEM_a4b3.b[2]);
                break;
            case FWUPD_CMD_PROGRAM_PAGE:
                DAT_EXTMEM_a4b3.b[0] = reg_fwupd_mailbox[MBOX_ARG0];
                DAT_EXTMEM_a4b3.b[1] = reg_fwupd_mailbox[MBOX_ARG1];
                DAT_EXTMEM_a4b3.b[2] = reg_fwupd_mailbox[MBOX_ARG2];
                DAT_EXTMEM_a4b3.b[3] = 0;
                flash_program_page(DAT_EXTMEM_a4b3.b[0], DAT_EXTMEM_a4b3.b[1], DAT_EXTMEM_a4b3.b[2]);
                break;
            case FWUPD_CMD_UNPROTECT:
                flash_begin_access();
                flash_unprotect(FWUPD_STATUS_SAVE);
                flash_end_access();
                break;
            case FWUPD_CMD_PROTECT:
                flash_begin_access();
                flash_restore_status(FWUPD_STATUS_SAVE);
                flash_end_access();
                break;
            case FWUPD_CMD_HALT:
                for (;;) ;
            }
            reg_fwupd_mailbox[MBOX_COMMAND] = 0;
            reg_fwupd_mailbox[MBOX_ACK] = ~DAT_EXTMEM_a4b7;
        }
        DAT_EXTMEM_f00a = PASS_MARK;
        DAT_EXTMEM_f0e0 = PASS_MARK;
    }
}
