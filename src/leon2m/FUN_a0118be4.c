/* leon2m FUN_a0118be4 @ 0xa0118be4-0xa0118e04 (136 words), -mcpu=v8 -O3 -g. Called by FUN_a014118c and FUN_a014122c.
 * Stores tab and pairs into words +8 and +0xc of the record DAT_a8027a98. d = 0x20 when bit 2 of
 * FUN_a00f1f9c(0, 0x29) is set, else 0x100. First table, i = 0..14: register 0xcf012fd0 = i << 4, then
 * 0xcf012fd4 / 0xcf012fd8 receive byte pair i of the 30-byte constant table b1 (record word +8 == 0) or the high
 * and low byte of the u16 (12000000 / d) / tab[i] (signed divisions). Second table, i = 0..15: 0xcf012fe0 = i, then
 * 0xcf012fe4 / 0xcf012fe8 receive byte pair i of the 32-byte constant table b2 (record word +8 == 0) or of the bytes
 * at record word +0xc. The record words are read again for each test.
 * Source form: b1 and b2 are initialised const local arrays, each declared with its own counter i in its own
 * block; GCC copies their initialisers (firmware 0x1a2f2f and 0x1a2f4d) to the stack with a memcpy call, and memcpy
 * is declared with the link name FUN_a013c910 (an __asm__ name, no code).
 */
#define R(a) (*(volatile unsigned int *)(a))

struct CfgBits { unsigned int b31 : 1, b30 : 1, b29 : 1, rest : 29; };
struct Cfg { union { unsigned int w; struct CfgBits b; } u0; unsigned int w4; unsigned short *w8; unsigned char *wc; };
extern struct Cfg DAT_a8027a98;
extern void *memcpy(void *dst, const void *src, unsigned int n) __asm__("FUN_a013c910");
extern unsigned char FUN_a00f1f9c(unsigned char blk, unsigned char reg);

void FUN_a0118be4(unsigned short *tab, unsigned char *pairs)
{
    unsigned short d;

    DAT_a8027a98.w8 = tab;
    DAT_a8027a98.wc = pairs;
    {
        unsigned char i;
        const unsigned char b1[30] = {
            0x3a, 0x98, 0x28, 0xda, 0x29, 0x8d, 0x1a, 0xa2, 0x16, 0x89, 0x13, 0x88, 0x11, 0x3b, 0x0f, 0x6b,
            0x0d, 0xf3, 0x0c, 0xbc, 0x0b, 0xb8, 0x0a, 0xd9, 0x0a, 0x1a, 0x09, 0x73, 0x08, 0xe0
        };

        d = 0x20;
        if (!(FUN_a00f1f9c(0, 0x29) & 4))
            d = 0x100;
        if (DAT_a8027a98.w8 == 0) {
            for (i = 0; i < 15; i++) {
                R(0xcf012fd0) = i << 4;
                R(0xcf012fd4) = b1[i * 2];
                R(0xcf012fd8) = b1[i * 2 + 1];
            }
        } else {
            for (i = 0; i < 15; i++) {
                int v = 12000000 / d / DAT_a8027a98.w8[i];
                R(0xcf012fd0) = i << 4;
                R(0xcf012fd4) = (unsigned short)v >> 8;
                R(0xcf012fd8) = v & 0xff;
            }
        }
    }
    {
        unsigned char i;
        const unsigned char b2[32] = {
            0x4a, 0x20, 0x49, 0x24, 0x48, 0x28, 0x47, 0x2c, 0x46, 0x30, 0x45, 0x34, 0x44, 0x38, 0x43, 0x3c,
            0x42, 0x3c, 0x41, 0x3e, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40
        };

        if (DAT_a8027a98.w8 == 0) {
            for (i = 0; i < 16; i++) {
                R(0xcf012fe0) = i;
                R(0xcf012fe4) = b2[i * 2];
                R(0xcf012fe8) = b2[i * 2 + 1];
            }
        } else {
            for (i = 0; i < 16; i++) {
                R(0xcf012fe0) = i;
                R(0xcf012fe4) = DAT_a8027a98.wc[i * 2];
                R(0xcf012fe8) = DAT_a8027a98.wc[i * 2 + 1];
            }
        }
    }
}
