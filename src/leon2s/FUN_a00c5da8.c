/* FUN_a00c5da8 (leon2s 0xa00c5da8-0xa00c5f18, 368 bytes), flags -mcpu=v8 -Os -g.
 * Writes the 8-bit value v (param_2) through ROM register routines chosen by param_1:
 * param_1 0..1 via func_0xa0fb7dd0 (regs 0x310 = 0xad, 0x311 = 8, 0x312 = v, 0x310 = 0), 2..3 via
 * func_0xa0fb7dd0 (0xa6 = 10, 0xa5 = 0x12, 0xa4 = 2, 0xa7 = v), 4 and above via func_0xa0fb6c00 with index
 * param_1 - 4 (0x408 = 1, 0x404 = 7, wait func_0xa0fc160c(1), 0x404 = 1, 0x400 = 3, 0x403 = 10, 0x402 = 0x40,
 * 0x401 = v + 2, 0x402 = 0x80). Then clears the word DAT_a8078c60[port] and bytes +0xd and +0xc of the
 * 16-byte record DAT_a807d5c8[port].
 * Source forms: port, the record pointer, v and param_1 - 4 are locals set at the top; byte +0xd is cleared
 * before byte +0xc.
 */
struct rec16 {
    unsigned char _0[0xc];
    unsigned char bc;
    unsigned char bd;
    unsigned char _e[2];
};
extern struct rec16 DAT_a807d5c8[];
extern unsigned int DAT_a8078c60[];
extern void func_0xa0fb7dd0(unsigned char, unsigned short, unsigned char);
extern void func_0xa0fb6c00(unsigned char, unsigned short, unsigned char);
extern void func_0xa0fc160c(unsigned int);

void FUN_a00c5da8(unsigned int param_1, unsigned int param_2)
{
    unsigned char port = param_1;
    struct rec16 *r = &DAT_a807d5c8[port];
    unsigned char v = param_2;
    unsigned int q = param_1 - 4;

    if (port < 2) {
        func_0xa0fb7dd0(port, 0x310, 0xad);
        func_0xa0fb7dd0(port, 0x311, 8);
        func_0xa0fb7dd0(port, 0x312, v);
        func_0xa0fb7dd0(port, 0x310, 0);
    } else if (port < 4) {
        func_0xa0fb7dd0(port, 0xa6, 10);
        func_0xa0fb7dd0(port, 0xa5, 0x12);
        func_0xa0fb7dd0(port, 0xa4, 2);
        func_0xa0fb7dd0(port, 0xa7, v);
    } else {
        func_0xa0fb6c00(q, 0x408, 1);
        func_0xa0fb6c00(q, 0x404, 7);
        func_0xa0fc160c(1);
        func_0xa0fb6c00(q, 0x404, 1);
        func_0xa0fb6c00(q, 0x400, 3);
        func_0xa0fb6c00(q, 0x403, 10);
        func_0xa0fb6c00(q, 0x402, 0x40);
        func_0xa0fb6c00(q, 0x401, v + 2);
        func_0xa0fb6c00(q, 0x402, 0x80);
    }
    DAT_a8078c60[port] = 0;
    r->bd = 0;
    r->bc = 0;
}
