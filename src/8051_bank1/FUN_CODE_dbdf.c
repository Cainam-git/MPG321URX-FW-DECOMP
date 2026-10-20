/* 8051_bank1 FUN_CODE_dbdf @ 0xdbdf (no draft)
 * Posts one 32-bit word to the Big chip mailbox portal at offset 0xB0: FUN_CODE_b228(0xB0, &v, 1).
 * v is the LARGE parameter at XDATA 0xA4B3 (stored with ?C?LSTXDATA 0x09b1); n = 1 goes to b228's XDATA
 * parameter 0xA4BF; tail LJMP b228. ('x = v; b228(0xb0, &x, 1)' also matches.)
 * Callers: LJMP at 0x21b3 (FUN_CODE_1c3c), LCALL at 0x244b (case body of the 0x224f switch, no functions.json entry).
 * Byte-exact with OPTIMIZE(8,SPEED) LARGE (MATCH exact None 23/23).
 */
void FUN_CODE_b228(unsigned char off, unsigned long *src, unsigned char n);
void FUN_CODE_dbdf(unsigned long v)
{
    FUN_CODE_b228(0xb0, &v, 1);
}
