/* fwupd_set_target_file  (FUN_CODE_a17e)
 *
 * Select the listed directory entry as the update file.
 * Name basis: proven - port command 0x48; caller prints 'File_SetTargetFilePara!'; NTFS $DATA walk or
 *   FAT/exFAT entry
 *
 * Matching notes
 * --------------
 * Flags: Keil C51 OPTIMIZE(8,SPEED) LARGE, one module written by hand (the update-medium reader: directory walk,
 * file copy, record reader). All code in this file is firmware C; there are no synthetic callers and no stub bodies.
 * It is one file because Keil builds the common-entry blocks in front of fwupd_seek_block_offset (af07),
 * fwupd_fat_step_cluster (72b0), lib_get_le_value (bf1b) and fwupd_store_entry_pos (df50) from the call sites it
 * sees in the module, so every caller that enters one of those blocks must be in this file.
 *
 * Members (bytes; a common-entry block in front where noted):
 *   a17e 494; 9235 670; aa43 395; 9d97 504; bdbd 266; af07 46 + 317 (block 0xaed9..0xaf06); 3e68 2070;
 *   bf1b 69 + 195 (block 0xbec7..0xbf1a); df50 35 + 38 (block 0xdf2d..0xdf4f; functions.json has df44 =
 *   0xdf44..0xdf76, the C function starts at 0xdf50); 813c 763; b84b 303; 1000 3669 (to 0x1e55); 872e 730;
 *   72b0 78 + 967 (block 0x7262..0x72af; functions.json has 72a5 = 0x72a5..0x7677, the C function starts at 0x72b0);
 *   1e55 3359 (to 0x2b74). fwupd_list_next_img_entry_part1 / 13c8 / 13eb / 140a / 140d are pieces inside 1000, 2342 / 272d pieces
 *   inside 1e55; 7262 / 7263 / 72a5, bec7 / bf0c / bf10 / bf15, df2d / df44 and aed9..af03 are common-entry pieces.
 *
 * Common-entry blocks (Keil OPTIMIZE(8) "reuse of common entry code"; each lives in front of its callee):
 *   0xaed9..0xaf06 -> fwupd_seek_block_offset.
 *   0x7262 (MOVX) + 0x7263..0x72a4 (arguments fwupd_dir_cluster, fwupd_dir_sector.dir_sector, fwupd_dir_entry_offset,
 *     fwupd_fat_entry_sector, fwupd_fat_entry_offset) + 0x72a5..0x72af (load a long @DPTR) -> fwupd_fat_step_cluster.
 *     7263 / 72a5 are not functions. Every call site of 1000 enters the blocks as in the firmware (7262 @1e22,
 *     7263 @13f9 / 1e41).
 *   0xbec7..0xbf08 + bf09 + bf0c / bf10 / bf15 -> lib_get_le_value. Users: 1000, 1e55, 72b0 @0x74b3, 3e68 (4116,
 *     433c, 44d9), 813c (8163, 8178, 83aa), b84b (b86f). The users of 0x011b enter at bf0c (without their
 *     MOV DPTR,#011b) because Keil built the long bec7 block (2 users). The chain step in 3e68
 *     'run_bytes += cluster_bytes; run_cluster = next_cluster; next_cluster = lib_get_le_value(...)' (0x433c /
 *     0x44d9) is what Keil puts into block 0xbec7. 813c and b84b enter at bf15 (L? labels are module-local, so they
 *     must be members).
 *   A local of a caller that appears in a block is found by its name in the one function of the module that has
 *     it: the locals of 3e68, 813c and b84b carry names no other function of this file uses.
 *   0xdf2d (arguments from fwupd_walk_position, DPTR = 0x03f7) + 0xdf44 (load an int @DPTR) -> fwupd_store_entry_pos.
 *
 * Source forms the exact build depends on:
 *   - Object layouts: struct fwupd_pos @0x0117 {long; int}, struct fwupd_geometry @0x0429 {char; int},
 *     struct ntfs_run @0x010d {int; long}, struct fwupd_walk_pos @0x03f2 {long; char; int; long; long}: the firmware
 *     walks 011a->011b, 0429->042a, 010e->010f and 03f5->03f6 with INC DPTR; with separate externs the df50 block is
 *     2 B longer and 1000 is not exact.
 *   - Locals of 1e55 are declared in the firmware's XDATA order (i 08eb, k 08ed, entry_pos 08ef, entries_left 08f1,
 *     name_part 08f2, dir_sector 08f3, entry_len 08f4, name_len 08f6, walk_cluster 08f7, walk_fat_sector 08fb,
 *     walk_fat_offset 08ff, rec_sector 0903; ch is a register local); 3e68's in its order (cluster_bytes 08fe,
 *     run_cluster 0902, next_cluster 0906, read_sector 090a, run_bytes 090e, dest 0912, fat_first 0916,
 *     fat_buf_sector 091a, fat_entry_pos 091e).
 *   - Keil loads the RIGHT operand of 'g1 + g2' (two globals) first, so the firmware's "0105 loaded first" is
 *     'fwupd_data_start_sector + fwupd_volume_start_sector'.
 *   - 3e68: 'if ((run_bytes & 0x1ff) != 0)' gives ?C?ULCMP (a bare 'if (run_bytes & 0x1ff)' gives ORL);
 *     'run_bytes += -COPY_PIECE_BYTES' gives ADD #0FFFFC000.
 *   - b84b: the exFAT test is written '!(fwupd_fs_type ^ FS_EXFAT)': the firmware has XRL #1 / MOV DPTR / JNZ,
 *     '== 1' gives CJNE. 'fwupd_entry_first_sector += fwupd_volume_start_sector' is written in BOTH arms: Keil
 *     cross-jumps the two arm tails and keeps the firmware's 'LCALL ?C?LSTXDATA; RET' at 0xb976; one shared += after
 *     the if/else gives LJMP.
 *   - 872e: the ((name_end - 2) & 0x1f) test is written twice; an int local keeps name_end - 2 alive and costs 8 B.
 *   - 1e55 loop tails: the two end-of-loop 'fwupd_dir_entry_offset += DIR_ENTRY_BYTES' statements (firmware 0x2208,
 *     0x2b52, 14 B each) keep their code inline + LCALL 7263. They are the else branches of the entry-type tests
 *     ('if (type == 0x85) {...} else ...;' and 'if (type != 0xE5) {...} else ...;'); the if/else join at the
 *     fwupd_fat_step_cluster call keeps Keil from folding them into the 72b0 block. The directory loops test the end
 *     mark as 'if (entry != 0) {...} else break;'.
 */

/* File system of the mounted volume (fwupd_fs_type, set by fwupd_mount_volume). */
#define FS_FAT                  0
#define FS_EXFAT                1
#define FS_NTFS                 2

/* FAT and exFAT directories: 0x20-byte entries; an entry whose first byte is 0 ends the directory. */
#define DIR_ENTRY_BYTES         0x20
#define DIR_ENTRY_ATTR          0x0b    /* FAT: offset of the attribute byte */
#define DIR_ENTRY_SKIPPED       0xe5    /* FAT: first byte of an entry the walk passes over */
#define FAT_ATTR_LONG_NAME      0x0f    /* FAT: attribute of a long-name entry */
#define LONG_NAME_COUNT_MASK    0x3f    /* FAT: number of long-name entries, in their first byte */
#define EXFAT_ENTRY_SET_FIRST   0x85    /* exFAT: first entry of a set; byte +1 = entries that follow */
#define EXFAT_NAME_CHARS        0x0f    /* exFAT: name characters per name entry (2 bytes each) */
#define NO_FAT_CHAIN_FLAG       0x02    /* exFAT: flag bit of the entry after the 0x85 entry */

/* FAT chain values (32-bit FAT entries, upper 4 bits ignored). */
#define FAT_ENTRY_MASK          0x0fffffff
#define FAT_CHAIN_LAST          0x0fffffff  /* fwupd_fat_step_cluster: end of the directory's chain */
#define FAT_CHAIN_END           0x0ffffff8  /* fwupd_copy_file_to_dram: the copy stops at this value or above */

/* NTFS: attribute types the walks look for; each MFT record is 2 sectors long. */
#define NTFS_ATTR_FILE_NAME     0x30    /* holds the name that is listed */
#define NTFS_ATTR_DATA          0x80    /* holds the data runs of the file */
#define NTFS_ATTR_INDEX_ROOT    0x90
#define NTFS_ATTR_INDEX_ALLOC   0xa0
#define MFT_RECORD_SECTORS      2
#define MFT_FIRST_ATTR_AT       0x14    /* record byte: offset of the first attribute */
#define NTFS_ATTR_LENGTH_AT     4       /* attribute byte: length (only its first byte is read) */
#define NTFS_ATTR_NAME_LEN_AT   9       /* attribute byte: length of the attribute's name in characters */
#define INDEX_ENTRY_LENGTH_AT   8       /* index entry byte: length of the entry */

/* The listed name. */
#define NAME_BUF_BYTES          0x2d    /* size of fwupd_entry_name */
#define NAME_LAST_INDEX         0x2c
#define NAME_PAD_BLANK          0x20    /* FAT 8.3 names: blanks are left out of the printed name */
#define FMT_NAME_LINE           0xe0a3  /* CODE address of "%s\r\n" */
#define FMT_DATA_CLUSTER        0xe08c  /* CODE address of "DataCluster = 0x%8lx\r\n" */

/* File copy. */
#define COPY_PIECE_BYTES        0x4000  /* largest single read of fwupd_copy_file_to_dram */
#define COPY_ROUND_BYTES        0x200   /* the last piece of a run is rounded up to this */

/* Read cursor of the block reader: a disk address (sectors from the volume start) and a byte offset in it. */
struct fwupd_pos { unsigned long sector; unsigned int offset; };
extern struct fwupd_pos xdata fwupd_saved_position;
extern unsigned char xdata fwupd_fs_type;
extern unsigned long xdata fwupd_entry_cluster;
extern unsigned long xdata fwupd_entry_sector;
extern unsigned long xdata fwupd_entry_offset;     /* byte offset of the remembered entry in its sector */
/* 0x0429: sector of the directory walk within its cluster (fwupd_reset_file_position clears it,
 * fwupd_restore_walk_position restores it); 0x042a: bytes per sector of the volume (set by fwupd_mount_volume and
 * fwupd_find_update_file). */
