/* leon2s FUN_a00a535c @ 0xa00a535c (-mcpu=v8 -Os)
 * r = (p3 * p1) / p2 (unsigned, p1 and p2 16-bit) * 100; prints "\n Pexil clock = %ld KHz\n\n" with r (FUN_a0073044),
 * calls FUN_a00a5148(0, r) and returns r.
 */
extern int FUN_a0073044(const char *, ...);
extern int FUN_a00a5148(int, int);

int FUN_a00a535c(unsigned short param_1, unsigned short param_2, int param_3)
{
    unsigned int prod;
    unsigned int divisor;
    int result;

    prod = (unsigned int)param_3 * (unsigned int)param_1;
    divisor = param_2 & 0xffff;
    result = (int)(prod / divisor) * 100;
    FUN_a0073044("\n Pexil clock = %ld KHz\n\n", result);
    FUN_a00a5148(0, result);
    return result;
}
