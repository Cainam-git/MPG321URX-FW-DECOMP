/* osd_write_memory_blocks  (FUN_a006c788)
 *
 * Write unpacked 8-word blocks into OSD memory, directly or through the register port.
 *   buf: block index
 *   addr: words
 *   n: block count
 * Name basis: derived - only caller osd_unzip_data; byte-swapped words to 0x20000000 + addr * 32 under the
 *   0xCF03C840 lock or via 0xCF011F88
 *
 * Matching notes
 * --------------
 * leon2s 0xa006c788-0xa006c9c0 (568 bytes), flags -mcpu=v8 -Os -g -msoft-float.
 * Source form: three loop variables (b counts the memory blocks, i is the memory word index and
 * the port block counter, j the port word index); every port byte is written as '(w >> s) & 0xff'.
 * Compiled with -msoft-float (it lowers the loop-invariant threshold: the 0xcf011fa0 address and the 0x80
 * constant are hoisted after the other port addresses, as in the firmware).
 */
extern unsigned char osd_unzip_mode;

#define R(a) (*(volatile unsigned int *)(a))

#define SHARED_LOCK        0xcf03c840       /* lock shared with the main processor */
#define LOCK_FREE          0
#define LOCK_BUSY          1
#define LOCK_HELD_HERE     2
#define OSD_MEM_MODE_REG   0xcf013428       /* bit 0 is set while the OSD memory is written directly */
#define OSD_MEMORY_BASE    0x20000000       /* one block is 8 words = 32 bytes */

/* Take the shared lock: poll up to 0x10000 times (writing HELD_HERE unless the register reads BUSY) until it
   reads HELD_HERE, then write HELD_HERE once more whether or not the polling succeeded. */
static inline void lock(void)
{
    unsigned short t = 0xffff;

    do {
        if (R(SHARED_LOCK) != LOCK_BUSY)
            R(SHARED_LOCK) = LOCK_HELD_HERE;
        if (R(SHARED_LOCK) == LOCK_HELD_HERE)
            break;
    } while (t--);
    R(SHARED_LOCK) = LOCK_HELD_HERE;
}

static inline void unlock(void)
{
    R(SHARED_LOCK) = LOCK_FREE;
}

/*
 * Write n blocks of 8 words from buf into OSD memory, starting at block number addr.
 *
 *   buf   the words, 8 per block, in the order they are written
 *   addr  number of the first block
 *   n     number of blocks
 *
 * The only caller is osd_unzip_data. The way of writing depends on osd_unzip_mode (set by
 * osd_request_unzip):
 *   mode 1  the memory is written directly: bit 0 of 0xcf013428 is set under the shared lock, every word is
 *           stored byte-swapped at 0x20000000 + addr * 32 (word index as in buf), then bit 0 is cleared again
 *           under the lock.
 *   others  the memory is written through the register port: for each block the 4 bytes of addr (low byte
 *           first) go to 0xcf011fa0, fa4, fa8 and fac, 0x80 goes to 0xcf011f84, then each of the 8 words goes
 *           to 0xcf011f88 as 4 bytes, high byte first. addr counts up by one per block.
 * The same port loop appears in the main processor's FUN_a01138fc.
 */
void osd_write_memory_blocks(unsigned int *buf, unsigned int addr, unsigned int n)
{
    unsigned int k = 0;                 /* index of the first word of the current block */
    unsigned int i, j, b;
    volatile unsigned int *dst;

    if (osd_unzip_mode == 1) {
        /* Direct write. */
        lock();
        R(OSD_MEM_MODE_REG) |= 1;
        unlock();
        dst = (volatile unsigned int *)((addr << 5) + OSD_MEMORY_BASE);
        for (b = 0; b < n; b++) {
            for (i = k; i < k + 8; i++) {
                dst[i] = (buf[i] >> 24) | (((buf[i] >> 16) & 0xff) << 8) | (((buf[i] >> 8) & 0xff) << 16) | (buf[i] << 24);
            }
            k += 8;
        }
        lock();
        R(OSD_MEM_MODE_REG) &= ~1;
        unlock();
    } else {
        /* Register port write. */
        for (i = 0; i < n; i++) {
            R(0xcf011fa0) = addr;
            R(0xcf011fa4) = addr >> 8;
            R(0xcf011fa8) = addr >> 16;
            R(0xcf011fac) = addr >> 24;
            R(0xcf011f84) = 0x80;
            for (j = k; j < k + 8; j++) {
                R(0xcf011f88) = (buf[j] >> 24) & 0xff;
                R(0xcf011f88) = (buf[j] >> 16) & 0xff;
                R(0xcf011f88) = (buf[j] >> 8) & 0xff;
                R(0xcf011f88) = buf[j] & 0xff;
            }
            k += 8;
            addr++;
        }
    }
}
