/* startup_load_core_images  (FUN_CODE_0b0d)
 *
 * Set up the chip and copy the other processors' programs to their run-time memory.
 * Note: Also starts the USB update agent (startup_start_usb_agent) and both LEON cores.
 * Name basis: proven - docs/MAP.md start-up step 2; prints 'Share Structure version is differnet with
 *   Bootloader!!'; calls the image copy and core set-up
 *
 * Matching notes
 * --------------
 * Built with OPTIMIZE(8,SPEED) LARGE. One C function over 0x0B0D..0x147A (2413 bytes); the piece at 0x1397 is the
 * else-arm of the last image record, reached only by jumps from inside this function.
 * Source forms the exact build depends on:
 * - startup_copy_flash_image stays in this file and is defined AFTER startup_load_core_images: Keil builds the
 *   three common-entry pieces 0x7352 / 0x7369 / 0x7381 in front of it only when its callers are in the same module.
 * - The fit tests are written 'room > len' (not 'len < room' / 'len <= room'); the sums keep the operand order
 *   'src + len' and 'excess + 0x9f060000'.
 * - The three-level else-if of the Leon2S record stays as written (Keil jumps into the middle of the shared tail).
 * - The chip registers 0xD000.. / 0xE000.. / 0xF000.. are declared volatile.
 * - The locals room / excess / end sit in XDATA 0xA473 / 0xA477 / 0xA47B; four_byte_addr is bit 0x20.0.
 */
extern volatile unsigned char xdata DAT_EXTMEM_d92d;
extern volatile unsigned char xdata DAT_EXTMEM_daf1[3];
extern volatile unsigned char xdata DAT_EXTMEM_dd09;
extern volatile unsigned char xdata DAT_EXTMEM_e1e0;
extern volatile unsigned char xdata DAT_EXTMEM_e001[3];
extern volatile unsigned char xdata DAT_EXTMEM_e011[3];
extern volatile unsigned char xdata DAT_EXTMEM_f400;
extern volatile unsigned char xdata DAT_EXTMEM_f00a;
extern volatile unsigned char xdata DAT_EXTMEM_f0e0;
extern volatile unsigned char xdata DAT_EXTMEM_f150;
extern volatile unsigned char xdata reg_chip_id;
extern unsigned char xdata startup_share_block[0x6a];
extern unsigned char xdata startup_share_copy[0x6a];
extern void lib_printf517(void *fmt, ...) large;
extern void flash_begin_access(void);
extern void flash_reset_fifo(void);
extern void startup_start_usb_agent(void *p);
extern void startup_load_tensilica_image(void *p, bit b);
extern void startup_setup_leon2m(void *p);
extern void startup_setup_leon2s(void *p);
extern unsigned long xdata startup_share_copy_0x0c, startup_share_copy_0x10, startup_share_copy_0x14, startup_share_copy_0x18, startup_share_copy_0x1c;
extern unsigned long xdata startup_share_copy_0x20, startup_share_copy_0x30, DAT_EXTMEM_a4b3, DAT_EXTMEM_a4b7, startup_share_copy_0x3c, DAT_EXTMEM_a4bf;
extern unsigned long xdata startup_share_copy_0x44, startup_share_copy_0x48, flash_leon2_base_address;
extern unsigned char xdata reg_flash_leon2_base_7_0, reg_flash_leon2_base_15_8, reg_flash_leon2_base_23_16, reg_flash_leon2_base_31_24, reg_flash_access_ctrl;
extern void startup_dma_fill(unsigned long addr, unsigned long len, unsigned char mode);
extern void startup_run_leon2m(void);
extern void startup_run_leon2s(void);
extern unsigned char xdata DAT_EXTMEM_a4f3;

void startup_copy_flash_image(unsigned long src, unsigned long dst, unsigned long len, bit four_byte_addr);

/* Share block version the boot loader writes first (two bytes, 00 01). */
#define SHARE_BLOCK_VERSION 1

