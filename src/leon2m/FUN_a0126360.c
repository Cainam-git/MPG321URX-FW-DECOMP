/* leon2m FUN_a0126360 @ 0xa0126360-0xa01264e8 (98 words).
 * Writes a 16-bit luminance gain to the panel controller (debug strings "OLED set Lum Gain %d,(%02x,%02x)", "OLED
 * Get Lum Gain %x %x", "OLED set Lum->retry (%d %d) (%d %d)"). The value goes big-endian into the 2-byte buffer
 * 0xa802d890. When FUN_a01248c8 returns non-zero (low byte), the buffer is written with FUN_a0147aa0(0x60, 2, 0x5e,
 * 5, 0, buffer, 2, 1), and after a 0x32 delay (func_0x4008d1a0) read back into 0xa802d888 with FUN_a0147ae8(0x60, 2,
 * 0x5e, 5, 0, buffer, 2). While the two buffers differ and the retry counter byte 0xa802c9fd is at most 9, the write
 * and read-back repeat and the counter is incremented. Same code as FUN_a012653c (register 0x1e) with register 0x5e
 * and a 16-bit value.
 */
extern unsigned char DAT_a802d888[2];
extern unsigned char DAT_a802d890[2];
extern unsigned char DAT_a802c9fd;
extern int FUN_a01248c8(void);
extern unsigned short FUN_a0147aa0(unsigned char, unsigned int, unsigned short, unsigned short, unsigned char, unsigned int, unsigned short, unsigned char);
extern unsigned short FUN_a0147ae8(unsigned int, unsigned int, unsigned short, unsigned short, unsigned char, unsigned int, unsigned short);
extern int func_0x4008d1a0(int);
extern int FUN_a00df170(const char *, ...);
extern const char s_001a4390[];
extern const char s_001a43c0[];
extern const char s_001a43e8[];

void FUN_a0126360(unsigned short val)
{
    DAT_a802d890[0] = val >> 8;
    DAT_a802d890[1] = val;
    if (!(FUN_a01248c8() & 0xff)) return;
    FUN_a00df170(s_001a4390, val, DAT_a802d890[0], DAT_a802d890[1]);
    FUN_a0147aa0(0x60, 2, 0x5e, 5, 0, (unsigned int)&DAT_a802d890, 2, 1);
    func_0x4008d1a0(0x32);
    FUN_a0147ae8(0x60, 2, 0x5e, 5, 0, (unsigned int)&DAT_a802d888, 2);
    FUN_a00df170(s_001a43c0, DAT_a802d888[0], DAT_a802d888[1]);
    func_0x4008d1a0(0x32);
    while ((DAT_a802d890[1] != DAT_a802d888[1] || DAT_a802d890[0] != DAT_a802d888[0]) && DAT_a802c9fd <= 9) {
        FUN_a00df170(s_001a43e8, DAT_a802d890[0], DAT_a802d890[1], DAT_a802d888[0], DAT_a802d888[1]);
        FUN_a0147aa0(0x60, 2, 0x5e, 5, 0, (unsigned int)&DAT_a802d890, 2, 1);
        func_0x4008d1a0(0x32);
        FUN_a0147ae8(0x60, 2, 0x5e, 5, 0, (unsigned int)&DAT_a802d888, 2);
        DAT_a802c9fd++;
    }
}
