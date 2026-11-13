/* startup_load_partition_table  (FUN_CODE_0003)
 *
 * Read the partition table and hand the address and size of the next program to the hardware.
 * Note: Does not check the table in any way: no checksum, no range check. Prints only the three registers
 *   changed by a DUALFW block of slot 1.
 * Name basis: derived - slot at 0x6000, or 0x7000 when the marker byte at 0x7FFF is 0xAA; copies the table
 *   bytes into the copy-address registers and the share block; prints '[0x%04X] = %02BX' for the DUALFW
 *   register changes
 *
 * Matching notes
 * --------------
 * Built with the section default OPTIMIZE(7,SPEED). One C function over 0x0003..0x0926.
 * Source form: the dead store to dead_byte (DATA 0x22), the result bit set once and never cleared, the write to
 * 0xF00A inside the DUALFW loop and the long runs of single-byte copies (no loops) are all in the original code;
 * the exact build depends on them.
 */

/* Where the table is.  startup_partition_table is CODE 0x6000 (slot 0); the slot-1 table starts 0x1000 bytes
 * further on, at CODE 0x7000.  The last byte of the slot-1 area (CODE 0x7FFF) selects the slot. */
#define PART_SLOT1_OFFSET     0x1000  /* offset of the slot-1 table from CODE 0x6000 */
#define PART_SLOT_MARKER      0x1fff  /* offset of the slot marker byte (CODE 0x7FFF) */
#define PART_SLOT1_SELECTED   0xaa    /* marker value that selects slot 1 */

/* Partition records: 8 bytes each from the start of the slot.  This routine reads record 0 as
 * byte 0 = extended-address byte of the flash, bytes 1..3 = flash address (high byte first),
 * bytes 5..7 = length (high byte first); byte 4 is not read for record 0.  Records 1..12 (table bytes
 * 0x08..0x67) are passed on to the share block. */

/* DUALFW block of slot 1: the six letters "DUALFW" at slot offset 0xFF0, then eight parameter bytes. */
#define DUALFW_PARAM_OFFSET   0x0ff6
#define DUALFW_PARAM_COUNT    8

/* Kinds of the share block entries (startup_share_block_write: XDATA 0x3000 + a fixed offset per kind).
 * The 8051 application (startup_load_core_images in bank 1) stops unless the version is 1, then passes
 * kind 1 to startup_start_usb_agent, kind 2 to startup_setup_leon2m, kind 3 to startup_setup_leon2s and kind 4
 * to startup_load_tensilica_image; it copies only the first 0x6A bytes of the block (kinds 0..5).
 * Kind 5 (4 bytes) is written by flash_identify; this routine does not write it. */
#define SHARE_KIND_VERSION    0   /* 2 bytes: 00 01 */
#define SHARE_KIND_USB_AGENT  1   /* 12 bytes from 0xA000 */
#define SHARE_KIND_LEON2M     2   /* 0x24 bytes from 0xA00C */
#define SHARE_KIND_LEON2S     3   /* 0x28 bytes from 0xA030 */
#define SHARE_KIND_TENSILICA  4   /* 12 bytes from 0xA058 */
#define SHARE_KIND_6          6   /* 12 bytes from 0xA064 */
#define SHARE_KIND_7          7   /* 12 bytes from 0xA070 */
#define SHARE_KIND_8          8   /* 12 bytes from 0xA07C */
#define SHARE_KIND_9          9   /* 12 bytes from 0xA088 */

#define REG_F00A_VALUE        0x55  /* value written to register 0xF00A; its purpose is not shown */

extern unsigned char code startup_partition_table[];
extern unsigned char xdata startup_partition_entries[];
extern unsigned char volatile xdata DAT_EXTMEM_f1d1, DAT_EXTMEM_f1d2, reg_copy_addr_f1d3, reg_copy_addr_f1d4, reg_copy_addr_f1d5;
extern unsigned char volatile xdata reg_copy_size_f1d6, reg_copy_size_f1d7, reg_copy_size_f1d8, DAT_EXTMEM_f00a;
extern void lib_printf(void *fmt, ...);
void flash_identify(void);
void SetExtendedAddr(unsigned char ear);
void startup_share_block_write(unsigned char kind, unsigned char len, unsigned char *src);

