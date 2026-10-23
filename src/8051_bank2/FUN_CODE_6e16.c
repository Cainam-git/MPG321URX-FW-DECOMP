/* 8051_bank2 FUN_CODE_6e16 @ 0x6e16..0x7262 (callers: 0xb6d3, 0xb6e3). Compiled OPTIMIZE(8,SPEED) LARGE.
 * One step of a state machine per port: port (LARGE parameter 0x08E5) 1 uses state byte 0x09CF, command register
 * 0xF193 and status register 0xF192; any other port uses 0x09CE, 0xF191 and 0xF190. Locals: st (0x08E6), cmd
 * (0x08E7), n (0x08E8), r (0x08E9, 2 bytes, copied with ?C?COPY from the structure FUN_CODE_467e returns).
 * FUN_CODE_a6fa(port); st = state byte, cmd = command register. FUN_CODE_e3f9() == 0: unless st is 0x81 / 0x82,
 * FUN_CODE_b706() and st = 0x82. Otherwise switch (st) (?C?CCASE table at 0x6e6f):
 *   0x81, 0x82: st = 0x83 when FUN_CODE_e3f9() returns 1.
 *   0x83: e4d9(), b706(), r = 467e(); while FUN_CODE_e4c9() is non-zero (at most four rounds): print "Fail to Read
 *         USB", 0xCD0A = 0xCD2A = 0x80, delay 10, both 0, delay 20, 0xF101 |= 0x30, delay 10, 0xF101 &= 0xCF,
 *         0xF101 |= 0x40, e4d9(), b706(), r = 467e(). Then st = 0x8F; r = {8, 0x50}: FUN_CODE_8cdc(), st = 0x96;
 *         r.a = 3: st = 0xA1 / 0xA2 for r.b = 1 / 2; r.a = 9: st = 0x93.
 *   0x96, 0x9B: e4d9(); cmd 0x45: FUN_CODE_1000() != 0 -> st = 0x96, else byte 0x0409 == 0 -> st = 0x9A, else
 *         FUN_CODE_d5c5() and st = 0x9B; cmd 0x46: print "CMD_LOADFILE2DRAM", FUN_CODE_9d97() true -> print
 *         "STATUS_WAIT_FW_UPDATE", st = 0x97, false -> print "CheckSum Fail!", st = 0x9C; cmd 0x47: FUN_CODE_1e55()
 *         == 0 -> d5c5(), st = 0x9B; cmd 0x48: FUN_CODE_a17e(), print "File_SetTargetFilePara!", st = 0x92.
 *   0x97: cmd 0x16 / 0x17: print "CMD_START_ISP_ROMCODE_MODE" / "..._DUALFW", FUN_CODE_a8a3(0x10 / 0x11); false ->
 *         st = 0x9C; true -> while (0xF19A & 0x8F) != 0x8F and st == 0x97: bits 0..2 of 0xF19A = 1..4 set st =
 *         0xC1..0xC4; then FUN_CODE_e21d(0); st still 0x97: (0x17 only: FUN_CODE_d10a()), st = 0x99, ceee(1),
 *         d1bb(0) and an endless loop.
 *   0x91: st = 0x8F, e4d9(); cmd 0x41 -> st = 0xB1, else FUN_CODE_35a9(0) != 0 -> st = 0x92.
 *   0xB1: cmd 0x42 -> st = 0xB2.   0xB2: st = FUN_CODE_35a9(1) ? 0x92 : 0x8F.   0x93: st = ba96() ? 0x92 : 0x93.
 *   0x92: cmd 0x11 / 0x12 / 0x14 / 0x15 -> FUN_CODE_a8a3(1 / 2 / 4 / 8); 0x31 nothing; 0x13 -> FUN_CODE_e432(),
 *         0xF193 = 0xF191 = 0xEE, endless loop; 0x43 -> FUN_CODE_dbd0(); 0x44 -> FUN_CODE_dc24().
 *   0xA1, 0xA2: FUN_CODE_d2fb().
 * Finally the state byte and the status register get st, and the command register is cleared when cmd != 0.
 * Source forms the bytes depend on: 0xF101 and 0xF19A are read through XBYTE (volatile: re-read after each store and
 * in each test), the other registers are plain externs (Keil then clears A before MOV DPTR for the zero stores);
 * identical case / arm tails are written out separately (Keil cross-jumps them); the round limit is 'n++ > 2'.
 */