struct fwupd_geometry { unsigned char dir_sector; unsigned int bytes_per_sector; };
extern struct fwupd_geometry xdata fwupd_dir_sector;
extern unsigned long xdata fwupd_ntfs_record_number;     /* NTFS: MFT record number of the entry listed last */
extern unsigned long xdata fwupd_data_start_sector;
extern unsigned long xdata fwupd_volume_start_sector;
extern unsigned long xdata fwupd_ntfs_mft_sector;
extern unsigned int xdata fwupd_sectors_per_cluster;
extern unsigned long xdata fwupd_buffer_sector;
extern unsigned char xdata fwupd_sector_buffer[];
extern void usb_disk_read_to_xdata(unsigned long addr, unsigned char *buf, unsigned long n);
extern void fwupd_seek_block_offset(unsigned long sector, unsigned int offset);
extern unsigned char xdata fwupd_ntfs_run_bytes;
extern unsigned char xdata fwupd_ntfs_run_count;     /* NTFS: number of data runs in fwupd_ntfs_run_list */
extern unsigned char xdata fwupd_ntfs_run_list[];

/* fwupd_ntfs_read_data_runs: copy the NTFS data-run list that starts at (rec_sector, offset) into
 * fwupd_ntfs_run_list, one byte per cursor move, and count the runs in fwupd_ntfs_run_count. Each run starts with a header
 * byte: low nibble = size of the length field, high nibble = size of the offset field; a header of 0 ends the list.
 * Callers: fwupd_ntfs_open_index_alloc. */
void fwupd_ntfs_read_data_runs(unsigned long rec_sector, unsigned int offset)
{
    unsigned char j;
    unsigned char len_size;
    unsigned char ofs_size;
    fwupd_ntfs_run_bytes = 0;
    fwupd_ntfs_run_count = 0;
    fwupd_seek_block_offset(rec_sector, offset);
    while (fwupd_sector_buffer[fwupd_saved_position.offset] != 0) {
        len_size = fwupd_sector_buffer[fwupd_saved_position.offset] & 0x0f;
        ofs_size = (fwupd_sector_buffer[fwupd_saved_position.offset] & 0xf0) >> 4;
        /* header byte + length field + offset field */
        for (j = 0; j < len_size + ofs_size + 1; j++) {
            fwupd_seek_block_offset(rec_sector, offset + j);
            fwupd_ntfs_run_list[fwupd_ntfs_run_bytes] = fwupd_sector_buffer[fwupd_saved_position.offset];
            fwupd_ntfs_run_bytes++;
        }
        offset += len_size + ofs_size + 1;
        fwupd_seek_block_offset(rec_sector, offset);
        fwupd_ntfs_run_count++;
    }
}

void fwupd_seek_block_offset(unsigned long sector, unsigned int offset);
void fwupd_take_file_entry(unsigned int entry);

/* fwupd_set_target_file: make the directory entry listed last the update file (port command 0x48; the caller,
 * fwupd_step_port_state, prints "File_SetTargetFilePara!" afterwards).
 *
 * Phases:
 *   NTFS:        1. read the MFT record of the entry listed last (record number fwupd_ntfs_record_number);
 *                2. walk its attributes, from the offset at record byte 0x14, to the data attribute (type 0x80);
 *                3. fwupd_take_file_entry(offset of that attribute).
 *   FAT / exFAT: 1. read again the directory sector of the entry remembered by fwupd_store_entry_pos during
 *                   the listing (cluster fwupd_entry_cluster, sector fwupd_entry_sector);
 *                2. fwupd_take_file_entry(the entry's byte offset, fwupd_entry_offset).
 * fwupd_take_file_entry then holds the file's first cluster, size and first sector for the copy. */
void fwupd_set_target_file(void)
{
    unsigned int attr_offset;
    unsigned long rec_sector;
    if (fwupd_fs_type == FS_NTFS) {
        /* Phase 1: read the MFT record. */
        rec_sector = fwupd_ntfs_record_number * MFT_RECORD_SECTORS + fwupd_ntfs_mft_sector;
        usb_disk_read_to_xdata(fwupd_volume_start_sector + rec_sector, fwupd_sector_buffer, fwupd_dir_sector.bytes_per_sector);
        /* Phase 2: first attribute, then attribute by attribute to the data attribute. */
        attr_offset = 0;
        fwupd_seek_block_offset(rec_sector, attr_offset + MFT_FIRST_ATTR_AT);
        attr_offset = fwupd_sector_buffer[fwupd_saved_position.offset];
        fwupd_seek_block_offset(rec_sector, attr_offset);
        while (fwupd_sector_buffer[fwupd_saved_position.offset] != NTFS_ATTR_DATA) {
            attr_offset += fwupd_sector_buffer[fwupd_saved_position.offset + NTFS_ATTR_LENGTH_AT];
            fwupd_seek_block_offset(rec_sector, attr_offset);
        }
        /* Phase 3 */
        fwupd_take_file_entry(attr_offset);
    } else {
        /* Phase 1: the remembered directory sector. */
        usb_disk_read_to_xdata((fwupd_entry_cluster - 2) * fwupd_sectors_per_cluster + (fwupd_data_start_sector + fwupd_volume_start_sector) + fwupd_entry_sector,
                      fwupd_sector_buffer, fwupd_dir_sector.bytes_per_sector);
        /* Phase 2 */
        fwupd_take_file_entry((unsigned int)fwupd_entry_offset);
    }
}

void fwupd_copy_file_to_dram(void);
extern void fwupd_build_record_table(void);

/* fwupd_load_file_to_dram: port command 0x46 (the caller prints "CMD_LOADFILE2DRAM"). The same two phases as
 * fwupd_set_target_file select the entry listed last; then the file is copied (fwupd_copy_file_to_dram) and its
 * record table read (fwupd_build_record_table). Returns 1 in every case. */
bit fwupd_load_file_to_dram(void)
{
    unsigned int attr_offset;
    unsigned long rec_sector;
    bit ok;
    if (fwupd_fs_type == FS_NTFS) {
        rec_sector = fwupd_ntfs_record_number * MFT_RECORD_SECTORS + fwupd_ntfs_mft_sector;
        usb_disk_read_to_xdata(fwupd_volume_start_sector + rec_sector, fwupd_sector_buffer, fwupd_dir_sector.bytes_per_sector);
        attr_offset = 0;
        fwupd_seek_block_offset(rec_sector, attr_offset + MFT_FIRST_ATTR_AT);
        attr_offset = fwupd_sector_buffer[fwupd_saved_position.offset];
        fwupd_seek_block_offset(rec_sector, attr_offset);
        while (fwupd_sector_buffer[fwupd_saved_position.offset] != NTFS_ATTR_DATA) {
            attr_offset += fwupd_sector_buffer[fwupd_saved_position.offset + NTFS_ATTR_LENGTH_AT];
            fwupd_seek_block_offset(rec_sector, attr_offset);
        }
        fwupd_take_file_entry(attr_offset);
    } else {
        usb_disk_read_to_xdata((fwupd_entry_cluster - 2) * fwupd_sectors_per_cluster + (fwupd_data_start_sector + fwupd_volume_start_sector) + fwupd_entry_sector,
                      fwupd_sector_buffer, fwupd_dir_sector.bytes_per_sector);
        fwupd_take_file_entry((unsigned int)fwupd_entry_offset);
    }
    fwupd_copy_file_to_dram();
    ok = 1;
    fwupd_build_record_table();
    return ok;
}

extern unsigned long xdata fwupd_ntfs_index_sector;     /* NTFS: sector of the index entry to list next */
extern unsigned int xdata fwupd_ntfs_index_offset;      /* NTFS: byte offset of that index entry */
extern unsigned char xdata fwupd_dir_entry_count;
extern void fwupd_restore_walk_position(void);
extern unsigned int xdata DAT_EXTMEM_08f4, DAT_EXTMEM_08f6;
extern unsigned char xdata fwupd_mft_first_attr_offset;     /* byte 0x14 of fwupd_sector_buffer (0x01e6 + 0x14) */
extern unsigned char xdata fwupd_ntfs_run_index;     /* NTFS: data run of the index being listed */
/* NTFS: the current data run; run_clusters = its length field, run_start = the sum of the offset fields of
 * runs 0..n (fwupd_ntfs_run_length / fwupd_ntfs_run_offset). */
struct ntfs_run { unsigned int run_clusters; unsigned long run_start; };
extern struct ntfs_run xdata fwupd_ntfs_run;
extern unsigned long fwupd_ntfs_run_length(unsigned char c);
extern unsigned long fwupd_ntfs_run_offset(unsigned char c);

/* fwupd_ntfs_open_index_alloc: in the MFT record 10 sectors past the MFT start, find the index allocation
 * attribute (0xA0), copy its data runs, read the first sector of the run fwupd_ntfs_run_index and move the cursor to the
 * index entry whose offset that sector holds at +0x18 (counted from +0x18). Callers: the NTFS arms of
 * fwupd_list_next_dir_entry and fwupd_list_next_img_entry, while fwupd_ntfs_in_index_alloc is clear (fwupd_reset_file_position
 * clears it). */
void fwupd_ntfs_open_index_alloc(void)
{
    unsigned int offset;
    unsigned long sector;
    for (offset = 0; offset < 0x80; offset++) fwupd_ntfs_run_list[offset] = 0;
    sector = fwupd_ntfs_mft_sector + 10;
    usb_disk_read_to_xdata(fwupd_volume_start_sector + sector, fwupd_sector_buffer, fwupd_dir_sector.bytes_per_sector);
    /* Walk the attributes to the index allocation attribute. */
    offset = fwupd_mft_first_attr_offset;
    fwupd_seek_block_offset(sector, offset);
    while (fwupd_sector_buffer[fwupd_saved_position.offset] != NTFS_ATTR_INDEX_ALLOC) {
        offset += fwupd_sector_buffer[offset + NTFS_ATTR_LENGTH_AT];
        fwupd_seek_block_offset(sector, offset);
    }
    /* Skip the attribute header and its name (2 bytes per character) to the data runs. */
    fwupd_seek_block_offset(sector, offset + NTFS_ATTR_NAME_LEN_AT);
    offset += fwupd_sector_buffer[fwupd_saved_position.offset] * 2 + 0x40;
    fwupd_seek_block_offset(sector, offset);
    fwupd_ntfs_read_data_runs(fwupd_saved_position.sector, fwupd_saved_position.offset);
    fwupd_ntfs_run.run_clusters = fwupd_ntfs_run_length(fwupd_ntfs_run_index);
    fwupd_ntfs_run.run_start = fwupd_ntfs_run_offset(fwupd_ntfs_run_index);
    /* First sector of the run; the first index entry lies at +0x18 + (the value at +0x18). */
    sector = fwupd_ntfs_run.run_start * fwupd_sectors_per_cluster + fwupd_dir_sector.dir_sector;
    offset = 0;
    usb_disk_read_to_xdata(fwupd_volume_start_sector + sector, fwupd_sector_buffer, fwupd_dir_sector.bytes_per_sector);
    fwupd_seek_block_offset(sector, offset + 0x18);
    offset = fwupd_sector_buffer[fwupd_saved_position.offset] + 0x18;
    fwupd_seek_block_offset(sector, offset);
    fwupd_restore_walk_position();
}

