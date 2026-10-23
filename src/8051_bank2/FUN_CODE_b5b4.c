/* 8051_bank2 FUN_CODE_b5b4 @ 0xb5b4 (338 B), OPTIMIZE(8,SPEED) LARGE (no RET after the endless loop); locals i 0x08E2,
 * c 0x08E3, d 0x08E4. Entered by LJMP from the Keil start-up code FUN_CODE_d426 (0xd432): the bank's main function.
 * Set-up: P1 = 0xE0, XDATA 0xF101 bit 7 cleared, EA = 0, SCON = 0x52, TMOD = 0x21, PCON = 0x80, TH1 = 0xF3, TR1 = 1,
 * XDATA 0xF1E0 bit 7 set. 16 rounds of FUN_CODE_e44b(0x32), each passing a new non-equal value of XDATA 0xF198 to
 * FUN_CODE_a36c and clearing 0xF198. Then 0xCD0A / 0xCD2A = 0x80, e44b(10), both 0, e44b(20), 0xF101 |= 0x30,
 * e44b(10), 0xF101 &= 0xCF, 0xF101 |= 0x40, printf "Start to loop..\r\n" (CODE 0xC28C).
 * Loop: a non-zero 0xF198 goes to FUN_CODE_a36c and is cleared. When the mode byte 0x09C6 differs from its copy
 * 0x09CD: mode 0 -> 0xF190 / 0xF192 = 0x09CE / 0x09CF, a6fa(0), b706(), a6fa(1), b706(), printf "Host Mode Init";
 * mode 1 -> a6fa(0), 60b9(), a6fa(1), 60b9(), printf "Device Mode Init"; then 0x09CD = 0x09C6. Otherwise, mode
 * 0xFF does nothing, mode 0 calls FUN_CODE_6e16(0) / (1) when 0xF191 / 0xF193 is not 0x21, mode 1 calls a6fa(0),
 * 5c20(), a6fa(1), 5c20().
 * volatile: 0xF198 is read twice for one value (test, then copy) and 0xF101 is read again right after a store; the
 * code shows both re-reads. Source forms the bytes depend on: d is set and never read ('c = 0; d = 0;' gives the
 * INC DPTR store pair); the copy is compared first ('0x09CD != 0x09C6' loads 0x09C6 into R7). No aids.
 */
#include <reg51.h>
extern volatile unsigned char xdata DAT_EXTMEM_f101;
extern unsigned char xdata DAT_EXTMEM_f1e0;
extern volatile unsigned char xdata DAT_EXTMEM_f198;
extern unsigned char xdata DAT_EXTMEM_f190;
extern unsigned char xdata DAT_EXTMEM_f191;
extern unsigned char xdata DAT_EXTMEM_f192;
extern unsigned char xdata DAT_EXTMEM_f193;
extern unsigned char xdata DAT_EXTMEM_cd0a;
extern unsigned char xdata DAT_EXTMEM_cd2a;
extern unsigned char xdata DAT_EXTMEM_09c6;
extern unsigned char xdata DAT_EXTMEM_09cd[3];
extern void FUN_CODE_65ab(void *fmt, ...) large;
void FUN_CODE_e44b(unsigned char n);
void FUN_CODE_a36c(unsigned char cmd);
void FUN_CODE_a6fa(unsigned char n);
void FUN_CODE_b706(void);
void FUN_CODE_60b9(void);
void FUN_CODE_5c20(void);
void FUN_CODE_6e16(unsigned char n);
void FUN_CODE_b5b4(void)
{
    unsigned char i;
    unsigned char c;
    unsigned char d;
    c = 0;
    d = 0;
    P1 = 0xe0;
    DAT_EXTMEM_f101 &= 0x7f;
    EA = 0;
    SCON = 0x52;
    TMOD = 0x21;
    PCON = 0x80;
    TH1 = 0xf3;
    TR1 = 1;
    DAT_EXTMEM_f1e0 |= 0x80;
    for (i = 0; i < 0x10; i++) {
        FUN_CODE_e44b(0x32);
        if (DAT_EXTMEM_f198 != c) {
            c = DAT_EXTMEM_f198;
            FUN_CODE_a36c(c);
            DAT_EXTMEM_f198 = 0;
        }
    }
    DAT_EXTMEM_cd0a = 0x80;
    DAT_EXTMEM_cd2a = 0x80;
    FUN_CODE_e44b(10);
    DAT_EXTMEM_cd0a = 0;
    DAT_EXTMEM_cd2a = 0;
    FUN_CODE_e44b(0x14);
    DAT_EXTMEM_f101 |= 0x30;
    FUN_CODE_e44b(10);
    DAT_EXTMEM_f101 &= 0xcf;
    DAT_EXTMEM_f101 |= 0x40;
    FUN_CODE_65ab((void code *)0xc28c);
    for (;;) {
        if (DAT_EXTMEM_f198 != 0) {
            c = DAT_EXTMEM_f198;
            FUN_CODE_a36c(c);
            DAT_EXTMEM_f198 = 0;
        }
        if (DAT_EXTMEM_09cd[0] != DAT_EXTMEM_09c6) {
            if (DAT_EXTMEM_09c6 == 0) {
                DAT_EXTMEM_f190 = DAT_EXTMEM_09cd[1];
                DAT_EXTMEM_f192 = DAT_EXTMEM_09cd[2];
                FUN_CODE_a6fa(0);
                FUN_CODE_b706();
                FUN_CODE_a6fa(1);
                FUN_CODE_b706();
                FUN_CODE_65ab((void code *)0xc29e);
            } else if (DAT_EXTMEM_09c6 == 1) {
                FUN_CODE_a6fa(0);
                FUN_CODE_60b9();
                FUN_CODE_a6fa(1);
                FUN_CODE_60b9();
                FUN_CODE_65ab((void code *)0xc2af);
            }
            DAT_EXTMEM_09cd[0] = DAT_EXTMEM_09c6;
        } else if (DAT_EXTMEM_09c6 != 0xff) {
            if (DAT_EXTMEM_09c6 == 0) {
                if (DAT_EXTMEM_f191 != 0x21) FUN_CODE_6e16(0);
                if (DAT_EXTMEM_f193 != 0x21) FUN_CODE_6e16(1);
            } else if (DAT_EXTMEM_09c6 == 1) {
                FUN_CODE_a6fa(0);
                FUN_CODE_5c20();
                FUN_CODE_a6fa(1);
                FUN_CODE_5c20();
            }
        }
    }
}
