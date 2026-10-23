/* leon2m FUN_a015266c @ 0xa015266c..0xa0152a20 (948 bytes)  Big chip start-up, step 2 of main()
 * Flags: -mcpu=v8 -O3 -g -msoft-float, also at -mcpu=v8 -O3 -g.
 *
 * Caller: main() FUN_a00295a4 (func_0x000f266c in the RAM copy), once, between FUN_a008796c and FUN_a0087020, before
 * the endless main loop. No other caller found.
 * What the code does (code facts, in order):
 * 1. Initialises the state block at 0xA802E3D0: word 0 bits 31, 30, 29, 28, 26, 24, 23, 22, 19 cleared and 27, 25, 21
 *    set; word +4 bits 20..31 cleared (three 4-bit fields); bytes +3/+6/+7/+0xB/+0x18/+0x1C/+0x1D/+0x22/+0x23/+0x30/+0x31
 *    = 0, +8 = 100, +9 and +0xC..+0x11 = 50, +0xA and +0x12..+0x17 = 0x80, +0x2E/+0x2F = 1; then bit 18 of word 0
 *    cleared, +0x33 = 1, half +0x36 = 0, +0x32 = +0x34 = 0.
 * 2. FUN_a0102680(); FUN_a00de7c4(); FUN_a0138ae8();
 * 3. WAIT 1 (no timeout): do { nop; r = FUN_a0133564(); 0xA802CF90 = r; } while (r == 0);
 *    FUN_a0133564 = MailBox_Read(portal 0 = helper chip 8051, offset 0xB8) bits 8..15. Prints "Boot from %02X\r\n" with r,
 *    then FUN_a0124448(0xA802CF90).
 * 4. WAIT 2 (no timeout): while (!FUN_a013701c()) { if (debug mask 0xA802B0B0 & 0x10) print "\n wait otp ready\r\n"; }
 *    FUN_a013701c = MailBox_Read(portal 1 = Small chip, offset 0xC) bit 26. Then "\n otp ready\r\n" (if mask & 0x10).
 * 5. FUN_a01400e0(); FUN_a0142380(); FUN_a0153c74(); calls the function pointer at 0xA802CC3C if it is non-zero;
 *    FUN_a0141b60(); FUN_a01427d4(); FUN_a0118400(0x1E, 0x32); FUN_a01118c0(FUN_a01423a0()); FUN_a0112db0(0);
 *    FUN_a01026e8(0, 960000000); FUN_a01026e8(4, 960000000) (GPLL_DISPM / GPLL_FRC = 960 MHz); FUN_a013a750();
 *    FUN_a01439d8(0, 1);
 * 6. WAIT 3 (no timeout): while (!FUN_a0136fc4()) { if (mask & 0x10) print "\n wait sub init\r\n"; }
 *    FUN_a0136fc4 = MailBox_Read(portal 1 = Small chip, offset 0) bit 0. Then "\n sub init\r\n" (if mask & 0x10).
 * 7. FUN_a012cfac(); FUN_a00fd558(); FUN_a0141964() (display start-up, matched); FUN_a015209c(); FUN_a013c944();
 *    FUN_a012fc04(); FUN_a012b7b8(); if ((raw active 0x58-byte row word 0 (FUN_a01241fc()) & 0x700000) == 0x200000, i.e.
 *    link type 2 = eDP) FUN_a012b9a0(); FUN_a0138284(); FUN_a01382e4(); FUN_a01356fc(2, 0); FUN_a01243dc();
 *    FUN_a012c188(); tail call FUN_a01298d8().
 * The three waits have NO timeout and run before main() reaches its main loop (where the command switch
 *   FUN_a00bfcc4 -> FUN_a00bf110 "--->UartSetI2CEnable" is served). So the command switch is served only after the
 *   helper chip has posted a non-zero boot byte AND the Small chip has set both ready bits. This function reads
 *   the 0x58-byte row only in step 7 (after the waits).
 * Matching notes: gcc 3.4 sched-deps flushes its pending memory lists after 32 refs: the 34th memory op of step 1
 *   (clrb +0x31) is a barrier, so bit 18 / +0x33 / +0x36 / +0x32 / +0x34 come after it in the source. Callee return
 *   types: FUN_a013701c / FUN_a0136fc4 / FUN_a00dd614 return unsigned char (btst 0xff at the use).
 * Statement order of step 1: one order that reproduces the target byte for byte under the barrier rule; gcc maps
 *   many source orders to the same code. The stores, their values and their final order are exactly the target's.
 */
