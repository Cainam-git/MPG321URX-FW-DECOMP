/* leon2m FUN_a00ad86c @ 0xa00ad86c  (-mcpu=v8 -O3 -g)
 * row = (sel & 3) * 2 + 4; id = 3 and w = 4 when flag != 0, else id = 4 and w = 0xC. Calls FUN_a0146c40(id, 0, 0),
 * FUN_a014667c(id, 0, 0, 0, 0, w, 0, 0, 0, 0, 0), FUN_a0146870(id, 0x48, row * 36 + a, 0x1C7, row * 36 + b, 0)
 * with (a, b) = (0x1A, 0x51) when flag != 0, else (0x16, 0x55), and FUN_a0146c40(id, 1, 0). When flag != 0 it
 * ends with a tail call FUN_a00ad5a4(2, 3, row, flag).
 * Callers: FUN_a00adaf4 and others.
 */
extern void FUN_a0146c40(int, int, int);
extern void FUN_a014667c(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int,
                         unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
extern void FUN_a0146870(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
extern void FUN_a00ad5a4(unsigned char, unsigned char, unsigned char, unsigned char);

void FUN_a00ad86c(unsigned char sel, unsigned char flag)
{
    unsigned char row = (sel & 3) * 2 + 4;
    unsigned char id;
    unsigned char w;

    if (flag) {
        id = 3;
        w = 4;
    } else {
        id = 4;
        w = 0xc;
    }
    FUN_a0146c40(id, 0, 0);
    FUN_a014667c(id, 0, 0, 0, 0, w, 0, 0, 0, 0, 0);
    if (flag)
        FUN_a0146870(id, 0x48, row * 36 + 0x1a, 0x1c7, row * 36 + 0x51, 0);
    else
        FUN_a0146870(id, 0x48, row * 36 + 0x16, 0x1c7, row * 36 + 0x55, 0);
    FUN_a0146c40(id, 1, 0);
    if (flag)
        FUN_a00ad5a4(2, 3, row, flag);
}
