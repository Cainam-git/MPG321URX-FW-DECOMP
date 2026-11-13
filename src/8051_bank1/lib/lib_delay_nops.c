/* lib_delay_nops  (FUN_CODE_ddd6)
 *
 * Wait n passes of four no-operation instructions.
 *   count: passes
 * Note: Not called anywhere.
 * Name basis: derived - _nop_() loop; no caller in the image
 *
 * Matching notes
 * --------------
 * 8051_bank1 FUN_CODE_ddd6 @ 0xddd6..0xdde5 (15 bytes), OPTIMIZE(7,SPEED).
 * The no-operation instructions are the _nop_() intrinsic from intrins.h; the loop counter is in R6.
 */
#include <intrins.h>

/* Busy-wait: count passes of four no-operation instructions each.
 *   count: number of passes
 * Nothing in the bank calls it. */
void lib_delay_nops(unsigned char count)
{
    unsigned char i;
    for (i = 0; i < count; i++) {
        _nop_();
        _nop_();
        _nop_();
        _nop_();
    }
}
