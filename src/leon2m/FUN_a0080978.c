/* leon2m FUN_a0080978 @ 0xa0080978  leave the fake-sleep power state (flags -mcpu=v8 -O3 -g)
 *
 * m = FUN_a00fe47c(); only when the 2-bit power-suspend field (bits 13..14 of 0xA802CFF8, a bit-field: the mask
 * form allocates registers differently) is 2 and
 * FUN_a012792c() and FUN_a0127944() are both 0: FUN_a0127898(), clear the field to 0, print "reset ucPowerSuspendStatus",
 * FUN_a01243bc(1), then (settings word +0x1F4 bit 30 set: FUN_a0124b40 + FUN_a0124a68, else FUN_a0124b40 +
 * FUN_a0124ab0), FUN_a01243bc(bit 30), FUN_a00d9978(), FUN_a00da754(settings byte +0xAC), FUN_a0125988();
 * if FUN_a01279c4() == 1 ("fake sleep" active): clear its 7 flags via FUN_a0127938/50/FUN_a01278e4, print
 * "escape fake sleep", FUN_a01279d0/FUN_a01278f0/FUN_a012795c(0), FUN_a008ee6c(0xff, 0),
 * FUN_a00fe44c(m & 0xfedf), FUN_a01268cc(0), FUN_a014512c(0, 1).
 * Called by the APP event generator FUN_a0080c10 (row 1e) when a no-signal event is posted in that power state.
 */
struct Scff4 { unsigned short h000, h002; unsigned short b15 : 1, susp : 2, rest : 13; };
extern struct Scff4 DAT_a802cff4;
struct Set { unsigned char pad[0xac]; unsigned char bac; unsigned char pad2[0x147]; unsigned int w1f4; };
extern struct Set DAT_a802d290;
extern const char s_000fed68[], s_000fed88[];
extern int FUN_a00df170();
extern int FUN_a00fe47c(void);
extern void FUN_a00fe44c(unsigned short);
extern unsigned char FUN_a012792c(void), FUN_a0127944(void), FUN_a01279c4(void);
extern void FUN_a0127898(void);
extern void FUN_a01243bc(unsigned char);
extern void FUN_a0124b40(void), FUN_a0124a68(void), FUN_a0124ab0(void);
extern void FUN_a00d9978(void);
extern void FUN_a00da754(unsigned char);
extern void FUN_a0125988(void);
extern void FUN_a0127938(unsigned char), FUN_a0127950(unsigned char), FUN_a01278e4(unsigned char);
extern void FUN_a01279d0(unsigned char), FUN_a01278f0(unsigned char), FUN_a012795c(unsigned char);
extern void FUN_a008ee6c(int, int);
extern void FUN_a01268cc(int);
extern void FUN_a014512c(int, int);

void FUN_a0080978(void)
{
    unsigned short m = FUN_a00fe47c();

    if (DAT_a802cff4.susp == 2 && !FUN_a012792c() && !FUN_a0127944()) {
        FUN_a0127898();
        DAT_a802cff4.susp = 0;
        FUN_a00df170(s_000fed68);
        FUN_a01243bc(1);
        if (DAT_a802d290.w1f4 & 0x40000000) {
            FUN_a0124b40();
            FUN_a0124a68();
        } else {
            FUN_a0124b40();
            FUN_a0124ab0();
        }
        FUN_a01243bc((DAT_a802d290.w1f4 >> 30) & 1);
        FUN_a00d9978();
        FUN_a00da754(DAT_a802d290.bac);
        FUN_a0125988();
        if (FUN_a01279c4() == 1) {
            FUN_a0127938(0);
            FUN_a0127950(0);
            FUN_a01278e4(0);
            FUN_a00df170(s_000fed88);
            FUN_a01279d0(0);
            FUN_a01278f0(0);
            FUN_a012795c(0);
            FUN_a008ee6c(0xff, 0);
            FUN_a00fe44c(m & 0xfedf);
            FUN_a01268cc(0);
            FUN_a014512c(0, 1);
        }
    }
}
