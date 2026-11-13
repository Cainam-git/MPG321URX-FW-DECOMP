/* fwupd_ntfs_run_offset  (FUN_CODE_c7c5)
 *
 * Return the cluster offset field of NTFS data run h.
 *   run_number
 * Returns: offset
 * Name basis: derived - high-nibble field of the run header, little-endian; run buffer 0x015C
 *
 * Matching notes
 * --------------
 * Built with OPTIMIZE(8,SPEED) LARGE. run_number stays in R7 (no call, so the LARGE parameter is never stored).
 * Locals: offset_bytes 0x090D, length_bytes 0x090E, pos 0x090F, i 0x0910, value (ulong) 0x0911..0x0914; header is
 * register-only. Source forms the bytes depend on: the step is written into header again ('header = ...;
 * pos += header;' keeps it in R6), and the header after the walk is named twice (Keil reads it once into R6);
 * reusing header there gives it a memory slot, a block-local copy gives other code. The index is a byte sum
 * (unsigned char)(pos + length_bytes + i). No common-entry block.
 */
extern unsigned char xdata fwupd_ntfs_run_list[];
extern unsigned char xdata DAT_EXTMEM_015d[];   /* fwupd_ntfs_run_list + 1: the bytes after a run's header */

#define RUN_OFFSET_SIZE_MASK  0xf0  /* header bits 4..7: bytes of the offset field */
#define RUN_LENGTH_SIZE_MASK  0x0f  /* header bits 0..3: bytes of the length field */

/* fwupd_ntfs_run_offset: return the offset field of data run run_number in fwupd_ntfs_run_list.
 *
 * Each run is a header byte, then the length field (low nibble of the header = its byte count), then the offset
 * field (high nibble = its byte count). The routine steps over run_number runs and returns the offset field of the
 * next one, low byte first; the value is not sign-extended. The length field is fwupd_ntfs_run_length.
 * Callers: fwupd_list_next_img_entry (piece fwupd_list_next_img_entry_part5), fwupd_list_next_dir_entry, fwupd_ntfs_open_index_alloc. */
unsigned long fwupd_ntfs_run_offset(unsigned char run_number)
{
    unsigned char offset_bytes;
    unsigned char length_bytes;
    unsigned char pos;
    unsigned char i;
    unsigned long value;
    unsigned char header;
    pos = 0;
    for (i = 0; i < run_number; i++) {
        header = fwupd_ntfs_run_list[pos];
        header = ((header & RUN_OFFSET_SIZE_MASK) >> 4) + (header & RUN_LENGTH_SIZE_MASK) + 1;
        pos += header;
    }
    length_bytes = fwupd_ntfs_run_list[pos] & RUN_LENGTH_SIZE_MASK;
    offset_bytes = (fwupd_ntfs_run_list[pos] & RUN_OFFSET_SIZE_MASK) >> 4;
    value = 0;
    for (i = 0; i < offset_bytes; i++)
        value += (unsigned long)DAT_EXTMEM_015d[(unsigned char)(pos + length_bytes + i)] << (i * 8);
    return value;
}
