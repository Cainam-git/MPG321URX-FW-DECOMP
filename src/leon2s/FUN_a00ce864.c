/* leon2s FUN_a00ce864 @ 0xa00ce864-0xa00cea60 (508 bytes, 127 words)
 * Flags: -mcpu=v8 -Os -g.
 * u8 port; DAT_a8078bb0 is an array of 24-byte records whose first word holds bit-fields (big-endian:
 * cnt = bits 24..27, st = bits 16..17; the firmware reads st back with lduh +0 & 3). It sets st = 1; if
 * DAT_a807d636 == port it sets record byte +9 and DAT_a807d636 to 0xff (source order b9 first gives the
 * firmware store order) and calls ROM func_0xa0f83044(DAT_9f1c2158, a symbol). ROM func_0xa0f96400(0, 0x90,
 * 0x69493, 0, buf) fills a 16-byte stack buffer. If buf[0] & 6: cnt -= 1; st = 0 when cnt is now 0, else 3
 * (the == 0 arm first); then it returns unless st == 1. If buf[0] & 0x18: st = 0. Otherwise buf[j] = j + 0xb0
 * for u16 j < 8, FUN_a00c87e8(port, 8, 0x8000), FUN_a00c7654(port, 1, buf[j]) for each j, ROM
 * func_0xa0f963d4(0, 0x80, 0x692f0, 7, buf), FUN_a00c7654(port, 6, 0xd0), and polls FUN_a00c7770(port, 6)
 * until bit 7 is clear. The record fields are bit-fields. No volatile.
 */
struct Rec24 {
    unsigned int top:4;
    unsigned int cnt:4;
    unsigned int mid:6;
    unsigned int st:2;
    unsigned int low:16;
    unsigned char b4[5];
    unsigned char b9;
    unsigned char pad[14];
};
extern struct Rec24 DAT_a8078bb0[];
extern unsigned char DAT_a807d636;
extern unsigned char DAT_9f1c2158[];
extern void FUN_a00c7654(unsigned char, unsigned char, unsigned char);
extern unsigned char FUN_a00c7770(unsigned char, unsigned char);
extern void FUN_a00c87e8(unsigned char, unsigned char, unsigned short);
extern int func_0xa0f83044(void *);
extern int func_0xa0f963d4(int, int, int, int, unsigned char *);
extern int func_0xa0f96400(int, int, int, int, unsigned char *);

void FUN_a00ce864(unsigned char port)
{
    unsigned char buf[16];
    unsigned short j;
    unsigned char b;

    DAT_a8078bb0[port].st = 1;
    if (DAT_a807d636 == port) {
        DAT_a8078bb0[port].b9 = 0xff;
        DAT_a807d636 = 0xff;
        func_0xa0f83044(DAT_9f1c2158);
    }
    func_0xa0f96400(0, 0x90, 0x69493, 0, buf);
    b = buf[0];
    if ((b & 6) != 0) {
        DAT_a8078bb0[port].cnt = DAT_a8078bb0[port].cnt - 1;
        if (DAT_a8078bb0[port].cnt == 0)
            DAT_a8078bb0[port].st = 0;
        else
            DAT_a8078bb0[port].st = 3;
        if (DAT_a8078bb0[port].st != 1)
            return;
    }
    if ((b & 0x18) != 0) {
        DAT_a8078bb0[port].st = 0;
    } else {
        for (j = 0; j < 8; j++)
            buf[j] = j + 0xb0;
        FUN_a00c87e8(port, 8, 0x8000);
        for (j = 0; j < 8; j++)
            FUN_a00c7654(port, 1, buf[j]);
        func_0xa0f963d4(0, 0x80, 0x692f0, 7, buf);
        FUN_a00c7654(port, 6, 0xd0);
        while (FUN_a00c7770(port, 6) & 0x80)
            ;
    }
}
