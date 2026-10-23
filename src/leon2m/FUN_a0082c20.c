/* FUN_a0082c20 (leon2m 0xa0082c20-0xa0082c38, 24 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Returns 1 when bit 4 (0x10) of the halfword DAT_a802af42 is set, else 0. Nothing in the image refers to it: no
 * call, branch, sethi/or constant or address word. It lies between FUN_a0082c0c and FUN_a0082c38. Source form: the
 * masked value in its own unsigned int local ('m = DAT_a802af42 & 0x10; return m != 0;') gives the and/cmp/addx
 * sequence; '(x & 0x10) != 0' in one expression becomes srl/and.
 */
extern unsigned short DAT_a802af42;

int FUN_a0082c20(void)
{
    unsigned int m = DAT_a802af42 & 0x10;

    return m != 0;
}
