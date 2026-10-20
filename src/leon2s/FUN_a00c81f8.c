/* FUN_a00c81f8 (leon2s 0xa00c81f8-0xa00c82dc, 228 bytes), flags -mcpu=v8 -Os -g.
 * Calls func_0xa0fc1794(2), stores register 0xf4 of port (func_0xa0fb7fd8(port, 0, 0xf4)) in buf[0], then
 * reads n bytes in blocks of up to 16: before each block it polls register 0xf5 until bits 0..4 equal
 * min(n, 16) - 1 (0x10 when n > 16), with one counter of 100 attempts shared by all blocks, then calls
 * FUN_a00c7fec(port, buf + blk * 16, min(n, 16), 0xf4). Returns 0.
 * Source forms: raw unsigned int port (and 0xff before each call); a for loop over blk with the n != 0
 * test; the poll is a while loop with an inner 'if (--tries == 0) break;'.
 */
extern void func_0xa0fc1794(unsigned int);
extern unsigned char func_0xa0fb7fd8(unsigned char, int, unsigned short);
extern void FUN_a00c7fec(unsigned char port, unsigned char *buf, unsigned char n, unsigned short reg);

int FUN_a00c81f8(unsigned int port, unsigned char *buf, unsigned short n)
{
    unsigned char tries = 100;
    unsigned short blk;

    func_0xa0fc1794(2);
    buf[0] = func_0xa0fb7fd8(port, 0, 0xf4);
    for (blk = 0; n != 0; blk++) {
        while ((func_0xa0fb7fd8(port, 0, 0xf5) & 0x1f) != (n > 0x10 ? 0x10 : n - 1)) {
            if (--tries == 0)
                break;
        }
        FUN_a00c7fec(port, buf + blk * 0x10, n > 0x10 ? 0x10 : n, 0xf4);
        n = n > 0x10 ? n - 0x10 : 0;
    }
    return 0;
}
