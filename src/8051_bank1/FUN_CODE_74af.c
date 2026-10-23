/* 8051_bank1 FUN_CODE_74af @ 0x74AF..0x760C (349 bytes), OPTIMIZE(8,SPEED) LARGE.
 * FUN_CODE_74af(p): p is a generic byte pointer (LARGE parameter at XDATA 0xA4A9..0xA4AB). Prints
 * "FillTypeCInfo : %02X, %02X, %02X, %02X, %02X\r\n" (CODE 0xB4E0) with p[0], p[1], p[2], p[3], p[9] (each passed
 * as unsigned int), then copies p[0..9] into the structure at XDATA 0xA69C..0xA6A5:
 *   0xA69C bits 1..0 = p[0], bits 3..2 = p[0] >> 2, bits 7..4 = (p[0] >> 4) & 0xF0 (always 0);
 *   0xA69D bit 0 = p[1], bit 1 = p[1] >> 1, bits 3..2 = p[1] >> 2, bits 5..4 = p[1] >> 4, bits 7..6 = p[1] >> 6;
 *   0xA69E..0xA6A4 = p[2..8]; 0xA6A5 bits 1..0 = p[9].
 * The bit groups are Keil bit-fields (allocated from bit 0 up); field names describe positions only.
 * Caller: the tail LJMP at 0x21FE in FUN_CODE_1c3c (record type 11, p = its payload buffer).
 * Source form: the bits 7..4 value '(p[0] >> 4) & 0xF0' gives the firmware's 'SWAP A / ANL A,#00H'.
 */
struct rec_a69c {
    unsigned char f0:2;         /* 0xA69C bits 1..0 */
    unsigned char f1:2;         /*        bits 3..2 */
    unsigned char f2:4;         /*        bits 7..4 */
    unsigned char g0:1;         /* 0xA69D bit 0 */
    unsigned char g1:1;         /*        bit 1 */
    unsigned char g2:2;         /*        bits 3..2 */
    unsigned char g3:2;         /*        bits 5..4 */
    unsigned char g4:2;         /*        bits 7..6 */
    unsigned char b[7];         /* 0xA69E..0xA6A4 */
    unsigned char h0:2;         /* 0xA6A5 bits 1..0 */
};
extern struct rec_a69c xdata DAT_EXTMEM_a69c;
extern void FUN_CODE_2820(void *fmt, ...) large;

void FUN_CODE_74af(unsigned char *p)
{
    FUN_CODE_2820((void code *)0xb4e0, (unsigned int)p[0], (unsigned int)p[1], (unsigned int)p[2],
                  (unsigned int)p[3], (unsigned int)p[9]);   /* "FillTypeCInfo : %02X, ..." */
    DAT_EXTMEM_a69c.f0 = p[0];
    DAT_EXTMEM_a69c.f1 = p[0] >> 2;
    DAT_EXTMEM_a69c.f2 = (p[0] >> 4) & 0xf0;
    DAT_EXTMEM_a69c.g0 = p[1];
    DAT_EXTMEM_a69c.g1 = p[1] >> 1;
    DAT_EXTMEM_a69c.g2 = p[1] >> 2;
    DAT_EXTMEM_a69c.g3 = p[1] >> 4;
    DAT_EXTMEM_a69c.g4 = p[1] >> 6;
    DAT_EXTMEM_a69c.b[0] = p[2];
    DAT_EXTMEM_a69c.b[1] = p[3];
    DAT_EXTMEM_a69c.b[2] = p[4];
    DAT_EXTMEM_a69c.b[3] = p[5];
    DAT_EXTMEM_a69c.b[4] = p[6];
    DAT_EXTMEM_a69c.b[5] = p[7];
    DAT_EXTMEM_a69c.b[6] = p[8];
    DAT_EXTMEM_a69c.h0 = p[9];
}
