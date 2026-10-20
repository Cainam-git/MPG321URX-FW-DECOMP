/* leon2m FUN_a01469e0 @ 0xa01469e0-0xa0146a80 (40 words).
 * For n 0..7 (jump table at 0xe3340) calls func_0x4008e6e4(n, b), which writes n into bits 0..2 of register 0xa5 of
 * register block b; other n skip it. Then tail-calls FUN_a011a848(a, b).
 */
extern void func_0x4008e6e4(unsigned int v, unsigned char blk);
extern void FUN_a011a848(unsigned char, unsigned char);

void FUN_a01469e0(unsigned char n, unsigned char a, unsigned char b)
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
    FUN_a011a848(a, b);
}
