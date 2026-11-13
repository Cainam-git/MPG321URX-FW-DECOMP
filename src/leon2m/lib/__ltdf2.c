/* __ltdf2  (FUN_a015e774)
 *
 * Compare two double values for less-than (software floating point).
 * Name basis: proven - original name: the toolchain library code calls it by this name
 *
 * Matching notes
 * --------------
 * leon2m FUN_a015e774 @ 0xa015e774 (-mcpu=v8 -O2 -g)
 * Same code as __nedf2.
 */
extern void __unpack_d(double *, unsigned int *);
extern int __fpcmp_parts_d(unsigned int *, unsigned int *);

/*
 * Unpack both doubles into six-word parts buffers. When word 0 of either buffer is 1 or less, return 1;
 * otherwise return the result of the parts comparison (__fpcmp_parts_d).
 */
int __ltdf2(double a, double b)
{
    unsigned int buf1[6];
    unsigned int buf2[6];

    __unpack_d(&a, buf1);
    __unpack_d(&b, buf2);

    if (buf1[0] <= 1 || buf2[0] <= 1)
        return 1;

    return __fpcmp_parts_d(buf1, buf2);
}
