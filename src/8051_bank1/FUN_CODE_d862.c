/* 8051_bank1 FUN_CODE_d862 @ 0xd862  OPTIMIZE(7,SPEED)
 * The key change is swapping the branch order: the firmware tests `JNZ` (jump if non-zero) to the else path, so the `if (a565 == 0)` case must come first in source. The `else` handles the non-zero case with the subtraction comparison. This matches the target's control flow exactly — the zero test comes first, and the non-zero path (subtraction) is at the end.
 */
extern unsigned char xdata DAT_EXTMEM_a564;
extern unsigned char xdata DAT_EXTMEM_a565;

unsigned char FUN_CODE_d862(void)
{
    unsigned char result = 0;
    unsigned char a565;
    
    a565 = DAT_EXTMEM_a565;
    if (a565 == 0) {
        if (DAT_EXTMEM_a564 == 0x7f) {
            result = 1;
        }
    } else {
        if ((a565 - DAT_EXTMEM_a564) == 1) {
            result = 1;
        }
    }
    return result;
}
