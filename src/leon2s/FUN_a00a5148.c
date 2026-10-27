/* FUN_a00a5148 (leon2s 0xa00a5148-0xa00a535c, 532 bytes), flags -mcpu=v8 -Os -g. Called by FUN_a00a535c.
 * void (int mode, unsigned int clk).
 * mode 0: clk is halved once, twice or three times when it is above 479999 / 959999 / 1919999 (sh = 1 / 2 / 3,
 * else 0); v = clk * 10 + (clk * 0xad0 / 3) / 1000 is written as three bytes (low first) to registers
 * 0xcf0140c4 / c8 / cc. Then, each time between lock() and unlock() on register 0xcf03c840 (lock: up to
 * 0x10000 tries writing 2 when it does not read 1, until it reads 2, then writes 2; unlock writes 0), bits 4..5
 * of register 0xcf014744 are cleared, then sh << 4 is ORed in.
 * mode 1: v = (clk << 17) / 12 is written as three bytes to registers 0xcf014104 / 108 / 10c.
 * Source form: the division by 1000 is written as t /= 125 before 'clk *= 10' and t / 8 in the sum (the same
 * value for unsigned t); it fixes the order of the reciprocal multiply and the clk * 10 steps.
 */
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

void FUN_a00a5148(int mode, unsigned int clk)
{
    unsigned char sh;
    unsigned int v, t;

    switch (mode) {
    case 0:
        sh = 0;
        if (clk > 479999) {
            if (clk <= 959999) {
                clk >>= 1;
                sh = 1;
            } else if (clk <= 1919999) {
                clk >>= 2;
                sh = 2;
            } else {
                clk >>= 3;
                sh = 3;
            }
        }
        t = clk * 0xad0 / 3;
        t /= 125;
        clk *= 10;
        v = clk + t / 8;
        R(0xcf0140c4) = v & 0xff;
        R(0xcf0140c8) = (v >> 8) & 0xff;
        R(0xcf0140cc) = (v >> 16) & 0xff;
        lock();
        R(0xcf014744) &= ~0x30;
        unlock();
        lock();
        R(0xcf014744) |= sh << 4;
        unlock();
        break;
    case 1:
        v = (clk << 17) / 12;
        R(0xcf014104) = v & 0xff;
        R(0xcf014108) = (v >> 8) & 0xff;
        R(0xcf01410c) = (v >> 16) & 0xff;
        break;
    }
}
