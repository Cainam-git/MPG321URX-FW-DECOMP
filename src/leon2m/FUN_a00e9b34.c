/* leon2m FUN_a00e9b34 @ 0xa00e9b34-0xa00e9c80 (83 words), flags -mcpu=v8 -O3 -g. Caller: FUN_a00e9c80.
 * FUN_a00e9b34(unit, p2, p3, val, b, r1, p6) writes three register fields with FUN_a00e0774, (reg, mask, shift)
 * taken from entry b of three word tables (b == -1 passes the table addresses themselves): tables 0xa8026838/
 * 0xa8026828/0xa802b708 get r1, tables 0xa8026348/0xa8026328/0xa802b658 and 0xa8026338/0xa8026318/0xa802b648 get
 * val. It then returns the two-word structure returned by FUN_a00e8e6c(unit, p2, p3, b, p6).
 * Source form: each write is its own if (b == -1)/else statement (as in FUN_a00e9c80); the structure result is
 * stored in a local and returned from it (the copy through fp-16 into the caller's return slot).
 */
struct win { int a; int b; };
extern void FUN_a00e0774(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);
extern struct win FUN_a00e8e6c(unsigned int, unsigned int, unsigned int, int, unsigned int);
extern unsigned int DAT_a8026838[], DAT_a8026828[], DAT_a802b708[];
extern unsigned int DAT_a8026348[], DAT_a8026328[], DAT_a802b658[];
extern unsigned int DAT_a8026338[], DAT_a8026318[], DAT_a802b648[];

struct win FUN_a00e9b34(unsigned int unit, unsigned int p2, unsigned int p3, int val, int b, int r1, unsigned int p6)
{
    struct win r;

    if (b == -1)
        FUN_a00e0774(unit, (unsigned int)DAT_a8026838, (unsigned int)DAT_a8026828, (unsigned int)DAT_a802b708, r1);
    else
        FUN_a00e0774(unit, DAT_a8026838[b], DAT_a8026828[b], DAT_a802b708[b], r1);
    if (b == -1)
        FUN_a00e0774(unit, (unsigned int)DAT_a8026348, (unsigned int)DAT_a8026328, (unsigned int)DAT_a802b658, val);
    else
        FUN_a00e0774(unit, DAT_a8026348[b], DAT_a8026328[b], DAT_a802b658[b], val);
    if (b == -1)
        FUN_a00e0774(unit, (unsigned int)DAT_a8026338, (unsigned int)DAT_a8026318, (unsigned int)DAT_a802b648, val);
    else
        FUN_a00e0774(unit, DAT_a8026338[b], DAT_a8026318[b], DAT_a802b648[b], val);
    r = FUN_a00e8e6c(unit, p2, p3, b, p6);
    return r;
}
