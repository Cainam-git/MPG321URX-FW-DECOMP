/* FUN_a010a2b0 (leon2m 0xa010a2b0-0xa010a2cc, 28 bytes, leaf), flags -mcpu=v8 -O3 -g -msoft-float.
 * Returns 1 when bit 7 (0x80) of the word register 0xcf01ea40 is set, otherwise 0. Nothing in the image refers to
 * it: no call, branch, sethi/or constant or address word. It lies between FUN_a0109bbc and FUN_a010a2cc. Source
 * form: the masked value is kept in its own unsigned int local, which keeps the and/cmp/addx sequence.
 */
#define REG (*(volatile unsigned int *)0xcf01ea40)

unsigned int FUN_a010a2b0(void)
{
    unsigned int m = REG & 0x80;
    return m != 0;
}
