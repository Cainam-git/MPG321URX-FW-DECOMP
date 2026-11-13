/* fwupd_test_ntfs_img_name  (FUN_CODE_4e8e)
 *
 * Report whether an NTFS file name ends in I, M, G (any case) and its sixth character from the end is not '~'.
 *   record_sector: record block
 *   name_offset
 *   name_length
 * Returns: 1 when .IMG
 * Name basis: derived - reads the last name characters through the block seek, case-insensitive I/M/G test;
 *   used by the IMG list
 *
 * Matching notes
 * --------------
 * Built with OPTIMIZE(8,SPEED) LARGE; returns a bit (carry). The parameters are LARGE memory parameters
 * (record_sector 0x0907..0x090A, name_offset 0x090B..0x090C, name_length 0x090D); found 0x090E.
 * Source form the bytes depend on: the tested byte is named twice in each || test (Keil reads it once and keeps it
 * in R7); a local 'c = ...; if (c == 'g' || c == 'G')' puts it in R6. No common-entry block.
 */
extern unsigned int xdata DAT_EXTMEM_011b;      /* the cursor's byte offset in fwupd_sector_buffer: the .offset
                                                   field of fwupd_saved_position (0x0117), set by
                                                   fwupd_seek_block_offset */
extern unsigned char xdata fwupd_sector_buffer[];
extern void fwupd_seek_block_offset(unsigned long sector, unsigned int offset);

#define FOUND_G      0x01
#define FOUND_M      0x02
#define FOUND_I      0x04
#define FOUND_NO_ALT 0x08       /* the sixth character from the end is not '~' */
#define FOUND_ALL    0x0f

/* fwupd_test_ntfs_img_name: tell whether an NTFS file name ends in ".IMG" (any case) and its sixth character from
 * the end is not '~'.
 *
 * record_sector: disk sector (from the volume start) the name offsets count from.
 * name_offset:   byte offset of the name's first character; the name has two bytes per character.
 * name_length:   the name's length in characters.
 * Returns 1 when all four tests pass, else 0.
 *
 * Each character is reached with fwupd_seek_block_offset, which reads the sector it falls in when needed; the
 * low byte of the character is tested. Caller: fwupd_list_next_img_entry (piece fwupd_list_next_img_entry_part5), for the list of
 * image files. */
bit fwupd_test_ntfs_img_name(unsigned long record_sector, unsigned int name_offset, unsigned char name_length)
{
    unsigned char found;
    found = 0;
    fwupd_seek_block_offset(record_sector, name_offset + (name_length - 1) * 2);
    if (fwupd_sector_buffer[DAT_EXTMEM_011b] == 'g' || fwupd_sector_buffer[DAT_EXTMEM_011b] == 'G') found |= FOUND_G;
    fwupd_seek_block_offset(record_sector, name_offset + (name_length - 2) * 2);
    if (fwupd_sector_buffer[DAT_EXTMEM_011b] == 'm' || fwupd_sector_buffer[DAT_EXTMEM_011b] == 'M') found |= FOUND_M;
    fwupd_seek_block_offset(record_sector, name_offset + (name_length - 3) * 2);
    if (fwupd_sector_buffer[DAT_EXTMEM_011b] == 'i' || fwupd_sector_buffer[DAT_EXTMEM_011b] == 'I') found |= FOUND_I;
    fwupd_seek_block_offset(record_sector, name_offset + (name_length - 6) * 2);
    if (fwupd_sector_buffer[DAT_EXTMEM_011b] != '~') found |= FOUND_NO_ALT;
    if ((found & FOUND_ALL) == FOUND_ALL)
        return 1;
    return 0;
}
