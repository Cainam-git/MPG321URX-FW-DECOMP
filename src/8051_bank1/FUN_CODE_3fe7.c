/* 8051_bank1 FUN_CODE_3fe7 @ 0x3fe7..0x42f6 (783 bytes)  STBC application main.
 * MATCH: tools/diff8051.py 8051_bank1 FUN_CODE_3fe7 -> 783/783 bytes, 100 %, exact None, at OPTIMIZE(8,SPEED) (also
 * with REGFILE(R.ORC); level 7 gives 787 bytes). Keys: 'm = a46f & 4; if (m)' gives the fw ANL A,#04H / JZ (a plain
 * 'if (a46f & 4)' gives JNB ACC.2); the chip-ID test before the loop is '(d511 == 0x1a) | (d511 == 0x20)' with
 * 0xD511 volatile (Keil evaluates the right operand first: fw R7 = (==0x20), R6 = (==0x1a), ORL); 0xA470 is one
 * 16-bit counter that is also the holder of the two wake-source return values ('if ((i = f()) != 0x0d)').
 * Entered by LJMP from the Keil start-up at 0xA64F (after XDATA 0xA000..0xAFFF and 0xF800..0xFFFF are cleared and
 * the init table CODE 0x708C is applied). Init table record XDATA 0xA770 = 0x02: the run state starts as 2.
 * What the code does (code facts):
 *  - Start-up: EA = 0; chip set-up (c9fb, def4, dcbb, ccc2(1), b06f, db18, d1de); 100 x 2 NOPs; prints
 *    "\r\n------NT68500 MCU Test program -----\n" (CODE 0xCA8D); 0xA771 = 0x6B / 0x3B / 0x0B by 0xF050 bit 2 / bit 5;
 *    0xF00A = 0xF0E0 = 0xF0E2 = 0xAA; XDATA 0xA800..0xAFFF = 0xFF (dd96); wake word 0xA46F = 0xF0DD; 0xF230 = 0;
 *    FUN_CODE_0b0d (share structure, Big/Small chip set-up, RUN Leon2 Main); grace bit BITS_20_0 = 1 and
 *    FUN_CODE_7b5a (restarts both liveness timers); FUN_CODE_c544(1) and, if 0xF0DD had bit 2, c544(2); EA = 1;
 *    afdc, dde5, d095; for chip IDs 0x1A / 0x20: 0xF60B = 0, 0xF60C = 0x80, 0xF60A |= 0x80.
 *  - FUN_CODE_c544(v): reads the 32-bit mailbox word at offset 0xB8 (FUN_CODE_a4e9),
 *    replaces bits 15..8 with v and writes it back (FUN_CODE_b228). The Big chip's start-up WAIT 1 FUN_a0133564
 *    reads exactly this byte (portal 0 +0xB8, (word >> 8) & 0xFF). So the 8051 releases the Big chip's first wait
 *    only here, after its own start-up and right after the liveness timers were restarted.
 *  - Endless loop, every pass: for chip IDs 0x1A / 0x20 FUN_CODE_4ec1; 0xF00A = 0x55 and 0xF0E0 = 0x55; then by
 *    run state XDATA 0xA770:
 *      2 (running): FUN_CODE_9243 (mailbox command from the Big chip -> FUN_CODE_224f), BITS_20_0 = 0,
 *        FUN_CODE_7b5a (three-core liveness check; it never returns once a ring has stalled).
 *      0 (set by Big-chip command 0x16 CMD_SYS_POWERSAVING in FUN_CODE_224f) or 1 (command 0x17 CMD_SYS_POWEROFF):
 *        poll the wake sources (state 0: 42f6, a1fe, ae1d, d2e9 -> 4, a57e -> 5..11 by its code 0..10 (0x0D = none),
 *        9d75 -> 0x13, deb0 -> 3, a085 -> code + 0x0D (0xFF = none); state 1: d2e9 -> 2, 9caa -> 0x0C, deb0 -> 3)
 *        into the wake word 0xA46F. If one fired: for wake 10 / 11 or 0xDCB0 bits 7..6 set, up to 10 rounds of
 *        (feed 0xF00A / 0xF0E0 = 0x55, pulse 0xDCB0 bit 1, wait 100 ticks FUN_CODE_d44e, print "cnt %d %d\r\n")
 *        while 0xDCB0 bits 7..6 stay set; then b881, d75e, prints "Wakeup!!! %BX\r\n" with the wake word,
 *        0xF00A = 0xF0E0 = 0xF0E2 = 0xAA, ce4b (Timer 0 reload from 0xA772/0xA773), c9fb, 0xE135 &= 0x3F for chip
 *        0x20, b06f, d1de, 0xDCF0 = 0x3100 bit 0, 100 x 2 NOPs, FUN_CODE_0b0d again, BITS_20_0 = 1 + 7b5a,
 *        c544(wake word), run state = 2 (the only write of 0xA770 outside 224f: 0x42EA), deb9, BITS_21_7 = 0.
 *    then FUN_CODE_dc3b at the end of every pass.
 * 0xF0E0 writes: 0xAA is written before every long blocking stretch (start-up here and in the boot loader
 *   FUN_CODE_151c, the wake-up re-init here, around command 0x27's c163 call in 224f at 0x273B) and 0x55 once per loop pass and
 *   inside every long wait loop (here the 0xDCB0 rounds, 6c34 flash command loop at 0x6DA8, 0xBF9E wait, and the
 *   deliberate forever-loop at 0x0B6E in 0b0d after "Share Structure version is differnet with Bootloader!!").
 *   No code reads 0xF0E0. The crash path of FUN_CODE_7b5a writes only 0xF00A = 0x55 before 'SJMP $': the last
 *   0xF0E0 value is the loop's 0x55 and it is never written again.
 * volatile only on hardware registers: 0xF0xx / 0xF2xx / 0xF6xx (register block, not in the cleared RAM ranges),
 *   0xD511 (chip ID, never written by bank 1 code), 0xDCB0 (bit-1 pulse, re-read in the loop). The rest is RAM.
 */
