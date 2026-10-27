/* 8051_bank1 FUN_CODE_b881 @ 0xb881 (124 B)
 * Over the six 2-byte entries of XDATA 0xA61D while entry byte 0 is 0x10..0x1F: e = the entry, then
 * FUN_CODE_5f73(e[0] - 0x10, 1 << (e[1] & 0x0F), (e[1] & 0x10) >> 4). r is set to 0xFF and not read again.
 * Same layout as FUN_CODE_a085 (table at 0xA611 there). Called from 0x425F.
 * LARGE locals: i at XDATA 0xA473, r at 0xA474, e at 0xA475..0xA476; n and c in registers (R7, R5).
 * Options: OPTIMIZE(8,SPEED) LARGE.
 * volatile: the firmware reads the entry again after the range test (same in FUN_CODE_a085).
 * Source form: the call arguments go to locals first (n, c), then the value 1 is written to ACC (reg51.h) and the
 * mask is 'ACC << c', so Keil loads A ('MOV A,#01H') before the count ('MOV R0,AR5').
 * Compiler aid: the call sits under 'if (ACC == 1)'. Keil knows A = 1 there and emits no test; inside an if block
 * n and c stay in registers (as a plain call statement in this loop Keil places them in XDATA).
 */
#include <reg51.h>
extern volatile unsigned char xdata DAT_EXTMEM_a61d[6][2];
extern void FUN_CODE_5f73(unsigned char sel, unsigned char mask, unsigned char on);

void FUN_CODE_b881(void)
{
    unsigned char i, r;
    unsigned char e[2];
    unsigned char n, c;

    r = 0xff;
    for (i = 0; i < 6; i++) {
        if ((unsigned char)(DAT_EXTMEM_a61d[i][0] + 0xf0) <= 0x0f) {
            e[0] = DAT_EXTMEM_a61d[i][0];
            e[1] = DAT_EXTMEM_a61d[i][1];
            n = e[0] - 0x10;
            c = e[1] & 0x0f;
            ACC = 1;
            if (ACC == 1) FUN_CODE_5f73(n, ACC << c, (e[1] & 0x10) >> 4);
        } else break;
    }
}
