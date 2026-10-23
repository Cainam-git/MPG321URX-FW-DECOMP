/* leon2m FUN_a008ef48 @ 0xA008EF48..0xA008F354 (259 words) "ShowLogo": draws the power-on MSI logo and switches the
 * panel on. Flags -mcpu=v8 -O3 -g (-msoft-float gives the same code).
 * Where: start-up step 3 (App_CoolInitialize FUN_a0087020 -> FUN_a0081e0c -> here), i.e. after start-up step 2 with
 * FUN_a0106d64. A Big chip that stops in step 2 never gets here: no logo.
 * What it does at power-on (code facts, in order):
 * 1. Prints "ShowLogo !!" (ROM 0x1080A8). FUN_a0145fe8(0,0,0,0,1), FUN_a0145fc0(0x100 x3), FUN_a013ae00(0x80).
 * 2. Byte 0xA802D299 (= 0xA802D290[9]) is set to 100 around FUN_a00d8cd4() and then restored; FUN_a0090fd8().
 * 3. OSD layer 0 set-up: FUN_a0146298(3,0), FUN_a01461a8(0xA8024078,0), FUN_a00b52f8(0x7F,0x18,2), two
 *    FUN_a0146370 positions from FUN_a0146194(0x7F,0x18) (second one + 0x8F0), FUN_a01461dc x2, FUN_a014654c(0x10F,
 *    0xCF,0), FUN_a01463f8(1,0,0).
 * 4. Logo data: 0xBE8 calls FUN_a014648c(1, low byte of ROM u16 table 0x101E52[i], ROM byte 0x104D00[i] << 8, 0),
 *    with | 8 in the second value for i <= 0x673. FUN_a0146648(0x1F,0x56,6,0x4A,0).
 * 5. OSD layer 1 set-up, then a 63 x 10 cell grid from ROM u16 table 0x100554 (FUN_a0146a80 / FUN_a0146b20), then a
 *    26 x 10 grid with 0. FUN_a0146648(0x1B,0x138,0,0,1).
 * 6. FUN_a014512c(1, 1) = "SYSAPI_PanelOnOffControl" (ROM 0x1A6DF8) panel ON with wait; if bits 14..13 of u16
 *    0xA802CFF8 == 01: FUN_a0122d0c(). FUN_a0146dc0(1,1); tail call FUN_a00a45a8().
 * Can it wait or fail? Its own loops all have constant counts (0xBE8, 63 x 10, 26 x 10). One callee can wait without a
 * limit: FUN_a014512c(1, 1) loops 'while (FUN_a0141a98() == 0) { FUN_a01413d0(); FUN_a01295e4(); FUN_a002ced8(); }'
 * (Ghidra's C of FUN_a014512c) until panel state byte 0xA802E110 == 6 and 0xA802CC08 != 1; each round calls
 * FUN_a002ced8 (8051 F204 -> F208 copy), so the ring-1 test of FUN_CODE_7b5a keeps passing while it waits. Printing (FUN_a00df170) polls
 * the UART at most 0xFFFFF times per byte (Ghidra's C).
 * Compiler aids (no code): the loop bound sits in a local 'n = 0xBE8' (a literal bound is folded to 'i <= 0xBE7',
 * the firmware compares LTU/GEU 0xBE8, the same as FUN_a01539b8 'rem = 20'); the i > 0x673 arm reads the byte
 * table into a local 'h' first (orders the two hoisted ROM table bases as in the firmware); 0xA802CFF8 bits 14..13
 * are a 2-bit bitfield (the same field as FUN_a0085984's Scff4 +4 f13).
 */
