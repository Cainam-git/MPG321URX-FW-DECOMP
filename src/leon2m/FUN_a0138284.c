/* leon2m FUN_a0138284 @ 0xa0138284 (-mcpu=v8 -O2 -g)
 * This should produce:
 * - `save %sp, -112, %sp`
 * - `call FUN_a01241fc` with `clr [%fp-16]` in delay slot (initializing buf)
 * - `mov 0x7d, %o0; mov 4, %o1; add %fp,-16,%o2; call FUN_a01370dc; clr %o3`
 * - `nop; ret; restore`
 */
extern int FUN_a01241fc(void);
extern int FUN_a01370dc();

void FUN_a0138284(void)
{
    unsigned char buf[4] = {0, 0, 0, 0};
    FUN_a01241fc();
    FUN_a01370dc(0x7d, 4, buf, 0);
}
