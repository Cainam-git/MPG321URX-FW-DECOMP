/* leon2s FUN_a00a2418 @ 0xa00a2418-0xa00a2564, -mcpu=v8 -Os -g.
 * (port, u8 m), void. Only when (u8)FUN_a008d800() > 0x82: for each set bit of m (bit 0 -> 0xc, bit 1 ->
 * 0xd, bit 2 -> 0xe, bit 3 -> 0xf, bit 4 -> 0xb) calls FUN_a00a73ac(value, p + 0xc0), p = the pointer at +0x24
 * of the 0x34-byte record ARR_a807db00[port]; then always FUN_a00a73ac(8, p + 0xc0) and FUN_a00a73ac(9, p + 0xc0).
 * Source form: port is a raw parameter truncated at each use (the firmware repeats the and 0xff).
 * Counterpart of FUN_a00a2564 (FUN_a00a73d4, both records).
 */
struct Port34 { unsigned char pad[0x24]; unsigned char *p24; unsigned char rest[0xc]; };
extern struct Port34 ARR_a807db00[];
extern unsigned char FUN_a008d800(void);
extern void FUN_a00a73ac(int, unsigned char *);

void FUN_a00a2418(unsigned int port, unsigned char m)
{
    if (FUN_a008d800() > 0x82) {
        if (m & 1)
            FUN_a00a73ac(0xc, ARR_a807db00[port & 0xff].p24 + 0xc0);
        if (m & 2)
            FUN_a00a73ac(0xd, ARR_a807db00[port & 0xff].p24 + 0xc0);
        if (m & 4)
            FUN_a00a73ac(0xe, ARR_a807db00[port & 0xff].p24 + 0xc0);
        if (m & 8)
            FUN_a00a73ac(0xf, ARR_a807db00[port & 0xff].p24 + 0xc0);
        if (m & 0x10)
            FUN_a00a73ac(0xb, ARR_a807db00[port & 0xff].p24 + 0xc0);
        FUN_a00a73ac(8, ARR_a807db00[port & 0xff].p24 + 0xc0);
        FUN_a00a73ac(9, ARR_a807db00[port & 0xff].p24 + 0xc0);
    }
}
