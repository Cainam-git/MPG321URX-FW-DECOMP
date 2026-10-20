/* leon2m FUN_a01567dc @ 0xa01567dc (-mcpu=v8 -O2 -g)
 * This function unpacks two double-precision arguments into their IEEE 754 parts using `__unpack_d`, then compares the two exponent fields. If either exponent is ≤ 1 (i.e., the value is zero, denormal, or tiny), it returns -1; otherwise it calls `__fpcmp_parts_d` to compare the full parts and returns its result. The Ghidra reconstruction was close but had the return value wrong (it returned a bogus 64-bit concatenation instead of -1) and the comparison branches were inverted; the similar matched functions `FUN_a015e774` and `FUN_a0156714` confirm the correct structure. The `return -1` (instead o
 */
extern void FUN_a015734c(double *, unsigned int *);
extern int FUN_a0157480(unsigned int *, unsigned int *);

int FUN_a01567dc(double a, double b)
{
    unsigned int buf1[6];
    unsigned int buf2[6];

    FUN_a015734c(&a, buf1);
    FUN_a015734c(&b, buf2);

    if (buf1[0] <= 1 || buf2[0] <= 1)
        return -1;

    return FUN_a0157480(buf1, buf2);
}