#include <absacc.h>
struct pair { unsigned char a; unsigned char b; };
extern unsigned char xdata DAT_EXTMEM_09ce;
extern unsigned char xdata DAT_EXTMEM_09cf;
extern unsigned char xdata DAT_EXTMEM_0409;
extern unsigned char xdata DAT_EXTMEM_cd0a, DAT_EXTMEM_cd2a;
extern unsigned char xdata DAT_EXTMEM_f190, DAT_EXTMEM_f191, DAT_EXTMEM_f192, DAT_EXTMEM_f193;
extern void FUN_CODE_65ab(void *fmt, ...) large;
void FUN_CODE_a6fa(unsigned char n);
unsigned char FUN_CODE_e3f9(void);
unsigned char FUN_CODE_e4c9(void);
void FUN_CODE_e4d9(void);
void FUN_CODE_b706(void);
struct pair FUN_CODE_467e(void);
void FUN_CODE_e44b(unsigned char n);
void FUN_CODE_8cdc(void);
unsigned char FUN_CODE_1000(void);
unsigned char FUN_CODE_1e55(void);
bit FUN_CODE_9d97(void);
void FUN_CODE_d5c5(void);
void FUN_CODE_a17e(void);
bit FUN_CODE_a8a3(unsigned char mode);
void FUN_CODE_e21d(unsigned char a);
void FUN_CODE_ceee(unsigned char on);
void FUN_CODE_d1bb(unsigned char m);
void FUN_CODE_d10a(void);
unsigned char FUN_CODE_35a9(unsigned char m);
unsigned char FUN_CODE_ba96(void);
void FUN_CODE_e432(void);
void FUN_CODE_dbd0(void);
void FUN_CODE_dc24(void);
void FUN_CODE_d2fb(void);

