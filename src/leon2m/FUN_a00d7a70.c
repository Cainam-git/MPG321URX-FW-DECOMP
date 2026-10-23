/* leon2m FUN_a00d7a70 @ 0xa00d7a70-0xa00d7b20 (44 words).
 * FUN_a00d6054(1, &t) fills a 16-byte, 8-aligned stack record t; a copy c of it goes to FUN_a0149b8c(1, &c),
 * then FUN_a0149f44(1). When the argument is non-zero, FUN_a014d474(1, 0) runs before the copy and
 * FUN_a01437dc(0x32), FUN_a014d474(1, 1) after FUN_a0149f44(1). Same record form as FUN_a00d7a30.
 */
struct Timing { unsigned long long q0, q1; };
extern void FUN_a00d6054(int, void *);
extern void FUN_a0149b8c(int, void *);
extern void FUN_a0149f44(unsigned char);
extern void FUN_a014d474(unsigned char, unsigned char);
extern void FUN_a01437dc(unsigned short ms);

void FUN_a00d7a70(unsigned char on)
{
    struct Timing t;
    struct Timing c;

    FUN_a00d6054(1, &t);
    if (on)
        FUN_a014d474(1, 0);
    c = t;
    FUN_a0149b8c(1, &c);
    FUN_a0149f44(1);
    if (on) {
        FUN_a01437dc(0x32);
        FUN_a014d474(1, 1);
    }
}
