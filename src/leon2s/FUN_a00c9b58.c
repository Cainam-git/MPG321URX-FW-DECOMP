/* leon2s FUN_a00c9b58 @ 0xa00c9b58 (-mcpu=v8 -Os -g)
 * Calls FUN_a00c99a4(p1, 0, 6, 4, p2), then FUN_a0fb7ee0(p1, r, v) for (r, v) = (4, 7), (0, 1), (6, 1), (7, 0),
 * (0, 0), (1, 0xfd), (9, 0); then (8, 0x42) and FUN_a0fb7f1c(p1, 0xf, 0x40, 0) when p2 == 0x400, otherwise (8,
 * 0xc2) and FUN_a0fb7f1c(p1, 0xf, 0x40, 1); then (3, 9), waits until bit 5 of FUN_a0fb7fa0(p1, 2) is set, then (3,
 * 0), (8, 0x40) and FUN_a0fb7f1c(p1, 0xf, 0x40, 0).
 * Source form: Ghidra's type and symbol names are kept.
 */
extern void FUN_a00c99a4(unsigned int, void *, unsigned char, unsigned char, unsigned short); /* 0xa00c99a4 */
extern void FUN_a0fb7ee0(unsigned int, int, int); /* 0xa0fb7ee0 */
extern void FUN_a0fb7f1c(unsigned int, int, int, int); /* 0xa0fb7f1c */
extern int FUN_a0fb7fa0(unsigned int, int); /* 0xa0fb7fa0 */

void FUN_a00c9b58(unsigned char param_1, unsigned short param_2)
{
    int status;

    FUN_a00c99a4(param_1, 0, 6, 4, param_2);

    FUN_a0fb7ee0(param_1, 4, 7);
    FUN_a0fb7ee0(param_1, 0, 1);
    FUN_a0fb7ee0(param_1, 6, 1);
    FUN_a0fb7ee0(param_1, 7, 0);
    FUN_a0fb7ee0(param_1, 0, 0);
    FUN_a0fb7ee0(param_1, 1, 0xfd);
    FUN_a0fb7ee0(param_1, 9, 0);

    if (param_2 == 0x400) {
        FUN_a0fb7ee0(param_1, 8, 0x42);
        FUN_a0fb7f1c(param_1, 0xf, 0x40, 0);
    } else {
        FUN_a0fb7ee0(param_1, 8, 0xc2);
        FUN_a0fb7f1c(param_1, 0xf, 0x40, 1);
    }

    FUN_a0fb7ee0(param_1, 3, 9);

    do {
        status = FUN_a0fb7fa0(param_1, 2);
    } while ((status & 0x20) == 0);

    FUN_a0fb7ee0(param_1, 3, 0);
    FUN_a0fb7ee0(param_1, 8, 0x40);
    FUN_a0fb7f1c(param_1, 0xf, 0x40, 0);
}
