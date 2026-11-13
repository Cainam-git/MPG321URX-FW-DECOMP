/* startup_load_tensilica_image  (FUN_CODE_c43e)
 *
 * Copy the Tensilica dimming program from flash by DMA.
 * Name basis: proven - docs/MAP.md start-up step 2 (partition record flash 0x030000, length 0xD8DC) via
 *   flash_dma_read; only for chip IDs 0x16/0x1E/0x1F/0x17
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_c43e, OPTIMIZE(8,SPEED) LARGE. 0xF152 is the only volatile (hardware register).
 */
#pragma LARGE
extern unsigned char volatile xdata DAT_EXTMEM_f152;
extern void flash_dma_read(unsigned long src, unsigned long len, unsigned char mode, bit four_byte);

/*
 * startup_load_tensilica_image - copy one flash record into the dimming processor's program by DMA: write 0x42 to
 * 0xF152, call flash_dma_read(source, length, 1, four_byte_address), then write 0x5B and 0x0B to 0xF152.
 *   record: two 32-bit words, flash source address and length in bytes
 *   four_byte_address: passed on as the 4-byte-address flag of flash_dma_read
 * Only caller: startup_load_core_images, with the record at XDATA 0xA4D7 (share structure copy), and only when reg_chip_id
 * is 0x16, 0x1E, 0x1F or 0x17.
 */
void startup_load_tensilica_image(unsigned long *record, bit four_byte_address)
{
    DAT_EXTMEM_f152 = 0x42;
    flash_dma_read(record[0], record[1], 1, four_byte_address);
    DAT_EXTMEM_f152 = 0x5B;
    DAT_EXTMEM_f152 = 0x0B;
}
