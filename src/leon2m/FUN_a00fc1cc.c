/* FUN_a00fc1cc (leon2m 0xa00fc1cc-0xa00fc200, 52 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Writes 0x78 >> s to the word register 0xcf012004, s = register 0xcf011480 & 3 (0x78 when s is 0). Nothing in the
 * image refers to it: no call, branch, sethi/or constant or address word. It lies between FUN_a00fc1a0 and
 * FUN_a00fc200. Source form: a separate register write in each arm of the if/else (signed shift of the int
 * constant).
 */
#define REG80 (*(volatile unsigned int *)0xcf011480)
#define REG04 (*(volatile unsigned int *)0xcf012004)
void FUN_a00fc1cc(void)
{
    unsigned int s = REG80 & 3;
    if (s)
        REG04 = 0x78 >> s;
    else
        REG04 = 0x78;
}
