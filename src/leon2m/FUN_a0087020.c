/* leon2m FUN_a0087020 @ 0xa0087020..0xa0087430 (1,040 bytes)  App_CoolInitialize: Big chip start-up, step 3 of main()
 * (flags -mcpu=v8 -O3 -g -msoft-float; -mcpu=v8 -O3 -g gives the same code).
 *
 * Caller: main() FUN_a00295a4 (func_0x00027020), once, after FUN_a015266c and before the endless main loop.
 * What the code does (code facts, in order):
 * 1. type = FUN_a0148868() (low byte); FUN_a00d3bb4().
 * 2. Initialises the state block at 0xA802CFF4 (halfword bitfields + bytes): +0 = 0x2C00 in
 *    effect (bit 12 cleared and stored first, low byte cleared, then bits 13/11/10 set, 9..8/14/15 cleared); +6 high
 *    byte 0 and bits 4..7 0; +8 = 0; +9 = byte 0xA802D430 (= idx); half +0xA bit 6, +0xE bit 15, +0x14 bits 15/14,
 *    +0x18 bit 15, +4 bits 15..9 and 6, +0x3E bits 15..13 cleared; +0x3F = 0; halves +0xC/+0x10/+0x12/+0x1A = 0,
 *    +0x1C = 0, +0x1E/+0x2C/+0x2E/+0x30/+0x32 = 0x3FF, +0x20 = 0x36F, +0x22 = 0x7E, +0x24..+0x2A = 0x2DD.
 *    Also 0xA802D431 = 0xA802D427[idx], 0xA802D432 = 0xA802D42B[idx].
 * 3. if (type == 0) FUN_a008e650(); prints "\nApp_CoolInitialize type = %d \r\n" (0xFF5C0) with type;
 *    FUN_a00ba8bc(); FUN_a0127914(0); FUN_a0127898(); FUN_a0129598(); FUN_a00db054();
 *    if (type != 4) { FUN_a008767c(0); FUN_a014bc58(0); }
 * 4. Logo: FUN_a0081e0c() (which calls the logo drawer FUN_a008ef48 "ShowLogo !!") is called for type 0 and 1, and
 *    for type 2 only when bit 31 of 0xA802E1A0 is 0 (InInfo.b31, see src/leon2m/FUN_a0145af8.c). For type 1 first:
 *    bit 14 of word 0xA802D290 cleared; if half 0xA802D486 == 0x55AA or byte 0xA802D465 != 0: 0xA802D486 = 0xBB99,
 *    0xA802D465 = 0, FUN_a00dc3dc(), FUN_a0145c5c(n, 0) for n = 8, 9, 6, 7, 0xB, 0xA, 0xD, 0xC, 0x10, 0xE, 0xF, bytes
 *    0xA802D472/73/76/77 = 0, FUN_a0145360(1); then FUN_a014aed0(0x30, &0xA802D290, 0, 0x1FC) (0x1FC = size of the
 *    0xA802D290 state block). Any other type: no logo call here.
 * 5. FUN_a00db174(); then FUN_a0086ae8(n): type 1 -> 1; type 2 -> 0xA802D2AE = 5, FUN_a014aed0(0x30, &0xA802D290,
 *    0, 0x1FC), n = 2 if 0xA802E1A0 bit 31 else 1; (type & 0xF0) == 0x30 or type 5 -> 2; type 3 -> 4 if
 *    FUN_a0148a24() == 1, else FUN_a0086ae8(3) and bit 15 of 0xA802CFF4 set; (type & 0xF0) == 0x20 -> 3; type 4 -> 4;
 *    else 0.
 * 6. Tail call FUN_a01243b0(half 0xA802D486 == 0x55AA).
 * Control flow: no loops and no waits in this function (all branches go forward, it always returns via the
 *   tail call); it reads no 0x58-byte row data itself. It is on the path to the MSI logo
 *   (FUN_a0081e0c).
 * Source form: the sched-deps pending-list barrier (34th memory op = the +0x2A store) splits step 2: the +4 bits
 *   11/6, +0x3E, +0x3F, +0x18, +0x2C..+0x32 statements come after it in the source; one logo call after the type-1
 *   block (bb-reorder duplicates it); FUN_a014aed0 declared int-returning (delay-slot filling).
 * Statement order of step 2: one of the many source orders that gcc compiles to the same code. The stores, their
 *   values and their final order are the firmware's.
 */
