# Data names: 8051 update agent (bank 2)

148 entries from `symbols/8051_bank2.data.json`, in address order. The source uses the names through the `#define` lists (see [Function names](../NAMES.md#names-in-the-source)); [Data objects](../DATA.md) describes the principal records. The *basis* column has the same meaning as for the function names.

| Basis | Entries |
|---|---:|
| proven | 25 |
| derived | 113 |
| descriptive | 10 |

## Constant data in the program

| Name | Label | What it holds | Basis |
|---|---|---|---|
| `usb_reg114_bit0_clear_flag` | `DAT_BIT_0000` | Set: the next write of register 0x114 clears its bit 0; clear: it sets the bit. | descriptive |
| `fwupd_ntfs_in_index_alloc` | `DAT_BIT_000b` | NTFS: set once the listing has moved from the index root to the index allocation. | derived |
| `fwupd_dir_end_reached` | `DAT_BIT_000c` | Set when the directory walk reached the end of its chain; the listing then returns 0 at once. | derived |
| `fwupd_file_contiguous` | `DAT_BIT_000d` | Set when the selected file is one unbroken run of clusters; the FAT chain is then not followed. | derived |
| `usb_block_buffer` | `DAT_0022` | Buffer in DATA through which 32-byte blocks of the USB port memory are read and written. | derived |

## Constant tables in code memory

| Name | Label | What it holds | Basis |
|---|---|---|---|
| `usb_host_init_table` | `DAT_CODE_c9d2` | The 16 register writes of the host set-up: register, value, wait. | proven |
| `flash_chip_table` | `DAT_CODE_cb8c` | The table of known flash chips, 8-byte records, looked up by JEDEC ID. | proven |
| `fwupd_svc_cmd_1e_record` | `DAT_CODE_cbc4` | Fixed eight-byte service packet 07 1E AA 55 CC 33 E2 1D, sent by fwupd_svc_send_rec_cbc4. | derived |
| `fwupd_svc_record10_template` | `DAT_CODE_cbcc` | Fixed ten-byte service record; fwupd_svc_send_rec_cbcc sends a copy with bytes 8 and 9 replaced. | derived |
| `flash_id_try_values` | `DAT_CODE_cbd6` | Values written to register 0xF068 before each of the three JEDEC ID read tries. | derived |
| `fwupd_boot_sector_head` | `DAT_CODE_e0a8` | First 11 bytes of a FAT boot sector (EB 58 90 'MSDOS5.0'), tested on block 0. | proven |
| `fwupd_msdos_oem_name` | `DAT_CODE_e0b9` | The OEM name 'MSDOS5.0' tested in the boot sector. | proven |
| `fwupd_ntfs_oem_name` | `DAT_CODE_e0c1` | The OEM name 'NTFS    ' tested in the boot sector. | proven |
| `uart_clock_factors` | `DAT_CODE_e543` | Clock factor per clock setting; timer reload and delay count are computed from it. | derived |

## Hardware registers and chip memory

| Name | Label | What it holds | Basis |
|---|---|---|---|
| `reg_usb_phy_ctrl52` | `DAT_EXTMEM_5052` | USB PHY register; bits 0-4 take the tuning value from the mailbox. | derived |
| `reg_usb0_reg_cmd` | `DAT_EXTMEM_cd00` | USB port 0 register access: 0x40 read, 0x80 write; bit 0 set when done. | derived |
| `reg_usb0_reg_index` | `DAT_EXTMEM_cd01` | USB port 0 register access: low byte of the register number. | derived |
| `reg_usb0_wdata0` | `DAT_EXTMEM_cd02` | USB port 0 register access: write value bits 0-7. | derived |
| `reg_usb0_wdata1` | `DAT_EXTMEM_cd03` | USB port 0 register access: write value bits 8-15. | derived |
| `reg_usb0_wdata2` | `DAT_EXTMEM_cd04` | USB port 0 register access: write value bits 16-23. | derived |
| `reg_usb0_wdata3` | `DAT_EXTMEM_cd05` | USB port 0 register access: write value bits 24-31. | derived |
| `reg_usb0_rdata0` | `DAT_EXTMEM_cd06` | USB port 0 register access: read value bits 0-7. | derived |
| `reg_usb0_rdata1` | `DAT_EXTMEM_cd07` | USB port 0 register access: read value bits 8-15. | derived |
| `reg_usb0_rdata2` | `DAT_EXTMEM_cd08` | USB port 0 register access: read value bits 16-23. | derived |
| `reg_usb0_rdata3` | `DAT_EXTMEM_cd09` | USB port 0 register access: read value bits 24-31. | derived |
| `reg_usb0_byte_0a` | `DAT_EXTMEM_cd0a` | USB controller 0 register byte 0x0A: 0x80 pulsed at reset; bit 5 switched by mailbox commands 0x21 / 0x22. | descriptive |
| `reg_usb1_reg_cmd` | `DAT_EXTMEM_cd20` | USB port 1 register access: 0x40 read, 0x80 write; bit 0 set when done. | derived |
| `reg_usb1_reg_index` | `DAT_EXTMEM_cd21` | USB port 1 register access: low byte of the register number. | derived |
| `reg_usb1_wdata0` | `DAT_EXTMEM_cd22` | USB port 1 register access: write value bits 0-7. | derived |
| `reg_usb1_wdata1` | `DAT_EXTMEM_cd23` | USB port 1 register access: write value bits 8-15. | derived |
| `reg_usb1_wdata2` | `DAT_EXTMEM_cd24` | USB port 1 register access: write value bits 16-23. | derived |
| `reg_usb1_wdata3` | `DAT_EXTMEM_cd25` | USB port 1 register access: write value bits 24-31. | derived |
| `reg_usb1_rdata0` | `DAT_EXTMEM_cd26` | USB port 1 register access: read value bits 0-7. | derived |
| `reg_usb1_rdata1` | `DAT_EXTMEM_cd27` | USB port 1 register access: read value bits 8-15. | derived |
| `reg_usb1_rdata2` | `DAT_EXTMEM_cd28` | USB port 1 register access: read value bits 16-23. | derived |
| `reg_usb1_rdata3` | `DAT_EXTMEM_cd29` | USB port 1 register access: read value bits 24-31. | derived |
| `reg_usb1_byte_0a` | `DAT_EXTMEM_cd2a` | USB controller 1 register byte 0x0A: 0x80 pulsed together with the same byte of controller 0. | descriptive |
| `reg_bus_block_ctrl` | `DAT_EXTMEM_cd30` | Bus block access: set to 0x80 before each 32-byte block. | derived |
| `reg_bus_block_wdata` | `DAT_EXTMEM_cd31` | Bus block access: write data, one byte at a time. | derived |
| `reg_bus_block_read_start` | `DAT_EXTMEM_cd32` | Bus block access: 0x80 starts a block read. | derived |
| `reg_bus_block_read_status` | `DAT_EXTMEM_cd33` | Bus block access: reads 0x80 when the block read is done. | derived |
| `reg_bus_block_rdata` | `DAT_EXTMEM_cd34` | Bus block access: read data, one byte at a time. | derived |
| `reg_bus_block_addr0` | `DAT_EXTMEM_cd35` | Bus block access: address bits 0-7. | derived |
| `reg_bus_block_addr1` | `DAT_EXTMEM_cd36` | Bus block access: address bits 8-15. | derived |
| `reg_bus_block_addr2` | `DAT_EXTMEM_cd37` | Bus block access: address bits 16-23. | derived |
| `reg_bus_block_addr3` | `DAT_EXTMEM_cd38` | Bus block access: address bits 24-31. | derived |
| `reg_fwupd_port0_status` | `DAT_EXTMEM_f190` | Mailbox: status of USB port 0 for the main processor. | proven |
| `reg_fwupd_port0_command` | `DAT_EXTMEM_f191` | Mailbox: command for USB port 0 from the main processor. | proven |
| `reg_fwupd_port1_status` | `DAT_EXTMEM_f192` | Mailbox: status of USB port 1 for the main processor. | proven |
| `reg_fwupd_port1_command` | `DAT_EXTMEM_f193` | Mailbox: command for USB port 1 from the main processor. | proven |
| `reg_fwupd_progress` | `DAT_EXTMEM_f194` | Mailbox: progress of the current job, 0..0xFF. | derived |
| `reg_fwupd_mailbox_cmd` | `DAT_EXTMEM_f198` | Mailbox command byte; taken and cleared by the main loop. | proven |
| `reg_fwupd_mailbox_f19a` | `DAT_EXTMEM_f19a` | Mailbox byte 0xF19A: parameter (USB mode of command 0x70, first file name byte). | derived |
| `reg_fwupd_mailbox_f19b` | `DAT_EXTMEM_f19b` | Mailbox byte 0xF19B: parameter or answer (DRAM address bits 0-7). | derived |
| `reg_fwupd_mailbox_f19c` | `DAT_EXTMEM_f19c` | Mailbox byte 0xF19C: parameter or answer (address or size byte). | derived |
| `reg_fwupd_mailbox_f19d` | `DAT_EXTMEM_f19d` | Mailbox byte 0xF19D: parameter or answer (address or size byte). | derived |
| `reg_fwupd_mailbox_f19e` | `DAT_EXTMEM_f19e` | Mailbox byte 0xF19E: parameter or answer (size byte). | derived |
| `reg_fwupd_mailbox_f19f` | `DAT_EXTMEM_f19f` | Mailbox byte 0xF19F: parameter or answer (size byte). | derived |

## RAM

| Name | Label | What it holds | Basis |
|---|---|---|---|
| `fwupd_buffer_sector` | `DAT_EXTMEM_0100` | Disk address of the block now in the sector buffer; read again only when it differs. | derived |
| `fwupd_ntfs_run_bytes` | `DAT_EXTMEM_0104` | Number of NTFS data-run bytes copied into the run list. | descriptive |
| `fwupd_volume_start_sector` | `DAT_EXTMEM_0105` | First sector of the volume (partition start from the boot sector +0x1C6, or 0). | proven |
| `fwupd_file_size` | `DAT_EXTMEM_0109` | Size of the selected update file. | proven |
| `fwupd_ntfs_run` | `DAT_EXTMEM_010d` | NTFS: the data run in use: length in clusters (word) and start (long at 0x010F). | derived |
| `fwupd_record_total` | `DAT_EXTMEM_0113` | Sizes of records 1 and up of the update image, each rounded up to 256-byte units, added together. | derived |
| `fwupd_saved_position` | `DAT_EXTMEM_0117` | Sector and byte offset left by fwupd_seek_block_offset: where the readers look in the sector buffer. | derived |
| `fwupd_entry_name` | `DAT_EXTMEM_011d` | The 0x2D-byte name of the directory entry listed last (printed). | proven |
| `fwupd_config_record_flag` | `DAT_EXTMEM_014a` | Set when the CONFIG.bin directory entry was found; without it the file passes unchecked. | derived |
| `fwupd_exfat_heap_offset` | `DAT_EXTMEM_014b` | exFAT cluster heap offset from the boot sector (+0x58). | derived |
| `fwupd_ntfs_run_count` | `DAT_EXTMEM_014f` | NTFS: number of data runs copied into fwupd_ntfs_run_list. | derived |
| `fwupd_dir_entry_offset` | `DAT_EXTMEM_0150` | Offset of the current 0x20-byte entry in the directory sector. | derived |
| `fwupd_entry_first_sector` | `DAT_EXTMEM_0152` | First sector of the directory entry being looked at. | derived |
| `fwupd_config_sum` | `DAT_EXTMEM_0156` | The 16-bit sum from the CONFIG.bin record (bytes +0x10, +0x11). | proven |
| `fwupd_fat_start_sector` | `DAT_EXTMEM_0158` | Start of the FAT: reserved sectors (FAT) or the FAT offset (exFAT +0x50). | derived |
| `fwupd_ntfs_run_list` | `DAT_EXTMEM_015c` | The NTFS data runs of the file record, copied byte by byte. | derived |
| `fwupd_sectors_per_cluster` | `DAT_EXTMEM_01dc` | Sectors per cluster of the mounted volume. | proven |
| `fwupd_fat_entry_sector` | `DAT_EXTMEM_01de` | FAT sector that holds the entry of the current cluster (cluster * 4 / sector size). | derived |
| `fwupd_ntfs_mft_sector` | `DAT_EXTMEM_01e2` | NTFS: first sector of the master file table (MFT cluster * sectors per cluster). | derived |
| `fwupd_sector_buffer` | `DAT_EXTMEM_01e6` | The 512-byte buffer of the disk block read last. | proven |
| `fwupd_mft_first_attr_offset` | `DAT_EXTMEM_01fa` | Byte 0x14 of the sector buffer: in a file record, the offset of its first attribute. | derived |
| `fwupd_file_first_cluster` | `DAT_EXTMEM_03e6` | First cluster of the selected update file. | proven |
| `fwupd_ntfs_index_sector` | `DAT_EXTMEM_03ee` | NTFS: sector of the index entry to list next. | derived |
| `fwupd_walk_position` | `DAT_EXTMEM_03f2` | Position of the FAT / exFAT directory walk: cluster, sector, offset and the cluster's FAT entry place. | derived |
| `fwupd_file_first_sector` | `DAT_EXTMEM_0401` | First sector of the selected update file. | proven |
| `fwupd_data_start_sector` | `DAT_EXTMEM_0405` | First data sector: cluster heap (exFAT) or behind the FATs (FAT). | derived |
| `fwupd_dir_entry_count` | `DAT_EXTMEM_0409` | Count of directory entries listed. | derived |
| `fwupd_ntfs_index_offset` | `DAT_EXTMEM_040a` | NTFS: byte offset of the index entry to list next; grows by the entry length. | derived |
| `fwupd_ntfs_record_number` | `DAT_EXTMEM_040c` | NTFS: file record number of the index entry listed last. | derived |
| `fwupd_fat_entry_offset` | `DAT_EXTMEM_0410` | Byte offset of the current cluster in the FAT (cluster * 4). | derived |
| `fwupd_dir_cluster` | `DAT_EXTMEM_0414` | The cluster of the directory being read; starts at the root cluster. | derived |
| `fwupd_root_cluster` | `DAT_EXTMEM_0418` | First cluster of the root directory. | proven |
| `fwupd_fs_type` | `DAT_EXTMEM_041c` | File system of the stick: 0 FAT, 1 exFAT, 2 NTFS. | proven |
| `fwupd_entry_cluster` | `DAT_EXTMEM_041d` | Cluster of the current directory entry. | derived |
| `fwupd_entry_sector` | `DAT_EXTMEM_0421` | Sector within the cluster of the current directory entry. | derived |
| `fwupd_entry_offset` | `DAT_EXTMEM_0425` | Byte offset, within its sector, of the directory entry remembered while listing. | derived |
| `fwupd_dir_sector` | `DAT_EXTMEM_0429` | Sector, within the directory cluster, that the directory walk is reading. | derived |
| `fwupd_bytes_per_sector` | `DAT_EXTMEM_042a` | Bytes per sector of the mounted volume. | proven |
| `fwupd_ntfs_run_index` | `DAT_EXTMEM_042c` | NTFS: number of the data run of the index that is being listed. | derived |
| `fwupd_last_percent` | `DAT_EXTMEM_042d` | Progress percent printed last by the flash block writer. | derived |
| `fwupd_record_count` | `DAT_EXTMEM_042e` | Number of header records in the image (from the header block). | derived |
| `fwupd_record_base` | `DAT_EXTMEM_042f` | Base flash address of the header records and DUALFW regions. | derived |
| `fwupd_last_record_size_low` | `DAT_EXTMEM_0433` | Low byte of the size word of the last image record; its top three bits give a block count. | derived |
| `fwupd_dualfw_region` | `DAT_EXTMEM_0434` | Current and next DUALFW region index. | derived |
| `fwupd_dualfw_region_next` | `DAT_EXTMEM_0435` | The 'next' region index: second byte of fwupd_dualfw_region, declared as its own byte in one file. | derived |
| `fwupd_svc_packet` | `DAT_EXTMEM_0436` | Command and reply packet of the flash service link. | derived |
| `fwupd_block_buffer` | `DAT_EXTMEM_0440` | The 512-byte block written to the flash. | derived |
| `fwupd_flash_chip_row` | `DAT_EXTMEM_0640` | The chip table row of the identified flash chip. | derived |
| `fwupd_flash_size_code` | `DAT_EXTMEM_0644` | Size code of the flash chip (size = code * 0x40000 bytes). | proven |
| `fwupd_svc_claim_reply_byte1` | `DAT_EXTMEM_0648` | Reply byte 1 of the service link, kept by fwupd_svc_claim_link when it takes the link. | descriptive |
| `fwupd_svc_claim_reply_byte2` | `DAT_EXTMEM_0649` | Reply byte 2 of the service link, kept by fwupd_svc_claim_link when it takes the link. | descriptive |
| `fwupd_mailbox_work_bytes` | `DAT_EXTMEM_064a` | Eight bytes filled by mailbox commands 0x41 (bytes 0..4) and 0x42 (bytes 5..7). | derived |
| `fwupd_record_table` | `DAT_EXTMEM_0652` | The header records of the image (up to 20). | derived |
| `fwupd_state_reg_on_flag` | `DAT_EXTMEM_06f2` | 1 lets fwupd_svc_write_state_reg write its register; fwupd_run_isp_write clears it before the write. | derived |
| `fwupd_state_reg_number_high` | `DAT_EXTMEM_06f3` | High byte of the main chip register number that fwupd_svc_write_state_reg writes. | derived |
| `fwupd_state_reg_number_low` | `DAT_EXTMEM_06f4` | Low byte of the main chip register number that fwupd_svc_write_state_reg writes. | derived |
| `fwupd_state_reg_value_0` | `DAT_EXTMEM_06f5` | Value fwupd_svc_write_state_reg writes to its register for state 0. | derived |
| `fwupd_state_reg_value_1` | `DAT_EXTMEM_06f6` | Value fwupd_svc_write_state_reg writes to its register for state 1. | derived |
| `fwupd_record_buffer` | `DAT_EXTMEM_06f7` | The 32-byte header record being refreshed. | derived |
| `fwupd_dram_address` | `DAT_EXTMEM_0717` | DRAM address of the loaded file, posted in 0xF19B..0xF19D. | derived |
| `usb_control_reply` | `DAT_EXTMEM_071b` | Reply bytes of the last USB control transfer, copied from the block buffer with the word bytes reversed. | derived |
| `usb_port_index` | `DAT_EXTMEM_075b` | The USB port (0 or 1) whose records are loaded. | proven |
| `usb_port_record` | `DAT_EXTMEM_075c` | Current copy of the 0x27-byte record of the selected USB port. | derived |
| `usb_port_records` | `DAT_EXTMEM_0783` | Saved 0x27-byte records of the two USB ports. | derived |
| `usb_next_device_address` | `DAT_EXTMEM_07d1` | Per USB port: the address the next enumerated device gets; starts at 3 and grows by 2. | derived |
| `usb_port_error_counts` | `DAT_EXTMEM_07d3` | Error counter of each USB port: 1 is added for every failed transfer or enumeration step. | derived |
| `usb_port_mem_base` | `DAT_EXTMEM_07d5` | Memory base of the selected port: common base + port * 0x380. | proven |
| `usb_setup_packets` | `DAT_EXTMEM_07d9` | Ten 8-byte USB setup packets sent by the control transfers; byte 6 is the data length. | derived |
| `usb_queue_head_ptr` | `DAT_EXTMEM_0829` | Pointer to the block buffer at DATA 0x22, through which the fields of a queue head are read and written. | derived |
| `usb_port_xfer_record` | `DAT_EXTMEM_082a` | Current copy of the 0x2E-byte transfer record of the selected port. | derived |
| `usb_port_xfer_records` | `DAT_EXTMEM_0858` | Saved 0x2E-byte transfer records of the two USB ports. | derived |
| `usb_port_list_block` | `DAT_EXTMEM_08b4` | Block address of the port's list area (port memory address a + 0x80); written to register 0x24. | derived |
| `usb_port_mem_offset` | `DAT_EXTMEM_08b8` | Port index * 0x380, the offset of the port memory. | proven |
| `usb_port_mem_addrs` | `DAT_EXTMEM_08bc` | Three addresses in the port memory: base + 0x280, + 0x20, + 8. | derived |
| `usb_mem_base` | `DAT_EXTMEM_08c9` | Common base of the USB port memory. | derived |
| `usb_port_bytes` | `DAT_EXTMEM_08cd` | Current copies of the three per-port bytes of the selected port. | descriptive |
| `usb_port_saved_bytes0` | `DAT_EXTMEM_08d0` | Saved first per-port byte of each USB port. | descriptive |
| `usb_port_saved_bytes1` | `DAT_EXTMEM_08d2` | Saved second per-port byte of each USB port. | descriptive |
| `usb_port_saved_bytes2` | `DAT_EXTMEM_08d4` | Saved third per-port byte of each USB port. | descriptive |
| `usb_msc_command_tag` | `DAT_EXTMEM_08de` | Tag put into each mass-storage command block ('USBC'); one higher after every command. | derived |
| `fwupd_svc_record10_copy` | `DAT_EXTMEM_08f5` | Working copy of the ten-byte service record, filled and sent by fwupd_svc_send_rec_cbcc. | derived |
| `fwupd_image_header` | `DAT_EXTMEM_0912` | Header block of the loaded image, checked for the NVTSC_IMG signature. | derived |
| `usb_device_max_packet` | `DAT_EXTMEM_09bd` | Largest packet of the device-mode control endpoint (0x40). | derived |
| `fwupd_requested_usb_mode` | `DAT_EXTMEM_09c6` | USB mode asked for by mailbox command 0x70 (0 or 1, host or device). | derived |
| `usb_phy_tune_value` | `DAT_EXTMEM_09cc` | Tuning value from mailbox byte 0xF199; below 0x20 it goes into register 0x5052. | derived |
| `fwupd_mode_state` | `DAT_EXTMEM_09cd` | Byte 0 = USB mode in effect, bytes 1 and 2 = status for 0xF190 and 0xF192. | derived |
| `fwupd_port0_state` | `DAT_EXTMEM_09ce` | State of the update state machine of USB port 0. | derived |
| `fwupd_port1_state` | `DAT_EXTMEM_09cf` | State of the update state machine of USB port 1. | derived |
| `timer_delay_loop_count` | `DAT_EXTMEM_09d0` | Loop count of the delay routine, set from the baud rate table. | derived |
| `i2c_bit_delay_count` | `DAT_EXTMEM_09d2` | Delay count of one bit on the bit-banged service bus. | derived |
