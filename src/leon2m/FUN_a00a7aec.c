/* leon2m FUN_a00a7aec @ 0xa00a7aec-0xa00a7c88 (103 words).
 * For i = 7..8 (p non-zero) or 0..6 (p 0): c = 0x49 for i 0, i * 3 + 0x52 for i 1..5, 0x64, 0x70, 0x7c for i 6, 7,
 * 8; row = (i % 7) * 2 + 6. For i 0, 6 and 7 calls FUN_a00b32e4(1, 1, 0x629a, 2, row - 1, 3, c), (.., row, 3,
 * c + 3) and (.., row + 1, 3, c + 6); for the other i FUN_a00b32e4(1, 1, 0x659a, 2, row, 3, c).
 * Source form: the end bound is assigned before the start bound; the 6/7 tests come before the 0 test.
 */
extern void FUN_a00b32e4(unsigned char, unsigned char, unsigned short, unsigned short, unsigned char, unsigned char,
                         unsigned char);

void FUN_a00a7aec(unsigned char p)
{
    unsigned char i, start, end, row;
    unsigned char c = 0;

    end = 9;
    start = 7;
    if (p == 0) {
        end = 7;
        start = 0;
    }
    for (i = start; i < end; i++) {
        switch (i) {
        case 0:
            c = 0x49;
            break;
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
            c = i * 3 + 0x52;
            break;
        case 6:
            c = 0x64;
            break;
        case 7:
            c = 0x70;
            break;
        case 8:
            c = 0x7c;
            break;
        }
        row = (i % 7) * 2 + 6;
        if (i == 6 || i == 7 || i == 0) {
            FUN_a00b32e4(1, 1, 0x629a, 2, row - 1, 3, c);
            FUN_a00b32e4(1, 1, 0x629a, 2, row, 3, c + 3);
            FUN_a00b32e4(1, 1, 0x629a, 2, row + 1, 3, c + 6);
        } else {
            FUN_a00b32e4(1, 1, 0x659a, 2, row, 3, c);
        }
    }
}
