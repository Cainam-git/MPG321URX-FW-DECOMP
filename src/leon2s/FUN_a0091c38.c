/* leon2s FUN_a0091c38 @ 0xa0091c38 (-mcpu=v8 -Os -g)
 * Twin of FUN_a009193c: same code, other constants.
 */
extern unsigned char ARR_a807d580[];

unsigned char FUN_a0091c38(unsigned int param_1)
{
    return ARR_a807d580[(param_1 & 0xff) * 28 + 0x1];
}
