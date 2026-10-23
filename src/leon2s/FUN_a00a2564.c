/* leon2s FUN_a00a2564 @ 0xa00a2564-0xa00a268c, -mcpu=v8 -Os -g.
 * (u8 m), void. Only when (u8)FUN_a008d800() > 0x82: for each set bit of m (bit 0 -> 0xc, bit 1 -> 0xd,
 * bit 2 -> 0xe, bit 3 -> 0xf, bit 4 -> 0xb) calls FUN_a00a73d4(value, p + 0xc0) for the pointer p at +0x24
 * of record 0 and then of record 1 of the 0x34-byte array ARR_a807db00.
 */
struct Port34 { unsigned char pad[0x24]; unsigned char *p24; unsigned char rest[0xc]; };
extern struct Port34 ARR_a807db00[];
extern unsigned char FUN_a008d800(void);
extern void FUN_a00a73d4(int, unsigned char *);

void FUN_a00a2564(unsigned char m)
{
    if (FUN_a008d800() > 0x82) {
        if (m & 1) {
            FUN_a00a73d4(0xc, ARR_a807db00[0].p24 + 0xc0);
            FUN_a00a73d4(0xc, ARR_a807db00[1].p24 + 0xc0);
        }
        if (m & 2) {
            FUN_a00a73d4(0xd, ARR_a807db00[0].p24 + 0xc0);
            FUN_a00a73d4(0xd, ARR_a807db00[1].p24 + 0xc0);
        }
        if (m & 4) {
            FUN_a00a73d4(0xe, ARR_a807db00[0].p24 + 0xc0);
            FUN_a00a73d4(0xe, ARR_a807db00[1].p24 + 0xc0);
        }
        if (m & 8) {
            FUN_a00a73d4(0xf, ARR_a807db00[0].p24 + 0xc0);
            FUN_a00a73d4(0xf, ARR_a807db00[1].p24 + 0xc0);
        }
        if (m & 0x10) {
            FUN_a00a73d4(0xb, ARR_a807db00[0].p24 + 0xc0);
            FUN_a00a73d4(0xb, ARR_a807db00[1].p24 + 0xc0);
        }
    }
}
