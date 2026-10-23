/* leon2s FUN_a00c2f58 @ 0xa00c2f58-0xa00c30e4, -mcpu=v8 -Os -g.
 * (u8 port), returns 0 or 1. Counterpart of FUN_a00c2de4 for the 16-byte records DAT_a807d5e8 and the
 * counters DAT_a8078c88, with func_0xa0fb6aa0(port, 0xbb, 1, 1) first, func_0xa0fb69b4 as register reader, and
 * func_0xa0f83044(0x9f1b7580, port, b) (ROM print, ROM address) before the counter reset.
 * Source form as FUN_a00c2de4 (second record pointer before the bit test).
 */
struct rec16 { unsigned int w0; unsigned int w4; unsigned int t; unsigned int wc; };
extern struct rec16 DAT_a807d5e8[];
extern unsigned char DAT_a8078c88[];
extern unsigned int func_0xa0fc2064(void);
extern void func_0xa0fb6aa0(unsigned char, unsigned short, unsigned char, unsigned char);
extern int func_0xa0f83044(const char *, ...);
extern unsigned int func_0xa0fb69b4(unsigned char, unsigned short);

unsigned char FUN_a00c2f58(unsigned char port)
{
    struct rec16 *rec = &DAT_a807d5e8[port];
    struct rec16 *cur;
    unsigned char r = 0;
    unsigned short a, b;

    if (func_0xa0fc2064() - rec->t > 100) {
        func_0xa0fb6aa0(port, 0xbb, 1, 1);
        a = ((func_0xa0fb69b4(port, 0xca) & 0xff) << 8) + (func_0xa0fb69b4(port, 0xc9) & 0xff);
        b = ((func_0xa0fb69b4(port, 0xce) & 0xff) << 8) + (func_0xa0fb69b4(port, 0xcd) & 0xff);
        cur = &DAT_a807d5e8[port];
        if (a < 0x10 && b > 5 && (cur->w0 & 0x1f0000) == 0) {
            if (DAT_a8078c88[port] > 4) {
                func_0xa0f83044((const char *)0x9f1b7580, port, b);
                DAT_a8078c88[port] = 0;
                r = 1;
            }
            DAT_a8078c88[port]++;
            if (b > 0x400 || (b > 0x300 && a < 8))
                DAT_a8078c88[port]++;
        } else {
            DAT_a8078c88[port] = 0;
        }
        rec->w0 &= ~0x1f0000;
        rec->t = func_0xa0fc2064();
    }
    return r & 1;
}