/* startup_load_partition_table
 *
 * Reads the partition table from the boot loader's own flash area, loads the copy registers 0xF1D1..0xF1D8 with the
 * flash address and length of the next program (record 0 of the table), and fills the share block at XDATA 0x3000
 * that the next program reads.  Called once, through startup_run_partition_loader, from startup_boot_main after
 * the flash chip has been identified; startup_boot_main then writes 0x87 to the copy start register 0xF1D0.
 *
 * Phases, in order:
 *   1. Choose the slot: the table at CODE 0x6000, or the one at 0x7000 when CODE 0x7FFF holds 0xAA.
 *   2. Record 0, flash address: bytes 3, 2, 1 into the copy registers 0xF1D3, 0xF1D4, 0xF1D5.
 *   3. Slot 1 only, when the slot holds "DUALFW" at offset 0xFF0: three read-modify-writes of XDATA registers
 *      from the eight parameter bytes after the tag, each printed as "[0x%04X] = %02BX", then flash_identify
 *      runs again.  The table in this firmware has 0 at CODE 0x7FFF, so this phase does not run.
 *   4. Record 0, byte 0: when not 0, SetExtendedAddr(byte 0) sets the flash chip's extended address register.
 *   5. Record 0, length: 0xF1D1 = 0xF1D2 = 0, then bytes 7, 6, 5 into the copy registers 0xF1D6, 0xF1D7, 0xF1D8.
 *   6. Share block: version 00 01 (kind 0), then kinds 1, 2, 3, 4, 6, 7, 8, 9, each built in XDATA 0xA000..0xA08F
 *      from table bytes 0x08..0x67 and a few fixed bytes, and copied in with startup_share_block_write.
 *   7. Return 1.
 *
 * Returns: always 1.  The table is not checked in any way (no checksum, no range check), and the result bit is set
 * at the start and never cleared, so the "Can't find valid partition table!!!" branch of startup_boot_main cannot
 * be reached (docs/MAP.md).
 */