struct CoolState {                      /* 0xA802CFF4 */
    unsigned short a15:1, b14:1, c13:1, d12:1, e11:1, f10:1, g98:2, lo:8;     /* +0x00 */
    unsigned short h02;                                                        /* +0x02 */
    unsigned short w15:1, w1413:2, w12:1, w11:1, w109:2, w87:2, w6:1, w50:6;   /* +0x04 */
    unsigned short hi6:8, f74:4, f30:4;                                        /* +0x06 */
    unsigned char b08, b09;                                                    /* +0x08 */
    unsigned short x15_7:9, x6:1, x5_0:6;                                      /* +0x0a */
    unsigned short h0c;                                                        /* +0x0c */
    unsigned short e15:1, e14_0:15;                                            /* +0x0e */
    unsigned short h10, h12;                                                   /* +0x10 */
    unsigned short m15:1, m14:1, m13_0:14;                                     /* +0x14 */
    unsigned short h16;                                                        /* +0x16 */
    unsigned short n15:1, n14_0:15;                                            /* +0x18 */
    unsigned short h1a;                                                        /* +0x1a */
    unsigned char b1c, b1d;                                                    /* +0x1c */
    unsigned short h1e, h20, h22, h24, h26, h28, h2a, h2c, h2e, h30, h32;      /* +0x1e */
    unsigned short h34, h36, h38, h3a, h3c;                                    /* +0x34 */
    unsigned short p15:1, p14:1, p13:1, p12_8:5, plo:8;                        /* +0x3e */
};
struct State290 {                       /* 0xA802D290 */
    unsigned int w0_hi:17, w0_b14:1, w0_lo:14;                                 /* +0x000 */
    unsigned char b004[0x1a];
    unsigned char b01e;                                                        /* +0x01e */
    unsigned char b01f[0x178];
    unsigned char a197[4];                                                     /* +0x197 */
    unsigned char a19b[5];                                                     /* +0x19b */
    unsigned char b1a0, b1a1, b1a2;                                            /* +0x1a0 */
    unsigned char b1a3[0x32];
    unsigned char b1d5;                                                        /* +0x1d5 */
    unsigned char b1d6[0xc];
    unsigned char b1e2, b1e3, b1e4, b1e5, b1e6, b1e7;                          /* +0x1e2 */
    unsigned char b1e8[0xe];
    unsigned short h1f6;                                                       /* +0x1f6 */
    unsigned char b1f8[4];
};
extern struct CoolState DAT_a802cff4;
extern struct State290 DAT_a802d290;
struct InInfo { unsigned int b31:1, f0:1, f1:1, b28:1, f2:1, f3:1, b25:2, rest0:24; };   /* 0xA802E1A0, as in src/leon2m/FUN_a0145af8.c */
extern struct InInfo DAT_a802e1a0;
extern char s_000ff5c0[];
extern int FUN_a00df170();
extern int FUN_a0148868(void);
extern void FUN_a00d3bb4(void);
extern void FUN_a008e650(void);
extern void FUN_a00ba8bc(void);
extern void FUN_a0127914(int);
extern void FUN_a0127898(void);
extern void FUN_a0129598(void);
extern void FUN_a00db054(void);
extern void FUN_a008767c(int);
extern void FUN_a014bc58(int);
extern void FUN_a0081e0c(void);
extern void FUN_a00db174(void);
extern void FUN_a00dc3dc(void);
extern void FUN_a0145c5c(int, int);
extern void FUN_a0145360(unsigned char);
extern int FUN_a014aed0(int, void *, int, int);
extern int FUN_a0148a24(void);
extern void FUN_a0086ae8(int);
extern void FUN_a01243b0(unsigned char);

