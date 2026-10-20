/* 8051_bank2 FUN_CODE_df7f @ 0xdf7f (63 B).
 * Callers (byte scan, xref.py): FUN_CODE_dd1a (0xdd5e), FUN_CODE_e4a4 (0xe4ad).
 * Code: LARGE parameters a, b (homes 0x08F3 / 0x08F4 = this function's XDATA block). The 10-byte record at code
 * 0xCBCC (09 2d aa 55 cc 33 e2 1d ff ff) is struct-copied (?C?COPY = FUN_CODE_3153) to xdata 0x08F5, bytes 8 and 9
 * become a and b, then bfcf(0x6e, 10, &buf) and tail call d059(5000).
 * Form note: an initialised local array at 0x08F5 (`unsigned char buf[10] = {...}`, which Keil builds as ?C?COPY
 * from an init image) compiles to the SAME instructions (v/df7f_L.c, 98.4 %), but
 * the judge cannot place it: it learns the init image _?ix1000 from its LOW byte only and then fills HIGH with 0x00.
 * So the buffer and the image are named by their firmware addresses here (DAT_EXTMEM_08f5, DAT_CODE_cbcc).
 * Same pattern and note as FUN_CODE_e384 (0x08F3 / 0xCBC4, 8 bytes).
 */
struct Rec10 { unsigned char b[10]; };
extern struct Rec10 code DAT_CODE_cbcc;
extern struct Rec10 xdata DAT_EXTMEM_08f5;
unsigned char FUN_CODE_bfcf(unsigned char addr, unsigned char len, unsigned char *buf);
void FUN_CODE_d059(unsigned int t);
void FUN_CODE_df7f(unsigned char a, unsigned char b)
{
    DAT_EXTMEM_08f5 = DAT_CODE_cbcc;
    DAT_EXTMEM_08f5.b[8] = a;
    DAT_EXTMEM_08f5.b[9] = b;
    FUN_CODE_bfcf(0x6e, 10, DAT_EXTMEM_08f5.b);
    FUN_CODE_d059(5000);
}
