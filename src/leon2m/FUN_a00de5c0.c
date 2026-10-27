/* FUN_a00de5c0 (leon2m 0xa00de5c0-0xa00de604, 68 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Delay loop: runs n outer passes of 0x9c40 nops each. Nothing in the image refers to it: no call, branch, sethi/or
 * constant or address word. It lies between FUN_a00de578 and FUN_a00de604.
 */
void FUN_a00de5c0(unsigned int n)
{
    unsigned int i, j;

    for (i = 0; i < n; i++)
        for (j = 0; j <= 0x9c3f; j++)
            __asm__("nop");
}
