/* leon2s FUN_a008dbd4 @ 0xa008dbd4-0xa008df40 (219 words), flags -mcpu=v8 -Os -g.
 * void (u8 port, u8 on, u8 mode). A fixed sequence of register-field writes on bank 1 of the port through
 * FUN_a00a80cc(port, 1, reg, mask, value), FUN_a00a8054(port, 1, reg, value) (read-modify-write of the byte
 * read by FUN_a00a7fd8(port, 1, reg)) and FUN_a00b1794(1) waits. on != 0: 0xc6/8 = 1, wait, 0xc7/2 = 0,
 * 0xc9 = (b & ~0xe | 6) & ~8, 0xc6/1 = 1, 0xc6/2 and 0xc6/4 = 1, 0 for mode 1 (0, 1 otherwise), wait,
 * 0xc6 = (b & 0x1f) | 0x80, wait, 0xc6/0x10, 0xc5/4, 0xc5/8 = 1, 0x9c = (b & ~7 | 3) & ~4, 0x9c/0x20 = 1,
 * 0x39/0x20 = 1, 0xc3 = 0x1c, 0xc2 = 0x3a, 0xc0/1 = 1, 0xb7 = (b & ~7 | 3) & ~4, 0xb0/0x20 = 1 and (tail call)
 * 0xb0/0x10 = 1. on == 0: 0x9c/0x20, 0xc6/0x10, 0xc5/4, 0xc5/8 = 0, wait, 0xc7/2 = 1, 0xc6/1, 0xc6/2, 0xc6/4 = 0,
 * wait, 0xc6/8 = 0 and (tail call) 0x39/0x20 = 0.
 * Source form: the read-modify-writes as separate statements on an unsigned char local (one expression lets
 * fold drop the first mask).
 */
extern void FUN_a00a80cc(unsigned char, unsigned char, unsigned short, unsigned int, unsigned char);
extern void FUN_a00a8054(unsigned char, unsigned char, unsigned short, unsigned char);
extern unsigned int FUN_a00a7fd8(unsigned char, unsigned char, unsigned short);
extern void FUN_a00b1794(int);

void FUN_a008dbd4(unsigned char port, unsigned char on, unsigned char mode)
{
    unsigned char v;

    if (on) {
        FUN_a00a80cc(port, 1, 0xc6, 8, 1);
        FUN_a00b1794(1);
        FUN_a00a80cc(port, 1, 0xc7, 2, 0);
        v = FUN_a00a7fd8(port, 1, 0xc9);
        v &= ~0xe;
        v |= 6;
        v &= ~8;
        FUN_a00a8054(port, 1, 0xc9, v);
        FUN_a00a80cc(port, 1, 0xc6, 1, 1);
        if (mode == 1) {
            FUN_a00a80cc(port, 1, 0xc6, 2, 1);
            FUN_a00a80cc(port, 1, 0xc6, 4, 0);
        } else {
            FUN_a00a80cc(port, 1, 0xc6, 2, 0);
            FUN_a00a80cc(port, 1, 0xc6, 4, 1);
        }
        FUN_a00b1794(1);
        FUN_a00a8054(port, 1, 0xc6, (FUN_a00a7fd8(port, 1, 0xc6) & 0x1f) | 0x80);
        FUN_a00b1794(1);
        FUN_a00a80cc(port, 1, 0xc6, 0x10, 1);
        FUN_a00a80cc(port, 1, 0xc5, 4, 1);
        FUN_a00a80cc(port, 1, 0xc5, 8, 1);
        v = FUN_a00a7fd8(port, 1, 0x9c);
        v &= ~7;
        v |= 3;
        v &= ~4;
        FUN_a00a8054(port, 1, 0x9c, v);
        FUN_a00a80cc(port, 1, 0x9c, 0x20, 1);
        FUN_a00a80cc(port, 1, 0x39, 0x20, 1);
        FUN_a00a8054(port, 1, 0xc3, 0x1c);
        FUN_a00a8054(port, 1, 0xc2, 0x3a);
        FUN_a00a80cc(port, 1, 0xc0, 1, 1);
        v = FUN_a00a7fd8(port, 1, 0xb7);
        v &= ~7;
        v |= 3;
        v &= ~4;
        FUN_a00a8054(port, 1, 0xb7, v);
        FUN_a00a80cc(port, 1, 0xb0, 0x20, 1);
        FUN_a00a80cc(port, 1, 0xb0, 0x10, 1);
    } else {
        FUN_a00a80cc(port, 1, 0x9c, 0x20, 0);
        FUN_a00a80cc(port, 1, 0xc6, 0x10, 0);
        FUN_a00a80cc(port, 1, 0xc5, 4, 0);
        FUN_a00a80cc(port, 1, 0xc5, 8, 0);
        FUN_a00b1794(1);
        FUN_a00a80cc(port, 1, 0xc7, 2, 1);
        FUN_a00a80cc(port, 1, 0xc6, 1, 0);
        FUN_a00a80cc(port, 1, 0xc6, 2, 0);
        FUN_a00a80cc(port, 1, 0xc6, 4, 0);
        FUN_a00b1794(1);
        FUN_a00a80cc(port, 1, 0xc6, 8, 0);
        FUN_a00a80cc(port, 1, 0x39, 0x20, 0);
    }
}
