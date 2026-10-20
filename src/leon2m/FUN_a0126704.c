/* leon2m FUN_a0126704 @ 0xa0126704  OLED set Frame rate control (hand; byte-exact at
 * -mcpu=v8 -O3 -g -msoft-float)
 *
 * Tells the panel-side OLED FRC chip (I2C device 0x60, 16-bit register addresses) which frame-rate mode to run:
 * writes the two bytes {0, val} to its register 0x00B2 (FUN_a0147aa0: I2C register write, bit delay 5, bus 0),
 * waits (func_0x4008d1a0(0x32) = FUN_a002d1a0), reads the register back into DAT_a802d888 (FUN_a0147ae8) and
 * prints "OLED set/Get Frame rate control"; while the read-back differs and the retry counter at 0xA802C9FD is at
 * most 9 it prints "...->retry", writes, waits, reads again and counts. Nothing happens unless the FRC ready pin
 * (FUN_a01248c8 = GPIO group 9 bit 3) is high.
 * val is the panel parameter row index (0 = 240 Hz row, 1 = 120 Hz row, 2 = 60 Hz row, the byte at 0xA802D893):
 * the OLED FRC handler FUN_a01295e4 passes it in its state 2; the OLED power state machine FUN_a0127c78 passes 0.
 * FUN_a0126878 reads the same register (printed by FUN_a00dac38 as SYSAPI_GetPanelParamStruct).
 * FW.012 never selected row 2, so it never sent 2 here; FW.021 sends 2 for inputs below 62.0 Hz.
 */
extern unsigned char DAT_a802d890[2], DAT_a802d888[2], DAT_a802c9fd;
extern unsigned char FUN_a01248c8(void);
extern unsigned short FUN_a0147aa0();
extern unsigned short FUN_a0147ae8();
extern int func_0x4008d1a0();
extern int FUN_a00df170();
extern char s_001a44a0[], s_001a44d0[], s_001a4500[];
void FUN_a0126704(unsigned char val)
{
    DAT_a802d890[1] = val;
    DAT_a802d890[0] = 0;
    if (!FUN_a01248c8()) return;
    FUN_a00df170(s_001a44a0, val);
    FUN_a0147aa0(0x60, 2, 0xb2, 5, 0, DAT_a802d890, 2, 1);
    func_0x4008d1a0(0x32);
    FUN_a0147ae8(0x60, 2, 0xb2, 5, 0, DAT_a802d888, 2);
    FUN_a00df170(s_001a44d0, DAT_a802d888[0], DAT_a802d888[1]);
    func_0x4008d1a0(0x32);
    while ((DAT_a802d890[1] != DAT_a802d888[1] || DAT_a802d890[0] != DAT_a802d888[0]) && DAT_a802c9fd <= 9) {
        FUN_a00df170(s_001a4500, DAT_a802d890[0], DAT_a802d890[1], DAT_a802d888[0], DAT_a802d888[1]);
        FUN_a0147aa0(0x60, 2, 0xb2, 5, 0, DAT_a802d890, 2, 1);
        func_0x4008d1a0(0x32);
        FUN_a0147ae8(0x60, 2, 0xb2, 5, 0, DAT_a802d888, 2);
        DAT_a802c9fd++;
    }
}