/*
 * startup_load_core_images - first job of sys_main: copy the programs of the other processors out of the SPI flash
 * into their run-time memory and start the USB update agent and both LEON processors.
 *
 * Input: the share block at XDATA 0x3000 that the boot loader filled. Its entries (kind: offset, length; the boot
 * loader's startup_share_block_write puts two bytes in front of each entry 1..4) are copied, without those gaps,
 * into startup_share_copy:
 *   kind 1  share +0x02 -> copy +0x00 (12 bytes): record handed to startup_start_usb_agent.
 *   kind 2  share +0x0E -> copy +0x0C (0x24 bytes): the Leon2M record
 *           +0x0C flash address and +0x10 length of the first image,
 *           +0x14 flash address, +0x18 destination and +0x1C length of the second image
 *           (the boot loader always stores 0x9F060000 as that destination),
 *           +0x20 a flash address that ends up in 0xF1DB..0xF1DE and flash_leon2_base_address.
 *   kind 3  share +0x32 -> copy +0x30 (0x28 bytes): the Leon2S record
 *           +0x30 flash address and +0x34 length of the first part,
 *           +0x38 flash address, +0x3C destination (the boot loader always stores 0x9F196000) and +0x40 length of
 *           the second part, +0x44 flash address and +0x48 length of the third part.
 *   kind 4  share +0x5A -> copy +0x58 (12 bytes): handed to startup_load_tensilica_image.
 *   kind 5  share +0x66 -> copy +0x64 (4 bytes): the boot loader's flash identification (chip index, erase
 *           opcode, 16-bit flash size code).
 * With this firmware's partition table (CODE 0x6000) the records are: Leon2M start-up code flash 0x0D0000
 * (0x7B44 bytes) and initialised data 0x0EC000 (0x6F38 bytes), +0x20 = 0x108000 (the Leon2M code window,
 * docs/MAP.md); Leon2S parts 0x050000 (0x54F60), 0x0A6000 (0x27E0), 0x0B0000 (0x1EEC5); Tensilica 0x030000 (0xD8DC).
 *
 * Phases, in order:
 *   1. Writes to chip registers 0xD92D, 0xDAF1.., 0xDD09, 0xE1E0, 0xE001.., 0xE011.., 0xF400 (purpose not shown).
 *   2. Share block version check: anything but 1 prints 'Share Structure version is differnet with Bootloader!!'
 *      and stops here for good, writing 0x55 to 0xF00A and 0xF0E0 in an endless loop.
 *   3. Copy the share block entries into startup_share_copy (layout above).
 *   4. Flash set-up and early starts: decide the flash address width, claim the flash interface, start the USB
 *      update agent, load the Tensilica program (chip IDs 0x16 / 0x1E / 0x1F / 0x17 only), set up both LEON
 *      processors.
 *   5. Leon2M images: the first image into the window at 0x9F040000, the second into 0x9F060000..0x9F07C000; the
 *      unused rest of the second window is filled by startup_dma_fill.
 *   6. Leon2S images: the first part split over 0x9F1A0000 / 0x9F140000 / 0x9F180000, the third part to
 *      0x9F1B0000 (same chip IDs as in phase 4), the second part into 0x9F178000..0x9F1A0000 with the same
 *      fit-or-overflow logic as phase 5.
 *   7. Hand the +0x20 flash address to 0xF1DB..0xF1DE, give the flash interface back (bit 7 of 0xF1DF clear),
 *      release both LEON processors and keep the address in flash_leon2_base_address.
 *
 * In phases 5 and 6 the branch for a destination below the window end is never taken with the destinations the
 * boot loader stores (0x9F060000 >= 0x9F05C000, 0x9F196000 >= 0x9F178000). In that branch the first fill starts at
 * the flash source address plus the length, not at the destination plus the length.
 * Called by sys_main at start-up and again on wake-up.
 */
