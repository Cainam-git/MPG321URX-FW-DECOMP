/* FUN_a0106294 (leon2m 0xa0106294-0xa01062c0, 44 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Writes 9 to the word register 0xcf00ec00 when c is 1, otherwise 0. Nothing in the image refers to it: no call,
 * branch, sethi/or constant or address word. It lies between FUN_a0106274 and FUN_a01062c0.
 */
#define REG (*(volatile unsigned int *)0xcf00ec00)

void FUN_a0106294(unsigned char c)
{
    if (c == 1)
        REG = 9;
    else
        REG = 0;
}
