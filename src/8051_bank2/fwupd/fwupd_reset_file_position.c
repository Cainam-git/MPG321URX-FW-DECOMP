/* fwupd_reset_file_position  (FUN_CODE_d5c5)
 *
 * Set the update file's read position back to the start.
 * Name basis: descriptive - 0x0414 / 0x0410 / 0x01DE from the start value 0x0418, counters cleared; NTFS (file
 *   system type 2) handled apart, FAT and exFAT together
 *
 * Matching notes
 * --------------
 * Built with OPTIMIZE(8,SPEED) LARGE. fwupd_dir_entry_count = 0 is written in each arm (Keil cross-jumps the shared
 * MOVX / MOV DPTR,#0409 / MOVX / RET tail); one store after the if gives 137 B. The product root_cluster * 4 is
 * computed twice (?C?LMUL each time). 0x0429 is declared as one byte here (only that byte is written).
 */
extern bit fwupd_ntfs_in_index_alloc;                    /* NTFS: the walk is in the index allocation */
extern bit fwupd_dir_end_reached;                    /* end of the directory reached */
extern unsigned char xdata fwupd_fs_type;
extern unsigned char xdata fwupd_ntfs_run_index; /* NTFS: index of the current data run */
extern unsigned char xdata fwupd_dir_sector; /* sector within the current cluster */
extern unsigned char xdata fwupd_dir_entry_count;
extern unsigned int xdata fwupd_bytes_per_sector;
extern unsigned int xdata fwupd_dir_entry_offset;
extern unsigned long xdata fwupd_fat_entry_offset;
extern unsigned long xdata fwupd_dir_cluster;
extern unsigned long xdata fwupd_root_cluster;
extern unsigned long xdata fwupd_fat_entry_sector;

#define FS_NTFS          2
#define FAT_ENTRY_BYTES  4

/* fwupd_reset_file_position: start the directory walk again from its beginning.
 *
 * NTFS: back to the index root (fwupd_ntfs_in_index_alloc and the data run index cleared). FAT / exFAT: back to the root cluster,
 * with its FAT position (offset and sector of its entry), sector 0 and entry offset 0. In both cases the end mark and
 * the count of listed entries are cleared.
 * Callers: fwupd_mount_volume at its end; fwupd_step_port_state when a list of images or directory entries
 * (port commands 0x45 / 0x47) reaches its end. */
void fwupd_reset_file_position(void)
{
    fwupd_dir_end_reached = 0;
    if (fwupd_fs_type == FS_NTFS) {
        fwupd_ntfs_in_index_alloc = 0;
        fwupd_ntfs_run_index = 0;
        fwupd_dir_entry_count = 0;
    } else {
        fwupd_dir_cluster = fwupd_root_cluster;
        fwupd_fat_entry_offset = fwupd_root_cluster * FAT_ENTRY_BYTES;
        fwupd_fat_entry_sector = fwupd_root_cluster * FAT_ENTRY_BYTES / fwupd_bytes_per_sector;
        fwupd_dir_entry_offset = 0;
        fwupd_dir_sector = 0;
        fwupd_dir_entry_count = 0;
    }
}
