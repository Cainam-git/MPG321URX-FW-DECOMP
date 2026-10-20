/* leon2m FUN_a008ac90 @ 0xa008ac90-0xa008ad20 (36 words).
 * Calls FUN_a0146b50(0xd3, 0), then FUN_a00a31a4(0, byte 0x10028a + 0xb, 0x14, 3, s, 0) with s = the data at 0x1002a0
 * when FUN_a0145af8(2) returns 0 and the data at 0x1002a8 otherwise.
 */
extern const unsigned char DAT_0010028a;
extern const char s_001002a0[], s_001002a8[];
extern void FUN_a0146b50(unsigned short, unsigned char);
extern unsigned short FUN_a0145af8(unsigned int);
extern void FUN_a00a31a4(unsigned char, unsigned short, unsigned short, unsigned char, const char *, unsigned char);

void FUN_a008ac90(void)
{
    FUN_a0146b50(0xd3, 0);
    if (FUN_a0145af8(2) != 0)
        FUN_a00a31a4(0, DAT_0010028a + 0xb, 0x14, 3, s_001002a8, 0);
    else
        FUN_a00a31a4(0, DAT_0010028a + 0xb, 0x14, 3, s_001002a0, 0);
}
