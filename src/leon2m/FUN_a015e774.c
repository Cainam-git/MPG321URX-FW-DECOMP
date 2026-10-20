/* leon2m FUN_a015e774 @ 0xa015e774  MATCH (-mcpu=v8 -O2 -g, twin)
 * Twin of FUN_a0156714: same code, constants swapped; byte-exact.
 * See FUN_a0156714 for the explanation; this copy's constants differ, so its comments were removed.
 */
extern void FUN_a015734c(double *, unsigned int *);
extern int FUN_a0157480(unsigned int *, unsigned int *);

int FUN_a015e774(double a, double b)
{
    unsigned int buf1[6];
    unsigned int buf2[6];

    FUN_a015734c(&a, buf1);
    FUN_a015734c(&b, buf2);

    if (buf1[0] <= 1 || buf2[0] <= 1)
        return 1;

    return FUN_a0157480(buf1, buf2);
}