void FUN_CODE_6e16(unsigned char port)
{
    unsigned char st;
    unsigned char cmd;
    unsigned char n;
    struct pair r;
    FUN_CODE_a6fa(port);
    if (port == 1) {
        st = DAT_EXTMEM_09cf;
        cmd = DAT_EXTMEM_f193;
    } else {
        st = DAT_EXTMEM_09ce;
        cmd = DAT_EXTMEM_f191;
    }
    if (FUN_CODE_e3f9() == 0) {
        if (st != 0x81 && st != 0x82) {
            FUN_CODE_b706();
            st = 0x82;
        }
    } else switch (st) {
    case 0x81:
        if (FUN_CODE_e3f9() == 1) st = 0x83;
        break;
    case 0x82:
        if (FUN_CODE_e3f9() == 1) st = 0x83;
        break;
    case 0x83:
        FUN_CODE_e4d9();
        FUN_CODE_b706();
        r = FUN_CODE_467e();
        n = 0;
        while (FUN_CODE_e4c9()) {
            FUN_CODE_65ab((void code *)0xc2c2);
            DAT_EXTMEM_cd0a = 0x80;
            DAT_EXTMEM_cd2a = 0x80;
            FUN_CODE_e44b(10);
            DAT_EXTMEM_cd0a = 0;
            DAT_EXTMEM_cd2a = 0;
            FUN_CODE_e44b(20);
            XBYTE[0xF101] |= 0x30;
            FUN_CODE_e44b(10);
            XBYTE[0xF101] &= 0xcf;
            XBYTE[0xF101] |= 0x40;
            FUN_CODE_e4d9();
            FUN_CODE_b706();
            r = FUN_CODE_467e();
            if (n++ > 2) break;
        }
        st = 0x8f;
        if (r.a == 8 && r.b == 0x50) {
            FUN_CODE_8cdc();
            st = 0x96;
        } else if (r.a == 3) {
            if (r.b == 1) st = 0xa1;
            else if (r.b == 2) st = 0xa2;
        } else if (r.a == 9) st = 0x93;
        break;
    case 0x96:
    case 0x9b:
        FUN_CODE_e4d9();
        if (cmd == 0x45) {
            if (FUN_CODE_1000() == 0) {
                if (DAT_EXTMEM_0409 == 0) st = 0x9a;
                else {
                    FUN_CODE_d5c5();
                    st = 0x9b;
                }
            } else st = 0x96;
        } else if (cmd == 0x46) {
            FUN_CODE_65ab((void code *)0xc2d5);
            if (FUN_CODE_9d97()) {
                FUN_CODE_65ab((void code *)0xc2e9);
                st = 0x97;
            } else {
                FUN_CODE_65ab((void code *)0xc301);
                st = 0x9c;
            }
        } else if (cmd == 0x47) {
            if (FUN_CODE_1e55() == 0) {
                FUN_CODE_d5c5();
                st = 0x9b;
            }
        } else if (cmd == 0x48) {
            FUN_CODE_a17e();
            FUN_CODE_65ab((void code *)0xc312);
            st = 0x92;
        }
        break;
    case 0x97:
        if (cmd == 0x16) {
            FUN_CODE_65ab((void code *)0xc32c);
            if (FUN_CODE_a8a3(0x10)) {
                while ((XBYTE[0xF19A] & 0x8f) != 0x8f && st == 0x97) {
                    if (XBYTE[0xF19A] & 7) {
                        if ((XBYTE[0xF19A] & 7) == 1) st = 0xc1;
                        else if ((XBYTE[0xF19A] & 7) == 2) st = 0xc2;
                        else if ((XBYTE[0xF19A] & 7) == 3) st = 0xc3;
                        else if ((XBYTE[0xF19A] & 7) == 4) st = 0xc4;
                    }
                }
                FUN_CODE_e21d(0);
                if (st == 0x97) {
                    st = 0x99;
                    FUN_CODE_ceee(1);
                    FUN_CODE_d1bb(0);
                    for (;;) ;
                }
            } else st = 0x9c;
        } else if (cmd == 0x17) {
            FUN_CODE_65ab((void code *)0xc349);
            if (FUN_CODE_a8a3(0x11)) {
                while ((XBYTE[0xF19A] & 0x8f) != 0x8f && st == 0x97) {
                    if (XBYTE[0xF19A] & 7) {
                        if ((XBYTE[0xF19A] & 7) == 1) st = 0xc1;
                        else if ((XBYTE[0xF19A] & 7) == 2) st = 0xc2;
                        else if ((XBYTE[0xF19A] & 7) == 3) st = 0xc3;
                        else if ((XBYTE[0xF19A] & 7) == 4) st = 0xc4;
                    }
                }
                FUN_CODE_e21d(0);
                if (st == 0x97) {
                    FUN_CODE_d10a();
                    st = 0x99;
                    FUN_CODE_ceee(1);
                    FUN_CODE_d1bb(0);
                    for (;;) ;
                }
            } else st = 0x9c;
        }
        break;
    case 0x91:
        st = 0x8f;
        FUN_CODE_e4d9();
        if (cmd == 0x41) st = 0xb1;
        else if (FUN_CODE_35a9(0)) st = 0x92;
        break;
    case 0xb1:
        if (cmd == 0x42) st = 0xb2;
        break;
    case 0xb2:
        if (FUN_CODE_35a9(1)) st = 0x92;
        else st = 0x8f;
        break;
    case 0x93:
        if (FUN_CODE_ba96()) st = 0x92;
        else st = 0x93;
        break;
    case 0x92:
        if (cmd == 0x11) FUN_CODE_a8a3(1);
        else if (cmd == 0x12) FUN_CODE_a8a3(2);
        else if (cmd == 0x31) ;
        else if (cmd == 0x13) {
            FUN_CODE_e432();
            DAT_EXTMEM_f193 = 0xee;
            DAT_EXTMEM_f191 = 0xee;
            for (;;) ;
        } else if (cmd == 0x14) FUN_CODE_a8a3(4);
        else if (cmd == 0x15) FUN_CODE_a8a3(8);
        else if (cmd == 0x43) FUN_CODE_dbd0();
        else if (cmd == 0x44) FUN_CODE_dc24();
        break;
    case 0xa1:
        FUN_CODE_d2fb();
        break;
    case 0xa2:
        FUN_CODE_d2fb();
        break;
    }
    if (port == 1) {
        DAT_EXTMEM_09cf = st;
        DAT_EXTMEM_f192 = st;
        if (cmd) DAT_EXTMEM_f193 = 0;
    } else {
        DAT_EXTMEM_09ce = st;
        DAT_EXTMEM_f190 = st;
        if (cmd) DAT_EXTMEM_f191 = 0;
    }
}
