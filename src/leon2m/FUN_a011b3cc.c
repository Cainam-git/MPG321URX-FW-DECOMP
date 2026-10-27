/* FUN_a011b3cc (leon2m 0xa011b3cc-0xa011b3e8, 28 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Delay loop: executes 0xa0 nop instructions (GCC counts down from 0x9f to -1) and returns. Nothing in the image
 * refers to it: no call, branch, sethi/or constant or address word. It lies between FUN_a011b3b8 and FUN_a011b3e8.
 * Source form: for (i = 0; i < 0xa0; i++) __asm__("nop"); the counter is unused, so GCC reverses it.
 */
void FUN_a011b3cc(void)
{
    int i;
    for (i = 0; i < 0xa0; i++)
        __asm__("nop");
}
