/* FUN_a00cdb0c (leon2s 0xa00cdb0c-0xa00cdc40, 308 bytes), flags -mcpu=v8 -Os -g.
 * void (u8 port). Works on the 24-byte DAT_a8078bb0[port] record (layout as in FUN_a00c91f8: word 0 holds
 * bit-fields, big-endian: f28 = bit 28, st = bits 16..17; bytes +3..+6 are plain u8 members). Sets st = 1.
 * When f28 is 0: bytes +3..+6 are cleared, FUN_a00c87e8(port, 0xb, 0x4015), then for i = 0..4 the low byte of
 * the register word at 0xcf000000 | ((0x6350 + i) << 2) is written with FUN_a00c7654(port, 1, v), then
 * FUN_a00c87e8(port, 0, 0). Then: b3 >= 0x7f sets b5 = 1, else b3++; b4 >= 7 sets b6 = 1, else b4++.
 * Same source form as FUN_a00c91f8 (source order of the byte clears 3, 4, 5, 6; 'set flag' arm first).
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

void FUN_a00cdb0c(unsigned char port)
{
    unsigned char i;

    DAT_a8078bb0[port].st = 1;
    if (DAT_a8078bb0[port].f28 == 0) {
        DAT_a8078bb0[port].b3 = 0;
        DAT_a8078bb0[port].b4 = 0;
        DAT_a8078bb0[port].b5 = 0;
        DAT_a8078bb0[port].b6 = 0;
        FUN_a00c87e8(port, 0xb, 0x4015);
        for (i = 0; i < 5; i++)
            FUN_a00c7654(port, 1, *(volatile unsigned int *)(0xcf000000 | ((i + 0x6350) << 2)) & 0xff);
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
