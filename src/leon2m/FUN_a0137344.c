/* leon2m FUN_a0137344 @ 0xa0137344-0xa0137644 (192 words), flags -mcpu=v8 -O3 -g -msoft-float.
 * buf = eight zeroed words. Calls func_0x4008c4d0(1, 0xa0, buf, 1) until buf[0] != 0, with func_0x4008d1a0(1)
 * between the reads; for wait == 0 also FUN_a00df170("wait reply cmd\r\n") when FUN_a00dd614(0x20) is not 0, and
 * at most 100 reads (low byte of the counter). Then func_0x4008c4d0(1, 0xa0, buf, 8) and w = buf[0]; returns unless
 * the low byte of w is 0x55 and the XOR of all bytes of buf[0..7] is 0 (check()). For bits 8..15 of w in
 * {0, 0x22, 0x31, 0x45, 0x5c, 0x5d, 0x71, 0x79, 0x7c, 0x83, 0x87, 0xa0, 0xa1, 0xa4, 0xf3, 0xfd} buf[0..7] is
 * copied to DAT_a802cb9c (two copy loops in the fw: one for 0, one for the other values). Ends with
 * func_0x4008c5f8(1, 0xa0, &zero, 1), zero = 0.
 * Callers: FUN_a013782c, FUN_a0137bb0, FUN_a0137fcc, FUN_a013808c, FUN_a01380c4, FUN_a01381f0, FUN_a01384ac,
 * FUN_a01384e4, FUN_a013851c, FUN_a0139040, FUN_a0139114, FUN_a01391a8, FUN_a013923c, FUN_a01393bc.
 * Source form: one loop for both wait values (the counter is decremented on every pass, the FUN_a00dd614
 * print and the counter test only for wait == 0; GCC's loop unswitching on wait gives the two fw loops); the
 * check is a static helper returning unsigned char, inlined.
 */
extern unsigned int DAT_a802cb9c[8];
extern unsigned char FUN_a00dd614(unsigned int level);
extern int FUN_a00df170(const char *fmt, ...);
extern void func_0x4008c4d0(unsigned char a, unsigned char b, unsigned int *buf, unsigned char n);
extern void func_0x4008c5f8(unsigned char a, unsigned char b, unsigned int *buf, unsigned char n);
extern void func_0x4008d1a0(int n);

static unsigned char check(unsigned int w, unsigned int *p, unsigned char k)
{
    unsigned int x = 0;
    unsigned char i;

    if ((w & 0xff) != 0x55)
        return 0;
    for (i = 0; i < k; i++)
        x = x ^ p[i] ^ (p[i] >> 8) ^ (p[i] >> 16) ^ (p[i] >> 24);
    return (unsigned char)x == 0;
}

void FUN_a0137344(unsigned char wait)
{
    unsigned int buf[8] = {0};
    unsigned int n = 100;
    unsigned int *p = buf;
    unsigned int zero;
    unsigned char i;
    unsigned int w;

    for (;;) {
        func_0x4008c4d0(1, 0xa0, p, 1);
        if (buf[0] != 0)
            break;
        n--;
        func_0x4008d1a0(1);
        if (wait == 0) {
            if (FUN_a00dd614(0x20))
                FUN_a00df170("wait reply cmd\r\n");
            if ((unsigned char)n == 0)
                break;
        }
    }
    func_0x4008c4d0(1, 0xa0, p, 8);
    w = buf[0];
    if (!check(w, p, 8))
        return;
    switch ((int)((w & 0xff00) >> 8)) {
    case 0:
        for (i = 0; i < 8; i++)
            DAT_a802cb9c[i] = p[i];
        break;
    case 0x22: case 0x31: case 0x45: case 0x5c: case 0x5d: case 0x71: case 0x79: case 0x7c:
    case 0x83: case 0x87: case 0xa0: case 0xa1: case 0xa4: case 0xf3: case 0xfd:
        for (i = 0; i < 8; i++)
            DAT_a802cb9c[i] = p[i];
        break;
    }
    zero = 0;
    func_0x4008c5f8(1, 0xa0, &zero, 1);
}
