/* leon2s FUN_a00a26a8 @ 0xa00a26a8 (-mcpu=v8 -Os -g)
 * Returns byte +0x184 of record p1 & 0xff of the 400-byte records at 0xA807D7E0. Same code as FUN_a00a26fc with
 * other constants.
 */
extern unsigned char ARR_a807d7e0[];

unsigned char FUN_a00a26a8(unsigned int param_1)
{
    return ARR_a807d7e0[(param_1 & 0xff) * 400 + 388];
}
