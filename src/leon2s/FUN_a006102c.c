/* FUN_a006102c (leon2s 0xa006102c-0xa0061138, 268 bytes), flags -mcpu=v8 -Os -g.
 * Clears bit 12 of hardware register 0x9f100090 and sets bit 12 of 0x9f120028. pend = 0x9f12009c & ~0x9f120064
 * (0x9f12009c read first), edge = 0x9f120064 >> 16. For bits i = 0, 1 set in pend with a non-zero function
 * pointer DAT_a8079378[i]: when bit i of edge is set, calls the function and then writes 1 << i to 0x9f12009c;
 * otherwise writes 1 << i first and then calls the function. Ends by writing 0x1000 to 0x9f120034 and
 * 0x9f10009c, clearing bit 12 of 0x9f120028 and setting bit 12 of 0x9f100090. volatile only on the hardware
 * registers.
 * Compiler aid: __builtin_expect(fn != 0, 0) on the pointer test emits no instructions; it changes the branch
 * prediction so that the loop increment is placed in the annulled delay slot of that test.
 */
#define R(a) (*(volatile unsigned int *)(a))
extern void (*DAT_a8079378[])(void);

void FUN_a006102c(void)
{
    unsigned int pend;
    unsigned int edge;
    unsigned int i;
    unsigned int bit;
    void (*fn)(void);

    R(0x9f100090) &= ~0x1000;
    R(0x9f120028) |= 0x1000;
    pend = R(0x9f12009c);
    pend &= ~R(0x9f120064);
    edge = R(0x9f120064) >> 16;
    for (i = 0; i < 2; i++) {
        bit = 1 << i;
        if (pend & bit) {
            fn = DAT_a8079378[i];
            if (__builtin_expect(fn != 0, 0)) {
                if (edge & bit) {
                    fn();
                    R(0x9f12009c) = bit;
                } else {
                    R(0x9f12009c) = bit;
                    fn();
                }
            }
        }
    }
    R(0x9f120034) = 0x1000;
    R(0x9f10009c) = 0x1000;
    R(0x9f120028) &= ~0x1000;
    R(0x9f100090) |= 0x1000;
}
