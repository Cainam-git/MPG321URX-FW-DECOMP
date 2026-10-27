/* 8051_bank1 FUN_CODE_d90a @ 0xd90a (32 B)
 * Returns the index 0..7 of the lowest set bit of FUN_CODE_dee2()'s result, 0xFF when no bit is set.
 * Called from FUN_CODE_38a7. Options: OPTIMIZE(7,SPEED) (also level 8).
 * Source form: the byte is written to ACC (reg51.h) and the shift reads ACC, so Keil loads A ('MOV A,R7') before
 * the count ('MOV R0,AR5'); the loop is 'do { } while (++i != 8)', compiled as 'INC R5; MOV A,R5; CJNE A,#08H'.
 */
#include <reg51.h>

extern unsigned char FUN_CODE_dee2(void);

unsigned char FUN_CODE_d90a(void)
{
    unsigned char v, i, r;

    v = FUN_CODE_dee2();
    r = 0xff;
    i = 0;
    do {
        ACC = v;
        if ((ACC >> i) & 1) {
            r = i;
            break;
        }
    } while (++i != 8);
    return r;
}