/* fwupd_ntfs_open_index_root: in the MFT record 10 sectors past the MFT start, find the index root attribute
 * (0x90) and move the cursor 0x18 + 2 * (name length) + 0x20 bytes into it; fwupd_restore_walk_position then copies
 * the cursor into fwupd_ntfs_index_sector / fwupd_ntfs_index_offset, where the NTFS listing starts. Caller: fwupd_mount_volume. */
void fwupd_ntfs_open_index_root(void)
{
    unsigned int offset;
    unsigned long sector;
    sector = fwupd_ntfs_mft_sector + 10;
    usb_disk_read_to_xdata(fwupd_volume_start_sector + sector, fwupd_sector_buffer, fwupd_dir_sector.bytes_per_sector);
    offset = fwupd_mft_first_attr_offset;
    fwupd_seek_block_offset(sector, offset);
    while (fwupd_sector_buffer[fwupd_saved_position.offset] != NTFS_ATTR_INDEX_ROOT) {
        offset += fwupd_sector_buffer[offset + NTFS_ATTR_LENGTH_AT];
        fwupd_seek_block_offset(sector, offset);
    }
    fwupd_seek_block_offset(sector, offset + NTFS_ATTR_NAME_LEN_AT);
    offset += fwupd_sector_buffer[fwupd_saved_position.offset] * 2 + 0x18;
    fwupd_seek_block_offset(sector, offset);
    offset += 0x10;
    fwupd_seek_block_offset(sector, offset);
    offset += 0x10;
    fwupd_seek_block_offset(sector, offset);
    fwupd_restore_walk_position();
}

extern bit fwupd_dir_end_reached;    /* end of the directory reached: the listers return 0 at once */
extern bit fwupd_ntfs_in_index_alloc;    /* NTFS: the listing has moved from the index root to the index allocation */
unsigned long lib_get_le_value(unsigned char *bytes, unsigned char count);
extern unsigned long xdata fwupd_dir_cluster;
extern unsigned long xdata fwupd_fat_entry_offset;
extern unsigned long xdata fwupd_fat_entry_sector;
extern unsigned int xdata fwupd_dir_entry_offset;
extern unsigned char xdata fwupd_entry_name[];
/* Position of the FAT / exFAT directory walk: the arguments fwupd_fat_step_cluster ends with (it stores them here);
 * fwupd_restore_walk_position copies them back into fwupd_dir_cluster, fwupd_dir_sector.dir_sector,
 * fwupd_dir_entry_offset, fwupd_fat_entry_sector and fwupd_fat_entry_offset. */
struct fwupd_walk_pos {
    unsigned long cluster;      /* cluster of the directory */
    unsigned char sector;       /* sector within that cluster */
    unsigned int offset;        /* byte offset within that sector */
    unsigned long fat_sector;   /* FAT sector holding the cluster's entry, counted from the FAT start */
    unsigned long fat_offset;   /* byte offset of that entry */
};
extern struct fwupd_walk_pos xdata fwupd_walk_position;
extern void fwupd_store_entry_pos_entry1(void);
void fwupd_store_entry_pos(unsigned long cluster, unsigned char sector, unsigned int offset);
extern void lib_printf517(void *fmt, ...) large;
bit fwupd_fat_step_cluster(unsigned long cluster, unsigned char sector, unsigned int offset,
                           unsigned long fat_sector, unsigned long fat_offset);
bit fwupd_test_exfat_img_name(unsigned int name_end, unsigned char dir_sector);
extern bit fwupd_test_ntfs_img_name(unsigned long sector, unsigned int offset, unsigned char name_len);

/* fwupd_list_next_img_entry: port command 0x45. List the next directory entry of the USB disk whose name ends in
 * .IMG (FAT: extension "IMG"), print its name with "%s\r\n" and remember it for fwupd_set_target_file /
 * fwupd_load_file_to_dram. Returns 1 when an entry was listed, 0 at the end of the directory.
 * It is fwupd_list_next_dir_entry with a name filter in each arm; the phases are the same:
 *   0. Return 0 when the end was reached before (fwupd_dir_end_reached); clear the name buffer.
 *   exFAT: 1. read the current directory sector; 2. walk the entries: 0 ends the walk; a set that starts with
 *          0x85: find the end of the name in the set's last entry and test it for ".IMG"
 *          (fwupd_test_exfat_img_name); on a match remember the set's second entry (fwupd_store_entry_pos), copy up
 *          to 3 name entries, print, step past the set, count it and return 1; else skip the whole set;
 *          3. step to the next entry (fwupd_fat_step_cluster); the end of the chain ends the walk.
 *   NTFS:  1. at the cursor (fwupd_ntfs_index_sector / fwupd_ntfs_index_offset): when the first 8 bytes are 0 the first time, open
 *          the index allocation (fwupd_ntfs_open_index_alloc); when they are 0 again, move to the next data run;
 *          2. per index entry: read its MFT record, walk to the file name attribute (0x30) and test the name
 *          (fwupd_test_ntfs_img_name); on a match copy the name, print, count, step past the entry and return 1;
 *          else step past it and test the next; 3. no entry left: set fwupd_dir_end_reached, return 0.
 *   FAT:   1. read the current directory sector; 2. walk: 0 ends; 0xE5 skipped; a long-name set whose short entry
 *          has the extension "IMG": remember the short entry, copy up to 3 long-name entries, print, step past the
 *          set, count, return 1 (other long-name sets are skipped whole); a short entry with extension "IMG": copy its
 *          8 name bytes, print, count, return 1; 3. step to the next entry as for exFAT. */
