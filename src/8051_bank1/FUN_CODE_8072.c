/* 8051_bank1 FUN_CODE_8072 @ 0x8072..0x81a9 (311 bytes), OPTIMIZE(8,SPEED) LARGE.
 * FUN_CODE_8072(dst, src, n): unpacks (n + 3) / 4 longs from src into bytes at dst, most significant byte first
 * (dst[4i] = bits 31..24 of src[i], ..., dst[4i + 3] = bits 7..0). Both are generic pointers; the longs are read
 * with ?C?LLDOPTR (once per byte), the bytes stored with ?C?CSTOPTR.
 * LARGE slots: dst 0xA4A9, src 0xA4AC, n 0xA4AF, i 0xA4B1, cnt 0xA4B2 (byte counter and limit).
 * Caller: FUN_CODE_1c3c (LCALL at 0x1CCF).
 */
void FUN_CODE_8072(unsigned char *dst, unsigned long *src, unsigned int n)
{
    unsigned char i;
    unsigned char cnt;

    cnt = (n + 3) >> 2;
    for (i = 0; i < cnt; i++) {
        dst[i * 4] = src[i] >> 24;
        dst[i * 4 + 1] = src[i] >> 16;
        dst[i * 4 + 2] = src[i] >> 8;
        dst[i * 4 + 3] = src[i];
    }
}
