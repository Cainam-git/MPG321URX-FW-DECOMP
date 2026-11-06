/* FUN_a006c788 (leon2s 0xa006c788-0xa006c9c0, 568 bytes), flags -mcpu=v8 -Os -g -msoft-float.
 * Writes n blocks of 8 words from buf. DAT_a80787e0 == 1: sets bit 0 of 0xcf013428 under the 0xcf03c840 lock
 * (lock: up to 0xffff polls writing 2 while the register is not 1, until it reads 2; then 2; unlock: 0), copies
 * buf[k .. k + 7] byte-swapped to the words at 0x20000000 + addr * 32 (same index k), k += 8 per block, then
 * clears bit 0 of 0xcf013428 under the lock. Otherwise per block: the 4 bytes of addr (low byte first) to
 * 0xcf011fa0 / fa4 / fa8 / fac, 0x80 to 0xcf011f84, then the 4 bytes of each word buf[k .. k + 7] (high byte
 * first) to 0xcf011f88; k += 8 and addr++ per block. Port loop as in the main processor's FUN_a01138fc.
 * Source form: three loop variables (b counts the memory blocks, i is the memory word index and the port block
 * counter, j the port word index); every port byte is written as '(w >> s) & 0xff'. Compiled with -msoft-float
 * (it lowers the loop-invariant threshold: the 0xcf011fa0 address and the 0x80 constant are hoisted after the
 * other port addresses, as in the firmware).
 */
extern unsigned char DAT_a80787e0;

#define R(a) (*(volatile unsigned int *)(a))

static inline void lock(void)
{
    unsigned short t = 0xffff;

    do {
        if (R(0xcf03c840) != 1)
            R(0xcf03c840) = 2;
        if (R(0xcf03c840) == 2)
            break;
    } while (t--);
    R(0xcf03c840) = 2;
}

static inline void unlock(void)
{
    R(0xcf03c840) = 0;
}

void FUN_a006c788(unsigned int *buf, unsigned int addr, unsigned int n)
{
    unsigned int k = 0;
    unsigned int i, j, b;
    volatile unsigned int *dst;

    if (DAT_a80787e0 == 1) {
        lock();
        R(0xcf013428) |= 1;
        unlock();
        dst = (volatile unsigned int *)((addr << 5) + 0x20000000);
        for (b = 0; b < n; b++) {
            for (i = k; i < k + 8; i++) {
                dst[i] = (buf[i] >> 24) | (((buf[i] >> 16) & 0xff) << 8) | (((buf[i] >> 8) & 0xff) << 16) | (buf[i] << 24);
            }
            k += 8;
        }
        lock();
        R(0xcf013428) &= ~1;
        unlock();
    } else {
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
