/* 8051_bank2 FUN_CODE_e04a @ 0xe04a (65 B).
 * Caller (byte scan, xref.py): FUN_CODE_69da (0x6a97).
 * Code: LARGE parameters a (ulong, R4..R7, stored to its home 0x0986 with ?C?LSTXDATA = FUN_CODE_34e1), b (ulong,
 * home 0x098A) and n (uchar, home 0x098E). abce(DATA 0x22 buffer, b, n, 0), then tail call b1a9(DATA 0x22 buffer,
 * a, n, 0): read n bytes at b into the buffer, write them at a. abce / b1a9 declared small as in the accepted
 * FUN_CODE_e373 / e306 / 8437 (n / f at DATA 0x0F / 0x10); DAT_0022 as in e373 (generic pointer type 00). No aids.
 */
extern unsigned char data DAT_0022[];
extern void FUN_CODE_abce(unsigned char *buf, unsigned long addr, unsigned char n, unsigned char f) small;
extern void FUN_CODE_b1a9(unsigned char *buf, unsigned long addr, unsigned char n, unsigned char f) small;
void FUN_CODE_e04a(unsigned long a, unsigned long b, unsigned char n)
{
    FUN_CODE_abce(DAT_0022, b, n, 0);
    FUN_CODE_b1a9(DAT_0022, a, n, 0);
}
