/* leon2s FUN_a00cad8c @ 0xa00cad8c-0xa00caee4, -mcpu=v8 -Os -g.
 * (u8 port), void. Record DAT_a8078bb0[port] (24 bytes, 2-bit field st = bits 16..17, byte +9 = b9; layout
 * of FUN_a00cb1d4). st = 1. st = 0 and return when (u8)FUN_a00c9798(port, &DAT_a807d250) != 0 or bits 2..3 of
 * DAT_a807d250 byte +1 are set; st = 3 and return when the 10-bit count ((hi & 3) << 8) + lo is not 0.
 * Otherwise FUN_a00c77dc(b9), FUN_a00c9cc8(b9), then FUN_a00c2488(b9, DAT_a807ce50 + 1) is retried up to 30
 * times with func_0xa0fc1794(10) (ROM call) between tries; when all fail st = 0. Then DAT_a807ce50[0] = 4,
 * an empty u8 count loop to 0x80, and the tail call FUN_a00c80f0(port, DAT_a807ce50, 0x74, 0x60, 0x81).
 */
struct Rec24 {
    unsigned int top : 4;
    unsigned int cnt : 4;
    unsigned int mid : 6;
    unsigned int st : 2;
    unsigned int low : 16;
    unsigned char b4[5];
    unsigned char b9;
    unsigned char rest[14];
};
struct D250 { unsigned char lo; unsigned char hi; };
extern struct Rec24 DAT_a8078bb0[];
extern struct D250 DAT_a807d250;
extern unsigned char DAT_a807ce50[];
extern unsigned int FUN_a00c9798(unsigned char, struct D250 *);
extern void FUN_a00c77dc(unsigned char);
extern void FUN_a00c9cc8(unsigned char);
extern unsigned char FUN_a00c2488(unsigned char, unsigned char *);
extern void func_0xa0fc1794(unsigned int);
extern int FUN_a00c80f0(unsigned char, unsigned char *, unsigned char, unsigned char, unsigned short);

void FUN_a00cad8c(unsigned char port)
{
    unsigned char t, i;
    unsigned short n;

    DAT_a8078bb0[port].st = 1;
    if ((unsigned char)FUN_a00c9798(port, &DAT_a807d250) != 0) {
        DAT_a8078bb0[port].st = 0;
        return;
    }
    n = ((DAT_a807d250.hi & 3) << 8) + DAT_a807d250.lo;
    if ((DAT_a807d250.hi & 0xc) != 0) {
        DAT_a8078bb0[port].st = 0;
        return;
    }
    if (n != 0) {
        DAT_a8078bb0[port].st = 3;
        return;
    }
    FUN_a00c77dc(DAT_a8078bb0[port].b9);
    FUN_a00c9cc8(DAT_a8078bb0[port].b9);
    t = 0x1e;
    while (FUN_a00c2488(DAT_a8078bb0[port].b9, &DAT_a807ce50[1]) == 0) {
        t--;
        func_0xa0fc1794(10);
        if (t == 0) {
            DAT_a8078bb0[port].st = 0;
            break;
        }
    }
    DAT_a807ce50[0] = 4;
    for (i = 0; i <= 0x80; i++)
        ;
    FUN_a00c80f0(port, DAT_a807ce50, 0x74, 0x60, 0x81);
}
