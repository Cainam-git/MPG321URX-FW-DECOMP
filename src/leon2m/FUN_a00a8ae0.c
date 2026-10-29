/* leon2m FUN_a00a8ae0 @ 0xa00a8ae0-0xa00a8bc0 (224 bytes), flags -mcpu=v8 -O3 -g. No direct callers.
 * Returns 1 when x is in one of the value sets 63-64, 67, 237-239, 68-69, 231-236, 111, 204, 122-124, 205-207,
 * 208-211, 216-220, 130-131 or 212-215, else 0. The tests run in that order.
 * Source form: one if statement per test, each returning 1; 67 / 237-239 and 111 / 204 share one if (GCC
 * evaluates each pair without a branch between them); the ranges are written 'x >= a && x <= b'.
 */
unsigned char FUN_a00a8ae0(int x)
{
    if (x >= 63 && x <= 64)
        return 1;
    if (x == 67 || (x >= 237 && x <= 239))
        return 1;
    if (x >= 68 && x <= 69)
        return 1;
    if (x >= 231 && x <= 236)
        return 1;
    if (x == 111 || x == 204)
        return 1;
    if (x >= 122 && x <= 124)
        return 1;
    if (x >= 205 && x <= 207)
        return 1;
    if (x >= 208 && x <= 211)
        return 1;
    if (x >= 216 && x <= 220)
        return 1;
    if (x >= 130 && x <= 131)
        return 1;
    if (x >= 212 && x <= 215)
        return 1;
    return 0;
}
