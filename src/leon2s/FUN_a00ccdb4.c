/* leon2s FUN_a00ccdb4 @ 0xa00ccdb4-0xa00ccf0c, -mcpu=v8 -Os -g.
 * (u8 port), void. Record DAT_a8078bb0[port] (24 bytes; st = bits 16..17, b18 = bit 18 of word 0).
 * st = 1; FUN_a00ccad4(port); FUN_a00c87c0(port, 0); FUN_a00c81f8(port, a, 8) (a = 8-byte stack buffer);
 * func_0xa0fb80cc(port, 0, 0x12f, 1, b18) (ROM call, last argument 0 or 1). Each failing step sets st = 3 and
 * returns: (u8)FUN_a00c7bf8(port), FUN_a00c82dc(port, c) (c = 8-byte buffer), then after
 * FUN_a00c7ccc(port, 1) (u8)FUN_a00c8360(port, &b), then after FUN_a00c8444(port) and FUN_a00c85e4(port, a, 0)
 * (u8)FUN_a00c850c(port). On success FUN_a00c8688(port, a) and FUN_a00c86bc(port).
 * Source form: one if per failing step (an || of the first two swaps two registers).
 */
struct Rec24 {
    unsigned int top : 13;
    unsigned int b18 : 1;
    unsigned int st : 2;
    unsigned int low : 16;
    unsigned char rest[20];
};
extern struct Rec24 DAT_a8078bb0[];
extern void FUN_a00ccad4(unsigned char);
extern unsigned int FUN_a00c87c0(unsigned char, unsigned int);
extern int FUN_a00c81f8(unsigned int, unsigned char *, unsigned short);
extern void func_0xa0fb80cc(unsigned char, int, int, int, int);
extern unsigned int FUN_a00c7bf8(unsigned char);
extern unsigned char FUN_a00c82dc(unsigned char, unsigned char *);
extern void FUN_a00c7ccc(unsigned char, unsigned char);
extern int FUN_a00c8360(unsigned int, unsigned char *);
extern void FUN_a00c8444(unsigned char);
extern void FUN_a00c85e4(unsigned int, unsigned char *, unsigned char);
extern unsigned int FUN_a00c850c(unsigned char);
extern void FUN_a00c8688(unsigned int, unsigned char *);
extern void FUN_a00c86bc(unsigned char);

void FUN_a00ccdb4(unsigned char port)
{
    unsigned char c[8];
    unsigned char a[8];
    unsigned char b;

    DAT_a8078bb0[port].st = 1;
    FUN_a00ccad4(port);
    FUN_a00c87c0(port, 0);
    FUN_a00c81f8(port, a, 8);
    if (DAT_a8078bb0[port].b18 == 0)
        func_0xa0fb80cc(port, 0, 0x12f, 1, 0);
    else
        func_0xa0fb80cc(port, 0, 0x12f, 1, 1);
    if ((unsigned char)FUN_a00c7bf8(port) != 0) {
        DAT_a8078bb0[port].st = 3;
        return;
    }
    if (FUN_a00c82dc(port, c) != 0) {
        DAT_a8078bb0[port].st = 3;
        return;
    }
    FUN_a00c7ccc(port, 1);
    if ((unsigned char)FUN_a00c8360(port, &b) != 0) {
        DAT_a8078bb0[port].st = 3;
        return;
    }
    FUN_a00c8444(port);
    FUN_a00c85e4(port, a, 0);
    if ((unsigned char)FUN_a00c850c(port) != 0) {
        DAT_a8078bb0[port].st = 3;
        return;
    }
    FUN_a00c8688(port, a);
    FUN_a00c86bc(port);
}
