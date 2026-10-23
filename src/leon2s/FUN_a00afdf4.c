/* FUN_a00afdf4 (leon2s 0xa00afdf4-0xa00afeb8, 196 bytes), flags -mcpu=v8 -Os -g.
 * q = FUN_a00add48(port, func_0x9f1c6624(port)). For mode 1 the function ends with the tail call
 * FUN_a00afdb0(port). Otherwise, when bit port of the byte DAT_a8079314 is clear, FUN_a00a8400(q, 1, 0x20, 0) and
 * FUN_a00a8400(q, 3, 2, 0); then FUN_a00a8400(q, 3, 3, 1), FUN_a00a8400(q, 3, 4, 1), FUN_a00b1794(1) and the tail
 * call FUN_a00a8400(q, 3, 4, 0).
 * Source form: FUN_a00afdb0 takes one parameter (it reads only %i0); the argument registers 3, 4, 0 of the last
 * tail call are set once before the mode test.
 */
extern unsigned char DAT_a8079314;
extern unsigned int func_0x9f1c6624(unsigned char);
extern unsigned char FUN_a00add48(unsigned char, unsigned char);
extern void FUN_a00a8400(unsigned char, unsigned short, unsigned char, unsigned char);
extern void FUN_a00afdb0(unsigned char);
extern void FUN_a00b1794(int);

void FUN_a00afdf4(unsigned char port, unsigned char mode)
{
    unsigned char q;

    q = FUN_a00add48(port, func_0x9f1c6624(port));
    if (mode == 1) {
        FUN_a00afdb0(port);
        return;
    }
    if (((DAT_a8079314 >> port) & 1) == 0) {
        FUN_a00a8400(q, 1, 0x20, 0);
        FUN_a00a8400(q, 3, 2, 0);
    }
    FUN_a00a8400(q, 3, 3, 1);
    FUN_a00a8400(q, 3, 4, 1);
    FUN_a00b1794(1);
    FUN_a00a8400(q, 3, 4, 0);
}
