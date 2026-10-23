/* 8051_bank1 FUN_CODE_c43e @ 0xC43E..0xC496 (88 bytes)  STBC start-up: flash DMA of one extra record (only when XDATA
 * 0xD511 is 0x16, 0x1E, 0x1F or 0x17). OPTIMIZE(8,SPEED) LARGE.
 * What it does (code): F152 = 0x42; FUN_CODE_8d60(p[0], p[1], 1, b); F152 = 0x5B; F152 = 0x0B.
 *   p (generic pointer, saved at XDATA 0xA4E7) points to two 32-bit words: p[0] is loaded with ?C?LLDPTR (0x0913),
 *   p[1] with ?C?LLDOPTR at offset 4 (0x0933). b is the 4-byte-address flag (bit 0x20.1 -> 8d60's bit 0x20.2).
 *   FUN_CODE_8d60(src, len, mode, four_byte) (read from the code): F60A = F60B = 0, F60C/F60D = len / 4
 *   (16-bit word count), F60E = mode, four_byte -> FUN_CODE_d81c(src >> 24) (flash extended address), F600 = 0x40,
 *   then the same SPI flash read registers as the image copy FUN_CODE_738c (F0EA, F0E6, F0EB..F0ED = len,
 *   F0F0..F0F2 = src, F0F4, F1C0, F0E5 start/wait). Unlike 738c (F600 = 0xA0, AHB destination in F602..F605) it
 *   writes no destination address.
 * Only caller FUN_CODE_0b0d at 0x0C69: c43e(&record[0x58] = XDATA 0xA4D7, f), run only when the register
 *   0xD511 is 0x16, 0x1E, 0x1F or 0x17 (0x0C49..0x0C5C), after 96eb(&0xA47F) and before F150 = 0x39 / 0x36 and the
 *   Leon2 Main set-up FUN_CODE_4a85. The record block 0xA47F.. is the boot loader's share structure copy.
 * The function copies whatever record +0x58 names and does not touch the Big chip's image window.
 * volatile only on the hardware register 0xF152.
 */
#pragma LARGE
extern unsigned char volatile xdata DAT_EXTMEM_f152;
extern void FUN_CODE_8d60(unsigned long src, unsigned long len, unsigned char mode, bit four_byte);

void FUN_CODE_c43e(unsigned long *p, bit b)
{
    DAT_EXTMEM_f152 = 0x42;
    FUN_CODE_8d60(p[0], p[1], 1, b);
    DAT_EXTMEM_f152 = 0x5B;
    DAT_EXTMEM_f152 = 0x0B;
}