bit startup_load_partition_table(void)
{
    unsigned char dead_byte;        /* DATA 0x22: set to 0 and never read */
    unsigned int slot;              /* offset of the chosen table from CODE 0x6000: 0 or PART_SLOT1_OFFSET */
    unsigned char share_version[2]; /* share block version 00 01 */
    unsigned char dualfw_param[8];  /* [0] register high byte; [1]/[2] AND; [3]/[4] OR; [5]/[6]/[7] AND or OR */
    unsigned char i;
    unsigned char xdata *patch_reg; /* XDATA register changed by the DUALFW block */
    bit table_ok;                   /* result: set here and never cleared */
    dead_byte = 0;
    table_ok = 1;
    share_version[0] = 0;
    share_version[1] = 1;

    /* Phase 1: slot 0 at CODE 0x6000, or slot 1 at 0x7000 when the marker byte says so. */
    if (startup_partition_table[PART_SLOT_MARKER] == PART_SLOT1_SELECTED) slot = PART_SLOT1_OFFSET; else slot = 0;

    /* Phase 2: flash address of the next program (record 0 bytes 1..3), low byte into 0xF1D3. */
    reg_copy_addr_f1d3 = startup_partition_table[slot + 3];
    reg_copy_addr_f1d4 = startup_partition_table[slot + 2];
    reg_copy_addr_f1d5 = startup_partition_table[slot + 1];

    /* Phase 3: DUALFW register patch, slot 1 only. */
    if (slot != 0 && startup_partition_table[slot + 0x0ff0] == 'D' && startup_partition_table[slot + 0x0ff1] == 'U' && startup_partition_table[slot + 0x0ff2] == 'A'
        && startup_partition_table[slot + 0x0ff3] == 'L' && startup_partition_table[slot + 0x0ff4] == 'F' && startup_partition_table[slot + 0x0ff5] == 'W') {
        for (i = 0; i < DUALFW_PARAM_COUNT; i++) {
            dualfw_param[i] = startup_partition_table[slot + DUALFW_PARAM_OFFSET + i];
            DAT_EXTMEM_f00a = REG_F00A_VALUE;
        }
        /* All three registers share the high address byte dualfw_param[0]. */
        patch_reg = (unsigned char xdata *)((dualfw_param[0] << 8) + dualfw_param[1]);
        *patch_reg &= dualfw_param[2];
        lib_printf((void code *)0x1886, (unsigned int)patch_reg, *patch_reg);   /* "[0x%04X] = %02BX\r\n" */
        patch_reg = (unsigned char xdata *)((dualfw_param[0] << 8) + dualfw_param[3]);
        *patch_reg |= dualfw_param[4];
        lib_printf((void code *)0x1886, (unsigned int)patch_reg, *patch_reg);
        patch_reg = (unsigned char xdata *)((dualfw_param[0] << 8) + dualfw_param[5]);
        /* dualfw_param[7] chooses AND (not 0) or OR (0) with dualfw_param[6]. */
        if (dualfw_param[7]) *patch_reg &= dualfw_param[6]; else *patch_reg |= dualfw_param[6];
        lib_printf((void code *)0x1886, (unsigned int)patch_reg, *patch_reg);
        DAT_EXTMEM_f00a = REG_F00A_VALUE;
        flash_identify();
    }

    /* Phase 4: a non-zero byte 0 of record 0 goes to the flash chip's extended address register. */
    if (startup_partition_table[slot]) SetExtendedAddr(startup_partition_table[slot]);

    /* Phase 5: length of the next program (record 0 bytes 5..7), low byte into 0xF1D6. */
    DAT_EXTMEM_f1d1 = 0;
    DAT_EXTMEM_f1d2 = 0;
    reg_copy_size_f1d6 = startup_partition_table[slot + 7];
    reg_copy_size_f1d7 = startup_partition_table[slot + 6];
    reg_copy_size_f1d8 = startup_partition_table[slot + 5];

    /* Phase 6: share block for the next program. */
    startup_share_block_write(SHARE_KIND_VERSION, 2, share_version);

    /* Kind 1: record 1 (table 0x08..0x0F); the last four of its 12 bytes are not written here. */
    startup_partition_entries[0x00] = startup_partition_table[slot + 0x08];
    startup_partition_entries[0x01] = startup_partition_table[slot + 0x09];
    startup_partition_entries[0x02] = startup_partition_table[slot + 0x0a];
    startup_partition_entries[0x03] = startup_partition_table[slot + 0x0b];
    startup_partition_entries[0x04] = startup_partition_table[slot + 0x0c];
    startup_partition_entries[0x05] = startup_partition_table[slot + 0x0d];
    startup_partition_entries[0x06] = startup_partition_table[slot + 0x0e];
    startup_partition_entries[0x07] = startup_partition_table[slot + 0x0f];
    startup_share_block_write(SHARE_KIND_USB_AGENT, 0x0c, &startup_partition_entries[0x00]);

    /* Kind 2 (0x24 bytes at 0xA00C): table 0x10..0x1B, fixed 9F 06 00 00, table 0x1C..0x23, eight zero bytes.
     * startup_load_core_images reads the fixed bytes as the 32-bit copy destination 0x9F060000. */
    startup_partition_entries[0x0c] = startup_partition_table[slot + 0x10];
    startup_partition_entries[0x0d] = startup_partition_table[slot + 0x11];
    startup_partition_entries[0x0e] = startup_partition_table[slot + 0x12];
    startup_partition_entries[0x0f] = startup_partition_table[slot + 0x13];
    startup_partition_entries[0x10] = startup_partition_table[slot + 0x14];
    startup_partition_entries[0x11] = startup_partition_table[slot + 0x15];
    startup_partition_entries[0x12] = startup_partition_table[slot + 0x16];
    startup_partition_entries[0x13] = startup_partition_table[slot + 0x17];
    startup_partition_entries[0x14] = startup_partition_table[slot + 0x18];
    startup_partition_entries[0x15] = startup_partition_table[slot + 0x19];
    startup_partition_entries[0x16] = startup_partition_table[slot + 0x1a];
    startup_partition_entries[0x17] = startup_partition_table[slot + 0x1b];
    startup_partition_entries[0x1c] = startup_partition_table[slot + 0x1c];
    startup_partition_entries[0x1d] = startup_partition_table[slot + 0x1d];
    startup_partition_entries[0x1e] = startup_partition_table[slot + 0x1e];
    startup_partition_entries[0x1f] = startup_partition_table[slot + 0x1f];
    startup_partition_entries[0x20] = startup_partition_table[slot + 0x20];
    startup_partition_entries[0x21] = startup_partition_table[slot + 0x21];
    startup_partition_entries[0x22] = startup_partition_table[slot + 0x22];
    startup_partition_entries[0x23] = startup_partition_table[slot + 0x23];
    startup_partition_entries[0x18] = 0x9f;
    startup_partition_entries[0x19] = 0x06;
    startup_partition_entries[0x1a] = 0x00;
    startup_partition_entries[0x1b] = 0x00;
    startup_partition_entries[0x24] = 0x00;
    startup_partition_entries[0x25] = 0x00;
    startup_partition_entries[0x26] = 0x00;
    startup_partition_entries[0x27] = 0x00;
    startup_partition_entries[0x28] = 0x00;
    startup_partition_entries[0x29] = 0x00;
    startup_partition_entries[0x2a] = 0x00;
    startup_partition_entries[0x2b] = 0x00;
    startup_share_block_write(SHARE_KIND_LEON2M, 0x24, &startup_partition_entries[0x0c]);

    /* Kind 3 (0x28 bytes at 0xA030): table 0x28..0x33, fixed 9F 19 60 00, table 0x34..0x37, table 0x40..0x47,
     * fixed 00 00 00 00 00 00 07 FF.  startup_load_core_images reads the first fixed bytes as the 32-bit copy
     * destination 0x9F196000.  Table bytes 0x38..0x3F go to kind 4 instead. */
    startup_partition_entries[0x30] = startup_partition_table[slot + 0x28];
    startup_partition_entries[0x31] = startup_partition_table[slot + 0x29];
    startup_partition_entries[0x32] = startup_partition_table[slot + 0x2a];
    startup_partition_entries[0x33] = startup_partition_table[slot + 0x2b];
    startup_partition_entries[0x34] = startup_partition_table[slot + 0x2c];
    startup_partition_entries[0x35] = startup_partition_table[slot + 0x2d];
    startup_partition_entries[0x36] = startup_partition_table[slot + 0x2e];
    startup_partition_entries[0x37] = startup_partition_table[slot + 0x2f];
    startup_partition_entries[0x38] = startup_partition_table[slot + 0x30];
    startup_partition_entries[0x39] = startup_partition_table[slot + 0x31];
    startup_partition_entries[0x3a] = startup_partition_table[slot + 0x32];
    startup_partition_entries[0x3b] = startup_partition_table[slot + 0x33];
    startup_partition_entries[0x40] = startup_partition_table[slot + 0x34];
    startup_partition_entries[0x41] = startup_partition_table[slot + 0x35];
    startup_partition_entries[0x42] = startup_partition_table[slot + 0x36];
    startup_partition_entries[0x43] = startup_partition_table[slot + 0x37];
    startup_partition_entries[0x44] = startup_partition_table[slot + 0x40];
    startup_partition_entries[0x45] = startup_partition_table[slot + 0x41];
    startup_partition_entries[0x46] = startup_partition_table[slot + 0x42];
    startup_partition_entries[0x47] = startup_partition_table[slot + 0x43];
    startup_partition_entries[0x48] = startup_partition_table[slot + 0x44];
    startup_partition_entries[0x49] = startup_partition_table[slot + 0x45];
    startup_partition_entries[0x4a] = startup_partition_table[slot + 0x46];
    startup_partition_entries[0x4b] = startup_partition_table[slot + 0x47];
    startup_partition_entries[0x3c] = 0x9f;
    startup_partition_entries[0x3d] = 0x19;
    startup_partition_entries[0x3e] = 0x60;
    startup_partition_entries[0x3f] = 0x00;
    startup_partition_entries[0x4c] = 0x00;
    startup_partition_entries[0x4d] = 0x00;
    startup_partition_entries[0x4e] = 0x00;
    startup_partition_entries[0x4f] = 0x00;
    startup_partition_entries[0x50] = 0x00;
    startup_partition_entries[0x51] = 0x00;
    startup_partition_entries[0x52] = 0x07;
    startup_partition_entries[0x53] = 0xff;
    startup_share_block_write(SHARE_KIND_LEON2S, 0x28, &startup_partition_entries[0x30]);

    /* Kinds 4, 6, 7, 8, 9: one 8-byte record each (table 0x38, 0x48, 0x50, 0x58, 0x60); the last four of their
     * 12 bytes are not written here.  Kind 5 is the flash information that flash_identify writes. */
    startup_partition_entries[0x58] = startup_partition_table[slot + 0x38];
    startup_partition_entries[0x59] = startup_partition_table[slot + 0x39];
    startup_partition_entries[0x5a] = startup_partition_table[slot + 0x3a];
    startup_partition_entries[0x5b] = startup_partition_table[slot + 0x3b];
    startup_partition_entries[0x5c] = startup_partition_table[slot + 0x3c];
    startup_partition_entries[0x5d] = startup_partition_table[slot + 0x3d];
    startup_partition_entries[0x5e] = startup_partition_table[slot + 0x3e];
    startup_partition_entries[0x5f] = startup_partition_table[slot + 0x3f];
    startup_share_block_write(SHARE_KIND_TENSILICA, 0x0c, &startup_partition_entries[0x58]);
    startup_partition_entries[0x64] = startup_partition_table[slot + 0x48];
    startup_partition_entries[0x65] = startup_partition_table[slot + 0x49];
    startup_partition_entries[0x66] = startup_partition_table[slot + 0x4a];
    startup_partition_entries[0x67] = startup_partition_table[slot + 0x4b];
    startup_partition_entries[0x68] = startup_partition_table[slot + 0x4c];
    startup_partition_entries[0x69] = startup_partition_table[slot + 0x4d];
    startup_partition_entries[0x6a] = startup_partition_table[slot + 0x4e];
    startup_partition_entries[0x6b] = startup_partition_table[slot + 0x4f];
    startup_share_block_write(SHARE_KIND_6, 0x0c, &startup_partition_entries[0x64]);
    startup_partition_entries[0x70] = startup_partition_table[slot + 0x50];
    startup_partition_entries[0x71] = startup_partition_table[slot + 0x51];
    startup_partition_entries[0x72] = startup_partition_table[slot + 0x52];
    startup_partition_entries[0x73] = startup_partition_table[slot + 0x53];
    startup_partition_entries[0x74] = startup_partition_table[slot + 0x54];
    startup_partition_entries[0x75] = startup_partition_table[slot + 0x55];
    startup_partition_entries[0x76] = startup_partition_table[slot + 0x56];
    startup_partition_entries[0x77] = startup_partition_table[slot + 0x57];
    startup_share_block_write(SHARE_KIND_7, 0x0c, &startup_partition_entries[0x70]);
    startup_partition_entries[0x7c] = startup_partition_table[slot + 0x58];
    startup_partition_entries[0x7d] = startup_partition_table[slot + 0x59];
    startup_partition_entries[0x7e] = startup_partition_table[slot + 0x5a];
    startup_partition_entries[0x7f] = startup_partition_table[slot + 0x5b];
    startup_partition_entries[0x80] = startup_partition_table[slot + 0x5c];
    startup_partition_entries[0x81] = startup_partition_table[slot + 0x5d];
    startup_partition_entries[0x82] = startup_partition_table[slot + 0x5e];
    startup_partition_entries[0x83] = startup_partition_table[slot + 0x5f];
    startup_share_block_write(SHARE_KIND_8, 0x0c, &startup_partition_entries[0x7c]);
    startup_partition_entries[0x88] = startup_partition_table[slot + 0x60];
    startup_partition_entries[0x89] = startup_partition_table[slot + 0x61];
    startup_partition_entries[0x8a] = startup_partition_table[slot + 0x62];
    startup_partition_entries[0x8b] = startup_partition_table[slot + 0x63];
    startup_partition_entries[0x8c] = startup_partition_table[slot + 0x64];
    startup_partition_entries[0x8d] = startup_partition_table[slot + 0x65];
    startup_partition_entries[0x8e] = startup_partition_table[slot + 0x66];
    startup_partition_entries[0x8f] = startup_partition_table[slot + 0x67];
    startup_share_block_write(SHARE_KIND_9, 0x0c, &startup_partition_entries[0x88]);

    /* Phase 7 */
    return table_ok;
}
