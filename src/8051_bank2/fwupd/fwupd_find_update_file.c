/* fwupd_find_update_file  (FUN_CODE_35a9)
 *
 * Search the USB disk's root folder for UPDATE*.bin and CONFIG.bin.
 *   use_mailbox_name: 1 = take the name from the command bytes
 * Returns: 1 file found and checked
 * Name basis: proven - name 'UPDATE' (or 6 bytes from 0xF19A) + 'BIN', attribute 0x20; FAT and exFAT; then
 *   copy and sum check
 *
 * Matching notes
 * --------------
 * fwupd_find_update_file @ 0x35a9..0x3e68 (2239 B), OPTIMIZE(8,SPEED) LARGE.
 * LARGE locals in the firmware's XDATA order: use_mailbox_name (parameter, 0x08F2), offset (0x08F3), found (0x08F5),
 * sector_index (0x08F6), port (0x08F7), name[6] (0x08F8, initialised from the CODE bytes "UPDATE" at 0xE0B3 with
 * ?C?COPY).
 * Source forms the exact build depends on:
 *   - exFAT name bytes are compared as '(unsigned int)(name[j] + 0x20) == buf[...]' (sum computed first, int compare).
 *   - The shifts are written 'x = 1; x <<= n;'.
 *   - The boot sector test is 'for (offset = 0; offset != 11; offset++)'.
 *   - 'return 0' right after the (found & 0x0F) test lets Keil use A (MOV R7,A).
 *   - XDATA 0x0429 is struct fwupd_geometry {dir_sector; bytes_per_sector} as in fwupd/fwupd_set_target_file.c.
 */
/* File system codes in fwupd_fs_type. */
#define FS_FAT                  0
#define FS_EXFAT                1

#define SECTOR_BYTES            0x200   /* bytes read for block 0 and the volume's first block */
#define BOOT_HEAD_BYTES         11      /* bytes compared with fwupd_boot_sector_head */
#define NOT_A_BOOT_SECTOR       0xff    /* 'found' while block 0 is tested */
#define PART_START_AT           0x1c6   /* block 0: 32-bit first sector of the volume */

/* exFAT boot sector fields (all 32-bit values, read with lib_get_le_value). */
#define EXFAT_FAT_OFFSET_AT     0x50    /* -> fwupd_fat_start_sector */
#define EXFAT_HEAP_OFFSET_AT    0x58    /* -> fwupd_exfat_heap_offset */
#define EXFAT_ROOT_CLUSTER_AT   0x60    /* -> fwupd_root_cluster (stored minus 2) */
#define EXFAT_SECTOR_SHIFT_AT   0x6c    /* byte: bytes per sector = 1 << value */
#define EXFAT_CLUSTER_SHIFT_AT  0x6d    /* byte: sectors per cluster = 1 << value */

/* FAT boot sector fields. */
#define FAT_SECTOR_BYTES_AT     0x0b    /* 16-bit bytes per sector */
#define FAT_CLUSTER_SECTORS_AT  0x0d    /* byte: sectors per cluster */
#define FAT_RESERVED_AT         0x0e    /* 16-bit: first sector of the FAT */
#define FAT_COUNT_AT            0x10    /* byte: number of FATs */
#define FAT_SIZE_AT             0x24    /* 32-bit: sectors per FAT */
#define FAT_ROOT_CLUSTER_AT     0x2c    /* 32-bit -> fwupd_root_cluster */

#define DIR_ENTRY_BYTES         0x20
#define EXFAT_ENTRY_SET_FIRST   0x85    /* exFAT: first entry of a set; the walk steps over the whole set */
#define EXFAT_SET_STEP          0x60    /* bytes stepped over after an EXFAT_ENTRY_SET_FIRST entry */
#define DIR_END_MARK            0       /* first entry byte 0 ends the walk */
#define FAT_ATTR_ACCEPTED       0x20    /* the only attribute byte (+0x0B) a FAT entry may have */
#define WALK_LIMIT              0x2800  /* an offset above this ends the search with 0 */

/* Bits in 'found'. */
#define FOUND_UPDATE_FILE       0x0a
#define FOUND_CONFIG_FILE       0xa0
#define FOUND_BOTH              0xaa
#define FOUND_UPDATE_MASK       0x0f

