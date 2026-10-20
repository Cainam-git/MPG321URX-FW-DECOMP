/* leon2s FUN_a00c91f8 @ 0xa00c91f8-0xa00c9334 (316 bytes, 79 words)
 * Flags: -mcpu=v8 -Os -g.
 * void (u8 port). It works on the 24-byte DAT_a8078bb0[port] record. Word 0 holds bit-fields (big-endian):
 * f28 = bit 28 (srl 28; btst 1), f23 = bit 23, st = bits 16..17. Byte +3 is a plain u8 member (as a
 * bit-field it is read with ld + and and compared signed). It sets st = 1. When f28 is 0: f23 = 0 (in the
 * same read-modify-write), bytes +3..+6 are cleared (source order 3, 4, 5, 6 gives the firmware stores 6, 3,
 * 4, 5), FUN_a00c87e8(port, 0xb, 0x4005) (3 args), five ROM reads func_0xa0fb7fd8(port, 0, i + 0x10) are
 * written with FUN_a00c7654(port, 1, v), then FUN_a00c87e8(port, 0, 0). Then: b3 >= 0x7f sets b5 = 1, else
 * b3++; b4 >= 7 sets b6 = 1, else b4++. The 'set flag' arm comes first in the source (the firmware falls
 * into it). No volatile.
 */
struct Rec24 {
    unsigned int a:3;
    unsigned int f28:1;
    unsigned int cnt:4;
    unsigned int f23:1;
    unsigned int mid:5;
    unsigned int st:2;
    unsigned int x:8;
    unsigned char b3;
    unsigned char b4;
    unsigned char b5;
    unsigned char b6;
    unsigned char pad[17];
};
extern struct Rec24 DAT_a8078bb0[];
extern void FUN_a00c7654(unsigned char, unsigned char, unsigned char);
extern void FUN_a00c87e8(unsigned char, unsigned char, unsigned short);
extern unsigned int func_0xa0fb7fd8(unsigned char, int, unsigned short);

void FUN_a00c91f8(unsigned char port)
{
    unsigned char i;

    DAT_a8078bb0[port].st = 1;
    if (DAT_a8078bb0[port].f28 == 0) {
        DAT_a8078bb0[port].f23 = 0;
        DAT_a8078bb0[port].b3 = 0;
        DAT_a8078bb0[port].b4 = 0;
        DAT_a8078bb0[port].b5 = 0;
        DAT_a8078bb0[port].b6 = 0;
        FUN_a00c87e8(port, 0xb, 0x4005);
        for (i = 0; i < 5; i++)
            FUN_a00c7654(port, 1, func_0xa0fb7fd8(port, 0, i + 0x10));
        FUN_a00c87e8(port, 0, 0);
    }
    if (DAT_a8078bb0[port].b3 >= 0x7f)
        DAT_a8078bb0[port].b5 = 1;
    else
        DAT_a8078bb0[port].b3++;
    if (DAT_a8078bb0[port].b4 >= 7)
        DAT_a8078bb0[port].b6 = 1;
    else
        DAT_a8078bb0[port].b4++;
}