struct BootState {
    unsigned int k31:1, k30:1, k29:1, k28:1, k27:1, k26:1, k25:1, k24:1,
                 k23:1, k22:1, k21:1, k20:1, k19:1, k18:1, x8:10;
    unsigned char b03;
    unsigned int f28:4, f24:4, f20:4, x16:4;
    unsigned char b06, b07;
    unsigned char b08, b09, b0a, b0b, b0c, b0d, b0e, b0f, b10, b11, b12, b13, b14, b15, b16, b17, b18;
    unsigned char b19, b1a, b1b, b1c, b1d, b1e, b1f, b20, b21, b22, b23, b24, b25, b26, b27, b28, b29, b2a, b2b, b2c, b2d;
    unsigned char b2e, b2f, b30, b31, b32, b33, b34, b35;
    unsigned short h36;
};
extern struct BootState DAT_a802e3d0;
extern unsigned char DAT_a802cf90;
extern void (*DAT_a802cc3c)(void);
extern char s_001a7558[], s_001a7570[], s_001a7588[], s_001a7598[], s_001a75b0[];
extern int FUN_a00df170();
extern void FUN_a0102680(void);
extern void FUN_a00de7c4(void);
extern void FUN_a0138ae8(void);
extern int FUN_a0133564(void);
extern void FUN_a0124448(unsigned char);
extern unsigned char FUN_a013701c(void);
extern unsigned char FUN_a00dd614(unsigned char);
extern void FUN_a01400e0(void);
extern void FUN_a0142380(void);
extern void FUN_a0153c74(void);
extern void FUN_a0141b60(void);
extern void FUN_a01427d4(void);
extern void FUN_a0118400(int, int);
extern int FUN_a01423a0(void);
extern void FUN_a01118c0(unsigned char);
extern void FUN_a0112db0(int);
extern void FUN_a01026e8(unsigned char ch, unsigned int freq);
extern void FUN_a013a750(void);
extern void FUN_a01439d8(int, int);
extern unsigned char FUN_a0136fc4(void);
extern void FUN_a012cfac(void);
extern void FUN_a00fd558(void);
extern void FUN_a0141964(void);
extern void FUN_a015209c(void);
extern void FUN_a013c944(void);
extern void FUN_a012fc04(void);
extern void FUN_a012b7b8(void);
extern unsigned int *FUN_a01241fc(void);
extern void FUN_a012b9a0(void);
extern void FUN_a0138284(void);
extern void FUN_a01382e4(void);
extern void FUN_a01356fc(int, int);
extern void FUN_a01243dc(void);
extern void FUN_a012c188(void);
extern void FUN_a01298d8(void);

void FUN_a015266c(void)
{
    unsigned char r;
    DAT_a802e3d0.b2e = 1;
    DAT_a802e3d0.b2f = 1;
    DAT_a802e3d0.k31 = 0;
    DAT_a802e3d0.k29 = 0;
    DAT_a802e3d0.k25 = 1;
    DAT_a802e3d0.k24 = 0;
    DAT_a802e3d0.k23 = 0;
    DAT_a802e3d0.b07 = 0;
    DAT_a802e3d0.k28 = 0;
    DAT_a802e3d0.k27 = 1;
    DAT_a802e3d0.k26 = 0;
    DAT_a802e3d0.f28 = 0;
    DAT_a802e3d0.k22 = 0;
    DAT_a802e3d0.b06 = 0;
    DAT_a802e3d0.k30 = 0;
    DAT_a802e3d0.k21 = 1;
    DAT_a802e3d0.k19 = 0;
    DAT_a802e3d0.f20 = 0;
    DAT_a802e3d0.b0a = 0x80;
    DAT_a802e3d0.b0b = 0;
    DAT_a802e3d0.b09 = 50;
    DAT_a802e3d0.b0e = 50;
    DAT_a802e3d0.b11 = 50;
    DAT_a802e3d0.b0d = 50;
    DAT_a802e3d0.b10 = 50;
    DAT_a802e3d0.b0c = 50;
    DAT_a802e3d0.b12 = 0x80;
    DAT_a802e3d0.b13 = 0x80;
    DAT_a802e3d0.b08 = 100;
    DAT_a802e3d0.b14 = 0x80;
    DAT_a802e3d0.b15 = 0x80;
    DAT_a802e3d0.b16 = 0x80;
    DAT_a802e3d0.f24 = 0;
    DAT_a802e3d0.b0f = 50;
    DAT_a802e3d0.b17 = 0x80;
    DAT_a802e3d0.b18 = 0;
    DAT_a802e3d0.b1c = 0;
    DAT_a802e3d0.b1d = 0;
    DAT_a802e3d0.b03 = 0;
    DAT_a802e3d0.b22 = 0;
    DAT_a802e3d0.b23 = 0;
    DAT_a802e3d0.b30 = 0;
    DAT_a802e3d0.b31 = 0;
    DAT_a802e3d0.k18 = 0;
    DAT_a802e3d0.h36 = 0;
    DAT_a802e3d0.b32 = 0;
    DAT_a802e3d0.b34 = 0;
    DAT_a802e3d0.b33 = 1;
    FUN_a0102680();
    FUN_a00de7c4();
    FUN_a0138ae8();
    do {
        __asm__ volatile ("nop");
        r = FUN_a0133564();
        DAT_a802cf90 = r;
    } while (r == 0);
    FUN_a00df170(s_001a7558, r);
    FUN_a0124448(DAT_a802cf90);
    while (FUN_a013701c() == 0) {
        if (FUN_a00dd614(0x10))
            FUN_a00df170(s_001a7570);
    }
    if (FUN_a00dd614(0x10))
        FUN_a00df170(s_001a7588);
    FUN_a01400e0();
    FUN_a0142380();
    FUN_a0153c74();
    if (DAT_a802cc3c != 0)
        DAT_a802cc3c();
    FUN_a0141b60();
    FUN_a01427d4();
    FUN_a0118400(0x1e, 0x32);
    FUN_a01118c0(FUN_a01423a0());
    FUN_a0112db0(0);
    FUN_a01026e8(0, 960000000);
    FUN_a01026e8(4, 960000000);
    FUN_a013a750();
    FUN_a01439d8(0, 1);
    while (FUN_a0136fc4() == 0) {
        if (FUN_a00dd614(0x10))
            FUN_a00df170(s_001a7598);
    }
    if (FUN_a00dd614(0x10))
        FUN_a00df170(s_001a75b0);
    FUN_a012cfac();
    FUN_a00fd558();
    FUN_a0141964();
    FUN_a015209c();
    FUN_a013c944();
    FUN_a012fc04();
    FUN_a012b7b8();
    if ((*FUN_a01241fc() & 0x700000) == 0x200000)
        FUN_a012b9a0();
    FUN_a0138284();
    FUN_a01382e4();
    FUN_a01356fc(2, 0);
    FUN_a01243dc();
    FUN_a012c188();
    FUN_a01298d8();
}
