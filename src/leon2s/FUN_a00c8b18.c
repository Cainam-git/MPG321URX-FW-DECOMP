/* leon2s FUN_a00c8b18 @ 0xa00c8b18-0xa00c8c64, -mcpu=v8 -Os -g.
 * (u8 port), void. Record DAT_a8078bb0[port] (24 bytes; word 0 bit-fields as in FUN_a00c91f8).
 * FUN_a00c8760(port, buf) != 0 (buf = 2 bytes): st = 3. Otherwise func_0xa0f83044(0x9f1c2030) when bit 1 of
 * func_0xa0fb7fd8(port, 0, 0xf) is clear; then the bytes func_0xa0fb7fd8(port, 0, 0x22) and (port, 0, 0x23) are
 * compared with buf[0] and buf[1]: on a difference func_0xa0f83044(0x9f1c2068), the 4-bit field cnt (bits
 * 24..27) is decremented and st = 3; when both match func_0xa0f83044(0x9f1c2040), bit 23 = 0 and st = 1.
 * The 0x9f1c.... arguments are ROM addresses outside the image.
 */
struct Rec24 {
    unsigned int a : 3;
    unsigned int f28 : 1;
    unsigned int cnt : 4;
    unsigned int f23 : 1;
    unsigned int mid : 5;
    unsigned int st : 2;
    unsigned int x : 16;
    unsigned char pad[20];
};
extern struct Rec24 DAT_a8078bb0[];
extern int func_0xa0f83044(const char *, ...);
extern unsigned char func_0xa0fb7fd8(unsigned char, int, unsigned short);
extern unsigned char FUN_a00c8760(unsigned char, unsigned char *);

void FUN_a00c8b18(unsigned char port)
{
    unsigned char buf[2];

    if (FUN_a00c8760(port, buf) != 0) {
        DAT_a8078bb0[port].st = 3;
        return;
    }
    if ((func_0xa0fb7fd8(port, 0, 0xf) & 2) == 0)
        func_0xa0f83044((const char *)0x9f1c2030);
    if (func_0xa0fb7fd8(port, 0, 0x22) != buf[0] || func_0xa0fb7fd8(port, 0, 0x23) != buf[1]) {
        func_0xa0f83044((const char *)0x9f1c2068);
        DAT_a8078bb0[port].cnt--;
        DAT_a8078bb0[port].st = 3;
        return;
    }
    func_0xa0f83044((const char *)0x9f1c2040);
    DAT_a8078bb0[port].f23 = 0;
    DAT_a8078bb0[port].st = 1;
}
