/* 8051_bank1 FUN_CODE_5f73 @ 0x5f73 .. 0x611a (written from the firmware)
 * FUN_CODE_5f73(sel, mask, on): read-modify-write of one XDATA register chosen by sel. For sel = 1..13 the register
 * is 0xF000, F001, F002, F003, F004, F010, F012, F114, F116, F118, F11A, F11C, F11E and its partner register is
 * 0xF005, F006, F007, F008, F009, F011, F013, F115, F117, F119, F11B, F11D, F11F: when bit 0 of on is set the
 * register becomes register | partner | mask, else (register | partner) & ~mask. sel = 14 sets (on) or clears the
 * mask bits of port P3 (SFR 0xB0). Other sel values change nothing. Two Keil switches with 14-entry LJMP tables
 * (0x5F98, 0x6063). Callers 0xA1DF, 0xB8F1. Options: OPTIMIZE(8,SPEED).
 * Source form: 'if ((on = on & 1) == 1)' keeps the masked value in R3 (MOV A,R3 / ANL / MOV R3,A); the case
 * statements 'reg = reg | partner | mask' read the partner first, and Keil cross-jumps the shared tails (0x6042, 0x610D).
 */
sfr P3 = 0xb0;
extern unsigned char xdata DAT_EXTMEM_f000;
extern unsigned char xdata DAT_EXTMEM_f001;
extern unsigned char xdata DAT_EXTMEM_f002;
extern unsigned char xdata DAT_EXTMEM_f003;
extern unsigned char xdata DAT_EXTMEM_f004;
extern unsigned char xdata DAT_EXTMEM_f005;
extern unsigned char xdata DAT_EXTMEM_f006;
extern unsigned char xdata DAT_EXTMEM_f007;
extern unsigned char xdata DAT_EXTMEM_f008;
extern unsigned char xdata DAT_EXTMEM_f009;
extern unsigned char xdata DAT_EXTMEM_f010;
extern unsigned char xdata DAT_EXTMEM_f011;
extern unsigned char xdata DAT_EXTMEM_f012;
extern unsigned char xdata DAT_EXTMEM_f013;
extern unsigned char xdata DAT_EXTMEM_f114;
extern unsigned char xdata DAT_EXTMEM_f115;
extern unsigned char xdata DAT_EXTMEM_f116;
extern unsigned char xdata DAT_EXTMEM_f117;
extern unsigned char xdata DAT_EXTMEM_f118;
extern unsigned char xdata DAT_EXTMEM_f119;
extern unsigned char xdata DAT_EXTMEM_f11a;
extern unsigned char xdata DAT_EXTMEM_f11b;
extern unsigned char xdata DAT_EXTMEM_f11c;
extern unsigned char xdata DAT_EXTMEM_f11d;
extern unsigned char xdata DAT_EXTMEM_f11e;
extern unsigned char xdata DAT_EXTMEM_f11f;

void FUN_CODE_5f73(unsigned char sel, unsigned char mask, unsigned char on)
{
    if ((on = on & 1) == 1) {
        switch (sel) {
        case 1: DAT_EXTMEM_f000 = DAT_EXTMEM_f000 | DAT_EXTMEM_f005 | mask; break;
        case 2: DAT_EXTMEM_f001 = DAT_EXTMEM_f001 | DAT_EXTMEM_f006 | mask; break;
        case 3: DAT_EXTMEM_f002 = DAT_EXTMEM_f002 | DAT_EXTMEM_f007 | mask; break;
        case 4: DAT_EXTMEM_f003 = DAT_EXTMEM_f003 | DAT_EXTMEM_f008 | mask; break;
        case 5: DAT_EXTMEM_f004 = DAT_EXTMEM_f004 | DAT_EXTMEM_f009 | mask; break;
        case 6: DAT_EXTMEM_f010 = DAT_EXTMEM_f010 | DAT_EXTMEM_f011 | mask; break;
        case 7: DAT_EXTMEM_f012 = DAT_EXTMEM_f012 | DAT_EXTMEM_f013 | mask; break;
        case 8: DAT_EXTMEM_f114 = DAT_EXTMEM_f114 | DAT_EXTMEM_f115 | mask; break;
        case 9: DAT_EXTMEM_f116 = DAT_EXTMEM_f116 | DAT_EXTMEM_f117 | mask; break;
        case 10: DAT_EXTMEM_f118 = DAT_EXTMEM_f118 | DAT_EXTMEM_f119 | mask; break;
        case 11: DAT_EXTMEM_f11a = DAT_EXTMEM_f11a | DAT_EXTMEM_f11b | mask; break;
        case 12: DAT_EXTMEM_f11c = DAT_EXTMEM_f11c | DAT_EXTMEM_f11d | mask; break;
        case 13: DAT_EXTMEM_f11e = DAT_EXTMEM_f11e | DAT_EXTMEM_f11f | mask; break;
        case 14: P3 |= mask; break;
        }
    } else {
        switch (sel) {
        case 1: DAT_EXTMEM_f000 = (DAT_EXTMEM_f000 | DAT_EXTMEM_f005) & ~mask; break;
        case 2: DAT_EXTMEM_f001 = (DAT_EXTMEM_f001 | DAT_EXTMEM_f006) & ~mask; break;
        case 3: DAT_EXTMEM_f002 = (DAT_EXTMEM_f002 | DAT_EXTMEM_f007) & ~mask; break;
        case 4: DAT_EXTMEM_f003 = (DAT_EXTMEM_f003 | DAT_EXTMEM_f008) & ~mask; break;
        case 5: DAT_EXTMEM_f004 = (DAT_EXTMEM_f004 | DAT_EXTMEM_f009) & ~mask; break;
        case 6: DAT_EXTMEM_f010 = (DAT_EXTMEM_f010 | DAT_EXTMEM_f011) & ~mask; break;
        case 7: DAT_EXTMEM_f012 = (DAT_EXTMEM_f012 | DAT_EXTMEM_f013) & ~mask; break;
        case 8: DAT_EXTMEM_f114 = (DAT_EXTMEM_f114 | DAT_EXTMEM_f115) & ~mask; break;
        case 9: DAT_EXTMEM_f116 = (DAT_EXTMEM_f116 | DAT_EXTMEM_f117) & ~mask; break;
        case 10: DAT_EXTMEM_f118 = (DAT_EXTMEM_f118 | DAT_EXTMEM_f119) & ~mask; break;
        case 11: DAT_EXTMEM_f11a = (DAT_EXTMEM_f11a | DAT_EXTMEM_f11b) & ~mask; break;
        case 12: DAT_EXTMEM_f11c = (DAT_EXTMEM_f11c | DAT_EXTMEM_f11d) & ~mask; break;
        case 13: DAT_EXTMEM_f11e = (DAT_EXTMEM_f11e | DAT_EXTMEM_f11f) & ~mask; break;
        case 14: P3 &= ~mask; break;
        }
    }
}
