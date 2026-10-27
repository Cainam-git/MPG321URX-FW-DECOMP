/* leon2m FUN_a00aa0e8 @ 0xa00aa0e8-0xa00aa258 (368 bytes), flags -mcpu=v8 -O3 -g.
 * row = sel * 2 - 8 for sel > 6, else sel * 2 + 6. For sel 2, 5 and 6 a flag is 1 when bit 15 of the word
 * _DAT_a802d404, bit 7 of _DAT_a802d338 or bit 31 of _DAT_a802d484 (in that order) is set, else 0. For any other
 * sel: FUN_a00a9468(1, 2), then FUN_a00b34d4(0, 1). For sel 2, 5 and 6: v = 0x742 (mode 1) or 0x792
 * (other modes) when the flag is 1, 0x200 less otherwise; FUN_a00b32e4(1, 1, v, 0x22, row, 3, k) with
 * k = 0x37 for v 0x742 and 0x792, else 0x34; then FUN_a00a9468(1, 3) and FUN_a00b34d4(0, 2).
 * Callers: FUN_a00919b4, FUN_a0091a68, FUN_a0091b94, FUN_a0095acc, FUN_a0095dd8, FUN_a0099440.
 * Source form: the bit 15 and bit 7 flags are set to 1 first and cleared when the bit is clear (the two tests
 * stay branches); the bit 31 mask is held in a local variable (and + addx instead of a sign shift); k is an int.
 * Compiler aid: __builtin_expect(..., 0) on the test of v emits no instructions; it places the k = 0x34
 * block in line after the branch.
 */
extern unsigned int _DAT_a802d404;
extern unsigned int _DAT_a802d338;
extern unsigned int _DAT_a802d484;
extern void FUN_a00b32e4(unsigned char, unsigned char, unsigned short, unsigned short, unsigned char, unsigned char, unsigned char);
extern void FUN_a00a9468(unsigned int, unsigned int);
extern void FUN_a00b34d4(unsigned int, unsigned int);

void FUN_a00aa0e8(unsigned char sel, unsigned char mode)
{
    unsigned char row;
    unsigned char on = 0xff;
    unsigned short v;
    int attr;
    unsigned int m;

    if (sel > 6)
        row = sel * 2 - 8;
    else
        row = sel * 2 + 6;
    if (sel == 2) {
        on = 1;
        if (!(_DAT_a802d404 & 0x8000))
            on = 0;
    } else if (sel == 5) {
        on = 1;
        if (!(_DAT_a802d338 & 0x80))
            on = 0;
    } else if (sel == 6) {
        m = 0x80000000;
        on = (_DAT_a802d484 & m) != 0;
    }
    if (sel == 5 || sel == 2 || sel == 6) {
        if (mode == 1)
            v = on == 1 ? 0x742 : 0x542;
        else
            v = on == 1 ? 0x792 : 0x592;
        attr = 0x37;
        if (!__builtin_expect(v == 0x742 || v == 0x792, 0))
            attr = 0x34;
        FUN_a00b32e4(1, 1, v, 0x22, row, 3, attr);
        FUN_a00a9468(1, 3);
        FUN_a00b34d4(0, 2);
    } else {
        FUN_a00a9468(1, 2);
        FUN_a00b34d4(0, 1);
    }
}
