/* leon2s FUN_a00ab674 @ 0xa00ab674  MATCH (-mcpu=v8 -Os -g, twin)
 * Twin of FUN_a00b0264: same code, constants swapped; byte-exact.
 */
extern unsigned char ARR_a807dc18[];

unsigned char FUN_a00ab674(unsigned int param_1)
{
    return ARR_a807dc18[(param_1 & 0xff) * 300 + 0x112];
}
