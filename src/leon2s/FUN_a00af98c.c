/* FUN_a00af98c (leon2s 0xa00af98c-0xa00afbbc, 560 bytes), flags -mcpu=v8 -Os -g.
 * Port setup sequence (u8 port) through FUN_a00a6c00 (write reg), FUN_a00a6c98 (port, reg, mask, set/clear)
 * and FUN_a00a6bb8 (read reg): reg 0x46 = 0x13, clear 0xd3 bit 2, reg 0x4d bit 7 = (b115 == 0), clear reg 3
 * bit 5, reg 0xbc = 0xd0, set 0x39 bit 3, 0x43 bit 4, 0x404 bit 0. Port != 0: FUN_a00af8bc(port, 0x90dfe,
 * 0xc5427), FUN_a00af94c(port). Port 0: for the ROM routine argument 3, 2, 1, 0 in turn
 * func_0x9f1c65a0(0, n), FUN_a00af8bc(0, 0x90dfe, 0xc5427), FUN_a00af94c(0); then, when byte +0x112 of
 * record 0 is set, sets bits 0, 1 and 2 of register 0xcf0046b0 one at a time. Then
 * func_0x9f1b6760(port, b126, b116 != 0 && b112 == 0) and reg 0x2d &= 0xfc.
 * Data: DAT_a807dc18 is an array of 300-byte port records (bytes +0x112, +0x115, +0x116, +0x126 used).
 * Source forms: the 'else' arms come second (b115 != 0 first, port != 0 first); the last record accesses go
 * through one record pointer.
 */
#define R46B0 (*(volatile unsigned int *)0xcf0046b0)

struct prec {
    unsigned char _000[0x112];
    unsigned char b112;
    unsigned char _113[2];
    unsigned char b115;
    unsigned char b116;
    unsigned char _117[0x126 - 0x117];
    unsigned char b126;
    unsigned char _127[0x12c - 0x127];
};
extern struct prec DAT_a807dc18[];
extern void FUN_a00a6c98(unsigned char, unsigned short, unsigned int, unsigned int);
extern void FUN_a00a6c00(unsigned char, unsigned short, unsigned int);
extern unsigned int FUN_a00a6bb8(unsigned char, unsigned short);
extern void FUN_a00af8bc(unsigned char, unsigned int, unsigned int);
extern void FUN_a00af94c(unsigned char);
extern void func_0x9f1c65a0(unsigned char, unsigned char);
extern void func_0x9f1b6760(unsigned char, unsigned char, unsigned char);

void FUN_a00af98c(unsigned char port)
{
    struct prec *r;

    FUN_a00a6c00(port, 0x46, 0x13);
    FUN_a00a6c98(port, 0xd3, 4, 0);
    if (DAT_a807dc18[port].b115 != 0)
        FUN_a00a6c98(port, 0x4d, 0x80, 0);
    else
        FUN_a00a6c98(port, 0x4d, 0x80, 1);
    FUN_a00a6c98(port, 3, 0x20, 0);
    FUN_a00a6c00(port, 0xbc, 0xd0);
    FUN_a00a6c98(port, 0x39, 8, 1);
    FUN_a00a6c98(port, 0x43, 0x10, 1);
    FUN_a00a6c98(port, 0x404, 1, 1);
    if (port != 0) {
        FUN_a00af8bc(port, 0x90dfe, 0xc5427);
        FUN_a00af94c(port);
    } else {
        func_0x9f1c65a0(0, 3);
        FUN_a00af8bc(0, 0x90dfe, 0xc5427);
        FUN_a00af94c(0);
        func_0x9f1c65a0(0, 2);
        FUN_a00af8bc(0, 0x90dfe, 0xc5427);
        FUN_a00af94c(0);
        func_0x9f1c65a0(0, 1);
        FUN_a00af8bc(0, 0x90dfe, 0xc5427);
        FUN_a00af94c(0);
        func_0x9f1c65a0(0, 0);
        FUN_a00af8bc(0, 0x90dfe, 0xc5427);
        FUN_a00af94c(0);
        if (DAT_a807dc18[0].b112 != 0) {
            R46B0 |= 1;
            R46B0 |= 2;
            R46B0 |= 4;
        }
    }
    r = &DAT_a807dc18[port];
    func_0x9f1b6760(port, r->b126, r->b116 != 0 && r->b112 == 0);
    FUN_a00a6c00(port, 0x2d, FUN_a00a6bb8(port, 0x2d) & 0xfc);
}
