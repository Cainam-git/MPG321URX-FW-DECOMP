/*
 * FUN_a00a4880 (leon2s, 0xa00a4880-0xa00a4e68, 1512 bytes), flags -mcpu=v8 -Os -g.
 * Per-port state machine on the 8-byte records ARR_a807dc10[port] (word 0 = state 0..4, byte 4 = retry
 * counter, byte 5 = flag). DAT_a8078748 == 1 forces state 0 first. Every step passes the byte DAT_a8079228
 * (re-read for each call) to FUN_a00a6190 / FUN_a00a61d4 / FUN_a00a621c; DAT_a807dc04[port] holds the
 * pointers a (register words +0xb4, +0xc0) and b.
 * 0: FUN_a00a6190 nonzero: unless FUN_a00a621c is nonzero, state 1 and DAT_a8078748 = 0. Else FUN_a00a61d4
 *    nonzero: for DAT_a8079228 0x71 / 0x81 FUN_a00afeb8(0 / 1, 1) and DAT_a8079230 = 1; DAT_a807922c =
 *    FUN_a00b2064(); state 4; DAT_a8078748 = 0. Otherwise state 0.
 * 1: FUN_a00a6190 nonzero: FUN_a00a621c == 1 sets state 0; then if *b == 0 and FUN_a00a60ac(port) == 0:
 *    state 1; else FUN_a00a60d8(port), DAT_a8079288[port] = FUN_a00a6110(port), DAT_a8079234[port] =
 *    FUN_a00b2064(), FUN_a00a63a8(80-byte record DAT_a8079238[port], DAT_a8079228), state 2.
 * 2: FUN_a00a6190 == 1 and FUN_a00a621c != 1, and FUN_a00b2064() - DAT_a8079234[port] > 40:
 *    VBP_tmp(port, DAT_a8079238[port], 0), bit 0 of register 0xcf02dc10 set, FUN_a00b160c(100), bit 0
 *    cleared, counter = 3, bit 1 of a[+0xb4] set, state 3.
 * 3: same test; counter nonzero: decrement, and when bit 2 of a[+0xb4] is clear FUN_a00a5d8c(port,
 *    0x90-byte record DAT_a807dbb4[port]) and state 4; counter zero: state 0 and FUN_a0073044("Port%c ChkSum
 *    Check Timeout\n", 'A' + port).
 * 4: FUN_a00a61d4 == 1: after more than 20 ticks of FUN_a00b2064 since DAT_a807922c, DAT_a8079230 == 1
 *    clears it and calls FUN_a00aec10, else FUN_a00aec2c nonzero calls FUN_a00afeb8(0 / 1, 0) for 0x71 /
 *    0x81. Then bit 12 of a[+0xc0] is set when FUN_a00aea64(0 / 1) (for 0x71 / 0x81) == 1 and the bit is
 *    clear, and cleared when it returns 0 and the bit is set. FUN_a00a61d4 != 1: a set bit 12 is cleared.
 *    Finally FUN_a00a47e0(port) == 1 clears the state and byte 5. Other states: no action.
 * Failed tests in steps 1-3 set state 0.
 * Source forms: the bit-12 clears go through the volatile local mask (the firmware stores 0x1000 to its
 * stack slot and reads it back before each clear; this also keeps the last call a normal call). The
 * register pointer has type volatile unsigned long (its alias set lets the state store sit between the
 * +0xb4 read and write). The bit-12 test is (unsigned char)(w >> 12) & 1 (srl + btst 1). Steps 2 and 3 are
 * if / else-if chains with one state-0 arm per failed test. FUN_a00a621c and FUN_a00a47e0 are declared
 * with unsigned char results (the firmware masks both results).
 */
struct st8 { unsigned int state; unsigned char cnt; unsigned char b5; unsigned char pad[2]; };
struct rec12 { volatile unsigned long *a; volatile unsigned int *b; unsigned int c; };
extern struct st8 ARR_a807dc10[];
extern struct rec12 DAT_a807dc04[];
extern unsigned char DAT_a8078748;
extern unsigned char DAT_a8079228;
extern unsigned int DAT_a807922c;
extern unsigned int DAT_a8079230;
extern unsigned int DAT_a8079234[];
extern unsigned char DAT_a8079238[][0x50];
extern unsigned char DAT_a8079288[];
extern unsigned char DAT_a807dbb4[][0x90];
#define REG_cf02dc10 (*(volatile unsigned int *)0xcf02dc10)

extern unsigned char FUN_a00a6190(unsigned char);
extern unsigned char FUN_a00a61d4(unsigned char);
extern unsigned char FUN_a00a621c(unsigned char);
extern unsigned int FUN_a00afeb8(unsigned int, unsigned int);
extern unsigned int FUN_a00b2064(void);
extern unsigned int FUN_a00a60ac(unsigned char);
extern void FUN_a00a60d8(unsigned char);
extern unsigned char FUN_a00a6110(unsigned char);
extern void FUN_a00a63a8(unsigned short *, unsigned int);
extern void VBP_tmp(unsigned char, unsigned char *, unsigned int);
extern void FUN_a00b160c(unsigned int);
extern void FUN_a00a5d8c(unsigned char, unsigned char *);
extern void FUN_a00aec10(void);
extern unsigned char FUN_a00aec2c(void);
extern unsigned char FUN_a00aea64(unsigned char);
extern unsigned char FUN_a00a47e0(unsigned char);
extern int FUN_a0073044(const char *, ...);

