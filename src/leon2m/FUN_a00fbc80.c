/* leon2m FUN_a00fbc80 @ 0xa00fbc80-0xa00fbdcc, flags -mcpu=v8 -O3 -g. Caller: FUN_a00fbdcc.
 * Returns 1. Only when p == 0 it acts on m (an if/else chain, not a switch: the firmware compares m with
 * 0, 1, 2, 3 in a row):
 *   m 0: FUN_a00fbaf8(0, 0), clears bit 31 of 0xd004002c, word 0x00
 *   m 1: FUN_a00fbaf8(0, 3), clears bit 31 of 0xd004002c, word 0x00
 *   m 2: FUN_a00fbaf8(0, 3), sets bit 31 of 0xd004002c,   word 0x03
 *   m 3: FUN_a00fbaf8(0, 3), sets bit 31 of 0xd004002c,   word 0x13
 *   else: FUN_a00fbaf8(0, 3), clears bit 31 of 0xd004002c, word 0x00
 * and then calls FUN_a00fb434(10, &word, 0, 0). Each arm has its own local word, so each gets its own stack
 * slot (fp-12, -16, -20, -24, -28 in source order).
 */
#define R(a) (*(volatile unsigned int *)(a))

extern int FUN_a00fbaf8(unsigned char, unsigned int);
extern int FUN_a00fb434(unsigned int, unsigned int *, unsigned int, unsigned int);

int FUN_a00fbc80(unsigned char p, unsigned char m)
{
    if (p == 0) {
        if (m == 0) {
            unsigned int v;

            FUN_a00fbaf8(0, 0);
            R(0xd004002c) &= ~0x80000000;
            v = 0;
            FUN_a00fb434(10, &v, 0, 0);
        } else if (m == 1) {
            unsigned int v;

            FUN_a00fbaf8(0, 3);
            R(0xd004002c) &= ~0x80000000;
            v = 0;
            FUN_a00fb434(10, &v, 0, 0);
        } else if (m == 2) {
            unsigned int v;

            FUN_a00fbaf8(0, 3);
            R(0xd004002c) |= 0x80000000;
            v = 3;
            FUN_a00fb434(10, &v, 0, 0);
        } else if (m == 3) {
            unsigned int v;

            FUN_a00fbaf8(0, 3);
            R(0xd004002c) |= 0x80000000;
            v = 0x13;
            FUN_a00fb434(10, &v, 0, 0);
        } else {
            unsigned int v;

            FUN_a00fbaf8(0, 3);
            R(0xd004002c) &= ~0x80000000;
            v = 0;
            FUN_a00fb434(10, &v, 0, 0);
        }
    }
    return 1;
}