#include <intrins.h>
sfr IE = 0xA8;
sbit EA = IE ^ 7;
extern bit BITS_20_0, BITS_21_7;
extern unsigned char volatile xdata DAT_EXTMEM_f00a, DAT_EXTMEM_f0e0, DAT_EXTMEM_f0e2, DAT_EXTMEM_f050, DAT_EXTMEM_f0dd;
extern unsigned char volatile xdata DAT_EXTMEM_f230, DAT_EXTMEM_f60a, DAT_EXTMEM_f60b, DAT_EXTMEM_f60c;
extern unsigned char volatile xdata DAT_EXTMEM_dcb0;
extern unsigned char xdata DAT_EXTMEM_e135, DAT_EXTMEM_3100;
extern unsigned char volatile xdata DAT_EXTMEM_d511;
extern unsigned char xdata DAT_EXTMEM_a770, DAT_EXTMEM_a771, DAT_EXTMEM_dcf0;
extern unsigned char xdata DAT_EXTMEM_a46f, DAT_EXTMEM_a472;
extern unsigned int xdata DAT_EXTMEM_a470;
extern void FUN_CODE_2820(void *fmt, ...) large;
extern void FUN_CODE_c9fb(void);
extern void FUN_CODE_def4(void);
extern void FUN_CODE_dcbb(void);
extern void FUN_CODE_ccc2(unsigned char m);
extern void FUN_CODE_b06f(void);
extern void FUN_CODE_db18(void);
extern void FUN_CODE_d1de(void);
extern void FUN_CODE_dd96(void);
extern void FUN_CODE_0b0d(void);
extern void FUN_CODE_7b5a(void);
extern void FUN_CODE_c544(unsigned char why);
extern void FUN_CODE_afdc(void);
extern unsigned long FUN_CODE_dde5(void);
extern void FUN_CODE_d095(void);
extern void FUN_CODE_4ec1(void);
extern void FUN_CODE_9243(void);
extern void FUN_CODE_42f6(void);
extern void FUN_CODE_a1fe(void);
extern void FUN_CODE_ae1d(void);
extern unsigned char FUN_CODE_d2e9(void);
extern unsigned char FUN_CODE_a57e(void);
extern bit FUN_CODE_9d75(void);
extern bit FUN_CODE_deb0(void);
extern unsigned char FUN_CODE_a085(void);
extern unsigned char FUN_CODE_9caa(void);
extern void FUN_CODE_d44e(unsigned int t);
extern void FUN_CODE_b881(void);
extern void FUN_CODE_d75e(void);
extern void FUN_CODE_ce4b(void);
extern void FUN_CODE_deb9(void);
extern void FUN_CODE_dc3b(void);

