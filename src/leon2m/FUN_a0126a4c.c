/* leon2m FUN_a0126a4c @ 0xa0126a4c  getTempSensing.
 * Reads register 8 of the OLED controller and scales it by 0.0625 (soft-float).
 * Flags -mcpu=v8 -O3 -msoft-float (without -g; with -g it does not match).
 * Stand-alone copy of a small static helper that FUN_a0127c78 (OLED power / panel state machine) also inlines.
 */
extern unsigned char DAT_a802d888[2];
extern unsigned char FUN_a01248c8(void);
extern unsigned short FUN_a0147ae8();
extern int FUN_a00df170();
extern char s_001a4590[], s_001a45b0[];
unsigned short FUN_a0126a4c(void)
{
    unsigned short raw, t;
    if (FUN_a01248c8())
        FUN_a0147ae8(0x60, 2, 8, 5, 0, DAT_a802d888, 2);
    raw = (DAT_a802d888[0] << 8) | DAT_a802d888[1];
    FUN_a00df170(s_001a4590, raw);
    t = raw * 0.0625;
    FUN_a00df170(s_001a45b0, t);
    return t;
}
