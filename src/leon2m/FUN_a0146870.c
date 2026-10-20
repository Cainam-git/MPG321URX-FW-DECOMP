/* leon2m FUN_a0146870 @ 0xa0146870-0xa014692c (47 words).
 * For n 0..7 (jump table at 0xe3300) calls func_0x4008e6e4(n, b), which writes n into bits 0..2 of register 0xa5 of
 * register block b; other n skip it. Then tail-calls func_0x4008e764(x, y, w, h, b) (FUN_a002e764, the window
 * register write).
 */
extern void func_0x4008e6e4(unsigned int v, unsigned char blk);
extern void func_0x4008e764(unsigned short, unsigned short, unsigned short, unsigned short, unsigned char);

void FUN_a0146870(unsigned char n, unsigned short x, unsigned short y, unsigned short w, unsigned short h,
                  unsigned char b)
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
    func_0x4008e764(x, y, w, h, b);
}
