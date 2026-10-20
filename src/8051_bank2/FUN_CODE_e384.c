/* 8051_bank2 FUN_CODE_e384 @ 0xe384 (39 B).
 * Caller (byte scan, xref.py): FUN_CODE_c1a6 (0xc1ae).
 * Code: struct copy (?C?COPY = FUN_CODE_3153, length 8) of the 8-byte code-space record at 0xCBC4 into the xdata
 * buffer 0x08F3, then bfcf(0x6e, 8, &buf), then tail call d059(0x0fa0). The record is
 * declared as 8 bytes. No aids.
 */
struct Rec8 { unsigned char b[8]; };
extern struct Rec8 code DAT_CODE_cbc4;
extern struct Rec8 xdata DAT_EXTMEM_08f3;
unsigned char FUN_CODE_bfcf(unsigned char addr, unsigned char len, unsigned char *buf);
void FUN_CODE_d059(unsigned int t);
void FUN_CODE_e384(void)
{
    DAT_EXTMEM_08f3 = DAT_CODE_cbc4;
    FUN_CODE_bfcf(0x6e, 8, (unsigned char *)&DAT_EXTMEM_08f3);
    FUN_CODE_d059(0x0fa0);
}
