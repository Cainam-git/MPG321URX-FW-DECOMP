/* leon2m FUN_a0126938 @ 0xa0126938  OLED set EL sensing: writes register 0xC2 of the panel-side OLED controller and prints 'OLED set EL sensing %d'.
 * (hand; BYTE-EXACT at -mcpu=v8 -O3 -msoft-float; verified word by word.)
 * Stand-alone copy of a small static helper that FUN_a0127c78 (OLED power / panel state machine) also
 * inlines.
 */
extern unsigned char DAT_a802d890[2];
extern unsigned char FUN_a01248c8(void);
extern unsigned short FUN_a0147aa0();
extern int FUN_a00df170();
extern char s_001a4568[];
void FUN_a0126938(unsigned char v)
{
    DAT_a802d890[0] = 0;
    DAT_a802d890[1] = v;
    if (!FUN_a01248c8()) return;
    FUN_a00df170(s_001a4568, v);
    FUN_a0147aa0(0x60, 2, 0xc2, 5, 0, DAT_a802d890, 2, 1);
}