unsigned char fwupd_list_next_img_entry(void)
{
    unsigned int i;
    unsigned int k;
    unsigned int entry_pos;
    unsigned char entries_left;
    unsigned char name_part;
    unsigned char dir_sector;
    unsigned int entry_len;
    unsigned char name_len;
    unsigned long walk_cluster;
    unsigned long walk_fat_sector;
    unsigned long walk_fat_offset;
    unsigned long rec_sector;
    /* Phase 0 */
    if (fwupd_dir_end_reached) return 0;
    for (k = 0; k < NAME_BUF_BYTES; k++) fwupd_entry_name[k] = 0;
    if (fwupd_fs_type == FS_EXFAT) {
        /* exFAT phase 1: the current directory sector. */
        usb_disk_read_to_xdata((fwupd_dir_cluster - 2) * fwupd_sectors_per_cluster + (fwupd_data_start_sector + fwupd_volume_start_sector) + fwupd_dir_sector.dir_sector,
                      fwupd_sector_buffer, fwupd_dir_sector.bytes_per_sector);
        /* exFAT phase 2: the entry walk. */
        for (;;) {
            if (fwupd_sector_buffer[fwupd_dir_entry_offset] != 0) {
                if (fwupd_sector_buffer[fwupd_dir_entry_offset] == EXFAT_ENTRY_SET_FIRST) {
                    entries_left = fwupd_sector_buffer[fwupd_dir_entry_offset + 1];
                    dir_sector = fwupd_dir_sector.dir_sector;
                    walk_cluster = fwupd_dir_cluster;
                    entry_pos = entries_left * DIR_ENTRY_BYTES + fwupd_dir_entry_offset;
                    walk_fat_sector = fwupd_fat_entry_sector;
                    walk_fat_offset = fwupd_fat_entry_offset;
                    /* To the last entry of the set; find the last name character in it (2-byte steps from +2,
                     * not past the entry's end). */
                    fwupd_fat_step_cluster(walk_cluster, dir_sector, entry_pos, walk_fat_sector, walk_fat_offset);
                    while (fwupd_sector_buffer[fwupd_walk_position.offset + 2] != 0) {
                        fwupd_walk_position.offset += 2;
                        if ((fwupd_walk_position.offset & 0x1f) == 0) { fwupd_walk_position.offset -= 2; break; }
                    }
                    if (fwupd_test_exfat_img_name(fwupd_walk_position.offset, dir_sector)) {
                    /* A .IMG file: remember the set's second entry, then copy the name entries (from the third). */
                    name_part = 0;
                    entry_pos = fwupd_dir_entry_offset + DIR_ENTRY_BYTES;
                    fwupd_fat_step_cluster(walk_cluster, dir_sector, entry_pos, walk_fat_sector, walk_fat_offset);
                    fwupd_store_entry_pos(fwupd_walk_position.cluster, fwupd_walk_position.sector, fwupd_walk_position.offset);
                    entry_pos = fwupd_dir_entry_offset + 0x40;
                    fwupd_fat_step_cluster(walk_cluster, dir_sector, entry_pos, walk_fat_sector, walk_fat_offset);
                    do {
                        /* first byte of each 2-byte character */
                        for (k = 0; k != EXFAT_NAME_CHARS; k++)
                            fwupd_entry_name[name_part * EXFAT_NAME_CHARS + k] = fwupd_sector_buffer[k * 2 + fwupd_walk_position.offset + 2];
                        fwupd_walk_position.offset += DIR_ENTRY_BYTES;
                        fwupd_fat_step_cluster(fwupd_walk_position.cluster, fwupd_walk_position.sector, fwupd_walk_position.offset, fwupd_walk_position.fat_sector, fwupd_walk_position.fat_offset);
                        entries_left--;
                        name_part++;
                        /* The buffer holds 3 name entries; count the rest for the step below. */
                        if (name_part > 2) { name_part += entries_left - 1; break; }
                    } while (entries_left - 1 != 0);
                    lib_printf517((void code *)FMT_NAME_LINE, (char *)fwupd_entry_name);
                    /* past the 0x85 entry, the second entry and the name entries */
                    fwupd_dir_entry_offset += (name_part + 2) * DIR_ENTRY_BYTES;
                    fwupd_dir_end_reached = fwupd_fat_step_cluster(fwupd_dir_cluster, fwupd_dir_sector.dir_sector, fwupd_dir_entry_offset, fwupd_fat_entry_sector, fwupd_fat_entry_offset);
                    fwupd_restore_walk_position();
                    fwupd_dir_entry_count++;
                    return 1;
                    }
                    /* not .IMG: skip the whole set */
                    fwupd_dir_entry_offset += (entries_left + 1) * DIR_ENTRY_BYTES;
                } else {
                    fwupd_dir_entry_offset += DIR_ENTRY_BYTES;
                }
                /* exFAT phase 3: next entry; the end of the chain ends the walk. */
                fwupd_dir_end_reached = fwupd_fat_step_cluster(fwupd_dir_cluster, fwupd_dir_sector.dir_sector, fwupd_dir_entry_offset, fwupd_fat_entry_sector, fwupd_fat_entry_offset);
                fwupd_restore_walk_position();
                if (fwupd_dir_end_reached) return 0;
            } else
                break;
        }
        return 0;
    } else if (fwupd_fs_type == FS_NTFS) {
        /* NTFS phase 1: at the end of the index root, open the index allocation once ... */
        fwupd_seek_block_offset(fwupd_ntfs_index_sector, fwupd_ntfs_index_offset);
        if (!fwupd_ntfs_in_index_alloc) {
            if (lib_get_le_value(fwupd_sector_buffer + fwupd_saved_position.offset, 4) == 0) {
                if (lib_get_le_value(fwupd_sector_buffer + 4 + fwupd_saved_position.offset, 4) == 0) {
                    fwupd_ntfs_open_index_alloc();
                    fwupd_ntfs_in_index_alloc = 1;
                }
            }
        }
        /* ... and at its end, go on with the next data run. */
        if (lib_get_le_value(fwupd_sector_buffer + fwupd_saved_position.offset, 4) == 0) {
            if (lib_get_le_value(fwupd_sector_buffer + 4 + fwupd_saved_position.offset, 4) == 0) {
                if (fwupd_ntfs_run_index < fwupd_ntfs_run_count - 1) {
                    fwupd_ntfs_run_index++;
                    if (fwupd_ntfs_run_index < fwupd_ntfs_run_count) {
                        fwupd_ntfs_run.run_clusters = fwupd_ntfs_run_length(fwupd_ntfs_run_index);
                        fwupd_ntfs_run.run_start = 0;
                        fwupd_dir_sector.dir_sector = 0;
                        for (i = 0; i < fwupd_ntfs_run_index + 1; i++) fwupd_ntfs_run.run_start += fwupd_ntfs_run_offset((unsigned char)i);
                    }
                    rec_sector = fwupd_ntfs_run.run_start * fwupd_sectors_per_cluster + fwupd_dir_sector.dir_sector;
                    i = 0;
                    usb_disk_read_to_xdata(fwupd_volume_start_sector + rec_sector, fwupd_sector_buffer, fwupd_dir_sector.bytes_per_sector);
                    fwupd_seek_block_offset(rec_sector, i + 0x18);
                    i = fwupd_sector_buffer[fwupd_saved_position.offset] + 0x18;
                    fwupd_seek_block_offset(rec_sector, i);
                    fwupd_restore_walk_position();
                }
            }
        }
        /* NTFS phase 2: index entries until one has a .IMG name. */
        while ((lib_get_le_value(fwupd_sector_buffer + fwupd_saved_position.offset, 4) != 0 ||
                lib_get_le_value(fwupd_sector_buffer + 4 + fwupd_saved_position.offset, 4) != 0) && fwupd_ntfs_run_index < fwupd_ntfs_run_count) {
            fwupd_ntfs_record_number = lib_get_le_value(fwupd_sector_buffer + fwupd_saved_position.offset, 4);
            fwupd_seek_block_offset(fwupd_ntfs_index_sector, fwupd_ntfs_index_offset + INDEX_ENTRY_LENGTH_AT);
            entry_len = fwupd_sector_buffer[fwupd_saved_position.offset];
            /* The entry's MFT record; i = offset in it. Walk to the file name attribute. */
            rec_sector = fwupd_ntfs_record_number * MFT_RECORD_SECTORS + fwupd_ntfs_mft_sector;
            usb_disk_read_to_xdata(fwupd_volume_start_sector + rec_sector, fwupd_sector_buffer, fwupd_dir_sector.bytes_per_sector);
            i = fwupd_mft_first_attr_offset;
            fwupd_seek_block_offset(rec_sector, i);
            while (fwupd_sector_buffer[fwupd_saved_position.offset] != NTFS_ATTR_FILE_NAME) {
                i += fwupd_sector_buffer[i + NTFS_ATTR_LENGTH_AT];
                fwupd_seek_block_offset(rec_sector, i);
            }
            /* Skip the attribute header (0x18 + 2 per character of its name), then 0x40 more: the name length;
             * the name's 2-byte characters follow 2 bytes later. */
            fwupd_seek_block_offset(rec_sector, i + NTFS_ATTR_NAME_LEN_AT);
            name_len = fwupd_sector_buffer[fwupd_saved_position.offset];
            i += name_len * 2 + 0x18;
            fwupd_seek_block_offset(rec_sector, i);
            i += 0x40;
            fwupd_seek_block_offset(rec_sector, i);
            name_len = fwupd_sector_buffer[fwupd_saved_position.offset];
            i += 2;
            fwupd_seek_block_offset(rec_sector, i);
            if (fwupd_test_ntfs_img_name(rec_sector, i, name_len)) {
                /* first byte of each character, at most NAME_BUF_BYTES */
                for (k = 0; k < name_len; k++) {
                    fwupd_seek_block_offset(rec_sector, i + k * 2);
                    fwupd_entry_name[k] = fwupd_sector_buffer[fwupd_saved_position.offset];
                    if (k == NAME_LAST_INDEX) break;
                }
                lib_printf517((void code *)FMT_NAME_LINE, (char *)fwupd_entry_name);
                fwupd_dir_entry_count++;
                fwupd_ntfs_index_offset += entry_len;
                fwupd_seek_block_offset(fwupd_ntfs_index_sector, fwupd_ntfs_index_offset);
                fwupd_restore_walk_position();
                return 1;
            }
            /* not .IMG: on to the next index entry */
            fwupd_ntfs_index_offset += entry_len;
            fwupd_seek_block_offset(fwupd_ntfs_index_sector, fwupd_ntfs_index_offset);
            fwupd_restore_walk_position();
        }
        /* NTFS phase 3 */
        fwupd_dir_end_reached = 1;
        return 0;
    }
    /* FAT phase 1: the current directory sector. */
    usb_disk_read_to_xdata((fwupd_dir_cluster - 2) * fwupd_sectors_per_cluster + (fwupd_data_start_sector + fwupd_volume_start_sector) + fwupd_dir_sector.dir_sector,
                  fwupd_sector_buffer, fwupd_dir_sector.bytes_per_sector);
    /* FAT phase 2: the entry walk. */
    for (;;) {
        if (fwupd_sector_buffer[fwupd_dir_entry_offset] != 0) {
            if (fwupd_sector_buffer[fwupd_dir_entry_offset] != DIR_ENTRY_SKIPPED) {
                if (fwupd_sector_buffer[fwupd_dir_entry_offset + DIR_ENTRY_ATTR] == FAT_ATTR_LONG_NAME) {
                    /* Long-name set: its short entry follows the entries_left long-name entries. */
                    entries_left = fwupd_sector_buffer[fwupd_dir_entry_offset] & LONG_NAME_COUNT_MASK;
                    entry_pos = entries_left * DIR_ENTRY_BYTES + fwupd_dir_entry_offset;
                    dir_sector = fwupd_dir_sector.dir_sector;
                    walk_cluster = fwupd_dir_cluster;
                    walk_fat_sector = fwupd_fat_entry_sector;
                    walk_fat_offset = fwupd_fat_entry_offset;
                    fwupd_fat_step_cluster(walk_cluster, dir_sector, entry_pos, walk_fat_sector, walk_fat_offset);
                    if (fwupd_sector_buffer[fwupd_walk_position.offset + 8] == 'I' && fwupd_sector_buffer[fwupd_walk_position.offset + 9] == 'M' &&
                        fwupd_sector_buffer[fwupd_walk_position.offset + 10] == 'G') {
                    /* Remember the short entry; copy the long-name entries from the one next to it backwards:
                     * characters 1..5 at +1, 6..11 at +0x0e, 12..13 at +0x1c (first byte of each). */
                    fwupd_store_entry_pos(fwupd_walk_position.cluster, fwupd_walk_position.sector, fwupd_walk_position.offset);
                    name_part = 0;
                    do {
                        entries_left--;
                        entry_pos = entries_left * DIR_ENTRY_BYTES + fwupd_dir_entry_offset;
                        fwupd_fat_step_cluster(walk_cluster, dir_sector, entry_pos, walk_fat_sector, walk_fat_offset);
                        for (k = 0; k != 5; k++)
                            fwupd_entry_name[name_part * 0x0d + k] = fwupd_sector_buffer[k * 2 + fwupd_walk_position.offset + 1];
                        for (k = 0; k != 6; k++)
                            fwupd_entry_name[name_part * 0x0d + k + 5] = fwupd_sector_buffer[k * 2 + fwupd_walk_position.offset + 0x0e];
                        for (k = 0; k != 2; k++)
                            fwupd_entry_name[name_part * 0x0d + k + 0x0b] = fwupd_sector_buffer[k * 2 + fwupd_walk_position.offset + 0x1c];
                        name_part++;
                        /* The buffer holds 3 long-name entries; count the rest for the step below. */
                        if (name_part > 2) { name_part += entries_left; break; }
                    } while (entries_left != 0);
                    lib_printf517((void code *)FMT_NAME_LINE, (char *)fwupd_entry_name);
                    /* past the long-name entries and the short entry */
                    fwupd_dir_entry_offset += (name_part + 1) * DIR_ENTRY_BYTES;
                    fwupd_dir_end_reached = fwupd_fat_step_cluster(fwupd_dir_cluster, fwupd_dir_sector.dir_sector, fwupd_dir_entry_offset, fwupd_fat_entry_sector, fwupd_fat_entry_offset);
                    fwupd_restore_walk_position();
                    fwupd_dir_entry_count++;
                    return 1;
                    }
                    /* not "IMG": skip the whole set */
                    fwupd_dir_entry_offset += (entries_left + 1) * DIR_ENTRY_BYTES;
                } else if (fwupd_sector_buffer[fwupd_dir_entry_offset + 8] == 'I' && fwupd_sector_buffer[fwupd_dir_entry_offset + 9] == 'M' &&
                           fwupd_sector_buffer[fwupd_dir_entry_offset + 10] == 'G') {
                    /* Short entry with extension "IMG": remember it, list its 8 name bytes. */
                    fwupd_store_entry_pos(fwupd_dir_cluster, fwupd_dir_sector.dir_sector, fwupd_dir_entry_offset);
                    for (k = 0; k != 8; k++) fwupd_entry_name[k] = fwupd_sector_buffer[fwupd_dir_entry_offset + k];
                    lib_printf517((void code *)FMT_NAME_LINE, (char *)fwupd_entry_name);
                    fwupd_dir_entry_offset += DIR_ENTRY_BYTES;
                    fwupd_dir_end_reached = fwupd_fat_step_cluster(fwupd_dir_cluster, fwupd_dir_sector.dir_sector, fwupd_dir_entry_offset, fwupd_fat_entry_sector, fwupd_fat_entry_offset);
                    fwupd_restore_walk_position();
                    fwupd_dir_entry_count++;
                    return 1;
                } else {
                    fwupd_dir_entry_offset += DIR_ENTRY_BYTES;
                }
            } else {
                fwupd_dir_entry_offset += DIR_ENTRY_BYTES;
            }
            /* FAT phase 3: next entry; the end of the chain ends the walk. */
            fwupd_dir_end_reached = fwupd_fat_step_cluster(fwupd_dir_cluster, fwupd_dir_sector.dir_sector, fwupd_dir_entry_offset, fwupd_fat_entry_sector, fwupd_fat_entry_offset);
            fwupd_restore_walk_position();
            if (fwupd_dir_end_reached) return 0;
        } else
            break;
    }
    return 0;
}

