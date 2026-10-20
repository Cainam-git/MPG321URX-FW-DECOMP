/* leon2s FUN_a00cb1d4 @ 0xa00cb1d4-0xa00cb3e8 (532 bytes, 133 words)
 * Flags: -mcpu=v8 -Os -g.
 * Code facts: void (u8 port). It uses the 24-byte DAT_a8078bb0 records. The 2-bit state field st (bits 16..17
 * of word 0, the same layout as FUN_a00ce864 / FUN_a00cf6bc) is set to 1. Every failure sets st = 0 and
 * returns: (u8)FUN_a00c9798(port, &DAT_a807d250) != 0, then byte +1 of the 2-byte DAT_a807d250 & 0xc, then
 * (u8)FUN_a00c8048(port, 0x74, 0x80, 0x11), then (u8)FUN_a00c81f8(port, DAT_a807ce50, 0x11). A zero
 * u16 count ((hi & 3) << 8) + lo (fw add, then sll 16 test) sets st = 3 and returns. Otherwise it reads 8 + 8 bytes
 * into a stack buffer with FUN_a00c7770(port, 1), after FUN_a00c87e8(port, 1 / 3, 0x8000). After
 * FUN_a00c87e8(port, 5, 0x8000) it writes DAT_a807ce50[1..16] and then the buffer with FUN_a00c7654(port, 1, b).
 * Last, it copies 5 bytes DAT_a807ce38[port*5 + i] -> DAT_a807cda8[port*5 + i]. All counters are u8.
 * BEHAVIOUR fixes against the draft: the count is joined with + (not |) as a u16; the record field is a
 * bit-field (no casted word masks). No aids, no volatile.
 */
struct Rec24 {
    unsigned int top:4;
    unsigned int cnt:4;
    unsigned int mid:6;
    unsigned int st:2;
    unsigned int low:16;
    unsigned char b4[20];
};
struct D250 { unsigned char lo; unsigned char hi; };
extern struct Rec24 DAT_a8078bb0[];
extern struct D250 DAT_a807d250;
extern unsigned char DAT_a807ce50[];
extern unsigned char DAT_a807cda8[];
extern unsigned char DAT_a807ce38[];
extern unsigned int FUN_a00c9798(unsigned char, struct D250 *);
extern unsigned int FUN_a00c8048(unsigned char, unsigned char, unsigned char, unsigned char);
extern unsigned int FUN_a00c81f8(unsigned char, unsigned char *, unsigned char);
extern void FUN_a00c87e8(unsigned char, unsigned char, unsigned short);
extern unsigned char FUN_a00c7770(unsigned char, unsigned char);
extern void FUN_a00c7654(unsigned char, unsigned char, unsigned char);

void FUN_a00cb1d4(unsigned char port)
{
    unsigned char buf[16];
    unsigned char i;
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
    if (n == 0) {
        DAT_a8078bb0[port].st = 3;
        return;
    }
    if ((unsigned char)FUN_a00c8048(port, 0x74, 0x80, 0x11) != 0) {
        DAT_a8078bb0[port].st = 0;
        return;
    }
    if ((unsigned char)FUN_a00c81f8(port, DAT_a807ce50, 0x11) != 0) {
        DAT_a8078bb0[port].st = 0;
        return;
    }
    FUN_a00c87e8(port, 1, 0x8000);
    for (i = 0; i < 8; i++)
        buf[i] = FUN_a00c7770(port, 1);
    FUN_a00c87e8(port, 3, 0x8000);
    for (i = 8; i < 16; i++)
        buf[i] = FUN_a00c7770(port, 1);
    FUN_a00c87e8(port, 5, 0x8000);
    for (i = 0; i < 16; i++)
        FUN_a00c7654(port, 1, DAT_a807ce50[i + 1]);
    for (i = 0; i < 16; i++)
        FUN_a00c7654(port, 1, buf[i]);
    for (i = 0; i < 5; i++)
        DAT_a807cda8[port * 5 + i] = DAT_a807ce38[port * 5 + i];
}
