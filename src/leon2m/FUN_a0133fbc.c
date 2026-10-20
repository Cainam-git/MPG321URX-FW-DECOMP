/* leon2m FUN_a0133fbc @ 0xa0133fbc-0xa0134068 (43 words), flags -mcpu=v8 -O3 -g. Callers: FUN_a01253bc,
 * FUN_a012c188, FUN_a012c80c, FUN_a012cd68.
 * When FUN_a00dd614(0x20) returns non-zero, prints "Enable Internal EDID : %d\r\n" with a. Then calls
 * func_0x4008f3f4(1, a, 0xa0, len > 0x80, 1) and, when len is above 0x100, tail-calls
 * func_0x4008f3f4(0xe, a, c, 0, 1) (the RAM copy of FUN_a002f3f4, which sends a command to the 8051 mailbox).
 * The two size flags are unsigned char locals set to 1 (the first one is passed as (flag & 1), the second one is
 * tested with == 1; a plain truth test changes the block order).
 */
extern unsigned char FUN_a00dd614(int);
extern int FUN_a00df170();
extern char s_001a53f8[];
extern void func_0x4008f3f4(unsigned char, unsigned char, unsigned char, unsigned char, unsigned char);

void FUN_a0133fbc(unsigned char a, unsigned short len, unsigned char c)
{
    unsigned char big = 0, huge = 0;

    if (FUN_a00dd614(0x20))
        FUN_a00df170(s_001a53f8, a);
    if (len > 0x80)
        big = 1;
    func_0x4008f3f4(1, a, 0xa0, big & 1, 1);
    if (len > 0x100)
        huge = 1;
    if (huge == 1)
        func_0x4008f3f4(0xe, a, c, 0, 1);
}
