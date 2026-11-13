/* startup_dma_fill  (FUN_CODE_a8bb)
 *
 * Fill the rest of a memory window by DMA without a source.
 * Name basis: proven - docs/MAP.md: fill routine of startup_load_core_images
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_a8bb @ 0xa8bb..0xa958, OPTIMIZE(8,SPEED) LARGE.
 * Parameters in the LARGE block: dst 0xA4E7 (arrives in R4..R7), len 0xA4EB, mode 0xA4EF; the union local is
 *   XDATA 0xA4F0 (the firmware moves the long's bytes one by one).
 * Source forms: '(unsigned int)(reg_dma_status & m)' gives ANL/JZ for the waits (as in startup_copy_flash_image);
 *   the acknowledge is written through the absolute address '*(volatile unsigned char xdata *)0xf601', which makes
 *   Keil reload DPTR (with the named register it reuses DPTR, 3 bytes short). Same register, same access.
 */
extern volatile unsigned char xdata reg_dma_ctrl, reg_dma_status, reg_dma_dst_7_0, reg_dma_dst_15_8, reg_dma_dst_23_16, reg_dma_dst_31_24;
extern volatile unsigned char xdata reg_dma_count_7_0, reg_dma_count_15_8, reg_dma_count_23_16, reg_dma_count_31_24;

#define DMA_CTRL_FILL      0x04   /* reg_dma_ctrl for mode 0 */
#define DMA_CTRL_MODE_1    0x02   /* reg_dma_ctrl for mode 1 */
#define DMA_STATUS_DONE    0x80   /* reg_dma_status bit 7, acknowledged by writing it back */
#define DMA_DONE_OTHER     0x40   /* reg_dma_status bit 6, acknowledged by writing it back */

/*
 * startup_dma_fill - run the image DMA engine over len bytes at dst without a flash source.
 *   dst   destination address in the 0x9F000000 range
 *   len   byte count; the DMA count registers take it in 4-byte words
 *   mode  0: control 0x04, wait for status bit 7; 1: control 0x02, wait for status bit 6; other: nothing started
 * Destination and word count go into the same registers as in startup_copy_flash_image; the DMA control is
 * cleared at the end in every mode.
 * Only caller: startup_load_core_images, always with mode 0, for the unused rest of the run-time windows after
 * the Leon2M and Leon2S images.
 */
void startup_dma_fill(unsigned long dst, unsigned long len, unsigned char mode)
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
    if (mode == 0) {
        reg_dma_ctrl = DMA_CTRL_FILL;
        while (!(unsigned int)(reg_dma_status & DMA_STATUS_DONE)) ;
        *(volatile unsigned char xdata *)0xf601 = DMA_STATUS_DONE;   /* reg_dma_status */
    } else if (mode == 1) {
        reg_dma_ctrl = DMA_CTRL_MODE_1;
        while (!(unsigned int)(reg_dma_status & DMA_DONE_OTHER)) ;
        *(volatile unsigned char xdata *)0xf601 = DMA_DONE_OTHER;    /* reg_dma_status */
    }
    reg_dma_ctrl = 0;
}