void startup_load_core_images(void)
{
    bit four_byte_addr;
    unsigned char i;
    unsigned int share_version;
    unsigned long room, excess, end;

    /* Phase 1: chip register set-up. */
    four_byte_addr = 0;
    DAT_EXTMEM_d92d |= 0x80;
    DAT_EXTMEM_daf1[0] = 0xaa;
    DAT_EXTMEM_daf1[1] = 0xaa;
    DAT_EXTMEM_daf1[2] = 0x42;
    DAT_EXTMEM_dd09 = 2;
    DAT_EXTMEM_e1e0 |= 1;
    DAT_EXTMEM_e001[0] = 0xaa;
    DAT_EXTMEM_e001[1] = 0x2a;
    DAT_EXTMEM_e001[2] = 0x2e;
    DAT_EXTMEM_e1e0 |= 2;
    DAT_EXTMEM_e011[0] = 0;
    DAT_EXTMEM_e011[1] = 0;
    DAT_EXTMEM_e011[2] = 8;
    DAT_EXTMEM_f400 |= 1;

    /* Phase 2: the share block must come from a boot loader with the same layout (version, high byte first). */
    share_version = startup_share_block[0];
    share_version = share_version << 8 | startup_share_block[1];
    if (share_version != SHARE_BLOCK_VERSION) {
        /* 'Share Structure version is differnet with Bootloader!!' */
        lib_printf517((void code *)0x821b);
        for (;;) {
            DAT_EXTMEM_f00a = 0x55;
            DAT_EXTMEM_f0e0 = 0x55;
        }
    }

    /* Phase 3: entries 1..5 of the share block, without the two bytes in front of each. */
    i = 0;
    do ((unsigned char *)&startup_share_copy)[i] = startup_share_block[2 + i]; while (++i != 12);
    i = 0;
    do ((unsigned char *)&startup_share_copy)[0x0c + i] = startup_share_block[0x0e + i]; while (++i != 0x24);
    i = 0;
    do ((unsigned char *)&startup_share_copy)[0x30 + i] = startup_share_block[0x32 + i]; while (++i != 0x28);
    i = 0;
    do ((unsigned char *)&startup_share_copy)[0x58 + i] = startup_share_block[0x5a + i]; while (++i != 12);
    i = 0;
    do ((unsigned char *)&startup_share_copy)[0x64 + i] = startup_share_block[0x66 + i]; while (++i != 4);

    /* Phase 4: a flash size code above 4 (high byte of copy +0x66) makes every image copy first set the flash's
       extended address register to the top byte of the source address. */
    if ((*(unsigned int xdata *)&startup_share_copy[0x66] & 0xff00) > 0x400) four_byte_addr = 1;
    flash_begin_access();
    flash_reset_fifo();
    startup_start_usb_agent(startup_share_copy);
    if (reg_chip_id == 0x16 || reg_chip_id == 0x1e || reg_chip_id == 0x1f || reg_chip_id == 0x17)
        startup_load_tensilica_image(&startup_share_copy[0x58], four_byte_addr);
    DAT_EXTMEM_f150 = 0x39;
    DAT_EXTMEM_f150 = 0x36;
    startup_setup_leon2m(&startup_share_copy[0x0c]);
    startup_setup_leon2s(&startup_share_copy[0x30]);

    /* Phase 5a: Leon2M first image; the window at 0x9F040000 takes 0x1C000 bytes, the rest goes to 0x9F060000. */
    if (startup_share_copy_0x10 > 0x1c000) {
        startup_copy_flash_image(startup_share_copy_0x0c, 0x9f040000, 0x1c000, four_byte_addr);
        startup_copy_flash_image(startup_share_copy_0x0c + 0x1c000, 0x9f060000, startup_share_copy_0x10 - 0x1c000, four_byte_addr);
    } else {
        startup_copy_flash_image(startup_share_copy_0x0c, 0x9f040000, startup_share_copy_0x10, four_byte_addr);
    }
    /* Phase 5b: Leon2M second image. */
    if (startup_share_copy_0x18 < 0x9f05c000) {
        /* Destination inside the first window (not reached with the boot loader's 0x9F060000). */
        room = 0x9f05c000 - startup_share_copy_0x18;
        if (room > startup_share_copy_0x1c) {
            /* Fits: copy it, fill the rest of the first window and all of 0x9F060000..0x9F07C000. */
            startup_copy_flash_image(startup_share_copy_0x14, startup_share_copy_0x18, startup_share_copy_0x1c, four_byte_addr);
            startup_dma_fill(startup_share_copy_0x14 + startup_share_copy_0x1c, room - startup_share_copy_0x1c, 0);
            startup_dma_fill(0x9f060000, 0x1c000, 0);
        } else {
            /* Too long: the overflow continues at 0x9F060000, the rest of that window is filled. */
            excess = startup_share_copy_0x1c - room;
            startup_copy_flash_image(startup_share_copy_0x14, startup_share_copy_0x18, room, four_byte_addr);
            startup_copy_flash_image(startup_share_copy_0x14 + room, 0x9f060000, excess, four_byte_addr);
            startup_dma_fill(excess + 0x9f060000, 0x1c000 - excess, 0);
        }
    } else {
        /* Destination in the second window: copy, then fill up to its end 0x9F07C000. */
        end = startup_share_copy_0x18 + startup_share_copy_0x1c;
        startup_copy_flash_image(startup_share_copy_0x14, startup_share_copy_0x18, startup_share_copy_0x1c, four_byte_addr);
        startup_dma_fill(end, 0x9f07c000 - end, 0);
    }

    /* Phase 6a: Leon2S first part: 0x8000 bytes to 0x9F1A0000, the next 0x38000 to 0x9F140000, the rest to
       0x9F180000. */
    if (DAT_EXTMEM_a4b3 > 0x40000) {
        startup_copy_flash_image(startup_share_copy_0x30, 0x9f1a0000, 0x8000, four_byte_addr);
        startup_copy_flash_image(startup_share_copy_0x30 + 0x8000, 0x9f140000, 0x38000, four_byte_addr);
        startup_copy_flash_image(startup_share_copy_0x30 + 0x40000, 0x9f180000, DAT_EXTMEM_a4b3 - 0x40000, four_byte_addr);
    } else if (DAT_EXTMEM_a4b3 > 0x8000) {
        startup_copy_flash_image(startup_share_copy_0x30, 0x9f1a0000, 0x8000, four_byte_addr);
        startup_copy_flash_image(startup_share_copy_0x30 + 0x8000, 0x9f140000, DAT_EXTMEM_a4b3 - 0x8000, four_byte_addr);
    } else {
        startup_copy_flash_image(startup_share_copy_0x30, 0x9f1a0000, DAT_EXTMEM_a4b3, four_byte_addr);
    }
    /* Phase 6b: Leon2S third part, only on the chips that also get the Tensilica program. */
    if (reg_chip_id == 0x16 || reg_chip_id == 0x1e || reg_chip_id == 0x1f || reg_chip_id == 0x17) {
        if (startup_share_copy_0x48 > 0)
            startup_copy_flash_image(startup_share_copy_0x44, 0x9f1b0000, startup_share_copy_0x48, four_byte_addr);
    }
    /* Phase 6c: Leon2S second part, same pattern as phase 5b with window ends 0x9F178000 / 0x9F1A0000 and the
       overflow window 0x9F180000 (0x20000 bytes). */
    if (startup_share_copy_0x3c < 0x9f178000) {
        room = 0x9f178000 - startup_share_copy_0x3c;
        if (room > DAT_EXTMEM_a4bf) {
            startup_copy_flash_image(DAT_EXTMEM_a4b7, startup_share_copy_0x3c, DAT_EXTMEM_a4bf, four_byte_addr);
            startup_dma_fill(DAT_EXTMEM_a4b7 + DAT_EXTMEM_a4bf, room - DAT_EXTMEM_a4bf, 0);
            startup_dma_fill(0x9f180000, 0x20000, 0);
        } else {
            excess = DAT_EXTMEM_a4bf - room;
            startup_copy_flash_image(DAT_EXTMEM_a4b7, startup_share_copy_0x3c, room, four_byte_addr);
            startup_copy_flash_image(DAT_EXTMEM_a4b7 + room, 0x9f180000, excess, four_byte_addr);
            startup_dma_fill(excess + 0x9f180000, 0x20000 - excess, 0);
        }
    } else {
        end = startup_share_copy_0x3c + DAT_EXTMEM_a4bf;
        startup_copy_flash_image(DAT_EXTMEM_a4b7, startup_share_copy_0x3c, DAT_EXTMEM_a4bf, four_byte_addr);
        startup_dma_fill(end, 0x9f1a0000 - end, 0);
    }

    /* Phase 7: flash address of copy +0x20 into 0xF1DB..0xF1DE, low byte first (Keil longs are high byte first). */
    reg_flash_leon2_base_7_0 = ((unsigned char xdata *)&startup_share_copy_0x20)[3];
    reg_flash_leon2_base_15_8 = ((unsigned char xdata *)&startup_share_copy_0x20)[2];
    reg_flash_leon2_base_23_16 = ((unsigned char xdata *)&startup_share_copy_0x20)[1];
    reg_flash_leon2_base_31_24 = ((unsigned char xdata *)&startup_share_copy_0x20)[0];
    /* Bit 7 clear: the 8051's claim from flash_begin_access ends here. */
    if (reg_chip_id == 0x1a) reg_flash_access_ctrl = 0x43; else reg_flash_access_ctrl = 0x03;
    startup_run_leon2m();
    startup_run_leon2s();
    flash_leon2_base_address = startup_share_copy_0x20;
}