struct fwupd_geometry { unsigned char dir_sector; unsigned int bytes_per_sector; };
extern struct fwupd_geometry xdata fwupd_dir_sector;
extern unsigned char xdata fwupd_sector_buffer[];
extern unsigned char code fwupd_boot_sector_head[];
extern unsigned long xdata fwupd_volume_start_sector;
extern unsigned long xdata fwupd_data_start_sector;
extern unsigned long xdata fwupd_root_cluster;
extern unsigned long xdata fwupd_exfat_heap_offset;
extern unsigned long xdata fwupd_fat_start_sector;
extern unsigned int xdata fwupd_sectors_per_cluster;
extern unsigned char xdata fwupd_fs_type;
extern unsigned char xdata fwupd_config_record_flag;
extern unsigned char xdata reg_fwupd_mailbox_f19a, reg_fwupd_mailbox_f19b, reg_fwupd_mailbox_f19c, reg_fwupd_mailbox_f19d, reg_fwupd_mailbox_f19e, reg_fwupd_mailbox_f19f;
extern unsigned char usb_get_current_port(void);
extern void usb_disk_read_to_xdata(unsigned long addr, unsigned char *buf, unsigned long n);
extern unsigned long lib_get_le_value(unsigned char *p, unsigned char n);
extern void fwupd_take_file_entry(unsigned int e);
extern void fwupd_take_config_entry(unsigned int e);
extern void fwupd_copy_file_to_dram(void);
extern unsigned char fwupd_verify_file_sum(void);

/* Find the update file (and CONFIG.BIN, when present) on the USB stick, load the update file into DRAM and check it.
 *   use_mailbox_name: 1 = the six name bytes come from mailbox bytes 0xF19A..0xF19F; any other value = "UPDATE".
 * Returns 1 when a file was loaded and fwupd_verify_file_sum accepted it, else 0.
 * Callers: usb_host_scan_hub_ports (with 0) and fwupd_step_port_state (with 0 or 1).
 *
 * Phases, in order:
 *   1. Name: choose the six name bytes, then write them to mailbox bytes 0xF19A..0xF19F.
 *   2. Volume start: read block 0 into fwupd_sector_buffer. When its first 11 bytes differ from
 *      fwupd_boot_sector_head, the volume starts at the 32-bit sector number at +0x1C6 and that block is read;
 *      else the volume starts at sector 0.
 *   3a. exFAT ("EXFAT" at bytes 3..7): set fwupd_fs_type and the geometry from the boot sector, read the block at
 *      fwupd_data_start_sector (cluster heap offset + (root cluster - 2) * sectors per cluster), then walk its 32-byte entries. Only entry sets
 *      (first byte 0x85) are tested: the name characters at set offsets +0x42..+0x4C (every second byte) against
 *      the six name bytes + 0x20, then 'b' 'i' 'n' at +0x50 / +0x52 / +0x54 (+0x4E is not compared); the same with
 *      "config". The end mark, or both files found, ends the walk.
 *   3b. FAT (anything else): set fwupd_fs_type and the geometry, read the first block of the data area, walk the
 *      32-byte entries: six name bytes, extension "BIN", attribute 0x20; the same with "CONFIG". The end mark, or
 *      both files found, ends the walk; without the update file the routine returns 0.
 *      In both walks: an update file entry goes to fwupd_take_file_entry, a CONFIG entry to fwupd_take_config_entry
 *      (and sets fwupd_config_record_flag); at the end of a block the next sector is read; an offset above 0x2800
 *      returns 0.
 *   4. Load: fwupd_copy_file_to_dram, then fwupd_verify_file_sum decides the result.
 * The exFAT walk goes on to phase 4 at the end mark without testing that the update file was found; only the FAT
 * walk tests it. Both walks read the following sectors in a row; they do not follow a cluster chain.
 */
