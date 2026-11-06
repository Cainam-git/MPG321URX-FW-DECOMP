/* leon2m FUN_a0137644 @ 0xa0137644-0xa01376ec (42 words), -mcpu=v8 -O3 -g. No direct callers found.
 * Clears the local word buffer buf[8] and calls func_0x4008c4d0(1, 0x80, buf, 1). With wait == 0 it repeats the
 * call until buf[0] is 0 and returns 1. Otherwise it makes at most 100 attempts: after each call it returns 1 when
 * buf[0] is 0, else it calls func_0x4008d1a0(1) before the next attempt; after the last attempt it returns 0.
 * Source form: one polling loop with the 'wait != 0' timeout step inside it (u8 counter n = 100, u8 result r = 0
 * set before the loop); GCC -O3 unswitches the loop on wait, which gives the two loop copies at 0xa0137674 and
 * 0xa01376a0 and keeps r in %l2.
 */
extern void func_0x4008c4d0(unsigned char a, unsigned char b, unsigned int *buf, unsigned char n);
extern void func_0x4008d1a0(int n);

unsigned char FUN_a0137644(unsigned char wait)
{
    unsigned int buf[8] = {0};
    unsigned char n = 100;
    unsigned char r = 0;

    for (;;) {
        func_0x4008c4d0(1, 0x80, buf, 1);
        if (buf[0] == 0) {
            r = 1;
            break;
        }
        if (wait != 0) {
            n--;
            func_0x4008d1a0(1);
            if (n == 0)
                break;
        }
    }
    return r;
}
