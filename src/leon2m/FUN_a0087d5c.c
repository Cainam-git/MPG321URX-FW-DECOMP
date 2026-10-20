/* leon2m FUN_a0087d5c @ 0xa0087d5c-0xa0087da4 (18 words).
 * With e = entry n (entry 0 when n >= 4) of the 0x44-byte records at 0xff600: calls FUN_a01474b0(1, e) and then
 * tail-calls FUN_a01474b0(0, e).
 */
struct R44 { unsigned char b[0x44]; };
extern const struct R44 DAT_000ff600[4];
extern void FUN_a01474b0(int, const struct R44 *);

void FUN_a0087d5c(unsigned char n)
{
    const struct R44 *e;

    if (n >= 4)
        n = 0;
    e = &DAT_000ff600[n];
    FUN_a01474b0(1, e);
    FUN_a01474b0(0, e);
}