void FUN_a00a4880(unsigned char port)
{
    volatile unsigned int mask;

    if (DAT_a8078748 == 1)
        ARR_a807dc10[port].state = 0;
    switch (ARR_a807dc10[port].state) {
    case 0:
        if (FUN_a00a6190(DAT_a8079228) != 0) {
            if (FUN_a00a621c(DAT_a8079228) != 0)
                break;
            ARR_a807dc10[port].state = 1;
        } else if (FUN_a00a61d4(DAT_a8079228) != 0) {
            if (DAT_a8079228 == 0x71) {
                FUN_a00afeb8(0, 1);
                DAT_a8079230 = 1;
            } else if (DAT_a8079228 == 0x81) {
                FUN_a00afeb8(1, 1);
                DAT_a8079230 = 1;
            }
            DAT_a807922c = FUN_a00b2064();
            ARR_a807dc10[port].state = 4;
        } else {
            ARR_a807dc10[port].state = 0;
            break;
        }
        DAT_a8078748 = 0;
        break;
    case 1:
        if (FUN_a00a6190(DAT_a8079228) != 0) {
            if (FUN_a00a621c(DAT_a8079228) == 1)
                ARR_a807dc10[port].state = 0;
            if (*DAT_a807dc04[port].b == 0 && FUN_a00a60ac(port) == 0) {
                ARR_a807dc10[port].state = 1;
            } else {
                FUN_a00a60d8(port);
                DAT_a8079288[port] = FUN_a00a6110(port);
                DAT_a8079234[port] = FUN_a00b2064();
                FUN_a00a63a8((unsigned short *)DAT_a8079238[port], DAT_a8079228);
                ARR_a807dc10[port].state = 2;
            }
        } else
            ARR_a807dc10[port].state = 0;
        break;
    case 2:
        if (FUN_a00a6190(DAT_a8079228) != 1)
            ARR_a807dc10[port].state = 0;
        else if (FUN_a00a621c(DAT_a8079228) == 1)
            ARR_a807dc10[port].state = 0;
        else if (FUN_a00b2064() - DAT_a8079234[port] > 40) {
            VBP_tmp(port, DAT_a8079238[port], 0);
            REG_cf02dc10 |= 1;
            FUN_a00b160c(100);
            REG_cf02dc10 &= ~1;
            ARR_a807dc10[port].cnt = 3;
            DAT_a807dc04[port].a[0xb4 / 4] |= 2;
            ARR_a807dc10[port].state = 3;
        }
        break;
    case 3:
        if (FUN_a00a6190(DAT_a8079228) != 1)
            ARR_a807dc10[port].state = 0;
        else if (FUN_a00a621c(DAT_a8079228) == 1)
            ARR_a807dc10[port].state = 0;
        else if (ARR_a807dc10[port].cnt != 0) {
            ARR_a807dc10[port].cnt--;
            if (!(DAT_a807dc04[port].a[0xb4 / 4] & 4)) {
                FUN_a00a5d8c(port, DAT_a807dbb4[port]);
                ARR_a807dc10[port].state = 4;
            }
        } else {
            ARR_a807dc10[port].state = 0;
            FUN_a0073044("Port%c ChkSum Check Timeout\n", (char)(port + 0x41));
        }
        break;
    case 4:
        if (FUN_a00a61d4(DAT_a8079228) == 1) {
            if (FUN_a00b2064() - DAT_a807922c > 20) {
                if (DAT_a8079230 == 1) {
                    DAT_a8079230 = 0;
                    FUN_a00aec10();
                } else if (FUN_a00aec2c() != 0) {
                    if (DAT_a8079228 == 0x71)
                        FUN_a00afeb8(0, 0);
                    else if (DAT_a8079228 == 0x81)
                        FUN_a00afeb8(1, 0);
                }
            }
            if (!((unsigned char)(DAT_a807dc04[port].a[0xc0 / 4] >> 12) & 1)) {
                if (DAT_a8079228 == 0x71 && FUN_a00aea64(0) == 1)
                    DAT_a807dc04[port].a[0xc0 / 4] |= 0x1000;
                else if (DAT_a8079228 == 0x81 && FUN_a00aea64(1) == 1)
                    DAT_a807dc04[port].a[0xc0 / 4] |= 0x1000;
            } else {
                if (DAT_a8079228 == 0x71 && FUN_a00aea64(0) == 0) {
                    mask = 0x1000;
                    DAT_a807dc04[port].a[0xc0 / 4] &= ~mask;
                } else if (DAT_a8079228 == 0x81 && FUN_a00aea64(1) == 0) {
                    mask = 0x1000;
                    DAT_a807dc04[port].a[0xc0 / 4] &= ~mask;
                }
            }
        } else {
            if ((unsigned char)(DAT_a807dc04[port].a[0xc0 / 4] >> 12) & 1) {
                mask = 0x1000;
                DAT_a807dc04[port].a[0xc0 / 4] &= ~mask;
            }
        }
        if (FUN_a00a47e0(port) == 1) {
            ARR_a807dc10[port].b5 = 0;
            ARR_a807dc10[port].state = 0;
        }
        break;
    }
}
