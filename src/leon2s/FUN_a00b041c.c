/* leon2s FUN_a00b041c @ 0xa00b041c (-mcpu=v8 -Os -g)
 * Twin of FUN_a00b0264: same code, other constants.
 */
extern unsigned char ARR_a807dc18[];

unsigned char FUN_a00b041c(unsigned int param_1)
{
    return ARR_a807dc18[(param_1 & 0xff) * 300 + 0xf8];
}