/* fwupd_list_next_dir_entry: port command 0x47. List the next directory entry of the USB disk, print its name with
 * "%s\r\n" and remember it for fwupd_set_target_file / fwupd_load_file_to_dram. Returns 1 when an entry was listed,
 * 0 at the end of the directory (the caller then resets the position with fwupd_reset_file_position).
 * Phases:
 *   0. Return 0 when the end was reached before (fwupd_dir_end_reached); clear the name buffer.
 *   exFAT: 1. read the current directory sector; 2. walk the entries: 0 ends the walk; a set that starts with
 *          0x85: remember its second entry (fwupd_store_entry_pos), copy up to 3 name entries, print, step past
 *          the set, count it, return 1; other entries are passed over; 3. step to the next entry
 *          (fwupd_fat_step_cluster); the end of the chain ends the walk.
 *   NTFS:  1. at the cursor (fwupd_ntfs_index_sector / fwupd_ntfs_index_offset): when the first 8 bytes are 0 the first time, open the
 *          index allocation (fwupd_ntfs_open_index_alloc); when they are 0 again, move to the next data run;
 *          2. when an index entry is there: read its MFT record, walk to the file name attribute (0x30), copy the
 *          name, print, count, step past the entry, return 1; 3. otherwise set fwupd_dir_end_reached, return 0.
 *   FAT:   1. read the current directory sector; 2. walk: 0 ends; 0xE5 passed over; a long-name set: remember its
 *          short entry, copy up to 3 long-name entries, print, step past the set, count, return 1; a short entry:
 *          remember it, copy its 11 name bytes without blanks, print, count, return 1; 3. step as for exFAT. */
