/* leon2s FUN_a00b0280 @ 0xa00b0280  MATCH (-mcpu=v8 -Os -g, twin)
 * Twin of FUN_a00b0264: same code, constants swapped; byte-exact.
 */
extern unsigned char ARR_a807dc18[];

unsigned char FUN_a00b0280(unsigned int param_1)
{
    return ARR_a807dc18[(param_1 & 0xff) * 300 + 0xb7];
}
