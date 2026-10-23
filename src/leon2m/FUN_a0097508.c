/* leon2m FUN_a0097508 @ 0xa0097508-0xa00976a8 (104 words).
 * When word 0xa802afec is 0x23: byte DAT_a802d290+0x1a4 = byte 0xa8025c55 and byte +0x19 = byte +0x8f. Otherwise:
 * byte +0x1a4 is cleared when FUN_a00837e4() is 1 and when it is 3; when word +0xb0 is non-zero it is cleared and
 * FUN_a00d5f3c() runs; bit 20 of word +0xac and bit 31 of word +0x1f4 are cleared; when byte +0x4a is 1 it is
 * cleared and FUN_a00d5eac(0) runs; when bit 7 of word +0xa8 is set it is cleared and FUN_a0124f44(),
 * FUN_a00d91fc(0), FUN_a00da184() run. Then byte +0x1f = afec - 0x23; when bit 20 of word +0xac is set, the byte
 * differs from byte 0xa8025c56 and FUN_a01445fc(byte +0x1e) is 0: FUN_a0124f44(), FUN_a00d91fc(0),
 * FUN_a01439d8(0x10, 1), FUN_a0148268(0, 1), FUN_a0148268(1, 1) (tail call).
 * Source form: bit 31 of word +0x1f4 is a signed 1-bit bit-field (a mask test places the clear block out of line).
 */
struct R290 {
    unsigned char pad0[0x19];
    unsigned char b19;
    unsigned char pad1a[0x1e - 0x1a];
    unsigned char b1e;
    unsigned char b1f;
    unsigned char pad20[0x4a - 0x20];
    unsigned char b4a;
    unsigned char pad4b[0x8f - 0x4b];
    unsigned char b8f;
    unsigned char pad90[0xa8 - 0x90];
    unsigned int wa8;
    unsigned int wac;
    unsigned int wb0;
    unsigned char padb4[0x1a4 - 0xb4];
    unsigned char b1a4;
    unsigned char pad1a5[0x1f4 - 0x1a5];
    union {
        unsigned int w;
        struct {
            signed int b31 : 1;
            unsigned int rest : 31;
        } f;
    } w1f4;
};
extern struct R290 DAT_a802d290;
extern unsigned int _DAT_a802afec;
extern unsigned char DAT_a8025c55;
extern unsigned char DAT_a8025c56;
extern unsigned char FUN_a00837e4(void);
extern void FUN_a00d5f3c(void);
extern void FUN_a00d5eac(int);
extern void FUN_a0124f44(void);
extern void FUN_a00d91fc(int);
extern void FUN_a00da184(void);
extern unsigned char FUN_a01445fc(unsigned char);
extern void FUN_a01439d8(int, int);
extern void FUN_a0148268(int, int);

void FUN_a0097508(void)
{
    if (_DAT_a802afec == 0x23) {
        DAT_a802d290.b1a4 = DAT_a8025c55;
        DAT_a802d290.b19 = DAT_a802d290.b8f;
    } else {
        if (FUN_a00837e4() == 1)
            DAT_a802d290.b1a4 = 0;
        if (DAT_a802d290.b1a4 == 3)
            DAT_a802d290.b1a4 = 0;
        if (DAT_a802d290.wb0 != 0) {
            DAT_a802d290.wb0 = 0;
            FUN_a00d5f3c();
        }
        DAT_a802d290.wac &= ~0x100000;
        if (DAT_a802d290.w1f4.f.b31)
            DAT_a802d290.w1f4.f.b31 = 0;
        if (DAT_a802d290.b4a == 1) {
            DAT_a802d290.b4a = 0;
            FUN_a00d5eac(0);
        }
        if (DAT_a802d290.wa8 & 0x80) {
            DAT_a802d290.wa8 &= ~0x80;
            FUN_a0124f44();
            FUN_a00d91fc(0);
            FUN_a00da184();
        }
    }
    DAT_a802d290.b1f = _DAT_a802afec - 0x23;
    if ((DAT_a802d290.wac & 0x100000) && DAT_a802d290.b1f != DAT_a8025c56 && !FUN_a01445fc(DAT_a802d290.b1e)) {
        FUN_a0124f44();
        FUN_a00d91fc(0);
        FUN_a01439d8(0x10, 1);
        FUN_a0148268(0, 1);
        FUN_a0148268(1, 1);
    }
}
