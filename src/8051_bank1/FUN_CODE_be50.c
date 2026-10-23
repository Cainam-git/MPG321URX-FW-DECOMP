/* 8051_bank1 FUN_CODE_be50 @ 0xBE50..0xBEB5 (101 bytes; unlisted code found in a gap of the function table).
 * Tests the bytes XDATA 0xA672 / 0xA673: x / y = 1 when the byte lies in 0x14..0x9C. The result (local bit) is 1 when
 * exactly one of x, y is set, and 0 when either byte is above 0x9D. When x and y are both set it passes the format at
 * CODE 0xB50F ("get two rp : %02bx %02bx\r\n") with both bytes to FUN_CODE_2820. Returns the bit in the carry.
 * Keil keeps x | y in R5 for both tests (common subexpression). No caller in the image. No aids.
 */
extern unsigned char xdata DAT_EXTMEM_a672[2];
extern void FUN_CODE_2820(void *fmt, ...) large;
bit FUN_CODE_be50(void)
{
    bit b;
    unsigned char x, y;
    b = 0;
    x = 0;
    y = 0;
    if (DAT_EXTMEM_a672[0] > 0x13 && DAT_EXTMEM_a672[0] < 0x9d) x = 1;
    if (DAT_EXTMEM_a672[1] > 0x13 && DAT_EXTMEM_a672[1] < 0x9d) y = 1;
    if ((x | y) && x != y) b = 1;
    if (DAT_EXTMEM_a672[0] > 0x9d || DAT_EXTMEM_a672[1] > 0x9d) b = 0;
    if ((x | y) && x == y) FUN_CODE_2820((void code *)0xb50f, DAT_EXTMEM_a672[0], DAT_EXTMEM_a672[1]);
    return b;
}