extern unsigned char DAT_a802d290[];
struct Scff8 { unsigned short b15 : 1; unsigned short f13 : 2; unsigned short rest : 13; };
extern struct Scff8 DAT_a802cff8;
extern unsigned short DAT_a8024078[], DAT_a8024098[], DAT_a802408c[], DAT_a802404c[], DAT_a802406c[];
extern const unsigned short DAT_00101e52[];
extern const unsigned char DAT_00104d00[];
extern const unsigned short DAT_00100554[];
extern char s_001080a8[];
extern int FUN_a00df170(const char *, ...);
extern void FUN_a0145fe8(int, int, int, int, int);
extern void FUN_a0145fc0(int, int, int);
extern void FUN_a013ae00(int);
extern void FUN_a00d8cd4(void);
extern void FUN_a0090fd8(void);
extern void FUN_a0146298(int, int);
extern void FUN_a01461a8(unsigned short *, int);
extern void FUN_a00b52f8(int, int, int);
extern unsigned short FUN_a0146194(int, int);
extern void FUN_a0146370(int, int, int);
extern void FUN_a01461dc(int, unsigned short *, int);
extern void FUN_a014654c(int, int, int);
extern void FUN_a01463f8(int, int, int);
extern void FUN_a014648c(int, unsigned char, unsigned short, int);
extern void FUN_a0146648(int, int, int, int, int);
extern void FUN_a0146dc0(int, int);
extern void FUN_a0146c40(int, int, int);
extern void FUN_a014613c(int, int, int);
extern void FUN_a0146ab0(int, int);
extern void FUN_a0146108(int);
extern void FUN_a0146a80(unsigned short, unsigned short, int, int, int);
extern void FUN_a0146b20(int, unsigned short, unsigned short, int, unsigned char, int);
extern void FUN_a014512c(int, int);
extern void FUN_a0122d0c(void);
extern void FUN_a00a45a8(void);

void FUN_a008ef48(void)
{
    unsigned char save, x, y;
    unsigned short i, u, v, n;

    save = DAT_a802d290[9];
    FUN_a00df170(s_001080a8);
    FUN_a0145fe8(0, 0, 0, 0, 1);
    FUN_a0145fc0(0x100, 0x100, 0x100);
    FUN_a013ae00(0x80);
    DAT_a802d290[9] = 100;
    FUN_a00d8cd4();
    DAT_a802d290[9] = save;
    FUN_a0090fd8();
    FUN_a0146298(3, 0);
    FUN_a01461a8(DAT_a8024078, 0);
    FUN_a00b52f8(0x7f, 0x18, 2);
    FUN_a0146298(3, 0);
    FUN_a0146370(0, FUN_a0146194(0x7f, 0x18), 0);
    FUN_a0146370(1, FUN_a0146194(0x7f, 0x18) + 0x8f0, 0);
    FUN_a01461dc(1, DAT_a8024098, 0);
    FUN_a01461dc(1, DAT_a802408c, 0);
    FUN_a014654c(0x10f, 0xcf, 0);
    FUN_a01463f8(1, 0, 0);
    n = 0xbe8;
    for (i = 0; i < n; i++) {
        if (i > 0x673) {
            unsigned char h = DAT_00104d00[i];
            FUN_a014648c(1, DAT_00101e52[i], h << 8, 0);
        }
        else
            FUN_a014648c(1, DAT_00101e52[i], DAT_00104d00[i] << 8 | 8, 0);
    }
    FUN_a0146648(0x1f, 0x56, 6, 0x4a, 0);
    FUN_a0146298(3, 1);
    FUN_a01461a8(DAT_a802404c, 1);
    FUN_a0146dc0(0, 1);
    FUN_a0146c40(8, 0, 1);
    FUN_a014613c(0x3f, 10, 1);
    FUN_a0146ab0(2, 1);
    FUN_a0146108(1);
    FUN_a014654c(0x136, 0x6e5, 1);
    FUN_a0146298(3, 1);
    FUN_a0146370(0, FUN_a0146194(0x3f, 10), 1);
    FUN_a01461dc(1, DAT_a802406c, 1);
    for (y = 0; y <= 9; y++)
        for (x = 0; x <= 0x3e; x++) {
            FUN_a0146a80(x, y, 1, 0, 1);
            FUN_a0146b20(1, x, y, 1, DAT_00100554[y * 63 + x], 1);
        }
    FUN_a0146ab0(2, 1);
    for (v = 0; v <= 9; v++)
        for (u = 0; u <= 0x19; u++) {
            FUN_a0146a80(u, v, 1, 0, 1);
            FUN_a0146b20(1, u, v, 1, 0, 1);
        }
    FUN_a0146648(0x1b, 0x138, 0, 0, 1);
    if (DAT_a802cff8.f13 == 1) {
        FUN_a014512c(1, 1);
        FUN_a0122d0c();
    } else
        FUN_a014512c(1, 1);
    FUN_a0146dc0(1, 1);
    FUN_a00a45a8();
}
