/* 8051_bank2 FUN_CODE_5c20 @ 0x5c20  BYTE-EXACT under OPTIMIZE(8,SPEED) LARGE (first C, MATCH exact None
 * 1177/1177).
 * FOTG210 (Faraday USB 2.0 OTG controller) interrupt service, polled from FUN_CODE_b5b4 (LCALL at 0xb6f8, 0xb700).
 * Controller registers are 32-bit, read with FUN_CODE_9b91(reg) and written with FUN_CODE_b317(reg, value) (value
 * is a memory parameter at XDATA 0x0992); register offsets and bit numbers below are code facts, the names in
 * the printf strings are the firmware's own (CODE 0x7DE9..0x7ED9, printf = FUN_CODE_65ab, strings passed as
 * absolute code pointers like FUN_CODE_ce2a):
 *   0x00C0 global status, written back to clear: bit 0 = device, bit 1 "OTG interrupt", bit 2 "HC interrupt".
 *   device: group = [0x140] & ~[0x130] (written back to 0x140):
 *     group bit 0: sub = [0x144] & ~[0x134] (written back): bit 4 "fotg210: cmd error", bit 5 "fotg210: cmd abort",
 *       bit 0 -> FUN_CODE_573b() (control setup handler, not in functions.json, only caller), else bit 3
 *       "command finish" and [0x120] |= 1;
 *     else group bit 1: "bulk ISO interrupt";
 *     else group bit 2: sub = [0x14C] & ~[0x13C] (written back): bit 0 "fotg210: reset by host": [0x104] = 0,
 *       [0x138] |= 0x10000, [0x108] |= 1, [0x1B0 + 4 i] = 0x1000 for i = 0..3, [0x120] &= ~4, [0x100] &= ~1;
 *       else bit 1 "fotg210: suspend/removed": empty 4-pass loop, [0x100] |= 8; else bit 2 "fotg210: resume";
 *       then bit 3 "fotg210: iso error", bit 4 "fotg210: iso abort", bit 8 "fotg210: dma error".
 * (Same overall shape as the Linux fotg210-udc fotg210_irq().)
 * LARGE locals at XDATA 0x08E5 gisr, 0x08E9 grp, 0x08ED sub, 0x08F1 v, 0x08F5 i (declaration order).
 * Tail 'LCALL 65ab; RET': the last 'if' jumps over the call to the RET (JZ 0x60b8), no aid needed. The "bulk
 * ISO interrupt" printf shares the dma-error LCALL (LJMP 0x6081, Keil cross-jump) and the reset / suspend arms
 * share the '[0x100] = v' store tail (SJMP 0x5ff4), both from the plain C below.
 * First draft had '[0x138] |= 0x100' (99.8 %, OR on R6 instead of R5).
 */
unsigned long FUN_CODE_9b91(unsigned int reg);
void FUN_CODE_b317(unsigned int reg, unsigned long v);
void FUN_CODE_573b(void);
extern void FUN_CODE_65ab(void *fmt, ...) large;

void FUN_CODE_5c20(void)
{
    unsigned long gisr;
    unsigned long grp;
    unsigned long sub;
    unsigned long v;
    unsigned char i;
    gisr = FUN_CODE_9b91(0x00c0);
    FUN_CODE_b317(0x00c0, gisr);
    if (gisr & 1) {
        grp = FUN_CODE_9b91(0x0140);
        grp &= ~FUN_CODE_9b91(0x0130);
        FUN_CODE_b317(0x0140, grp);
        if (grp & 1) {
            sub = FUN_CODE_9b91(0x0144);
            sub &= ~FUN_CODE_9b91(0x0134);
            FUN_CODE_b317(0x0144, sub);
            if (sub & 0x10) FUN_CODE_65ab((void code *)0x7de9);
            if (sub & 0x20) FUN_CODE_65ab((void code *)0x7dfe);
            if (sub & 1) {
                FUN_CODE_573b();
            } else if (sub & 8) {
                FUN_CODE_65ab((void code *)0x7e13);
                v = FUN_CODE_9b91(0x0120);
                v |= 1;
                FUN_CODE_b317(0x0120, v);
            }
        } else if (grp & 2) {
            FUN_CODE_65ab((void code *)0x7e24);
        } else if (grp & 4) {
            sub = FUN_CODE_9b91(0x014c);
            sub &= ~FUN_CODE_9b91(0x013c);
            FUN_CODE_b317(0x014c, sub);
            if (sub & 1) {
                FUN_CODE_65ab((void code *)0x7e39);
                FUN_CODE_b317(0x0104, 0);
                v = FUN_CODE_9b91(0x0138);
                v |= 0x10000;
                FUN_CODE_b317(0x0138, v);
                v = FUN_CODE_9b91(0x0108);
                v |= 1;
                FUN_CODE_b317(0x0108, v);
                for (i = 0; i < 4; i++) FUN_CODE_b317(0x01b0 + i * 4, 0x1000);
                v = FUN_CODE_9b91(0x0120);
                v &= ~4;
                FUN_CODE_b317(0x0120, v);
                v = FUN_CODE_9b91(0x0100);
                v &= ~1;
                FUN_CODE_b317(0x0100, v);
            } else if (sub & 2) {
                FUN_CODE_65ab((void code *)0x7e52);
                for (i = 0; i < 4; i++) ;
                v = FUN_CODE_9b91(0x0100);
                v |= 8;
                FUN_CODE_b317(0x0100, v);
            } else if (sub & 4) {
                FUN_CODE_65ab((void code *)0x7e6d);
            }
            if (sub & 8) FUN_CODE_65ab((void code *)0x7e7f);
            if (sub & 0x10) FUN_CODE_65ab((void code *)0x7e94);
            if (sub & 0x100) FUN_CODE_65ab((void code *)0x7ea9);
        }
    }
    if (gisr & 2) FUN_CODE_65ab((void code *)0x7ebe);
    if (gisr & 4) FUN_CODE_65ab((void code *)0x7ece);
}
