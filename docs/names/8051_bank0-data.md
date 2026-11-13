# Data names: 8051 boot loader (bank 0)

43 entries from `symbols/8051_bank0.data.json`, in address order. The source uses the names through the `#define` lists (see [Function names](../NAMES.md#names-in-the-source)); [Data objects](../DATA.md) describes the principal records. The *basis* column has the same meaning as for the function names.

| Basis | Entries |
|---|---:|
| proven | 17 |
| derived | 24 |
| descriptive | 2 |

## Constant data in the program

| Name | Label | What it holds | Basis |
|---|---|---|---|
| `startup_marker_bytes` | `DAT_08` | IDATA bytes 0x08.. searched for the marker 0x60 when the clock variant is not 0x20. | descriptive |
| `startup_marker_bytes_slow_clock` | `DAT_0e` | IDATA bytes 0x0E.. searched for the marker 0x30 when the clock variant is 0x20 (the slower clock). | descriptive |
| `flash_chip_flags` | `DAT_0014` | Flags byte of the identified chip; bit 1 = status registers written one by one. | derived |
| `flash_jedec_command` | `DAT_0022` | The command byte 0x9F (Read JEDEC ID) sent by the ID read. | derived |
| `flash_jedec_answer` | `DAT_0023` | The four answer bytes of the JEDEC ID read. | derived |
| `flash_quad_capable_flag` | `DAT_002f` | Set when the identified chip can read in quad mode (chip flags bit 0). | proven |
| `flash_chip_index` | `DAT_0030` | Index of the identified chip from the chip table (maker only: low nibble 0xF). | proven |
| `flash_erase_opcode` | `DAT_0031` | Sector erase opcode of the chip: 0xD7 for maker 0x7F, else 0x20. | proven |
| `flash_size_code` | `DAT_0032` | The 16-bit size code of the identified chip. | proven |
| `reg_sys_clock_variant` | `DAT_d511` | Chip register read as the clock variant: 0x20 selects the 48 MHz UART clock, any other value 96 MHz. | derived |
| `reg_flash_jedec_id` | `DAT_f064` | The three JEDEC ID bytes of the flash chip (maker, memory type, capacity). | derived |

## Constant tables in code memory

| Name | Label | What it holds | Basis |
|---|---|---|---|
| `flash_chip_table` | `DAT_CODE_4000` | The 57 known flash chips: index, maker, memory type, capacity, size code, flags. | proven |
| `startup_partition_table` | `DAT_CODE_6000` | The partition table at CODE 0x6000 (0x7000 for slot 1). | proven |

## Hardware registers and chip memory

| Name | Label | What it holds | Basis |
|---|---|---|---|
| `startup_share_block` | `DAT_EXTMEM_3000` | The share block that the boot loader fills for the next program. | proven |
| `reg_flash_read_mode` | `DAT_EXTMEM_f050` | Flash mode bits: bit 2 quad read (0x6B), bit 5 dual read (0x3B). | proven |
| `reg_flash_jedec_maker` | `DAT_EXTMEM_f064` | JEDEC ID byte 0: the maker of the flash chip. | derived |
| `reg_flash_jedec_mem_type` | `DAT_EXTMEM_f065` | JEDEC ID byte 1: the memory type. | derived |
| `reg_flash_jedec_capacity` | `DAT_EXTMEM_f066` | JEDEC ID byte 2: the capacity code. | derived |
| `reg_flash_spi_start` | `DAT_EXTMEM_f0e5` | SPI start register: bit 0 starts a transfer, bit 1 a read; each clears when done. | proven |
| `reg_flash_spi_mode` | `DAT_EXTMEM_f0e6` | SPI mode register: bits 2-3 = bus mode, low bits = transfer kind (0x41, 1). | derived |
| `reg_flash_read_opcode` | `DAT_EXTMEM_f0ea` | The read opcode of the flash controller (0x6B, 0x3B, 0x0B or a command). | proven |
| `reg_flash_length_high` | `DAT_EXTMEM_f0eb` | Transfer length bits 16-23. | proven |
| `reg_flash_length_mid` | `DAT_EXTMEM_f0ec` | Transfer length bits 8-15. | proven |
| `reg_flash_length_low` | `DAT_EXTMEM_f0ed` | Transfer length bits 0-7. | proven |
| `reg_flash_command` | `DAT_EXTMEM_f0ee` | The first byte (opcode) of a flash command. | proven |
| `reg_flash_read_byte` | `DAT_EXTMEM_f0ef` | The byte that a one-byte read command returns. | proven |
| `reg_flash_addr_f0f0` | `DAT_EXTMEM_f0f0` | Address register written with address bits 24-31 by the stream read. | derived |
| `reg_flash_addr_f0f1` | `DAT_EXTMEM_f0f1` | Address register written with address bits 16-23 by the stream read. | derived |
| `reg_flash_addr_f0f2` | `DAT_EXTMEM_f0f2` | Address register written with address bits 0-7 by the stream read. | derived |
| `reg_flash_transfer_type` | `DAT_EXTMEM_f0f4` | Transfer type: (command length << 5) \| 0x13, 0x0B stream read, 0x07 one-byte read. | proven |
| `reg_gpio_port12` | `DAT_EXTMEM_f11c` | Output register of GPIO port 12. | derived |
| `reg_gpio_port12_partner` | `DAT_EXTMEM_f11d` | Partner register of GPIO port 12. | derived |
| `reg_flash_fifo_f1c0` | `DAT_EXTMEM_f1c0` | FIFO register: write mode 0x82 / 0x84, stream mode 0x81, read data of the stream. | derived |
| `reg_flash_fifo_write` | `DAT_EXTMEM_f1c3` | FIFO data register for the command bytes after the opcode. | proven |
| `reg_flash_fifo_f1c8` | `DAT_EXTMEM_f1c8` | FIFO register: mode 0x81 / 0x82, then the answer bytes of a transfer. | derived |
| `reg_copy_start` | `DAT_EXTMEM_f1d0` | Copy register: 0x87 starts the hardware copy of the next program. | derived |
| `reg_copy_addr_f1d3` | `DAT_EXTMEM_f1d3` | Copy register: partition table byte 3 (flash address of the next program). | derived |
| `reg_copy_addr_f1d4` | `DAT_EXTMEM_f1d4` | Copy register: partition table byte 2 (flash address of the next program). | derived |
| `reg_copy_addr_f1d5` | `DAT_EXTMEM_f1d5` | Copy register: partition table byte 1 (flash address of the next program). | derived |
| `reg_copy_size_f1d6` | `DAT_EXTMEM_f1d6` | Copy register: partition table byte 7 (size of the next program). | derived |
| `reg_copy_size_f1d7` | `DAT_EXTMEM_f1d7` | Copy register: partition table byte 6 (size of the next program). | derived |
| `reg_copy_size_f1d8` | `DAT_EXTMEM_f1d8` | Copy register: partition table byte 5 (size of the next program). | derived |

## RAM

| Name | Label | What it holds | Basis |
|---|---|---|---|
| `startup_partition_entries` | `DAT_EXTMEM_a000` | The 12-byte descriptors built from the partition table for the share block. | derived |
