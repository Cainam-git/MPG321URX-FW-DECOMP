/* FUN_a008642c (leon2s 0xa008642c-0xa00864d4, 168 bytes), flags -mcpu=v8 -Os -g.
 * Fills a 5-byte stack buffer: byte 0 maps the low byte of param_2 (0, 1, 2, 3) to 0x21, 0x22, 0x23, 7 (other
 * values 0); bytes 1..4 all hold (y << 3) | x, where x and y get bit 2 set when they are above 2. Passes the
 * buffer to FUN_a00863d4(param_1 & 0xff, 0x80, 0x102, param_3 & 0xf, buf) and returns 1 when the result is
 * non-zero. Same layout as FUN_a00864d4. Source form: bytes 2..4 are copied from byte 1.
 */
extern unsigned char FUN_a00863d4(unsigned int, unsigned int, unsigned int, char, unsigned int);

int FUN_a008642c(unsigned int param_1, unsigned int param_2, unsigned int param_3, unsigned char x, unsigned char y)
{
    unsigned char buf[5];
    unsigned char uVar1;

    uVar1 = (unsigned char)param_2;
    if (uVar1 == 0)
        buf[0] = 0x21;
    else if (uVar1 == 1)
        buf[0] = 0x22;
    else if (uVar1 == 2)
        buf[0] = 0x23;
    else if (uVar1 == 3)
        buf[0] = 7;
    else
        buf[0] = 0;
    if (x > 2)
        x |= 4;
    if (y > 2)
        y |= 4;
    buf[1] = (y << 3) | x;
    buf[2] = buf[1];
    buf[3] = buf[1];
    buf[4] = buf[1];
    return FUN_a00863d4((unsigned char)param_1, 0x80, 0x102, param_3 & 0xf, (unsigned int)buf) != 0;
}
