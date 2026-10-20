/* leon2m FUN_a00b52f8 @ 0xa00b52f8  MATCH (-mcpu=v8 -O2 -g)
 * The function performs a fixed sequence of calls, truncates `param_1` and `param_3` to 16 bits via zero-extension (which the compiler implements with `sll`/`srl`), masks `param_2` to 8 bits, reads two bytes from a fixed address, and ends with a tail call returning the result of `FUN_a0146108(0)`. The only structural change from the previous attempt is using `(unsigned short)` casts to force the exact shift idioms seen in the target, and correcting the final call to return its value.
 */
extern void FUN_a0146dc0(int, int);
extern void FUN_a0146c40(int, int, int);
extern void FUN_a0146648(int, int, int, int, int);
extern void FUN_a014613c(int, int, int);
extern void FUN_a0146518(int, int, int);
extern void FUN_a0146ab0(int, int);
extern int FUN_a0146108(int);

int FUN_a00b52f8(int param_1, int param_2, int param_3) {
    FUN_a0146dc0(0, 0);
    FUN_a0146c40(8, 0, 0);
    FUN_a0146648(0, 0, 0, 0, 0);
    FUN_a014613c((unsigned short)param_1, param_2 & 0xff, 0);
    {
        unsigned char *p = (unsigned char *)0xa802d290;
        FUN_a0146518(p[0xd], p[0xe], 0);
    }
    FUN_a0146ab0((unsigned short)param_3, 0);
    return FUN_a0146108(0);
}