unsigned char fwupd_list_next_dir_entry(void)
{
    unsigned int i;
    unsigned int k;
    unsigned int entry_pos;
    unsigned char entries_left;
    unsigned char name_part;
    unsigned char dir_sector;
    unsigned int entry_len;
    unsigned char name_len;
    unsigned long walk_cluster;
    unsigned long walk_fat_sector;
    unsigned long walk_fat_offset;
    unsigned long rec_sector;
    unsigned char ch;
    /* Phase 0 */
    if (fwupd_dir_end_reached) return 0;
    for (k = 0; k < NAME_BUF_BYTES; k++) fwupd_entry_name[k] = 0;
    if (fwupd_fs_type == FS_EXFAT) {
        /* exFAT phase 1: the current directory sector. */
        usb_disk_read_to_xdata((fwupd_dir_cluster - 2) * fwupd_sectors_per_cluster + (fwupd_data_start_sector + fwupd_volume_start_sector) + fwupd_dir_sector.dir_sector,
                      fwupd_sector_buffer, fwupd_dir_sector.bytes_per_sector);
        /* exFAT phase 2: the entry walk. */
        for (;;) {
            if (fwupd_sector_buffer[fwupd_dir_entry_offset] != 0) {
                if (fwupd_sector_buffer[fwupd_dir_entry_offset] == EXFAT_ENTRY_SET_FIRST) {
                    entries_left = fwupd_sector_buffer[fwupd_dir_entry_offset + 1];
                    dir_sector = fwupd_dir_sector.dir_sector;
                    walk_cluster = fwupd_dir_cluster;
                    entry_pos = entries_left * DIR_ENTRY_BYTES + fwupd_dir_entry_offset;
                    walk_fat_sector = fwupd_fat_entry_sector;
                    walk_fat_offset = fwupd_fat_entry_offset;
                    /* To the set's last entry and the end of the name in it, as in fwupd_list_next_img_entry; the
                     * next step call overwrites the position found. */
                    fwupd_fat_step_cluster(walk_cluster, dir_sector, entry_pos, walk_fat_sector, walk_fat_offset);
                    while (fwupd_sector_buffer[fwupd_walk_position.offset + 2] != 0) {
                        fwupd_walk_position.offset += 2;
                        if ((fwupd_walk_position.offset & 0x1f) == 0) { fwupd_walk_position.offset -= 2; break; }
                    }
                    /* Remember the set's second entry, then copy the name entries (from the third). */
                    name_part = 0;
                    entry_pos = fwupd_dir_entry_offset + DIR_ENTRY_BYTES;
                    fwupd_fat_step_cluster(walk_cluster, dir_sector, entry_pos, walk_fat_sector, walk_fat_offset);
                    fwupd_store_entry_pos(fwupd_walk_position.cluster, fwupd_walk_position.sector, fwupd_walk_position.offset);
                    entry_pos = fwupd_dir_entry_offset + 0x40;
                    fwupd_fat_step_cluster(walk_cluster, dir_sector, entry_pos, walk_fat_sector, walk_fat_offset);
                    do {
                        /* first byte of each 2-byte character */
                        for (k = 0; k != EXFAT_NAME_CHARS; k++)
                            fwupd_entry_name[name_part * EXFAT_NAME_CHARS + k] = fwupd_sector_buffer[k * 2 + fwupd_walk_position.offset + 2];
                        fwupd_walk_position.offset += DIR_ENTRY_BYTES;
                        fwupd_fat_step_cluster(fwupd_walk_position.cluster, fwupd_walk_position.sector, fwupd_walk_position.offset, fwupd_walk_position.fat_sector, fwupd_walk_position.fat_offset);
                        entries_left--;
                        name_part++;
                        /* The buffer holds 3 name entries; count the rest for the step below. */
                        if (name_part > 2) { name_part += entries_left - 1; break; }
                    } while (entries_left - 1 != 0);
                    lib_printf517((void code *)FMT_NAME_LINE, (char *)fwupd_entry_name);
                    /* past the 0x85 entry, the second entry and the name entries */
                    fwupd_dir_entry_offset += (name_part + 2) * DIR_ENTRY_BYTES;
                    fwupd_dir_end_reached = fwupd_fat_step_cluster(fwupd_dir_cluster, fwupd_dir_sector.dir_sector, fwupd_dir_entry_offset, fwupd_fat_entry_sector, fwupd_fat_entry_offset);
                    fwupd_restore_walk_position();
                    fwupd_dir_entry_count++;
                    return 1;
                } else
                    fwupd_dir_entry_offset += DIR_ENTRY_BYTES;
                /* exFAT phase 3: next entry; the end of the chain ends the walk. */
                fwupd_dir_end_reached = fwupd_fat_step_cluster(fwupd_dir_cluster, fwupd_dir_sector.dir_sector, fwupd_dir_entry_offset, fwupd_fat_entry_sector, fwupd_fat_entry_offset);
                fwupd_restore_walk_position();
                if (fwupd_dir_end_reached) return 0;
            } else
                break;
        }
        return 0;
    } else if (fwupd_fs_type == FS_NTFS) {
        /* NTFS phase 1: at the end of the index root, open the index allocation once ... */
        fwupd_seek_block_offset(fwupd_ntfs_index_sector, fwupd_ntfs_index_offset);
        if (!fwupd_ntfs_in_index_alloc) {
            if (lib_get_le_value(fwupd_sector_buffer + fwupd_saved_position.offset, 4) == 0) {
                if (lib_get_le_value(fwupd_sector_buffer + 4 + fwupd_saved_position.offset, 4) == 0) {
                    fwupd_ntfs_open_index_alloc();
                    fwupd_ntfs_in_index_alloc = 1;
                }
            }
        }
        /* ... and at its end, go on with the next data run. */
        if (lib_get_le_value(fwupd_sector_buffer + fwupd_saved_position.offset, 4) == 0) {
            if (lib_get_le_value(fwupd_sector_buffer + 4 + fwupd_saved_position.offset, 4) == 0) {
                if (fwupd_ntfs_run_index < fwupd_ntfs_run_count - 1) {
                    fwupd_ntfs_run_index++;
                    if (fwupd_ntfs_run_index < fwupd_ntfs_run_count) {
                        fwupd_ntfs_run.run_clusters = fwupd_ntfs_run_length(fwupd_ntfs_run_index);
                        fwupd_ntfs_run.run_start = 0;
                        fwupd_dir_sector.dir_sector = 0;
                        for (i = 0; i < fwupd_ntfs_run_index + 1; i++) fwupd_ntfs_run.run_start += fwupd_ntfs_run_offset((unsigned char)i);
                    }
                    rec_sector = fwupd_ntfs_run.run_start * fwupd_sectors_per_cluster + fwupd_dir_sector.dir_sector;
                    i = 0;
                    usb_disk_read_to_xdata(fwupd_volume_start_sector + rec_sector, fwupd_sector_buffer, fwupd_dir_sector.bytes_per_sector);
                    fwupd_seek_block_offset(rec_sector, i + 0x18);
                    i = fwupd_sector_buffer[fwupd_saved_position.offset] + 0x18;
                    fwupd_seek_block_offset(rec_sector, i);
                    fwupd_restore_walk_position();
                }
            }
        }
        /* NTFS phase 2: list the index entry at the cursor. */
        if ((lib_get_le_value(fwupd_sector_buffer + fwupd_saved_position.offset, 4) != 0 ||
             lib_get_le_value(fwupd_sector_buffer + 4 + fwupd_saved_position.offset, 4) != 0) && fwupd_ntfs_run_index < fwupd_ntfs_run_count) {
            fwupd_ntfs_record_number = lib_get_le_value(fwupd_sector_buffer + fwupd_saved_position.offset, 4);
            fwupd_seek_block_offset(fwupd_ntfs_index_sector, fwupd_ntfs_index_offset + INDEX_ENTRY_LENGTH_AT);
            entry_len = fwupd_sector_buffer[fwupd_saved_position.offset];
            /* The entry's MFT record; i = offset in it. Walk to the file name attribute. */
            rec_sector = fwupd_ntfs_record_number * MFT_RECORD_SECTORS + fwupd_ntfs_mft_sector;
            usb_disk_read_to_xdata(fwupd_volume_start_sector + rec_sector, fwupd_sector_buffer, fwupd_dir_sector.bytes_per_sector);
            i = fwupd_mft_first_attr_offset;
            fwupd_seek_block_offset(rec_sector, i);
            while (fwupd_sector_buffer[fwupd_saved_position.offset] != NTFS_ATTR_FILE_NAME) {
                i += fwupd_sector_buffer[i + NTFS_ATTR_LENGTH_AT];
                fwupd_seek_block_offset(rec_sector, i);
            }
            /* Skip the attribute header (0x18 + 2 per character of its name), then 0x40 more: the name length;
             * the name's 2-byte characters follow 2 bytes later. */
            fwupd_seek_block_offset(rec_sector, i + NTFS_ATTR_NAME_LEN_AT);
            name_len = fwupd_sector_buffer[fwupd_saved_position.offset];
            i += name_len * 2 + 0x18;
            fwupd_seek_block_offset(rec_sector, i);
            i += 0x40;
            fwupd_seek_block_offset(rec_sector, i);
            name_len = fwupd_sector_buffer[fwupd_saved_position.offset];
            i += 2;
            fwupd_seek_block_offset(rec_sector, i);
            /* first byte of each character, at most NAME_BUF_BYTES */
            for (k = 0; k < name_len; k++) {
                fwupd_seek_block_offset(rec_sector, i + k * 2);
                fwupd_entry_name[k] = fwupd_sector_buffer[fwupd_saved_position.offset];
                if (k == NAME_LAST_INDEX) break;
            }
            lib_printf517((void code *)FMT_NAME_LINE, (char *)fwupd_entry_name);
            fwupd_dir_entry_count++;
            fwupd_ntfs_index_offset += entry_len;
            fwupd_seek_block_offset(fwupd_ntfs_index_sector, fwupd_ntfs_index_offset);
            fwupd_restore_walk_position();
            return 1;
        }
        /* NTFS phase 3 */
        fwupd_dir_end_reached = 1;
        return 0;
    }
    /* FAT phase 1: the current directory sector. */
    usb_disk_read_to_xdata((fwupd_dir_cluster - 2) * fwupd_sectors_per_cluster + (fwupd_data_start_sector + fwupd_volume_start_sector) + fwupd_dir_sector.dir_sector,
                  fwupd_sector_buffer, fwupd_dir_sector.bytes_per_sector);
    /* FAT phase 2: the entry walk. */
    for (;;) {
        if (fwupd_sector_buffer[fwupd_dir_entry_offset] != 0) {
            if (fwupd_sector_buffer[fwupd_dir_entry_offset] != DIR_ENTRY_SKIPPED) {
                if (fwupd_sector_buffer[fwupd_dir_entry_offset + DIR_ENTRY_ATTR] == FAT_ATTR_LONG_NAME) {
                    /* Long-name set: remember its short entry (after the entries_left long-name entries), then
                     * copy the long-name entries from the one next to it backwards: characters 1..5 at +1,
                     * 6..11 at +0x0e, 12..13 at +0x1c (first byte of each). */
                    entries_left = fwupd_sector_buffer[fwupd_dir_entry_offset] & LONG_NAME_COUNT_MASK;
                    entry_pos = entries_left * DIR_ENTRY_BYTES + fwupd_dir_entry_offset;
                    dir_sector = fwupd_dir_sector.dir_sector;
                    walk_cluster = fwupd_dir_cluster;
                    walk_fat_sector = fwupd_fat_entry_sector;
                    walk_fat_offset = fwupd_fat_entry_offset;
                    fwupd_fat_step_cluster(walk_cluster, dir_sector, entry_pos, walk_fat_sector, walk_fat_offset);
                    fwupd_store_entry_pos(fwupd_walk_position.cluster, fwupd_walk_position.sector, fwupd_walk_position.offset);
                    name_part = 0;
                    do {
                        entries_left--;
                        entry_pos = entries_left * DIR_ENTRY_BYTES + fwupd_dir_entry_offset;
                        fwupd_fat_step_cluster(walk_cluster, dir_sector, entry_pos, walk_fat_sector, walk_fat_offset);
                        for (k = 0; k != 5; k++)
                            fwupd_entry_name[name_part * 0x0d + k] = fwupd_sector_buffer[k * 2 + fwupd_walk_position.offset + 1];
                        for (k = 0; k != 6; k++)
                            fwupd_entry_name[name_part * 0x0d + k + 5] = fwupd_sector_buffer[k * 2 + fwupd_walk_position.offset + 0x0e];
                        for (k = 0; k != 2; k++)
                            fwupd_entry_name[name_part * 0x0d + k + 0x0b] = fwupd_sector_buffer[k * 2 + fwupd_walk_position.offset + 0x1c];
                        name_part++;
                        /* The buffer holds 3 long-name entries; count the rest for the step below. */
                        if (name_part > 2) { name_part += entries_left; break; }
                    } while (entries_left != 0);
                    lib_printf517((void code *)FMT_NAME_LINE, (char *)fwupd_entry_name);
                    /* past the long-name entries and the short entry */
                    fwupd_dir_entry_offset += (name_part + 1) * DIR_ENTRY_BYTES;
                    fwupd_dir_end_reached = fwupd_fat_step_cluster(fwupd_dir_cluster, fwupd_dir_sector.dir_sector, fwupd_dir_entry_offset, fwupd_fat_entry_sector, fwupd_fat_entry_offset);
                    fwupd_restore_walk_position();
                    fwupd_dir_entry_count++;
                    return 1;
                }
                /* Short entry: remember it, copy its 11 name bytes without the blanks. */
                fwupd_store_entry_pos(fwupd_dir_cluster, fwupd_dir_sector.dir_sector, fwupd_dir_entry_offset);
                for (k = 0; k < 0x0b; k++) {
                    ch = fwupd_sector_buffer[fwupd_dir_entry_offset + k];
                    if (ch != NAME_PAD_BLANK) fwupd_entry_name[k] = ch;
                }
                lib_printf517((void code *)FMT_NAME_LINE, (char *)fwupd_entry_name);
                fwupd_dir_entry_offset += DIR_ENTRY_BYTES;
                fwupd_dir_end_reached = fwupd_fat_step_cluster(fwupd_dir_cluster, fwupd_dir_sector.dir_sector, fwupd_dir_entry_offset, fwupd_fat_entry_sector, fwupd_fat_entry_offset);
                fwupd_restore_walk_position();
                fwupd_dir_entry_count++;
                return 1;
            } else
                fwupd_dir_entry_offset += DIR_ENTRY_BYTES;
            /* FAT phase 3: next entry; the end of the chain ends the walk. */
            fwupd_dir_end_reached = fwupd_fat_step_cluster(fwupd_dir_cluster, fwupd_dir_sector.dir_sector, fwupd_dir_entry_offset, fwupd_fat_entry_sector, fwupd_fat_entry_offset);
            fwupd_restore_walk_position();
            if (fwupd_dir_end_reached) return 0;
        } else
            break;
    }
    return 0;
}

extern bit fwupd_file_contiguous;    /* the selected file is one contiguous run: no FAT chain is followed */
extern unsigned long xdata fwupd_file_first_cluster;
extern unsigned long xdata fwupd_file_size;
extern unsigned long xdata fwupd_fat_start_sector;
extern void usb_disk_read_to_offset(unsigned long s, unsigned long n, unsigned long dst);

/* fwupd_copy_file_to_dram: copy the selected file (first cluster fwupd_file_first_cluster, fwupd_file_size bytes)
 * from the USB disk with usb_disk_read_to_offset(sector, bytes, destination offset), in reads of at most 0x4000 bytes.
 * Callers: fwupd_load_file_to_dram, fwupd_find_update_file.
 * Phases:
 *   NTFS:        the file is read as one run from sector first cluster * sectors per cluster: 0x4000-byte pieces,
 *                then the rest.
 *   FAT / exFAT: 1. cluster size in bytes; read the FAT entry of the first cluster (none when fwupd_file_contiguous is set:
 *                   next_cluster = FAT_CHAIN_END, so one pass copies the file size, at least 0x200 bytes);
 *                2. per pass: start at the current cluster and add each cluster whose successor is the next number,
 *                   up to 0x4000 bytes, reading FAT sectors as the chain needs them;
 *                3. count the run's last cluster (end of chain, or a jump: then go on at the jump target);
 *                4. read the run in 0x4000-byte pieces, the last one rounded up to 0x200 bytes;
 *                   repeat 2-4 until the chain value reaches FAT_CHAIN_END. */
