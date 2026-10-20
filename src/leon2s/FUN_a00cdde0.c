/*
 * FUN_a00cdde0 (leon2s, 0xa00cdde0-0xa00ce420, 1600 bytes), flags -mcpu=v8 -Os -g.
 * Sets the 2-bit field (bits 16..17 of word 0) of the 24-byte record DAT_a8078bb0[port] to 1 and calls
 * FUN_a00c77dc and FUN_a00c9cc8 with the record byte +9. Then calls FUN_a00c2488(byte +9, DAT_a807ce50)
 * until it returns nonzero, at most 30 times, with func_0xa0fc1794(10) after each zero result; after 30
 * zero results the field is set to 0. Finally copies the 128 bytes of DAT_a807ce50 in 16 groups of 8 into
 * a stack buffer and passes each group to func_0xa0f963d4(0, 0x80, addr, 7, buf), addr = 0x69220 + 8 * k.
 * Source forms: a while loop on the FUN_a00c2488 result with the counter decremented first in the body;
 * the address is one variable advanced by 8 after each send (the firmware adds 8 to a register); the
 * table offsets are constants per group.
 */
struct Rec18 { unsigned int hi : 14; unsigned int f16 : 2; unsigned int lo : 16; unsigned char _4[5]; unsigned char b9; unsigned char _a[0xe]; };
extern struct Rec18 DAT_a8078bb0[];
extern unsigned char DAT_a807ce50[];
extern void FUN_a00c77dc(unsigned char);
extern void FUN_a00c9cc8(unsigned char);
extern unsigned char FUN_a00c2488(unsigned char, unsigned char *);
extern void func_0xa0fc1794(unsigned int);
extern int func_0xa0f963d4(unsigned int, unsigned int, unsigned int, unsigned int, unsigned char *);

#define COPY_SEND8(k)                                                   \
    for (i = 0; i < 8; i++)                                        \
        buf[i] = DAT_a807ce50[(k) * 8 + i];                        \
    func_0xa0f963d4(0, 0x80, addr, 7, buf);                        \
    addr += 8

void FUN_a00cdde0(unsigned char port)
{
    unsigned char buf[8];
    unsigned short i;
    unsigned char n;
    unsigned int addr;

    DAT_a8078bb0[port].f16 = 1;
    FUN_a00c77dc(DAT_a8078bb0[port].b9);
    FUN_a00c9cc8(DAT_a8078bb0[port].b9);
    n = 30;
    while (FUN_a00c2488(DAT_a8078bb0[port].b9, DAT_a807ce50) == 0) {
        n--;
        func_0xa0fc1794(10);
        if (n == 0) {
            DAT_a8078bb0[port].f16 = 0;
            break;
        }
    }
    addr = 0x69220;
    COPY_SEND8(0);
    COPY_SEND8(1);
    COPY_SEND8(2);
    COPY_SEND8(3);
    COPY_SEND8(4);
    COPY_SEND8(5);
    COPY_SEND8(6);
    COPY_SEND8(7);
    COPY_SEND8(8);
    COPY_SEND8(9);
    COPY_SEND8(10);
    COPY_SEND8(11);
    COPY_SEND8(12);
    COPY_SEND8(13);
    COPY_SEND8(14);
    COPY_SEND8(15);
}
