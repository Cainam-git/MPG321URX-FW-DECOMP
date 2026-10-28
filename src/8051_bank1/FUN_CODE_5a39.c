/* 8051_bank1 module FUN_CODE_5a39: FUN_CODE_5a39 @ 0x5a39 (461 B), then FUN_CODE_db05 @ 0xdb05 (19 B).
 * Over the six 2-byte entries e of XDATA 0xA5ED (stops at the first hit, found = 1):
 *  - e[0] in 0x10..0x1E: hit when the bit result of FUN_CODE_af47(e[0] - 0x10, 1 << (e[1] & 0x0F)) equals bit 4 of
 *    e[1]; FUN_CODE_2820 with the string at CODE 0x98D2 ("Key%02X : %02X %02X\r\n") and i, e[0], e[1].
 *  - e[0] in 0x30..0x38: k = FUN_CODE_aeb2(e[0] - 0x30); hit when e[1] is 0xFF and k <= 0xF8 (string 0x98E8,
 *    "PWR_DPMS ADC key %BX %BX %BX\r\n"), or when k < e[1] + g and (e[1] < g or k > (unsigned char)(e[1] - g)),
 *    g = XDATA 0xA62E (string 0x9907, "ADC key %BX %BX %BX\r\n").
 *  Each hit then calls FUN_CODE_db05(1, 0), FUN_CODE_db05(e[0], 1) and FUN_CODE_db05(e[1] & 0x0F or k, 2).
 * After the loop: when found and XDATA 0xA629 is set and FUN_CODE_d94a() - (XDATA int 0xA5EB) < 50, found = 0;
 * otherwise 0xA5EB = FUN_CODE_d94a(). Returns found.
 * LARGE locals: i at XDATA 0xA474, e at 0xA475..0xA476, k at 0xA477, found at 0xA478.
 * Options: OPTIMIZE(8,SPEED) LARGE.
 * Source form: the af47 arguments go to locals first (n, c) and the mask is '1 << c'. The comparison is cast to
 * unsigned char. The three '0xA5EB = FUN_CODE_d94a()' arms after the loop are written out each (Keil merges
 * their common code, which gives the firmware's 'JNZ / SJMP' pairs).
  * FUN_CODE_db05(v, i): XDATA 0xF230[i] = v for i < 0x10 (v in R7, i in R5).
 * Common-entry block 0xDAFE (in front of FUN_CODE_db05): 'MOV DPTR,#0A475H; MOVX A,@DPTR; MOV R7,A; MOV R5,#01H',
 * Keil's OPTIMIZE(8) shared set-up of the three 'FUN_CODE_db05(e[0], 1)' calls (e[0] is XDATA 0xA475), which
 * the call sites enter with LCALL 0xDAFE.
 * Source form: FUN_CODE_db05 is defined after FUN_CODE_5a39. Defined first, Keil knows that FUN_CODE_db05 leaves
 * R5 unchanged (it then sets R5 = 1 with 'INC R5') and also moves the preceding 'FUN_CODE_db05(1, 0)' call into
 * the block.
 */

void FUN_CODE_db05(unsigned char v, unsigned char i);
extern unsigned char xdata DAT_EXTMEM_a5ed[6][2];
extern unsigned char xdata DAT_EXTMEM_a62e, DAT_EXTMEM_a629;
extern unsigned int xdata DAT_EXTMEM_a5eb;
extern void FUN_CODE_2820(void *fmt, ...) large;
bit FUN_CODE_af47(unsigned char n, unsigned char mask);
extern unsigned char FUN_CODE_aeb2(unsigned char v);
extern unsigned int FUN_CODE_d94a(void);

unsigned char FUN_CODE_5a39(void)
{
    unsigned char i;
    unsigned char e[2];
    unsigned char k;
    unsigned char found;
    unsigned char n, c;

    found = 0;
    for (i = 0; i < 6; i++) {
        e[0] = DAT_EXTMEM_a5ed[i][0];
        e[1] = DAT_EXTMEM_a5ed[i][1];
        if ((unsigned char)(e[0] + 0xf0) < 0x0f) {
            n = e[0] + 0xf0;
            c = e[1] & 0x0f;
            if ((unsigned char)(FUN_CODE_af47(n, 1 << c) == ((e[1] & 0x10) >> 4))) {
                FUN_CODE_2820((void code *)0x98d2, i, e[0], e[1]);
                FUN_CODE_db05(1, 0);
                FUN_CODE_db05(e[0], 1);
                FUN_CODE_db05(e[1] & 0x0f, 2);
                found = 1;
                break;
            }
        } else if ((unsigned char)(e[0] + 0xd0) < 9) {
            k = FUN_CODE_aeb2(e[0] + 0xd0);
            if (e[1] == 0xff) {
                if (k <= 0xf8) {
                    FUN_CODE_2820((void code *)0x98e8, k, DAT_EXTMEM_a5ed[i][1], DAT_EXTMEM_a62e);
                    FUN_CODE_db05(1, 0);
                    FUN_CODE_db05(e[0], 1);
                    FUN_CODE_db05(k, 2);
                    found = 1;
                    break;
                }
            } else if ((k < e[1] + DAT_EXTMEM_a62e && e[1] < DAT_EXTMEM_a62e) || (k < e[1] + DAT_EXTMEM_a62e && k > (unsigned char)(e[1] - DAT_EXTMEM_a62e))) {
                FUN_CODE_2820((void code *)0x9907, k, e[1], DAT_EXTMEM_a62e);
                FUN_CODE_db05(1, 0);
                FUN_CODE_db05(e[0], 1);
                FUN_CODE_db05(k, 2);
                found = 1;
                break;
            }
        }
    }
    if (found == 0) {
        DAT_EXTMEM_a5eb = FUN_CODE_d94a();
    } else if (DAT_EXTMEM_a629 == 0) {
        DAT_EXTMEM_a5eb = FUN_CODE_d94a();
    } else if (FUN_CODE_d94a() - DAT_EXTMEM_a5eb < 50) {
        found = 0;
    } else {
        DAT_EXTMEM_a5eb = FUN_CODE_d94a();
    }
    return found;
}

extern unsigned char xdata DAT_EXTMEM_f230[];

void FUN_CODE_db05(unsigned char v, unsigned char i)
{
    if (i < 0x10) DAT_EXTMEM_f230[i] = v;
}