void fwupd_copy_file_to_dram(void)
{
    unsigned long cluster_bytes;
    unsigned long run_cluster;      /* cluster the current run has reached */
    unsigned long next_cluster;     /* FAT entry of run_cluster */
    unsigned long read_sector;      /* disk sector of the next read */
    unsigned long run_bytes;
    unsigned long dest;             /* destination offset of the next read */
    unsigned long fat_first;        /* disk sector of the FAT's start */
    unsigned long fat_buf_sector;   /* FAT sector held in fwupd_sector_buffer */
    unsigned int fat_entry_pos;     /* byte of the next FAT entry in that sector */
    if (fwupd_fs_type == FS_NTFS) {
        read_sector = fwupd_file_first_cluster * fwupd_sectors_per_cluster + fwupd_volume_start_sector;
        run_bytes = fwupd_file_size;
        dest = 0;
        while (run_bytes > COPY_PIECE_BYTES) {
            usb_disk_read_to_offset(read_sector, COPY_PIECE_BYTES, dest);
            dest += COPY_PIECE_BYTES;
            run_bytes += -COPY_PIECE_BYTES;
            read_sector += COPY_PIECE_BYTES / fwupd_dir_sector.bytes_per_sector;
        }
        usb_disk_read_to_offset(read_sector, run_bytes, dest);
        dest += run_bytes;
    } else {
        /* Phase 1 */
        cluster_bytes = fwupd_dir_sector.bytes_per_sector;
        cluster_bytes = fwupd_sectors_per_cluster * cluster_bytes;
        run_cluster = fwupd_file_first_cluster;
        if (!fwupd_file_contiguous) {
            /* 4 bytes per FAT entry */
            fat_first = fwupd_fat_start_sector + fwupd_volume_start_sector;
            fat_buf_sector = fat_first + run_cluster / (fwupd_dir_sector.bytes_per_sector >> 2);
            usb_disk_read_to_xdata(fat_buf_sector, fwupd_sector_buffer, fwupd_dir_sector.bytes_per_sector);
            fat_entry_pos = run_cluster * 4 % fwupd_dir_sector.bytes_per_sector;
            next_cluster = lib_get_le_value(fwupd_sector_buffer + fat_entry_pos, 4) & FAT_ENTRY_MASK;
        } else {
            next_cluster = FAT_CHAIN_END;
        }
        dest = 0;
        do {
            /* Phase 2: one run of consecutive clusters. */
            if (!fwupd_file_contiguous) {
                run_bytes = 0;
                fat_entry_pos = next_cluster * 4 % fwupd_dir_sector.bytes_per_sector;
            } else {
                if (fwupd_file_size < COPY_ROUND_BYTES) run_bytes = COPY_ROUND_BYTES; else run_bytes = fwupd_file_size;
            }
            read_sector = (run_cluster - 2) * fwupd_sectors_per_cluster;
            read_sector = read_sector + fwupd_data_start_sector + fwupd_volume_start_sector;
            while (run_bytes < COPY_PIECE_BYTES && next_cluster - run_cluster == 1) {
                if (fat_first + next_cluster / (fwupd_dir_sector.bytes_per_sector >> 2) != fat_buf_sector) {
                    fat_buf_sector = fat_first + next_cluster / (fwupd_dir_sector.bytes_per_sector >> 2);
                    usb_disk_read_to_xdata(fat_buf_sector, fwupd_sector_buffer, fwupd_dir_sector.bytes_per_sector);
                }
                run_bytes += cluster_bytes;
                run_cluster = next_cluster;
                next_cluster = lib_get_le_value(fwupd_sector_buffer + fat_entry_pos, 4) & FAT_ENTRY_MASK;
                fat_entry_pos = next_cluster * 4 % fwupd_dir_sector.bytes_per_sector;
            }
            /* Phase 3: the run's last cluster. */
            if (next_cluster > FAT_CHAIN_END) {
                run_bytes += cluster_bytes;
            } else if (next_cluster - run_cluster > 1 && !fwupd_file_contiguous) {
                /* The chain jumps: the next pass starts at the jump target. */
                run_cluster = next_cluster;
                if (fat_first + next_cluster / (fwupd_dir_sector.bytes_per_sector >> 2) != fat_buf_sector) {
                    fat_buf_sector = fat_first + next_cluster / (fwupd_dir_sector.bytes_per_sector >> 2);
                    usb_disk_read_to_xdata(fat_buf_sector, fwupd_sector_buffer, fwupd_dir_sector.bytes_per_sector);
                }
                run_bytes += cluster_bytes;
                run_cluster = next_cluster;
                next_cluster = lib_get_le_value(fwupd_sector_buffer + fat_entry_pos, 4) & FAT_ENTRY_MASK;
            }
            /* Phase 4: read the run. */
            while (run_bytes > COPY_PIECE_BYTES) {
                usb_disk_read_to_offset(read_sector, COPY_PIECE_BYTES, dest);
                dest += COPY_PIECE_BYTES;
                run_bytes += -COPY_PIECE_BYTES;
                read_sector += COPY_PIECE_BYTES / fwupd_dir_sector.bytes_per_sector;
            }
            if ((run_bytes & 0x1ff) != 0) run_bytes = (run_bytes / COPY_ROUND_BYTES + 1) * COPY_ROUND_BYTES;
            usb_disk_read_to_offset(read_sector, run_bytes, dest);
            dest += run_bytes;
        } while (next_cluster < FAT_CHAIN_END);
    }
}

extern unsigned char usb_get_current_port(void);
extern unsigned long xdata fwupd_file_first_sector;
extern unsigned long xdata fwupd_root_cluster;

/* fwupd_take_file_entry: take the file whose entry starts at byte file_entry of fwupd_sector_buffer (NTFS: whose
 * data attribute starts there) as the selected file: fwupd_file_first_cluster, fwupd_file_size, and for FAT / exFAT
 * fwupd_file_first_sector and fwupd_file_contiguous. Callers: fwupd_set_target_file, fwupd_load_file_to_dram,
 * fwupd_find_update_file.
 *   exFAT: size at +0x18, first cluster at +0x14, fwupd_file_contiguous = bit 1 of +1 (fwupd_set_target_file passes the
 *          set's second entry, fwupd_find_update_file the 0x85 entry itself).
 *   NTFS: the byte at +0x40 is a data-run header (low nibble = size of the length field, high nibble = size of the
 *         offset field); the run's length goes to fwupd_ntfs_run.run_clusters, its offset is the first cluster;
 *         size = length * sectors per cluster * bytes per sector.
 *   FAT: first cluster = (word at +0x14) << 16 + word at +0x1a, size at +0x1c, fwupd_file_contiguous = 0.
 * The port number read first is stored and not used (as in fwupd_take_config_entry). */
void fwupd_take_file_entry(unsigned int file_entry)
{
    unsigned char file_port;
    unsigned char run_len_size;
    unsigned char run_ofs_size;
    unsigned long attr_sector;
    file_port = usb_get_current_port();
    if (fwupd_fs_type == FS_EXFAT) {
        fwupd_file_size = lib_get_le_value(fwupd_sector_buffer + file_entry + 0x18, 4);
        fwupd_file_first_cluster = lib_get_le_value(fwupd_sector_buffer + file_entry + 0x14, 4);
        fwupd_file_first_sector = (fwupd_file_first_cluster - 2) * fwupd_sectors_per_cluster + fwupd_data_start_sector;
        fwupd_file_first_sector += fwupd_volume_start_sector;
        if (fwupd_sector_buffer[file_entry + 1] & NO_FAT_CHAIN_FLAG) fwupd_file_contiguous = 1; else fwupd_file_contiguous = 0;
    } else if (fwupd_fs_type == FS_NTFS) {
        attr_sector = fwupd_saved_position.sector;
        fwupd_seek_block_offset(attr_sector, file_entry + 0x40);
        run_len_size = fwupd_sector_buffer[fwupd_saved_position.offset] & 0x0f;
        run_ofs_size = (fwupd_sector_buffer[fwupd_saved_position.offset] & 0xf0) >> 4;
        fwupd_seek_block_offset(attr_sector, file_entry + 0x41);
        fwupd_ntfs_run.run_clusters = lib_get_le_value(fwupd_sector_buffer + fwupd_saved_position.offset, run_len_size);
        fwupd_seek_block_offset(attr_sector, file_entry + 0x41 + run_len_size);
        fwupd_file_first_cluster = lib_get_le_value(fwupd_sector_buffer + fwupd_saved_position.offset, run_ofs_size);
        fwupd_file_size = (unsigned long)fwupd_ntfs_run.run_clusters * fwupd_sectors_per_cluster * fwupd_dir_sector.bytes_per_sector;
    } else {
        fwupd_file_first_cluster = lib_get_le_value(fwupd_sector_buffer + file_entry + 0x14, 2);
        fwupd_file_first_cluster = (fwupd_file_first_cluster << 16) + lib_get_le_value(fwupd_sector_buffer + file_entry + 0x1a, 2);
        fwupd_file_size = lib_get_le_value(fwupd_sector_buffer + file_entry + 0x1c, 4);
        fwupd_file_first_sector = (fwupd_file_first_cluster - fwupd_root_cluster) * fwupd_sectors_per_cluster + fwupd_data_start_sector;
        fwupd_file_first_sector += fwupd_volume_start_sector;
        fwupd_file_contiguous = 0;
    }
}

extern unsigned long xdata fwupd_entry_first_sector;
extern unsigned long xdata fwupd_exfat_heap_offset;
extern unsigned long xdata fwupd_root_cluster;

/* fwupd_take_config_entry: first sector of the file whose directory entry starts at byte config_entry of
 * fwupd_sector_buffer -> fwupd_entry_first_sector (counted from the disk start). Caller: fwupd_find_update_file
 * (the CONFIG.bin entry).
 *   exFAT: first cluster = the long at +0x34 (the next entry's +0x14);
 *          sector = (cluster - 2) * sectors per cluster + fwupd_exfat_heap_offset.
 *   FAT:   first cluster = (word at +0x14) << 16 + word at +0x1a;
 *          sector = (cluster - fwupd_root_cluster) * sectors per cluster + fwupd_data_start_sector.
 * The port number read first is stored and not used. */
