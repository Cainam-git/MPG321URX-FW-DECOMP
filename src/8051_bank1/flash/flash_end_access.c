/* flash_end_access  (FUN_CODE_dc67)
 *
 * Release the SPI flash interface after a flash job.
 * Name basis: derived - undoes flash_begin_access; called at the end of every flash routine
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_dc67 @ 0xdc67  OPTIMIZE(8,SPEED)
 * Source form: the register variables are placed with _at_ and keep the decompiler's symbol names where no name was given.
 */
#define CHIP_ID_1A            0x1a   /* reg_chip_id value */
#define FLASH_ACCESS_8051_OFF 0x7f   /* clears bit 7 of reg_flash_access_ctrl */

unsigned char xdata reg_chip_id _at_ 0xd511;
unsigned char xdata DAT_EXTMEM_f1a8 _at_ 0xf1a8;
unsigned char xdata reg_flash_access_ctrl _at_ 0xf1df;

/* End of a flash job, the reverse of flash_begin_access: on chip variant
 * 0x1A set bit 0 of the register at 0xF1A8, then clear bit 7 of
 * reg_flash_access_ctrl. */
void flash_end_access(void)
{
    if (reg_chip_id == CHIP_ID_1A) {
        DAT_EXTMEM_f1a8 = DAT_EXTMEM_f1a8 | 1;
    }
    reg_flash_access_ctrl = reg_flash_access_ctrl & FLASH_ACCESS_8051_OFF;
    return;
}
