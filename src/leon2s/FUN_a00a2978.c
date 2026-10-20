/* leon2s FUN_a00a2978 @ 0xa00a2978  MATCH (-mcpu=v8 -Os -g, twin)
 * Twin of FUN_a00a26fc: same code, constants swapped; byte-exact.
 */
extern unsigned char ARR_a807d7e0[];

unsigned char FUN_a00a2978(unsigned int param_1)
{
    return ARR_a807d7e0[(param_1 & 0xff) * 400 + 7];
}
