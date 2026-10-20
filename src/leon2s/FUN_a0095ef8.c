/* leon2s FUN_a0095ef8 @ 0xa0095ef8  MATCH (-mcpu=v8 -Os -g)
 * This should compile to exactly the target: mask, multiply by 7 (via sll/sub), shift left 2, add base, load word at +4, shift right 31, return.
 */
extern unsigned int ARR_a807d580[];

unsigned int FUN_a0095ef8(unsigned int param_1)
{
    return ARR_a807d580[(param_1 & 0xff) * 7 + 1] >> 31;
}
