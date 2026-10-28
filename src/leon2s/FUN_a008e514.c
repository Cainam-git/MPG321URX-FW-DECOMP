/* leon2s FUN_a008e514 @ 0xa008e514-0xa008e5ac (38 words), flags -mcpu=v8 -Os -g.
 * Code facts: a = 0, b = c, e = c for en == 0; a = 2, b = 8, e = c otherwise. When FUN_a008d800() > 0x81 it
 * tail-calls FUN_a0095f20(port, en, a, b, 0, e); else FUN_a008d980(port, a), FUN_a008d920(port, b),
 * FUN_a008da34(port, 0) and a tail call FUN_a008d9d4(port, e).
 * Same form as the neighbour FUN_a008e484: all byte locals first set to 0, then each arm assigns every local
 * (including the repeated 'a = 0' and 'e = c'). Aids: none.
 */
extern unsigned char FUN_a008d800(void);
extern void FUN_a008d980(unsigned int param_1, unsigned char param_2);
extern void FUN_a008d920(unsigned int param_1, unsigned char param_2);
extern void FUN_a008da34(unsigned int param_1, unsigned char param_2);
extern void FUN_a008d9d4(unsigned int param_1, unsigned char param_2);
extern void FUN_a0095f20(unsigned char p1, unsigned char p2, unsigned char p3, unsigned char p4,
                         unsigned char p5, unsigned char p6);

void FUN_a008e514(unsigned char port, unsigned char en, unsigned char c)
{
    unsigned char a;
    unsigned char b;
    unsigned char e;

    a = 0;
    b = 0;
    e = 0;
    if (en == 0) {
        a = 0;
        b = c;
        e = c;
    } else {
        a = 2;
        b = 8;
        e = c;
    }
    if (FUN_a008d800() > 0x81) {
        FUN_a0095f20(port, en, a, b, 0, e);
        return;
    }
    FUN_a008d980(port, a);
    FUN_a008d920(port, b);
    FUN_a008da34(port, 0);
    FUN_a008d9d4(port, e);
}
