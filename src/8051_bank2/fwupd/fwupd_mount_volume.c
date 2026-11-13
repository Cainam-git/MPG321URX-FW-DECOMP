/* fwupd_mount_volume  (FUN_CODE_8cdc)
 *
 * Read the USB disk's boot sector and set up FAT, exFAT or NTFS access.
 * Name basis: proven - boot sector OEM ids 'MSDOS5.0' / 'NTFS', partition start at MBR offset 0x1C6, geometry
 *   fields per type
 *
 * Matching notes
 * --------------
 * 8051_bank2 FUN_CODE_8cdc @ 0x8cdc..0x8f95, compiled with OPTIMIZE(8,SPEED) LARGE.
 * usb_disk_read_to_xdata takes its byte count as a long in its XDATA parameter block (0x0927, through
 * ?C?LSTKXDATA).
 * Source form the bytes depend on: the name test compares '(char)fwupd_sector_buffer[3 + i]' with the char tables
 * (Keil loads the buffer byte into R5, the table byte into R4 and XORs the two registers); mismatch = 0xFF ends the
 * loop. The exFAT sizes are set to 1 and then shifted, as two statements each. The NTFS arm leaves through
 * 'goto done' past the FAT position set-up.
 */

/* File system types (fwupd_fs_type). */
#define FS_FAT               0
#define FS_EXFAT             1
#define FS_NTFS              2

#define SECTOR_BYTES         0x200       /* bytes read per block */
#define NAME_AT              3           /* the 8-byte name in the boot sector: bytes 3..10 */
#define NAME_BYTES           8
#define NAME_MISMATCH        0xff
#define PART_START_AT        0x1c6       /* 4-byte volume start read from block 0 when no name matched */

/* Boot sector byte offsets, named after the value each one gives. */
#define EXFAT_FAT_START_AT       0x50
#define EXFAT_DATA_START_AT      0x58
#define EXFAT_ROOT_CLUSTER_AT    0x60
#define EXFAT_SECTOR_SHIFT_AT    0x6c    /* bytes per sector = 1 << this byte */
#define EXFAT_CLUSTER_SHIFT_AT   0x6d    /* sectors per cluster = 1 << this byte */
#define BYTES_PER_SECTOR_AT      0x0b    /* 2 bytes, FAT and NTFS */
#define SECTORS_PER_CLUSTER_AT   0x0d    /* 1 byte, FAT and NTFS */
#define NTFS_MFT_CLUSTER_AT      0x30    /* 4 bytes; times sectors per cluster = fwupd_ntfs_mft_sector */
#define FAT_RESERVED_AT          0x0e    /* 2 bytes: FAT start, also added to the data start */
#define FAT_COUNT_AT             0x10    /* 1 byte: multiplier of the 4-byte value at 0x24 */
#define FAT_SIZE_AT              0x24
#define FAT_ROOT_CLUSTER_AT      0x2c
#define FAT_ENTRY_BYTES          4       /* fwupd_fat_entry_offset = cluster * 4 */

extern unsigned char xdata fwupd_sector_buffer[];
extern char code fwupd_msdos_oem_name[];
extern char code fwupd_ntfs_oem_name[];
extern unsigned long xdata fwupd_volume_start_sector;
extern unsigned char xdata fwupd_fs_type;
extern unsigned int xdata fwupd_sectors_per_cluster;
extern unsigned int xdata fwupd_bytes_per_sector;
extern unsigned long xdata fwupd_root_cluster;
extern unsigned long xdata fwupd_data_start_sector;
extern unsigned long xdata fwupd_fat_start_sector;
extern unsigned long xdata fwupd_ntfs_mft_sector;
extern unsigned long xdata fwupd_dir_cluster;
extern unsigned long xdata fwupd_fat_entry_offset;
extern unsigned long xdata fwupd_fat_entry_sector;
void usb_disk_read_to_xdata(unsigned long addr, unsigned char *buf, unsigned long n);
unsigned long lib_get_le_value(unsigned char *p, unsigned char n);
void fwupd_ntfs_open_index_root(void);
void fwupd_reset_file_position(void);
void fwupd_set_value_0156(unsigned int v);

/* fwupd_mount_volume: find the volume on the storage device and take its layout from the boot sector.
 *
 * Caller: fwupd_step_port_state, after enumeration found a storage device (class 8, protocol 0x50); the port state
 * then becomes STATE_DISK_MOUNTED (0x96).
 *
 * Order:
 *   1. Read block 0. When each of its bytes 3..10 equals the byte at the same place in "MSDOS5.0" or in "NTFS    ",
 *      block 0 is the volume's own boot sector (volume start 0). Otherwise the 4-byte value at 0x1C6 is the volume
 *      start, and the block there is read instead.
 *   2. Decide the type from bytes 3..7 of that block: "EXFAT" -> exFAT, "NTFS" -> NTFS, anything else -> FAT (not
 *      checked further). Each type fills the sizes and start sectors it uses (see the offsets above).
 *   3. NTFS: fwupd_ntfs_open_index_root finds the root folder. exFAT and FAT: the directory walk starts at the
 *      root cluster (fwupd_dir_cluster), with its FAT entry offset (cluster * 4) and the FAT sector holding it.
 *   4. fwupd_reset_file_position, and the CONFIG.bin sum (fwupd_config_sum at 0x0156) = 0.
 * Nothing is returned and no step can fail here.
 */
