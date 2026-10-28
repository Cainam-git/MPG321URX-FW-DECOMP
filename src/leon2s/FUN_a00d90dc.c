/* FUN_a00d90dc (leon2s 0xa00d90dc-0xa00d9474, 920 bytes), flags -mcpu=v8 -Os -g. void (void).
 * Called from the type switch of FUN_a00d9698 (type 0x38). 10-byte stack record r (zero-initialised) filled by
 * FUN_a00d73b4(r, 0, 1, 0x38), then FUN_a00d7bf8(). Stack command h (24 bytes, fp-48): bits 24..30 of the first
 * word = 0x38, bit 21 = bit 1 of func_0xa0fb6bb8(0, 0x2a8), bit 20 = bit 3 of func_0xa0fb6bb8(0, 0x32), bit 19 = 1,
 * bits 13..15 = 2, bits 11..12 = 1, bit 8 = 1, byte 3 = r[1]. Two-byte table a: a[0] = 0x80 | bits 21, 20, 19 of
 * the header moved to bits 5, 4, 3; a[1] = 0x49.
 * Register block 0xcf018e00: writes 0x1f to +0x10 and 0x80 to +0x14 and waits for bit 7 of +0x14 to clear; writes
 * 0 to +0x00, 0x14 to +0x24 and 0 to +0x28. Then 20 words to +0x04, for i = 0..19, the low byte of an OR of
 * a[i] (i < 2), r[1] (i == 0), r[i + 2] (i < 7), func_0xa0fb6bb8(0, 0x28c + i) (i < 8),
 * func_0xa0fb6bb8(0, 0x280 + i) (i < 5) and func_0xa0fb6bb8(0, 0x2df - i) (i < 8); 0 for i >= 8.
 * Then writes 0x80 to +0x04 and 1 to +0x14 and waits for bit 0 of +0x14 to clear, writes 0x22 to +0x00 and 0x80
 * to +0x08 and waits for bit 7 of +0x08 to clear, and reads 20 words of +0x04 into bytes 4..23 of h.
 * Ends with FUN_a00d7ca4() and FUN_a00d791c(&h, 2, 1, 0x38, 0x18).
 * Source forms: header bit-fields (big-endian, first field = MSB); a[0] is computed right after the bit-19
 * store (before the bits 8..15 fields); each flag bit goes through an unsigned int v ('v = x & 2; f = v != 0');
 * an if/else-if chain on i (== 0, < 2, < 5, < 7, < 8), each arm with its own OR expression with the stack byte
 * terms first and its own store of 'v & 0xff' (v unsigned int).
 */
struct hdr38 {
    unsigned int b31 : 1;
    unsigned int type : 7;
    unsigned int b23 : 1;
    unsigned int b22 : 1;
    unsigned int b21 : 1;
    unsigned int b20 : 1;
    unsigned int b19 : 1;
    unsigned int f16 : 3;
    unsigned int f13 : 3;
    unsigned int f11 : 2;
    unsigned int b10 : 1;
    unsigned int b9 : 1;
    unsigned int b8 : 1;
    unsigned int lo : 8;
};
union cmd {
    struct hdr38 h;
    unsigned char b[0x18];
};
#define REG_200 (*(volatile unsigned int *)0xcf018e00)
#define REG_204 (*(volatile unsigned int *)0xcf018e04)
#define REG_208 (*(volatile unsigned int *)0xcf018e08)
#define REG_210 (*(volatile unsigned int *)0xcf018e10)
#define REG_214 (*(volatile unsigned int *)0xcf018e14)
#define REG_224 (*(volatile unsigned int *)0xcf018e24)
#define REG_228 (*(volatile unsigned int *)0xcf018e28)
extern void FUN_a00d73b4(void *, int, int, int);
extern void FUN_a00d7bf8(void);
extern void FUN_a00d7ca4(void);
extern unsigned char func_0xa0fb6bb8(unsigned char, unsigned short);
extern void FUN_a00d791c(void *, int, int, int, unsigned short);

void FUN_a00d90dc(void)
{
    unsigned char r[10] = {0};
    union cmd h;
    unsigned char a[2];
    unsigned char i;
    unsigned int v;

    FUN_a00d73b4(r, 0, 1, 0x38);
    FUN_a00d7bf8();
    h.h.type = 0x38;
    v = func_0xa0fb6bb8(0, 0x2a8) & 2;
    h.h.b21 = v != 0;
    v = func_0xa0fb6bb8(0, 0x32) & 8;
    h.h.b20 = v != 0;
    h.h.b19 = 1;
    a[0] = 0x80 | (h.h.b21 << 5) | (h.h.b20 << 4) | (h.h.b19 << 3);
    h.h.f13 = 2;
    h.h.f11 = 1;
    h.h.b8 = 1;
    a[1] = 0x49;
    h.b[3] = r[1];
    REG_210 = 0x1f;
    REG_214 = 0x80;
    while (REG_214 & 0x80)
        ;
    REG_200 = 0;
    REG_224 = 0x14;
    REG_228 = 0;
    for (i = 0; i < 0x14; i++) {
        if (i == 0) {
            v = a[i] | r[i + 2] | r[1] | func_0xa0fb6bb8(0, 0x28c + i) | func_0xa0fb6bb8(0, 0x280 + i) | func_0xa0fb6bb8(0, 0x2df - i); REG_204 = v & 0xff;
        } else if (i < 2) {
            v = a[i] | r[i + 2] | func_0xa0fb6bb8(0, 0x28c + i) | func_0xa0fb6bb8(0, 0x280 + i) | func_0xa0fb6bb8(0, 0x2df - i); REG_204 = v & 0xff;
        } else if (i < 5) {
            v = r[i + 2] | func_0xa0fb6bb8(0, 0x28c + i) | func_0xa0fb6bb8(0, 0x280 + i) | func_0xa0fb6bb8(0, 0x2df - i); REG_204 = v & 0xff;
        } else if (i < 7) {
            v = r[i + 2] | func_0xa0fb6bb8(0, 0x28c + i) | func_0xa0fb6bb8(0, 0x2df - i); REG_204 = v & 0xff;
        } else if (i < 8) {
            v = func_0xa0fb6bb8(0, 0x28c + i) | func_0xa0fb6bb8(0, 0x2df - i); REG_204 = v & 0xff;
        } else {
            REG_204 = 0;
        }
    }
    REG_204 = 0x80;
    REG_214 = 1;
    while (REG_214 & 1)
        ;
    REG_200 = 0x22;
    REG_208 = 0x80;
    while (REG_208 & 0x80)
        ;
    for (i = 0; i < 0x14; i++)
        h.b[4 + i] = REG_204;
    FUN_a00d7ca4();
    FUN_a00d791c(&h, 2, 1, 0x38, 0x18);
}
