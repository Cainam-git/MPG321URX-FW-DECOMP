/* 8051_bank2 FUN_CODE_e1c1 @ 0xe1c1 (42 B).
 * Callers (byte scan, xref.py): FUN_CODE_9f8f (0xa0e4), FUN_CODE_ca42 (0xcafa).
 * Code: 3-byte command {2, 0x0f, a} in the xdata buffer DAT_EXTMEM_0436, sent with bfcf(0x6e, 3, buf), wait
 * d059(100), then tail call e4bf(buf). Twin of FUN_CODE_e27c, minus e27c's store of the bfcf result
 * (0x08f0): here the result is unused. No aids.
 */
extern unsigned char xdata DAT_EXTMEM_0436[];
unsigned char FUN_CODE_bfcf(unsigned char addr, unsigned char len, unsigned char *buf);
void FUN_CODE_d059(unsigned int t);
void FUN_CODE_e4bf(unsigned char *buf);
void FUN_CODE_e1c1(unsigned char a)
{
    DAT_EXTMEM_0436[0] = 2;
    DAT_EXTMEM_0436[1] = 0x0f;
    DAT_EXTMEM_0436[2] = a;
    FUN_CODE_bfcf(0x6e, 3, DAT_EXTMEM_0436);
    FUN_CODE_d059(100);
    FUN_CODE_e4bf(DAT_EXTMEM_0436);
}