void fwupd_mount_volume(void)
{
    unsigned char i;
    unsigned char mismatch;
    usb_disk_read_to_xdata(0, fwupd_sector_buffer, SECTOR_BYTES);
    mismatch = 0;
    for (i = 0; i < NAME_BYTES; i++) {
        if ((char)fwupd_sector_buffer[NAME_AT + i] != fwupd_msdos_oem_name[i] && (char)fwupd_sector_buffer[NAME_AT + i] != fwupd_ntfs_oem_name[i]) {
            mismatch = NAME_MISMATCH;
            break;
        }
    }
    /* No known name in block 0: take the volume start from it and read that block. */
    if (mismatch == NAME_MISMATCH) {
        fwupd_volume_start_sector = lib_get_le_value(fwupd_sector_buffer + PART_START_AT, 4);
        usb_disk_read_to_xdata(fwupd_volume_start_sector, fwupd_sector_buffer, SECTOR_BYTES);
    } else fwupd_volume_start_sector = 0;
    if (fwupd_sector_buffer[3] == 'E' && fwupd_sector_buffer[4] == 'X' && fwupd_sector_buffer[5] == 'F' && fwupd_sector_buffer[6] == 'A'
        && fwupd_sector_buffer[7] == 'T') {
        fwupd_fs_type = FS_EXFAT;
        fwupd_sectors_per_cluster = 1;
        fwupd_sectors_per_cluster <<= fwupd_sector_buffer[EXFAT_CLUSTER_SHIFT_AT];
        fwupd_bytes_per_sector = 1;
        fwupd_bytes_per_sector <<= fwupd_sector_buffer[EXFAT_SECTOR_SHIFT_AT];
        fwupd_root_cluster = lib_get_le_value(fwupd_sector_buffer + EXFAT_ROOT_CLUSTER_AT, 4);
        fwupd_data_start_sector = lib_get_le_value(fwupd_sector_buffer + EXFAT_DATA_START_AT, 4);
        fwupd_fat_start_sector = lib_get_le_value(fwupd_sector_buffer + EXFAT_FAT_START_AT, 4);
    } else if (fwupd_sector_buffer[3] == 'N' && fwupd_sector_buffer[4] == 'T' && fwupd_sector_buffer[5] == 'F'
        && fwupd_sector_buffer[6] == 'S') {
        fwupd_fs_type = FS_NTFS;
        fwupd_bytes_per_sector = lib_get_le_value(fwupd_sector_buffer + BYTES_PER_SECTOR_AT, 2);
        fwupd_sectors_per_cluster = fwupd_sector_buffer[SECTORS_PER_CLUSTER_AT];
        fwupd_ntfs_mft_sector = lib_get_le_value(fwupd_sector_buffer + NTFS_MFT_CLUSTER_AT, 4) * fwupd_sectors_per_cluster;
        fwupd_ntfs_open_index_root();
        goto done;          /* NTFS has no FAT position to set up */
    } else {
        fwupd_fs_type = FS_FAT;
        fwupd_bytes_per_sector = lib_get_le_value(fwupd_sector_buffer + BYTES_PER_SECTOR_AT, 2);
        fwupd_data_start_sector = lib_get_le_value(fwupd_sector_buffer + FAT_SIZE_AT, 4) * fwupd_sector_buffer[FAT_COUNT_AT]
            + lib_get_le_value(fwupd_sector_buffer + FAT_RESERVED_AT, 2);
        fwupd_fat_start_sector = lib_get_le_value(fwupd_sector_buffer + FAT_RESERVED_AT, 2);
        fwupd_root_cluster = lib_get_le_value(fwupd_sector_buffer + FAT_ROOT_CLUSTER_AT, 4);
        fwupd_sectors_per_cluster = fwupd_sector_buffer[SECTORS_PER_CLUSTER_AT];
    }
    /* Start the directory walk at the root cluster. */
    fwupd_dir_cluster = fwupd_root_cluster;
    fwupd_fat_entry_offset = fwupd_root_cluster * FAT_ENTRY_BYTES;
    fwupd_fat_entry_sector = fwupd_root_cluster * FAT_ENTRY_BYTES / fwupd_bytes_per_sector;
done:
    fwupd_reset_file_position();
    fwupd_set_value_0156(0);
}
