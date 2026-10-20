/* leon2m FUN_a0156714 @ 0xa0156714 (-mcpu=v8 -O2 -g)
 * This should match: the two calls, the two comparisons, the early return of 1, and the final call with its result returned.
 */
extern void FUN_a015734c(double *, unsigned int *);
extern int FUN_a0157480(unsigned int *, unsigned int *);

int FUN_a0156714(double a, double b)
{
    unsigned int buf1[6];
    unsigned int buf2[6];

    FUN_a015734c(&a, buf1);
    FUN_a015734c(&b, buf2);

    if (buf1[0] <= 1 || buf2[0] <= 1)
        return 1;

    return FUN_a0157480(buf1, buf2);
}