extern volatile unsigned char xdata reg_dma_ctrl, reg_dma_status, reg_dma_dst_7_0, reg_dma_dst_15_8, reg_dma_dst_23_16, reg_dma_dst_31_24;
extern volatile unsigned char xdata reg_dma_count_7_0, reg_dma_count_15_8, reg_dma_count_23_16, reg_dma_count_31_24;
extern volatile unsigned char xdata reg_flash_spi_start, reg_flash_spi_mode, reg_flash_spi_read_opcode, reg_flash_spi_count_high, reg_flash_spi_count_mid, reg_flash_spi_count_low;
extern volatile unsigned char xdata reg_flash_spi_addr_high, reg_flash_spi_addr_mid, reg_flash_spi_addr_low, reg_flash_spi_format, reg_flash_fifo_port;
extern unsigned char xdata flash_read_opcode;
extern void flash_write_extended_addr(unsigned char ext);

/*
 * startup_copy_flash_image - copy len bytes from SPI flash address src to the memory address dst with the image
 * DMA engine, and wait until the flash side is done.
 *   src             flash address (only the low three bytes go to the SPI address registers)
 *   dst             destination address in the 0x9F000000 range
 *   len             byte count; the DMA count registers take it in 4-byte words
 *   four_byte_addr  set: first write the top byte of src to the flash's extended address register
 * Steps: destination and word count into the DMA registers (0xF602.. / 0xF606.., low byte first), extended
 * address if needed, DMA control 0xA0, then the SPI read job (opcode from flash_read_opcode, mode, count, address,
 * format 3), start bit 1 of 0xF0E5, wait until it clears, acknowledge the DMA status (0x80) and stop the DMA.
 * Callers: startup_load_core_images only.
 * Matching notes: byte-exact under OPTIMIZE(8,SPEED) LARGE at 0x738C..0x74AE (291 bytes); its code segment
 * starts at 0x7352 with the common-entry pieces 0x7352 / 0x7369 / 0x7381 built from the calls above.
 * Parameters in the LARGE block: src 0xA4E7 (arrives in R4..R7), dst 0xA4EB, len 0xA4EF, four_byte_addr bit 0x20.1;
 * the union local is XDATA 0xA4F3. Keil forms: '(src >> 24) & 0xff' gives the CLR A before the call at 0x7419;
 * '(unsigned int)(reg_flash_spi_start & 2)' gives ANL A,#2 / JNZ for the busy wait (a plain '& 2' gives JB ACC.1).
 */
