/* flash_dma_read  (FUN_CODE_8d60)
 *
 * Start a flash DMA read of a block and wait until it finishes.
 *   flash_addr: flash address
 *   byte_count
 *   dma_mode: channel byte
 * Name basis: proven - docs/MAP.md: Tensilica program load via startup_load_tensilica_image; registers
 *   0xF60A.., 0xF0EA..; poll 0xF0E5 bit 1
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_8d60 @ 0x8d60..0x8e61 (257 bytes), OPTIMIZE(8,SPEED) LARGE.
 * LARGE slots: flash_addr 0xA4EA, byte_count 0xA4EE, dma_mode 0xA4F2, split 0xA4F3 (stored with ?C?LSTXDATA,
 * read back byte by byte). byte_count / 4 is computed twice (?C?ULDIV each time).
 * Source form: volatile only on reg_flash_spi_start (polled); the poll test is cast to unsigned int for the
 * firmware's ANL / JNZ.
 */
typedef union { unsigned long l; unsigned char b[4]; } DW;
extern unsigned char xdata DAT_EXTMEM_f60a, DAT_EXTMEM_f60b, reg_dma_flash_count_low, reg_dma_flash_count_high, DAT_EXTMEM_f60e;
extern unsigned char xdata reg_dma_ctrl, reg_dma_status;
extern unsigned char volatile xdata reg_flash_spi_start;
extern unsigned char xdata reg_flash_spi_mode, reg_flash_spi_read_opcode;
extern unsigned char xdata reg_flash_spi_count_high, reg_flash_spi_count_mid, reg_flash_spi_count_low;
extern unsigned char xdata reg_flash_spi_addr_high, reg_flash_spi_addr_mid, reg_flash_spi_addr_low, reg_flash_spi_format;
extern unsigned char xdata reg_flash_fifo_port;
extern unsigned char xdata flash_read_opcode;
extern bit flash_extended_addr_flag;
extern void flash_write_extended_addr(unsigned char ext);

#define DMA_CTRL_FLASH_READ      0x40  /* reg_dma_ctrl: flash read job */
#define DMA_DONE_OTHER           0x40  /* reg_dma_status bit 6, acknowledged by writing it back */
#define SPI_MODE_KEEP_BUS        0x0c  /* bits 2..3 of reg_flash_spi_mode are kept */
#define SPI_MODE_READ            0x01  /* read or program transfer */
#define SPI_FORMAT_WITH_ADDRESS  3     /* opcode followed by a 3-byte address */
#define SPI_START_READ           0x02  /* reg_flash_spi_start bit 1: set to start a read, clears when done */

/*
 * flash_dma_read - copy a block of the SPI flash by DMA and wait until the transfer is done.
 *   flash_addr  flash address of the block; bits 0..23 go to the SPI address registers
 *   byte_count  length in bytes; the DMA count registers get byte_count / 4, the SPI count registers bits 0..23
 *   dma_mode    written to DMA register 0xF60E (the only caller passes 1)
 * When flash_extended_addr_flag is set, bits 24..31 of the address are first written to the flash's extended
 * address register (flash_write_extended_addr). The only caller, startup_load_tensilica_image, passes this bit
 * as its fourth (bit) argument when it loads the Tensilica program at start-up.
 * Order: set up the DMA job, start it, set up the SPI read (opcode from flash_read_opcode: quad, dual or fast
 * read as chosen at start-up), start the read, wait for reg_flash_spi_start bit 1 to clear, acknowledge the DMA
 * done bit and stop the DMA.
 */
void flash_dma_read(unsigned long flash_addr, unsigned long byte_count, unsigned char dma_mode)
{
    DW split;   /* the 32-bit values taken apart into bytes, most significant first */

    DAT_EXTMEM_f60a = 0;
    DAT_EXTMEM_f60b = 0;
    reg_dma_flash_count_low = byte_count / 4;
    reg_dma_flash_count_high = (byte_count / 4) >> 8;
    DAT_EXTMEM_f60e = dma_mode;
    if (flash_extended_addr_flag)
        flash_write_extended_addr((unsigned char)((flash_addr >> 24) & 0xff));
    reg_dma_ctrl = DMA_CTRL_FLASH_READ;
    reg_flash_spi_read_opcode = flash_read_opcode;
    reg_flash_spi_mode = (reg_flash_spi_mode & SPI_MODE_KEEP_BUS) | SPI_MODE_READ;
    split.l = byte_count;
    reg_flash_spi_count_high = split.b[1];
    reg_flash_spi_count_mid = split.b[2];
    reg_flash_spi_count_low = split.b[3];
    split.l = flash_addr;
    reg_flash_spi_addr_high = split.b[1];
    reg_flash_spi_addr_mid = split.b[2];
    reg_flash_spi_addr_low = split.b[3];
    reg_flash_spi_format = SPI_FORMAT_WITH_ADDRESS;
    reg_flash_fifo_port = 0;
    reg_flash_spi_start = SPI_START_READ;
    while ((unsigned int)(reg_flash_spi_start & SPI_START_READ))
        ;
    reg_dma_status = DMA_DONE_OTHER;
    reg_dma_ctrl = 0;
}