void FUN_a0087020(void)
{
    unsigned char type, idx;

    type = FUN_a0148868();
    FUN_a00d3bb4();
    DAT_a802cff4.d12 = 0;
    DAT_a802cff4.lo = 0;
    DAT_a802cff4.hi6 = 0;
    idx = DAT_a802d290.b1a0;
    DAT_a802d290.b1a1 = DAT_a802d290.a197[idx];
    DAT_a802d290.b1a2 = DAT_a802d290.a19b[idx];
    DAT_a802cff4.b09 = idx;
    DAT_a802cff4.c13 = 1;
    DAT_a802cff4.e11 = 1;
    DAT_a802cff4.f10 = 1;
    DAT_a802cff4.g98 = 0;
    DAT_a802cff4.b14 = 0;
    DAT_a802cff4.e11 = 1;
    DAT_a802cff4.a15 = 0;
    DAT_a802cff4.h24 = 0x2dd;
    DAT_a802cff4.f74 = 0;
    DAT_a802cff4.x6 = 0;
    DAT_a802cff4.e15 = 0;
    DAT_a802cff4.m15 = 0;
    DAT_a802cff4.m14 = 0;
    DAT_a802cff4.w1413 = 0;
    DAT_a802cff4.w12 = 0;
    DAT_a802cff4.w109 = 0;
    DAT_a802cff4.w15 = 0;
    DAT_a802cff4.h20 = 0x36f;
    DAT_a802cff4.h22 = 0x7e;
    DAT_a802cff4.h26 = 0x2dd;
    DAT_a802cff4.h28 = 0x2dd;
    DAT_a802cff4.b08 = 0;
    DAT_a802cff4.b1c = 0;
    DAT_a802cff4.h0c = 0;
    DAT_a802cff4.h10 = 0;
    DAT_a802cff4.h12 = 0;
    DAT_a802cff4.h1a = 0;
    DAT_a802cff4.h1e = 0x3ff;
    DAT_a802cff4.h2a = 0x2dd;
    DAT_a802cff4.w11 = 0;
    DAT_a802cff4.w6 = 0;
    DAT_a802cff4.p14 = 0;
    DAT_a802cff4.p15 = 0;
    DAT_a802cff4.n15 = 0;
    DAT_a802cff4.p13 = 0;
    DAT_a802cff4.plo = 0;
    DAT_a802cff4.h2c = 0x3ff;
    DAT_a802cff4.h2e = 0x3ff;
    DAT_a802cff4.h30 = 0x3ff;
    DAT_a802cff4.h32 = 0x3ff;
    if (type == 0)
        FUN_a008e650();
    FUN_a00df170(s_000ff5c0, type);
    FUN_a00ba8bc();
    FUN_a0127914(0);
    FUN_a0127898();
    FUN_a0129598();
    FUN_a00db054();
    if (type != 4) {
        FUN_a008767c(0);
        FUN_a014bc58(0);
    }
    if (type <= 1) {
        if (type == 1) {
            DAT_a802d290.w0_b14 = 0;
            if (DAT_a802d290.h1f6 == 0x55aa || DAT_a802d290.b1d5 != 0) {
                DAT_a802d290.h1f6 = 0xbb99;
                DAT_a802d290.b1d5 = 0;
                FUN_a00dc3dc();
                FUN_a0145c5c(8, 0);
                FUN_a0145c5c(9, 0);
                FUN_a0145c5c(6, 0);
                FUN_a0145c5c(7, 0);
                DAT_a802d290.b1e2 = 0;
                DAT_a802d290.b1e6 = 0;
                DAT_a802d290.b1e3 = 0;
                DAT_a802d290.b1e7 = 0;
                FUN_a0145c5c(0xb, 0);
                FUN_a0145c5c(0xa, 0);
                FUN_a0145c5c(0xd, 0);
                FUN_a0145c5c(0xc, 0);
                FUN_a0145c5c(0x10, 0);
                FUN_a0145c5c(0xe, 0);
                FUN_a0145c5c(0xf, 0);
                FUN_a0145360(1);
            }
            FUN_a014aed0(0x30, &DAT_a802d290, 0, sizeof DAT_a802d290);
        }
        FUN_a0081e0c();
    } else if (type == 2 && DAT_a802e1a0.b31 == 0)
            FUN_a0081e0c();
    FUN_a00db174();
    if (type == 1)
        FUN_a0086ae8(1);
    else if (type == 2) {
        DAT_a802d290.b01e = 5;
        FUN_a014aed0(0x30, &DAT_a802d290, 0, sizeof DAT_a802d290);
        if (DAT_a802e1a0.b31 == 0)
            FUN_a0086ae8(1);
        else
            FUN_a0086ae8(2);
    } else if ((type & 0xf0) == 0x30)
        FUN_a0086ae8(2);
    else if (type == 5)
        FUN_a0086ae8(2);
    else if (type == 3) {
        if ((unsigned char)FUN_a0148a24() == 1)
            FUN_a0086ae8(4);
        else {
            FUN_a0086ae8(3);
            DAT_a802cff4.a15 = 1;
        }
    } else if ((type & 0xf0) == 0x20)
        FUN_a0086ae8(3);
    else if (type == 4)
        FUN_a0086ae8(4);
    else
        FUN_a0086ae8(0);
    if (DAT_a802d290.h1f6 == 0x55aa)
        FUN_a01243b0(1);
    else
        FUN_a01243b0(0);
}
