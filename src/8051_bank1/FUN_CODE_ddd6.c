/* 8051_bank1 FUN_CODE_ddd6 @ 0xddd6..0xdde5 (15 bytes), OPTIMIZE(7,SPEED).
 * Delay: n passes of four NOPs (_nop_() intrinsic from intrins.h), counter in R6.
 * No caller: nothing in bank 1 calls, jumps to or stores the address 0xDDD6.
 */
#include <intrins.h>

void FUN_CODE_ddd6(unsigned char n)
{
    unsigned char i;
    for (i = 0; i < n; i++) {
        _nop_();
        _nop_();
        _nop_();
        _nop_();
    }
}
