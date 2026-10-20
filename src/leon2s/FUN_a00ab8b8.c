/* leon2s FUN_a00ab8b8 @ 0xa00ab8b8-0xa00ab93c (33 words), flags -mcpu=v8 -Os -g.
 * Code facts: leaf; resets the 300-byte port record ARR_a807dc18[port] (u8 port): bytes +0x110 = 3,
 * +0x111 = 2, +0x115 = 1, +0x116 = 1, +0x117 = 2, +0x118 = 0x1b, u16 +0x120 = 600, and clears +0x112..0x114,
 * +0x119..0x11f, +0x123..0x125, +0x128, +0x129. void.
 * Fixes vs the autoc draft (78.79): real base ARR_a807dc18 (the draft used a raw 0xa807dc18 + idx and a list
 * of mid-record names) and the SOURCE store order: ascending offsets, except that +0x117 comes after the
 * u16 +0x120 store and +0x128 is the last store (-Os sched2 emits the non-zero stores and the last source
 * store early; found by a one-line position search, 5 adjacent positions of +0x117 are exact). Aids: none.
 */
extern unsigned char ARR_a807dc18[];

void FUN_a00ab8b8(unsigned char port)
{
    unsigned char *r = ARR_a807dc18 + port * 300;

    r[0x110] = 3;
    r[0x111] = 2;
    r[0x112] = 0;
    r[0x113] = 0;
    r[0x114] = 0;
    r[0x115] = 1;
    r[0x116] = 1;
    r[0x118] = 0x1b;
    r[0x119] = 0;
    r[0x11a] = 0;
    r[0x11b] = 0;
    r[0x11c] = 0;
    r[0x11d] = 0;
    r[0x11e] = 0;
    r[0x11f] = 0;
    *(unsigned short *)(r + 0x120) = 600;
    r[0x117] = 2;
    r[0x123] = 0;
    r[0x124] = 0;
    r[0x125] = 0;
    r[0x129] = 0;
    r[0x128] = 0;
}
