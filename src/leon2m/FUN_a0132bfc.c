/* leon2m FUN_a0132bfc @ 0xa0132bfc-0xa0132c54 (22 words).
 * With a = byte 0xa802cb97 and b = byte 0xa802cb96: d = b - a + 0x24 when a > b, 0x24 when a == b and b - a - 1 when
 * a < b; returns d << 4 cut to 16 bits. A leaf routine without a register window.
 */
extern unsigned char DAT_a802cb96, DAT_a802cb97;

unsigned short FUN_a0132bfc(void)
{
    unsigned char a = DAT_a802cb97, b = DAT_a802cb96;
    unsigned short d = 0x24;

    if (a > b)
        d = b - a + 0x24;
    else if (a < b)
        d = b - a - 1;
    return d << 4;
}
