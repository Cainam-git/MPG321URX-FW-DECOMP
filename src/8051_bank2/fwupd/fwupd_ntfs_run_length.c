/* fwupd_ntfs_run_length  (FUN_CODE_c89e)
 *
 * Return the first byte of the length field of NTFS data run n.
 *   run_number: number of the data run in fwupd_ntfs_run_list
 * Returns: the first length byte (0 when the field has no bytes)
 * Note: The other length bytes are shifted right by 8 or more before they are added, which leaves 0.
 * Name basis: derived - skips n runs by their header nibbles; adds the length bytes, byte i shifted right by 8
 *   * i; run buffer 0x015C
 *
 * Matching notes
 * --------------
 * Built with OPTIMIZE(8,SPEED) LARGE. run_number stays in R7 during the first loop (the LARGE parameter is never
 * stored). Locals: length_bytes 0x090D, pos 0x090E, i 0x090F, value (ulong) 0x0910..0x0913. t and c are declared
 * and never used; the matched source has them.
 * Source form the bytes depend on: each byte is shifted right as a byte ('>> (i * 8)'), not widened to a long first.
 */
extern unsigned char xdata fwupd_ntfs_run_list[];

#define RUN_OFFSET_SIZE_MASK  0xf0  /* header bits 4..7: bytes of the offset field */
#define RUN_LENGTH_SIZE_MASK  0x0f  /* header bits 0..3: bytes of the length field */

/* fwupd_ntfs_run_length: return the length field of data run run_number in fwupd_ntfs_run_list.
 *
 * The run layout is the one in fwupd_ntfs_run_offset. The routine steps over run_number runs and adds up the bytes
 * of the next run's length field, each shifted right by 8 * its position. An 8-bit value shifted right by 8 or more
 * is 0, so the result is the first length byte alone.
 * Callers: two places in the update-medium reader (fwupd/fwupd_set_target_file.c), each with run number fwupd_ntfs_run_index, storing
 * the result at XDATA 0x010D. */
unsigned long fwupd_ntfs_run_length(unsigned char run_number)
{
    unsigned char length_bytes;
    unsigned char pos;
    unsigned char i;
    unsigned long value;
    unsigned char t, c;
    pos = 0;
    for (i = 0; i < run_number; i++) {
        pos += ((fwupd_ntfs_run_list[pos] & RUN_OFFSET_SIZE_MASK) >> 4) + (fwupd_ntfs_run_list[pos] & RUN_LENGTH_SIZE_MASK) + 1;
    }
    length_bytes = fwupd_ntfs_run_list[pos] & RUN_LENGTH_SIZE_MASK;
    value = 0;
    for (i = 0; i < length_bytes; i++) {
        value = value + (fwupd_ntfs_run_list[(unsigned char)(pos + i) + 1] >> (i * 8));
    }
    return value;
}
