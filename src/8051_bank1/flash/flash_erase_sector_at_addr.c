/* flash_erase_sector_at_addr  (FUN_CODE_da91)
 *
 * Erase the 4 KB flash sector that holds the requested address.
 * Name basis: derived - mailbox command 0x13; DoBlockErase(address / 0x1000, 0x20 = Sector Erase opcode)
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_da91 @ 0xda91
 * Options: OPTIMIZE(8,SPEED). The sector number is a 32-bit division by 0x1000 (?C?ULDIV); the call is a tail jump.
 */
#define FLASH_SECTOR_BYTES 0x1000   /* 4 KB sector */
#define FLASH_CMD_ERASE_4K 0x20     /* sector erase opcode */

extern unsigned long xdata flash_job_address;
void DoBlockErase(unsigned int sector, unsigned char cmd);

/* Erase the sector that holds the current flash job address
 * (flash_job_address). Run for mailbox command 0x13. */
void flash_erase_sector_at_addr(void)
{
    DoBlockErase(flash_job_address / FLASH_SECTOR_BYTES, FLASH_CMD_ERASE_4K);
}
