/* 8051_bank1 FUN_CODE_d511 @ 0xd511
 * Serial character output: retries FUN_CODE_d1a8(c) (16-entry TX ring put, returns non-zero when full) with a
 * 1000-step delay between tries; after more than 0xF0 retries it sets TI (kicks the TX interrupt) on every retry.
 * Then XDATA 0xF00A = 0x55 and it returns c.
 * c / n / j stay in R5 / R4 / R6:R7 only with REGFILE(R.ORC) (without it they go to DATA: 20 %). 'j != 1000' also matches.
 * Callers 0x1f41 (FUN_CODE_1c3c), LJMP at 0x2817 (no functions.json entry).
 * Options: OPTIMIZE(8,SPEED) REGFILE(R.ORC).
 */
#include <reg51.h>
extern unsigned char xdata DAT_EXTMEM_f00a;
unsigned char FUN_CODE_d1a8(unsigned char c);
unsigned char FUN_CODE_d511(unsigned char c)
{
    unsigned char n;
    unsigned int j;
    n = 0;
    while (FUN_CODE_d1a8(c)) {
        for (j = 0; j < 1000; j++) ;
        n++;
        if (n > 0xf0) TI = 1;
    }
    DAT_EXTMEM_f00a = 0x55;
    return c;
}