void fwupd_take_config_entry(unsigned int config_entry)
{
    unsigned char config_port;
    unsigned long config_cluster;
    config_port = usb_get_current_port();
    if (!(fwupd_fs_type ^ FS_EXFAT)) {
        fwupd_entry_first_sector = (lib_get_le_value(fwupd_sector_buffer + config_entry + 0x34, 4) - 2) * fwupd_sectors_per_cluster + fwupd_exfat_heap_offset;
        fwupd_entry_first_sector += fwupd_volume_start_sector;
    } else {
        config_cluster = lib_get_le_value(fwupd_sector_buffer + config_entry + 0x14, 2);
        config_cluster = (config_cluster << 16) + lib_get_le_value(fwupd_sector_buffer + config_entry + 0x1a, 2);
        fwupd_entry_first_sector = (config_cluster - fwupd_root_cluster) * fwupd_sectors_per_cluster + fwupd_data_start_sector;
        fwupd_entry_first_sector += fwupd_volume_start_sector;
    }
}

/* fwupd_store_entry_pos: remember where the entry being listed lies (cluster, sector in the cluster, byte
 * offset in the sector); fwupd_set_target_file reads that sector again. */
void fwupd_store_entry_pos(unsigned long cluster, unsigned char sector, unsigned int offset)
{
    fwupd_entry_cluster = cluster;
    fwupd_entry_sector = sector;
    fwupd_entry_offset = offset;
}

/* lib_get_le_value: the little-endian value of the count bytes at bytes (bytes[count - 1] is the most significant). */
unsigned long lib_get_le_value(unsigned char *bytes, unsigned char count)
{
    unsigned char i;
    unsigned long value;
    value = 0;
    for (i = 1; i < count + 1; i++) {
        value <<= 8;
        value |= bytes[count - i];
    }
    return value;
}
extern unsigned long xdata fwupd_fat_start_sector;

/* fwupd_fat_step_cluster: move the FAT / exFAT directory walk to (cluster, sector, offset) and load the sector it
 * falls in; fat_sector / fat_offset give the FAT entry of the cluster (sector counted from the FAT start, byte
 * offset). The final position is stored in fwupd_walk_position. Returns 1 when the FAT entry read is FAT_CHAIN_LAST
 * (end of the directory's chain), else 0. Entered through the common-entry block 0x7262 / 0x7263 / 0x72a5.
 * Phases:
 *   1. offset past the sector end: next sector of the cluster, offset %= sector size, read it;
 *      otherwise, when sector differs from the stored one, read the walk's current sector again;
 *   2. sector past the cluster end: read the FAT sector, take the next cluster from the FAT entry, print it
 *      ("DataCluster = 0x%8lx"); not the end: work out the FAT position of the new cluster and read its first sector;
 *   3. store the position. */
bit fwupd_fat_step_cluster(unsigned long cluster, unsigned char sector, unsigned int offset,
                           unsigned long fat_sector, unsigned long fat_offset)
{
    bit chain_end;
    chain_end = 0;
    /* Phase 1 */
    if (offset >= fwupd_dir_sector.bytes_per_sector) {
        sector++;
        offset = offset % fwupd_dir_sector.bytes_per_sector;
        usb_disk_read_to_xdata((cluster - 2) * fwupd_sectors_per_cluster + (fwupd_data_start_sector + fwupd_volume_start_sector) + sector,
                      fwupd_sector_buffer, fwupd_dir_sector.bytes_per_sector);
    } else if (sector != fwupd_walk_position.sector) {
        usb_disk_read_to_xdata((fwupd_dir_cluster - 2) * fwupd_sectors_per_cluster + (fwupd_data_start_sector + fwupd_volume_start_sector) + fwupd_dir_sector.dir_sector,
                      fwupd_sector_buffer, fwupd_dir_sector.bytes_per_sector);
    }
    /* Phase 2 */
    if (sector >= fwupd_sectors_per_cluster) {
        sector = 0;
        usb_disk_read_to_xdata(fwupd_fat_start_sector + fwupd_volume_start_sector + fat_sector, fwupd_sector_buffer, fwupd_dir_sector.bytes_per_sector);
        cluster = lib_get_le_value(fwupd_sector_buffer + (unsigned int)fat_offset, 4);
        lib_printf517((void code *)FMT_DATA_CLUSTER, cluster);
        if (cluster == FAT_CHAIN_LAST) {
            chain_end = 1;
        } else {
            /* 4 bytes per FAT entry */
            fat_offset = cluster * 4;
            fat_sector = fat_offset / fwupd_dir_sector.bytes_per_sector;
            if (fat_offset >= fwupd_dir_sector.bytes_per_sector) fat_offset = fat_offset % fwupd_dir_sector.bytes_per_sector;
            usb_disk_read_to_xdata((cluster - 2) * fwupd_sectors_per_cluster + (fwupd_data_start_sector + fwupd_volume_start_sector), fwupd_sector_buffer, fwupd_dir_sector.bytes_per_sector);
        }
    }
    /* Phase 3 */
    fwupd_walk_position.cluster = cluster;
    fwupd_walk_position.sector = sector;
    fwupd_walk_position.offset = offset;
    fwupd_walk_position.fat_sector = fat_sector;
    fwupd_walk_position.fat_offset = fat_offset;
    return chain_end;
}

/* fwupd_test_exfat_img_name: 1 when the exFAT name whose last character is at byte name_end of fwupd_sector_buffer
 * ends in ".IMG" (characters 'G' at name_end, 'M' at name_end - 2, 'I' at name_end - 4, either case); called by
 * fwupd_list_next_img_entry. Phases:
 *   1. the three characters lie in one entry: test them in place;
 *   2. 'M' or 'I' lies in the entry before: it is 2 bytes further back (past that entry's first two bytes); when the
 *      entry before lies in the previous sector, load it (fwupd_fat_step_cluster from the stored walk position) and
 *      take the character at 0x1FE / 0x1FC;
 *   3. read the directory sector dir_sector of fwupd_dir_cluster again. */
bit fwupd_test_exfat_img_name(unsigned int name_end, unsigned char dir_sector)
{
    bit is_img;
    is_img = 0;
    if (((name_end - 2) & 0x1f) == 0 || ((name_end - 4) & 0x1f) == 0) {
        /* Phase 2 */
        if (((name_end - 2) & 0x1f) == 0) {
            /* 'M' and 'I' are in the entry before */
            if (fwupd_sector_buffer[name_end] == 'G' || fwupd_sector_buffer[name_end] == 'g') {
                if (name_end - 2 == 0) {
                    fwupd_fat_step_cluster(fwupd_walk_position.cluster, dir_sector, name_end, fwupd_walk_position.fat_sector, fwupd_walk_position.fat_offset);
                    if ((fwupd_sector_buffer[0x1fe] == 'M' || fwupd_sector_buffer[0x1fe] == 'm') &&
                        (fwupd_sector_buffer[0x1fc] == 'I' || fwupd_sector_buffer[0x1fc] == 'i')) is_img = 1; else is_img = 0;
                } else {
                    if ((fwupd_sector_buffer[name_end - 4] == 'M' || fwupd_sector_buffer[name_end - 4] == 'm') &&
                        (fwupd_sector_buffer[name_end - 6] == 'I' || fwupd_sector_buffer[name_end - 6] == 'i')) is_img = 1; else is_img = 0;
                }
            } else is_img = 0;
        } else if (((name_end - 4) & 0x1f) == 0) {
            /* only 'I' is in the entry before */
            if ((fwupd_sector_buffer[name_end] == 'G' || fwupd_sector_buffer[name_end] == 'g') &&
                (fwupd_sector_buffer[name_end - 2] == 'M' || fwupd_sector_buffer[name_end - 2] == 'm')) {
                if (name_end - 4 == 0) {
                    fwupd_fat_step_cluster(fwupd_walk_position.cluster, dir_sector, name_end, fwupd_walk_position.fat_sector, fwupd_walk_position.fat_offset);
                    if (fwupd_sector_buffer[0x1fe] == 'I' || fwupd_sector_buffer[0x1fe] == 'i') is_img = 1; else is_img = 0;
                } else {
                    if (fwupd_sector_buffer[name_end - 6] == 'I' || fwupd_sector_buffer[name_end - 6] == 'i') is_img = 1; else is_img = 0;
                }
            } else is_img = 0;
        }
    } else {
        /* Phase 1 */
        if ((fwupd_sector_buffer[name_end] == 'G' || fwupd_sector_buffer[name_end] == 'g') &&
            (fwupd_sector_buffer[name_end - 2] == 'M' || fwupd_sector_buffer[name_end - 2] == 'm') &&
            (fwupd_sector_buffer[name_end - 4] == 'I' || fwupd_sector_buffer[name_end - 4] == 'i')) is_img = 1; else is_img = 0;
    }
    /* Phase 3 */
    usb_disk_read_to_xdata((fwupd_dir_cluster - 2) * fwupd_sectors_per_cluster + (fwupd_data_start_sector + fwupd_volume_start_sector) + dir_sector,
                  fwupd_sector_buffer, fwupd_dir_sector.bytes_per_sector);
    return is_img;
}

/* fwupd_seek_block_offset: move the read cursor to byte offset of disk address sector (sectors from the volume
 * start); an offset past the sector end moves on by whole sectors. The sector is read only when it is not the one in
 * fwupd_sector_buffer already (fwupd_buffer_sector). The cursor is left in fwupd_saved_position. */
void fwupd_seek_block_offset(unsigned long sector, unsigned int offset)
{
    if (offset >= fwupd_dir_sector.bytes_per_sector) {
        sector += offset / fwupd_dir_sector.bytes_per_sector;
        offset = offset % fwupd_dir_sector.bytes_per_sector;
        if (fwupd_buffer_sector != sector) usb_disk_read_to_xdata(fwupd_volume_start_sector + sector, fwupd_sector_buffer, fwupd_dir_sector.bytes_per_sector);
    } else {
        if (fwupd_buffer_sector != sector) usb_disk_read_to_xdata(fwupd_volume_start_sector + sector, fwupd_sector_buffer, fwupd_dir_sector.bytes_per_sector);
    }
    fwupd_saved_position.sector = sector;
    fwupd_saved_position.offset = offset;
    fwupd_buffer_sector = sector;
}

