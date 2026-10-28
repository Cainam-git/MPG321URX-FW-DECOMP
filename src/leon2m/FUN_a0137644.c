/* leon2m FUN_a0137644 @ 0xa0137644-0xa01376ec (42 words), -mcpu=v8 -O3 -g. No direct callers found.
 * Clears the local word buffer buf[8] and calls func_0x4008c4d0(1, 0x80, buf, 1). With wait == 0 it repeats the
 * call until buf[0] is 0 and returns 1. Otherwise it makes at most 100 attempts: after each call it returns 1 when
 * buf[0] is 0, else it calls func_0x4008d1a0(1) before the next attempt; after the last attempt it returns 0.
 * Source form: the call argument is a pointer p = buf, the tests read buf[0] directly, and the attempt counter n is
 * an unsigned int tested as (unsigned char)n.
 * Compiler aids: 'for (;;) break;' after the declarations emits no instructions; it ends the scheduling region,
 * so r = 0 is set before the wait test and r is kept in %l2. __builtin_expect on the loop condition emits no
 * instructions; with it GCC keeps the byte test of n (btst 0xff) and the firmware's block order of the loop.
 */
extern void func_0x4008c4d0(unsigned char a, unsigned char b, unsigned int *buf, unsigned char n);
extern void func_0x4008d1a0(int n);

unsigned char FUN_a0137644(unsigned char wait)
{
    unsigned int buf[8] = {0};
    unsigned int n = 100;
    unsigned char r = 0;
    unsigned int *p = buf;

    for (;;)
        break;
    if (wait == 0) {
        do
            func_0x4008c4d0(1, 0x80, p, 1);
        while (buf[0] != 0);
        r = 1;
    } else {
        do {
            func_0x4008c4d0(1, 0x80, p, 1);
            if (buf[0] == 0) {
                r = 1;
                break;
            }
            n--;
            func_0x4008d1a0(1);
        } while (__builtin_expect((unsigned char)n != 0, 1));
    }
    return r & 1;
}
