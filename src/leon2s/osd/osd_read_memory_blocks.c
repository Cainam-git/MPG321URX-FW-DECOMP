/* osd_read_memory_blocks  (FUN_a006c9c0)
 *
 * Read 8-word blocks of packed data through the 0xCF011F80 register port.
 *   out: buffer
 *   addr: first block
 *   n: block count
 * Name basis: derived - address bytes to 0xCF011FA0.., waits for 0x80, data from 0xCF011F94; same routine as
 *   the main processor's
 *
 * Matching notes
 * --------------
 * Flags -mcpu=v8 -Os -g -msoft-float (-msoft-float changes the loop-invariant threshold, as in
 * DRV_HDMI21_RXDetect_FSM_LTS_3). Same source form as the main processor's FUN_a0113cd8, except that the byte
 * order comes from osd_unzip_mode. The wait counter reuses the word-loop counter j. out[j] is updated after
 * every register read, not built in a temporary. volatile only on the hardware registers.
 */
#define REG(a) (*(volatile unsigned int *)(a))

extern unsigned char osd_unzip_mode;

/*
 * Read n blocks of 8 words each through the register port at 0xcf011f80 into out[].
 *
 *   out   buffer, n * 8 words
 *   addr  number of the first block; goes up by one per block
 *   n     number of blocks
 *
 * Per block: the four bytes of addr are written to 0xcf011fa0..0xcf011fac, 0x80 to 0xcf011f84 and 0xcf011f8c,
 * then 0xcf011f90 is polled (at most 0xffff times) for 0x80. A block that does not report ready is read anyway.
 * Each word takes four reads of 0xcf011f94. Their order follows osd_unzip_mode (set by osd_request_unzip):
 * mode 1 puts the first byte read in the low byte of the word, any other mode in the high byte.
 * Called by osd_read_packed_chunk.
 */
void osd_read_memory_blocks(unsigned int *out, unsigned int addr, unsigned short n)
{
    unsigned short i, j;

    for (i = 0; i < n; i++) {
        REG(0xcf011fa0) = addr;
        REG(0xcf011fa4) = addr >> 8;
        REG(0xcf011fa8) = addr >> 16;
        REG(0xcf011fac) = addr >> 24;
        REG(0xcf011f84) = 0x80;
        REG(0xcf011f8c) = 0x80;
        j = 0xffff;
        while (REG(0xcf011f90) != 0x80) {
            if (--j == 0)
                break;
        }
        if (osd_unzip_mode == 1) {
            /* First byte read is the low byte. */
            for (j = i * 8; j < i * 8 + 8; j++) {
                out[j] = REG(0xcf011f94);
                out[j] |= REG(0xcf011f94) << 8;
                out[j] |= REG(0xcf011f94) << 16;
                out[j] |= REG(0xcf011f94) << 24;
            }
        } else {
            /* First byte read is the high byte. */
            for (j = i * 8; j < i * 8 + 8; j++) {
                out[j] = REG(0xcf011f94) << 24;
                out[j] |= REG(0xcf011f94) << 16;
                out[j] |= REG(0xcf011f94) << 8;
                out[j] |= REG(0xcf011f94);
            }
        }
        addr++;
    }
}
