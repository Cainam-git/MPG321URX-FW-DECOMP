/* leon2m FUN_a0126f4c @ 0xa0126f4c-0xa0127154 (130 words).
 * Writes the screen saver range to the panel controller (debug strings "OLED set Screen Saver Range %x %x" and
 * "OLED Get Screen Saver Range %x %x"; the retry message is the shared string 0x1a46d0). When bit 15 of word
 * 0xa802d46c (offset 0x1dc of the block at 0xa802d290) is set, the 2-byte buffer 0xa802d890 becomes
 * {(1 - byte 0xa802d470) | ((1 - byte 0xa802d471) << 4), byte 0xa802d46f + 1} (byte 0xa802d46f is the
 * low byte of that word); otherwise it is {0, 0}. When
 * FUN_a01248c8 returns non-zero (low byte), the buffer and the four source fields ("%x %x %x %x") are logged, the
 * buffer is written with FUN_a0147aa0(0x60, 2, 0x60, 5, 0, buffer, 2, 1) and read back into 0xa802d888 after a 0x32
 * delay, and the write is repeated while the two differ and the retry counter byte 0xa802c9fd is at most 9.
 * Same retry code as FUN_a012653c.
 */
struct G290 {
    unsigned char pad0[0x1dc];
    union {
        unsigned int w;         /* 0xa802d46c */
        unsigned char b[4];     /* b[3] = byte 0xa802d46f */
    } u1dc;
    unsigned char b1e0;         /* 0xa802d470 */
    unsigned char b1e1;         /* 0xa802d471 */
};
extern struct G290 DAT_a802d290;
extern unsigned char DAT_a802d888[2];
extern unsigned char DAT_a802d890[2];
extern unsigned char DAT_a802c9fd;
extern int FUN_a01248c8(void);
extern unsigned short FUN_a0147aa0(unsigned char, unsigned int, unsigned short, unsigned short, unsigned char, unsigned int, unsigned short, unsigned char);
extern unsigned short FUN_a0147ae8(unsigned int, unsigned int, unsigned short, unsigned short, unsigned char, unsigned int, unsigned short);
extern int func_0x4008d1a0(int);
extern int FUN_a00df170(const char *, ...);
extern const char s_001a4780[];
extern const char s_001a47b0[];
extern const char s_001a47c0[];
extern const char s_001a46d0[];

void FUN_a0126f4c(void)
{
    if (!(DAT_a802d290.u1dc.w & 0x8000)) {
        DAT_a802d890[1] = 0;
        DAT_a802d890[0] = 0;
    } else {
        DAT_a802d890[0] = (1 - DAT_a802d290.b1e0) | ((1 - DAT_a802d290.b1e1) << 4);
        DAT_a802d890[1] = DAT_a802d290.u1dc.b[3] + 1;
    }
    if (!(FUN_a01248c8() & 0xff)) return;
    FUN_a00df170(s_001a4780, DAT_a802d890[0], DAT_a802d890[1]);
    FUN_a00df170(s_001a47b0, (DAT_a802d290.u1dc.w >> 15) & 1, DAT_a802d290.b1e0, DAT_a802d290.u1dc.b[3], DAT_a802d290.b1e1);
    FUN_a0147aa0(0x60, 2, 0x60, 5, 0, (unsigned int)&DAT_a802d890, 2, 1);
    func_0x4008d1a0(0x32);
    FUN_a0147ae8(0x60, 2, 0x60, 5, 0, (unsigned int)&DAT_a802d888, 2);
    FUN_a00df170(s_001a47c0, DAT_a802d888[0], DAT_a802d888[1]);
    func_0x4008d1a0(0x32);
    while ((DAT_a802d890[1] != DAT_a802d888[1] || DAT_a802d890[0] != DAT_a802d888[0]) && DAT_a802c9fd <= 9) {
        FUN_a00df170(s_001a46d0, DAT_a802d890[0], DAT_a802d890[1], DAT_a802d888[0], DAT_a802d888[1]);
        FUN_a0147aa0(0x60, 2, 0x60, 5, 0, (unsigned int)&DAT_a802d890, 2, 1);
        func_0x4008d1a0(0x32);
        FUN_a0147ae8(0x60, 2, 0x60, 5, 0, (unsigned int)&DAT_a802d888, 2);
        DAT_a802c9fd++;
    }
}
