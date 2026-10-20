/* leon2m FUN_a01084a8 @ 0xa01084a8  set or clear one bit in three registers (hand; BYTE-EXACT
 * at -mcpu=v8 -O3 -g; callee of the OLED FRC handler FUN_a01295e4, which calls
 * FUN_a01084a8(FUN_a013cda8(0), 0))
 *
 * Prints string 0x19ABE8 with (bit, on). on != 0: 0xCF011800, 0xCF011A00, 0xCF011BF8 |= 1 << bit (in that order);
 * on == 0: 0xCF011BF8, 0xCF011A00, 0xCF011800 &= ~(1 << bit) (reverse order).
 * BYTE-EXACT keys: constant-address register macros in every statement and the mask written inline as (1 << bit)
 *   in each statement (no mask variable): gcc's sched1 hoists the per-arm address computations above the branch,
 *   which gives the firmware's extra register copies; a 'mask' local changes the register choice.
 */
#define R(a) (*(volatile unsigned int *)(a))
extern int FUN_a00df170();
extern char s_0019abe8[];
void FUN_a01084a8(unsigned char bit, unsigned char on)
{
    FUN_a00df170(s_0019abe8, bit, on);
    if (on) {
        R(0xcf011800) |= (1 << bit);
        R(0xcf011a00) |= (1 << bit);
        R(0xcf011bf8) |= (1 << bit);
    } else {
        R(0xcf011bf8) &= ~(1 << bit);
        R(0xcf011a00) &= ~(1 << bit);
        R(0xcf011800) &= ~(1 << bit);
    }
}

