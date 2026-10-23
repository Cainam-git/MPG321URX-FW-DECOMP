/* 8051_bank1 FUN_CODE_65e9 @ 0x65E9..0x6781 (408 bytes), OPTIMIZE(8,SPEED) LARGE. Returns a bit (carry).
 * LARGE locals st 0xA493, v 0xA494, p1 0xA495..0xA497, p2 0xA498..0xA49A (generic pointers), t 0xA49B..0xA49C.
 * Picks the first of the XDATA registers 0xF01C, 0xF01E, 0xF085, 0xF087, 0xF099, 0xF0A3, 0xF076 whose bit 0 is
 * set as p1, with p2 = 0xF03A, 0xF042, 0xF08A, 0xF092, 0xF09C, 0xF0B9, 0xF141 respectively; returns 0 when none
 * is set. Then v = *p1 & 0x3C, *p1 = v | 0x81, st = *p2 & 3, t = FUN_CODE_d94a(). While FUN_CODE_d94a() - t
 * stays below 500: XDATA 0xF00A = 0x55; when *p2 & 3 differs from st, st takes the new value and t is reset
 * from FUN_CODE_d94a(); when bit 0 of *p1 is set again, *p1 = v | 0x81 and t is reset. Returns 1 after that.
 * The registers are hardware registers (volatile, read through 'unsigned char volatile *' generic pointers).
 * Source form: '*p1 = (v = *p1 & 0x3C) | 0x81' (one expression) keeps v in A for the store; two statements
 * make Keil re-read v. Caller: LCALL at 0xC108.
 */
extern unsigned char volatile xdata DAT_EXTMEM_f00a;
extern unsigned char volatile xdata DAT_EXTMEM_f01c, DAT_EXTMEM_f01e, DAT_EXTMEM_f085, DAT_EXTMEM_f087;
extern unsigned char volatile xdata DAT_EXTMEM_f099, DAT_EXTMEM_f0a3, DAT_EXTMEM_f076;
extern unsigned int FUN_CODE_d94a(void);

bit FUN_CODE_65e9(void)
{
    unsigned char st, v;
    unsigned char volatile *p1, *p2;
    unsigned int t;
    unsigned char x;

    if (DAT_EXTMEM_f01c & 1) {
        p1 = (unsigned char xdata *)0xf01c;
        p2 = (unsigned char xdata *)0xf03a;
    } else if (DAT_EXTMEM_f01e & 1) {
        p1 = (unsigned char xdata *)0xf01e;
        p2 = (unsigned char xdata *)0xf042;
    } else if (DAT_EXTMEM_f085 & 1) {
        p1 = (unsigned char xdata *)0xf085;
        p2 = (unsigned char xdata *)0xf08a;
    } else if (DAT_EXTMEM_f087 & 1) {
        p1 = (unsigned char xdata *)0xf087;
        p2 = (unsigned char xdata *)0xf092;
    } else if (DAT_EXTMEM_f099 & 1) {
        p1 = (unsigned char xdata *)0xf099;
        p2 = (unsigned char xdata *)0xf09c;
    } else if (DAT_EXTMEM_f0a3 & 1) {
        p1 = (unsigned char xdata *)0xf0a3;
        p2 = (unsigned char xdata *)0xf0b9;
    } else if (DAT_EXTMEM_f076 & 1) {
        p1 = (unsigned char xdata *)0xf076;
        p2 = (unsigned char xdata *)0xf141;
    } else {
        return 0;
    }
    *p1 = (v = *p1 & 0x3c) | 0x81;
    st = *p2 & 3;
    t = FUN_CODE_d94a();
    while (FUN_CODE_d94a() - t < 500) {
        DAT_EXTMEM_f00a = 0x55;
        x = *p2 & 3;
        if (st != x) {
            st = x;
            t = FUN_CODE_d94a();
        }
        if (*p1 & 1) {
            *p1 = v | 0x81;
            t = FUN_CODE_d94a();
        }
    }
    return 1;
}
