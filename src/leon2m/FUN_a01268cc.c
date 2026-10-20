/* leon2m FUN_a01268cc @ 0xa01268cc  OLED set OFF Sensing: writes register 0xC0 of the panel-side OLED controller and prints 'OLED set OFF Sensing %d'.
 * (BYTE-EXACT at -mcpu=v8 -O3 -msoft-float; verified word by word.)
 * Stand-alone copy of a small static function that FUN_a0127c78 (OLED power / panel state machine) also inlines.
 */
extern unsigned char DAT_a802d890[2];
extern unsigned char FUN_a01248c8(void);
extern unsigned short FUN_a0147aa0();
extern int FUN_a00df170();
extern char s_001a4540[];
void FUN_a01268cc(unsigned char v)
{
    DAT_a802d890[0] = 0;
    DAT_a802d890[1] = v;
    if (!FUN_a01248c8()) return;
    FUN_a00df170(s_001a4540, v);
    FUN_a0147aa0(0x60, 2, 0xc0, 5, 0, DAT_a802d890, 2, 1);
}