unsigned char fwupd_find_update_file(unsigned char use_mailbox_name)
{
    unsigned int offset;            /* byte offset of the current entry in fwupd_sector_buffer */
    unsigned char found;            /* FOUND_* bits */
    unsigned char sector_index;     /* sectors read after the first block of the folder */
    unsigned char port;             /* kept, not read again */
    unsigned char name[6] = "UPDATE";

    /* 1. Name to look for. */
    if (use_mailbox_name == 1) {
        name[0] = reg_fwupd_mailbox_f19a;
        name[1] = reg_fwupd_mailbox_f19b;
        name[2] = reg_fwupd_mailbox_f19c;
        name[3] = reg_fwupd_mailbox_f19d;
        name[4] = reg_fwupd_mailbox_f19e;
        name[5] = reg_fwupd_mailbox_f19f;
    }
    reg_fwupd_mailbox_f19a = name[0];
    reg_fwupd_mailbox_f19b = name[1];
    reg_fwupd_mailbox_f19c = name[2];
    reg_fwupd_mailbox_f19d = name[3];
    reg_fwupd_mailbox_f19e = name[4];
    reg_fwupd_mailbox_f19f = name[5];
    port = usb_get_current_port();

    /* 2. Block 0: boot sector of the volume, or the volume start at +0x1C6. */
    usb_disk_read_to_xdata(0, fwupd_sector_buffer, SECTOR_BYTES);
    found = 0;
    for (offset = 0; offset != BOOT_HEAD_BYTES; offset++) {
        if (fwupd_sector_buffer[offset] != fwupd_boot_sector_head[offset]) {
            found = NOT_A_BOOT_SECTOR;
            break;
        }
    }
    if (found == NOT_A_BOOT_SECTOR) {
        fwupd_volume_start_sector = lib_get_le_value(&fwupd_sector_buffer[PART_START_AT], 4);
        usb_disk_read_to_xdata(fwupd_volume_start_sector, fwupd_sector_buffer, SECTOR_BYTES);
    } else {
        fwupd_volume_start_sector = 0;
    }

    if (fwupd_sector_buffer[3] == 'E' && fwupd_sector_buffer[4] == 'X' && fwupd_sector_buffer[5] == 'F' && fwupd_sector_buffer[6] == 'A'
        && fwupd_sector_buffer[7] == 'T') {
        /* 3a. exFAT geometry. */
        fwupd_fs_type = FS_EXFAT;
        fwupd_sectors_per_cluster = 1;
        fwupd_sectors_per_cluster <<= fwupd_sector_buffer[EXFAT_CLUSTER_SHIFT_AT];
        fwupd_dir_sector.bytes_per_sector = 1;
        fwupd_dir_sector.bytes_per_sector <<= fwupd_sector_buffer[EXFAT_SECTOR_SHIFT_AT];
        fwupd_root_cluster = lib_get_le_value(&fwupd_sector_buffer[EXFAT_ROOT_CLUSTER_AT], 4) - 2;
        fwupd_exfat_heap_offset = lib_get_le_value(&fwupd_sector_buffer[EXFAT_HEAP_OFFSET_AT], 4);
        fwupd_data_start_sector = fwupd_exfat_heap_offset + fwupd_root_cluster * fwupd_sectors_per_cluster;
        fwupd_fat_start_sector = lib_get_le_value(&fwupd_sector_buffer[EXFAT_FAT_OFFSET_AT], 4);
        usb_disk_read_to_xdata(fwupd_data_start_sector + fwupd_volume_start_sector, fwupd_sector_buffer, fwupd_dir_sector.bytes_per_sector);
        offset = 0;
        sector_index = 0;
        found = 0;
        fwupd_config_record_flag = 0;
        /* exFAT walk. */
        for (;;) {
            if (fwupd_sector_buffer[offset] == DIR_END_MARK) goto load;
            if (fwupd_sector_buffer[offset] == EXFAT_ENTRY_SET_FIRST) {
                if ((unsigned int)(name[0] + 0x20) == fwupd_sector_buffer[offset + 0x42] && (unsigned int)(name[1] + 0x20) == fwupd_sector_buffer[offset + 0x44]
                    && (unsigned int)(name[2] + 0x20) == fwupd_sector_buffer[offset + 0x46] && (unsigned int)(name[3] + 0x20) == fwupd_sector_buffer[offset + 0x48]
                    && (unsigned int)(name[4] + 0x20) == fwupd_sector_buffer[offset + 0x4a] && (unsigned int)(name[5] + 0x20) == fwupd_sector_buffer[offset + 0x4c]
                    && fwupd_sector_buffer[offset + 0x50] == 'b' && fwupd_sector_buffer[offset + 0x52] == 'i' && fwupd_sector_buffer[offset + 0x54] == 'n') {
                    fwupd_take_file_entry(offset);
                    found |= FOUND_UPDATE_FILE;
                } else if (fwupd_sector_buffer[offset + 0x42] == 'c' && fwupd_sector_buffer[offset + 0x44] == 'o' && fwupd_sector_buffer[offset + 0x46] == 'n'
                    && fwupd_sector_buffer[offset + 0x48] == 'f' && fwupd_sector_buffer[offset + 0x4a] == 'i' && fwupd_sector_buffer[offset + 0x4c] == 'g'
                    && fwupd_sector_buffer[offset + 0x50] == 'b' && fwupd_sector_buffer[offset + 0x52] == 'i' && fwupd_sector_buffer[offset + 0x54] == 'n') {
                    fwupd_take_config_entry(offset);
                    found |= FOUND_CONFIG_FILE;
                    fwupd_config_record_flag = 1;
                }
                offset += EXFAT_SET_STEP;
            } else {
                offset += DIR_ENTRY_BYTES;
            }
            if (found == FOUND_BOTH) goto load;
            if (offset >= fwupd_dir_sector.bytes_per_sector) {
                /* Next sector of the folder. */
                sector_index++;
                offset = 0;
                usb_disk_read_to_xdata(fwupd_data_start_sector + fwupd_volume_start_sector + sector_index, fwupd_sector_buffer, fwupd_dir_sector.bytes_per_sector);
            }
            if (offset > WALK_LIMIT) return 0;
        }
    } else {
        /* 3b. FAT geometry. */
        fwupd_fs_type = FS_FAT;
        fwupd_dir_sector.bytes_per_sector = lib_get_le_value(&fwupd_sector_buffer[FAT_SECTOR_BYTES_AT], 2);
        fwupd_data_start_sector = lib_get_le_value(&fwupd_sector_buffer[FAT_SIZE_AT], 4) * fwupd_sector_buffer[FAT_COUNT_AT] + lib_get_le_value(&fwupd_sector_buffer[FAT_RESERVED_AT], 2);
        fwupd_fat_start_sector = lib_get_le_value(&fwupd_sector_buffer[FAT_RESERVED_AT], 2);
        fwupd_root_cluster = lib_get_le_value(&fwupd_sector_buffer[FAT_ROOT_CLUSTER_AT], 4);
        fwupd_sectors_per_cluster = fwupd_sector_buffer[FAT_CLUSTER_SECTORS_AT];
        usb_disk_read_to_xdata(fwupd_data_start_sector + fwupd_volume_start_sector, fwupd_sector_buffer, fwupd_dir_sector.bytes_per_sector);
        offset = 0;
        sector_index = 0;
        found = 0;
        fwupd_config_record_flag = 0;
        /* FAT walk: name bytes 0..5, extension bytes 8..10, attribute byte 11. */
        for (;;) {
            if (fwupd_sector_buffer[offset] == DIR_END_MARK) break;
            if (fwupd_sector_buffer[offset] == name[0] && fwupd_sector_buffer[offset + 1] == name[1] && fwupd_sector_buffer[offset + 2] == name[2]
                && fwupd_sector_buffer[offset + 3] == name[3] && fwupd_sector_buffer[offset + 4] == name[4] && fwupd_sector_buffer[offset + 5] == name[5]
                && fwupd_sector_buffer[offset + 8] == 'B' && fwupd_sector_buffer[offset + 9] == 'I' && fwupd_sector_buffer[offset + 10] == 'N'
                && fwupd_sector_buffer[offset + 11] == FAT_ATTR_ACCEPTED) {
                fwupd_take_file_entry(offset);
                found |= FOUND_UPDATE_FILE;
            } else if (fwupd_sector_buffer[offset] == 'C' && fwupd_sector_buffer[offset + 1] == 'O' && fwupd_sector_buffer[offset + 2] == 'N'
                && fwupd_sector_buffer[offset + 3] == 'F' && fwupd_sector_buffer[offset + 4] == 'I' && fwupd_sector_buffer[offset + 5] == 'G'
                && fwupd_sector_buffer[offset + 8] == 'B' && fwupd_sector_buffer[offset + 9] == 'I' && fwupd_sector_buffer[offset + 10] == 'N'
                && fwupd_sector_buffer[offset + 11] == FAT_ATTR_ACCEPTED) {
                fwupd_take_config_entry(offset);
                found |= FOUND_CONFIG_FILE;
                fwupd_config_record_flag = 1;
            }
            if (found == FOUND_BOTH) break;
            offset += DIR_ENTRY_BYTES;
            if (offset >= fwupd_dir_sector.bytes_per_sector) {
                /* Next sector of the folder. */
                sector_index++;
                offset = 0;
                usb_disk_read_to_xdata(fwupd_data_start_sector + fwupd_volume_start_sector + sector_index, fwupd_sector_buffer, fwupd_dir_sector.bytes_per_sector);
            }
            if (offset > WALK_LIMIT) return 0;
        }
        if (!(found & FOUND_UPDATE_MASK)) return 0;
    }
load:
    /* 4. Load the file and check its sum. */
    fwupd_copy_file_to_dram();
    if (!fwupd_verify_file_sum()) return 0;
    return 1;
}
