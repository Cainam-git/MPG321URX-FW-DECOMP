/* leon2m FUN_a008ac00 @ 0xa008ac00-0xa008ac90 (36 words).
 * Calls FUN_a0146b50(0xf7, 0), then FUN_a00a31a4(0, byte 0x100287 + 0xb, 0x13, 3, s, 0) with s = the data at 0x1002a0
 * when FUN_a0145af8(0x10) returns 0 and the data at 0x1002a8 otherwise.
 */
extern const unsigned char DAT_00100287;
extern const char s_001002a0[], s_001002a8[];
extern void FUN_a0146b50(unsigned short, unsigned char);
extern unsigned short FUN_a0145af8(unsigned int);
extern void FUN_a00a31a4(unsigned char, unsigned short, unsigned short, unsigned char, const char *, unsigned char);

void FUN_a008ac00(void)
{
    FUN_a0146b50(0xf7, 0);
    if (FUN_a0145af8(0x10) != 0)
        FUN_a00a31a4(0, DAT_00100287 + 0xb, 0x13, 3, s_001002a8, 0);
    else
        FUN_a00a31a4(0, DAT_00100287 + 0xb, 0x13, 3, s_001002a0, 0);
}
