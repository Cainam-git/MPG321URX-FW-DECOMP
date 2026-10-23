/* leon2s FUN_a00a26fc @ 0xa00a26fc (-mcpu=v8 -Os -g)
 * Returns byte +0x19 of the 400-byte record p & 0xff at 0xA807D7E0.
 */
extern unsigned char ARR_a807d7e0[];

unsigned char FUN_a00a26fc(unsigned int param_1)
{
    return ARR_a807d7e0[(param_1 & 0xff) * 400 + 25];
}
