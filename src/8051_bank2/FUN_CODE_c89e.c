/* FUN_CODE_c89e, 8051_bank2 (helper chip updater), range 0xC89E..0xC973 (213 B).
 * Options: OPTIMIZE(8,SPEED) LARGE.
 * Code facts: n stays in R7 during the first loop (the LARGE parameter is never stored). Locals: k 0x090D,
 * off 0x090E, i 0x090F, v (ulong) 0x0910..0x0913; t and c are register-only (R6, R7). Walks the record list in
 * XDATA 0x015C as FUN_CODE_c7c5 does: each record starts with a header byte whose high and low nibbles are lengths,
 * a record is high + low + 1 bytes. It skips n records, then for i = 0 .. (low nibble of that header) - 1 adds
 * byte[off + i + 1] >> (i * 8) to v (an 8-bit right shift, so only i = 0 adds a non-zero value) and returns v.
 * Twin of FUN_CODE_c7c5 (same walk; c7c5 shifts left as a long).
 * Shift order: the firmware loads the byte into A before the count into R0 ('MOV A,R6; MOV R0,AR7' after the
 *   'MOV R7,A' of i * 8). That order comes from the byte and the count in named locals t and c, with the shift
 *   written as the result of a '?:' on 't == t' whose two outcomes are the same expression.
 * Compiler aid: the '?:' 't == t ? t >> c : t >> c' emits no code (both outcomes are identical; Keil merges them and
 *   drops the test). Inside the '?:' t and c stay in registers; as a plain 't >> c' in this loop Keil places them in
 *   XDATA (a library store of v follows in the loop body).
 * Caller: FUN_CODE_a17e (0x010D = FUN_CODE_c89e(0x042C), two sites).
 */
extern unsigned char xdata DAT_EXTMEM_015c[];
unsigned long FUN_CODE_c89e(unsigned char n)
{
    unsigned char k;
    unsigned char off;
    unsigned char i;
    unsigned long v;
    unsigned char t, c;
    off = 0;
    for (i = 0; i < n; i++) {
        off += ((DAT_EXTMEM_015c[off] & 0xf0) >> 4) + (DAT_EXTMEM_015c[off] & 0x0f) + 1;
    }
    k = DAT_EXTMEM_015c[off] & 0x0f;
    v = 0;
    for (i = 0; i < k; i++) {
        v = v + (t = DAT_EXTMEM_015c[(unsigned char)(off + i) + 1], c = i * 8, t == t ? t >> c : t >> c);
    }
    return v;
}
