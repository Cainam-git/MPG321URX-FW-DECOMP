/* leon2m FUN_a00d7a30 @ 0xa00d7a30-0xa00d7a70 (16 words), flags -mcpu=v8 -O3 -g.
 * Twin of FUN_a00d79f0.
 * Code facts: FUN_a00d6054(2, &t) fills a 16-byte, 8-aligned stack record; it is copied as a whole (two ldd/std
 * pairs) into a second record c; FUN_a0149b8c(2, &c); FUN_a0149e8c(2). void(void).
 * Source form: a struct of two u64 copied by one struct assignment (separate u64 locals give another frame
 * layout); void prototypes.
 * Compiler aids: none.
 */
struct Timing { unsigned long long q0, q1; };
extern void FUN_a00d6054(int, void *);
extern void FUN_a0149b8c(int, void *);
extern void FUN_a0149e8c(unsigned char);

void FUN_a00d7a30(void)
{
    struct Timing t;
    struct Timing c;

    FUN_a00d6054(2, &t);
    c = t;
    FUN_a0149b8c(2, &c);
    FUN_a0149e8c(2);
}
