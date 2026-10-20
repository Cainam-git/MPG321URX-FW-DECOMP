/* 8051_bank0 FUN_CODE_1873 @ 0x1873  STBC boot loader: short busy-wait delay (byte-exact with
 * OPTIMIZE(7,SPEED)).
 * Spins n times (n in R7) over eight NOP instructions; no side effects. Callers: FUN_CODE_16db (0x1727),
 * FUN_CODE_172d (0x176c) and FUN_CODE_17af (0x17dc).
 */
#include <intrins.h>

void FUN_CODE_1873(unsigned char n)
{
    unsigned char i;
    for (i = 0; i < n; i++) {
        _nop_(); _nop_(); _nop_(); _nop_(); _nop_(); _nop_(); _nop_(); _nop_();
    }
}
