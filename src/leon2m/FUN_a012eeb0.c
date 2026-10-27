/* leon2m FUN_a012eeb0 @ 0xa012eeb0-0xa012f12c (636 bytes), flags -mcpu=v8 -O3 -g. Callers: FUN_a014c794,
 * FUN_a014c7bc.
 * Prints "LoadGamma : %02X" with v, then switches on v (jump table for 0x11..0x30):
 *  - 0x11..0x18, 0x1a: with byte DAT_a802e1d7 == 0: when FUN_a010af18() is non-zero FUN_a010af50() and
 *    func_0x4008d1a0(50) first; FUN_a010ae70(), FUN_a010afc8(), FUN_a010b198(), FUN_a012e3ec(1 << (v & 0xf) as
 *    16 bits), FUN_a010af34(). Otherwise: when FUN_a010ae38() is non-zero FUN_a010ae70() and func_0x4008d1a0(50)
 *    first; FUN_a010af50(), FUN_a010adc0(0, 1), FUN_a012e3ec(1 << (v & 0xf)), FUN_a010ae54().
 *  - 0x19: the second form with FUN_a012e3ec(0x200).
 *  - 0x20: the FUN_a010ae38 test as above, FUN_a010af50(), FUN_a010afc8(), FUN_a010b198(), FUN_a010adc0(1, 1),
 *    FUN_a012ec24(0 / 1 / 2, word DAT_a8027bac[v & 0xf] + 0 / 0x140 / 0x280), FUN_a010ae54().
 *  - 0x30: the FUN_a010af18 test as above, FUN_a010ae70(), FUN_a010afc8(), FUN_a010b198(),
 *    FUN_a010af6c(0 / 1 / 2, word DAT_a8027ba8[v & 0xf] + 0 / 0x40 / 0x80), FUN_a010af34().
 *  - other values: FUN_a010ae70(), FUN_a010af50(), FUN_a010afc8(), FUN_a010b198().
 * Source form: the DAT_a802e1d7 test is written '== 0' first (the firmware's fall-through order).
 */
extern int FUN_a00df170(const char *fmt, ...);
extern const char s_001a5220[];
extern unsigned char FUN_a010ae38(void);
extern void FUN_a010ae54(void);
extern void FUN_a010ae70(void);
extern unsigned char FUN_a010af18(void);
extern void FUN_a010af34(void);
extern void FUN_a010af50(void);
extern void FUN_a010af6c(int, int);
extern void FUN_a010afc8(void);
extern void FUN_a010b198(void);
extern void FUN_a010adc0(unsigned char, unsigned char);
extern void FUN_a012e3ec(unsigned int bit);
extern void FUN_a012ec24(unsigned char ch, const unsigned char *s);
extern void func_0x4008d1a0(int ms);
extern unsigned char DAT_a802e1d7;
extern unsigned int DAT_a8027ba8[], DAT_a8027bac[];

void FUN_a012eeb0(unsigned char v)
{
    FUN_a00df170(s_001a5220, v);
    switch (v) {
    case 0x11: case 0x12: case 0x13: case 0x14: case 0x15: case 0x16: case 0x17: case 0x18: case 0x1a:
        if (DAT_a802e1d7 == 0) {
            if (FUN_a010af18()) {
                FUN_a010af50();
                func_0x4008d1a0(0x32);
            }
            FUN_a010ae70();
            FUN_a010afc8();
            FUN_a010b198();
            FUN_a012e3ec((unsigned short)(1 << (v & 0xf)));
            FUN_a010af34();
        } else {
            if (FUN_a010ae38()) {
                FUN_a010ae70();
                func_0x4008d1a0(0x32);
            }
            FUN_a010af50();
            FUN_a010adc0(0, 1);
            FUN_a012e3ec((unsigned short)(1 << (v & 0xf)));
            FUN_a010ae54();
        }
        break;
    case 0x19:
        if (FUN_a010ae38()) {
            FUN_a010ae70();
            func_0x4008d1a0(0x32);
        }
        FUN_a010af50();
        FUN_a010adc0(0, 1);
        FUN_a012e3ec(0x200);
        FUN_a010ae54();
        break;
    case 0x20:
        if (FUN_a010ae38()) {
            FUN_a010ae70();
            func_0x4008d1a0(0x32);
        }
        FUN_a010af50();
        FUN_a010afc8();
        FUN_a010b198();
        FUN_a010adc0(1, 1);
        FUN_a012ec24(0, (const unsigned char *)DAT_a8027bac[v & 0xf]);
        FUN_a012ec24(1, (const unsigned char *)(DAT_a8027bac[v & 0xf] + 0x140));
        FUN_a012ec24(2, (const unsigned char *)(DAT_a8027bac[v & 0xf] + 0x280));
        FUN_a010ae54();
        break;
    case 0x30:
        if (FUN_a010af18()) {
            FUN_a010af50();
            func_0x4008d1a0(0x32);
        }
        FUN_a010ae70();
        FUN_a010afc8();
        FUN_a010b198();
        FUN_a010af6c(0, DAT_a8027ba8[v & 0xf]);
        FUN_a010af6c(1, DAT_a8027ba8[v & 0xf] + 0x40);
        FUN_a010af6c(2, DAT_a8027ba8[v & 0xf] + 0x80);
        FUN_a010af34();
        break;
    default:
        FUN_a010ae70();
        FUN_a010af50();
        FUN_a010afc8();
        FUN_a010b198();
        break;
    }
}
