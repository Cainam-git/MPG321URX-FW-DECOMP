/* leon2m FUN_a002fae0 @ 0xa002fae0-0xa002fb44 (25 words), flags -mcpu=v8 -O3 -g.
 * Code facts: for the 4 port records DAT_a802df30[i] (0x78 bytes; i*15*8): m = FUN_a002c204() (u8
 * read of hw 0xcf03c890, no args); if m & byte +0x76 of the record, FUN_a002e3c4((word +0 >> 12) &
 * 0xf, 1). The record offset is computed before the call. void(void).
 * The records are one struct array; FUN_a002c204 takes no arguments.
 * Source form: a record pointer p for the +0x76 test and the direct DAT_a802df30[i].w00 for the word read give
 * the fw [base + off] / [off + base] operand orders. Aids: none.
 */
struct Port { unsigned int w00; unsigned char pad[0x76 - 4]; unsigned char b76; unsigned char pad2; };
extern struct Port DAT_a802df30[4];
extern unsigned char FUN_a002c204(void);
extern void FUN_a002e3c4(unsigned char, int);

void FUN_a002fae0(void)
{
    unsigned char i;

    for (i = 0; i < 4; i++) {
        struct Port *p = &DAT_a802df30[i];
        if (FUN_a002c204() & p->b76)
            FUN_a002e3c4((DAT_a802df30[i].w00 >> 12) & 0xf, 1);
    }
}
