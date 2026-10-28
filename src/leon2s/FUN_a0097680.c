/* leon2s FUN_a0097680 @ 0xa0097680-0xa00977cc, flags -mcpu=v8 -Os -g.
 * Reads one value from the register block of port 'port' and scales it. Called by FSM_MODE_DETECT_STANDBY.
 * Data: DAT_a807db00[port] (0x34-byte entries) holds the register block pointers r0 (+0) and r20 (+0x20).
 *   hold != 0: n = 50, FUN_a00a73ac(0x18, r20 + 0xe); while FUN_a00a7408(0x19, r20 + 0xe) returns 0:
 *   FUN_a00b1794(1), leave when n is 0, else n--; returns 0 when n is 0 after the loop.
 *   When FUN_a00a7408(0x19, r20 + 0xe) != 0: a = r20[0x10],
 *   r = (((a * 960) << FUN_a00a7408(0xc, r0 + 2)) + 0x8000 >> 16) / (((r0[2] & 0xc0) >> 6) + 1), else r = 0.
 *   hold == 0: FUN_a00a73ac(0x18, r20 + 0xe) at the end. Returns r (unsigned short).
 * Source form: n = 50 set before the first FUN_a00a73ac call; the wait loop leaves with 'break' when n is 0
 *   and the test 'n == 0' after the loop returns 0; every register block access through DAT_a807db00[port].
 */
struct port_rec {
    volatile unsigned int *r0;
    unsigned int _04[7];
    volatile unsigned int *r20;
    unsigned char _24[0x34 - 0x24];
};
extern struct port_rec DAT_a807db00[];
extern void FUN_a00a73ac(unsigned int, volatile unsigned int *);
extern unsigned int FUN_a00a7408(unsigned int, volatile unsigned int *);
extern void FUN_a00b1794(unsigned int);

unsigned short FUN_a0097680(unsigned char port, unsigned char hold)
{
    unsigned short r = 0;
    unsigned char n;
    unsigned int a;

    if (hold) {
        n = 50;
        FUN_a00a73ac(0x18, DAT_a807db00[port].r20 + 0xe);
        while (FUN_a00a7408(0x19, DAT_a807db00[port].r20 + 0xe) == 0) {
            FUN_a00b1794(1);
            if (n == 0)
                break;
            n--;
        }
        if (n == 0)
            return 0;
    }
    if (FUN_a00a7408(0x19, DAT_a807db00[port].r20 + 0xe)) {
        a = DAT_a807db00[port].r20[0x10];
        r = (((a * 960) << FUN_a00a7408(0xc, DAT_a807db00[port].r0 + 2)) + 0x8000 >> 16) /
            (((DAT_a807db00[port].r0[2] & 0xc0) >> 6) + 1);
    }
    if (hold == 0)
        FUN_a00a73ac(0x18, DAT_a807db00[port].r20 + 0xe);
    return r;
}
