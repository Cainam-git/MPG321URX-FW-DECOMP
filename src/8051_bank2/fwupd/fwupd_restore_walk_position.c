/* fwupd_restore_walk_position  (FUN_CODE_d751)
 *
 * Copy the stored directory walk position back into the variables the directory listing works with.
 * Note: NTFS: the block reader's cursor becomes the index listing cursor; FAT / exFAT: the five values stored
 *   by fwupd_fat_step_cluster.
 * Name basis: derived - copies fwupd_saved_position (NTFS) or fwupd_walk_position (FAT, exFAT) into the
 *   listing variables; called after each step of the directory and index walk
 *
 * Matching notes
 * --------------
 * Built with OPTIMIZE(7,SPEED), the section default (OPTIMIZE(8,SPEED) LARGE gives the same bytes). Every value
 * is copied field by field; the struct layouts are those of fwupd/fwupd_set_target_file.c.
 */
/* The block reader's cursor (as in fwupd/fwupd_set_target_file.c). */
struct fwupd_pos { unsigned long sector; unsigned int offset; };
/* Position of the FAT / exFAT directory walk, stored by fwupd_fat_step_cluster (as in fwupd/fwupd_set_target_file.c). */
struct fwupd_walk_pos {
    unsigned long cluster;      /* cluster of the directory */
    unsigned char sector;       /* sector within that cluster */
    unsigned int offset;        /* byte offset within that sector */
    unsigned long fat_sector;   /* FAT sector holding the cluster's entry */
    unsigned long fat_offset;   /* byte offset of that entry */
};
struct fwupd_geometry { unsigned char dir_sector; unsigned int bytes_per_sector; };
extern struct fwupd_pos xdata fwupd_saved_position;
extern struct fwupd_walk_pos xdata fwupd_walk_position;
extern unsigned char xdata fwupd_fs_type;
extern unsigned long xdata fwupd_ntfs_index_sector;     /* NTFS: sector of the index entry to list next */
extern unsigned int xdata fwupd_ntfs_index_offset;      /* NTFS: byte offset of that index entry */
extern unsigned long xdata fwupd_dir_cluster;
extern struct fwupd_geometry xdata fwupd_dir_sector;
extern unsigned int xdata fwupd_dir_entry_offset;
extern unsigned long xdata fwupd_fat_entry_sector;
extern unsigned long xdata fwupd_fat_entry_offset;

#define FS_NTFS 2       /* fwupd_fs_type: 0 FAT, 1 exFAT, 2 NTFS */

/* fwupd_restore_walk_position: copy a stored position back into the variables the directory listing works with.
 *
 * NTFS: the block reader's cursor (fwupd_saved_position, moved by fwupd_seek_block_offset) becomes the listing
 * cursor fwupd_ntfs_index_sector / fwupd_ntfs_index_offset.
 * FAT and exFAT: the walk position that fwupd_fat_step_cluster stored in fwupd_walk_position goes back into
 * fwupd_dir_cluster, fwupd_dir_sector.dir_sector, fwupd_dir_entry_offset, fwupd_fat_entry_sector and
 * fwupd_fat_entry_offset.
 * Callers: the directory listers and the NTFS index openers of fwupd/fwupd_set_target_file.c. */
void fwupd_restore_walk_position(void)
{
    if (fwupd_fs_type == FS_NTFS) {
        fwupd_ntfs_index_sector = fwupd_saved_position.sector;
        fwupd_ntfs_index_offset = fwupd_saved_position.offset;
    } else {
        fwupd_dir_cluster = fwupd_walk_position.cluster;
        fwupd_dir_sector.dir_sector = fwupd_walk_position.sector;
        fwupd_dir_entry_offset = fwupd_walk_position.offset;
        fwupd_fat_entry_sector = fwupd_walk_position.fat_sector;
        fwupd_fat_entry_offset = fwupd_walk_position.fat_offset;
    }
}
