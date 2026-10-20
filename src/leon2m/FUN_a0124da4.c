/* leon2m FUN_a0124da4 @ 0xa0124da4-0xa0124df8 (21 words), flags -mcpu=v8 -O3 -g.
 * Code facts: leaf; r = ROM record DAT_001a42a8[n] (0x16 bytes, same table as FUN_a0125380); if n <= 7 and r->b0e !=
 * 0xff: tail ROM func_0x4008c86c(r->b0e, r->b0f, ~r->b10 & 0xff).
 * The third argument is the complement of byte +0x10 (fw 'xnor %g0, x' then 'and 0xff'); the table symbol
 * DAT_001a42a8 is an array of 22-byte structs. Compiler aids: none.
 */
struct rec { unsigned char b00[0xe]; unsigned char b0e, b0f, b10; unsigned char b11[5]; };
extern const struct rec DAT_001a42a8[];
extern void func_0x4008c86c(unsigned char, unsigned char, unsigned char);

void FUN_a0124da4(unsigned char n)
{
    const struct rec *r = &DAT_001a42a8[n];

    if (n <= 7 && r->b0e != 0xff)
        func_0x4008c86c(r->b0e, r->b0f, ~r->b10);
}
