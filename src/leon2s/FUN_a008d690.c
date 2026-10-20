/* leon2s FUN_a008d690 @ 0xa008d690-0xa008d70c (31 words), flags -mcpu=v8 -Os -g.
 * Code facts: ROM table ARR_a00b4036 of 4-byte {u16 a; u16 b} records. sum = u16 sum of
 * rec[0xc..0x10].b; FUN_a008d2e0(rec[0xc].a (= u16 at 0xa00b4066), sum, 0x9f1b0600);
 * FUN_a008d490(0x9f1b0600, 0xc, 0x11); byte DAT_a8078c00 = 1; tail call FUN_a006fedc() (no args:
 * it sets %o0.. itself). void, no params.
 * Fixes vs the autoc draft (84.38): the table is ONE record array at 0xa00b4036 (the draft had two
 * names, 0xa00b4038 indexed by u16*2 and 0xa00b4066); the tail callee takes no args (the draft
 * forwarded 6). Aids: none.
 */
struct Pair { unsigned short a; unsigned short b; };
extern const struct Pair ARR_a00b4036[];
extern unsigned char DAT_a8078c00;
extern void FUN_a006fedc(void);
extern void FUN_a008d2e0(unsigned short, unsigned short, unsigned int);
extern void FUN_a008d490(unsigned int, unsigned char, unsigned char);

void FUN_a008d690(void)
{
    unsigned short sum = 0;
    unsigned char i;

    for (i = 0xc; i <= 0x10; i++)
        sum += ARR_a00b4036[i].b;
    FUN_a008d2e0(ARR_a00b4036[0xc].a, sum, 0x9f1b0600);
    FUN_a008d490(0x9f1b0600, 0xc, 0x11);
    DAT_a8078c00 = 1;
    FUN_a006fedc();
}
