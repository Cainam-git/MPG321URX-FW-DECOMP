/* 8051_bank1 FUN_CODE_942e @ 0x942e..0x9522 (244 bytes), OPTIMIZE(8,SPEED) LARGE.
 * FUN_CODE_942e(ch): a fixed sequence of FUN_CODE_d884(ch, reg, value) and FUN_CODE_c73e(ch, idx, mask, 1) calls,
 * same scheme as FUN_CODE_45aa: (0xC6, 0x14), (0xC7, 0x1E), (0xC8, 0x84); (0xC9, 0x81) when FUN_CODE_d737(ch, 0xC7)
 * returns 0x1E, else (0xC9, 0x03); c73e(0xD0, 0x04); (0xD3, 0). Four constant byte locals a = 0, b = c = d = 1 select
 * the groups a: (0xCB, 1), (0xCD, 0x80); b: c73e(0xCD, 0x40); c: (0xD6, 0xF0), (0xD8, 0x10), (0xD9, 0x10);
 * d: (0xDA, 1). Then (0xDB, 0) and (0xDC, 0x31) as a tail jump.
 * LARGE slots: ch 0xA4B4 (read back before every call), a..d 0xA4B5..0xA4B8.
 * Callers: FUN_CODE_8a51 (0x8B3B, 0x8B45).
 */
void FUN_CODE_d884(unsigned char ch, unsigned char reg, unsigned char v);
void FUN_CODE_c73e(unsigned char bank, unsigned char idx, unsigned char mask, unsigned char set);
unsigned char FUN_CODE_d737(unsigned char sel, unsigned char idx);

void FUN_CODE_942e(unsigned char ch)
{
    unsigned char a, b, c, d;

    a = 0;
    b = 1;
    c = 1;
    d = 1;
    FUN_CODE_d884(ch, 0xc6, 0x14);
    FUN_CODE_d884(ch, 0xc7, 0x1e);
    FUN_CODE_d884(ch, 0xc8, 0x84);
    if (FUN_CODE_d737(ch, 0xc7) == 0x1e) {
        FUN_CODE_d884(ch, 0xc9, 0x81);
    } else {
        FUN_CODE_d884(ch, 0xc9, 0x03);
    }
    FUN_CODE_c73e(ch, 0xd0, 0x04, 1);
    FUN_CODE_d884(ch, 0xd3, 0x00);
    if (a) {
        FUN_CODE_d884(ch, 0xcb, 0x01);
        FUN_CODE_d884(ch, 0xcd, 0x80);
    }
    if (b) {
        FUN_CODE_c73e(ch, 0xcd, 0x40, 1);
    }
    if (c) {
        FUN_CODE_d884(ch, 0xd6, 0xf0);
        FUN_CODE_d884(ch, 0xd8, 0x10);
        FUN_CODE_d884(ch, 0xd9, 0x10);
    }
    if (d) {
        FUN_CODE_d884(ch, 0xda, 0x01);
    }
    FUN_CODE_d884(ch, 0xdb, 0x00);
    FUN_CODE_d884(ch, 0xdc, 0x31);
}
