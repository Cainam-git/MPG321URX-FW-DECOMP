/* 8051_bank1 FUN_CODE_c698 @ 0xC698..0xC6EC (84 bytes; unlisted code found in a gap of the function table).
 * Twin of FUN_CODE_be50 with the range 0x42..0xC7: x / y = 1 when byte XDATA 0xA672 / 0xA673 lies in it; the result
 * (local bit) is 1 when exactly one of x, y is set. When both are set it passes the format at CODE 0xB52A
 * ("get two rd : %02bx %02bx\r\n") with both bytes to FUN_CODE_2820. Returns the bit in the carry.
 * No caller in the image. No aids.
 */
extern unsigned char xdata DAT_EXTMEM_a672[2];
extern void FUN_CODE_2820(void *fmt, ...) large;
bit FUN_CODE_c698(void)
{
    bit b;
    unsigned char x, y;
    b = 0;
    x = 0;
    y = 0;
    if (DAT_EXTMEM_a672[0] > 0x41 && DAT_EXTMEM_a672[0] < 0xc8) x = 1;
    if (DAT_EXTMEM_a672[1] > 0x41 && DAT_EXTMEM_a672[1] < 0xc8) y = 1;
    if ((x | y) && x != y) b = 1;
    if ((x | y) && x == y) FUN_CODE_2820((void code *)0xb52a, DAT_EXTMEM_a672[0], DAT_EXTMEM_a672[1]);
    return b;
}
