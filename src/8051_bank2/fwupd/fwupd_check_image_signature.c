/* fwupd_check_image_signature  (FUN_CODE_db76)
 *
 * Check the first block of the loaded update file for the 'NVTSC_IMG' signature.
 * Returns: 1 when the signature matches
 * Note: The text is tested at bytes 1..9 of the block; byte 0 is not tested.
 * Name basis: proven - reads one 32-byte block from the start of the loaded file (block fwupd_dram_address)
 *   into fwupd_image_header (0x0912) and compares nine characters with 'NVTSC_IMG'
 *
 * Matching notes
 * --------------
 * Built with OPTIMIZE(7,SPEED), the section default (OPTIMIZE(8,SPEED) LARGE and the SMALL forms give the same
 * bytes: no locals, no tail call). usb_port_read_blocks_buf is declared small as in fwupd/fwupd_refresh_flash_records.c (n and in_order
 * go to DATA 0x0F / 0x10).
 */
extern unsigned char xdata fwupd_image_header[];
extern unsigned long fwupd_get_value_0717(void);
extern void usb_port_read_blocks_buf(unsigned char *buf, unsigned long addr, unsigned char n, unsigned char in_order) small;

/* fwupd_check_image_signature: read the first 32-byte block of the loaded file (block fwupd_dram_address, through
 * fwupd_get_value_0717) into fwupd_image_header and test it for the text "NVTSC_IMG".
 * Returns 1 when all nine characters are there, else 0.
 *
 * in_order 0 stores each group of four bytes the other way round, so the characters are tested at buffer
 * positions 2 1 0, 7 6 5 4, 11 10: bytes 1..9 of the block as the data register gives them. Byte 0 is not tested.
 * Caller: fwupd_build_record_table, which reads the record table only when this returns 1. */
bit fwupd_check_image_signature(void)
{
    usb_port_read_blocks_buf(fwupd_image_header, fwupd_get_value_0717(), 1, 0);
    if (fwupd_image_header[2] == 'N' &&
        fwupd_image_header[1] == 'V' &&
        fwupd_image_header[0] == 'T' &&
        fwupd_image_header[7] == 'S' &&
        fwupd_image_header[6] == 'C' &&
        fwupd_image_header[5] == '_' &&
        fwupd_image_header[4] == 'I' &&
        fwupd_image_header[11] == 'M' &&
        fwupd_image_header[10] == 'G')
    {
        return 1;
    }
    return 0;
}
