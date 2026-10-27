/* 8051_bank1 FUN_CODE_7f36 @ 0x7f36..0x8072 (316 B)  Byte-exact with OPTIMIZE(8,SPEED) LARGE.
 * Returns 0 when the XDATA words 0xA604 or 0xA5FF are 0. Otherwise calls FUN_CODE_c32e with the words 0xA606,
 * 0xA601, 0xA604, 0xA5FF as XDATA pointers and the bytes 0xA608, 0xA603 (p in R1..R3, the other five arguments in
 * its XDATA parameter block 0xA71E..0xA728, where FUN_CODE_c32e reads them), then FUN_CODE_dd63(0).
 * n = number of leading bytes of the 6-byte field at XDATA 0xA60B before the first 0x00 or 0xFF byte;
 * FUN_CODE_8622(byte 0xA609, byte 0xA60A, n, buf) fills buf[0..n-1]; returns 0 at the first buf byte that differs
 * from the field. Then the 16-byte local table tbl (initialised to zero from CODE) gets 3 and the n buf bytes
 * (it is not read afterwards) and the function returns 1.
 * LARGE locals: buf 0xA6C4..0xA6C9, n 0xA6CA, tbl 0xA6CB..0xA6DA.
 * volatile: written outside the 8051 program (no 8051 code or init record writes 0xA609..0xA610); the firmware
 *   reads the entry again for the 0xFF test.
 * Source form: the compare is written 'id[i] != buf[i]' (field first).
 */
extern unsigned int xdata DAT_EXTMEM_a5ff, DAT_EXTMEM_a601, DAT_EXTMEM_a604, DAT_EXTMEM_a606;
extern unsigned char xdata DAT_EXTMEM_a603, DAT_EXTMEM_a608;
struct rec_a609 { unsigned char dev; unsigned char reg; unsigned char id[6]; };
extern volatile struct rec_a609 xdata DAT_EXTMEM_a609;

void FUN_CODE_c32e(unsigned char *p, unsigned char *a, unsigned char *b, unsigned char *c, unsigned char d, unsigned char e);
void FUN_CODE_dd63(char c);
void FUN_CODE_8622(unsigned char dev, unsigned int reg, unsigned int n, unsigned char *buf);

unsigned char FUN_CODE_7f36(void)
{
    unsigned char buf[6];
    unsigned char n;
    unsigned char tbl[16] = {0};
    unsigned char i;

    if (DAT_EXTMEM_a604 == 0 || DAT_EXTMEM_a5ff == 0) return 0;
    FUN_CODE_c32e((unsigned char *)DAT_EXTMEM_a606, (unsigned char *)DAT_EXTMEM_a601, (unsigned char *)DAT_EXTMEM_a604,
                  (unsigned char *)DAT_EXTMEM_a5ff, DAT_EXTMEM_a608, DAT_EXTMEM_a603);
    FUN_CODE_dd63(0);
    for (i = 0; i < 6; i++) {
        if (DAT_EXTMEM_a609.id[i] == 0) break;
        if (DAT_EXTMEM_a609.id[i] == 0xff) break;
    }
    n = i;
    FUN_CODE_8622(DAT_EXTMEM_a609.dev, DAT_EXTMEM_a609.reg, n, buf);
    for (i = 0; i < n; i++) {
        if (DAT_EXTMEM_a609.id[i] != buf[i]) return 0;
    }
    tbl[0] = 3;
    for (i = 0; i < n; i++) tbl[i + 1] = buf[i];
    return 1;
}
