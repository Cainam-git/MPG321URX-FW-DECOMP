/* leon2s FUN_a00a2718 @ 0xa00a2718 (-mcpu=v8 -Os -g)
 * Twin of FUN_a00a26fc: same code, other constants.
 */
extern unsigned char ARR_a807d7e0[];

unsigned char FUN_a00a2718(unsigned int param_1)
{
    return ARR_a807d7e0[(param_1 & 0xff) * 400 + 47];
}
