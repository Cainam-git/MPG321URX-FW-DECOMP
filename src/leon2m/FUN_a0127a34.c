/* leon2m FUN_a0127a34 @ 0xa0127a34  OFF-sensing time due: FUN_a0145af8(0xd) * 60 + FUN_a0145af8(0xb) > 19, or FUN_a0145af8(0xd) >= 4.
 * (BYTE-EXACT at -mcpu=v8 -O3 -msoft-float; verified word by word.)
 * Stand-alone copy of a small static helper that FUN_a0127c78 (OLED power / panel state machine) also
 * inlines.
 */
extern unsigned short FUN_a0145af8(unsigned int);
unsigned char FUN_a0127a34(void)
{
    unsigned char r;
    if (FUN_a0145af8(0x10) == 0) {
        if (FUN_a0145af8(0xd) >= 4) r = 1; else r = 0;
    } else {
        if (FUN_a0145af8(0xd) * 60 + FUN_a0145af8(0xb) > 19) r = 1; else r = 0;
    }
    return r;
}
