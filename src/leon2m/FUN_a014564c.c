/* FUN_a014564c (leon2m 0xa014564c-0xa0145660, 20 bytes, leaf), flags -mcpu=v8 -O3 -g.
 * Calls FUN_a0153b20(1) as a tail call; the nop after it is the -g line nop. Nothing in the image refers to it: no
 * call, branch, sethi/or constant or address word. It lies between FUN_a0145644 and FUN_a0145660. Source form: a
 * void wrapper with a constant argument.
 */
extern void FUN_a0153b20(int);

void FUN_a014564c(void)
{
    FUN_a0153b20(1);
}
