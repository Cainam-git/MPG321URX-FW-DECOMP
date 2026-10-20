/* leon2m FUN_a00f0b58 @ 0xa00f0b58-0xa00f1100 (362 words), -mcpu=v8 -O3 -g.
 * BYTE-EXACT (first C from the asm): jf 100.00 match=True, rawcmp 0/362.
 * What it does (dc6c channel bring-up, the "PLL auto on" / FreeRun step of one port; p = port code):
 *   p 2 or 6 -> block 2 with the state DAT_a802b746 (done flag), b744 (u16 retry count), b74a (u16 start tick);
 *   p 3 or 7 -> block 3 with b742 / b740 / b748; other p: return. v = reg 0x8e of the port (FUN_a00f2254 =
 *   port register read, FUN_a00f2298 = write, FUN_a00f232c = bit set/clear).
 *   Phase 1 (global DAT_a802b747 == 0): (v & 3) == 0 and count > 0x95, or count > 299 -> b747 = 1, count = 0;
 *     (v & 3) != 0 and count < 300 -> print "1retry_%d %02X" (count, v), FUN_a00f0380(p, count, v),
 *     reg 0x8e = 3, FUN_a0121c6c(p); p not 6/7 and reg 0x54 bit 7 clear -> print "[%02x]1Fail ? %d %d" and copy
 *     regs 0x77/0x78 into 0x52/0x53 (the inlined copy_7778); count++; return.
 *   Phase 2: done = 1 when ((v & 3) == 0 and reg 0x88 bit 5) or count > 299. (v & 3) != 0, reg 0x88 bit 5 set and
 *     count < 300 -> clear 0x88 bit 5, print "2retry_%d %02X", FUN_a00f0380 != 0 -> count = 300, the "2Fail ?"
 *     copy (p not 6/7, reg 0x54 bit 7 clear), reg 0x8e = 3, FUN_a0121c6c(p), start tick = now, count++.
 *     Then, while reg 0x88 bit 5 is clear: print MISC 5100 (only 2 arguments for the 4 %02x: code fact) and
 *     510B..510F of the clamped block; when 5100 bits 5 and 7 are both set: print "[%02x]PLL auto on : %d" (p,
 *     ms since the start tick); more than 50 ms -> FUN_a0121c6c(p), func_0x4008d1a0(5), set reg 0x88 bit 5,
 *     print "FreeRun", tail FUN_a00f2298(p, 0x8e, 3).
 *   Nothing here reads the input rate; it is the per-port PLL lock retry (up to 300 passes)
 *     that has to finish before the free-run calibration FUN_a00f04f8 of dc6c state 8.
 * Levers: the port test as four arms 2, 3, 6, 7 with the same bodies (fw compare chain; '||' gives xor/subx);
 *   the block clamp as an inlined helper 'static int blk_of(u8 b) { if (b >= 4) b = 0; return b; }' (fw: the
 *   first use a subx mask, the later uses branchy, like the fw); the 77/78 copy as a static helper used twice
 *   (fw has both copies inline) with the 52/53 value written straight into the print call (as a variable the
 *   'or' operands swap: 2 words).
 * Aids: none. volatile only on the 0xcf... registers.
 */
extern int FUN_a00df170(const char *fmt, ...);
extern unsigned char FUN_a00f2254(unsigned char blk, unsigned char reg);
extern void FUN_a00f2298(unsigned char blk, unsigned char reg, unsigned char val);
extern void FUN_a00f232c(unsigned char blk, unsigned char reg, unsigned char mask, unsigned char set);
extern unsigned char FUN_a00f0380(unsigned char p, unsigned short cnt, unsigned char v);
extern void FUN_a0121c6c(unsigned char);
extern int func_0x4008d1a0(int ms);
extern unsigned short func_0x4008d588(void);
extern unsigned short func_0x4008d594(unsigned short);
extern const unsigned short DAT_00199ffc[4];
extern unsigned char DAT_a802b747;
extern unsigned char DAT_a802b742, DAT_a802b746;
extern unsigned short DAT_a802b740, DAT_a802b744, DAT_a802b748, DAT_a802b74a;
extern char s_0019a1e0[], s_0019a200[], s_0019a220[], s_0019a240[], s_0019a260[], s_0019a270[];
extern char s_0019a290[], s_0019a2b0[];

