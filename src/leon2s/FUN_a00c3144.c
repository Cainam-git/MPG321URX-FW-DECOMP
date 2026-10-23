/* leon2s FUN_a00c3144 @ 0xa00c3144-0xa00c32bc, -mcpu=v8 -Os -g.
 * (u8 port), void. st = DAT_a8078c90[port], t = DAT_a8078c98[port] (u32), bit = 1 << port in the byte mask
 * DAT_a8078c5b. st = 0 when bit 7 of halfword +0x12 of the 0x14-byte record DAT_a807a824[port] is clear;
 * t = func_0xa0fc2064() (ROM call) when st == 1 and byte +0 of that record is 3. When (u8)FUN_a00c30e4(port)
 * == 1: bit cleared, st = 0. Otherwise, when st == 1 and func_0xa0fc2064() - t <= 699: bit set. Otherwise by
 * byte +0xd of the 16-byte record DAT_a807d5c8[port]: 2..12 sets the bit, 13 clears it and sets st = 1, any
 * other value clears it and sets st = 0.
 * Source form: in the value-13 arm st = 1 is written before the mask update.
 */
struct R14 { unsigned char b0; unsigned char pad[0x11]; unsigned short h12; };
struct rec16 { unsigned char pad[0xd]; unsigned char b13; unsigned char rest[2]; };
extern struct R14 DAT_a807a824[];
extern struct rec16 DAT_a807d5c8[];
extern unsigned char DAT_a8078c90[];
extern unsigned int DAT_a8078c98[];
extern unsigned char DAT_a8078c5b;
extern unsigned int func_0xa0fc2064(void);
extern unsigned int FUN_a00c30e4(unsigned char);

void FUN_a00c3144(unsigned char port)
{
    unsigned char c;

    if ((DAT_a807a824[port].h12 & 0x80) == 0)
        DAT_a8078c90[port] = 0;
    if (DAT_a8078c90[port] == 1 && DAT_a807a824[port].b0 == 3)
        DAT_a8078c98[port] = func_0xa0fc2064();
    if ((unsigned char)FUN_a00c30e4(port) == 1) {
        DAT_a8078c5b &= ~(1 << port);
        DAT_a8078c90[port] = 0;
        return;
    }
    if (DAT_a8078c90[port] == 1 && func_0xa0fc2064() - DAT_a8078c98[port] <= 699) {
        DAT_a8078c5b |= 1 << port;
        return;
    }
    c = DAT_a807d5c8[port].b13;
    if ((unsigned char)(c - 2) <= 10) {
        DAT_a8078c5b |= 1 << port;
    } else if (c == 13) {
        DAT_a8078c90[port] = 1;
        DAT_a8078c5b &= ~(1 << port);
    } else {
        DAT_a8078c5b &= ~(1 << port);
        DAT_a8078c90[port] = 0;
    }
}
