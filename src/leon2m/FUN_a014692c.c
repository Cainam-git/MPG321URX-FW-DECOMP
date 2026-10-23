/* leon2m FUN_a014692c @ 0xa014692c-0xa01469e0 (180 bytes), flags -mcpu=v8 -O3 -g.
 * For n 0..7 (jump table at 0xe3320) calls func_0x4008e6e4(n, b); other n skip it. Then tail-calls
 * FUN_a011a9e4(p1, p2, p3, p4, p5, b): b (the 7th parameter, read from the stack once at entry) is also the 6th
 * argument of the tail call, which is why the firmware keeps it in %i5 and p5 in %l0.
 */
extern void func_0x4008e6e4(unsigned int v, unsigned char blk);
extern void FUN_a011a9e4(unsigned char sel, unsigned int b, unsigned int c, unsigned char d, unsigned int e, unsigned char blk);

void FUN_a014692c(unsigned char n, unsigned char p1, unsigned char p2, unsigned char p3, unsigned char p4,
                  unsigned char p5, unsigned char b)
{
    switch (n) {
    case 0: func_0x4008e6e4(0, b); break;
    case 1: func_0x4008e6e4(1, b); break;
    case 2: func_0x4008e6e4(2, b); break;
    case 3: func_0x4008e6e4(3, b); break;
    case 4: func_0x4008e6e4(4, b); break;
    case 5: func_0x4008e6e4(5, b); break;
    case 6: func_0x4008e6e4(6, b); break;
    case 7: func_0x4008e6e4(7, b); break;
    }
    FUN_a011a9e4(p1, p2, p3, p4, p5, b);
}
