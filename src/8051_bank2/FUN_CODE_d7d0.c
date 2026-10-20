/* 8051_bank2 FUN_CODE_d7d0 @ 0xd7d0 (124 B).
 * Caller (byte scan, xref.py): FUN_CODE_a547 (0xa6a5).
 * Code: number of 256-byte pages for n bytes, rounded up: r = n / 256 (?C?ULDIV FUN_CODE_3380), plus 1 when
 * n % 256 != 0 (low byte vs 0 with ?C?ULCMP). LARGE parameter n (0x0912), local r (0x0916). The else arm stores r
 * and then increments it as a second statement (store / reload / add / store in the firmware).
 * `(n & 0xff) == 0` gives the same bytes (v/d7d0_2.c). No aids.
 */
unsigned long FUN_CODE_d7d0(unsigned long n)
{
    unsigned long r;
    if (n % 256 == 0) r = n / 256;
    else {
        r = n / 256;
        r++;
    }
    return r;
}
