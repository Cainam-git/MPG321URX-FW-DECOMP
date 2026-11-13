/* fwupd_read_file_block16  (FUN_CODE_e54b)
 *
 * Read 512-byte block n of the loaded file copy (16-bit block number).
 * Name basis: derived - forwards to fwupd_read_file_block with the block number widened to 32 bits; called
 *   with block numbers by fwupd_verify_file_sum and fwupd_write_flash_blocks
 *
 * Matching notes
 * --------------
 * 8051_bank2 FUN_CODE_e54b @ 0xe54b, OPTIMIZE(8,SPEED).
 * The widening is CLR A / MOV R4,A / MOV R5,A in front of the tail jump (LJMP) to fwupd_read_file_block.
 */
void fwupd_read_file_block(unsigned long off, unsigned char *buf);

/* Read 512-byte block `block` of the loaded file copy in port memory into buf (fwupd_read_file_block, with the
 * block number widened to 32 bits). Nothing is read from the USB disk here.
 * Callers: fwupd_verify_file_sum (the byte sum of the file) and fwupd_write_flash_blocks (each block before it goes
 * to the flash). */
void fwupd_read_file_block16(unsigned int block, unsigned char *buf)
{
    fwupd_read_file_block(block, buf);
}
