/* flash_begin_access  (FUN_CODE_dc51)
 *
 * Claim the SPI flash interface for the 8051 before a flash job.
 * Name basis: derived - sets bit 7 of reg 0xF1DF (bit 0 of 0xF1A8 cleared on chip 0x1A); called at the start
 *   of every flash routine
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_dc51 @ 0xdc51  OPTIMIZE(8,SPEED)
 * Source form: the register variables are placed with _at_ and keep the decompiler's symbol names where no name was given.
 */
#define CHIP_ID_1A            0x1a   /* reg_chip_id value */
#define FLASH_ACCESS_8051     0x80   /* bit 7 of reg_flash_access_ctrl */
#define F1A8_CLEAR_MASK       0xfe   /* clears bit 0 */

unsigned char xdata reg_chip_id _at_ 0xd511;
unsigned char xdata DAT_EXTMEM_f1a8 _at_ 0xf1a8;
unsigned char xdata reg_flash_access_ctrl _at_ 0xf1df;

/* Start of a flash job: set bit 7 of reg_flash_access_ctrl (gives the SPI
 * flash interface to the 8051); on chip variant 0x1A also clear bit 0 of
 * the register at 0xF1A8. flash_end_access undoes both. */
void flash_begin_access(void)
{
    reg_flash_access_ctrl = reg_flash_access_ctrl | FLASH_ACCESS_8051;
    if (reg_chip_id == CHIP_ID_1A) {
        DAT_EXTMEM_f1a8 = DAT_EXTMEM_f1a8 & F1A8_CLEAR_MASK;
    }
    return;
}
