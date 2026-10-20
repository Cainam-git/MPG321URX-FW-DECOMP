/* leon2m FUN_a00a7d70 @ 0xa00a7d70-0xa00a7e00 (36 words), flags -mcpu=v8 -O3 -g. No direct callers (reached
 * through a table).
 * Calls func_0x4008e2a4(), then FUN_a00b32e4(1, 0, c, 7, q, n, 0) for q = 6..0x15 except 5 and 7: q = 6 with
 * c = 0x7c2 and n = 10, the others with c = 0x792 and n = 0xb. Same loop as the start of FUN_a00ad460; the row-5
 * and row-7 tests are two nested ifs.
 */
extern void func_0x4008e2a4(void);
extern void FUN_a00b32e4(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);

void FUN_a00a7d70(void)
{
    unsigned char i;

    func_0x4008e2a4();
    for (i = 6; i <= 0x15; i++) {
        if (i != 5)
            if (i != 7) {
                if (i == 6)
                    FUN_a00b32e4(1, 0, 0x7c2, 7, 6, 10, 0);
                else
                    FUN_a00b32e4(1, 0, 0x792, 7, i, 0xb, 0);
            }
    }
}