#define MREG(i, o) (*(volatile unsigned int *)(0xcf000000 | ((DAT_00199ffc[i] + (o)) << 2)))
#define BLK(x) blk_of(x)
static int blk_of(unsigned char b)
{
    if (b >= 4)
        b = 0;
    return b;
}

static void copy_7778(unsigned char p, char *fmt)
{
    unsigned short a;

    a = (FUN_a00f2254(p, 0x78) & 0x7f) << 8 | FUN_a00f2254(p, 0x77);
    FUN_a00df170(fmt, p, (FUN_a00f2254(p, 0x53) & 0x7f) << 8 | FUN_a00f2254(p, 0x52), a);
    FUN_a00f2298(p, 0x52, a);
    FUN_a00f2298(p, 0x53, a >> 8);
}

void FUN_a00f0b58(unsigned char p)
{
    unsigned char *done;
    unsigned short *cnt, *tick;
    unsigned char blk, v;

    if (p == 2) {
        done = &DAT_a802b746;
        cnt = &DAT_a802b744;
        tick = &DAT_a802b74a;
        blk = 2;
    } else if (p == 3) {
        done = &DAT_a802b742;
        cnt = &DAT_a802b740;
        tick = &DAT_a802b748;
        blk = 3;
    } else if (p == 6) {
        done = &DAT_a802b746;
        cnt = &DAT_a802b744;
        tick = &DAT_a802b74a;
        blk = 2;
    } else if (p == 7) {
        done = &DAT_a802b742;
        cnt = &DAT_a802b740;
        tick = &DAT_a802b748;
        blk = 3;
    } else
        return;
    v = FUN_a00f2254(p, 0x8e);
    if (DAT_a802b747 == 0) {
        if (((v & 3) == 0 && *cnt > 0x95) || *cnt > 299) {
            DAT_a802b747 = 1;
            *cnt = 0;
        }
        if ((v & 3) != 0 && *cnt < 300) {
            FUN_a00df170(s_0019a1e0, *cnt, v);
            FUN_a00f0380(p, *cnt, v);
            FUN_a00f2298(p, 0x8e, 3);
            FUN_a0121c6c(p);
        }
        if (p != 6 && p != 7 && (FUN_a00f2254(p, 0x54) & 0x80) == 0)
            copy_7778(p, s_0019a290);
        (*cnt)++;
        return;
    }
    if (((v & 3) == 0 && (FUN_a00f2254(p, 0x88) & 0x20)) || *cnt > 299)
        *done = 1;
    if ((v & 3) != 0 && (FUN_a00f2254(p, 0x88) & 0x20) && *cnt < 300) {
        FUN_a00f232c(p, 0x88, 0x20, 0);
        FUN_a00df170(s_0019a270, *cnt, v);
        if (FUN_a00f0380(p, *cnt, v))
            *cnt = 300;
        if (p != 6 && p != 7 && (FUN_a00f2254(p, 0x54) & 0x80) == 0)
            copy_7778(p, s_0019a2b0);
        FUN_a00f2298(p, 0x8e, 3);
        FUN_a0121c6c(p);
        *tick = func_0x4008d588();
        (*cnt)++;
    }
    if (FUN_a00f2254(p, 0x88) & 0x20)
        return;
    FUN_a00df170(s_0019a200, blk, MREG(BLK(blk), 0) & 0xff);
    FUN_a00df170(s_0019a220, MREG(BLK(blk), 0xb) & 0xff, MREG(BLK(blk), 0xc) & 0xff, MREG(BLK(blk), 0xd) & 0xff,
                 MREG(BLK(blk), 0xe) & 0xff, MREG(BLK(blk), 0xf) & 0xff);
    if ((MREG(BLK(blk), 0) & 0xa0) != 0xa0)
        return;
    FUN_a00df170(s_0019a240, p, func_0x4008d594(*tick));
    if (func_0x4008d594(*tick) <= 0x32)
        return;
    FUN_a0121c6c(p);
    func_0x4008d1a0(5);
    FUN_a00f232c(p, 0x88, 0x20, 1);
    FUN_a00df170(s_0019a260);
    FUN_a00f2298(p, 0x8e, 3);
}
