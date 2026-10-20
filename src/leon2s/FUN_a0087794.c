/* FUN_a0087794 (leon2s 0xa0087794-0xa0087824, 144 bytes), flags -mcpu=v8 -Os -g.
 * w = v | (bit 6 of FUN_a00a78b4(port, 3)). When bit 4 of byte 0 of the 6-byte record port of ARR_a807cd2e is
 * set: FUN_a00a78fc(port, 3, w | 0x80) and FUN_a00a7940(port, 0x78, 0x10, 0); otherwise FUN_a00a78fc(port, 3, w)
 * and FUN_a00a7940(port, 0x78, 0x10, 1). The last call is a tail call. The value expression is written out in
 * each arm.
 */
struct Rec6 { unsigned char b0; unsigned char _1[5]; };
extern struct Rec6 ARR_a807cd2e[];
extern unsigned int FUN_a00a78b4(unsigned char, unsigned short);
extern void FUN_a00a78fc(unsigned char, unsigned short, unsigned char);
extern void FUN_a00a7940(unsigned int, short, unsigned int, unsigned int);

void FUN_a0087794(unsigned char port, unsigned int v)
{
    unsigned int r = FUN_a00a78b4(port, 3);

    if (ARR_a807cd2e[port].b0 & 0x10) {
        FUN_a00a78fc(port, 3, v | (r & 0x40) | 0x80);
        FUN_a00a7940(port, 0x78, 0x10, 0);
    } else {
        FUN_a00a78fc(port, 3, v | (r & 0x40));
        FUN_a00a7940(port, 0x78, 0x10, 1);
    }
}
