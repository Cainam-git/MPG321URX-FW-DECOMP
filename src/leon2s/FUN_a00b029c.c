/* leon2s FUN_a00b029c @ 0xa00b029c (-mcpu=v8 -Os -g)
 * Returns byte +0xdd of the 300-byte record (p & 0xff) at 0xA807DC18.
 */
extern unsigned char ARR_a807dc18[];

unsigned char FUN_a00b029c(unsigned int param_1)
{
    return ARR_a807dc18[(param_1 & 0xff) * 300 + 0xdd];
}
