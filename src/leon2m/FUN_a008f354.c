/* leon2m FUN_a008f354 @ 0xa008f354-0xa008f3e8 (148 bytes, 37 words).
 * Flags: -mcpu=v8 -O3 -g.
 * Code facts: calls FUN_a0090fd8(), FUN_a014512c(0, 1), FUN_a0145fe8(0, 0, 0, 0, 0), FUN_a00d8cd4(),
 * FUN_a00d7de0(), FUN_a00d9764(), FUN_a00d7bc0(); if bit 12 (0x1000) of the u16 at
 * DAT_a802cff4 + 4 is clear: FUN_a00da254(); then FUN_a00b50d8(1) and that bit is cleared
 * (lduh / andn / sth). The record base is a SYMBOL (fw sethi/or of 0xa802cff4, kept in %l0).
 * Source form: bit 12 of the u16 at +4 is a 1-bit BIT-FIELD (big-endian: fields a:3, b12:1, b:12 from the MSB).
 * The mask form '& 0x1000' (also with a mask variable, a cast, '!', '1 << 12' or an empty then-arm) gives
 * 'btst %o5,%g1'; the bit-field gives the fw 'btst %g1,%o5'. The +0/+2 halves are unnamed u16 slots.
 * No volatile. Aids: none.
 */
extern void FUN_a0090fd8(void);
extern void FUN_a014512c(unsigned int param_1, unsigned int param_2);
extern void FUN_a0145fe8(unsigned int param_1, unsigned int param_2, unsigned int param_3, unsigned int param_4, unsigned int param_5);
extern void FUN_a00d8cd4(void);
extern void FUN_a00d7de0(void);
extern void FUN_a00d9764(void);
extern void FUN_a00d7bc0(void);
extern void FUN_a00da254(void);
extern void FUN_a00b50d8(unsigned int param_1);
extern struct { unsigned short h0, h2; unsigned short h4a:3, b12:1, h4b:12; } DAT_a802cff4;

void FUN_a008f354(void)
{
    FUN_a0090fd8();
    FUN_a014512c(0, 1);
    FUN_a0145fe8(0, 0, 0, 0, 0);
    FUN_a00d8cd4();
    FUN_a00d7de0();
    FUN_a00d9764();
    FUN_a00d7bc0();
    
    if (DAT_a802cff4.b12 == 0) {
        FUN_a00da254();
    }
    
    FUN_a00b50d8(1);
    DAT_a802cff4.b12 = 0;
}
