/* leon2s FUN_a00c2de4 @ 0xa00c2de4-0xa00c2f58, -mcpu=v8 -Os -g.
 * (u8 port), returns 0 or 1. rec = 16-byte record DAT_a807d5c8[port] (word +8 = time stamp). Nothing (0)
 * unless func_0xa0fc2064() - rec->t > 100 (ROM call). Then func_0xa0fb65c4(port, 0xbb, 1);
 * a = (reg 0xca << 8) + reg 0xc9 and b = (reg 0xce << 8) + reg 0xcd (u16, func_0xa0fb657c). When a < 0x10,
 * b > 5 and bits 16..20 of rec word 0 are 0: the counter DAT_a8078c80[port] is reset to 0 with result 1 when
 * it is above 4, then incremented, and incremented once more when b > 0x400 or (b > 0x300 and a < 8);
 * otherwise the counter is cleared. Finally bits 16..20 of rec word 0 are cleared and rec->t = the time.
 * Source form: a second record pointer cur taken right before the bit test (address operand order).
 */
struct rec16 { unsigned int w0; unsigned int w4; unsigned int t; unsigned int wc; };
extern struct rec16 DAT_a807d5c8[];
extern unsigned char DAT_a8078c80[];
extern unsigned int func_0xa0fc2064(void);
extern void func_0xa0fb65c4(unsigned char, unsigned short, unsigned char);
extern unsigned int func_0xa0fb657c(unsigned char, unsigned short);

unsigned char FUN_a00c2de4(unsigned char port)
{
    struct rec16 *rec = &DAT_a807d5c8[port];
    struct rec16 *cur;
    unsigned char r = 0;
    unsigned short a, b;

    if (func_0xa0fc2064() - rec->t > 100) {
        func_0xa0fb65c4(port, 0xbb, 1);
        a = ((func_0xa0fb657c(port, 0xca) & 0xff) << 8) + (func_0xa0fb657c(port, 0xc9) & 0xff);
        b = ((func_0xa0fb657c(port, 0xce) & 0xff) << 8) + (func_0xa0fb657c(port, 0xcd) & 0xff);
        cur = &DAT_a807d5c8[port];
        if (a < 0x10 && b > 5 && (cur->w0 & 0x1f0000) == 0) {
            if (DAT_a8078c80[port] > 4) {
                DAT_a8078c80[port] = 0;
                r = 1;
            }
            DAT_a8078c80[port]++;
            if (b > 0x400 || (b > 0x300 && a < 8))
                DAT_a8078c80[port]++;
        } else {
            DAT_a8078c80[port] = 0;
        }
        rec->w0 &= ~0x1f0000;
        rec->t = func_0xa0fc2064();
    }
    return r & 1;
}