void startup_copy_flash_image(unsigned long src, unsigned long dst, unsigned long len, bit four_byte_addr)
{
    union { unsigned long l; unsigned char b[4]; } bytes;   /* b[0] = high byte */
    bytes.l = dst;
    reg_dma_dst_31_24 = bytes.b[0];
    reg_dma_dst_23_16 = bytes.b[1];
    reg_dma_dst_15_8 = bytes.b[2];
    reg_dma_dst_7_0 = bytes.b[3];
    bytes.l = len / 4;
    reg_dma_count_7_0 = bytes.b[3];
    reg_dma_count_15_8 = bytes.b[2];
    reg_dma_count_23_16 = bytes.b[1];
    reg_dma_count_31_24 = bytes.b[0];
    if (four_byte_addr) flash_write_extended_addr((unsigned char)((src >> 24) & 0xff));
    reg_dma_ctrl = 0xa0;
    reg_flash_spi_read_opcode = flash_read_opcode;
    reg_flash_spi_mode = reg_flash_spi_mode & 0x0c | 1;
    bytes.l = len;
    reg_flash_spi_count_high = bytes.b[1];
    reg_flash_spi_count_mid = bytes.b[2];
    reg_flash_spi_count_low = bytes.b[3];
    bytes.l = src;
    reg_flash_spi_addr_high = bytes.b[1];
    reg_flash_spi_addr_mid = bytes.b[2];
    reg_flash_spi_addr_low = bytes.b[3];
    reg_flash_spi_format = 3;
    reg_flash_fifo_port = 0;
    reg_flash_spi_start = 2;
    while ((unsigned int)(reg_flash_spi_start & 2)) ;
    reg_dma_status = 0x80;
    reg_dma_ctrl = 0;
}
