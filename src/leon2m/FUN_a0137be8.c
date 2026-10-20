/* leon2m FUN_a0137be8 @ 0xa0137be8  MATCH (-mcpu=v8 -O2 -g)
 * The function builds a 4-byte buffer containing three byte parameters (the fourth byte is zero from the `clr`), then calls `FUN_a01370dc` with command `0x25`, length `4`, the buffer pointer, and `1` as the last argument. The assembly shows `mov 0x25, %o0; mov 4, %o1; add %fp, -16, %o2; call FUN_a01370dc; mov 1, %o3` — this matches the similar functions exactly, just with different constants and one more byte parameter.
 */
extern int FUN_a01370dc();

void FUN_a0137be8(unsigned char param_1, unsigned char param_2, unsigned char param_3)
{
    unsigned char local[4] = {param_1, param_2, param_3};
    FUN_a01370dc(0x25, 4, local, 1);
}
