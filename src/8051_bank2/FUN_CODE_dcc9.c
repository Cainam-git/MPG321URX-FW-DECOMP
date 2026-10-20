/* 8051_bank2 FUN_CODE_dcc9 @ 0xdcc9 (81 B).
 * Callers (byte scan, xref.py): FUN_CODE_8437 (0x8479, 0x8507, 0x86f7; declared there as
 * `extern unsigned char FUN_CODE_dcc9(unsigned long v)`, called as dcc9(d64c(0))).
 * Code: LARGE parameter v (0x08F6), local r (0x08FA, stored per arm and read back once at the end). Low 16 bits of v
 * == 0 -> 0x40; else low 15 bits (v & 0x7fff) == 0 -> 0x20; else 4. Both tests are ?C?ULCMP (FUN_CODE_342d) against
 * 0. Own segment, not one of the 8437 module's common-entry members. No aids.
 */
unsigned char FUN_CODE_dcc9(unsigned long v)
{
    unsigned char r;
    if ((v & 0xffff) == 0) r = 0x40;
    else if ((v & 0x7fff) == 0) r = 0x20;
    else r = 4;
    return r;
}