void FUN_CODE_3fe7(void)
{
    unsigned char m;

    EA = 0;
    FUN_CODE_c9fb();
    FUN_CODE_def4();
    FUN_CODE_dcbb();
    FUN_CODE_ccc2(1);
    FUN_CODE_b06f();
    FUN_CODE_db18();
    FUN_CODE_d1de();
    DAT_EXTMEM_a470 = 0;
    do {
        _nop_();
        _nop_();
        DAT_EXTMEM_a470++;
    } while (DAT_EXTMEM_a470 != 100);
    FUN_CODE_2820((void code *)0xca8d);
    if (DAT_EXTMEM_f050 & 0x04) DAT_EXTMEM_a771 = 0x6b;
    else if (DAT_EXTMEM_f050 & 0x20) DAT_EXTMEM_a771 = 0x3b;
    else DAT_EXTMEM_a771 = 0x0b;
    DAT_EXTMEM_f00a = 0xaa;
    DAT_EXTMEM_f0e0 = 0xaa;
    DAT_EXTMEM_f0e2 = 0xaa;
    FUN_CODE_dd96();
    DAT_EXTMEM_a46f = DAT_EXTMEM_f0dd;
    DAT_EXTMEM_f230 = 0;
    FUN_CODE_0b0d();
    BITS_20_0 = 1;
    FUN_CODE_7b5a();
    FUN_CODE_c544(1);
    m = DAT_EXTMEM_a46f & 0x04;
    if (m) FUN_CODE_c544(2);
    EA = 1;
    FUN_CODE_afdc();
    FUN_CODE_dde5();
    FUN_CODE_d095();
    if ((DAT_EXTMEM_d511 == 0x1a) | (DAT_EXTMEM_d511 == 0x20)) {
        DAT_EXTMEM_f60b = 0;
        DAT_EXTMEM_f60c = 0x80;
        DAT_EXTMEM_f60a |= 0x80;
    }
    for (;;) {
        if (DAT_EXTMEM_d511 == 0x1a || DAT_EXTMEM_d511 == 0x20) FUN_CODE_4ec1();
        DAT_EXTMEM_f00a = 0x55;
        DAT_EXTMEM_f0e0 = 0x55;
        if (DAT_EXTMEM_a770 == 2) {
            FUN_CODE_9243();
            BITS_20_0 = 0;
            FUN_CODE_7b5a();
        } else {
            DAT_EXTMEM_a46f = 0;
            if (DAT_EXTMEM_a770 == 0) {
                FUN_CODE_42f6();
                FUN_CODE_a1fe();
                FUN_CODE_ae1d();
                if (FUN_CODE_d2e9()) DAT_EXTMEM_a46f = 4;
                if ((DAT_EXTMEM_a470 = FUN_CODE_a57e()) != 0x0d) {
                    switch (DAT_EXTMEM_a470) {
                    case 0: DAT_EXTMEM_a46f = 5; break;
                    case 1: case 2: DAT_EXTMEM_a46f = 6; break;
                    case 3: case 4: DAT_EXTMEM_a46f = 7; break;
                    case 5: DAT_EXTMEM_a46f = 8; break;
                    case 6: DAT_EXTMEM_a46f = 9; break;
                    case 7: case 8: DAT_EXTMEM_a46f = 10; break;
                    case 9: case 10: DAT_EXTMEM_a46f = 11; break;
                    }
                }
                if (FUN_CODE_9d75()) DAT_EXTMEM_a46f = 0x13;
                if (FUN_CODE_deb0()) DAT_EXTMEM_a46f = 3;
                if ((DAT_EXTMEM_a470 = FUN_CODE_a085()) != 0xff) DAT_EXTMEM_a46f = DAT_EXTMEM_a470 + 0x0d;
            } else if (DAT_EXTMEM_a770 == 1) {
                if (FUN_CODE_d2e9()) DAT_EXTMEM_a46f = 2;
                if (FUN_CODE_9caa()) DAT_EXTMEM_a46f = 0x0c;
                if (FUN_CODE_deb0()) DAT_EXTMEM_a46f = 3;
            }
            if (DAT_EXTMEM_a46f != 0) {
                DAT_EXTMEM_a472 = 0;
                if (DAT_EXTMEM_a46f == 10 || DAT_EXTMEM_a46f == 11 || (DAT_EXTMEM_dcb0 & 0xc0)) {
                    do {
                        DAT_EXTMEM_f00a = 0x55;
                        DAT_EXTMEM_f0e0 = 0x55;
                        DAT_EXTMEM_dcb0 |= 0x02;
                        DAT_EXTMEM_dcb0 &= ~0x02;
                        FUN_CODE_d44e(100);
                        DAT_EXTMEM_a472++;
                        FUN_CODE_2820((void code *)0xcab5, (unsigned int)DAT_EXTMEM_a472, (unsigned int)DAT_EXTMEM_dcb0);
                    } while ((DAT_EXTMEM_dcb0 & 0xc0) && DAT_EXTMEM_a472 < 10);
                }
                FUN_CODE_b881();
                FUN_CODE_d75e();
                FUN_CODE_2820((void code *)0xcac1, DAT_EXTMEM_a46f);
                DAT_EXTMEM_f00a = 0xaa;
                DAT_EXTMEM_f0e0 = 0xaa;
                DAT_EXTMEM_f0e2 = 0xaa;
                FUN_CODE_ce4b();
                FUN_CODE_c9fb();
                if (DAT_EXTMEM_d511 == 0x20) DAT_EXTMEM_e135 &= 0x3f;
                FUN_CODE_b06f();
                FUN_CODE_d1de();
                if (DAT_EXTMEM_3100 & 0x01) DAT_EXTMEM_dcf0 = 1;
                else DAT_EXTMEM_dcf0 = 0;
                DAT_EXTMEM_a470 = 0;
                do {
                    _nop_();
                    _nop_();
                    DAT_EXTMEM_a470++;
                } while (DAT_EXTMEM_a470 != 100);
                FUN_CODE_0b0d();
                BITS_20_0 = 1;
                FUN_CODE_7b5a();
                FUN_CODE_c544(DAT_EXTMEM_a46f);
                DAT_EXTMEM_a770 = 2;
                FUN_CODE_deb9();
                BITS_21_7 = 0;
            }
        }
        FUN_CODE_dc3b();
    }
}
