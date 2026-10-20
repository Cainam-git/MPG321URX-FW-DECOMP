/* leon2s FUN_a00b0438 @ 0xa00b0438  MATCH (-mcpu=v8 -Os -g)
 * The target computes `(param & 0xff) * 300` as a byte offset, then loads a word at `+0xfc`. Since the array is word-sized, the index is `(param & 0xff) * 75 + 63`. This produces the same `smul` by 0x12c and `ld [%o0 + 0xfc]` as the target. The similarity to the proven siblings (which use byte arrays with `*300 + 0x127`) suggests the compiler will emit the same sequence: `and`, `sethi`, `smul`, `or`, `add`, `retl`, `ld`.
 */
extern unsigned int ARR_a807dc18[];

unsigned int FUN_a00b0438(unsigned int param_1)
{
    return ARR_a807dc18[(param_1 & 0xff) * 75 + 0x3f];
}
